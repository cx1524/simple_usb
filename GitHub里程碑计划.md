# USB 自研框架 GitHub 里程碑管理计划

> 本文件是把《[USB新手从零搭建框架实践计划](./USB新手从零搭建框架实践计划.md)》转译为 **GitHub Milestone + Issue** 的管理方案。
> 用途：在 GitHub 仓库中用 Milestone 管理阶段、用 Issue 管理任务、用 Label 分类、用 Pull Request/提交固化进度。
>
> 里程碑与计划文档的对应关系：A/B/C 来自计划文档 §4.1，D（移植）来自 §5。
> 依赖严格串行：A ← B ← C ← D。**B 完成前不要碰移植**。

---

## 0. 使用说明（在 GitHub 上怎么用）

1. **创建 4 个 Milestone**：按第 1 节总览表逐个创建（标题、描述、截止日期可选，可先留空）。
2. **创建 Issue**：按第 2 节每个里程碑下的任务清单逐个创建（标题、描述、验收标准可直接复制）。
3. **打 Label**：新建第 3 节建议的 Label，每个 Issue 至少打一个 `type/*` 和一个 `module/*`。
4. **进度跟踪**：每完成一个 Issue 就关闭；对应代码合入主分支并在里程碑描述/提交信息中记录。
5. **固化提交**：每个里程碑完成时打一个 tag（如 `v0.1.0` / `v0.2.0` / `v0.3.0` / `v1.0.0`），保证每个里程碑都是一个可编译可验证的提交。

---

## 1. 里程碑总览

| # | 里程碑标题 | 覆盖模块 | 覆盖文件 | 完成标志（验收标准） | 依赖 | 建议 Tag |
| --- | --- | --- | --- | --- | --- | --- |
| A | 最小枚举逻辑 | M1–M4 | `core/usb_def.h`、`core/usb_dcd.h`、`core/usbd_fsm.c`、`core/usbd_ep0.c` | Mock 下：GET_DESCRIPTOR(Device) 回 18 字节 + SET_ADDRESS 成功 + `wLength=8` 仅回 8 字节 + 非法请求 Stall | 无 | `v0.1.0` |
| B | 完整枚举逻辑 | M5–M6 | `core/usbd_desc.c`、`core/usbd_req.c`、`core/usbd_event.c` | Mock 下：配置拼接自检通过（`wTotalLength`==实际长度）+ 字符串正确 + SET_CONFIGURATION(0)/(非0) 往返正确 + 事件分发覆盖所有订阅者 | A | `v0.2.0` |
| C | 类驱动与传输 | M7–M10 | `class/usbd_class.c`、`class/cdc/usbd_cdc.c`、`core/usb_transfer.c`、`mock/mock_dcd.c` + 测试 | Mock 下：CDC 枚举 + 类请求 + Bulk + ZLP 全绿；`ctest` 通过；框架无任何 MCU 依赖 | B | `v0.3.0` |
| D | 移植 MCU 跑通 CDC | §5 移植清单 | `port/`（板级初始化 + 真实 DCD） | 烧录后 Windows 出现 COM 口；PuTTY 双向收发；拔插 10 次稳定 | C | `v1.0.0` |

> 截止日期建议：个人学习项目可暂不设置，或由你自己根据节奏补充。

---

## 2. 各里程碑详情（含 Issue 任务清单）

> 说明：每个 M 步骤对应 1 个 Issue。描述中的"为什么"可参见计划文档对应章节；验收标准为关闭 Issue 的必要条件。

### Milestone A：最小枚举逻辑（M1–M4）

**描述**：搭出协议栈"心脏"——协议词汇表、与硬件的契约接口、设备状态机、EP0 控制传输引擎。此阶段只追求"最小枚举"跑通，不涉及描述符拼接和类驱动。

#### Issue A1 填充 `core/usb_def.h`（M1 协议词汇表）
- **描述**：定义描述符类型常量、SETUP 包结构、bmRequestType 位域、标准请求码、描述符结构体、端点地址宏、速度/传输类型/错误码枚举。参考计划文档 §3 Step 1。
- **验收**：编译通过；`sizeof(usb_setup_packet_t) == 8`；字段与 USB 2.0 规范 §9.6 一致。

#### Issue A2 填充 `core/usb_dcd.h`（M2 与硬件的契约）
- **描述**：三组接口——控制类（init/connect/disconnect/set_address/remote_wakeup）、端点类（ep_open/close/stall/clear_stall/write/read）、事件上报（事件枚举 + 回调注册）。`ep_write` 必须是非阻塞语义。参考计划文档 §3 Step 2。
- **验收**：头文件无任何芯片头文件依赖；提供 stub（或由 mock 先实现桩）使全工程可链接。

#### Issue A3 填充 `core/usbd_fsm.c`（M3 设备状态机）
- **描述**：状态枚举（ATTACHED/POWERED/DEFAULT/ADDRESS/CONFIGURED）、集中切换函数 `usbd_set_state()`（含非法跳转校验）、进入/退出钩子、RESET 处理。参考计划文档 §3 Step 3。
- **验收**：单测遍历合法迁移；构造 DEFAULT→CONFIGURED 非法跳转被拒绝。

#### Issue A4 填充 `core/usbd_ep0.c`（M4 EP0 控制传输引擎）
- **描述**：三阶段状态机（SETUP→DATA→STATUS）、SETUP 解析分发、DATA-IN 分包 + ZLP、DATA-OUT 接收、Stall 策略、SET_ADDRESS 延迟写。参考计划文档 §3 Step 4。
- **验收**（配合 A5 的 Mock）：GET_DESCRIPTOR(Device) 恰好 18 字节；`wLength=8` 只回 8 字节；非法请求 Stall 且后续请求正常。

#### Issue A5 最小 Mock + 验证用例
- **描述**：实现 `mock/mock_dcd.c` 的最小可用版（可注入 RESET、SETUP，记录协议层行为），配套最小 CMake 工程；跑通 A4 的验收用例。
- **验收**：A1–A4 的验收用例全部通过，Milestone A 关闭；打 tag `v0.1.0`。

---

### Milestone B：完整枚举逻辑（M5–M6）

**描述**：补全描述符管理与标准请求引擎，让"完整枚举序列"在 Mock 下跑通；引入事件总线解决多模块对总线事件的订阅。

#### Issue B1 填充 `core/usbd_desc.c` + `core/usbd_req.c`（M5 描述符 + 标准请求）
- **描述**：描述符注册/查询（设备、配置、字符串：语言 ID → 索引 → UTF-16LE）、配置描述符动态拼接（wTotalLength 自检）、GET_DESCRIPTOR / SET_ADDRESS / SET_CONFIGURATION / GET_STATUS / SET_FEATURE / CLEAR_FEATURE。所有 GET_DESCRIPTOR 返回 `min(wLength, 总长)`。参考计划文档 §3 Step 5。
- **验收**：Mock 驱动完整枚举序列，逐包断言描述符字节；故意改错 wTotalLength，自检报错。

#### Issue B2 填充 `core/usbd_event.c`（M6 事件总线）
- **描述**：事件类型（RESET/SUSPEND/RESUME/SOF/CONFIGURED）、订阅/退订、多订阅者分发。参考计划文档 §3 Step 6。
- **验收**：注册两个订阅者，发一次 RESET，两者都收到。

#### Issue B3 枚举回归用例
- **描述**：补齐枚举序列测试（含 SET_CONFIGURATION(0)/(非0) 往返、字符串描述符、wLength 截断），纳入 CMake 测试。
- **验收**：B1、B2 验收用例全部通过，Milestone B 关闭；打 tag `v0.2.0`。

---

### Milestone C：类驱动与传输（M7–M10）

**描述**：接入类驱动框架与 CDC ACM 类驱动、传输管理器，用完整版 Mock（假主机）跑通 CDC 枚举 + 类请求 + Bulk + ZLP；框架达到"无任何 MCU 依赖、可在 PC 上全量验证"。

#### Issue C1 填充 `class/usbd_class.c`（M7 类驱动框架）
- **描述**：`usb_class_driver_t`（init/deinit/reset/setup_req/get_config_desc/xfer_complete）、注册 + 接口号分配、接口/端点绑定表、类请求路由。参考计划文档 §3 Step 7。
- **验收**：注册两个类驱动（CDC + 测试类），发各自接口的类请求，路由正确；无归属驱动时 Stall。

#### Issue C2 填充 `class/cdc/usbd_cdc.c`（M8 CDC ACM 类驱动）
- **描述**：CDC 描述符片段（2 接口 + 3 端点 + 功能描述符链）、类请求（SET/GET_LINE_CODING、SET_CONTROL_LINE_STATE、SEND_BREAK）、Bulk 收发（OUT 完成回调立刻重新武装）。参考计划文档 §3 Step 8。
- **验收**：Mock 下发枚举 + SetLineCoding + 双向 Bulk 数据，字节一致。

#### Issue C3 填充 `core/usb_transfer.c`（M9 传输管理器）
- **描述**：`usb_transfer_t`（ep_addr/buffer/total_len/transferred/complete_cb）、单请求模型、ZLP 自动追加、完成通知。参考计划文档 §3 Step 9。
- **验收**：Mock 下发送 64/128 字节（MPS 整数倍），不卡死且字节一致。

#### Issue C4 完整版 Mock + 全量测试用例（M10 验证平台）
- **描述**：Mock 升级为"假主机"：可注入 RESET→逐条 SETUP→业务传输，记录行为并断言回复字节；独立 CMake 工程，`ctest` 入口。覆盖计划文档 §3 Step 10 的 7 条用例：
  1. 完整枚举序列逐包断言描述符字节；
  2. `wLength=8` 只回 8 字节；
  3. 非法请求 → Stall，且后续请求正常；
  4. 配置描述符 `wTotalLength` == 实际长度；
  5. CDC 类请求序列被正确应答；
  6. Bulk 双向收发 + ZLP 场景字节一致；
  7. 状态机非法跳转被拒绝。
- **验收**：`ctest` 全绿；grep 确认框架代码无 `malloc`/动态内存、无芯片头文件；Milestone C 关闭；打 tag `v0.3.0`。

---

### Milestone D：移植真实 MCU 跑通 CDC（§5）

**描述**：协议层已被 Mock 充分验证（前置：Milestone C 全绿）。本阶段只写 `port/` 适配层：板级初始化 + 真实 DCD 实现，协议层 `core/class` 一行不改。按 §5.2 顺序执行，每步一个 Issue。

#### Issue D1 配置 USB 时钟
- **描述**：按 MCU 手册配置 USB 时钟（FS 需精确 48 MHz）。参考计划文档 §5.2 步骤 1。
- **验收**：时钟测量/确认正确，能供 USB 控制器使用。

#### Issue D2 GPIO 复用与控制器使能
- **描述**：GPIO 复用 D+/D- 引脚；PHY/控制器复位与使能，规划 FIFO。参考计划文档 §5.2 步骤 2、3。
- **验收**：控制器可工作，FIFO 规划总和 ≤ 控制器总容量。

#### Issue D3 实现真实 DCD（11 个接口）
- **描述**：实现 `usb_dcd.h` 全部接口（ep_open/close/stall/write/read、set_address、connect/disconnect…），按协议层调用顺序逐个实现。参考计划文档 §5.2 步骤 4。
- **验收**：接口实现完整，与契约语义一致（尤其 `ep_write` 非阻塞）。

#### Issue D4 中断处理与事件上报
- **描述**：实现中断处理：RESET/SETUP/传输完成 → 上报协议层回调；ISR 只做"读状态→清标志→回调"三件事，无打印/延时。参考计划文档 §5.2 步骤 5、§5.3。
- **验收**：枚举依赖的三条时间窗满足（复位后 10ms / SET_ADDRESS 后 2ms / 上电 100ms）。

#### Issue D5 替换 Mock 并集成
- **描述**：CMake 中把 `mock_dcd.c` 换成真实 DCD，加 `usb_dcd_connect()` 调用；USB 初始化放在 RTOS 调度器启动前（如用 RTOS）。参考计划文档 §5.2 步骤 6、§5.3。
- **验收**：烧录后 Windows 出现 COM 口（或设备管理器看到"USB 串行设备"）。

#### Issue D6 CDC 双向通路验证
- **描述**：PuTTY/Tera Term 双向测试：MCU→PC 每秒发 "Hello World!"；PC→MCU 回显；可选 Wireshark+USBPcap/Bus Hound 抓包确认枚举与类请求；拔插 10 次稳定、无 hardfault。参考计划文档 §5.4、§5.5。
- **验收**：双向收发正常且拔插稳定；Milestone D 关闭；打 tag `v1.0.0`。

---

## 3. GitHub 配置建议

### 3.1 Labels

| Label | 说明 | 建议颜色 |
| --- | --- | --- |
| `type/feature` | 功能实现（填充骨架代码） | `#0E8A16`（绿） |
| `type/test` | 测试 / 验证用例 | `#1D76DB`（蓝） |
| `type/docs` | 文档 | `#FFFFFF`（白） |
| `module/core` | core/ 层（M1–M6、M9） | `#5319E7`（紫） |
| `module/class` | class/ 类驱动层（M7、M8） | `#B60205`（红） |
| `module/mock` | mock/ 验证平台（M10） | `#FBCA04`（黄） |
| `module/port` | port/ 硬件适配（Milestone D） | `#D93F0B`（橙） |
| `blocked` | 被前置任务阻塞 | `#000000`（黑） |

### 3.2 Issue 创建建议

- 一个 M 步骤 = 一个 Issue，标题格式：`[M1] 填充 usb_def.h（协议词汇表）`。
- Issue 描述中写清：**做什么**（引用计划文档章节）、**为什么**（一句话）、**验收标准**。
- 里程碑内按依赖顺序排序，A4 的验收依赖 A5 的 Mock，可在 Issue 中互相 @ 引用。

### 3.3 提交 / 分支策略

- 每个 Issue 一个分支（`feat/m1-usb-def` 等），完成后合入 `main` 并关闭 Issue。
- 里程碑完成即打 tag：`v0.1.0`（A）→ `v0.2.0`（B）→ `v0.3.0`（C）→ `v1.0.0`（D）。
- 提交信息格式建议：`[M1] 添加协议词汇表定义`，便于和 Issue 对应。

---

## 4. 任务总览（快速复制用）

| Issue | 标题 | Milestone | Label |
| --- | --- | --- | --- |
| A1 | [M1] 填充 usb_def.h（协议词汇表） | A | feature / core |
| A2 | [M2] 填充 usb_dcd.h（硬件契约接口） | A | feature / core |
| A3 | [M3] 填充 usbd_fsm.c（设备状态机） | A | feature / core |
| A4 | [M4] 填充 usbd_ep0.c（EP0 控制传输引擎） | A | feature / core |
| A5 | 最小 Mock + 枚举验证用例 | A | test / mock |
| B1 | [M5] 填充 usbd_desc.c + usbd_req.c | B | feature / core |
| B2 | [M6] 填充 usbd_event.c（事件总线） | B | feature / core |
| B3 | 枚举回归用例（SET_CONFIGURATION 往返等） | B | test / mock |
| C1 | [M7] 填充 usbd_class.c（类驱动框架） | C | feature / class |
| C2 | [M8] 填充 usbd_cdc.c（CDC ACM 类驱动） | C | feature / class |
| C3 | [M9] 填充 usb_transfer.c（传输管理器） | C | feature / core |
| C4 | 完整 Mock + ctest 全量用例 | C | test / mock |
| D1 | 配置 USB 时钟（48 MHz） | D | feature / port |
| D2 | GPIO 复用与控制器使能 | D | feature / port |
| D3 | 实现真实 DCD（11 个接口） | D | feature / port |
| D4 | 中断处理与事件上报 | D | feature / port |
| D5 | 替换 Mock 并集成 | D | feature / port |
| D6 | CDC 双向通路验证 | D | test / port |

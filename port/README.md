# 硬件适配层（port/）— 占位目录

> 本目录用于存放**后续补充的硬件适配方案**（DCD 具体芯片实现）。
> 当前阶段仅开发纯软件协议层，本目录暂为空。

## 适配层需要提供的内容（接口契约，详见《USB新手从零搭建框架实践计划》§2.4）

| 契约项 | 说明 |
| --- | --- |
| 平台初始化回调 | `usb_platform_init(speed)`：时钟、PHY、GPIO、控制器复位、中断使能 |
| DCD 实现 | 实现 `framework/core/usb_dcd.h` 全部接口（ep_open/close/stall/write/read、set_address、connect/disconnect） |
| 事件上报 | 中断服务程序中调用协议层注册的事件回调，保证"读状态 → 清标志 → 回调"三件事内无阻塞 |
| 内存对齐要求 | 如需 DMA / 缓存一致性，向协议层声明缓冲区对齐要求 |
| 速度能力声明 | 声明支持的速度（FS/HS），协议层按速度选择描述符集 |

## 预期的目录结构（后续补充时生成）

```
port/
├── README.md                    # 本文件：硬件适配接口契约说明
├── usb_platform_xxx.c/.h        # 平台初始化（时钟/PHY/GPIO/中断）
└── usb_dcd_xxx.c/.h             # 某芯片的 DCD 实现（实现 framework/core/usb_dcd.h 接口）
```

## 约束

- 适配层是唯一允许包含寄存器/芯片头文件的层；
- 协议层代码零改动即可接入任意适配实现（替换 Mock 后做真实总线验证）。

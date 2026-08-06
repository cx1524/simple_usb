/**
 * @file usbd_ep0.h
 * @brief EP0 控制传输引擎：SETUP → DATA → STATUS 三阶段状态机（纯软件，MCU 无关）
 *
 * 【所属层】第二层 USBD Core 子模块（core）。协议栈中最复杂的单模块。
 *
 * 【职责】
 *   1. 接收 DCD 上报的 SETUP 包（usb_setup_packet_t），解析 bmRequestType 分发：
 *      标准请求 → usbd_req 处理；类请求 → usbd_class 路由；厂商请求 → Stall。
 *   2. DATA 阶段：IN 分包发送（每包 ≤ MPS，末包不足或 ZLP，按 min(wLength, 实际长) 返回）；
 *      OUT 按 wLength 接收。
 *   3. STATUS 阶段：IN 传输等主机 OUT+ZLP；OUT 传输设备发 IN+ZLP；无数据阶段直接 STATUS。
 *   4. Stall 策略：SETUP 阶段绝不 Stall；DATA/STATUS 方向不匹配或不支持 → Stall；
 *      Stall 后自动恢复等待下一个 SETUP。
 *   5. SET_ADDRESS 时序：SETUP 暂存地址，STATUS 完成后调 usb_dcd_set_address()。
 *
 * 【需要实现（TODO）】
 *   [ ] EP0 三阶段状态机（EP0_IDLE / SETUP / DATA_IN / DATA_OUT / STATUS）
 *   [ ] SETUP 分发逻辑（标准/类/厂商）
 *   [ ] DATA-IN 分包与 ZLP 处理
 *   [ ] Stall 触发与恢复
 *   [ ] SET_ADDRESS 延迟写地址
 *
 * 【依赖】usb_def.h / usb_dcd.h / usbd_req.h / usbd_class.h。
 * 【参考】《MCU-USB 启动流程说明》§6.3.2；《USB新手从零搭建框架实践计划》M4。
 */

#ifndef __USBD_EP0_H__
#define __USBD_EP0_H__

/* TODO: 在此定义本文件内容（见上方职责清单） */

#endif /* __USBD_EP0_H__ */

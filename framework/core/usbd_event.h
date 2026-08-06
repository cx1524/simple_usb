/**
 * @file usbd_event.h
 * @brief 事件总线：为类驱动与应用提供异步事件（RESET/SUSPEND/RESUME/SOF/CONFIGURED）
 *
 * 【所属层】第二层 USBD Core 子模块（core）。纯软件注册-分发机制，MCU 无关。
 *
 * 【职责】
 *   1. 事件类型定义：RESET / SUSPEND / RESUME / SOF / CONFIGURED。
 *   2. 注册接口：每个事件允许注册多个回调（链表或数组），类驱动与应用均可订阅。
 *   3. 分发：DCD 中断 → USBD Core 打包事件 → 按事件类型遍历调用订阅者回调。
 *   4. 典型处理约定：RESET → 所有类驱动 reset()；CONFIGURED → 应用启动首个 OUT 接收。
 *
 * 【需要实现（TODO）】
 *   [ ] 事件类型枚举与回调函数签名
 *   [ ] 订阅/退订接口
 *   [ ] 事件分发实现（支持多订阅者）
 *
 * 【依赖】usb_def.h。
 * 【参考】《MCU-USB 启动流程说明》§6.3.5；《USB新手从零搭建框架实践计划》M6。
 */

#ifndef __USBD_EVENT_H__
#define __USBD_EVENT_H__

/* TODO: 在此定义本文件内容（见上方职责清单） */

#endif /* __USBD_EVENT_H__ */

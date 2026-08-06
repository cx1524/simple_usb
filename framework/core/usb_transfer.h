/**
 * @file usb_transfer.h
 * @brief 传输管理器：业务端点（Bulk/Interrupt）传输请求管理与完成通知（纯软件）
 *
 * 【所属层】第四层传输管理器（core，协议无关）。
 *
 * 【职责】
 *   1. 传输请求结构 usb_transfer_t：ep_addr / buffer / total_len / transferred /
 *      complete_cb（可选 user_data）。
 *   2. 每端点单请求模型（MVP），队列化留作增强项。
 *   3. **ZLP 自动处理**：发送总长恰为 MPS 整数倍时，最后一个满包后自动追加
 *      0 长度包，结束传输。
 *   4. 完成回调：在中断上下文中只置标志，由应用层任务消费（纯软件约定）。
 *
 * 【需要实现（TODO）】
 *   [ ] usb_transfer_t 结构定义
 *   [ ] 请求发起接口（发送/接收）
 *   [ ] ZLP 自动追加逻辑
 *   [ ] 完成回调通知机制
 *
 * 【依赖】usb_def.h / usb_dcd.h。
 * 【参考】《MCU-USB 启动流程说明》§6.5；《USB新手从零搭建框架实践计划》M9。
 */

#ifndef __USB_TRANSFER_H__
#define __USB_TRANSFER_H__

/* TODO: 在此定义本文件内容（见上方职责清单） */

#endif /* __USB_TRANSFER_H__ */

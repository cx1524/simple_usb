/**
 * @file usb_dcd.h
 * @brief DCD（设备控制器驱动）抽象接口层：协议层与硬件的唯一边界（MCU 无关）
 *
 * 【所属层】第一层 DCD（core 基础）。本框架中只定义接口，不实现任何具体芯片驱动；
 *           具体芯片适配（寄存器序列 / FIFO / 中断）由后续"硬件适配方案"补充。
 *
 * 【职责】
 *   1. 控制类接口：usb_dcd_init() / usb_dcd_connect() / usb_dcd_disconnect() /
 *      usb_dcd_set_address() / usb_dcd_remote_wakeup()。
 *   2. 端点类接口：usb_dcd_ep_open(ep_addr, type, mps, bInterval) /
 *      usb_dcd_ep_close() / usb_dcd_ep_stall() / usb_dcd_ep_clear_stall() /
 *      usb_dcd_ep_write() / usb_dcd_ep_read()。
 *   3. 事件上报：usb_dcd_event_t 事件类型 + 回调注册 usb_dcd_set_event_cb()，
 *      事件包括 RESET / SUSPEND / RESUME / SOF / SETUP_RECV /
 *      EP_IN_XFER_COMPLETE / EP_OUT_XFER_COMPLETE。
 *   4. 桩实现（usb_dcd_stub）：所有接口返回"未实现"，保证无硬件时可链接。
 *
 * 【需要实现（TODO）】
 *   [ ] 各接口函数声明（参数/返回值类型需与芯片无关）
 *   [ ] 事件类型枚举与回调注册接口
 *   [ ] 桩实现文件（或由 Mock DCD 替代）
 *
 * 【接口契约（冻结后不再新增耦合点）】
 *   协议层 → DCD：调用 usb_dcd_* 接口；
 *   DCD → 协议层：通过回调上报事件（SETUP 携带 usb_setup_packet_t，传输完成携带
 *   端点地址 + 实际字节数）。
 *
 * 【约束】不得包含任何寄存器/芯片头文件。
 * 【参考】《MCU-USB 启动流程说明》§6.2.1 / §6.2.2；《USB新手从零搭建框架实践计划》§2.4。
 */

#ifndef __USB_DCD_H__
#define __USB_DCD_H__

#include <stdint.h>

/* TODO: 在此定义本文件内容（见上方职责清单） */
void usb_dcd_init(void);
void usb_dcd_connect(void);
void usb_dcd_disconnect(void);
void usb_dcd_set_address(uint8_t address);
void usb_dcd_remote_wakeup(void);

void usb_dcd_ep_open(uint8_t ep_addr, uint8_t type, uint16_t mps, uint8_t bInterval);
void usb_dcd_ep_close(uint8_t ep_addr);
void usb_dcd_ep_stall(uint8_t ep_addr);
void usb_dcd_ep_clear_stall(uint8_t ep_addr);
void usb_dcd_ep_write(uint8_t ep_addr, const uint8_t *data, uint16_t len);
uint16_t usb_dcd_ep_read(uint8_t ep_addr, uint8_t *data, uint16_t len);

#endif /* __USB_DCD_H__ */

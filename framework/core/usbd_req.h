/**
 * @file usbd_req.h
 * @brief 标准请求处理器（Chapter 9）：全部标准请求的解析与应答（纯软件，MCU 无关）
 *
 * 【所属层】第二层 USBD Core 子模块（core）。
 *
 * 【职责】
 *   1. 标准请求分发：GET_DESCRIPTOR / SET_ADDRESS / SET_CONFIGURATION /
 *      GET_CONFIGURATION / GET_STATUS / SET_FEATURE / CLEAR_FEATURE /
 *      GET_INTERFACE / SET_INTERFACE 等。
 *   2. GET_DESCRIPTOR 三级路由（类型 → 索引 → 语言 ID），分包返回 min(wLength, 总长)。
 *   3. SET_ADDRESS / SET_CONFIGURATION 与状态机（usbd_fsm）联动。
 *   4. GET_STATUS / SET_FEATURE / CLEAR_FEATURE（端点 Halt）。
 *
 * 【需要实现（TODO）】
 *   [ ] 各标准请求处理函数声明
 *   [ ] 请求分发表（bRequest → handler）
 *   [ ] 与 usbd_desc / usbd_fsm / usb_dcd 的联动接口
 *
 * 【依赖】usb_def.h / usbd_desc.h / usbd_fsm.h / usb_dcd.h。
 * 【参考】《MCU-USB 启动流程说明》§6.3.3；USB 2.0 Spec §9.4。
 */

#ifndef __USBD_REQ_H__
#define __USBD_REQ_H__

/* TODO: 在此定义本文件内容（见上方职责清单） */

#endif /* __USBD_REQ_H__ */

/**
 * @file usbd_cdc.h
 * @brief CDC ACM（虚拟串口）类驱动：描述符片段 / 类请求 / 业务端点收发
 *
 * 【所属层】第三层类驱动框架的具体类实现（class/cdc，首个目标类，MCU 无关）。
 *
 * 【职责】
 *   1. 描述符片段（无任何芯片相关字段）：
 *      - 接口 0（通信类 0x02 / 子类 0x02 ACM / 协议 0x01）：功能描述符链
 *        Header + Call Management + ACM + Union；端点 INT IN（通知，MPS 8，bInterval 10）；
 *      - 接口 1（数据类 0x0A / 协议 0x00）：Bulk IN + Bulk OUT，MPS 64；
 *      - 端点地址由框架统一分配（如 0x81 / 0x01 / 0x82），通过配置宏/注册参数注入。
 *   2. 类请求：SET_LINE_CODING / GET_LINE_CODING / SET_CONTROL_LINE_STATE /
 *      SEND_BREAK，按 wIndex（接口号）路由。
 *   3. 收发：Bulk IN 发送（完成回调 + ZLP 由传输管理器处理）；
 *      Bulk OUT 循环接收（完成回调中立即发起下一次读，避免丢包）。
 *   4. 事件：CONFIGURED → 启动首个 OUT 接收；RESET → 复位内部状态。
 *
 * 【需要实现（TODO）】
 *   [ ] 描述符片段生成（并入 usbd_desc 拼接）
 *   [ ] 类请求处理（线路编码 / 控制线状态等）
 *   [ ] Bulk 收发接口与回调
 *   [ ] 注册到 usbd_class 的驱动实例
 *
 * 【依赖】usb_def.h / usbd_class.h / usb_transfer.h。
 * 【参考】《MCU-USB 启动流程说明》§6.4 / §4.2；USB CDC Spec 1.2；
 *         《USB新手从零搭建框架实践计划》M8。
 */

#ifndef __USBD_CDC_H__
#define __USBD_CDC_H__

/* TODO: 在此定义本文件内容（见上方职责清单） */

#endif /* __USBD_CDC_H__ */

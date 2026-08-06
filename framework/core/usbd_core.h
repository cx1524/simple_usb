/**
 * @file usbd_core.h
 * @brief USBD Core 公共头：对外统一 API（初始化 / 描述符注册 / 类驱动注册 / 事件订阅 / 连接）
 *
 * 【所属层】第二层 USBD Core。本文件是协议层对外的门面，聚合 fsm / ep0 / req / desc /
 *           event / class 各子模块，应用只需包含本头文件即可使用框架。
 *
 * 【职责】
 *   1. 对外生命周期 API：usbd_init() / usbd_connect() / usbd_disconnect()。
 *   2. 注册类 API：设备描述符注册、字符串表注册、配置描述符注册、类驱动注册。
 *   3. 事件订阅 API：应用/类驱动订阅 RESET / SUSPEND / RESUME / SOF / CONFIGURED。
 *   4. 内部模块之间的公共类型（设备状态、速度、接口/端点绑定信息）声明。
 *
 * 【需要实现（TODO）】
 *   [ ] 对外 API 声明（参数类型以 usb_def.h 为基础）
 *   [ ] 聚合各子模块头文件（fsm / ep0 / req / desc / event / class）
 *   [ ] 内部公共类型（如设备对象句柄、速度选择、错误码）
 *
 * 【依赖】usb_def.h / usb_dcd.h / 各子模块头。
 * 【参考】《MCU-USB 启动流程说明》§6.3。
 */

#ifndef __USBD_CORE_H__
#define __USBD_CORE_H__

/* TODO: 在此定义本文件内容（见上方职责清单） */

#endif /* __USBD_CORE_H__ */

/**
 * @file usbd_class.h
 * @brief 类驱动框架：类驱动注册 / 请求路由 / 接口与端点绑定（纯软件，MCU 无关）
 *
 * 【所属层】第三层类驱动框架（class），不绑定任何具体类。
 *
 * 【职责】
 *   1. 定义类驱动接口 usb_class_driver_t：
 *      init / deinit / reset / setup_req / get_config_desc / xfer_complete。
 *   2. 注册接口 usbd_class_register()：自动分配接口号，维护两张绑定表——
 *      接口号 → 类驱动、端点地址 → 类驱动。
 *   3. 类请求路由：SETUP 到达后按 bmRequestType 分派——类请求按接收者
 *      （接口/端点）查绑定表 → 调对应驱动的 setup_req()；找不到 → Stall。
 *   4. 描述符拼接钩子：GET_DESCRIPTOR(Config) 时调接口归属驱动的
 *      get_config_desc() 取类特定片段，参与 wTotalLength 重算。
 *
 * 【需要实现（TODO）】
 *   [ ] usb_class_driver_t 结构定义
 *   [ ] 注册接口 + 接口号自动分配 + 绑定表维护
 *   [ ] 类请求路由逻辑
 *   [ ] 描述符片段钩子（与 usbd_desc 联动）
 *
 * 【依赖】usb_def.h / usbd_event.h / usbd_desc.h / usb_dcd.h。
 * 【参考】《MCU-USB 启动流程说明》§6.4；《USB新手从零搭建框架实践计划》M7。
 */

#ifndef __USBD_CLASS_H__
#define __USBD_CLASS_H__

/* TODO: 在此定义本文件内容（见上方职责清单） */

#endif /* __USBD_CLASS_H__ */

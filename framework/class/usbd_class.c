/**
 * @file usbd_class.c
 * @brief 类驱动框架实现（占位骨架，待实现）
 *
 * 【需要实现（TODO）】
 *   [ ] 类驱动注册表与接口号分配
 *   [ ] 接口 → 驱动、端点 → 驱动绑定表
 *   [ ] 类请求路由（按 bmRequestType 接收者字段）
 *   [ ] get_config_desc 钩子接入 usbd_desc 拼接流程
 *
 * 【验证】注册两个不同类驱动，路由与拼接均正确；未知类请求 Stall。
 * 【参考】《MCU-USB 启动流程说明》§6.4；《USB新手从零搭建框架实践计划》M7。
 */

#include "usbd_class.h"

/* TODO: 实现类驱动框架（见上方职责清单） */

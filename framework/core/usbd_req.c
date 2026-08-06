/**
 * @file usbd_req.c
 * @brief 标准请求处理器实现（占位骨架，待实现）
 *
 * 【需要实现（TODO）】
 *   [ ] 标准请求分发（GET_DESCRIPTOR / SET_ADDRESS / SET_CONFIGURATION /
 *       GET_STATUS / SET_FEATURE / CLEAR_FEATURE 等）
 *   [ ] 请求合法性校验（状态机状态、wValue/wIndex 范围），非法请求 → Stall
 *   [ ] 与描述符管理（usbd_desc）和状态机（usbd_fsm）联动
 *
 * 【验证】Mock DCD 驱动：完整枚举序列逐包断言；非法请求 Stall。
 * 【参考】《MCU-USB 启动流程说明》§6.3.3；《USB新手从零搭建框架实践计划》M5。
 */

#include "usbd_req.h"

/* TODO: 实现标准请求处理器（见上方职责清单） */

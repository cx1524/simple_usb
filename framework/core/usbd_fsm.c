/**
 * @file usbd_fsm.c
 * @brief 设备状态机实现（占位骨架，待实现）
 *
 * 【需要实现（TODO）】
 *   [ ] 状态枚举与当前状态变量
 *   [ ] usbd_set_state()：合法迁移表 + 非法跳转拒绝 + 钩子调用
 *   [ ] RESET 事件处理：状态回 DEFAULT、清设备地址、复位所有端点状态
 *   [ ] 端点激活/反激活钩子（最终落到 usb_dcd_ep_open / usb_dcd_ep_close）
 *
 * 【验证】单元测试遍历合法/非法迁移路径。
 * 【参考】《MCU-USB 启动流程说明》§6.3.1；《USB新手从零搭建框架实践计划》M3。
 */

#include "usbd_fsm.h"

/* TODO: 实现设备状态机（见上方职责清单） */

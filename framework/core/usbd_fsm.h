/**
 * @file usbd_fsm.h
 * @brief 设备状态机：USB 2.0 §9.1 状态定义与切换接口（纯软件，MCU 无关）
 *
 * 【所属层】第二层 USBD Core 子模块（core）。
 *
 * 【职责】
 *   1. 定义设备状态枚举：ATTACHED / POWERED / DEFAULT / ADDRESS / CONFIGURED。
 *   2. 提供集中式状态切换入口 usbd_set_state()，包含入口校验（拒绝非法跳转，
 *      如 DEFAULT 直接跳 CONFIGURED）。
 *   3. 状态切换钩子：进入 CONFIGURED 时激活业务端点，退出时反激活。
 *   4. 对外提供当前状态查询接口。
 *
 * 【需要实现（TODO）】
 *   [ ] 状态枚举定义
 *   [ ] usbd_set_state() 集中切换 + 非法跳转校验
 *   [ ] 进入/退出钩子注册机制
 *   [ ] 状态查询接口
 *
 * 【依赖】usb_def.h。
 * 【参考】《MCU-USB 启动流程说明》§6.3.1；USB 2.0 Spec §9.1。
 */

#ifndef __USBD_FSM_H__
#define __USBD_FSM_H__

/* TODO: 在此定义本文件内容（见上方职责清单） */

#endif /* __USBD_FSM_H__ */

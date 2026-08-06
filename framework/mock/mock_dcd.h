/**
 * @file mock_dcd.h
 * @brief Mock DCD：主机侧 DCD 仿真器，用于无硬件时验证协议层（验证工具，非框架本体）
 *
 * 【所属层】第一层 DCD 的验证替代品，严格实现 usb_dcd.h 接口契约。
 *
 * 【职责】
 *   1. 仿真 DCD 行为：模拟主机枚举流程（注入事件序列：RESET → ENUMDONE →
 *      逐条 SETUP → 业务传输）。
 *   2. 仿真端点：记录 usb_dcd_ep_write 的数据供断言比对；按 MPS 拆包回灌给
 *      OUT 接收（模拟主机发送数据）。
 *   3. 行为记录：记录协议层对 DCD 的每一次调用（接口/地址/Stall 序列），
 *      作为测试断言与调试日志。
 *
 * 【需要实现（TODO）】
 *   [ ] 实现 usb_dcd.h 全部接口（仿真语义）
 *   [ ] 枚举事件注入 API（模拟主机请求序列）
 *   [ ] 调用记录日志 + 断言比对辅助函数
 *
 * 【依赖】usb_def.h / usb_dcd.h。
 * 【参考】《USB新手从零搭建框架实践计划》M10。
 */

#ifndef __MOCK_DCD_H__
#define __MOCK_DCD_H__

/* TODO: 在此定义本文件内容（见上方职责清单） */

#endif /* __MOCK_DCD_H__ */

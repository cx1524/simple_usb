/**
 * @file usb_transfer.c
 * @brief 传输管理器实现（占位骨架，待实现）
 *
 * 【需要实现（TODO）】
 *   [ ] 每端点传输请求状态维护（占用/空闲）
 *   [ ] 发送：分包下发到 usb_dcd_ep_write + 完成回调驱动的下一包
 *   [ ] ZLP 自动追加（total_len 为 MPS 整数倍时）
 *   [ ] 接收：DCD OUT 完成回调 → 通知上层
 *
 * 【验证】Mock DCD 下连续发送 MPS 整数倍数据不卡死、字节一致。
 * 【参考】《MCU-USB 启动流程说明》§6.5；《USB新手从零搭建框架实践计划》M9。
 */

#include "usb_transfer.h"

/* TODO: 实现传输管理器（见上方职责清单） */

/**
 * @file usbd_ep0.c
 * @brief EP0 控制传输引擎实现（占位骨架，待实现）
 *
 * 【需要实现（TODO）】
 *   [ ] EP0 三阶段状态机（SETUP → DATA → STATUS）及各阶段迁移
 *   [ ] SETUP 包解析与分发（标准 → usbd_req；类 → usbd_class 路由；厂商 → Stall）
 *   [ ] DATA-IN 分包发送（MPS 拆包 + ZLP）+ DATA-OUT 接收
 *   [ ] Stall 策略（SETUP 绝不 Stall；DATA/STATUS 方向不匹配或请求不支持 → Stall）
 *   [ ] SET_ADDRESS：STATUS 完成后写地址（2 ms 窗口）
 *   [ ] 传输完成事件（DCD 回调）驱动阶段迁移
 *
 * 【验证】Mock DCD 驱动：GET_DESCRIPTOR(Device) 恰好回 18 字节；
 *        wLength=8 仅回 8 字节；非法请求 Stall 后可恢复。
 * 【参考】《MCU-USB 启动流程说明》§6.3.2；《USB新手从零搭建框架实践计划》M4。
 */

#include "usbd_ep0.h"

/* TODO: 实现 EP0 控制传输引擎（见上方职责清单） */

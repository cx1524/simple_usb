/**
 * @file usbd_cdc.c
 * @brief CDC ACM 类驱动实现（占位骨架，待实现）
 *
 * 【需要实现（TODO）】
 *   [ ] CDC 描述符片段（通信接口功能描述符链 + 数据接口 + 3 端点）
 *   [ ] 类请求处理（SET/GET_LINE_CODING、SET_CONTROL_LINE_STATE、SEND_BREAK）
 *   [ ] Bulk IN 发送 / Bulk OUT 循环接收
 *   [ ] CONFIGURED / RESET 事件处理
 *
 * 【验证】Mock DCD 下描述符树解析正确、类请求序列应答正确、Bulk 双向收发一致。
 * 【参考】《MCU-USB 启动流程说明》§6.4；USB CDC Spec 1.2；《USB新手从零搭建框架实践计划》M8。
 */

#include "usbd_cdc.h"

/* TODO: 实现 CDC ACM 类驱动（见上方职责清单） */

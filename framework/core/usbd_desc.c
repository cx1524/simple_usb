/**
 * @file usbd_desc.c
 * @brief 描述符管理实现（占位骨架，待实现）
 *
 * 【需要实现（TODO）】
 *   [ ] 描述符注册（设备/字符串/配置层级）与存储结构
 *   [ ] GET_DESCRIPTOR 查询分发（Device / Config / String）
 *   [ ] 配置描述符动态拼接：遍历配置 → 接口 → 类特定片段 → 端点，累加 wTotalLength
 *   [ ] wTotalLength 与实际返回长度自检断言
 *
 * 【验证】Mock DCD 下枚举序列逐包比对；wTotalLength == 实际长度。
 * 【参考】《MCU-USB 启动流程说明》§6.3.4；《USB新手从零搭建框架实践计划》M5。
 */

#include "usbd_desc.h"

/* TODO: 实现描述符管理（见上方职责清单） */

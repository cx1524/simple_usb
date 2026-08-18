/**
 * @file usb_def.h
 * @brief 协议基础层：USB 标准常量、SETUP 包、描述符结构体定义（MCU 无关）
 *
 * 【所属层】协议栈"字典"（core 基础），被 USBD Core / 类驱动 / 传输管理器共同依赖，
 *          不依赖任何硬件。
 *
 * 【职责】
 *   1. 描述符类型常量：DEVICE / CONFIGURATION / STRING / INTERFACE / ENDPOINT /
 *      DEVICE_QUALIFIER / IAD 等。
 *   2. usb_setup_packet_t：8 字节 SETUP 包结构（bmRequestType / bRequest /
 *      wValue / wIndex / wLength，Little-Endian）。
 *   3. bmRequestType 位域宏：D6-D5 请求类型（标准/类/厂商）、D4-D0 接收者（设备/接口/端点）。
 *   4. 标准请求码：GET_STATUS / CLEAR_FEATURE / SET_FEATURE / SET_ADDRESS /
 *      GET_DESCRIPTOR / SET_DESCRIPTOR / GET_CONFIGURATION / SET_CONFIGURATION /
 *      GET_INTERFACE / SET_INTERFACE / SYNCH_FRAME。
 *   5. 描述符结构体：usb_desc_device_t / usb_desc_configuration_t /
 *      usb_desc_interface_t / usb_desc_endpoint_t / 字符串描述符（对齐 USB 2.0 §9.6）。
 *   6. 辅助宏与枚举：端点地址宏（EP_NUM / EP_DIR_IN）、速度枚举（FS/HS）、
 *      传输类型（CTRL / ISO / BULK / INT）、错误码。
 *
 * 【需要实现（TODO）】
 *   [ ] 描述符类型常量定义
 *   [ ] usb_setup_packet_t 与 bmRequestType 位域宏
 *   [ ] 标准请求码定义
 *   [ ] 各类描述符结构体
 *   [ ] 端点地址宏 / 速度 / 传输类型 / 错误码枚举
 *
 * 【约束】仅依赖 <stdint.h> 等标准头，禁止包含任何 MCU 头文件。
 * 【参考】《MCU-USB 启动流程说明》§6.3.2 / §6.7；USB 2.0 Spec §9.6。
 */

#ifndef __USB_DEF_H__
#define __USB_DEF_H__

/* TODO: 在此定义本文件内容（见上方职责清单） */

/* Request type */
#define GET_STATUS 0x00
#define CLEAR_FEATURE 0x01
#define SET_FEATURE 0x03
#define SET_ADDRESS 0x05
#define GET_DESCRIPTOR 0x06
#define SET_CONFIGURATION 0x09
#define GET_INTERFACE 0x0A
#define SET_INTERFACE 0x0B
#define SYNCH_FRAME 0x0C


typedef struct SET_UP_PACKET_T{
    uint8_t bmRequestType; // direction[7:7] | request_type[6:5] | recipient[4:0]
    uint8_t bRequest;
    uint16_t wValue;
    uint16_t wIndex;
    uint16_t wLength;
} SET_UP_PACKET_T;


#endif /* __USB_DEF_H__ */

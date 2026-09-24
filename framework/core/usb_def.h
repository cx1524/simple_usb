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
 *   [x] 描述符类型常量定义
 *   [x] usb_setup_packet_t 与 bmRequestType 位域宏
 *   [x] 标准请求码定义
 *   [x] 各类描述符结构体
 *   [x] 端点地址宏 / 速度 / 传输类型 / 错误码枚举
 *
 * 【约束】仅依赖 <stdint.h> 等标准头，禁止包含任何 MCU 头文件。
 * 【参考】《MCU-USB 启动流程说明》§6.3.2 / §6.7；USB 2.0 Spec §9.6。
 */

#ifndef __USB_DEF_H__
#define __USB_DEF_H__

/* TODO: 在此定义本文件内容（见上方职责清单） */
#include <stdint.h>

#if defined(_MSC_VER)
    #define USB_PACKED
    #pragma pack(push, 1)
#else
    #define USB_PACKED __attribute__((packed))
#endif

/* @brief 端点地址宏定义 */
#define USB_EP_NUM(addr)      ((addr) & 0xF)
#define USB_EP_DIR_IN         (0x80)
#define USB_EP_DIR_OUT        (0x00)
#define USB_EP_ADDR(num, dir) ((num) | (dir))

// 速度枚举
#define USB_SPEED_LS          (0x00)
#define USB_SPEED_FS          (0x01)
#define USB_SPEED_HS          (0x02)

// 传输类型枚举
#define USB_TRANSFER_TYPE_CTRL    (0x00)
#define USB_TRANSFER_TYPE_ISO     (0x01)
#define USB_TRANSFER_TYPE_BULK    (0x02)
#define USB_TRANSFER_TYPE_INT     (0x03)

//错误码枚举
#define USB_ERROR_NONE 0x00
#define USB_ERROR_INVALID_PARAM 0x01
#define USB_ERROR_NOT_SUPPORTED 0x02
#define USB_ERROR_TIMEOUT 0x03
#define USB_ERROR_NOT_FOUND 0x04
#define USB_ERROR_INVALID_STATE 0x05
#define USB_ERROR_INVALID_LENGTH 0x06
#define USB_ERROR_INVALID_DATA 0x07
#define USB_ERROR_INVALID_ADDRESS 0x08
#define USB_ERROR_INVALID_ENDPOINT 0x09
#define USB_ERROR_INVALID_TRANSFER_TYPE 0x0A
#define USB_ERROR_INVALID_SPEED 0x0B
#define USB_ERROR_INVALID_ENDPOINT_DIR 0x0C
#define USB_ERROR_INVALID_ENDPOINT_NUM 0x0D
#define USB_ERROR_INVALID_ENDPOINT_DIR 0x0E
#define USB_ERROR_INVALID_ENDPOINT_NUM 0x0F
#define USB_ERROR_INVALID_ENDPOINT_DIR 0x10
#define USB_ERROR_INVALID_ENDPOINT_NUM 0x11
#define USB_ERROR_INVALID_ENDPOINT_DIR 0x12

/* @brief 描述符类型常量定义 */
#define USB_DESC_DEVICE 1
#define USB_DESC_CONFIGURATION 2
#define USB_DESC_STRING 3
#define USB_DESC_INTERFACE 4
#define USB_DESC_ENDPOINT 5
#define USB_DESC_DEVICE_QUALIFIER 6
#define USB_DESC_OTHER_SPEED_CONFIGUATION 7
#define USB_DESC_INTERFACE_POWER 8

/* @brief bmRequestType 位域宏定义 */
#define USB_REQUEST_TYPE_DIRECTION_OUT       0x00
#define USB_REQUEST_TYPE_DIRECTION_IN        0x80
#define USB_REQUEST_TYPE_TYPE_STANDARD       0x00
#define USB_REQUEST_TYPE_TYPE_CLASS          0x20
#define USB_REQUEST_TYPE_TYPE_VENDOR         0x40
#define USB_REQUEST_TYPE_RECIPIENT_DEVICE    0x00
#define USB_REQUEST_TYPE_RECIPIENT_INTERFACE 0x01
#define USB_REQUEST_TYPE_RECIPIENT_ENDPOINT  0x02
#define USB_REQUEST_TYPE_RECIPIENT_OTHER     0x03

/* @brief 标准请求码定义 */
#define USB_REQUEST_GET_STATUS 0x00
#define USB_REQUEST_CLEAR_FEATURE 0x01
#define USB_REQUEST_SET_FEATURE 0x03
#define USB_REQUEST_SET_ADDRESS 0x05
#define USB_REQUEST_GET_DESCRIPTOR 0x06
#define USB_REQUEST_SET_DESCRIPTOR 0x07
#define USB_REQUEST_GET_CONFIGURATION 0x08
#define USB_REQUEST_SET_CONFIGURATION 0x09
#define USB_REQUEST_GET_INTERFACE 0x0A
#define USB_REQUEST_SET_INTERFACE 0x0B
#define USB_REQUEST_SYNCH_FRAME 0x0C

/* @brief SETUP 包结构体定义 */
USB_PACKED typedef struct usb_setup_packet_t {
    uint8_t bmRequestType;
    uint8_t bRequest;
    uint16_t wValue;
    uint16_t wIndex;
    uint16_t wLength;
} usb_setup_packet_t;

/* @brief 各类描述符结构体定义 */

/* 标准设备描述符 */
USB_PACKED typedef struct usb_desc_device_t {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t bcdUSB;
    uint8_t bDeviceClass;
    uint8_t bDeviceSubClass;
    uint8_t bDeviceProtocol;
    uint8_t bMaxPacketSize0;
    uint16_t idVendor;
    uint16_t idProduct;
    uint16_t bcdDevice;
    uint8_t iManufacturer;
    uint8_t iProduct;
    uint8_t iSerialNumber;
    uint8_t bNumConfigurations;
} usb_desc_device_t;

USB_PACKED typedef struct usb_desc_device_qualifier_t {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t bcdUSB;
    uint8_t bDeviceClass;
    uint8_t bDeviceSubClass;
    uint8_t bDeviceProtocol;
    uint8_t bMaxPacketSize0;
    uint8_t bNumConfigurations;
    uint8_t bReserved;
} usb_desc_device_qualifier_t;

USB_PACKED typedef struct usb_desc_configuration_t {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t wTotalLength;
    uint8_t bNumInterfaces;
    uint8_t bConfigurationValue;
    uint8_t iConfiguration;
    uint8_t bmAttributes;
    uint8_t bMaxPower;
} usb_desc_configuration_t;

USB_PACKED typedef struct usb_desc_other_speed_configuration_t {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint16_t wTotalLength;
    uint8_t bNumInterfaces;
    uint8_t bConfigurationValue;
    uint8_t iConfiguration;
    uint8_t bmAttributes;
    uint8_t bMaxPower;
} usb_desc_other_speed_configuration_t;

USB_PACKED typedef struct usb_desc_interface_t {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bInterfaceNumber;
    uint8_t bAlternateSetting;
    uint8_t bNumEndpoints;
    uint8_t bInterfaceClass;
    uint8_t bInterfaceSubClass;
    uint8_t bInterfaceProtocol;
    uint8_t iInterface;
} usb_desc_interface_t;

USB_PACKED typedef struct usb_desc_endpoint_t {
    uint8_t bLength;
    uint8_t bDescriptorType;
    uint8_t bEndpointAddress;
    uint8_t bmAttributes;
    uint16_t wMaxPacketSize;
    uint8_t bInterval;
} usb_desc_endpoint_t;

#endif /* __USB_DEF_H__ */

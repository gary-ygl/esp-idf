// Copyright 2015-2016 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef _SOC_GPIO_STRUCT_H_
#define _SOC_GPIO_STRUCT_H_
typedef struct {
    volatile uint32_t bt_select;                             /*NA*/
    volatile uint32_t out;                                   /*GPIO0~31 output value*/
    volatile uint32_t out_w1ts;                              /*GPIO0~31 output value write 1 to set*/
    volatile uint32_t out_w1tc;                              /*GPIO0~31 output value write 1 to clear*/
    union {
        struct {
            volatile uint32_t out_data:   8;                 /*GPIO32~39 output value*/
            volatile uint32_t reserved8: 24;
        };
        volatile uint32_t val;
    }out1;
    union {
        struct {
            volatile uint32_t out_data:   8;                 /*GPIO32~39 output value write 1 to set*/
            volatile uint32_t reserved8: 24;
        };
        volatile uint32_t val;
    }out1_w1ts;
    union {
        struct {
            volatile uint32_t out_data:   8;                 /*GPIO32~39 output value write 1 to clear*/
            volatile uint32_t reserved8: 24;
        };
        volatile uint32_t val;
    }out1_w1tc;
    union {
        struct {
            volatile uint32_t sdio_sel:   8;                 /*SDIO PADS on/off control from outside*/
            volatile uint32_t reserved8: 24;
        };
        volatile uint32_t val;
    }sdio_select;
    volatile uint32_t enable;                                /*GPIO0~31 output enable*/
    volatile uint32_t enable_w1ts;                           /*GPIO0~31 output enable write 1 to set*/
    volatile uint32_t enable_w1tc;                           /*GPIO0~31 output enable write 1 to clear*/
    union {
        struct {
            volatile uint32_t enable_data: 8;                /*GPIO32~39 output enable*/
            volatile uint32_t reserved8:  24;
        };
        volatile uint32_t val;
    }enable1;
    union {
        struct {
            volatile uint32_t enable_data: 8;                /*GPIO32~39 output enable write 1 to set*/
            volatile uint32_t reserved8:  24;
        };
        volatile uint32_t val;
    }enable1_w1ts;
    union {
        struct {
            volatile uint32_t enable_data: 8;                /*GPIO32~39 output enable write 1 to clear*/
            volatile uint32_t reserved8:  24;
        };
        volatile uint32_t val;
    }enable1_w1tc;
    union {
        struct {
            volatile uint32_t strapping: 16;                 /*GPIO strapping results: {2'd0  boot_sel_dig[7:1]  vsdio_boot_sel  boot_sel_chip[5:0]}.   Boot_sel_dig[7:1]: {U0RXD  SD_CLK  SD_CMD  SD_DATA0  SD_DATA1  SD_DATA2  SD_DATA3}.  vsdio_boot_sel: MTDI. boot_sel_chip[5:0]: {GPIO0  U0TXD  GPIO2  GPIO4  MTDO  GPIO5}*/
            volatile uint32_t reserved16:16;
        };
        volatile uint32_t val;
    }strap;
    volatile uint32_t in;                                    /*GPIO0~31 input value*/
    union {
        struct {
            volatile uint32_t in_data: 8;                    /*GPIO32~39 input value*/
            volatile uint32_t reserved8:   24;
        };
        volatile uint32_t val;
    }in1;
    volatile uint32_t status;                                /*GPIO0~31 interrupt status*/
    volatile uint32_t status_w1ts;                           /*GPIO0~31 interrupt status write 1 to set*/
    volatile uint32_t status_w1tc;                           /*GPIO0~31 interrupt status write 1 to clear*/
    union {
        struct {
            volatile uint32_t status_interrupt: 8;           /*GPIO32~39 interrupt status*/
            volatile uint32_t reserved8:       24;
        };
        volatile uint32_t val;
    }status1;
    union {
        struct {
            volatile uint32_t status_interrupt: 8;           /*GPIO32~39 interrupt status write 1 to set*/
            volatile uint32_t reserved8:       24;
        };
        volatile uint32_t val;
    }status1_w1ts;
    union {
        struct {
            volatile uint32_t status_interrupt: 8;           /*GPIO32~39 interrupt status write 1 to clear*/
            volatile uint32_t reserved8:       24;
        };
        volatile uint32_t val;
    }status1_w1tc;
    volatile uint32_t reserved_5c;
    volatile uint32_t acpu_int;                              /*GPIO0~31 APP CPU interrupt status*/
    volatile uint32_t acpu_nmi_int;                          /*GPIO0~31 APP CPU non-maskable interrupt status*/
    volatile uint32_t pcpu_int;                              /*GPIO0~31 PRO CPU interrupt status*/
    volatile uint32_t pcpu_nmi_int;                          /*GPIO0~31 PRO CPU non-maskable interrupt status*/
    volatile uint32_t cpusdio_int;                           /*SDIO's extent GPIO0~31 interrupt*/
    union {
        struct {
            volatile uint32_t appcpu_int: 8;                 /*GPIO32~39 APP CPU interrupt status*/
            volatile uint32_t reserved8: 24;
        };
        volatile uint32_t val;
    }acpu_int1;
    union {
        struct {
            volatile uint32_t appcpu_nmi_int: 8;             /*GPIO32~39 APP CPU non-maskable interrupt status*/
            volatile uint32_t reserved8:     24;
        };
        volatile uint32_t val;
    }acpu_nmi_int1;
    union {
        struct {
            volatile uint32_t procpu_int: 8;                 /*GPIO32~39 PRO CPU interrupt status*/
            volatile uint32_t reserved8: 24;
        };
        volatile uint32_t val;
    }pcpu_int1;
    union {
        struct {
            volatile uint32_t procpu_nmi_int: 8;             /*GPIO32~39 PRO CPU non-maskable interrupt status*/
            volatile uint32_t reserved8:     24;
        };
        volatile uint32_t val;
    }pcpu_nmi_int1;
    union {
        struct {
            volatile uint32_t sdio_int:   8;                 /*SDIO's extent GPIO32~39 interrupt*/
            volatile uint32_t reserved8: 24;
        };
        volatile uint32_t val;
    }cpusdio_int1;
    union {
        struct {
            volatile uint32_t reserved0:         2;
            volatile uint32_t pin_pad_driver:    1;         /*if set to 0: normal output  if set to 1: open drain*/
            volatile uint32_t reserved3:         4;
            volatile uint32_t pin_int_type:      3;         /*if set to 0: GPIO interrupt disable  if set to 1: rising edge trigger  if set to 2: falling edge trigger  if set to 3: any edge trigger  if set to 4: low level trigger  if set to 5: high level trigger*/
            volatile uint32_t pin_wakeup_enable: 1;         /*GPIO wake up enable  only available in light sleep*/
            volatile uint32_t pin_config:        2;         /*NA*/
            volatile uint32_t pin_int_ena:       5;         /*bit0: APP CPU interrupt enable  bit1: APP CPU non-maskable interrupt enable  bit3: PRO CPU interrupt enable  bit4:  PRO CPU non-maskable interrupt enable  bit5: SDIO's extent interrupt enable*/
            volatile uint32_t reserved18:       14;
        };
        volatile uint32_t val;
    }pin[40];
    union {
        struct {
            volatile uint32_t cali_rtc_max:10;
            volatile uint32_t reserved10:  21;
            volatile uint32_t cali_start:   1;
        };
        volatile uint32_t val;
    }cali_conf;
    union {
        struct {
            volatile uint32_t cali_value_sync2:20;
            volatile uint32_t reserved20:      10;
            volatile uint32_t cali_rdy_real:    1;
            volatile uint32_t cali_rdy_sync2:   1;
        };
        volatile uint32_t val;
    }cali_data;
    union {
        struct {
            volatile uint32_t func_in_sel:     6;           /*select one of the 256 inputs*/
            volatile uint32_t func_in_inv_sel: 1;           /*revert the value of the input if you want to revert  please set the value to 1*/
            volatile uint32_t sig_in_sel:      1;           /*if the slow signal bypass the io matrix or not if you want  setting the value to 1*/
            volatile uint32_t reserved8:      24;           /*The 256 registers below are selection control for 256 input signals connected to GPIO matrix's 40 GPIO input  if GPIO_FUNCx_IN_SEL is set to n(0<=n<40): it means GPIOn input is used for input signal x  if GPIO_FUNCx_IN_SEL is set to 0x38: the input signal x is set to 1   if GPIO_FUNCx_IN_SEL is set to 0x30: the input signal x is set to 0*/
        };
        volatile uint32_t val;
    }func_in_sel_cfg[256];
    union {
        struct {
            volatile uint32_t func_out_sel:     9;          /*select one of the 256 output to 40 GPIO*/
            volatile uint32_t func_out_inv_sel: 1;          /*invert the output value  if you want to revert the output value  setting the value to 1*/
            volatile uint32_t func_oen_sel:     1;          /*weather using the logical oen signal or not using the value setting by the register*/
            volatile uint32_t func_oen_inv_sel: 1;          /*invert the output enable value  if you want to revert the output enable value  setting the value to 1*/
            volatile uint32_t reserved12:      20;          /*The 40 registers below are selection control for 40 GPIO output  if GPIO_FUNCx_OUT_SEL is set to n(0<=n<256): it means GPIOn input is used for output signal x  if GPIO_FUNCx_OUT_INV_SEL is set to 1  the output signal x is set to ~value.  if GPIO_FUNC0_OUT_SEL is 256 or GPIO_FUNC0_OEN_SEL is 1 using GPIO_ENABLE_DATA[x] for the enable value else using the signal enable*/
        };
        volatile uint32_t val;
    }func_out_sel_cfg[40];
} gpio_dev_t;
extern volatile gpio_dev_t GPIO;
#endif  /* _SOC_GPIO_STRUCT_H_ */

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
#ifndef _SOC_GPIO_SD_STRUCT_H_
#define _SOC_GPIO_SD_STRUCT_H_
typedef struct {
    union {
        struct {
            volatile uint32_t sd_in:       8;
            volatile uint32_t prescale:    8;
            volatile uint32_t reserved16: 16;
        };
        volatile uint32_t val;
    }sigmadelta[8];
    union {
        struct {
            volatile uint32_t reserved0: 31;
            volatile uint32_t clk_en:     1;
        };
        volatile uint32_t val;
    }sigmadelta_cg;
    union {
        struct {
            volatile uint32_t reserved0: 31;
            volatile uint32_t spi_swap:   1;
        };
        volatile uint32_t val;
    }sigmadelta_misc;
    union {
        struct {
            volatile uint32_t date:      28;
            volatile uint32_t reserved28: 4;
        };
        volatile uint32_t val;
    }sigmadelta_version;
} gpio_sd_dev_t;
extern volatile gpio_sd_dev_t SIGMADELTA;
#endif  /* _SOC_GPIO_SD_STRUCT_H_ */

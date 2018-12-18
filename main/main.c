#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_bt.h"


#include "esp_gap_ble_api.h"
#include "esp_gatts_api.h"
#include "esp_bt_defs.h"
#include "esp_bt_main.h"



void enableFlushAfterPrintf()
{
    setvbuf(stdout, 0, _IONBF, 0);
    setvbuf(stdin, 0, _IONBF, 0);
}

void input_task(void *p){
    while(1){
        puts("test task input \n");
    }
}

void bluetooth_server_task(void *p){
    while(1){
        puts("test task output \n");
    }
}

void app_main(void){
    enableFlushAfterPrintf();

    esp_err_t ret;

    // Initialize NVS.
    ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        puts("Cannot initialize flash  \n");
        ret = nvs_flash_init();
    }

    esp_bt_controller_config_t bt_cfg = BT_CONTROLLER_INIT_CONFIG_DEFAULT();
    ret = esp_bt_controller_init(&bt_cfg);
    if (ret) {
        puts("Cannot initialize bt  \n");
        return;
    }

    ret = esp_bt_controller_enable(ESP_BT_MODE_BLE);
    if (ret) {
        puts("Cannot enable bt  \n");
        return;
    }




    // puts("test task input \n");
    // xTaskCreate(bluetooth_server_task, "Task 1", 1000, NULL, 1, NULL );
    // xTaskCreate(input_task, "Task 2",1000, NULL, 1, NULL );
      
}

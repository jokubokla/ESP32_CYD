//============================================================================
//
//  CYD_EEZ_V1 - Cheap Yellow Display - EEZ Studio generierter Code
//
//  main.cpp ist NICHT generiert
//
//  Version 1.0 - 14.09.2025
//  (c) 2025 by Johannes Kepler University Linz (JKU von der KI erweitert)
//
//============================================================================

#include "touchscreen.h"
#include "ui.h"

//============================================================================
//
//============================================================================
static void button_event_blue(lv_event_t *e) 
{
  lv_event_code_t code = lv_event_get_code(e);

  if(code == LV_EVENT_CLICKED)
  {
    static uint8_t counter = 0;
    counter ++;
    lv_label_set_text_fmt(objects.lbl_beispiel, "Hier wurde %d mal geklicked", counter);
  }
}

//============================================================================
//
//============================================================================
static void button_event_red(lv_event_t *e) 
{
  lv_event_code_t code = lv_event_get_code(e);

  if(code == LV_EVENT_CLICKED)
  {

   if(lv_obj_has_state(objects.chk_test, LV_STATE_CHECKED))
   {
     // Checkbox is checked
    lv_label_set_text_fmt(objects.lbl_beispiel, "Checkbox is checked");
   }
   else
   {
     // Checkbox is not checked
    lv_label_set_text_fmt(objects.lbl_beispiel, "Checkbox is not checked");
   }

  }

}

//============================================================================
//
//============================================================================
void setup() 
{
  touchscreen_setup();
  ui_init();
  
  lv_obj_add_event_cb(objects.btn_blue, button_event_blue, LV_EVENT_ALL, NULL);
  lv_obj_add_event_cb(objects.btn_red, button_event_red, LV_EVENT_ALL, NULL);
}

//============================================================================
//
//============================================================================
void loop() 
{
  lv_task_handler();
  lv_tick_inc(5);
  delay(5);
}

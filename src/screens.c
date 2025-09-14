#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // lbl_sample
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_sample = obj;
            lv_obj_set_pos(obj, 86, 190);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "This is a Sample Text");
        }
        {
            // btn_blue
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.btn_blue = obj;
            lv_obj_set_pos(obj, 28, 41);
            lv_obj_set_size(obj, 120, 50);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2137f3), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // btn_blue_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.btn_blue_label = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Click me");
                }
            }
        }
        {
            // btn_red
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.btn_red = obj;
            lv_obj_set_pos(obj, 176, 41);
            lv_obj_set_size(obj, 120, 50);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff3213d), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // btn_red_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.btn_red_label = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Or me....");
                }
            }
        }
        {
            // chk_Test
            lv_obj_t *obj = lv_checkbox_create(parent_obj);
            objects.chk_test = obj;
            lv_obj_set_pos(obj, 109, 131);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_checkbox_set_text(obj, "Checkbox");
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
}



typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
}

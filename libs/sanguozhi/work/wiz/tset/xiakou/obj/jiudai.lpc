//  jiudai.c
//  酒袋
//  created by tset 1/17/98
//  last updated by tset 1/19/98

#include <sanguo.h>

inherit M_VALUE;
inherit OBJ;
inherit M_GETTABLE;
inherit M_DRINK_CONTAINER;
inherit M_DRINKABLE;

void setup() {
        set_id("jiudai", "酒袋", "skin");
        set_long("一个可以装酒和水的酒袋。");
        set_gettable(1);
        set_num_drinks(5);
        set_value(100);
        set_currency_type("coin");
        set_con("米酒");
   set_drink_action((: this_body()->simple_action("$N拿起酒袋喝了几口"+
        query_con()+"。\n") :));
   set_last_drink_action( (: this_body()->simple_action("$N摇了摇酒袋，"+
        "一扬脖把里面的"+query_con()+"喝得一干二尽。\n") :));
   set_finish_drink_action( (: write("酒袋已经空了。\n") :));
}


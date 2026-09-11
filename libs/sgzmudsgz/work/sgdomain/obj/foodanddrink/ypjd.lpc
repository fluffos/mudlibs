// by fire on Dce 11, 1997 yangpi_jiudai.c 羊皮酒袋
#include <sanguo.h>
inherit M_VALUE;
inherit OBJ;
inherit M_GETTABLE;
inherit M_DRINKABLE;
void setup()
{   set_id("skin", "羊皮酒袋", "jiudai");
    set_long("一个可以装酒和水的羊皮酒袋。");
    set_gettable(1);
    set_max_drinks(15);
	set_num_drinks(5);
    set_value(50);
    set_currency_type("coin");
    set_con("烧酒");
    set_drink_action((: this_body()->simple_action("$N拿起羊皮酒袋喝了几口"+query_con()+"。\n") :));
    set_last_drink_action( (: this_body()->simple_action("$N摇了摇羊皮酒袋，一扬脖把里面的"+query_con()+"喝得一干二尽。\n") :));
    set_finish_drink_action( (: write("羊皮酒袋已经空了。\n") :));
}

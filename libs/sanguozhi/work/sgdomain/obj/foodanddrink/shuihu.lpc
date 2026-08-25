// shuihu.c by fire on 1999, Jan
inherit OBJ;
inherit M_GETTABLE;
inherit M_DRINKABLE;
void setup()
{   set_id("shuihu", "水壶");
    set_long("一个可以装水的木水壶。");
    set_gettable(1);
    set_max_drinks(20);
    set_con("清水");
    set_drink_action((: this_body()->simple_action("$N拿起水壶喝了几口"
		+query_con()+"。\n") :));
    set_last_drink_action( (: this_body()->simple_action("$N摇了摇水壶，一扬脖把里面的"+query_con()+"喝得一干二尽。\n") :));
    set_finish_drink_action( (: write("水壶已经空了。\n") :));
}

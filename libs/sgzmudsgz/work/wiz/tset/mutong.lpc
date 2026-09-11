// mutong.c "牧童"
#include <mudlib.h>
inherit LIVING;
inherit M_ITEMS;

void setup() {
    set_name("boy", "牧童");
    set_gender(1);
    set_proper_name("小牧童");
    set_in_room_desc("放牛的小牧童(boy)");
    set_long("小牧童正懒洋洋地躺在老黄牛背上，用草帽遮着太阳，手上时不时玩弄着一柄短笛。");

    add_item("短笛", "flute", "duan di",
		([ "look" : "一柄手制的短笛。",
		]) );
    add_item("草帽", "hat", "caomao",
                 ([     "look" : "一顶破草帽。",
                        "get" : "你取不下来。",
                 ]) );
}

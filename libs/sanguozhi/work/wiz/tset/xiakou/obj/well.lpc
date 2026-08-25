//  well.c
//  井
//  created by tset 1/19/98
//  last updated by tset 1/19/98

#include <mudlib.h>
#include <ansi.h>

inherit OBJ;
inherit M_DRINK_CONTAINER;
inherit M_DRINKABLE;

int always_usable() { return 1; }       // drink without acquire

void setup() {
        set_id("well", "水井", "jing");
        set_long("一口浅浅的水井，井边有个水瓢用来打水。");
        set_in_room_desc("一口浅浅的水井。\n");
        set_num_drinks(100);
        set_con("井水");
   set_drink_action((: this_body()->simple_action("$N俯身舀起一瓢"+
        query_con()+"，咕嘟咕嘟一口气喝得干干净净。\n") :));
   set_last_drink_action( (: this_body()->simple_action(YEL+"$N拿起水瓢，"+
        "舀出最后一滴"+query_con()+"，喝得一干二尽。\n"+NOR) :));
   set_finish_drink_action( (: write(RED+"水井枯竭了。\n"+NOR) :));
}


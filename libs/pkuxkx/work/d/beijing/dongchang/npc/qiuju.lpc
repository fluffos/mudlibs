// qiuju.c 邱聚

#include <ansi.h>
#include "/d/beijing/autok.h"
#include "autocheck.h"

inherit NPC;

void create()
{
        set_name("邱聚", ({"qiu ju", "qiu",}));
        set("title", YEL"『内侍八虎』" + MAG"值殿监掌印太监"NOR);
        set("long",
                "待添加。\n\n"
        );

        set("gender", "无性");
        set("rank_info/respect", "公公");

        set("attitude", "heroism");
        set("class", "eunuch");
/*
        set("inquiry",([
                "自宫"  : (: ask_for_zigong :),
                "东厂"  : (: ask_for_dongchang :),
                "关防印": (: ask_yin :),
        ]));
*/
        set("age", 50 + random(20));
        set("shen_type", -1);

				set("pin", 2);
//				set("yin_count", 5);
				
				set("combat_exp", 1000);
	
        set("chat_chance", 15);
        set("chat_msg", ({
//                (: random_move :)
        }) );
        
				setup();

        carry_object("/d/beijing/dongchang/obj/guanfu")->wear();
//        add_money("silver", 50);
}

void init()
{
	object ob;

	::init();
	if( !query_heart_beat(this_object()) ) set_heart_beat(1);

//	add_action("do_join", "join");
	
	ob = this_player();
	do_check(ob, this_object());
}
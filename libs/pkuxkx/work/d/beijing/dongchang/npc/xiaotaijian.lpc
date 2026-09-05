// xiaotaijian.c 小太监

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("小太监", ({"xiao taijian", "taijian",}));
//        set("title", YEL"『小太监』"NOR);
        set("long",
                "一个无精打采的小太监。\n"
        );

        set("gender", "无性");
        set("rank_info/respect", "公公");

        set("attitude", "heroism");
        set("class", "eunuch");

        set("inquiry",([

        ]));

        set("age", 14 + random(5));
        set("shen_type", -1);

				set("pin", 9);
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
}

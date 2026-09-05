// xiaofan
#include <ansi.h>

inherit NPC;
inherit F_DEALER;


void create()
{
	set_name("小贩", ({ "xiao fan", "seller" }));
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 15+random(45));
        set("long", "他是一个挑着食担的小贩。\n");
	set("combat_exp", 50000);
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
	set("vendor_goods", ({
                
                "/d/lingjiu/obj/suanmei",
      
                "/clone/food/shengjian-mantou",
                "/clone/food/su-jianjiao",
                "/d/xingxiu/npc/obj/case",
	}));
        

	setup();
        
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

#include "die.h"
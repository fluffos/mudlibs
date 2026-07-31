//NPC:/d/suzhou/npc/axiu.c 
//by dwolf
//97.11.4 

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name(HIW"阿绣"NOR, ({ "a xiu", "xiu" }));
	set("title", YEL"当铺老板"NOR);
	set("shen_type", 10);

	set("gender", "女性");
	set_max_encumbrance(100000000);
	set("age", 25);
	set("long",
		"阿绣是个老muder,后来她不玩了，改行当上老板了。真让人羡慕。\n");
	set("no_get_from", 1);
        set("no_get",1);

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_temp("apply/attack", 100);
	set_temp("apply/attack", 100);
	set_temp("apply/damage", 45);

	set("combat_exp", 100000);
	set("attitude", "friendly");
	
	setup();
	carry_object("/obj/cloth")->wear();
	add_money("gold", 3);
}

void init()
{
        add_action("do_vendor_list", "list");
}

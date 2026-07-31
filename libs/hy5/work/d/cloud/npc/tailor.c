
// tailor.c
#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("裁缝", ({ "tailor" }) );
        set("title", "布庄");
        set("gender", "男性" );
        set("age", 42);
        set("long", "一位看上去很和蔼的老裁缝，正在缝制衣服。\n");
	set("str", 12);
	set("int", 24);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("sword", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);

//        set("where","north");
        set("inquiry", ([
		"香茗坊" : "您也知道'碧海银针'？茶楼就在斜对面，我常去的。", 
        ]) );
set("vendor_goods", ({
		"/d/city/npc/cloth/belt",
		"/d/city/npc/cloth/boots",
		"/d/city/npc/cloth/bu-shoes",
		"/d/city/npc/cloth/cloth",
		"/d/city/npc/cloth/color-dress",
		"/d/city/npc/cloth/fu-cloth",
		"/d/city/npc/cloth/gui-dress",
		"/d/city/npc/cloth/hat",
		"/d/city/npc/cloth/jade-belt",
		"/d/city/npc/cloth/liu-dress",
		"/d/city/npc/cloth/marry-dress",
		"/d/city/npc/cloth/mini-dress",
		"/d/city/npc/cloth/moon-dress",
		"/d/city/npc/cloth/pink-dress",
		"/d/city/npc/cloth/qi-dress",
		"/d/city/npc/cloth/red-dress",
		"/d/city/npc/cloth/scarf",
		"/d/city/npc/cloth/sha-dress",
		"/d/city/npc/cloth/xian-cloth",
		"/d/city/npc/cloth/xiu-cloth",
		"/d/city/npc/cloth/xiu-scarf",
		"/d/city/npc/cloth/yan-dress",
		"/d/city/npc/cloth/zi-dress",
	}));

	setup();
	add_money("silver", 2);
	add_money("coin", 50);
        carry_object("/clone/misc/cloth")->wear();

}

void init()
{
        object ob;

        ::init();
	add_action("do_list", "list");
	add_action("do_buy", "buy");
        
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 0:
                        say( "老裁缝抬起头看了你一眼，问道：客官买布还是制衣?\n");
                        break;
                case 1:
                        say( "裁缝的手脚甚是麻利，显然已做了多年了。\n");
	}
}


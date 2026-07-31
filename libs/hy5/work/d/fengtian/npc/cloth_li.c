// cloth_li.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;



mapping clothes = ([
	"t_chougua" : ([
		"name" : HIC"蓝缎大氅"NOR,
		"value": 250000,]),
	"b_chougua" : ([
		"name" : HIB"宝蓝绸袄"NOR,
		"value": 220000,]),
	"s_skirt"   : ([
		"name" : WHT HIM"镂花长裙"NOR,
		"value": 250000,]),
	"l_skirt"   : ([
		"name" : WHT HIG"绿玉长裙"NOR,
		"value": 300000,]),
]);

void create()
{
        set_name("李大姐", ({ "boss li","li" }) );
	set("title","巧手");
        set("gender", "女性" );
        set("age", 45);
        set("long","这是一位精干的中年妇女。\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
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
	carry_object(__DIR__"obj/hua_skirt")->wear();
}


void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");

}
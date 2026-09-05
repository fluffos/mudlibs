// /d/beijing/npc/xilaile.c
// Npc: 神医喜来乐
// Date: 2003.3
// by vast

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("喜来乐", ({"xi laile", "xi",}));
	set("title", HIC"一笑堂大夫"NOR);
	set("nickname", HIR"神医"NOR);
	set("long",
		"他就是河北沧州有名的神医，在这个兵荒马乱的年代来到京城行医，\n"
              "他看起来很和蔼，有什么疑难杂症都可以请他医治。\n"
	);


	set("gender", "男性");
	set("attitude", "heroism");
	set("rank_info/respect", "大夫");

	set("age", 50);
	set("shen_type",1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 900);
	set("max_jing", 900);
	set("neili", 900);
	set("max_neili", 900);
	set("combat_exp", 10000);
	set("score", 100);


	setup();

	carry_object("/clone/armor/cloth")->wear();
}


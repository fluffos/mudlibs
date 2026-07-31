// tong2.c 右僮

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("右僮", ({ "you tong", "you", "tong" }) );
	set("gender", "男性");
	set("age", 13);
	set("long","他是雪山飞狐胡斐的童子。\n");
	set("attitude", "friendly");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 1200000);
	set_skill("dodge", 100);
	set_skill("force", 100);
	set_skill("sword", 300);
	set_skill("cuff", 100);
	set_skill("hand", 100);


	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/yinjian")->wield();
}

// yang.c 杨成协

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("杨成协", ({ "yang chengxie", "yang","chengxie" }));
	set("title", HIR "红花会"HIG"八当家" NOR);
	set("nickname", CYN "铁塔" NOR);
	set("long", 
"他又肥又高，手执钢鞭，鞭身甚是粗重，看模样少说也有三十来斤。\n");
	set("gender", "男性");
	set("class", "fighter");
	set("age", 26);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 21500);
	set("max_jing", 22900);
	set("neili", 20000);
	set("max_neili", 20000);
	set("jiali", 100);
	set("combat_exp", 700000);

	set_skill("force", 260);
	set_skill("dodge", 260);
	set_skill("parry", 260);
	set_skill("whip", 260);
	set_skill("hand", 260);
	set_skill("claw", 260);
	set_skill("yunlong-shengong", 260);
	set_skill("yunlong-shenfa", 260);
	set_skill("yunlong-bian", 260);
	set_skill("yunlong-shou", 260);
	set_skill("yunlong-zhua", 260);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-bian");
	map_skill("claw", "yunlong-zhua");
	map_skill("whip", "yunlong-bian");

	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");
	set("env/wimpy", 20);

 	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/tiebian")->wield();
}


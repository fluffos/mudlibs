// xu.c 徐天宏

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("徐天宏", ({ "xu tianhong", "xu","tianhong" }));
	set("title", HIR "红花会"HIG"七当家" NOR);
	set("nickname", HIC "武诸葛" NOR);
	set("long", 
"其人身材矮小，足智多谋，是红花会的智囊军师，武功也颇
不弱，冷静持重。\n");
	set("gender", "男性");
	set("class", "scholar");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 19);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 17800);
	set("max_jing", 17800);
	set("neili", 31000);
	set("max_neili", 31000);
	set("jiali", 100);
	set("combat_exp", 750000);

	set_skill("literate", 180);
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("blade", 180);
	set_skill("hand", 180);
	set_skill("claw", 180);
	set_skill("yunlong-shengong", 280);
	set_skill("wuhu-duanmendao", 280);
	set_skill("yunlong-shenfa", 280);
	set_skill("yunlong-shou", 280);
	set_skill("yunlong-zhua", 280);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "wuhu-duanmendao");
	map_skill("claw", "yunlong-zhua");

	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");
	set("env/wimpy", 20);

 	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}


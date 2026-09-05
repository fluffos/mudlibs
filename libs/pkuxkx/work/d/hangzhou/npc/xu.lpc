// xu.c 徐天宏

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
#include "/new_quest/qzhengpai.h"
#include "/new_quest/quest.h"

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
	
	set("max_qi", 2000);
	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("combat_exp", 3500000);

	set_skill("literate", 200);
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("sword", 180);

	set_skill("bingchuan-xinfa", 180);
	set_skill("zhuangzi-mengwu", 180);
	set_skill("luohua-jian",     180);

	map_skill("dodge", "zhuangzi-mengwu");
	map_skill("force", "bingchuan-xinfa");
	map_skill("sword", "luohua-jian");
	map_skill("parry", "luohua-jian");

	set("env/wimpy", 20);
        create_family("红花会", 3, "弟子");
        set("inquiry", ([
        "quest":   (: ask_quest() :),
        "cancelquest":   (: ask_cancel() :),
        "取消任务":   (: ask_cancel() :),
      ]));

 	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}



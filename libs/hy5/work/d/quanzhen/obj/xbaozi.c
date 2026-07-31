//Cracked by Roath
// /clone/beast/xbaozi.c
// 小豹子
// sdong 08/98
// Modified by xQin 11/00

#include <ansi.h>
inherit NPC;


void create()
{
		  set_name("小豹子", ({ "xiao baozi", "baozi" }) );
set("no_get",1);
	set("race", "野兽");
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
		  set("long", "一只身体不大可是很结实的小豹子，它正瞪着眼睛看着你。\n");
		  set("attitude", "aggressive");
		  set("max_qi", 100);
		  set("max_jing", 100);
		  set("max_jingli", 100);


		  set("str", 30);
		  set("con", 80);
		  set("dex", 30);
		  set("int", 10);

		  set("combat_exp", 20000);

		  set_temp("apply/attack", 10);
		  set_temp("apply/damage", 10);
		  set_temp("apply/armor", 10);

		  setup();
}void unconcious()
{
    die();
}

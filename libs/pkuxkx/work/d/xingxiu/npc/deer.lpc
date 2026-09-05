// 小鹿
// created by zine 2 Sep 2010

inherit NPC;
#include <ansi.h>

void create()
{
	set_name(YEL"小鹿"NOR, ({ "xiao lu", "deer" }) );
	set("race", "野兽");
	set("age", random(2));
	set("long", "一只可爱的小鹿正好奇地望着你。\n");
	set("max_qi", 1);
	set("qi", 1);
	set("str", 10);
	set("con", 1);
	set("dex", 1);
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
	set("combat_exp", 1);
	set("chat_chance", 5);
        set("chat_msg", ({
           (:random_move:),
        }) );
	setup();
}

#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIW"小鹿"NOR, ({ "xiao lu", "lu", "deer" }) );
	set("race", "野兽");
	set("age", 5);
	set("long", "一只可爱的小鹿。见有人来，睁着圆圆的眼珠相望，\n"
                    "显得十分好奇，却殊无惊怕之意。\n");
	set("attitude", "peaceful");
	
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
        set("max_qi",4000);
        set("qi",4000);
	set("combat_exp", 900000);
	set_temp("apply/attack", 2);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 2);
	set_temp("apply/armor", 1);
	set("shen_type",1);set("score",200);setup();  
        carry_object(__DIR__"obj/lurou");
}
void die()
{
	object ob;
	message_vision("$N凄惨的望着你，到死也不知发生了何事...\n", this_object());
	ob = new(__DIR__"obj/lurou");
	ob->move(environment(this_object()));
	destruct(this_object());
}


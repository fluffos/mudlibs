#pragma save_binary
#include <ansi.h>

inherit NPC;

void create()
{
   set_name(HIW"北极熊"NOR, ({ "beiji xiong", "beiji", "xiong" }) );
	set("race", "野兽");
	set("age", 3);
         set("long", HIW"一只白白胖胖的北极熊。\n"NOR);
	
         set("str", 130);
         set("cor", 30);
         set("per", 30);
         set("con", 30);
         set("cps", 30);
         set("max_kee", 1000);
         set("max_gin", 1000);
         set("max_sen", 1000);
         set("max_force", 1000);
         set("eff_force", 1000);
         set("force", 1000);
         set("max_mana", 1000);
         set("eff_mana", 1000);
         set("mana", 1000);
         set("max_atman", 1000);
         set("eff_atman", 1000);
         set("atman", 1000);
         set("force_factor", random(80));
	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 25000);
        set("chat_chance",20);
        set("chat_msg", ({
        "北极熊低声说道：好可怜的孩子，想出去的话可以跳(JUMP)下去，不过那样会付出一些代价。\n",
        }));
        set_temp("apply/force", random(50));
        set_temp("apply/armor", random(100));
        set_temp("apply/armor_vs_force", random(100));
        set_temp("apply/attack", random(50));
        set_temp("apply/damage", random(50));
        set_temp("apply/parry", random(50));
        set_temp("apply/dodge", random(50));
	setup();
     carry_object(__DIR__"food/coke");
}

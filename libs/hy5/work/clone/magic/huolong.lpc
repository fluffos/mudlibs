// migong lev14

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name(HIR"伊弗利特"NOR, ({ "shenghuo long" , "long" , "dragon" }));
                set("race", "野兽");
       set("long",
"一条巨大的红色的龙，看到了你，向你扑了过来。
。\n");
//              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" , "claw"}) );
	       set("max_qi",20000+random(10000));
  set("max_jing",20000+random(10000));
  set("max_sen",20000+random(10000));
  set("max_mana",20000+random(10000));

set("zhuanbest",1);  
set("magicgift",1);  

set("title",HIR+"圣之红龙"+NOR);
      set("dex",100);
      set("con",100);
     set("str" ,100);
       
    set("age", 80);

//       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 9000000+random(2000000));
            set_temp("apply/attack", 400);
        set_temp("apply/damage", 400);
        set_temp("apply/armor", 400);
        set_temp("apply/defence",400);
     set_skill("sword", 400+random(300));
      set_skill("parry", 400+random(300));
      set_skill("force", 400+random(300));
      set_skill("dodge", 400+random(300));
      set_skill("spells", 400+random(300));
      set_skill("magic-fire", 400+random(300));
      set_skill("unarmed", 400+random(300));

       set_skill("dragon", 400+random(300));

      map_skill("spells", "magic-fire");
      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
    (: perform_action, "spells.fireball" :),
    (: perform_action, "spells.firebolt" :),
    (: perform_action, "spells.meteor" :),
    (: perform_action, "spells.immolation" :),
    (: perform_action, "unarmed.yaoyao" :),
    (: perform_action, "unarmed.penhuo" :),
    (: perform_action, "unarmed.tuwu" :),
 }) );
     
   setup();

}



void invocation(object who, int level)
{
	int i;
	object *enemy;
        who=this_player();
if (!wizardp(who))
        who->apply_condition("zdizi_busy",4);
	message("vision",
		 name() + "突然大吼一声！\n" NOR,
		environment(), this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
if (enemy[i]!=who)
{
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
}
		}
	}
	set_leader(who);
	set("possessed",who);
}
int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object owner;
	message("vision",HIR"由于战斗已经结束！\n\n"
		+ name() + HIR"化为一道红光，消失不见了。\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

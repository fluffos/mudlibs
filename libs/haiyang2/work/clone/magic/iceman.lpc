// migong lev14

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name(HIC"沙拉斯"NOR, ({ "tian moshen" , "tianmoshen" }));
                set("gender", "男性");
       set("long",
"一个高大无比，全身闪电的男子。
。\n");
//              set("attitude", "aggressive");
               set("vendetta/authority",1);

        set("verbs", ({ "bite" , "claw"}) );
	       set("max_qi",20000+random(10000));
  set("max_jing",20000+random(10000));
  set("max_sen",20000+random(10000));
  set("max_mana",20000+random(10000));
set("per",40);
set("zhuanbest",1);  
set("magicgift",3);  

set("title",HIC+"天魔神"+NOR);
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
      set_skill("magic-unarmed", 400+random(300));
      set_skill("magic-sword", 400+random(300));
      set_skill("magic-ice", 400+random(300));
      set_skill("unarmed", 400+random(300));

       set_skill("dragon", 400+random(300));

      map_skill("spells", "magic-ice");
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
map_skill("parry", "magic-unarmed");
      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
    (: perform_action, "spells.lightningball" :),
    (: perform_action, "spells.implosion" :),
    (: perform_action, "spells.lightningbolt" :),
    (: perform_action, "spells.stun" :),
 }) );
     
   setup();
    carry_object(__DIR__"icesword")->wield();
}



void invocation(object who, int level)
{
	int i;
	object *enemy;
        who=this_player();
if (!wizardp(who))
        who->apply_condition("zdizi_busy",4);
	message("vision",
		 name() + "突然冷吟一声！\n" NOR,
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
	message("vision",HIC"由于战斗已经结束！\n\n"
		+ name() + HIC"化为一片闪电，消失不见了。\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

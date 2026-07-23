// migong lev14

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name(HIB"路西法"NOR, ({ "dark angel" , "darkangel" }));
                set("gender", "男性");
       set("long",
"一个高大无比，身上有十二翼的坠天使。
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
set("magicgift",4);  

set("title",HIB+"坠天使"+NOR);
      set("dex",150);
      set("con",150);
     set("str" ,150);
       
    set("age", 30);

//       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 12000000+random(8000000));
            set_temp("apply/attack", 400);
        set_temp("apply/damage", 500);
        set_temp("apply/armor", 500);
        set_temp("apply/defence",500);
      set_skill("sword", 400+random(500));
      set_skill("parry", 400+random(500));
      set_skill("force", 400+random(500));
      set_skill("dodge", 400+random(500));
      set_skill("spells", 400+random(500));
      set_skill("magic-unarmed", 400+random(500));
      set_skill("magic-sword", 400+random(500));
      set_skill("magic-dark", 400+random(500));
      set_skill("unarmed", 400+random(500));

       set_skill("dragon", 400+random(500));

      map_skill("spells", "magic-dark");
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
map_skill("parry", "magic-unarmed");
      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
    (: perform_action, "spells.nuclea" :),
    (: perform_action, "spells.darkstorm" :),
    (: perform_action, "spells.darkwind" :),
    (: perform_action, "spells.darkmetor" :),
    (: perform_action, "spells.dragon" :),
 }) );
     
   setup();
    carry_object(__DIR__"darksword")->wield();
}



void invocation(object who, int level)
{
	int i;
	object *enemy;
        who=this_player();
if (!wizardp(who))
        who->apply_condition("zdizi_busy",4);
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
	message("vision",BLK"由于战斗已经结束！\n\n"
		+ name() + BLK"化为一个黑洞，消失不见了。\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

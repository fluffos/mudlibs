//军天使 米迦勒 !!! 

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name(HIY"米迦勒"NOR, ({ "light angel" , "lightangel" }));
                set("gender", "男性");
       set("long",
"一个高大无比，身上有六翼的军天使。
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

set("title",HIR+"军天使"+NOR);
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
      set_skill("magic-light", 400+random(500));
      set_skill("unarmed", 400+random(500));

       set_skill("dragon", 400+random(500));

      map_skill("spells", "magic-light");
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
map_skill("parry", "magic-unarmed");
      map_skill("dodge", "dragon");


 set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
    (: perform_action, "spells.moonlight lightangel" :),
    (: perform_action, "spells.sunfield" :),
    (: perform_action, "spells.sunbolt" :),
    (: perform_action, "spells.holyword" :),
    (: perform_action, "spells.delete" :),
 }) );
     
   setup();
    carry_object(__DIR__"lightsword")->wield();
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
		+ name() + BLK"化为一道圣光，消失不见了。\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

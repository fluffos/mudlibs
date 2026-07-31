#include <ansi.h>
inherit BOSS;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"半人马"NOR, ({ "gentaur"}));
	set("magicgift",3);
	set("magicset",1);
       set("zhuanbest",1);
       set("long",
"一只可怕的半人马。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",35000000+random(8000000));
        set_skill("spells",900+random(300));
        set_skill("force",950+random(300));
	set_skill("unarmed",950+random(300));
	set_skill("sword",950+random(300));
	set_skill("club",950+random(300));
	set_skill("whip",950+random(300));
	set_skill("throwing",950+random(300));
	set_skill("parry",950+random(300));
      set_skill("magic-unarmed", 950+random(300));
      set_skill("magic-sword", 950+random(300));
      set_skill("magic-ice", 1000+random(200));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
map_skill("spells", "magic-ice");
        set("no_get",1);
	set_skill("force",950+random(300));
	set_skill("force",950+random(300));
b=74500+random(60000);
a=75000+random(50000);
d=49+random(60);
set("str",d);
set("dex",80+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
        set("jing",b);
        set("max_jing",b);
set("eff_jing",b);
        set("qi",a);
        set("max_qi",a);
set("eff_qi",a);

        set("neili",a);
        set("max_neili",a);
       
    set("age", 15);

        set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",1500);
	set_temp("apply/damage",1400);

 set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
    (: perform_action, "spells.lightningball" :),
 }) );
     set("chat_chance", 2);
        set("chat_msg", ({
                (: random_move :),
           }) );

  	set("bonus", random(680)+680);
	set("killer_reward", ([
	      "FI&/clone/box/gbox"   :   300,
	      "TW&480"   :  200,
	      "TA&480"   :  200,
	])); 
   setup();

carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/cloth")->wear();
}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight"))
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}


int hit_ob(object me, object ob, int damage)
{
  if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3)
{
ob->apply_condition("new_poison5", 8); 
        tell_object(ob, HIG "你觉得被打中的地方闪过一阵光华！\n" NOR );
}
}

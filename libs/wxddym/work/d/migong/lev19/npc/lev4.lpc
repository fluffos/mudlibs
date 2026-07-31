#include <ansi.h>
inherit NPC;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"德鲁伊"NOR, ({ "Druid"}));
	set("magicgift",4);
	set("magicset",1);
       set("zhuanbest",1);
       set("long",
"一位可怕的德鲁伊。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",39000000+random(8000000));
        set_skill("force",450+random(200));
	set_skill("unarmed",450+random(200));
	set_skill("sword",450+random(200));
	set_skill("club",450+random(200));
	set_skill("whip",450+random(200));
	set_skill("throwing",450+random(200));
	set_skill("parry",450+random(200));
set_skill("spells",400+random(200));
      set_skill("magic-unarmed", 440+random(200));
      set_skill("magic-sword", 440+random(200));
      set_skill("magic-fire", 440+random(200));
      set_skill("magic-earth", 440+random(200));
      set_skill("magic-ice", 440+random(200));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
map_skill("spells", "magic-earth");
        set("no_get",1);
	set_skill("force",550+random(300));
	set_skill("huntian-qigong",550+random(300));
	map_skill("force", "huntian-qigong");
b=26500+random(5000);
a=28200+random(4000);
d=85+random(60);
set("str",d);
set("dex",30+d);
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
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);

 set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
(: perform_action, "spells.Attach" :),
    (: perform_action, "spells.stab" :),
 }) );
     set("chat_chance",10);
        set("chat_msg", ({
		(: command("get coin") :),
		(: command("get silver") :),
                (: random_move :),
           }) );
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
string msg;
        if(random((int)me->query("combat_exp")) > ob->query("combat_exp")/2)   
{
           ob->start_busy(2);
           msg = RED"$N"RED"突然叫出一群乌鸦出来!，$n"RED"结果被打的不能动了!\n"NOR;
            message_vision(msg, me, ob);
}
}
void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;        
              me->add("score",1);
        message_vision(RED"$N,倒地而亡，不动弹了。\n"NOR,ob,me);
        if((int)me->query("combat_exp") < ob->query("combat_exp"))   {
        message("vision", me->name() + HIG"成功消灭"+ob->query("name")+",增加了80经验和40潜能。\n"NOR, me);
        me->add("combat_exp",80);
        me->add("potential",40);
        destruct(ob);
        }

               destruct(ob);
        return;
}


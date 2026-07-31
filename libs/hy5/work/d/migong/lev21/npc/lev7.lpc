#include <ansi.h>
inherit NPC;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"亡灵法师"NOR, ({ "lich"}));
if (random(2)==0)
	set("magicgift",5);
else 	set("magicgift",6);
set("nickname",HIB"魔族军团"NOR);
	set("magicset",1);
       set("zhuanbest",1);
       set("long",
"一位可怕的亡灵法师。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",57000000+random(8000000));
        set_skill("spells",490+random(300));
        set_skill("force",490+random(300));
	set_skill("unarmed",490+random(300));
	set_skill("sword",490+random(300));
	set_skill("club",490+random(300));
	set_skill("whip",490+random(300));
	set_skill("throwing",490+random(300));
	set_skill("parry",490+random(300));
      set_skill("magic-unarmed", 490+random(300));
      set_skill("magic-sword", 490+random(300));
      set_skill("magic-light", 490+random(200));
      set_skill("magic-dark", 490+random(200));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
map_skill("spells", "magic-dark");
        set("no_get",1);
      set_skill("magic-dark", 700+random(300));
      set_skill("magic-light", 700+random(300));
      set_skill("magic-earth", 600+random(300));
      set_skill("magic-ice", 600+random(300));
      set_skill("magic-water", 600+random(300));
      set_skill("magic-fire", 600+random(300));
      set_skill("magic-unarmed", 600+random(300));
      set_skill("magic-sword", 600+random(300));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
	set_skill("force",650+random(300));
	set_skill("huntian-qigong",650+random(300));
	map_skill("force", "huntian-qigong");
b=39500+random(5000);
a=33500+random(5000);
d=95+random(60);
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
    (: perform_action, "spells.darkstorm" :),
    (: perform_action, "spells.darkwind" :),
    (: perform_action, "spells.darkmetor" :),
 }) );
     set("chat_chance", 5);
        set("chat_msg", ({
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

void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;        
              me->add("score",1);
        message_vision(RED"$N,倒地而亡，不动弹了。\n"NOR,ob,me);
        if((int)me->query("combat_exp") < ob->query("combat_exp"))   {
        message("vision", me->name() + HIG"成功消灭"+ob->query("name")+",增加了160经验和80潜能。\n"NOR, me);
        me->add("combat_exp",160);
        me->add("potential",80);
              me->add("score",1);
        destruct(ob);
        }
 
               destruct(ob);
        return;
}

int hit_ob(object me, object ob, int damage)
{
string msg;
        if(random((int)me->query("combat_exp")) > ob->query("combat_exp")/2)   
{
             ob->add("jing",-ob->query("jing")/30);
             ob->add("eff_jing",-ob->query("eff_jing")/30);
if (!ob->is_busy())
             ob->start_busy(3);
           msg = HIC"$N"HIB"突然使用魔光弹打向$n!! $n看来受伤不小!\n"NOR;
            message_vision(msg, me, ob);
}
}
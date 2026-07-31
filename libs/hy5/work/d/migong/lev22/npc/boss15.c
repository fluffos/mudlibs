#include <ansi.h>
inherit NPC;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""HIB"", ""HIB"", ""HIB"", ""HIB"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"特里亚"NOR, ({ "yesno"}));
set("magicgift",1+random(6));
	set("magicset",1);
       set("title",HIW"暗之天使"NOR);
       set("zhuanbest",1);
       set("long",
"一位可怕的天使君主。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",75000000+random(8000000));
        set_skill("force",550+random(300));
	set_skill("unarmed",550+random(300));
	set_skill("sword",550+random(300));
	set_skill("club",550+random(300));
	set_skill("whip",550+random(300));
	set_skill("throwing",550+random(300));
	set_skill("parry",550+random(300));
	set_skill("force",690+random(300));	
set_skill("spells",600+random(300));
      set_skill("magic-unarmed", 580+random(300));
      set_skill("magic-sword", 580+random(200));
      set_skill("magic-dark", 580+random(300));
      set_skill("magic-light", 580+random(300));
      set_skill("magic-earth", 580+random(300));
      set_skill("magic-ice", 580+random(300));
      set_skill("magic-water", 580+random(300));
      set_skill("magic-fire", 580+random(300));
            map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
map_skill("spells", "magic-dark");
        set("no_get",1);
      set_skill("magic-dark", 800+random(300));
      set_skill("magic-light", 800+random(300));
      set_skill("magic-earth", 700+random(300));
      set_skill("magic-ice", 700+random(300));
      set_skill("magic-water", 700+random(300));
      set_skill("magic-fire", 700+random(300));
      set_skill("magic-unarmedboss", 800+random(300));
      set_skill("magic-swordboss", 800+random(300));
      map_skill("sword", "magic-swordboss");
      map_skill("unarmed", "magic-unarmedboss");
      map_skill("parry", "magic-unarmedboss");
	set_skill("force",850+random(300));
	set_skill("huntian-qigong",850+random(300));
	map_skill("force", "huntian-qigong");
b=358000+random(168000);
a=388000+random(168000);
d=168+random(60);
set("str",d);
set("dex",60+d);
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
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	set_temp("apply/armor",5800);
	set_temp("apply/damage",1600);
     map_skill("spells", "magic-dark");
        set("chat_chance_combat", 69);
        set("chat_msg_combat", ({
              (: perform_action, "spells.nuclea" :),
               (: perform_action, "spells.darkstorm" :),
               (: perform_action, "spells.darkwind" :),
               (: perform_action, "spells.darkmetor" :),
               (: perform_action, "spells.darkforce" :),
               (: perform_action, "spells.dragon" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.castigate" :),                                                              
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
              me->add("score",100);
        me->set("title",ob->query("title"));
        me->set("qi",me->query("max_qi"));
        me->set("jing",me->query("max_jing"));
        me->set("neili",me->query("max_neili"));
        message_vision(HIB"$N,化为了无数的光芒，消失在空中。\n"NOR,ob,me);
        message("vision", me->name() + HIG"在最终任务中!!打败了"+ob->query("title")+HIG":"+ob->query("name")+HIG"("+ob->query("id")+HIG")。\n"NOR, users());
        destruct(ob);
        return;
}

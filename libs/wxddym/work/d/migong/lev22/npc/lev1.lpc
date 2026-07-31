#include <ansi.h>
inherit NPC;
mapping *data=({
(["id":"dark angel","title":"黑暗天使军团","name":"堕胎天使",]),
(["id":"dark angel","title":"黑暗天使军团","name":"绝壁天使",]),
(["id":"dark angel","title":"黑暗天使军团","name":"不死天使",]),
(["id":"dark angel","title":"黑暗天使军团","name":"情欲天使",]),
(["id":"dark angel","title":"黑暗天使军团","name":"地震天使",]),
(["id":"dark angel","title":"黑暗天使军团","name":"受胎天使",]),
(["id":"dark angel","title":"黑暗天使军团","name":"不妊天使",]),
(["id":"dark angel","title":"黑暗天使军团","name":"愤怒天使",]),
(["id":"dark angel","title":"黑暗天使军团","name":"堕胎天使",]),
(["id":"dark angel","title":"黑暗天使军团","name":"昆虫之天使",]),
(["id":"dark angel","title":"黑暗天使军团","name":"娼妇天使",]),
(["id":"dark angel","title":"黑暗天使军团","name":"破坏天使",]),
(["id":"dark angel","title":"黑暗天使军团","name":"死亡天使",]),
(["id":"dark angel","title":"黑暗天使军团","name":"毁灭天使",]),
(["id":"dark angel","title":"黑暗天使军团","name":"亡灵天使",])
});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
	npc=data[random(sizeof(data))];
set_name(order[random(13)]+npc["name"]+NOR,({ npc["id"] }));    
set("nickname",(HIB+npc["title"])+NOR);
	set("magicgift",1+random(6));
	set("zhuanbest",1);
	set("magicset",1);
       set("long",
"一位黑暗天使。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",75000000+random(8000000));
        set_skill("force",490+random(300));
	set_skill("unarmed",490+random(300));
	set_skill("sword",490+random(300));
	set_skill("club",490+random(300));
	set_skill("whip",490+random(300));
	set_skill("throwing",490+random(300));
	set_skill("parry",490+random(300));
	set_skill("force",690+random(300));	
      set_skill("magic-dark", 490+random(300));
      set_skill("magic-light", 490+random(300));
      set_skill("magic-earth", 490+random(300));
      set_skill("magic-ice", 490+random(300));
      set_skill("magic-water", 490+random(300));
      set_skill("magic-fire", 490+random(300));
      set_skill("magic-unarmed", 490+random(300));
      set_skill("magic-sword", 490+random(300));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
        set("no_get",1);
      set_skill("magic-dark", 700+random(300));
      set_skill("magic-light", 700+random(300));
      set_skill("magic-earth", 700+random(300));
      set_skill("magic-ice", 700+random(300));
      set_skill("magic-water", 700+random(300));
      set_skill("magic-fire", 700+random(300));
      set_skill("magic-unarmed", 700+random(300));
      set_skill("magic-sword", 700+random(300));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
	set_skill("force",750+random(300));
	set_skill("huntian-qigong",750+random(300));
	map_skill("force", "huntian-qigong");
b=59000+random(16000);
a=51000+random(18000);
d=165+random(60);
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

set("shen",-100000);
        set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	set_temp("apply/armor",5800);
	set_temp("apply/damage",1600);
     set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
           }) );
if (random(2)==0)
{
     map_skill("spells", "magic-dark");
        set("chat_chance_combat", 69);
        set("chat_msg_combat", ({
              (: perform_action, "spells.nuclea" :),
               (: perform_action, "spells.darkstorm" :),
               (: perform_action, "spells.darkwind" :),
               (: perform_action, "spells.darkmetor" :),
               (: perform_action, "spells.darkforce" :),
               (: perform_action, "spells.dragon" :),                                                            
		(: command("use huoqiang") :),
		(: command("use huoqiang") :),
//               (: perform_action, "spells.summon" :),                                                            
//               (: perform_action, "spells.castigate" :),                                                              
        }) );
}
else 
{
     map_skill("spells", "magic-earth");
        set("chat_chance_combat", 69);
        set("chat_msg_combat", ({
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.stab" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.Attach" :),
               (: perform_action, "spells.missile" :),
               (: perform_action, "spells.quake" :),                                                            
		(: command("use huoqiang") :),
		(: command("use huoqiang") :),
//               (: perform_action, "spells.summon" :),                                                            
//               (: perform_action, "spells.Dintfield" :),                                                             
        }) );
        }
   setup();

carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/cloth")->wear();
	carry_object("/clone/box/new2/29");
if (random(10)==0)
	carry_object("/clone/box/new2/30");
if (random(10)==0)
	carry_object("/clone/box/new2/31");
if (random(10)==0)
	carry_object("/clone/box/new2/32");
if (random(10)==0)
	carry_object("/clone/box/new2/33");	
if (random(10)==0)
	carry_object("/clone/box/new2/34");		
if (random(10)==0)
	carry_object("/clone/box/new2/35");			
if (random(10)==0)
	carry_object("/clone/box/new2/36");		
}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") )
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
        message("vision", me->name() + HIG"成功打死"+ob->query("name")+",增加了80经验和40潜能。\n"NOR, me);
        me->add("combat_exp",80);
        me->add("potential",40);
        destruct(ob);
        }

               destruct(ob);
        return;
}


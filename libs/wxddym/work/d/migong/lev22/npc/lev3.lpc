#include <ansi.h>
inherit NPC;
mapping *data=({
(["id":"chaos angel","title":"混沌天使军团","name":"山脉天使",]),
(["id":"chaos angel","title":"混沌天使军团","name":"植物天使",]),
(["id":"chaos angel","title":"混沌天使军团","name":"健康天使",]),
(["id":"chaos angel","title":"混沌天使军团","name":"森林天使",]),
(["id":"chaos angel","title":"混沌天使军团","name":"遗忘天使",]),
(["id":"chaos angel","title":"混沌天使军团","name":"食物天使",]),
(["id":"chaos angel","title":"混沌天使军团","name":"计算天使",]),
(["id":"chaos angel","title":"混沌天使军团","name":"宝瓶宫天使",]),
(["id":"chaos angel","title":"混沌天使军团","name":"沈默天使",]),
(["id":"chaos angel","title":"混沌天使军团","name":"蔬菜天使",]),
(["id":"chaos angel","title":"混沌天使军团","name":"练金术天使",]),
(["id":"chaos angel","title":"混沌天使军团","name":"记忆天使",]),
(["id":"chaos angel","title":"混沌天使军团","name":"婚姻天使",]),
(["id":"chaos angel","title":"混沌天使军团","name":"平衡天使",]),
(["id":"chaos angel","title":"混沌天使军团","name":"水流天使",])
});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
	npc=data[random(sizeof(data))];
set_name(order[random(13)]+npc["name"]+NOR,({ npc["id"] }));    
set("nickname",(HIY+npc["title"])+NOR);
	set("magicgift",1+random(6));
	set("zhuanbest",1);
	set("magicset",1);
       set("long",
"一位混沌天使。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",75000000+random(8000000));
        set_skill("force",490+random(300));
	set_skill("unarmed",490+random(300));
	set_skill("sword",500+random(300));
	set_skill("club",500+random(300));
	set_skill("whip",500+random(300));
	set_skill("throwing",500+random(300));
	set_skill("parry",500+random(300));
	set_skill("force",690+random(300));	
      set_skill("magic-dark", 500+random(500));
      set_skill("magic-light", 500+random(300));
      set_skill("magic-earth", 500+random(300));
      set_skill("magic-ice", 500+random(300));
      set_skill("magic-water", 500+random(300));
      set_skill("magic-fire", 500+random(300));
      set_skill("magic-unarmed", 500+random(300));
      set_skill("magic-sword", 500+random(300));
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
     map_skill("spells", "magic-fire");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
               (: perform_action, "spells.light" :),
               (: perform_action, "spells.fireball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.immolation" :),
               (: perform_action, "spells.firebolt" :),
               (: perform_action, "spells.meteor" :),                                                            
		(: command("use huoqiang") :),
		(: command("use huoqiang") :),
//               (: perform_action, "spells.summon" :),                                                            
//               (: perform_action, "spells.incinerate" :),                                                            
        }) );
}
else 
{
     map_skill("spells", "magic-water");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
               (: perform_action, "spells.door" :),
               (: perform_action, "spells.iceball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.crystal" :),
               (: perform_action, "spells.icebolt" :),
               (: perform_action, "spells.storm" :),                                                            
		(: command("use huoqiang") :),
		(: command("use huoqiang") :),
//               (: perform_action, "spells.summon" :),                                                            
//               (: perform_action, "spells.zeroring" :),                                                            
        }) );
}
   setup();

carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/cloth")->wear();
if (random(10)==0)
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
        if(userp(ob[i]) && ob[i]->query("shen")< -100000) continue;
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


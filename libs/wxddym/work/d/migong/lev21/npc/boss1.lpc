#include <ansi.h>
inherit NPC;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""HIB"", ""HIB"", ""HIB"", ""HIB"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"莉莉斯"NOR, ({ "Lilith"}));
if (random(2)==0)
	set("magicgift",5);
else 	set("magicgift",6);
	set("magicset",1);
       set("title",HIB"懒惰之坠天使"NOR);
       set("zhuanbest",1);
       set("long",
"一位可怕的懒惰之坠天使。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",55000000+random(8000000));
        set_skill("force",550+random(300));
	set_skill("unarmed",550+random(300));
	set_skill("sword",550+random(300));
	set_skill("club",550+random(300));
	set_skill("whip",550+random(300));
	set_skill("throwing",550+random(300));
	set_skill("parry",550+random(300));
set_skill("spells",600+random(300));
      set_skill("magic-unarmed", 550+random(300));
      set_skill("magic-sword", 550+random(200));
      set_skill("magic-dark", 660+random(200));
      set_skill("magic-light", 660+random(200));
      set_skill("magic-ice", 660+random(200));
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
b=638000+random(68000);
a=678000+random(68000);
d=58+random(60);
set("str",d);
set("dex",40+d);
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
	set_temp("apply/armor",600);
	set_temp("apply/damage",600);

 set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
    (: perform_action, "spells.nuclea" :),
    (: perform_action, "spells.darkstorm" :),
    (: perform_action, "spells.darkwind" :),
    (: perform_action, "spells.darkmetor" :),
    (: perform_action, "spells.dragon" :),
    (: perform_action, "spells.castigate" :),
 }) );

if (random(4)==1)
{
map_skill("spells", "magic-light");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
    (: perform_action, "spells.moonlight Lilith" :),
    (: perform_action, "spells.sunfield" :),
    (: perform_action, "spells.sunbolt" :),
    (: perform_action, "spells.holyword" :),
    (: perform_action, "spells.delete" :),                                                    
    (: perform_action, "spells.sunarrow" :), 
        }) );
}
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
        object jla , jlb;        
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;        
              me->add("score",1);
        message_vision(HIB"$N,倒地而亡，化为了无数黑色的光芒。\n"NOR,ob,me);
        if((int)me->query("combat_exp") < ob->query("combat_exp"))   {
        message("vision", me->name() + HIG"成功消灭"+ob->query("title")+HIG",完成了任务。\n"NOR, users());
        me->add("combat_exp",600);
        me->add("potential",300);
        me->add("score",1);
if (!present("dark blade", me)
&& me->query("zhuanbest")
)
{
        jla=new("/clone/magic/obj/sword16");
        jla->move(me);
message("vision", me->name() + HIG"找到了古代武器:"+jla->query("name")+HIG"。\n"NOR, users());
}
        destruct(ob);
        }
if (!present("dark blade", me)
&& me->query("zhuanbest")
)
{
        jla=new("/clone/magic/obj/sword16");
        jla->move(me);
message("vision", me->name() + HIG"找到了古代武器:"+jla->query("name")+HIG"。\n"NOR, users());
}

               destruct(ob);
        return;
}


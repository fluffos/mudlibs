#include <ansi.h>
inherit NPC;
string *order = ({""HIB"", ""HIG"", ""RED"", ""MAG"", ""HIB"", ""HIB"", ""HIB"", ""HIB"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"梅菲斯特.费雷斯"NOR, ({ "Mephisto"}));
if (random(2)==0)
	set("magicgift",5);
else 	set("magicgift",6);
	set("magicset",1);
       set("title",HIB"骄傲之坠天使"NOR);
       set("zhuanbest",1);
       set("long",
"一位可怕的骄傲之坠天使。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	set("combat_exp",60000000+random(8000000));
        set_skill("force",50+random(300));
	set_skill("unarmed",590+random(300));
	set_skill("sword",590+random(300));
	set_skill("club",590+random(300));
	set_skill("whip",590+random(300));
	set_skill("throwing",590+random(300));
	set_skill("spells",600+random(300));
	set_skill("parry",590+random(300));
      set_skill("magic-unarmed", 590+random(200));
      set_skill("magic-sword", 590+random(200));
      set_skill("magic-fire", 600+random(200));
      set_skill("magic-light", 690+random(200));
      set_skill("magic-dark", 690+random(200));
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
b=899000+random(66000);
a=899000+random(68000);
d=60+random(60);
set("str",d);
set("dex",140+d);
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
        message_vision(HIB"$N,倒地而亡，化为了无数的黑色光芒。\n"NOR,ob,me);
        if((int)me->query("combat_exp") < ob->query("combat_exp"))   {
        message("vision", me->name() + HIG"成功消灭"+ob->query("title")+HIG",完成了光之世界的任务。\n"NOR, users());
        me->add("combat_exp",600);
        me->add("potential",300);
        me->add("score",1);
        me->set_temp("magicov1",1);
me->set("migong/lev21",1);
if (!present("dark jian", me)
&& me->query("zhuanbest")
)
{
corpse=new("/clone/magic/obj/darksword");
corpse->move(me);
message("vision", me->name() + HIG"找到了古代神器:"+corpse->query("name")+HIG"。\n"NOR, users());

}

        destruct(ob);
        }
if (!present("dark jian", me)
&& me->query("zhuanbest")
)
{
corpse=new("/clone/magic/obj/darksword");
corpse->move(me);
message("vision", me->name() + HIG"找到了古代神器:"+corpse->query("name")+HIG"。\n"NOR, users());
}
               destruct(ob);
        return;
}


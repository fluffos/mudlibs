#include <ansi.h>
inherit NPC;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIR"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"阿迪索"NOR, ({ "adesso"}));
if (random(2)==0)
	set("magicgift",2);
else 	set("magicgift",1);
	set("magicset",1);
       set("title",HIR"炎之力量使"NOR);
       set("zhuanbest",1);
       set("long",
"一位可怕的炎之力量使。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",23000000+random(8000000));
        set_skill("force",400+random(200));
	set_skill("unarmed",400+random(200));
	set_skill("sword",400+random(200));
	set_skill("club",400+random(200));
	set_skill("whip",400+random(200));
	set_skill("throwing",400+random(200));
	set_skill("parry",400+random(200));
      set_skill("magic-unarmed", 400+random(200));
      set_skill("magic-sword", 400+random(200));
      set_skill("magic-fire", 600+random(200));
      set_skill("magic-water", 600+random(200));
      set_skill("magic-ice", 600+random(200));
set_skill("spells",600+random(200));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
map_skill("spells", "magic-fire");
        set("no_get",1);
b=160000+random(66000);
a=180000+random(68000);
d=30+random(60);
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
	set_temp("apply/armor",600);
	set_temp("apply/damage",600);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
               (: perform_action, "spells.light" :),
               (: perform_action, "spells.fireball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.immolation" :),
               (: perform_action, "spells.firebolt" :),
               (: perform_action, "spells.meteor" :),                                                            
               (: perform_action, "spells.incinerate" :),                                                                                                                     
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
        object jla , jlb;        
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;        
              me->add("score",1);
        message_vision(HIR"$N,倒地而亡，化为了一团火炎。\n"NOR,ob,me);
        if((int)me->query("combat_exp") < ob->query("combat_exp"))   {
        message("vision", me->name() + HIG"成功消灭"+ob->query("title")+HIG",完成了任务。\n"NOR, users());
        me->add("combat_exp",600);
        me->add("potential",300);
        me->add("score",1);
if (!present("fire jian", me)
&& me->query("zhuanbest")
)
{
        jla=new("/clone/magic/obj/sword11");
        jla->move(me);
message("vision", me->name() + HIG"找到了古代武器:"+jla->query("name")+HIG"。\n"NOR, users());
}
        destruct(ob);
        }
if (!present("fire jian", me)
&& me->query("zhuanbest")
)
{
        jla=new("/clone/magic/obj/sword11");
        jla->move(me);
message("vision", me->name() + HIG"找到了古代武器:"+jla->query("name")+HIG"。\n"NOR, users());
}

               destruct(ob);
        return;
}


void unconcious()
{
die();
}

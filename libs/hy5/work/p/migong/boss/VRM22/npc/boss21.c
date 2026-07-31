#include <ansi.h>
inherit BOSS;
#include "/d/migong/romnpc.c"
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""HIB"", ""HIB"", ""HIB"", ""HIB"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"贝黑摩斯"NOR, ({ "wuyou"}));
set("magicgift",1+random(6));
	set("magicset",1);
       set("title",HIB"强欲天使"NOR);
       set("zhuanbest",1);
       set("long",
"一位可怕的坠天使。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",75000000+random(8000000));
      set_skill("force",1550+random(300));
	set_skill("unarmed",1550+random(300));
	set_skill("sword",1550+random(300));
	set_skill("club",1550+random(300));
	set_skill("whip",1550+random(300));
	set_skill("throwing",1550+random(300));
	set_skill("parry",1550+random(300));
	set_skill("force",1690+random(300));	
set_skill("spells",1600+random(300));
      set_skill("magic-unarmed", 1580+random(300));
      set_skill("magic-sword", 1580+random(200));
      set_skill("magic-dark", 1580+random(300));
      set_skill("magic-light", 1580+random(300));
      set_skill("magic-earth", 1580+random(300));
      set_skill("magic-ice", 1580+random(300));
      set_skill("magic-water",1580+random(300));
      set_skill("magic-fire", 1580+random(300));
            map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
map_skill("spells", "magic-dark");
        set("no_get",1);
      set_skill("magic-dark", 1800+random(300));
      set_skill("magic-light", 1800+random(300));
      set_skill("magic-earth", 1700+random(300));
      set_skill("magic-ice", 1700+random(300));
      set_skill("magic-water", 1700+random(300));
      set_skill("magic-fire", 1700+random(300));
      set_skill("magic-unarmedboss", 1800+random(300));
      set_skill("magic-swordboss", 1800+random(300));
      map_skill("sword", "magic-swordboss");
      map_skill("unarmed", "magic-unarmedboss");
      map_skill("parry", "magic-unarmedboss");
	set_skill("force",1850+random(300));
	set_skill("huntian-qigong",1850+random(300));
	map_skill("force", "huntian-qigong");
b=2558000+random(568000);
a=2588000+random(568000);
d=188+random(60);
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
	set_temp("apply/armor",8800);
	set_temp("apply/damage",8600);
     map_skill("spells", "magic-earth");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.stab" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.Attach" :),
               (: perform_action, "spells.missile" :),
               (: perform_action, "spells.quake" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.Dintfield" :),                                                             
        }) );
        

if (random(18)==0)
{
set("nickname",HIY"武功高超"NOR);
        set_skill("spells",1800+random(1000));
        set_skill("force",1800+random(1000));
	set_skill("unarmed",1800+random(1000));
	set_skill("sword",1800+random(1000));
	set_skill("club",1800+random(1000));
	set_skill("whip",1800+random(1000));
	set_skill("throwing",1800+random(1000));
	set_skill("parry",1800+random(1000));
}
else
if (random(18)==0)
{
set("nickname",MAG"魔法强大"NOR);
      set_skill("magic-unarmed", 1850+random(1300));
      set_skill("magic-sword", 1850+random(1300));
      set_skill("magic-ice", 1850+random(1200));
      set_skill("magic-water", 1850+random(1200));
      set_skill("magic-fire", 1850+random(1200));
      set_skill("magic-earth", 1850+random(1200));
      set_skill("magic-light", 1850+random(1200));
      set_skill("magic-dark", 1850+random(1200));
}
else
if (random(18)==0)
{
set("nickname",HIB"经验丰富"NOR);
set("combat_exp",150000000+random(58000000));
}
else
if (random(18)==0)
{
set("nickname",HIR"强大不死"NOR);
set("dex",300);
        set("jing",3900000);
        set("max_jing",3900000);
        set("eff_jing",3900000);
        set("qi",3900000);
        set("max_qi",3900000);
        set("eff_qi",3900000);
        set("neili",3900000);
        set("max_neili",3900000);
}
else
if (random(18)==0)
{
set("nickname",HIC"超级加强"NOR);
d=188+random(188);
set("str",d);
set("dex",30+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
}
else
if (random(18)==0)
{
set("dex",300);
        set("jing",2358000);
        set("max_jing",2358000);
        set("eff_jing",2358000);
        set("qi",2358000);
        set("max_qi",2358000);
        set("eff_qi",2358000);
        set("neili",2358000);
        set("max_neili",2358000);
      set_skill("magic-unarmed", 1850+random(800));
      set_skill("magic-sword", 1850+random(800));
      set_skill("magic-ice", 1850+random(800));
      set_skill("magic-water", 1850+random(800));
      set_skill("magic-fire", 1850+random(800));
      set_skill("magic-earth", 1850+random(800));
      set_skill("magic-light", 1850+random(800));
      set_skill("magic-dark", 1850+random(800));
        set_skill("spells",1850+random(800));
        set_skill("force",1850+random(800));
	set_skill("unarmed",1850+random(800));
	set_skill("sword",1850+random(800));
	set_skill("club",1850+random(800));
	set_skill("whip",1850+random(800));
	set_skill("throwing",1850+random(800));
	set_skill("parry",1850+random(800));
set("nickname",HIC"完美无敌"NOR);
d=188+random(188);
set("str",d);
set("dex",30+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
}
        set("killer_reward", ([
                "FI&/clone/box/gbox"   :   680,
		"GE&6"   :  500,
		"KS&9"   :   500,
		"BL&8"   :  500,
                "TW&480"   :  580,
                "TA&480"   :  580,
                "TZ&0"   :  500,
               "TZ&1"   :  300,
               "TZ&2"   :  100,	
        ]));
	set("bonus", 3200+random(3200));
   setup();

 if (random(2)==0)
{
 	 initlvl(1750+random(300));
}
else
	{
	carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/cloth")->wear();
}
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
ob->apply_condition("new_poison7", 10); 
        tell_object(ob, HIW "你觉得被打中的地方闪过一阵五彩光华！\n" NOR );
}
}
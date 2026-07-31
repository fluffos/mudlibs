#include <ansi.h>
inherit BOSS;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"食人魔法师"NOR, ({ "ogre magi"}));
	set("magicgift",2);
	set("magicset",1);
       set("zhuanbest",1);
       set("long",
"一只可怕的食人魔法师。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",20000000+random(8000000));
        set_skill("force",800+random(200));
	set_skill("unarmed",800+random(200));
	set_skill("sword",800+random(200));
	set_skill("club",800+random(200));
	set_skill("whip",800+random(200));
	set_skill("throwing",800+random(200));
	set_skill("parry",800+random(200));
      set_skill("spells",800+random(200));
      set_skill("magic-unarmed", 800+random(200));
      set_skill("magic-sword", 800+random(200));
      set_skill("magic-fire", 800+random(200));
      set_skill("magic-water", 800+random(200));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
map_skill("spells", "magic-water");
        set("no_get",1);
b=93500+random(94500);
a=91111+random(94500);
d=70+random(60);
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
	set_temp("apply/armor",3500);
	set_temp("apply/damage",3400);

 set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
    (: perform_action, "spells.iceball" :),
 (: perform_action, "spells.crystal" :),
 }) );
 	set("bonus", random(580)+580);
	set("killer_reward", ([
	      "FI&/clone/box/gbox"   :   300,
	      "TW&480"   :  200,
	      "TA&480"   :  200,
	]));
	
if (random(18)==0)
{
set("nickname",HIY"武功高超"NOR);
        set_skill("spells",1000+random(1000));
        set_skill("force",1000+random(1000));
	set_skill("unarmed",1000+random(1000));
	set_skill("sword",1000+random(1000));
	set_skill("club",1000+random(1000));
	set_skill("whip",1000+random(1000));
	set_skill("throwing",1000+random(1000));
	set_skill("parry",1000+random(1000));
}
else
if (random(18)==0)
{
set("nickname",MAG"魔法强大"NOR);
      set_skill("magic-unarmed", 850+random(1300));
      set_skill("magic-sword", 850+random(1300));
      set_skill("magic-ice", 850+random(1200));
      set_skill("magic-water", 850+random(1200));
      set_skill("magic-fire", 850+random(1200));
      set_skill("magic-earth", 850+random(1200));
      set_skill("magic-light", 850+random(1200));
      set_skill("magic-dark", 850+random(1200));
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
        set("jing",900000);
        set("max_jing",900000);
        set("eff_jing",900000);
        set("qi",900000);
        set("max_qi",900000);
        set("eff_qi",900000);
        set("neili",900000);
        set("max_neili",900000);
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
        set("jing",800000);
        set("max_jing",800000);
        set("eff_jing",800000);
        set("qi",800000);
        set("max_qi",800000);
        set("eff_qi",800000);
        set("neili",800000);
        set("max_neili",800000);
      set_skill("magic-unarmed", 850+random(800));
      set_skill("magic-sword", 850+random(800));
      set_skill("magic-ice", 850+random(800));
      set_skill("magic-water", 850+random(800));
      set_skill("magic-fire", 850+random(800));
      set_skill("magic-earth", 850+random(800));
      set_skill("magic-light", 850+random(800));
      set_skill("magic-dark", 850+random(800));
        set_skill("spells",850+random(800));
        set_skill("force",850+random(800));
	set_skill("unarmed",850+random(800));
	set_skill("sword",850+random(800));
	set_skill("club",850+random(800));
	set_skill("whip",850+random(800));
	set_skill("throwing",850+random(800));
	set_skill("parry",850+random(800));
set("nickname",HIC"完美无敌"NOR);
d=188+random(188);
set("str",d);
set("dex",30+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
}
	
   setup();

//carry_object(__DIR__"obj/sword")->wield();
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
        if(random((int)me->query("combat_exp")) > ob->query("combat_exp")/3)   
{
ob->apply_condition("new_poison3", 8); 
if (!ob->is_busy())
             ob->start_busy(3);
           msg = HIW"$N"HIW"突然对着$n"HIW"念咒!!结果$n"HIW"的行动受了影响了!\n"NOR;
            message_vision(msg, me, ob);
}
}
#include <ansi.h>
inherit BOSS;
mapping *data=({
(["id":"mon ster","title":"魔法怪物","name":"蝗虫",]),
(["id":"mon ster","title":"魔法怪物","name":"毒蜘蛛",]),
(["id":"mon ster","title":"魔法怪物","name":"史莱姆",]),
(["id":"mon ster","title":"魔法怪物","name":"蝎子",]),
(["id":"mon ster","title":"魔法怪物","name":"眼精王蛇",]),
(["id":"mon ster","title":"魔法怪物","name":"食人花",]),
(["id":"mon ster","title":"魔法怪物","name":"树精",]),
(["id":"mon ster","title":"魔法怪物","name":"吸血蝙蝠",]),
(["id":"mon ster","title":"魔法怪物","name":"魔狐",]),
(["id":"mon ster","title":"魔法怪物","name":"古代猴",]),
(["id":"mon ster","title":"魔法怪物","name":"地狱之犬",]),
(["id":"mon ster","title":"魔法怪物","name":"猪怪",]),
(["id":"mon ster","title":"魔法怪物","name":"狼怪",]),
(["id":"mon ster","title":"魔法怪物","name":"金钱豹",]),
(["id":"mon ster","title":"魔法怪物","name":"杀人蜂",]),
(["id":"mon ster","title":"魔法怪物","name":"巨蜥",])
});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
	npc=data[random(sizeof(data))];
set_name(order[random(13)]+npc["name"]+NOR,({ npc["id"] }));    
	set("magicgift",4);
	set("magicset",1);
          set("race", "野兽");
       set("long",
"一只可怕的魔法怪物。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "头部", "身体", "四肢" }) );
        set("verbs", ({ "bite", "claw" }) );
	       set("max_qi",500+random(500));
	set("combat_exp",45000000+random(8000000));
        set_skill("force",990+random(300));
	set_skill("unarmed",990+random(300));
	set_skill("sword",990+random(300));
	set_skill("club",990+random(300));
	set_skill("whip",990+random(300));
	set_skill("throwing",990+random(300));
	set_skill("parry",990+random(300));
	set_skill("dodge",990+random(300));
 set_skill("dragon", 990+random(300));
  map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
        set("no_get",1);
	set_skill("force",950+random(300));
	set_skill("huntian-qigong",950+random(300));
	map_skill("force", "huntian-qigong");
b=75800+random(76000);
a=76800+random(75000);
d=89+random(60);
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
	set_temp("apply/armor",2500);
	set_temp("apply/damage",2400);
     set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
           }) );
 set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
    (: perform_action, "unarmed.yaoyao" :),
    (: perform_action, "unarmed.penhuo" :),
    (: perform_action, "unarmed.tuwu" :),
 }) );
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
  	set("bonus", random(680)+780);
	set("killer_reward", ([
	      "FI&/clone/box/gbox"   :   300,
	      "TW&480"   :  200,
	      "TA&480"   :  200,
	])); 

   setup();

        

}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
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

//ob->apply_condition("ill_dongshang",10);
//ob->apply_condition("ill_fashao",10);
//ob->apply_condition("ill_kesou",10);
//ob->apply_condition("ill_shanghan",10);
//ob->apply_condition("ill_zhongshu",10);
//ob->apply_condition("ice_poison",10);
//ob->apply_condition("xx_poison",10);
//ob->apply_condition("cold_poison",10);
//ob->apply_condition("flower_poison",10);
//ob->apply_condition("rose_poison",10);
//ob->apply_condition("scorpion_poison",10);
  if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3)
{
        ob->apply_condition("chanchu_poison", 40);
        ob->apply_condition("xiezi_poison", 40);
        ob->apply_condition("snake_poison", 40);
        ob->apply_condition("zhizhu_poison", 40);
        ob->apply_condition("new_poison6", 8); 
        tell_object(ob, HIG "你觉得被咬中的地方一阵麻痒！\n" NOR );
}
}

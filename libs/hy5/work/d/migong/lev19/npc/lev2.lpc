#include <ansi.h>
inherit NPC;
mapping *data=({
(["id":"magic mob","title":"魔法斗士","name":"肉人",]),
(["id":"magic mob","title":"魔法斗士","name":"猫男",]),
(["id":"magic mob","title":"魔法斗士","name":"狼男",]),
(["id":"magic mob","title":"魔法斗士","name":"特洛鲁",]),
(["id":"magic mob","title":"魔法斗士","name":"巨人",]),
(["id":"magic mob","title":"魔法斗士","name":"石人",]),
(["id":"magic mob","title":"魔法斗士","name":"木乃伊",]),
(["id":"magic mob","title":"魔法斗士","name":"武斗家",]),
(["id":"magic mob","title":"魔法斗士","name":"骷髅人",]),
(["id":"magic mob","title":"魔法斗士","name":"魔法师",]),
(["id":"magic mob","title":"魔法斗士","name":"神官",]),
(["id":"magic mob","title":"魔法斗士","name":"飞马骑士",]),
(["id":"magic mob","title":"魔法斗士","name":"死灵骑士",]),
(["id":"magic mob","title":"魔法斗士","name":"骸骨",]),
(["id":"magic mob","title":"魔法斗士","name":"眼魔",]),
(["id":"magic mob","title":"魔法斗士","name":"半人马",]),
(["id":"magic mob","title":"魔法斗士","name":"黑暗精灵",]),
(["id":"magic mob","title":"魔法斗士","name":"矮人",]),
(["id":"magic mob","title":"魔法斗士","name":"精灵",]),
(["id":"magic mob","title":"魔法斗士","name":"战士",]),
(["id":"magic mob","title":"魔法斗士","name":"地精",]),
(["id":"magic mob","title":"魔法斗士","name":"妖精",]),
(["id":"magic mob","title":"魔法斗士","name":"半兽人",]),
(["id":"magic mob","title":"魔法斗士","name":"鸟人",]),
(["id":"mon ster","title":"魔法怪物","name":"精神体",])
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
       set("long",
"一只可怕的魔法战士。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",45000000+random(8000000));
        set_skill("force",490+random(300));
	set_skill("unarmed",490+random(300));
	set_skill("sword",490+random(300));
	set_skill("club",490+random(300));
	set_skill("whip",490+random(300));
	set_skill("throwing",490+random(300));
	set_skill("parry",490+random(300));
      set_skill("magic-unarmed", 490+random(300));
      set_skill("magic-sword", 490+random(300));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
        set("no_get",1);
	set_skill("force",550+random(300));
	set_skill("huntian-qigong",550+random(300));
	map_skill("force", "huntian-qigong");
b=25600+random(6000);
a=27600+random(5000);
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
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
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
if (me->query_condition("xx_poison"))
        me->apply_condition("xx_poison", 0);
if (me->query_condition("cold_poison"))
        me->apply_condition("cold_poison", 0);
if (me->query_condition("ice_poison"))
        me->apply_condition("ice_poison", 0);
if (me->query_condition("flower_poison"))
        me->apply_condition("flower_poison", 0);
        me->add("combat_exp",80);
        me->add("potential",40);
        destruct(ob);
        }

               destruct(ob);
        return;
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
  if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp"))
{
        ob->apply_condition("ice_poison", 40);
        ob->apply_condition("xx_poison", 40);
        ob->apply_condition("cold_poison", 40);
        ob->apply_condition("flower_poison", 40);
        tell_object(ob, HIG "你觉得被打中的地方一阵麻痒！\n" NOR );
}
}

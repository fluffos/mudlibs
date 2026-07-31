#include <ansi.h>
inherit BOSS;
int big_blowing();
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
//	npc=data[random(sizeof(data))];
   set_name(order[random(13)]+"小人物"NOR, ({ "boss hxsd"}));
set("magicgift",1+random(6));
       set("title",HIY"混沌创造神"NOR);
	set("magicgift",1+random(6));
        set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("MKS", 50000);
        set("PKS", 50000);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
	set("zhuanbest",1);
	set("magicset",1);
       set("long",
"这个世界的创造神之一。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",866500+random(500));
	set("combat_exp",380000000+random(8000000));
        set_skill("force",3690+random(300));
	set_skill("unarmed",3690+random(300));
	set_skill("sword",3690+random(300));
	set_skill("club",3690+random(300));
	set_skill("whip",3690+random(300));
	set_skill("throwing",3690+random(300));
	set_skill("parry",3690+random(300));
set_skill("force",3690+random(300));
      set_skill("magic-dark", 3690+random(300));
      set_skill("magic-light", 3690+random(300));
      set_skill("magic-earth", 3690+random(300));
      set_skill("magic-ice", 3690+random(300));
      set_skill("magic-water", 3690+random(300));
      set_skill("magic-fire", 3690+random(300));
      set_skill("magic-unarmedboss", 3690+random(300));
      set_skill("ai-sword", 3690+random(300));
      set_skill("magic-swordboss", 3690+random(300));
      map_skill("sword", "magic-swordboss");
      map_skill("unarmed", "magic-unarmedboss");
      map_skill("parry", "magic-unarmedboss");
            set_skill("taiji-shengong", 3800);
      map_skill("force", "taiji-shengong");
if (random(3)==0)
{
      map_skill("sword", "ai-sword");
      map_skill("parry", "ai-sword");
}      
      set_skill("jiuyin-zhengong", 3680+random(300));
      set_skill("jiuyin-shenfa", 3680+random(200));
      set_skill("dafumo-quan", 3680+random(300));
      set_skill("jiuyin-shenzhang", 3680+random(300));
      set_skill("jiuyin-shenzhua", 3680+random(300));
      set_skill("xuanyin-jian", 3680+random(300));
      set_skill("yinlong-bian", 3680+random(300));
      set_skill("xuanyin-jian", 3680+random(300));
      map_skill("dodge", "jiuyin-shenfa");
      map_skill("force", "jiuyin-zhengong");
      map_skill("strike", "cuixin-zhang");
      map_skill("claw", "jiuyin-shenzhua");
        set("no_get",1);
b=9999000+random(2568000);
a=9999000+random(2568000);
d=200+random(60);
set("str",d);
set("dex",130+d);
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
	set_temp("apply/armor",9800);
	set_temp("apply/damage",9600);
if (random(2)==0)
{
     map_skill("spells", "magic-fire");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
               (: perform_action, "spells.light" :),
               (: perform_action, "spells.fireball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.immolation" :),
               (: perform_action, "spells.firebolt" :),
               (: perform_action, "spells.meteor" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.incinerate" :),                                                            
                (: big_blowing :),
                (: big_blowing :), 
	(: command("use huoqiang") :),
        }) );
}
else 
{
     map_skill("spells", "magic-water");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
               (: perform_action, "spells.door" :),
               (: perform_action, "spells.iceball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.crystal" :),
               (: perform_action, "spells.icebolt" :),
               (: perform_action, "spells.storm" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.zeroring" :),                                                            
                (: big_blowing :),
                (: big_blowing :), 
	(: command("use huoqiang") :),
        }) );
}

// 物品奖励
	set("bonus", random(200000)+19000);
	set("killer_reward", ([
		"FI&/clone/box/gbox"   :   10000,
		"RI&40"   :   8000,
		"GE&7"   :  8000,
		"KS&9"   :   8000,
		"BL&9"   :  8000,
		"RI&60"   :   8000,
		"GE&7"   :  8000,
		"JD&7"   :  8000,
		"YC&5"   :  8000,
		"WG&5"   :  8000,
		"YW&5"   :  8000,
		"YA&5"   :  8000,
		"TW&480"   :  8000,
		"TA&480"   :  8000,
    "TZ&0"   :  8000,
    "TZ&1"   :  8000,
    "TZ&2"   :  8000,	
	]));


   setup();

carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/cloth")->wear();
	carry_object("/clone/box/new2/36");	
	carry_object("/clone/box/new2/35");		
	carry_object("/clone/box/new2/34");		
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
        call_out("check",0);
        }
}



int hit_ob(object me, object ob, int damage)
{

        if (me->is_busy()) me->start_busy(1);

  if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3)
{
ob->apply_condition("new_poison7", 10); 
        tell_object(ob, HIW "你觉得被打中的地方闪过一阵五彩光华！\n" NOR );
}

if (random(2)==0)        
{
        damage = 9999 + random(9999);
        damage -= ob->query_temp("apply/reduce_cold");
        if (damage < 0) damage = 0;
        ob->apply_condition("new_poison2", 2); 
        ob->receive_wound("qi", damage);
        me->set("neili", me->query("max_neili"));
message_vision(HIY"$N打出了几道虚之光线 !!登时令$n 受到了伤害。\n"NOR,me,ob);
}

if (random(12)==0)
{
message_vision(HIR"$N的魔法属性发生了巨大的变化!!\n"NOR,me);
set("magicgift",1);
     map_skill("spells", "magic-fire");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
               (: perform_action, "spells.light" :),
               (: perform_action, "spells.fireball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.immolation" :),
               (: perform_action, "spells.firebolt" :),
               (: perform_action, "spells.meteor" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.incinerate" :),                                                            
                (: big_blowing :),
                (: big_blowing :), 
        }) );
}
else if (random(12)==0)
{
message_vision(HIR"$N的魔法属性发生了巨大的变化!!\n"NOR,me);
     map_skill("spells", "magic-water");
set("magicgift",1);
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
               (: perform_action, "spells.door" :),
               (: perform_action, "spells.iceball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.crystal" :),
               (: perform_action, "spells.icebolt" :),
               (: perform_action, "spells.storm" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.zeroring" :),                                                            
                (: big_blowing :),
                (: big_blowing :), 
        }) );
}
else if (random(12)==0)
{
message_vision(HIR"$N的魔法属性发生了巨大的变化!!\n"NOR,me);
set("magicgift",3);
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
                (: big_blowing :),
                (: big_blowing :), 
        }) );
}
else if (random(12)==0)
{
set("magicgift",4);
message_vision(HIR"$N的魔法属性发生了巨大的变化!!\n"NOR,me);
     map_skill("spells", "magic-ice");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
               (: perform_action, "spells.invisibility" :),
               (: perform_action, "spells.lightningball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.implosion" :),
               (: perform_action, "spells.lightningbolt" :),
               (: perform_action, "spells.stun" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.holylightning" :),                                                            
                (: big_blowing :),
                (: big_blowing :), 
        }) );
}
else if (random(12)==0)
{
message_vision(HIR"$N的魔法属性发生了巨大的变化!!\n"NOR,me);
set("magicgift",5);
     map_skill("spells", "magic-light");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
               (: perform_action, "spells.cure hxsd" :),
               (: perform_action, "spells.delete" :),
               (: perform_action, "spells.holyword" :),
               (: perform_action, "spells.moonlight hxsd" :),
               (: perform_action, "spells.sunbolt" :),
               (: perform_action, "spells.sunfield" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.sunarrow" :),                                                            
                (: big_blowing :),
                (: big_blowing :), 
        }) );
}
else if (random(12)==0)
{
message_vision(HIR"$N的魔法属性发生了巨大的变化!!\n"NOR,me);
set("magicgift",6);
     map_skill("spells", "magic-dark");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
              (: perform_action, "spells.nuclea" :),
               (: perform_action, "spells.darkstorm" :),
               (: perform_action, "spells.darkwind" :),
               (: perform_action, "spells.darkmetor" :),
               (: perform_action, "spells.darkforce" :),
               (: perform_action, "spells.dragon" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.castigate" :),                                                              
                (: big_blowing :),
                (: big_blowing :), 
        }) );
}
else if (random(12)==0)
{
message_vision(HIR"$N的魔法属性发生了巨大的变化!!\n"NOR,me);
set("magicgift",0);
      set_skill("jiuyin-zhengong", 3680+random(300));
      set_skill("jiuyin-shenfa", 3680+random(200));
      set_skill("dafumo-quan", 3680+random(300));
      set_skill("jiuyin-shenzhang", 3680+random(300));
      set_skill("jiuyin-shenzhua", 3680+random(300));
      set_skill("xuanyin-jian", 3680+random(300));
      set_skill("yinlong-bian", 3680+random(300));
      set_skill("xuanyin-jian", 3680+random(300));
      map_skill("dodge", "jiuyin-shenfa");
      map_skill("force", "jiuyin-zhengong");
      map_skill("strike", "cuixin-zhang");
      map_skill("sword", "xuanyin-jian");
      map_skill("unarmed", "dafumo-quan");
      map_skill("parry", "jiuyin-shenzhua");
      map_skill("claw", "jiuyin-shenzhua");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
               (: perform_action, "spells.moonlight hxsd" :),
               (: perform_action, "dodge.huanyinbu" :),
               (: perform_action, "unarmed.fumo" :),                                                            
               (: perform_action, "claw.sanjue" :),                                                            
               (: perform_action, "claw.sanjue" :),                                                            
               (: perform_action, "claw.sanjue" :),                                                            
               (: perform_action, "strike.cuixin" :),                                                            
                 (: big_blowing :),
                (: big_blowing :), 
        }) );
}
}


void check()
{
        object ob=this_object();
        object me=this_player();
    
     if (!ob)
     {
     remove_call_out("check");
     return;
     }

     if (!me)
     {
     remove_call_out("check");
     return;
     }


     if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }
     if( me->is_ghost() )
     {
     remove_call_out("check");
     return;
     }
     
if (ob->is_busy() && ob->is_fighting())
{
        message_vision(HIW"$N"HIW"身上圣光一闪，又恢复了行动！\n",ob,me);
        ob->interrupt_me();
        ob->start_busy(1);
        ob->start_busy(0);
ob->set_temp("apply/intelligence", 200);
ob->set_temp("apply/strength",200);
ob->set_temp("apply/dexerity",200);
ob->set_temp("apply/constitution",200);
ob->set_temp("apply/karey", 200);
ob->set_temp("apply/percao", 200);	
ob->set_temp("apply/armor", 9900);
ob->set_temp("apply/defense", 200);
ob->set_temp("apply/attack", 200);
ob->set_temp("apply/damage", 9900);     
	if((int)ob->query("qi") < (int)ob->query("max_qi")/6)
        {
        ob->add("qi",ob->query("max_qi")/12);
        ob->add("eff_qi",ob->query("max_qi")/12);
        }
ob->clear_condition();
ob->apply_condition("new_poison8",8);
}

        remove_call_out("check");
        call_out("check",1+random(3));
}


int big_blowing()
{
        message_vision(HIY "$N" HIY "用手在天空划了一个五芒星，念到 来吧，用虚无的力量毁灭一切！"
                       "天空突然变得五彩斑斓！！\n" NOR, this_object());
if (this_object()->is_busy()) this_object()->start_busy(1);
	this_object()->clear_condition();
        remove_call_out("hurting");
        call_out("hurting", 3);
        return 1;
}


int hurting()
{
        int dam, i , num;
        object *inv;
        
       message_vision(HIY "$N" HIY "打出一个巨大的五彩冲击波．．．．．．虚神的力量遍布大地！！！\n" NOR,
                       this_object());
                       
        inv = all_inventory(environment(this_object()));        

        num = sizeof(inv);       
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        
        dam = 50000 / num;
        
        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object() && userp(inv[i]))
                {
                        dam -= inv[i]->query_temp("apply/reduce_wind");
                        if (dam <0) dam = 10;
                       inv[i]->start_busy(2);
if (this_object()->is_busy()) this_object()->start_busy(1);
	this_object()->apply_condition("new_poison8", 8);
	this_object()->clear_condition();
                        inv[i]->apply_condition("new_poison7", 8);
                        inv[i]->apply_condition("tmqidu_poison", 1);
                        inv[i]->apply_condition("sanxiao_poison",3);
                        inv[i]->apply_condition("wuhudu_poison",3);
                        inv[i]->apply_condition("qx_snake_poison",3);
                        inv[i]->apply_condition("baituo_poison",3);
                        inv[i]->receive_wound("qi", dam/2);
                        inv[i]->receive_wound("jing", dam/3);
                        COMBAT_D->report_status(inv[i], 1);
                }
        }
        return 1;
}
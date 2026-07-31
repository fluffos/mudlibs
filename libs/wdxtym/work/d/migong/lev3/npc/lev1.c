// migong lev1
//by name

#include <ansi.h>
inherit NPC;
void create()
{

   set_name(HIG"鳄鱼", ({ "ye shou"}));
   set("race", "野兽");
   set("long","这是一只"+name()+"，请小心。\n");
   set("attitude", "aggressive");
   set("limbs", ({ "头部", "身体", "前爪", "后抓", "尾巴" }) );
   set("max_qi",1500+random(1500));
   set("max_jing",1500+random(1500));
   set("max_sen",1500+random(1500));
   set("max_mana",1500+random(1500));
   
     set("age", 50);
     set("dex",50);
     set("str",50);     
     set_temp("apply/attack", 50);
     set_temp("apply/damage", 50);
     set_temp("apply/armor", 50);
     set_temp("apply/defence",50);    
     set("combat_exp", 1500000);
     setup();
}

void init()
{	
	object ob; 
	ob = this_player();
	::init();
	if (interactive(ob) && ! is_fighting()){
	remove_call_out("greeting");
	call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	kill_ob(ob);
}
void die()
{
        object ob, me;
        ob = this_object();
        me=  this_object()->query_last_damage_from();        
        message_vision(WHT"$N一声惨叫,倒在地上，翻了个跟头就不动弹了。\n"NOR,ob,me);
        if((int)me->query("combat_exp") > 500000){
        message("vision", me->name() + "成功打死了"+name()+"增加了150修为和150潜能。\n", me);
        me->add("combat_exp",150);
        me->add("potential",150);
        }
       ::die();
}

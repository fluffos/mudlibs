// migong lev1
//by name

#include <ansi.h>
inherit NPC;
void create()
{

   set_name("狐狸", ({ "ye shou"}));
   set("race", "野兽");
   set("long","这是一只"+name()+"，请小心。\n");
   set("attitude", "aggressive");
   set("limbs", ({ "头部", "身体", "前爪", "后抓", "尾巴" }) );
   set("max_qi",500+random(500));
   set("max_jing",500+random(500));
   set("max_sen",500+random(500));
   set("max_mana",500+random(500));
   
     set("age", 30);
     set("dex",30);
     set("str",30);     
     set_temp("apply/attack", 30);
     set_temp("apply/damage", 30);
     set_temp("apply/armor", 30);
     set_temp("apply/defence",30);    
     set("combat_exp", 500000);
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
        if((int)me->query("combat_exp") > 100000){
        message("vision", me->name() + "成功打死了"+name()+"增加了100修为和100潜能。\n", me);
        me->add("combat_exp",100);
        me->add("potential",100);
        }
       ::die();
}

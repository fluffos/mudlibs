//Cracked by Roath

inherit NPC;
#include <ansi.h>

void create()
{
   set_name("飞天斑斓虎", ({ "lao hu","tiger","hu" }) );
   set("race", "野兽");
   set("age", 3);
   set("long", "一只样子很凶狠的老虎。\n");
   
   set("str", 32);


   set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
   set("verbs", ({ "bite", "claw" }) );
   set_skill("unarmed",50);
   set_skill("parry",50);
   set("combat_exp",160000);
   set_temp("apply/attack", 20);
   set_temp("apply/armor", 10);
   	       set("max_qi",15000+random(10000));
  set("max_jing",15000+random(10000));
  set("max_jing",20000+random(10000));
  set("max_mana",20000+random(10000));
 set("combat_exp", 6000000);
            set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/defence",100);
      set_skill("dodge", 400+random(100));

      set_skill("unarmed", 400+random(100));

       set_skill("dragon", 400+random(100));

      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
               
    (: perform_action, "unarmed.tuwu" :),
    (: perform_action, "unarmed.yaoyao" :),
    (: perform_action, "unarmed.penhuo" :),

 }) );
   setup();
}
void destruct_me (object me)
{
  destruct (me);
}

void kill_ob (object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
void die()
{
        object ob=this_object()->query_temp("my_killer");
        object corpse;
        object me=this_object();
        if(ob) {
        ob->set_temp("tiger_kill","yes");
        }
        message_vision ("$N惨叫一声，倒在血泊中。\n",me);

::die();
}

void destroy(object ob)
{
        destruct(ob);
        return;
}
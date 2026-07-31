//Cracked by Roath
 
inherit NPC;
#include <ansi.h>
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("Öí¹Ö", ({ "zhu guai","pig" }));
  set("age", 600);
  set("gender", "ÄÐÐÔ");
  set("long", "Ò»¸öÒ°Öí¹Ö¡£\n");
  set("attitude", "peaceful");
  set("str", 70);
  set("per", 10);
  set("combat_exp",2500000);
  set("combat_exp",9500000);
  set("max_qi", 4000);
  set("max_jing", 4000);
  set("max_neili", 4000);
  set("neili", 4000);
  set("force_factor", 200);
  set("mana_factor", 50);

  setup();
   initlvl((200+random(200)),59);
  //carry_object("/d/kaifeng/obj/jiuchipa")->wield();
  carry_object("/d/obj/armor/tongjia")->wear();
}
void init()
{
          object ob = this_player();

        if ( ob->query_temp("apply/name")&&
            ob->query_temp("apply/name")[0] == "´äÀ¼" )
        {
        command("hug cui lan");
        command("kiss cui lan");
        return;
        }
        return ;
}

int accept_fight (object ob)
{
  
  kill_ob (ob);
}
void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
 call_out ("move_to_cave",1,this_object());

}

void move_to_cave (object me)
{
  object where = environment(me);
//  string place;
  //place = "/d/qujing/yunzhan/shulin1";
 // place[strlen(place)-1] = '0'+random(10); 
  if (! where ||
    where->query("short") == "[33mÊ÷ÁÖ[m")
    return;
  message_vision ("\n$N»¯×÷Ò»µÀ½ð¹âÏûÊ§ÁË£¡\n",me);
  me->move("/d/qujing/yunzhan/shulin7");
}
void die()
{
  object me = this_object();
  object ob = query_temp("my_killer");

  if (ob)
  {
  message_vision(HIR"Ö»¼û$N±ä³ÉµÀµÀ½ð¹âÖ±³åÔÆÏö¡£\n"NOR,me);
  message_vision(HIR"Ô­À´$NÊÇ¸öÌì¹ÙÏÂ·²£¬Í¶´íÁËÌ¥¡£\n"NOR,me);
  ob->set_temp("pig_killed",1);
  destruct(me) ;
   }
}

//Cracked by Roath

inherit NPC;
#include <ansi.h>
#include "/d/migong/romnpc2.c"
void create()
{
          set_name("Ğ¡°×Áú", ({"bai long","long","dragon"}));
          set("long","Ëû±¾ÊÇÎ÷º£ÁúÍõ°½ÈòÖ®×Ó£¬Òò·¸ÁËÄæØõÖ®×ï£¬±»±áÏÂÈË¼ä¡£\n");
          set("gender", "ÄĞĞÔ");
          set("age", 23);
          set("per",30);        
          set("str",60);        
          set("combat_exp", 5000000);
          set("per", 30);
          set("max_qi", 4200);
          set("qi",4200);
          set("force_factor",200);
          set("max_jing", 2800);
          set("env/wimpy",60);
          set("jing",2800);
          set("combat_exp", 7000000);
          set("neili", 4000);
          set("max_neili", 2000);
          set("max_neili", 1800);
          set("neili", 1600);
          set_skill("unarmed", 220);
          set_skill("dodge", 300);
          set_skill("force", 200);
          set_skill("parry", 180);
          set_skill("hammer", 190);
          set_skill("staff", 80);


         setup();
         initlvl((200+random(100)),6);
        carry_object("/d/obj/cloth/longpao")->wear();
}

int accept_fight (object ob)
{
  
  kill_ob (ob);
  return 1;
}
void destruct_me (object me)
{
  destruct (me);
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
        tell_room(environment(me),HIY"Ğ¡°×ÁúÒ¡ÉíÒ»±ä£¬±äµÃºÍĞ¡ÓãÃçÒ»Ä£Ò»Ñù¡£\n"NOR);
        tell_room(environment(me),"Ğ¡°×ÁúÌÓÅÜÊ§°Ü.....\n");
        this_object()->set_name("[31mĞ¡ÓãÃç[m",({"xiao yumiao","fish"}));
}
void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object pusa = new ("/d/qujing/yingjian/npc/pusa");


  if (ob)
  {
    ob->set_temp("obstacle/long_killed",1);
    call_out ("pusa_appearing",1,ob);
    pusa->announce_success (ob);
  destruct (pusa); 
  }
  message_vision ("\nÖ»¼ûĞ¡ÓãÃçË»½ĞÒ»Éù£¬³åÌì¶øÆğ£¬Ô­À´ÊÇÌõÕæÁú¡£\n",ob);
::die();
}



void unconcious ()
{
  die ();
}

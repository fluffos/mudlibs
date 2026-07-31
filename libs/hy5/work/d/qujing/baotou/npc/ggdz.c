// rewritten by snowcat on 4.12.1997

inherit NPC;
#include "/d/migong/romnpc2.c"
int move_player();

void create()
{
  set_name("¹Å¹Öµó×ê", ({"guguai diaozuan", "diaozuan", "zuan"}));
  set("gender", "ÄĞĞÔ");
  set("age", 20);
  set("attitude", "friendly");
  set("combat_exp", 150000);
  set("combat_exp", 200000);

  set("per", 25);
  set_skill("dodge", 60);
  set("max_jing",600);
  set("max_qi",600);
  set("max_jing",600);
  set("neili",800);
  set("max_neili",800);
  set("max_neili",800);
  set("force_factor",25);
  set_skill("unarmed",60);
  set_skill("parry",60);
  set_skill("dodge",60);
  setup();
initlvl((600+random(600)),55);
  set("inquiry", ([
       "here": "Õâ¶ùÊÇ±ªÍ·É½£¬ÉÏÃæÊÇ»¢¿Ú¶´Ò²¡£\n",
       "±ªÍ·É½": "±ªÍ·É½£¬ÉÏÃæ±ãÊÇ»¢¿Ú¶´¡£\n",
       "»¢¿Ú¶´": (: move_player :),
       "dong": (: move_player :),
       "name": "¹Å¹Öµó×ê¡£\n",
      ]));
  carry_object("/d/qujing/baotou/obj/cloth1")->wear();
  carry_object("/d/qujing/baotou/obj/weapon1")->wield();

}

int move_player()
{
  object me = this_object();
  object who = this_player();

  message_vision ("$N¿´ÁË$nÒ»ÑÛ¡£\n",me,who);
  if (who->query("combat_exp") < 10000)
  {
    message_vision ("$NÒ¡Ò¡Í·£ºµÀĞĞ²»¹»£¬È¥²»µÃÈ¥²»µÃ¡£\n",me);
    return 1;
  }


 
  message_vision ("$NËµ£º$n½ñÌìºıÍ¿ÁËÒ²£¬ĞÖµÜÎÒÒ»½Å¾Í°ÑÄãÌß½ø¶´Àï¡£\n",me,who);
  message_vision ("Ëµ×Å$N·ÉÆğÒ»½Å£¬$nË³ÊÆÍùÉÏÒ»Ô¾¡£\n",me,who);
  who->move("/d/qujing/baotou/dongwai");
  message_vision ("¶´¿ÚÒ»ÕóĞÈ·ç´µÀ´£¬$N¸Ğµ½Ò»ÕóÍ»ÈçÆäÀ´µÄÍ·ÔÎ¡£\n",who);
  who->set("neili",0);
  return 1;
}

ÿ
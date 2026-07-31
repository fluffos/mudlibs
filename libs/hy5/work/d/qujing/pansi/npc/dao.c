// created 11/20/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("µÀÊ¿", ({ "dao shi", "dao", "shi" }));
  set("title", "»Æ»¨Îå¹«");   
  set("long", "Ò»Î»ÓûÉñÓûÏÉµÄ»Æ»¨¹ÛÎå¹«µÀÊ¿¡£");
  set("gender", "ÄĞĞÔ");
  set("age", 40);
  set("attitude", "heroism");
  set("per", 29);
  set("max_qi", 1500);
  set("max_jing", 1500);
  set("max_jing", 1500);
  set("neili", 1200);
  set("max_neili", 1200);
  set("force_factor", 100);
  set("max_neili", 600);
  set("neili", 600);
  set("mana_factor", 80);
  set("combat_exp", 550000);
  set("combat_exp", 53600000);

 
  setup();
  initlvl((600+random(600)),7);
  carry_object("/d/obj/cloth/daopao")->wear();
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object daogu = new ("/d/qujing/pansi/npc/daogu");
  if (ob && 
      ! ob->query_temp("obstacle/pansi_killed_"+me->query("name")))
  {
    ob->set_temp("obstacle/pansi_killed_"+me->query("name"),1);
    ob->add_temp("obstacle/pansi_killed",1);
  }
  if (ob &&
      ob->query_temp("obstacle/pansi_killed")>=15 &&
      ob->query("obstacle/pansi")!="done")
  {
     daogu->announce_success (ob);
  destruct (daogu); 
  }
  message_vision ("\n$NÆËµ¹ÔÚ³¾°£Àï£¬ÏÖÉíÎªÒ»Æß³ßòÚò¼¾«¡£\n",me);
  message_vision ("\nòÚò¼¾«»¯ÎªÒ»¹ÉÇàÑÌàáµØÏûÉ¢ÁË¡£\n",me);
::die();
}

void daogu_appearing (object who)
{
  


}

void destruct_me(object me)
{
  destruct(me);
}

void unconcious ()
{
  die ();
}

/*
void fight_ob (object ob)
{
  object me = this_object();

  call_out ("recovering",1,me,ob);  
  call_out ("hurting",random(5)+5,me,ob);  
}
*/

int accept_fight(object ob)
{
  
  kill_ob(ob);
  return 1;
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  call_out ("recovering",1,me,ob);  
  call_out ("hurting",random(5)+5,me,ob);  
  ::kill_ob(ob);
}

void recovering (object me, object ob)
{
  object needle;

  if (! me)
    return;

  if (! ob)
    return;

  //if (! me->is_fighting())
  //   return;

  if (environment(ob) != environment(me))
    return;

  needle = present("xiuhua zhen",ob);
  if ((! needle ||
       needle != ob->query_temp("weapon")) &&
       (me->query("qi") < (me->query("max_qi")*3/4) ||
        me->query("jing") < (me->query("max_jing")*3/4)))
  {
    message_vision ("\n$NÉíÉÏÍòµÀ½ğ¹âÒ»ÉÁ£¬¶ÙÊ±¾«ÉñÆøÑª¾¡»Ø£¡\n",me);
    me->set("jing",me->query("max_jing"));
    me->set("qi",me->query("max_qi"));
    me->set("jing",me->query("max_jing"));
    me->set("eff_jing",me->query("max_jing"));
    me->set("eff_qi",me->query("max_qi"));
    me->set("eff_jing",me->query("max_jing"));
  }
  call_out ("recovering",1,me,ob);  
}

void hurting (object me, object ob)
{
  string *msgs = ({
    "$N½«ÒÂÒ»ÏÆ£¬ÎŞÊıµÀ½ğ¹âÏò$nÒ»Éä£¡\n",
    "$NÒ»Ì§ÊÖ£¬Ğ²ÏÂÇ§Ö»ÑÛ¾¦½ğ¹âÉÁÉÁÉäÏò$n£¡\n",
    "$NÏÆÆğ¸ì²²ÏÂÎŞÊıÖ»ÑÛ¾¦±Å³ö½ğ¹âÖ±ÉäÏò$n£¡\n",
  });
  string *strs = ({
    "( $NÒ»¸öôóôò²»ÓÉ×ÔÖ÷µØ²Ò½ĞÒ»Éù£¡ )\n",
    "( $NÓ¦Éùµ¹ÏÂ£¬ÓÖÃãÇ¿ÅÀ½«ÆğÀ´£¡ )\n",
    "( $NÍ´¿àµØ²Òº¿ÁËÒ»Éù£¡ )\n",
  });
  object needle;
  int damage;

  if (! me)
    return;

  if (! ob)
    return;

  //if (! me->is_fighting())
  //  return;

  if (environment(ob) != environment(me))
    return;
 
  message_vision ("\n"+msgs[random(sizeof(msgs))],me,ob);
  
  needle = present("xiuhua zhen",ob);
  if (! needle ||
      needle != ob->query_temp("weapon") ||
      random(3) == 0)
  {
    message_vision (strs[random(sizeof(strs))],ob);
    damage = ob->query("max_qi")/(6+random(4));
    ob->add("qi",-damage); 
    ob->add("eff_qi",-damage); 
    ob->add("jing",-damage); 
    ob->add("eff_jing",-damage); 
  }
  else
  {
    message_vision ("µ«¼û$NÊÖÉÏĞå»¨ÕëÒ»ÉÁ£¬"+
                    "$nº¿½ĞÒ»Éù£¬Ğ²ÏÂ¼¸Ö»ÑÛ¾¦¶ÙÊ±ÃğÈ¥£¡\n",ob,me);
  }
  remove_call_out ("hurting");  
  call_out ("hurting",random(10)+10,me,ob);  
}
ÿ
// sgzl

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("»ìÊÀÄ§Íõ", ({ "hunshi mowang", "mowang"}) );
  set("gender", "ÄĞĞÔ" );
       set("long",
                "Ö»¼ûÕâÄ§Íõ£º\n
¡¡¡¡Í·´÷ÎÚ½ğ¿ø£¬Ó³ÈÕ¹âÃ÷£»Éí¹ÒÔíÂŞÅÛ£¬Ó­·çÆ®µ´¡£
    ÏÂ´©×ÅºÚÌú¼×£¬½ôÀÕÆ¤Ìõ£»×ãÌ¤×Å»¨ñŞÑ¥£¬ĞÛÈçÉÏ½«¡£
    Ñü¹ãÊ®Î§£¬Éí¸ßÈıÕÉ£¬ÊÖÖ´Ò»¿Úµ¶£¬·æÈĞ¶àÃ÷ÁÁ¡£
    ³ÆÎª»ìÊÀÄ§£¬ÀÚÂäĞ×Ä£Ñù¡£\n");
  set("age", 30);
  set("str", 30);
  set("per", 30);
  set("int", 30);
  set("attitude", "killer");
  
  set("combat_exp", 150000);
  set("daoxing", 100000);



 

  setup();
initlvl((600+random(600)),61);
  carry_object("/d/obj/armor/tongjia.c")->wear();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/obj/weapon/blade/yanblade.c")->wield();
}

void init()
{
  object ob=this_player();

  ::init();
     remove_call_out("greeting");
     call_out("greeting", 1, ob);
}

void greeting(object ob)
{
  object me=this_object();
  message_vision("$NºÈµÀ£ºÕâµØÅÌÀÏ×ÓÕ¼ÁË£¬À´ÕÒËÀÂï£¡\n",me);
  command("kill " + ob->query("id"));
}


int accept_fight (object ob)
{
  
  kill_ob (ob);
  return 1;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}


void die()
{
  object ob = query_temp("my_killer");
  object me = this_object();
  object ma;
  object panzi;

  if (ob)
  {
  message_vision ("\n$N²Ò½ĞÒ»Éù£¬±»¿³ÎªÁ½¶Î¡£\n",me);
  ma = new (__DIR__"ma");
  message_vision ("\nºï×ÓÍ·ÁìÂíÔªË§Áì×Å¼¸Ö»ºï×ÓÅÜÁË¹ıÀ´£¬¿´µ½$N±»Õ¶£¬¸ßĞËµÄÌøÁËÆğÀ´¡£\n",me);
  if(ob->query("dntg/huaguo")!="done")  
    {
    ma->announce_success (ob);
    panzi = new ("/d/qujing/hgs/obj/shipan");
    panzi->move(ob);
    }
  message_vision ("\nÂíÔªË§´ø×ÅÖÚºï×ÓÆßÊÖ°Ë½ÅµÄ°Ñ$NµÄÊ¬ÌåÍÏÁË³öÈ¥¡£\n",me);
  destruct (ma);
  }
  destruct(me);
}

ÿÿ

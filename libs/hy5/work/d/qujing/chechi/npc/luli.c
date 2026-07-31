// create by snowcat 10/16/1997

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("Â¹Á¦´óÏÉ", ({"luli daxian", "luli", "daxian" }));
  set("title","¹úÊ¦");
  set("long","³µ³Ù¹úµÄÈý´óµÀÊ¿Ö®Ò»£¬ÉÆÓÚÇóË®ÆíÓê£¬±»×ðÎª¹úÊ¦¡£\n");
  set("gender", "ÄÐÐÔ");
  set("rank_info/respect", "¹úÊ¦");
  set("age", 40);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30);
  set("max_qi", 1300);
  set("max_jing", 1300);
  set("max_jing", 1300);
  set("neili", 1300);
  set("max_neili", 1300);
  set("force_factor", 80);
  set("max_neili", 1300);
  set("neili", 1300);
  set("mana_factor", 40);
  set("combat_exp", 900000);
  set("combat_exp", 25000000);

  set_skill("unarmed", 75);
  set_skill("dodge", 75);
  set_skill("parry", 75);
  set_skill("spells", 75);
  set_skill("force", 75);
  
  setup();
    initlvl((380+random(380)),62);
  carry_object("/d/obj/cloth/daopao")->wear();
  
}

void init()
{
  ::init();
  call_out("follow_player",random(10)+1,this_object(),this_player());
}

void follow_player (object me, object who)
{
  object room = environment(me);

  if (room->query("short")!="ÈýÇåµî")
    return;

  if (! who)
    return;

  if (me->query("have_followed"))
    return;
    
  if (who->query("obstacle/chechi")=="done")
    return;

  if (who->query_temp("obstacle/chechi")!="eaten")
    return;

  if (room != environment(who))
    return;

  me->set_temp("no_return",1);
  me->set("have_followed",1);
  message_vision ("Ö»¼û$NÒ»±ßµ»¸æ£¬Ò»±ßÐ±ÑÛ¿´×Å$n¡£\n",me,who);
  who->set("neili",0);

  call_out("do_follow",random(3)+3,me,who);
}

void do_follow (object me, object who)
{
  object room = environment(me);

  if (room->query("short")!="ÈýÇåµî")
    return;

  if (! who)
    return;

  if (room != environment(who))
    return;

  me->set_leader(who);
  message_vision ("$N¶Ô×Å$nÒ»ÉùÀäÐ¦¡£\n",me,who);
  if (!who->query_temp("chechi/recognized"))
  {
    who->set_temp("chechi/recognized",1);
    message_vision("$NºÈµÀ£º¡°´óµ¨ÍçÍ½£¬¾¹¸ÒÃ°³äÎÒµÀÊ¥ÈË£¡¿ìÈ¥¼û¹úÍõÁì×ï£¡¡±\n",
                   me,who);
  }
  message_vision ("$N¾ö¶¨¿ªÊ¼¸úËæ$nÒ»ÆðÐÐ¶¯¡£\n",me,who);
}

void die()
{
  object me = this_object();
  object where = environment(me);
  object ob = new ("/d/qujing/chechi/obj/lutou");

  message_vision ("$NÈíÈíµØµ¹ÏÂ£¬ÁôÏÂÒ»Ö»°×É«Â¹Í·¡£\n",me);
  ob->move(where);
  destruct(me);
}

ÿ
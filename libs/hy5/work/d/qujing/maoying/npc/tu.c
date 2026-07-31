// created 11/20/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
string *names = ({
  "白兔精",
  "灰兔精",
  "黑兔精",
  "赤兔精",
  "黄兔精",
  "长毛兔精",
  "短毛兔精",
  "卷毛兔精",
});

void jump_away ();

void create()
{
  set_name(names[random(sizeof(names))], ({ "tu jing", "tu", "jing" }));
  set("long", "一位兔模兔样的女子。\n");
  set("gender", "女性");
  set("age", 20);
  set("attitude", "peaceful");
  set("per", 29);
  set("max_qi", 1800);
  set("max_jing", 1800);
  set("max_jing", 1800);
  set("neili", 1800);
  set("max_neili", 1800);
  //set("force_factor", 10);
  set("max_neili", 1100);
  set("neili", 1100);
  set("mana_factor", 80);
  set("combat_exp", 2540000);
  set("combat_exp", 68000000);


  set("chat_chance_combat", 2);
  set("chat_msg_combat", ({ (: jump_away :) }) );

  setup();
   initlvl((860+random(860)),2);
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

void jump_away ()
{
  string s;
  object room;
  object me = this_object();
  
  s = sprintf ("/d/qujing/maoying/shanpo%d.c",random(10)+1);
  room = load_object(s);
  message_vision ("嗖地一声，$N向外跳去……\n",me);
  me->move(room);
  if (present("tu jing 6",environment(me)))
    destruct (me);
  else
    message_vision ("$N嗖地一声跳了过来……\n",me);
}

void destruct_me(object me)
{
  destruct(me);
}

void unconcious ()
{
  die ();
}

void die ()
{
  object me = this_object();
  message_vision ("\n$N翻倒在地，还原为一只野兔，向外一蹿。\n",me);
::die();
}

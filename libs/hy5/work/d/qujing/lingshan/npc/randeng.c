//Cracked by Roath
// snowcat 12 14 1997

inherit NPC;
#include "/d/migong/romnpc2.c"
int give_book ();

void create()
{
  set_name("燃灯古佛", ({ "randeng gufo", "randeng", "gufo" }));
  set("title", "灵山");
  set("gender", "男性");
  set("age", 1000);
  set("attitude", "peaceful");
  set("str",40);
  set("per",40);
  set("max_qi", 3000);
  set("max_jing", 3000);
  set("max_jing", 3000);
  set("neili", 3000);
  set("max_neili", 3000);
  set("force_factor", 100);
  set("max_neili", 3000);
  set("neili", 3000);
  set("mana_factor", 100);
  set("combat_exp", 1500000);
  set("combat_exp", 5000000);

  set_skill("literate", 120);
  set_skill("spells", 120);

  set("inquiry", ([
    "book" : (: give_book :),
    "jing" : (: give_book :),
    "qujing" : (: give_book :),
    "经" : (: give_book :),
    "取经" : (: give_book :),
    "经书" : (: give_book :),
  ]) );

  setup();
        initlvl((1000+random(1000)),random(63));
  carry_object("/d/obj/cloth/jia_sha")->wear();
}



int give_book()
{
  object me = this_object();
  object who = this_player();
  object book;

  if (! who->query("obstacle/reward"))
  {
    message_vision ("$N对$n摇了摇头：你先回去，好好过西域再来取经。\n",me,who);
    return 1;
  }
  if (me->query_temp("given_book"))
  {
    message_vision ("$N对$n摇了摇头：经书已给过了，等等再来吧。\n",me,who);
    return 1;
  }
  book = new (__DIR__"qujing");
  command ("nod");
  message_vision("$N给$n一本"+book->query("name")+"。\n",me,who);
  if(!book->move(who)) {
      destruct(book);
  }
  command ("give "+who->query("id")+" book");
  me->set_temp("given_book",1);
  call_out("reset_give",180);
  return 1;
}

void reset_give ()
{
  object me = this_object();
  me->set_temp("given_book",0);
}





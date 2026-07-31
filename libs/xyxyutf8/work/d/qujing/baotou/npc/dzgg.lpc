// rewritten by snowcat on 4.12.1997

inherit NPC;

int move_player();

void create()
{
  set_name("刁钻古怪", ({"diaozuan guguai", "guguai", "guai"}));
  set("gender", "男性");
  set("age", 20);
  set("attitude", "friendly");
  set_level(50);

  set("per", 25);
  set_skill("dodge", 500);
  set_skill("unarmed",500);
  set_skill("parry",500);
  set_skill("dodge",500);
  setup();

  set("inquiry", ([
       "here": "这儿是豹头山，上面是虎口洞也。\n",
       "豹头山": "豹头山，上面便是虎口洞。\n",
       "虎口洞": (: move_player :),
       "dong": (: move_player :),
       "name": "刁钻古怪。\n",
      ]));
  carry_object("/d/qujing/baotou/obj/cloth1")->wear();
  carry_object(sprintf("/d/qujing/baotou/obj/weapon%d",random(2)))->wield();

}

int move_player()
{
  object me = this_object();
  object who = this_player();

  message_vision ("$N看了$n一眼。\n",me,who);
  if(who->query_level()<40)
  {
    message_vision ("$N摇摇头：道行不够，去不得去不得。\n",me);
    return 1;
  }

  if (! who->query_temp("apply/name") ||
      who->query_temp("apply/name")[0] != "古怪刁钻")
  {
    message_vision ("$N摇摇头：不认得你，不认得你。\n",me);
    return 1;
  }
 
  message_vision ("$N说：$n今天糊涂了也，兄弟我一脚就把你踢进洞里。\n",me,who);
  message_vision ("说着$N飞起一脚，$n顺势往上一跃。\n",me,who);
  who->move("/d/qujing/baotou/dongwai");
  message_vision ("洞口一阵腥风吹来，$N感到一阵突如其来的头晕。\n",who);
  who->set("mana",0);
  return 1;
}
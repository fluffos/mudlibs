// rewritten by snowcat on 4.12.1997

inherit NPC;

int give_fajian();

void destruct_me (object me)
{
  message_vision ("$N往地下一钻便消失了。\n",me);
  destruct (me);
}

void create()
{
  set_name("白髯土地", ({"tu di", "tu", "di"}));
  set("gender", "男性");
  set("age", 100);
  set("attitude", "friendly");
  set("combat_exp", 250000);
  set("daoxing", 300000);

  set("per", 25);
  set_skill("dodge", 60);
  set("max_sen",600);
  set("max_gee",600);
  set("max_gin",600);
  set("force",800);
  set("max_force",800);
  set("max_mana",800);
  set("force_factor",25);
  set_skill("spells",60);
  set_skill("stick",60);
  setup();

  set("inquiry", ([
       "here": "这儿是隐雾山，亦有连环洞在此。\n",
       "隐雾山": "隐雾山乃有连环洞之去处，多加小心为是。\n",
       "连环洞": "连环洞在隐雾山下连环相衔，有两个入口也。\n",
       "name": "隐雾山土地也，老夫别无他物，只有一宝。\n",
       "宝": "老夫有一法简，乃一锦一禅师所赠。\n",
       "法简": (: give_fajian :),
       "fajian": (: give_fajian :),
      ]));
  carry_object("/d/obj/cloth/choupao")->wear();

}

int give_fajian()
{
  object me = this_object();
  object who = this_player();
  object fajian;

  if (who->query_level()<40 ||
      present("fa jian",who))
  {
    command ("shake");
    return 1;
  }

  fajian = new ("/d/qujing/yinwu/obj/fajian");
  fajian->move(me);
  command("hmm");
  command("give "+who->query("id")+" fa jian"); 
  destruct_me(this_object());
  return 1;
}

void die()
{
	destruct_me(this_object());
}
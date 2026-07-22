// by snowcat oct 22 1997

inherit NPC;

void create()
{
  set_name("护宫卫士", ({"wei shi", "shi"}));
  set("gender", "男性");
  set_level(40);
  set("age", 30);
  set("per", 25);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",60);
  set_skill("unarmed",400);
  set_skill("dodge",400);
  set_skill("parry",400);
  set_skill("force",400);
  set_skill("spells",400);
  setup();
  carry_object("/d/obj/armor/tongjia")->wear();
  carry_object("/d/obj/weapon/spear/tieqiang")->wield();
  set("no_nk_reward",1);
}

void init ()
{
  object ob = this_player();
  object me = this_object();

  if(living(ob))
  call_out("greeting", 1, ob);
}

void greeting(object ob)
{
  if( !ob || environment(ob) != environment() ) return;
  if (ob && interactive(ob))
  {
    if (! ob->query_temp("weishi_kill"))
      message_vision ("$N喝道：贱民无法无天，擅闯禁地！\n",this_object());
    this_object()->kill_ob(ob);
    ob->set_temp("weishi_kill",1);
  }
}

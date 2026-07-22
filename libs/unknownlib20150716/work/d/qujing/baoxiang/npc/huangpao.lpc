// create by snowcat 10/16/1997

inherit NPC;

int give_dan ();

void create()
{
  set_name("黄袍怪", ({"huangpao guai", "guai" }));
  set("title","奎木狼");
  set("gender", "男性");
  set_level(150);
  set("age", 120);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("force_factor",1500);
  set("mana_factor", 40);

  set_skill("unarmed",1500);
  set_skill("dodge",1500);
  set_skill("parry",1500);
  set_skill("spells",1500);
  set_skill("force",1500);
  set_skill("gouhunshu",1500);
  set_skill("tonsillit",1500);
  set_skill("ghost-steps",1500);
  set_skill("jinghun-zhang",1500);
  map_skill("unarmed", "jinghun-zhang");
  map_skill("dodge", "ghost-steps");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  set("eff_dx",-150000);
  set("nkgain",200);
  set("inquiry", ([
       "丹": (: give_dan :),
       "内丹": (: give_dan :),
       "舍利子": (: give_dan :),
       "舍利子内丹": (: give_dan :),
      ]));
  
  setup();
  carry_object("/d/qujing/baoxiang/obj/sppifeng")->wear();
  
}

int give_dan ()
{
  object me = this_object();
  object who = this_player();
  string *names = who->query_temp("apply/name");
  
  if (! names ||
      sizeof(names)==0 ||
      names[0]!="百花羞")
  {
    message_vision ("$N说道：你是何许人也？\n",me);
    return 1;
  }
  if (me->query("has_given"))
  {
    message_vision ("$N说道：浑家，舍利子内丹不是已在你处？\n",me);
    return 1;
  }
  if (me->query("has_refused"))
  {
    message_vision ("$N说道：浑家好无理，舍利子内丹不给就是不给，怎好无礼强求？\n",me);
    return 1;
  }
  if (random(3))
  {
    me->set("has_refused",1);
    message_vision ("$N说道：浑家，舍利子内丹还是放在我身边为好。\n",me);
    return 1;
  }
  else
  {
    object dan = new ("/d/qujing/baoxiang/obj/dan");
    me->set("has_given",1);
    message_vision ("$N说道：浑家，我这就给。\n",me);
    message_vision ("$N递给$n一颗舍利子内丹。\n",me,who);
    dan->move(who);
    return 1;
  }
}

void die()
{
  if( environment() )
    message("sound", "\n\n奎木狼星嗖地向天空飞去……\n\n", environment());
  destruct (this_object());
}
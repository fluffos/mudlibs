#include <ansi.h>
inherit NPC;

int ask_title();
string ask_player();

void create()
{
	set_name("袁天罡", ({ "yuan tiangang", "yuan" }));
	set("title",HIC"玄都观主"NOR);
  set("gender", "男性");
	set("age", 80);
	set("long", "这是一个得道高人，被唐太宗奉为国师。\n");
	
	set("combat_exp", 10000000);
	set("shen_type", 1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

  set("inquiry", ([
    "休闲玩家" : (: ask_player :),
  ]) );

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

string ask_player()
{
  object me=this_player();
  
  if ( time()-me->query("xiuxian_time")<7*24*3600 )
    return "你刚下了决心，马上就反悔似乎有点不妥，再考虑一阵子再过来吧。\n";
  
  if ( me->query("xiuxian_player") )
  {
    tell_object(me, "你决定要重入江湖？（Y-是/其他输入-取消）：");
    input_to("xiuxian_decide", me);
    return 0;
  }
  else
  {
    if ( me->query("combat_exp")<=10000000 || me->query("mud_age")/3600<24*15 )
      return "你涉入江湖不深，现在退隐江湖似乎过早了一点。\n";
    
    if ( time()<me->query("xiuxian_abuse") )
      return "你在江湖中与人结怨甚深，现在退隐江湖还未到时机。\n";
    
    tell_object(me, "你厌倦了江湖仇杀，决心退隐江湖？（Y-是/其他输入-取消）：");
    input_to("tuiyin_decide", me);
    return 0;
  }
}

protected void xiuxian_decide(string dmsg, object me)
{
  if ( dmsg == "Y" || dmsg =="y" )
  {
    me->delete("xiuxian_player");
    me->set("xiuxian_time", time());
    CHANNEL_D->do_channel(this_object(), "jh", HIC+me->query("name")+HIC"决定重出江湖。");
    tell_object(me, "你慎重考虑以后决定重出江湖。\n");
    return;
  }
  else 
    tell_object(me, "你经过慎重考虑以后，还是没下定决心要重出江湖。\n");  
}

protected void tuiyin_decide(string dmsg, object me)
{
  if ( dmsg == "Y" || dmsg =="y" )
  {
    me->set("xiuxian_player",1);
    me->set("xiuxian_time", time());
    CHANNEL_D->do_channel(this_object(), "jh", HIC+me->query("name")+HIC"厌倦了江湖仇杀，决心退隐江湖。");
    tell_object(me, "你慎重考虑以后决定退隐江湖。\n");
    return;
  }
  else 
    tell_object(me, "你经过慎重考虑以后，还是没下定决心要退隐江湖。\n");  
}
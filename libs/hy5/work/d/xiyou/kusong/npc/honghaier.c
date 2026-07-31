//Cracked by Roath
inherit NPC;
#include "/d/migong/romnpc2.c"
#include <ansi.h>
int ask_niang(object me);
int do_yes();

int rank_me();

void create()
{
       set_name("红孩儿", ({"honghai er","er"}));
	set("title", "圣婴大王");
	set("long", "牛魔王与罗刹女的儿子，于火焰山中修炼了一身好本领。\n");
       set("gender", "男性");
       set("age", 16);
	set("per", 25);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("spi", 25);

       	set("attitude", "heroism");

        
  set("combat_exp", 22500000);

        set("eff_dx", -500000);
        set("nkgain", 500);

       	set("class","yaomo");
       	set("max_qi", 1600);
       	set("max_jing", 1600);
       	set("neili", 2500);
       	set("max_neili", 1600);
       	set("force_factor", 100);
       	set("max_neili", 1600);
       	set("neili", 2500);
       	set("mana_factor", 80);
       



	create_family("火云洞", 2, "蓝");

        set("inquiry", ([
               
                "铁扇公主": (: ask_niang :),
]) );


        setup();
        
if (random(2)==0)
     initlvl((290+random(390)),7);        
else initlvl((390+random(390)),59);
     
        carry_object("/d/qujing/nanhai/obj/huojianqiang")->wield();
        carry_object("/d/qujing/bibotan/obj/zhanpao")->wear();
}





void init()
{
        object ob = this_player();
        remove_call_out("check");
        call_out("check",1,ob);
        add_action("do_yes","ok");
}

void check(object ob)
{
        object where;
        if (!ob) return;
        where=environment(ob);
        if(ob->query("family/family_name") == "火云洞")
           return;
        if(ob->query("title") == "普通百姓")
           return;
        if(ob->query_temp("kusong_killed") == 1)
           return;
        if ( random(10)==0 )
           {
        command("say 这位朋友与我有缘。");
        command("say 我正好抓到一个和尚，吃了他，可以长生不老啊。");
        command("xixi");
        return;
            }

        if( present("jin che",where) || present("mu che",where)
        ||  present("shui che",where) || present("huo che",where) ||
            present("tu che",where) )
          {
if (userp(ob)) {
        kill_ob(ob);
        message_vision(HIR"只见红孩儿手架五行车，手中火尖枪对$N一指。\n"NOR,ob);
        message_vision(HIR"一股三昧真火带着浓烟扑向$N，$N抽身便走。\n"NOR,ob);
        ob->move(__DIR__"guaishiya");
        ob->unconcious();
        }
}

}
int ask_niang(object me)
{
       me=this_player();
       command("jump");
       me->set_temp("ok",1);
       command("say 我去请我娘一起吃肉好吗（ok）？\n");
       return 1;
}

int do_yes()
{
        object ob = this_player();
        if( ! ob->query_temp("ok") ) return 0;
        command("say 请在家等候，孩儿快去快回。");
        command("bye");
        destruct(this_object());
        return 1;
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
void announce_success (object who)
{
  int i;
  object honghaier= this_object();

  if (! who->query_temp("che1_broken"))
   {
    destruct (honghaier);
    return;
   } 
  if (! who->query_temp("che2_broken"))
   {
    destruct (honghaier);
    return;
   } 
  if (! who->query_temp("che3_broken"))
   {
    destruct (honghaier);
    return;
   } 
  if (! who->query_temp("che4_broken"))
   {
    destruct (honghaier);
    return;  
   } 
  if (! who->query_temp("che5_broken"))
   {
    destruct (honghaier);
    return;  
   } 
  honghaier->move(environment(who));
  who->set_temp("kusong_killed",1);
  message_vision (HIR"一团红色的烟雾涌了过来,红孩儿突然从里面蹦了出来.\n"NOR,who);
  message_vision (HIG"$N手中"HIR+"火尖枪"HIG+"朝$n一指:大胆臭贼,敢破坏我的五行车.\n"NOR,honghaier,who);
  message_vision (HIG"只听一声$N怒喝:我就说父王怎么会来看我.臭贼拿命来.\n"NOR,honghaier,who);
  who->command("bian");
  kill_ob(who);
}  
void die()
{
  object ob = query_temp("my_killer");
  object pusa = new ("/d/qujing/kusong/npc/pusa");
  object me = this_object();
  if (ob->query_temp("obstacle/hong_killed")) 
{
	::die();  
  return ;
}
  if (ob)
  {
    ob->set_temp("obstacle/hong_killed",1);
  pusa->announce_success (ob);
  destruct (pusa); 
  }
  message_vision(HIY"天上传来观音菩萨的声音：红孩儿，还不随我回南海去。\n"NOR,ob);
::die();
}
void destruct_me (object me)
{
  destruct (me);
}


void unconcious ()
{
  die();
}

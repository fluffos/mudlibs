//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/npc/dahan.c
 

inherit NPC;
#include <ansi.h>
#include "/d/migong/romnpc2.c"
string ask_jiasha();

void create()
{
   set_name("黑熊怪", ({ "hei xiong", "bear", "monster" }));
   set("long", "山间野兽，不知从哪里学到一身好本领。");
   set("gender", "男性");
   set("age", 30);
   set("attitude", "heroism");
   set("per", 9);
   set("rank_info/self", "黑熊");
   set("rank_info/rude", "熊怪");
   set("max_qi", 2000);
   set("max_jing", 2000);
   set("neili", 1000);
   set("max_neili", 1000);
   set("force_factor", 20);
   set("max_neili", 1000);
   set("neili", 1000);
   set("mana_factor", 20);
   set("combat_exp", 8500000);
  
   set("inquiry",([
        "袈裟": (: ask_jiasha :),
        "jiasha":  (: ask_jiasha :),
        ]));

   setup();
   initlvl((200+random(200)),27);
   carry_object("/d/obj/weapon/spear/jinqiang")->wield();
}

int accept_fight (object ob)
{
  //
  kill_ob (ob);
  return 1;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
  call_out ("move_to_cave",1,this_object());
}

void move_to_cave (object me)
{
  object where = environment(me);
  object room = load_object("/d/qujing/heifeng/cave");
  if (! where ||
    where->query("short") == "正台")
    return;
  message_vision ("\n$N化作一阵风消失了！\n",me);
  me->move(room);
}

string ask_jiasha()
{
        object ob = this_player();
        object me = this_object();

        if( ob->query("obstacle/hf") )
        {
        command("shake");
        return("这又何从说起。\n");
        }



        command("hehe");
        return("请稍等。");

}

void unconcious ()
{
  die ();
}
void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
object pusa = new ("/d/qujing/heifeng/npc/pusa");
  if (ob)
  {
    ob->set_temp("obstacle/heixiong_killed",1);
      pusa->announce_success (ob);
  destruct (pusa); 
  //message_vision(HIR"只见$N摔倒在地，现了本形。原来是只黑熊！\n"NOR,me);
  }
  message_vision(HIR"只见$N摔倒在地，现了本形。原来是只黑熊！\n"NOR,me);
::die();
}


    

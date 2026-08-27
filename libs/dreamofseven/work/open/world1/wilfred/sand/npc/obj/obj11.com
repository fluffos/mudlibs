// ........................ 無言  wilfred@DS

#include <ansi.h>
inherit ITEM;
void do_heal(object me);

void create()
{
  set_name("羊皮帳蓬",({"tent"}));
  set_weight(2500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("short","帳篷內");
    set("long",@LONG
這是一個用草繩綑成一捲，以羊皮製成的小型帳篷，
類似外塞民族所使用的蒙古包，必需搭建起來才能使
用。可惜製工甚為粗糙，極易損壞。
使用方法: use tent
LONG
);
    set("value",400);
  }
  set("no_recall",1);
  set("no_clean_up",1);
  set("no_goto",1);
  set_max_encumbrance(1);
  setup();

}

void init()
{
  add_action("do_sleep","use");
}

int do_sleep(string str)
{
  object ob = this_object(), me = this_player(), *inv;
  int i;
  if(!str || str != "tent") return 0;

  if(me->is_ghost()) return notify_fail("你現在是鬼魂無法使用羊皮帳篷!\n");
   if(me->query_temp("killer"))
          return notify_fail("你殺了人暫時不可以使用羊皮帳篷!\n");
   if(me->query_temp("invader"))
     return notify_fail("你攻擊了玩家暫時無法使用羊皮帳篷!\n");

  if(me->is_busy() || me->is_fighting())
  {
    write("你正在忙，沒空作其他事情。\n");
    return 1;
  }
  if(me->query("hp") < 0) return notify_fail("你快要去見閻羅王了喔！\n");

  if(query("useing") || query("used"))
  {
    inv = all_inventory(environment(this_player()));
    for(i=0;i<sizeof(inv);i++)
      if(inv[i]->query("id") == "tent" && inv[i] != ob) return 0;
    inv = all_inventory(this_player());
    for(i=0;i<sizeof(inv);i++)
      if(inv[i]->query("id") == "tent" && inv[i] != ob) return 0;

    write("沒有多餘的羊皮帳篷可供你使用了！\n");
    return 1;
  }

  set_max_encumbrance(999999);
  if(environment(ob) == me)
  {
    message_vision(CYN"$N拿出一個$n，很快的把$n撘好了。\n"NOR,me,ob);
    ob->move(environment(me));
  }
  message_vision(HIW"\n$N一個矮身，往$n鑽了進去。\n\n"NOR,me,ob);
  set("long","這個" +ob->name(1)+ "正在使用中。\n");

  set("useing",1);
  set("no_get", 1);
  set("no_sac", 1);

  me->move(ob);
  me->set_temp("sleeping",1);
  me->start_busy(16);
  call_out("do_sleep_1",5,0,me);
  return 1;
}

void do_sleep_1(int index, object me)
{
  object ob = this_object();
  object *obs;
  int i;
  if(!me) destruct(ob);
  if(me->is_ghost() || !environment(me))
  {
    obs = all_inventory(ob);
    for(i=0;i<sizeof(obs);i++)
      obs[i]->move(environment(ob));
    delete("useing");
    delete("no_get");
    delete("no_sac");
    set("used",1);
    call_out("dest_obj",1);
    return;
  }
  if(environment(me) != ob)
  {
    me->delete_temp("sleeping");
    call_out("dest_obj",1);
    return;
  }

  switch(index)
  {
    case 0 : tell_room(environment(ob),HIM+ob->name(1)+"裡傳來陣陣打呼聲。\n"NOR,me);
             write(HIR"\n[你覺得眼皮沉重，馬上就睡著了]\n\n"NOR);
             do_heal(me);
             break;

    case 1 : write(HIR"\n .......... ＺZｚzＺ\n\n"NOR);
             do_heal(me);
             break;

    case 2 : write(HIG"\n醒來後你覺得精神好了很多，打了個呵欠，從" +ob->name(1)+ "裡走了出來。\n\n"NOR);
             tell_room(environment(ob),HIW+me->name(1)+"從"+ob->name(1)+"裡走了出來。\n"NOR,me);
             set("long","因使用過而變得破損不堪的"+ob->name(1)+"。");
             set_name("破損的帳蓬",({"broken tent","tent"}));

             delete("useing");
             delete("no_get");
             delete("no_sac");

             set("used",1);
             me->start_busy(0);
             me->delete_temp("sleeping");
             me->move(environment(ob));
             break;
  }
  index++;
  if(index < 3) call_out("do_sleep_1",12,index,me);
    else call_out("dest_obj",5);
  return;
}

void do_heal(object me)
{
  if(me->query("hp")+450 < me->query("max_hp")) me->add("hp",random(100)+350);
    else me->set("hp",me->query("max_hp"));
  if(me->query("ap")+250 < me->query("max_ap")) me->add("ap",random(50)+150);
    else me->set("ap",me->query("max_ap"));
  if(me->query("mp")+250 < me->query("max_mp")) me->add("mp",random(50)+150);
    else me->set("mp",me->query("max_mp"));
}

void dest_obj()
{
  message_vision("一陣風吹來，將$N吹垮了。\n",this_object());
  destruct(this_object());
}


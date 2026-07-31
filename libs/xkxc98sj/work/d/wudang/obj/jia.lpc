#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW "兵器架" NOR, ({ "bingqi jia", "jia" }) );         
        set_weight(30000000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("unit", "个");
        set("long", "这是一个专门用来放各种兵器的架子。
里面有：
       钢刀(dao)，        剑(sword)，
       木刀(mudao)，        令(ling)， 
	
等武器护具。\n");
        set("material","wood");
        set("no_get",1);
        }
        setup();
}
void init()
{
    add_action("do_get",({"get","na"}));
}

int do_get(string arg)
{
  object me,ob;
  string arg1,arg2;
  me=this_player();
  if(!arg || sscanf(arg, "%s from %s", arg1, arg2)!=2)
   return notify_fail("命令格式: get <兵器名称> from jia。\n");
  if (arg2!="jia")
     return notify_fail("命令格式: get <兵器名称> from jia。\n");
  if(present(arg1, me) || present(arg1, environment()))
     return notify_fail("已经有这样东西了。\n");
    switch (arg1){
          case "jian": ob=new("/clone/weapon/changjian"); break;             
          case "dao": ob=new("/clone/weapon/blade"); break;   
          case "mudao": ob=new("/clone/weapon/mudao"); break;   
          case "ling": ob=new("/clone/weapon/ling"); break;   
          default :
                 return notify_fail("没有这种兵器。\n");
          }
     if(ob) ob->move(me);
       message_vision("$N从兵器架上拿出一件$n。\n",me, ob);  
       return 1;
}

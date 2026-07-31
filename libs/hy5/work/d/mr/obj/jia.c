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
       鞭(bian)，        刀(dao)， 
       棍(gun)，         棒(bang)，
       杖(zhang)，       剑(jian)，
       斧(axe)，       匕首(dagger)， 

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
          case "dao": ob=new("/clone/weapon/gangdao"); break;   
          case "bian": ob=new("/clone/weapon/changbian"); break;         
          case "axe": ob=new("/clone/weapon/axe"); break;
          case "zhang": ob=new("/clone/weapon/gangzhang"); break;
          case "gun": ob=new("clone/weapon/qimeigun"); break;           
          case "dagger": ob=new("clone/weapon/dagger"); break;
          case "bang": ob=new("clone/weapon/zhubang"); break; 
          default :
                 return notify_fail("没有这种兵器。\n");
          }
     if(ob) ob->move(me);
       message_vision("$N从兵器架上拿出一件$n。\n",me, ob);  
       return 1;
}

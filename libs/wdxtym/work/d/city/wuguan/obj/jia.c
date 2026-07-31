
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
       杖(gangzhang)，   剑(jian)，
       锤(chui)，        令(ling)， 

等武器护具。\n
命令格式: na <兵器名称> from jia \n");
        set("material","wood");
        set("no_get",1);
        }
        setup();
}
/*
void init()
{
       add_action("do_get","na");
}

int do_get(string arg)
{
       object me,ob;
       string arg1,arg2;
       me=this_player();
       if(!arg || sscanf(arg, "%s from %s", arg1, arg2)!=2)
            return notify_fail("命令格式: na <兵器名称> from jia。\n");
       if (arg2!="jia")
            return notify_fail("命令格式: na <兵器名称> from jia。\n");
       if(me->query_temp("marks/拿"))
            return notify_fail("你已经拿过了。\n");
//     if(present(arg1, me) || present(arg1, environment()))
//          return notify_fail("已经有这样东西了。\n");
       switch (arg1){
          case "jian": ob=new("/clone/weapon/changjian"); break;             
          case "dao": ob=new("/clone/weapon/blade"); break;   
          case "bian": ob=new("/clone/weapon/whip"); break;         
          case "ling": ob=new("/clone/weapon/tieling"); break;
          case "gangzhang": ob=new("/clone/weapon/gangzhang"); break;
          case "gun": ob=new("clone/weapon/tiegun"); break;           
          case "chui": ob=new("clone/weapon/tiechui"); break;
          case "bang": ob=new("clone/weapon/zhubang"); break; 
          default :
                 return notify_fail("没有这种兵器。\n");
       }
       if(ob){
       	 ob->set("value", 10);
       	 ob->move(me);
       }
       message_vision("$N从兵器架上拿出一件$n。\n",me, ob); 
       me->set_temp("marks/拿",1);
       return 1;
}
*/
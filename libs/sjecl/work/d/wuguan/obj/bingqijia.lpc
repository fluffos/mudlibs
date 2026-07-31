//bingqijia.c 兵器架

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW "兵器架" NOR, ({ "bingqi jia", "jia" }) );         
        set_weight(30000000);
        set_max_encumbrance(25000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("unit", "个");
        set("long", "这是一个专门用来放各种兵器的架子．n");
        set("value", 1000000);
        set("material","wood");
        set("no_get",1);
        }
        setup();
}

void init()
{
        object ob;
        int i,j;
        j=3;
        for(i=0;i<j;i++) {          
                ob=new("/d/village/obj/zhujian");
                ob->move(this_object());
                ob=new("/d/city/obj/gangjian");
                ob->move(this_object());
                ob=new("/clone/weapon/changjian");
                ob->move(this_object());
        }
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
     return notify_fail("你已经拿了这样东西了。\n");
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
     if(ob) ob->move(me);
       message_vision("$N从兵器架上拿出一件$n。\n",me, ob);  
       return 1;
}

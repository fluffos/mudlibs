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
        set("long", "这是一个专门用来放兵器的架子。
里面有：\n\n"
                   HIY"金龙夺"NOR"(duo) \n\n" 
                   HIR"火云笔"NOR"(bi)
\n");
        set("material","wood");
        set("no_get",1);
        }
        setup();
}
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
  if(me->query_temp("tz_marks/拿2"))
       return notify_fail("你已经拿过了。\n");
    switch (arg1){
          case "duo":      ob=unew(__DIR__"jinlong-duo"); break;             
          case "bi":       ob=unew(__DIR__"huoyun-bi"); break;
          default :
                 return notify_fail("没有这种兵器。\n");
          }
     if(!ob)
       return notify_fail("宝物已经被人拿走了。\n");
     if(ob) ob->move(me);
       message_vision("$N从兵器架上拿出一件$n。\n",me, ob); 
       me->set_temp("tz_marks/拿2",1);
       return 1;


}


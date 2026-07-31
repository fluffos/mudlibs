inherit ITEM;
void create()
{
        set_name(HIC"英雄令"NOR, ({ "yxling","ling"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是英雄令.   
     玩家可以使用(home)指令来回到英雄街!\n
英雄令新增功能：你可以使用英雄令home回到英雄街后，look map，\n
可以看到通向各个任务区域的入口说明：\n
1.是通向襄阳城。\n2.是通向北京城。
");
             set("unit", "块");
             set("no_get", 1);
                 set("value", 100000);
        }
}
void init()
{
    if ( !this_player()->is_ghost() )
//    add_action("do_drop","drop");
  add_action("do_home","home");
}
int do_home()
{
    object me = this_player();
          if( environment(me)->query("no_home") )
               return notify_fail("这里用不了英雄令!\n");
        if (me->query_condition("ypjob") > 0) 
               return notify_fail("西夏任务时，无法使用英雄令，请在西夏任务完成后或时限过后再使用!!\n");
           if( me->query("id")=="wuwum")   
                  return notify_fail(HIY"wuwum不能乱动!!!!!!!!!!!!!!!!!!!!!!。\n"NOR); 
        if( me->query_temp("yxling")>time() )
               return notify_fail("英雄令让你这么用，迟早用出毛病来，还是等一下再用吧!!\n");
        if( me->over_encumbranced() )
                return notify_fail("你的负荷过重，动弹不得。\n");
        if( me->is_busy() )
                return notify_fail("你的动作还没有完成，不能移动。\n");
        if (me->is_fighting()) return 0;

    me->set_temp("yxling",time()+1);
   write("你从怀中拿出英雄令，口里不知念了些什么，\n
   往天上一飞,飞英雄街去了!\n");
   me->move("/u/zjb/room/yingxiong");
   return 1;
}
/*
int do_drop(string arg)
{
object me = this_player();
object obj = this_object();
        if( !arg || arg=="" ) return 0;
         if( arg=="yxling"||"ling")
        destruct(obj);
                  message("vision", "英雄令啪的一声掉地上,转眼就不见了。\n", this_player());
return 1;
}
*/


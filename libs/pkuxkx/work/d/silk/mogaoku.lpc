// /d/xingxiu/mogaoku.c
// Jay 3/17/96

#include <ansi.h>
inherit ROOM;

// can put some book about budism here.

int do_mx(string arg);
int clear_items()
{
    int i;
    object* invs = all_inventory();
    for(i=0;i<sizeof(invs);i++)
    {
        if(objectp(invs[i]) && !userp(invs[i]) && !invs[i]->is_character())
        {
            destruct(invs[i]);       
        }
    }
    remove_call_out("clear_items");
    call_out("clear_items",10);
    return 1;
}
void create()
{
        set("short", "莫高窟");
        set("long", @LONG
这里墙壁上绘制着与佛教相关的画面，有仙女飞天，还有反弹琵琶。洞中
还有很多佛像和经书。你被这些瑰丽的文化之宝惊呆了。(你可以在这里冥想
mingxiang).
LONG
        );
        set("exits", ([ 
             "north" : __DIR__"yueerquan",
]));
        set("no_clean_up", 0);
        set("no_perform",1);
        set("no_exert",1);
        set("no_fight",1);

        setup();
        call_out("clear_items",10);
//        replace_program(ROOM);
}

void init()
{
    add_action("do_mx","mingxiang");
    
}
int do_mx(string arg)
{
object me;
me=this_player();
if(arg) return 1;
if(me->query("combat_exp")<2000) 
{
write(HIW"你现在经验太低无法冥想佛家的真理!\n"NOR);
return 1;
}
if(me->is_busy()||me->is_fighting())
{
write(HIW"你现在无法冥想佛家的真理!\n"NOR);
return 1;
}
if(me->query("jingli")<10)
{
write(HIW"很明显,你现在太累了,无法冥想佛家的真理!\n"NOR);
return 1;
}
if (me->query("mogaoku/zhengguo")>5)
{
  write(HIW"你自觉已经无法百尺竿头，更进一步，不由得叹了口气。\n"NOR);
  return 1;
}
me->add("jingli",-2);
if(random(6000)!=0)
{
write(HIW"你冥想了佛家的真理,觉得颇有所获!\n"NOR);
me->start_busy(5);
if (random(5) == 0)
me->add("potential",1);
return 1;
}
else
{
switch (random(30)){
case 0:
   write(HIW"你觉得冥冥中自己的臂力有所提高!\n"NOR);
                CHANNEL_D->do_channel(this_object(), "jh", HIB"传说" + me->query("name") +HIB "在莫高窟参佛多年终成正果，提高先天臂力!", -1);
  me->add("xiantian/str/mgk",1);
me->add("str",1);
break;
case 1:
   write(HIW"你觉得冥冥中自己的根骨有所提高!\n"NOR);
                CHANNEL_D->do_channel(this_object(), "jh", HIB"传说" + me->query("name") +HIB "在莫高窟参佛多年终成正果，提高先天根骨!", -1);
  me->add("xiantian/con/mgk",1);
me->add("con",1);
break;
case 2:
   write(HIW"你觉得冥冥中自己的悟性有所提高!\n"NOR);
                CHANNEL_D->do_channel(this_object(), "jh", HIB"传说" + me->query("name") +HIB "在莫高窟参佛多年终成正果，提高先天悟性!", -1);
  me->add("xiantian/int/mgk",1);
me->add("int",1);
break;
case 3:
   write(HIW"你觉得冥冥中自己的身法有所提高!\n"NOR);
                CHANNEL_D->do_channel(this_object(), "jh", HIB"传说" + me->query("name") +HIB "在莫高窟参佛多年终成正果，提高先天身法!", -1);
  me->add("xiantian/dex/mgk",1);
me->add("dex",1);
break;
case 4:
   write(HIW"你觉得冥冥中自己的福缘有所提高!\n"NOR);
                 CHANNEL_D->do_channel(this_object(), "jh", HIB"传说" + me->query("name") +HIB "在莫高窟参佛多年终成正果，提高福缘!", -1);
  me->add("xiantian/kar/mgk",1);
me->add("kar",1);
break;
default :
   write(HIW"你觉得冥冥中自己的灵性有所提高!\n"NOR);
//                message( "channel:" + "chat",HIW + "【仙界谣传】"+HIB"传说" + me->query("name") +HIB "在莫高窟参佛多年终成正果，提高灵性!\n"NOR,users());
  me->add("xiantian/spi/mgk",1);
me->add("spi",1);
break;
}
  me->add("mogaoku/zhengguo",1);
return 1;
}
}

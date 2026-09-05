// /d/xingxiu/mogaoku.c
// Jay 3/17/96

#include <ansi.h>
inherit ROOM;

// can put some book about budism here.

int do_mx(string arg);
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

        setup();
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
me->add("jingli",-2);
if(random(600)>=30)
{
write(HIW"你冥想了佛家的真理,觉得颇有所获!\n"NOR);
me->start_busy(10);
me->add("potential",1);
me->add("combat_exp",random(2)+1);
return 1;
}
else
{
switch (random(8)){
case 0:
   write(HIW"你觉得冥冥中自己的臂力有所提高!\n"NOR);
                message( "channel:" + "chat",HIW + "【仙界谣传】"+HIB"传说" + me->query("name") +HIB "在莫高窟参佛多年终成正果，提高先天臂力!\n"NOR,users());
me->add("str",1);
break;
case 1:
   write(HIW"你觉得冥冥中自己的根骨有所提高!\n"NOR);
                message( "channel:" + "chat",HIW + "【仙界谣传】"+HIB"传说" + me->query("name") +HIB "在莫高窟参佛多年终成正果，提高先天根骨!\n"NOR,users());
me->add("con",1);
break;
case 2:
   write(HIW"你觉得冥冥中自己的悟性有所提高!\n"NOR);
                message( "channel:" + "chat",HIW + "【仙界谣传】"+HIB"传说" + me->query("name") +HIB "在莫高窟参佛多年终成正果，提高先天悟性!\n"NOR,users());
me->add("int",1);
break;
case 3:
   write(HIW"你觉得冥冥中自己的身法有所提高!\n"NOR);
                message( "channel:" + "chat",HIW + "【仙界谣传】"+HIB"传说" + me->query("name") +HIB "在莫高窟参佛多年终成正果，提高先天身法!\n"NOR,users());
me->add("dex",1);
break;
case 4:
   write(HIW"你觉得冥冥中自己的福缘有所提高!\n"NOR);
                message( "channel:" + "chat",HIW + "【仙界谣传】"+HIB"传说" + me->query("name") +HIB "在莫高窟参佛多年终成正果，提高福缘!\n"NOR,users());
me->add("kar",1);
break;
default :
   write(HIW"你觉得冥冥中自己的灵性有所提高!\n"NOR);
                message( "channel:" + "chat",HIW + "【仙界谣传】"+HIB"传说" + me->query("name") +HIB "在莫高窟参佛多年终成正果，提高灵性!\n"NOR,users());
me->add("spi",1);
break;
}
return 1;
}
}

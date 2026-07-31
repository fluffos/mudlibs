// lang5.c 长廊
// By River 99/05/20
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIY"西厢长廊"NOR);
        set("long",@LONG
转过几个弯后，已到西厢长廊的尽头。相对廊子的细窄而言，尽头的大水
池令人顿觉豁然开朗，池子极大，周围圈以古色古香的砖瓦，再配以飘逸的柳
条，有种仙境的意味。池中豢养的鱼儿浑身金灿灿的，活跃非常。池子的北面
是剑室，南面是芝房，散发出一股泥土的清香。
LONG
    );

        set("exits",([
           "north": __DIR__"jianshi",
           "south": __DIR__"zhifang",
           "east": __DIR__"lang4",
        ]));
        setup();
}

void init()
{
        object me = this_player();
        if(me->query_temp("jqg/enter")){
          me->delete_temp("jqg/enter");
          }
}

int valid_leave(object me, string dir)
{
        if ( !me->query_temp("gsz_agree")
           && dir !="east")
	return notify_fail("这里是绝情谷的禁地，没有庄主的命令，外派弟子不能进入！！\n");
        return ::valid_leave(me, dir); 
}

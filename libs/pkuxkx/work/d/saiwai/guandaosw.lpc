//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "官道");
        set("long", @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。路上行人纷纷，部分
行人还别有刀剑，显然是江湖人士，看起来还是少惹为妙！西南面一座雄关
直耸云霄。
LONG
        );

        set("exits", ([
               "north" : __DIR__"guandaow2",
               "northeast" : __DIR__"guandaosa",
               "southwest" : "/d/jinyang/yanmenguan",

        ]));
        set("objects", ([
		"/d/jinyang/yanmenguan/npc/guanyuan" : 1,
        ]));
        set("outdoors", "saiwai");
        setup();
        
}

void init()
{
    add_action("do_se","southeast");
}

int do_se()
{
    object me=this_player();
    object ob=this_object();
    object room=load_object("/d/jinyang/yanmenguan/guandao");
    object center=load_object("/d/jinyang/yanmenguan/center");
    if (!me->query_temp("yanmen/permit"))
    {
        return 0;
    }
    if (!center->query("is_on"))
    {
        return 0;
    }
    if (center->query("yanmen/already_start"))
    {
        tell_object(me,"萧远山大人已经动身了，估计是追不上他了。\n");
        return 1;
    }
    message_vision("$N深吸一口气，向东南方向离去。\n",me);
    tell_room(room,me->query("name")+"从西北方向的官道走了过来。\n");
    me->move(room);
    return 1;
}
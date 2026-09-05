// room: /d/xingxiu/saimachang.c
// Jay 3/17/96
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "赛马场");
        set("long", @LONG
这里是小镇的赛马场。场上正在举行一年一度的赛马表演。一个维吾尔族
避祸迁居于此的姑娘正站在场边。
LONG
        );
        set("exits", ([ 
             "southeast" : __DIR__"beijiang",]));
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        set("objects", ([
                __DIR__"npc/alamuhan" : 1  ]) );

        setup();
       
}

void init()
{
    add_action("do_zuan","zuan");
}

int do_zuan()
{
    object room,me=this_player();
    if (me->query("family/family_name")!="星宿派")
    {
        return 0;
    }
    else
    {
        room=load_object(__DIR__"midao2");
        if (room)
        {
            me->move(room);
            tell_room(this_object(),"众人觉得眼前一花，"+me->query("name")+"就不见了。\n",me);
            tell_object(me,"你钻进了星宿派秘道入口。\n");
        }
        return 1;
    }
}


//shulin.c树林
//diabio(青云)2001.3.30

#include <ansi.h>
#include <room.h>
#include <command.h>
inherit ROOM;
int consider_lv(object ob,int a);

void create ()
{
        set ("short", "树林");
        set ("long", @LONG
这是一片树林，林子很密，只有这一条小路穿林而过，一些阳光透
过密林射在地上，到了晚上这里基本是伸手不见五指的。在前面隐约
可以看见一个小房间。
LONG);
        set("exits", ([
             "east"  : __DIR__"pubu",
             "west"  : __DIR__"shulin"+(1+random(4)),
             "south" : __DIR__"shulin"+(1+random(4)),
             "north" : __DIR__"shulin"+(1+random(4)),               
        ]));


        set("outdoors", "feitian");
        setup();
}




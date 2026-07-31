//caodi.c 草地 

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIG"草地"NOR);
        set("long", @LONG
一片绿幽幽的草坪，不由的想起了，修带不为歌舞缓，浓铺堪作醉人茵，
无意衬香衾。晴霁后，颜色一般新，游子不归生满地，佳人远意正青春，留咏
卒难伸。
LONG
        );
        set("objects",([
             __DIR__"npc/npc"+random(15) : 1,
        ]));

        set("exits", ([
        "west" : __DIR__"huilang5",
        "southeast" : __DIR__"quqiao4",
        "northeast" : __DIR__"zoulang2",
        "east" : __DIR__"zhongting",
        ]));
        
        set("no_death",1);set("bwdhpk",1);
        set("outdoors", "试剑山庄");

        setup();
}


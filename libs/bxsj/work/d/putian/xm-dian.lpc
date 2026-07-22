// Room: /d/putian/xm-dian.c 须弥殿
// lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "须弥殿");
        set("long", @LONG
这里是须弥殿，这一殿也是烛火明亮，殿堂却较前面三殿小得多。殿中放
了两个蒲团，蒲团旁边有几张桌子，还有几把椅子，墙上有几张画像，都是佛
经典故。
LONG
        );

        set("exits", ([
                "north" : __DIR__"houdian",
                "south" : __DIR__"jcyuan",

        ]));
        set("objects",([
		__DIR__"npc/shami" : 2,
        ]));

        setup();
}

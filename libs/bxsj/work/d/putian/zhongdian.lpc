// Room: /d/putian/zhongdian.c 中殿
// lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"中殿"NOR);
        set("long", @LONG
这是寺中的中殿，殿中面积不是很大，但是感觉好象很宽阔，地上铺了一
层青色的方砖，两旁立着些佛像。平常这里不会有外人进来，游客只能走到前
殿的门口，后面一般是进不来的。
LONG
        );

        set("exits", ([
                "north" : __DIR__"qiandian",
                "south" : __DIR__"houdian",

        ]));
        set("objects",([
		__DIR__"npc/shami" : 1,
        ]));

        setup();
}

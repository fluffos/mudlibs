#include <ansi.h>
inherit ROOM;
void create()
{set("short", HIC"太湖阁"NOR);
set("long", @LONG
太湖阁是一个木制红漆游船,它就泊在太湖桥旁边。
太湖终年不断的水气把它笼罩得迷迷蒙蒙的。
里面不时传来一阵阵欢笑声和花拳声，还有卖艺女的歌声。
LONG);

	set("exits", ([
                "south" : __DIR__"bridge2",
		"up": __DIR__"geup",
                ]));
	set("outdoors", "guiyunzhuang");
        set("objects", ([
            __DIR__"npc/xiaoer" : 1,
	]));
	setup();
}

void init()
{

}

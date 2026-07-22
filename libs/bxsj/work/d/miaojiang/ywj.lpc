// /u/dubei/miaojiang

#include <ansi.h>
inherit ROOM;

void create()
{
       set("short",HIY "药王居" NOR);
        set("long", @LONG
这里是一间简朴的竹斋，四周全是一排排药柜。靠里的桌子上面放着几本
医典。一位少女坐在后面观看着书籍，旁边站着一个小丫鬟。屋里有一股淡淡
的草药芬芳。
LONG
        );
        set("no_fight",1);
	set("no_sleep_room",1);
        set("exits", ([
                "north" : __DIR__"yaofang1",
                "northwest" : __DIR__"jiedao2",
                   
        ]));
        set("objects",([
                __DIR__"npc/chenglingsu" : 1,
                __DIR__"npc/yahuan" : 1,

        ]));

       

        setup();

}

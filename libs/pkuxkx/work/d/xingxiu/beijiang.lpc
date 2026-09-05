// /d/xingxiu/beijiang.c
// Jay 3/17/96

inherit ROOM;
#include "/d/parties/public/entry.h"
void create()
{
        set("short", "回族小镇");
        set("long", @LONG
这里是一座回族为主多族杂居的小镇。小镇上人来人往，十分热闹。只是很
多人说的话你听不懂。镇西有家小店铺，西北方向人声鼎沸，好像在举行什么比
赛，东北面新开了一家车马行，东面有家院落，院门口有棵大树。
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"store",
        "east" : __DIR__"house",
        "northwest" : __DIR__"saimachang",
        "southeast" : __DIR__"shanjiao",
	"northup":"/d/lingjiu/shanxiaxiaolu1",
	"northeast" : __DIR__"machehang",
]));
        set("objects", ([
                __DIR__"npc/woman": 2 ]) );
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        set("self_build_entry",1);
        set("self_dir","southwest");
        setup();
}



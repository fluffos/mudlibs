//shufang.c
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "书房");
        set("long", @LONG
这里是老馆主的书房，但馆主已经很久没来这里了。到是五弟子卜垣经常
来这里，顺便指导一些喜欢读书的小孩们。书房周围的书架上整整齐齐地堆放
着很多书籍。正对大门的那边墙上写了几个醒目的大字（dazi）。
LONG
        );
        set("item_desc", ([
		"dazi" : "
    ※※※※※※※※※※※※※※※※※※※
    ※※※※　　　　　　　　　　　※※※※
    ※※※※　                    ※※※※
    ※※※※ 　 　少壮不努力，　　※※※※
    ※※※※　                    ※※※※
    ※※※※　　　　　　　　　　  ※※※※
    ※※※※　                    ※※※※
    ※※※※ 　 　老大徒悲伤。  　※※※※
    ※※※※　                    ※※※※
    ※※※※　　　　　　　　　　　※※※※
    ※※※※※※※※※※※※※※※※※※※\n" ,
 
	]));

        set("exits", ([
                "south" : __DIR__"zoulang6",
        ]));
	set("no_fight",1);
        set("objects", ([
                __DIR__"npc/dizi5" : 1,
        ]) );
        
        setup();

}

int valid_leave(object me, string dir)
{
        me->set_temp("mark/literate", 0);
        return 1;
}

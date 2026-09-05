//绝情谷
// By Zine 

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"绝情谷前"NOR);
        set("long", 
"前方是一座美丽的山谷，西面的小路分岔极多，让人眼花缭乱。\n"

        );
        
        set("exits", ([
                "northwest" : __DIR__"xiaolu2",
                "southwest" : __DIR__"xiaolu2",
                "west" : __DIR__"xiaolu2",
                "east" : __DIR__"caodi",
                //"southwest" : __DIR__"citywall2",
                //"northeast" : "xiaolu2",
                
        ]));
        set("objects", ([
        __DIR__"npc/shougu-dizi" : 2,
        ]));
        set("outdoors", "jueqinggu");
        setup();
   
}

void init()
{
	object me=this_player();
	add_action("do_querypath","querypath");
}
int do_querypath()
{
	object me=this_player();
	mapping legal_dir=(["qian":"前","hou":"后","zuo":"左","you":"右"]);
	if (!me->query("jueqinggu/maze")||!arrayp(me->query("jueqinggu/maze"))) return 0;
	tell_object(me,"你刻上的路线是：\n");
	for (int i=0;i<sizeof(me->query("jueqinggu/maze"));i++)
		tell_object(me,legal_dir[me->query("jueqinggu/maze")[i]]+" ");
	tell_object(me,"\n");
	return 1;
}

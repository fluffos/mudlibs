inherit ROOM;
#include <ansi.h>
void DestGenNpc()
{
	object *pu,puren;
	pu=children(__DIR__"npc/yahuan2");
	if (sizeof(pu)>=1)
	for (int i=0;i<sizeof(pu);i++)
	destruct(pu[i]);
	puren=new(__DIR__"npc/yahuan2");
	puren->move(this_object());
	puren->random_move();
	puren->random_move();
	
}
void create()
{
        set("short", HIW"后厅"NOR);
        set("long", 
"这里是都统制府的后厅，家眷住在左右的厢房里。\n"

        );
        set("exits", ([
                
                "east" : __DIR__"youxiang",
                "south" : __DIR__"lianwu",
                "west" : __DIR__"zuoxiang",
                "north" : __DIR__"houyuan",
                
        ]));
        set("objects", ([
		__DIR__"npc/dayahuan" : 1,
        //"/d/city/npc/bing" : 1,
        
        ]));
        //set("outdoors", "yingtianfu");
        setup();
		DestGenNpc();
}
int valid_leave(object me,string dir)
{
	if (dir=="south"&&!userp(me)&&me->query("is_yahuan"))
	return notify_fail(".");
	return ::valid_leave(me,dir);
}

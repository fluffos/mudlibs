inherit ROOM;
#include <ansi.h>
void DestGenNpc()
{
	object *pu,puren;
	pu=children(__DIR__"npc/puren");
	if (sizeof(pu)>=1)
	for (int i=0;i<sizeof(pu);i++)
	destruct(pu[i]);
	for (int j=0;j<3;j++)
	{
		if (random(2))
		{
			puren=new(__DIR__"npc/puren");
			puren->move(this_object());
			puren->random_move();
			puren->random_move();
		}
	}
}
void create()
{
        set("short", "前厅");
        set("long", 
"这里是建康都府的前厅，一些低级官员正在等候拜见。\n"

        );
        set("exits", ([
                
                "north" : __DIR__"huilang1",
                "west" : __DIR__"puren",
                "east" : __DIR__"shiwei1",
                "south" : __DIR__"damen",
                
        ]));
        set("objects", ([
		//"/d/yingtiannorth/npc/wujiang" : 1,
        //"/d/city/npc/bing" : 1,
        
        ]));
       // set("outdoors", "yingtianfu");
        setup();
		DestGenNpc();
   
}
int valid_leave(object me,string dir)
{
	if (dir=="south"&&!userp(me)&&me->query("is_puren"))
	return notify_fail(".");
	return ::valid_leave(me,dir);
}

//xiaolu1.c  

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "林间小径");
        set("long", @LONG
你走在一条小径上，两旁种满了竹子，修篁森森，绿荫满地，除了竹叶
声和鸟鸣声，听不到别的动静。
LONG
        );

        set("exits", ([
                "north" : __DIR__"xiaolu2",
                "south" : __DIR__"houyuan",
                "west" : __DIR__"xiaolu3",
        ]));

	set("outdoors", "quanzhen");
	set("objects", ([
"/d/quanzhen/npc/liuchuxuan" : 1]));

        setup();
        
}
/*
int valid_leave(object me, string dir)
{
	mapping fam;

	if (dir == "north")
	{
		if( mapp(fam = me->query("family")) 
		&&  fam["family_name"] == "全真教" 
		&&  fam["generation"] == 2  ) 
			return ::valid_leave(me, dir);
		
		
		if( me->query("guilty") == 0 
		&&  !wizardp(me) )
		{
			return notify_fail("刘处玄说道：“后山禁地，还在建设之中，闲杂人等不得入内，尔等速速离去。”\n");
		}
	}

	return ::valid_leave(me, dir);
}
*/



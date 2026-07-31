inherit ROOM;
 
void create()
{
        set("short", "洞口");
        set("long",@LONG
这是一条后山上的一个小山洞。洞口很小，但能容一个人钻进去。里面
黑黝黝的什么也看不见。
LONG);
        set("exits", ([
            "east"   : __DIR__"bagua1",
            "west"   : __DIR__"road4",
            "south"   : __DIR__"bagua0",
            "north"   : __DIR__"bagua0",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "taohua");
        setup();
//        replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
	if (dir =="east" ||dir =="south"||dir =="north")
	{
	
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你想进去拐卖人口？\n");
       		
		}
		
	}

	return ::valid_leave(me, dir);
}
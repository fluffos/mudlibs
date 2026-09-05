inherit ROOM;

void create()
{
	set("short","小山村");
	set("long","一个普通的小山村，村里有百来户人家。奇怪的是，旁边的匪帮从来不曾来骚扰这里。\r\n");
	set("exits", ([ 
         "north" : __DIR__"east1",
      ]));
	set("objects", ([
		__DIR__"npc/butou" : 1,
	]));
	
	setup();	
}

int valid_leave(object me, string dir)
{	
	if(dir != "north") return ::valid_leave(me, dir);
//	if(JIAOFEI_D->istaskstart())		
//	{
//		return notify_fail("一名士兵对你大喊:官府正在剿匪，闲杂人等不得靠近！\r\n");	
//	}

	return ::valid_leave(me, dir);
}

int isstartroom()
{
    return 1;
}
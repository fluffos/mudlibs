inherit ROOM;

void create()
{
	set("short", "内城城门");
	set("long", @LONG
此间是贵阳城内城的城门，贵阳为贵州重镇。内城城墙由石块和土
垒成，高丈五，厚达丈余。城下三两个盔甲鲜明的军士，向南就是贵阳
的内城了。
LONG );

	set("exits", ([
                          "north"      : __DIR__"center",
                         "south"      : __DIR__"ncenter",
                         
		
	]));
    set("objects",([
     __DIR__"npc/bing":2,
 __DIR__"npc/wujiang":2,
     
     ]));

 	set("outdoors", "guizhou");
	setup();
	replace_program(ROOM);
}




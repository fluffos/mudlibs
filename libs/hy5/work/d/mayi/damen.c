// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "大门");
	set("long", @LONG
这里一个大宅院，不知道里面住的是什么人。平时这个大门总是关
着的，也不见有什么人从里面出入。
LONG
	);
set("outdoors", "mayi");
set("exits", ([
                "south": __DIR__"xijie", 
         ]));
       setup();
	replace_program(ROOM);
}	

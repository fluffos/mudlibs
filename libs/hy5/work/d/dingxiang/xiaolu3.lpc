// /d/yazhang/xiaolu3.c
// Room in 牙帐
// modify by yang

inherit ROOM;

void create()
{
	set("short", "草原小路");
	set("long", @LONG
这里是一条去大草原的必经之路，小路两旁杂草众多，路上行人也
很少。南面就是一望无际的大草原了。
LONG 
        );
	set("exits", ([
		"northwest" : __DIR__"xiaolu2-3",
		"south" : "/d/suiye/caoyuan",
	]));
	
	
 	set("outdoors", "yazhang");
	setup();
	replace_program(ROOM);
}


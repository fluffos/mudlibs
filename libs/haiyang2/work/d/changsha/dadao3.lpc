// /d/zhuojun/dadao3.c
// Room in 涿郡
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "湘江山路");
	set("long", @LONG
你走在一条青石大道上，边上是滚滚的湘江,此处人
群稀少，四周也静悄悄的。
LONG
        );
set("outdoors", "changsha");
set("exits", ([
                "northwest":"/d/yueyang/nanmen",  
                "southwest":__DIR__"dadao2",    
	]));
       setup();
	replace_program(ROOM);
}

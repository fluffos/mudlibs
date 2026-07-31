// 雪路2
// by steel 

inherit ROOM;

void create()
{
	set("short", "雪原");
	set("long", @LONG
	这里是北方的一片雪原,积雪终年不化,放眼望去,白茫茫的一片,
一个人影也看不到.    
LONG
	);
	
	set("exits", ([
		"south" : __DIR__"road1",
		"west" :__DIR__"road3",
                "north" :__DIR__"road4",
                "northwest" :__DIR__"road5", 
               ]));
	setup();
	replace_program(ROOM);
}


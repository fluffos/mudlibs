// little hotel
// by steel 

inherit ROOM;

void create()
{
	set("short", "雪原小店");
	set("long", @LONG
        这是一家很小的酒店,但生意还不错,在风雪中奔波的人到了
这里,都要停下来喝一杯北方的烈酒,暖一暖身子。	   
LONG
	);
    set("exits", ([
		"east" : __DIR__"road3",
			]));
    set("objects",([
          __DIR__"npc/xiaoer":1,
    ]) ); 
	setup();
	replace_program(ROOM);
}


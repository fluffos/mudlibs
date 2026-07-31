//山洞
// by steel 

inherit ROOM;

void create()
{
	set("short", "雪洞");
	set("long", @LONG
	这是雪山中的一个洞,洞内风雪虽然小了点,但是奇寒无比,看来没
有什么生命可以在这里生存.  
LONG
	);
	
	set("exits", ([
                "southwest" : __DIR__"hole8",
                "northwest":__DIR__"hole"+(random(10)+1),
                "west":__DIR__"hole"+(random(10)+1),
                "northeast":__DIR__"hole"+(random(10)+1),
                "north":__DIR__"hole10",     
          ]));
	setup();
	replace_program(ROOM);
}

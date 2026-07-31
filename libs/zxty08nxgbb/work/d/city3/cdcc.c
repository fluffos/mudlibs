 
inherit ROOM;

void create()
{
        set("short", "驿站");
	set("long", @LONG
这是城里唯一一家驿站。因从未丢失过任何信件和货物而且传
递及时，这里的声誉一直很好。
LONG
	);

	set("exits", ([
                "southwest" : __DIR__"cdta",
	]));

	setup();
	replace_program(ROOM);
}


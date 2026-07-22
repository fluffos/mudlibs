// songlin1.c 松林

inherit ROOM;

void create()
{
	set("short", "松林");
	set("long", @LONG
茂密的松林，不时能见到几只松鼠在树上跳来跳去。虽然只有几
丝阳光能透林而入，却不显得阴森可怖。习习凉风不时迎面吹来，
使人浑身舒畅。使你想躺在这里，睡上一觉。
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"east" : __DIR__"songlin1",
		"west" : __DIR__"songlin2",
                "north" : __DIR__"songlin2",
                "south" : __DIR__"songlin1",
        ]));
	setup();
	replace_program(ROOM);
}

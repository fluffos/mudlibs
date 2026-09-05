
inherit ROOM;

void create()
{
	set("short", "平原");
	set("long", @LONG
但见一大片平原。沿途所见，除了低丘高树之外，尽是青草奇花。
草丛之中，偶而惊起一些叫不出名目的大鸟小兽，看来也皆无害于人。
LONG
	);

	set("exits", ([
                 "east" : __DIR__"pyuan4",
		"south" : __DIR__"xiongdong",
                 "west" : __DIR__"haitan",
                "north" : __DIR__"pyuan2",
	]));
	set("objects",([
          __DIR__"npc/lu" : 2,
    ]));
	set("outdoors", "bhdao");
	setup();
	replace_program(ROOM);
}



// Room: /d/linzhi/by10.c

inherit ROOM;

void create()
{
	set("short", "沟谷丛林南");
	set("long", @LONG
你来到易贡河谷内的丛林区，这里冬无严寒夏无酷暑，气候
十分宜人。过了这片丛林就到易贡湖了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"by09",
  "north" : __DIR__"by11",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 2100);
	setup();
	replace_program(ROOM);
}

//ROOM damen.c

inherit ROOM;

void create()
{
	set("short", "庙门");
	set("long",@LONG
这里是卧云庵的大门。一条青砖大道直通门口，在路的四周种满了各种
青竹，走到门前，看见在门楣上挂了一块匾，上书三个大字「卧云庵」。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "east" : __DIR__"jinding",
                "south" : __DIR__"guangchang",
	]));

	set("objects",([
	]));
	setup();
}

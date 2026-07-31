//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "林中山涧");
	set("long", @LONG
密林深处豁然开朗，一道激流从上上飞溅下来，山涧并不宽，更
谈不上深，行人尽可徒步通过。涧水清凉干净，路人往往停下来用竹
筒装水解渴。四面皆是青竹林，竹叶随山风沙沙作响。有些摆夷村民
不远数里上山来采新鲜竹笋为食。
LONG
        );

	set("exits", ([
		"northdown" : __DIR__"minov26",
		"southdown" : __DIR__"minov28",
		]));

	set("objects", ([
		__DIR__"npc/byshanren.c" : 1,
		]));

	set("resource/water",1);
	set("outdoors","dali");
	set("cost", 5);
	setup();
}

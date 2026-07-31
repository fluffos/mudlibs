//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "民居");
	set("long", @LONG
这是一座用木柴及兽皮搭成的乌夷民居。此地的村民主要从事耕
作，由于实行换季轮耕，不得不经常迁徙，因而房舍都颇简陋，说是
房舍，倒不如说更象帐篷，拆、建都甚方便。
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov46",
		]));

	set("objects", ([
		__DIR__"npc/wykid.c" : 1,
		]));

	set("cost", 2);
	setup();
}

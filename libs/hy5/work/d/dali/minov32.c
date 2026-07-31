//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "养蚕房");
	set("long", @LONG
这是一间摆夷族的杆栏民居，此间下层却没有牛羊，三面用竹席
围住，似一个棚屋，中置数座竹架竹盘，饲养着一些桑蚕。一位摆夷
姑娘正在用新鲜的桑叶喂养桑蚕。
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov31",
		]));

	set("objects", ([
		__DIR__"npc/bycannv" : 1,
		]));

	set("cost", 2);
	setup();
}

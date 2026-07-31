//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "杆栏");
	set("long", @LONG
一间摆夷族的杆栏民居，此间下层没有牛羊，却用竹席围成一个养
桑蚕的小棚屋，有竹架竹盘。楼上传来阵阵纺纱机的梭飞声。
LONG
        );

	set("exits", ([
		"east" : __DIR__"minov33",
		"up" : __DIR__"minov35",
		]));

	set("objects", ([
		__DIR__"npc/bycannv" : 1,
		]));

	set("cost", 2);
	setup();
}

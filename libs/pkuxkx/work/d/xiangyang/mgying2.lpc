inherit ROOM;
void create()
{
	set("short", "蒙古营门");
	set("long", @LONG
 这里是蒙古大军的军营,一队蒙古军兵正在操练，他们个个，训练有素，骁勇善战，
 怪不得蒙古大军能够攻无不克战无不胜。前面有一座大帐，镀金帐顶十分华贵。
LONG
	);

	set("exits", ([
		"south" : __DIR__"mgying1",
		"north" : __DIR__"jinzhang",          
	]));

	set("objects", ([
		__DIR__"npc/mgjiang2" : 2,
	        __DIR__"npc/mgjun" : 4,
        ]));

	setup();
}


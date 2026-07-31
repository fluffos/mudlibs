//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "河西镇");
	set("long", @LONG
此镇正处妃丽湖南，住的是阿藜蛮的休猎部。阿藜蛮属台夷，村
民除了耕种沿湖的田地外，主要以捕鱼为生。临湖风光格外秀丽，北
边不远就是渔船出入的小码头。南边山中有不少野兽，休猎部的男子
经常前去狩猎。
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov73",
		"south" : __DIR__"minov74",
		"west" : __DIR__"minov75",
		"northeast" : __DIR__"minov65",
		]));

	set("objects", ([
		__DIR__"npc/tyshang" : 1,
	]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}

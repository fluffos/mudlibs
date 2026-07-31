//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "高黎山东坡");
	set("long", @LONG
这里是高黎山的东坡，向东俯视奔淌而过的东泸水，远远眺望跨
谷相对的碧罗雪山。此去再向西全是崇山峻岭，人烟稀少。山间林深
兽多，乌夷族的猎人经常进山打猎。
LONG
        );

	set("exits", ([
		"eastdown" : __DIR__"minov45",
		"west" : __DIR__"minov56",
		]));

	set("objects", ([
		__DIR__"npc/goat.c" : 1
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}

//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "武定镇");
	set("long", @LONG
这里是台夷分支卢鹿族罗蝥部的治府，罗蝥部除了这武定州外还
辖元谋、禄定两镇。此镇不大，正处山中竹林深处，显得格外清幽。
卢鹿族人的竹楼四散分布在竹林中。
LONG
        );

	set("exits", ([
		"northeast" : __DIR__"minov66",
		"north" : __DIR__"minov68",
		"south" : __DIR__"minov70",
		"west" : __DIR__"minov77",
		]));

	set("objects", ([
		__DIR__"npc/tygirl" : 1,
	]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}

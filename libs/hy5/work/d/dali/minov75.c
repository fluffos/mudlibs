//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "渔家");
	set("long", @LONG
休猎部专事渔猎，很少蓄养牲畜或耕作。这是一座普通的竹楼，
下层通常的牲畜圈是修补竹筏渔网的工棚，一位台夷妇女正在细心地
"编织渔网。楼边有一排木架，挂满开过膛的鱼，正在凉晒鱼干。
LONG
        );

	set("exits", ([
		"east" : __DIR__"minov72",
		]));

	set("objects", ([
		__DIR__"npc/tywoman" : 1,
	]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}

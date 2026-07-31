//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "大竹楼");
	set("long", @LONG
这是一座普通样式的台夷竹楼，建在鲁望镇中心，与四周其它竹
楼比占地广大得多，也特别高大，似有三层，正是普麽部的祭祀大屋。
此处下层也不养牲畜，打扫得干干净净。宽大的竹梯直通上层
LONG
        );

	set("exits", ([
		"south" : __DIR__"minov76",
		"up" : __DIR__"minov29",
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}

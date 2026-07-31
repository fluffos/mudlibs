// By River@SJ

inherit ROOM;

void create()
{
        set("short", "大道");
        set("long", @LONG
这里是通往西域的丝绸古路，繁华的城镇在身后慢慢消逝，迎面而来的是
阵阵风浪。不时有一队队商人丛你身边擦身而过。北边就接近了兰州城，往东
南方向是去青城的道路。
LONG);
	set("outdoors", "兰州");

	set("exits", ([
		"southeast" : "/d/group/entry/lzsroad3",
		"north" : __DIR__"sroad1",
	]));

	set("objects",([
		__DIR__"npc/keshang" : 1,
	]));
        
	setup();
}

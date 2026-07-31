// Room: /d/shaolin/dxbdian.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "正殿");
	set("long", @LONG
这里是少林寺的大雄宝殿。正中供奉着如来三宝，左右各是
文殊、普贤菩萨。一群青衣小和尚们正在佛像前的地上诵经。
缕缕香烟与梵唱交错在一起，仰视佛祖拈花浅笑的面容，令人顿
时生起几分脱俗之感。身边经常有一队队僧人鱼贯而入，看他们
手持戒刀，似乎是巡寺的僧人。
LONG );
	set("exits", ([
		"south" : "/d/shaolin/dxbdian",
	]));
	set("objects",([
		__DIR__"npc/yu" : 1,
		__DIR__"npc/chongxu" : 1,
		__DIR__"npc/fangzheng" : 1,
		__DIR__"npc/renwoxing" : 1,
		__DIR__"npc/xiang" : 1,
	]));
	setup();
}

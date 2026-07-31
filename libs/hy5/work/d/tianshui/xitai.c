// Room: /u/xiaozhen/xitai.c

inherit ROOM;

void create()
{
	set("short", "戏台");
	set("long", @LONG
这里是小镇戏台，今天正好有一队流动演出的戏子来到天水
镇在这里演出，台下坐满了来看戏的镇民。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"sroad1",
  "west" : __DIR__"houtai",
  "westup" : __DIR__"taishang",
]));
	set("objects",([
	__DIR__"npc/guanzhong" : 2,
	__DIR__"npc/xiaofan" :1,
]));
	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me,string dir)
{
	if(dir == "westup" || dir == "wu")
		return notify_fail("“不许上台捣乱！！”观众们一拥而上把你从台上揪了下来。\n");
	return ::valid_leave();
}
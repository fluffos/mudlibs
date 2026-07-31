// Room: /open/dt/xunpufang.c

inherit ROOM;

void create()
{
	set("short", "巡捕房");
	set("long", @LONG
由于大同人尚武之风甚重，所以巡捕们的差事总也做不完，每
天都要抓一帮在街头打架的少年回来，但这帮少年也不是随便打人，
按他们的说法只是在切蹉武艺而已，巡捕们对这帮爱闹事的年轻人
也头疼得紧，抓吧，他们却实没有搔扰过一般商客，不抓吧，他们
成天在街头舞拳弄脚也实在不像话。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"tanhuanglu2",
]));

	setup();
	replace_program(ROOM);
}

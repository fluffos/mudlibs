
inherit ROOM;

void create()
{
	set("short", "蓬莱");
	set("long", @LONG
你已经到了蓬莱岛，传说中的海上仙山。你的正面就是大海，放眼望去，天水
一色，让你心旷神怡。如果你运气足够好，说不定你可以看到海市蜃楼。你的
左边有一艘看起来饱经风雨的古战船，右边是一个仙人洞，仙人早已仙去，
现在只有一个鱼妇在那里卖一些海贝。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" : "/d/road/rjntopl2",
]));

	setup();
	replace_program(ROOM);
}

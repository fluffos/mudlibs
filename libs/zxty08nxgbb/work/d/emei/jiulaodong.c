// Room: /d/emei/jiulaodong.c 峨嵋派 九老洞

inherit ROOM;

void create()
{
	set("short", "九老洞");
	set("long", @LONG
这里是一个洞口十分窄小的石洞。侧身前行，回身向洞口望去，只见
对面一条飞瀑从悬崖下飞流直下。走进洞里面却豁然开朗，里面摆设了一
些圆形的石桌、石椅。此洞冬暖夏凉，寒暑不侵，实是一个静修的好去处。
LONG
	);
	set("exits", ([
                "out": __DIR__"jiudaoguai4",
                "east": __DIR__"lianhuashi",
	]));

	set("objects",([
	        "/d/emei/npc/little_monkey": 1,
                "/d/emei/npc/monkey" : 1,
        ]));
	setup();
}

// Room: huilang7.c

inherit ROOM;

void create()
{
	set("short", "遮雨廊");
	set("long", @LONG
一道不算太宽的长廊，通向几座主要的大殿，廊顶和廊柱上满布壁画，描写
了历史人物事迹和佛教故事，色彩艳丽，形象逼真。
LONG
	);

	set("exits", ([
		"eastup" : __DIR__"zhudubadian",
                "west" : __DIR__"yushengdian",
                "south" : __DIR__"huilang5",
	]));
        set("outdoors", "雪山");
        set("objects", ([CLASS_D("xueshan") + "/hubayin" : 1,]));
	setup();
}
int valid_leave(object me, string dir)
{
        if ((string)me->query("family/family_name") != "大轮寺" 
           && dir == "west"  
           && present("hu bayin", environment(me)))
	return notify_fail(
"呼巴音手一伸，道：“这位施主，此处只有吐蕃王族才可以进去，请去别处随喜吧。\n");

	return ::valid_leave(me, dir);
}

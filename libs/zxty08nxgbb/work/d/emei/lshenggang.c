// Room: /d/emei/lshenggang.c 龙升坪

inherit ROOM;

void create()
{
        set("short", "龙升坪");
	set("long", @LONG
这是一条盘曲蜿蜒而上的小路，由于其形状扭曲的象一条游龙，故称为
龙升坪。沿着人工开凿的石阶而上，可以看到远处的山峰时隐时现在云雾中，
峰峦挺秀，婀娜多资。你不禁赞叹道“才睹‘登龙’腾汉宇，遥瞻‘飞凤’
弄晴川”。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
               "west":__DIR__"chunyangd1",
               "southup":__DIR__"shenshuige",
	]));

	setup();
	replace_program(ROOM);
}




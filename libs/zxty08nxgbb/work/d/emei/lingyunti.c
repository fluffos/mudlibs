// Room: /d/emei/lingyunti.c 峨嵋派 凌云梯


inherit ROOM;


void create()
{
	set("short", "凌云梯");
	set("long", @LONG
这里是一条笔直上山的石梁，人工凿出一格格阶梯，其实山势已经很高。
薄薄的浮云不断环绕着石阶流动，走在路上，前面的石阶已经模糊不清。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
		"northdown" : __DIR__"xixiangchi",
		"southup" : __DIR__"leidongping",
	]));

	set("objects",([
	]));

	setup();
}

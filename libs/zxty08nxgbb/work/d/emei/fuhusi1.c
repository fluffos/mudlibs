// Room: /d/emei/baoguosi.c 峨嵋派 伏虎石
// create by host dec,20 1997

inherit ROOM;


void create()
{
	set("short", "伏虎石");
	set("long", @LONG
这是一条小道，两边依然是茂密的竹林。引人注目的是在路旁有一块
酷似老虎的大石，张牙舞爪，惟妙惟肖。这里有一条叉路，再往南是一座
寺庙，往东走是上山的必经之路。
LONG
	);
         set("outdoors", "emei");
	set("exits", ([
		"south" : __DIR__"fuhusi",
                "west" : __DIR__"milin2",
                "north":__DIR__"milin1",
	]));

	set("objects",([
	]));

	setup();

}

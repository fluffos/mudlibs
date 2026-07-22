// Room: /d/emei/wannianan.c 峨嵋派 万年庵
// create by host dec,20 1997

inherit ROOM;


void create()
{
	set("short", "万年庵");
	set("long", @LONG
这是一座砖殿，共分两层。墙壁、斗拱、窗棂全部用大大小小的砖堆
砌而建。在大殿正中铸造的普贤骑象的铜像，形态威武生动。在砖殿四周
的墙壁上彩绘了许多的人物，或座或立形态各异。扬头往去在殿的最上层
挂了一口古钟，不时发出嗡嗡声。
LONG
	);

	set("exits", ([
                "east": __DIR__"shierpan1",
	]));


	set("objects",([
	]));

	setup();
}

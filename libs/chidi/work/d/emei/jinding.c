// Room: /d/emei/jinding.c 峨嵋派 金顶
// create by host dec,15
inherit ROOM;


void create()
{
	set("short", "金顶");
	set("long", @LONG
这里时峨嵋上的绝顶「金顶」，登上绝顶的观海崖，站在上面望向四方，
只见滚滚漂动的云雾，环绕着山的四周，雾气迷梦，凉风阵阵。从舍身岩而
上，阳光从相反方向投射在云雾上出现了一个巨大的彩色光环，光环中俊秀
的山峰如同大海中的岛屿，景色十分的壮观。从这里往西到了峨嵋最大的宝
刹「卧云庵」，而继续往上是峨嵋的藏经阁「华藏庵」。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                 "northdown": __DIR__"baizhangyan",
                 "west": __DIR__"miaomen",
                 "southup" : __DIR__"duguangtai",
	]));
	set("objects",([
	]));

	setup();
        call_other("/d/board/emei_b","???");
}

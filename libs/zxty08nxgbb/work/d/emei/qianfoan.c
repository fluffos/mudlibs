// Room: /d/emei/qianfoan.c 峨嵋派 千佛庵

inherit ROOM;

void create()
{
	set("short", "千佛庵");
	set("long", @LONG
这里是峨嵋的千佛庵。是一座宽敞宏伟的庵堂，庵前种满了许多的古
红椿树，树木茂密，遮天闭日。庵内正中供奉几尊铜铸的佛像，最为引人
注目的是屋顶挂了一盏雕刻有三百余铜雕佛像，飞龙、莲花近百的千佛莲
灯。因此吸引了无数的人长途跋涉前来参阐理佛，香火到十分的旺盛。
LONG
	);

	set("exits", ([
		"west" : __DIR__"shangu",
	]));

	set("objects",([
                 CLASS_D("emei") + "/jingzhao": 1,
	]));

	setup();
}

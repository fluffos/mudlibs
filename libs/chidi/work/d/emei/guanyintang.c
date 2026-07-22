// Room: /d/emei/guanyintang.c 峨嵋派 观音堂
// create by host dec,20 1997

inherit ROOM;


void create()
{
	set("short", "观音堂");
	set("long", @LONG
这是一座看起来并不起眼的佛堂，堂内全是用铁瓦石柱建成。但在正中
安然稳放了一座“千手观音”，如孔雀开屏般的从上、左、右三个方向伸出
的手，每只都雕得纤美细柔，手拿法器，千姿百态无一雷同。在左右金童、
玉女分伺两旁。
LONG
	);

	set("exits", ([
                "northwest" :  __DIR__"huayanding",
                "east" : __DIR__"xixiangchi",
	]));

	set("objects",([
             CLASS_D("emei") + "/jingkong": 1,
	]));

	setup();
}

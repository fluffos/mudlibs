// Room: /d/emei/chunyangd.c 峨嵋派 纯阳殿
// create by host dec,12 1997

inherit ROOM;


void create()
{
	set("short", "纯阳殿");
	set("long", @LONG
这里是峨嵋的纯阳殿，大殿正中供奉了一尊普贤菩萨。一群青衣小尼
正在佛像前的地上诵经。大殿四周墙壁的横龛冒出缕缕香烟与梵唱交错在
一起，令人顿时生起几分脱俗之感。
LONG
	);

	set("exits", ([
                "east":__DIR__"chanfang1",
                "north":__DIR__"chunyangd1",
                "west":__DIR__"chanfang2",
	]));

	set("objects",([
                CLASS_D("emei") + "/jingxian" : 1,
         ]));
	setup();

}

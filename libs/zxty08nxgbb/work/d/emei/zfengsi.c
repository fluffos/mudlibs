// Room: /d/emei/zfengsi.c 峨嵋派 中峰寺
// create by host dec,20 1997

inherit ROOM;


void create()
{
	set("short", "中锋寺");
	set("long", @LONG
这是一座纯石建成的砖殿，大殿四周墙壁上有横龛，上雕刻了数尊佛像。
墙壁的窗棂是被雕刻成了许多梅花状，每当阳光透入，大殿中仿佛被一层雪
白的梅花所覆盖。在正中有一个较大的佛龛，上摆放了一座白玉石的观音。
LONG
	);

	set("exits", ([
		"west" : __DIR__"shenshuige",
	]));

	set("objects",([
                 CLASS_D("emei") + "/jingjia": 1,
	]));

	setup();
}

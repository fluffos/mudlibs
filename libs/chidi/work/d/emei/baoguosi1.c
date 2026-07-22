// Room: /d/emei/baoguosi.c 峨嵋派 保国寺


inherit ROOM;


void create()
{
        set("short", "大殿");
	set("long", @LONG
这里报国寺的正殿，琉璃八角顶，挂着三十六个铜铃，微风吹动，不停
的响起悦耳的铃声。外木檐为斗拱，内有券顶。正中供奉有一尊用杏木雕成
的“千手千眼观音”，观音四面千手，每手一眼，构思巧妙，雕工精美。
LONG
	);
        set("valid_startroom", 1);
	set("exits", ([
                "north":__DIR__"baoguosi",
	]));
        set("objects",([
               CLASS_D("emei") + "/jingxin" : 1,
	]));

	setup();
}

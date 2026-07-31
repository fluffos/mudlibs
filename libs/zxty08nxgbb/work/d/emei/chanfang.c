//  /d/emei/chanfang.c 禅房

inherit ROOM;

void create()
{
        set("short","禅房");
	set("long", @LONG
这里是一间峨嵋僧众参阐和修习的地方，屋内摆设很简单，除了有一张
很大的竹床和一张桌椅外，别无他物。不过仔细往墙上看去，仿佛可以看到
墙壁上刻一些经文。在屋中有几位年纪比较轻的俗家弟子，在闭目打坐。
LONG
	);
        set("set_jingzuo",1);
	set("exits", ([ /* sizeof() == 3 */
                "west": __DIR__"baoguosi",
		]));

	set("objects",([
               "/d/emei/npc/sumengqing": 1,
	]));


	setup();
}

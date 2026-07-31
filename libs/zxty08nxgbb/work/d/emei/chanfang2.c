//  /d/emei/chanfang1.c 禅房

inherit ROOM;

void create()
{
        set("short","禅房");
	set("long", @LONG
这是一间峨嵋僧众参阐和修习的地方，屋内摆设很简单，正中
一张茶几，一张木床上放了一个蒲团。
LONG
	);
        set("set_jingzuo",1);
	set("exits", ([ 
                "east": __DIR__"chunyangd",
		]));

	set("objects", ([ 
              "/d/emei/npc/limingxia": 1,
	]));

	setup();

}

// Room: /d/emei/shangu.c 峨嵋派 山谷口

inherit ROOM;

void create()
{
	set("short", "山谷口");
	set("long", @LONG
这里是一线天的尽头，道路豁然开朗，抬头望去，只见前面不远处是
一个山谷，树林茂密，百草从生。在谷口东面处有一座庵堂，不时从里面
传来木鱼的敲打声。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                 "east" : __DIR__"qianfoan",
		 "south" : __DIR__"jiudaoguai1",
                 "northdown":__DIR__"yixiantian",
	]));

        set("objects", ([ 
                "/d/emei/npc/qiaofu" : 1,
            ]));

	setup();
}




// Room: /d/emei/jietuopo.c 峨嵋派 解脱坡


inherit ROOM;




void create()
{
	set("short", "解脱坡");
	set("long", @LONG
这里是一条深邃小峡谷，两边长满了茂密的植物，翠绿的竹林、鲜艳的
花卉、清脆的鸟鸣。偶尔还可以看到有几只松鼠在树林间窜来窜去。清晨几
许阳光透入进来，似云蒸霞蔚般，气象万千。
LONG
	);

	set("exits", ([
                 "southup":__DIR__"chunyangd1",
                 "northdown":__DIR__"liangfengqiao",
                 "east":__DIR__"rongshulin1",
	]));
        set("objects",([
	 "/d/emei/npc/songshu" : 1,
        ]));

        set("outdoors", "emei");
	setup();
	replace_program(ROOM);
}




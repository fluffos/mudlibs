// Room: /city/biaoju.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
        set("short", "飞龙帮总部");
        set("long", @LONG
你来到一座结构宏伟的建筑前，左右石坛上各插着一根两丈多高的旗杆，杆
上青旗飘扬。右首旗子用金线绣着一头张牙舞爪的狮子，狮子上头有一只蝙蝠飞
翔。左首旗子上写着「飞龙帮」三个黑字，银钩铁划，刚劲非凡。入口处排着两
条长凳，几名帮众坐着把守。帮主正跟他们说笑。
LONG);

	set("exits", ([
		"south" : __DIR__"xidajie3",
	]));

	set("objects", ([
                 "/clone/npc/feilong" : 1,
                __DIR__"npc/bangzhong" : 4,
	]));

	setup();
	replace_program(ROOM);
}
// Room: /city/biaoju.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
        set("short", "巨鲸帮总舵");
        set("long", @LONG
你来到一座结构宏伟的建筑前，左右石坛上各插着一根两丈多高的旗杆，
杆上青旗飘扬。右首旗子用金线绣着一头张牙舞爪的狮子，狮子上头有一只
蝙蝠飞翔。左首旗子上写着“巨鲸帮”三个黑字，银钩铁划，刚劲非凡。入
口处排着两条长凳，几名帮众坐着把守。帮主正跟他们说笑。
LONG
	);

	set("exits", ([
		"north" : __DIR__"xijie",
	]));

	set("objects", ([
		"/clone/npc/jujing" : 1,
                __DIR__"npc/bangzhong" : 4,
	]));

	setup();
	replace_program(ROOM);
}


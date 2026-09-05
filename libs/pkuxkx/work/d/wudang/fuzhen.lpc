// fuzhen.c 复真观一层
// by arnzh 97/1/24

inherit ROOM;

void create()
{
	set("short", "复真观一层");
	set("long", 
"这是一座刚建好的道观，矗立在寂静的松林之中。观门前\n"
"悬着一块新漆的匾额，上书“复真观”。这儿是武当派收藏道\n"
"学典籍的地方，武当弟子可在此处阅读经书，也有不少道士抄\n"
"下经书，回去用心研学。\n"
	);
        set("outdoors", "wudang");

	set("exits", ([
		"east" : __DIR__"ximen",
		"up" : __DIR__"fuzhen2",
		"north" : __DIR__"songlin",
	]));
        set("objects", ([
                CLASS_D("wudang") + "/zhixiang" : 1,
                       ]));

       	setup();
	replace_program(ROOM);
}


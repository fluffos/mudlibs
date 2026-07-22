// /d/emei/taolin.c 峨嵋派 桃林
// create by host dec,20 1997
inherit ROOM;

void create()
{
	set("short", "桃林");
	set("long", @LONG
你走进一片桃林，树上结满了粉红的果实，红云一片，望不到边。看着
垂枝的仙桃，踏著柔软的细草，鼻中闻着弥漫在空气中的桃李香，阵阵沁人
心脾，令人欲醉。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([ 
		"south" : __DIR__"liba",
                "north" : __DIR__"yunvfeng",
		]));
	set("objects", ([ 
	]));

	setup();
}

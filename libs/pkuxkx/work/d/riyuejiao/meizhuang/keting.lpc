// keting.c	梅庄客厅
// by bing

inherit ROOM;

void create()
{
        set("short", "客厅");
        set("long", @LONG
这里是梅庄庄主接待客人的地方。堂上摆着一张方桌，几把椅子。
中央的墙壁上挂着一幅画(drawing)，此外再没什么装饰物，整个屋子
显得明亮，洁净。
LONG);
	    set("item_desc",([
        	"drawing" :"只见画中所绘是一个仙人的背面，墨意淋漓，笔力雄健，又见画上题款
是：「丹青生大醉后泼墨」八字，笔法森严，一笔笔便如长剑的刺划。
好象这字中画中，更似乎蕴藏着一套极高明的剑术。\n",
	    ]));

        set("exits", ([ 
	"south" : __DIR__"tianjing",
	"west"	: __DIR__"huilang",
	"north" : __DIR__"yuanzi",
]) );
	set("objects",([
		__DIR__"npc/dingjian":1,
		]));
	setup();
}

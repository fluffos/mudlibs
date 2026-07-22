// Room: /city/shuyuan.c

inherit ROOM;

void create()
{
	set("short", "书院");
	set("long", @LONG
这里就是顾炎武晚年隐居, 教书谈文的扬州书院。你一抬头，就见到壁上
挂着一幅高约五尺，宽约丈许的大画，绘的是一大片山水，笔势纵横，气象雄
伟，你不禁喝了声采。画上只题了四个大字：“如此江山”。你走到画前仔细
观看，只见大江浩浩东流，两岸峰峦无数，点缀着奇树怪石，只是画中云气弥
漫，山川虽美，却令人一见之下，胸臆间顿生郁积之气。顾先生的身后还有一
幅字贴(zitie)。
LONG
	);

	set("exits", ([
        "up" : __DIR__"wizroom",
		"south" : __DIR__"dongdajie2",
	]));

	set("item_desc", ([
		"zitie" : "清风虽细难吹我，明月何尝不照人。\n山川开霁故壁完，何处登临不狂喜? \n\n"
	]));
	
	set("objects", ([
		__DIR__"npc/gu": 1,
		__DIR__"npc/boy": 1,
	]));

	set("incity",1);
	setup();
}

int valid_leave(object me, string dir)
{
	me->delete_temp("mark/literate");
	return 1;
}

//changan city
// Cracked by 凌惊雪 1-3-2003

inherit ROOM;

void create ()
{
        set ("short", "寒窗古屋");
        set ("long", @LONG
    此间书局是洛阳城中卖书最多，最快的地方。这里的老板大
有名气，听说曾是当今皇太子的老师。凡是京都出的新书，都被快马
送到这里，然后刻板印刷。这里不但很多风骚文人喜欢的诗词，还卖
一些粗浅的功夫书，供城中居民练来强身健体。
LONG);

        set("exits", 
        ([ //sizeof() == 4
                "south" : __DIR__"dingde1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/bookseller" : 1,
        ]));
        set("outdoors", "luoyang");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}



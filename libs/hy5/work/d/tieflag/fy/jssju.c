 inherit ROOM;
void create()
{
        set("short", "警世书局");
        set("long", @LONG
这是风云城中唯一的书局，是城中卖书最多最快的地方。老板大有名气，听说
是当今皇太子的老师。凡是京都出的新书，都被快马送到这里，然后刻板印刷。书
局里不但有很多风骚文人喜欢的诗词，还卖一些粗浅的功夫书，供城中居民练来强
身健体。
LONG
        );
        set("exits", ([
                "east" : __DIR__"nwind1",
        ]));
        set("objects", ([
                __DIR__"npc/bookseller": 1,
        ]) );
        set("coor/x",-10);
        set("coor/y",10);
        set("coor/z",0);
        set("coor/x",-10);
        set("coor/y",10);
        set("coor/z",0);
        setup();
        replace_program(ROOM); 
}    

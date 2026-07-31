 inherit ROOM;
void create()
{
        set("short", "沙岭");
        set("long", @LONG
放眼望去，只有黄沙，无边无际，无穷无尽的黄沙，没有水，没有生命，也
没有希望。此处地远人稀，不仅时常出没的沙盗横行猖獗，更为可怖的是频繁的
风沙暴，但见黄沙在风暴中卷舞，沙丘上赫然尸身纵横，血迹未干。天地间，充
满了萧索萧杀之气。
LONG
        );
        set("exits", ([ 
                "south" : "/d/quicksand/greenland",
                "west" : "/d/quicksand/desert6",
                "northeast" : __DIR__"mirage",
                "east" : "/d/quicksand/desert8",
        ]));
        set("outdoors", "loulan"); 
        set("coor/x",-1085);
        set("coor/y",50);
        set("coor/z",0);
        setup();
}

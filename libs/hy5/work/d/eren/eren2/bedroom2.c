 inherit ROOM;
void create()
{
        set("short", "卧室");
        set("long", @LONG
一进门，便闻到一阵浓烈花香，屋内地上铺了绣花锦垫，墙上点着红烛。
珠帘锦帷、富丽灿烂。东侧有一张六尺宽,八尺长的红木镏金大床，床侧的石
壁上镶满了镜子，屋顶雕有石刻，皆是男女欢好之式，看的人血脉翕张。
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"palace4",
                                ]));
        set("objects", ([
                __DIR__"npc/girl2" : 1,
                __DIR__"npc/girl4" : 1,
                __DIR__"npc/xiaomimi" : 1,
                __DIR__"npc/baiyi" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       

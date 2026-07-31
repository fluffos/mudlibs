// shanlu1.c 山路
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
从武功西门出来，路势变急了，这是一条用石块铺成的山路。路
两旁光秃秃的，没有什么树木，全是一块块的大石头。这条路好象通
往前面的终南山上。北面有一个小村庄，村中正升起冉冉的炊烟。
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "eastup" : __DIR__"shanlu2",
                "northup" : __DIR__"xiaocun",
                "southwest" : __DIR__"ximen",
//"westdown" : "/d/hanzhong/shanlu",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

 inherit ROOM;
void create()
{
        set("short", "阿斯塔那");
        set("long", @LONG
阿斯塔那是维吾尔语，意思是“首府”。墓葬按家族分区，每一家
族均有固定的墓地，以砾石为界，每个墓葬基本都有斜坡墓道和土墓室。
墓道和墓室顶部地面一般都堆摆砾石，平面呈“甲”字形。
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"emin",
]));
        set("objects", ([
        __DIR__"npc/ghost" : 3,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("coor/x",-1040);
        set("coor/y",2020);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}

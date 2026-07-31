 inherit ROOM;
void create()
{
        set("short", "北佛塔");
        set("long", @LONG
你的眼前骤然一变，便从黑暗的世界中，进入了一个辉煌灿烂的天地，有如
奇迹。这里是一巨大的石柱上，雕着华美而古拙的图案，四壁闪耀着奇光。仔细
看去，原来这竟然本是座巍峨耸立的佛塔，陷入沙漠后，逐渐成了“大石柱”，
你做梦也未想到沙漠之下竟有如此堂皇伟大的建筑。这里，便是汉时辉煌一时的
楼兰古国遗址！
LONG
        ); 
        set("exits", ([ 
                "up" : __DIR__"kongquehe",
                "south" : __DIR__"northstrt2",
        ]));
        set("objects", ([
                __DIR__"npc/qi" : 1,
        ]) );
        set("indoors", "loulan");
        set("coor/x",-1000);
        set("coor/y",250);
        set("coor/z",-100);
        setup();
} 
int valid_leave(object me, string dir)
{
        object ob;
        mapping m_family;
        if( me->query("class") != "knight" )
        {
                if( userp(me) && dir=="south" && ob=present("dugu shang", this_object()) ) 
                {
                        if( !me->query_temp("marks/knight_win_dugu"))                
                                return notify_fail("独孤伤冷冷道：打赢我，进去；打输了，滚蛋。”\n");
                }
        }
        return 1;
}

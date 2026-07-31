 inherit ROOM;
void create()
{
        set("short", "西佛塔");
        set("long", @LONG
你的眼前骤然一变，便从黑暗的世界中，进入了个辉煌灿烂的天地，有如奇
迹。这里是一巨大的石柱上，雕着华美而古拙的图案，四壁闪耀着奇光。仔细看
去，原来这竟然本是座巍峨耸立的佛塔，陷入沙漠后，逐渐成了“大石柱”，你
做梦也未想到沙漠之下竟有如此堂皇伟大的建筑。这里，便是汉时辉煌一时的楼
兰古国遗址！
LONG
        );
        set("exits", ([ 
                "up" : __DIR__"kongquehe",
                "east" : __DIR__"weststrt3",
        ]));
        set("indoors", "loulan");
        set("objects", ([
               __DIR__"npc/cai" : 1,
        ]) ); 
        set("coor/x",-1050);
        set("coor/y",200);
        set("coor/z",-100);
        setup();
} 
int valid_leave(object me, string dir)
{
        object ob;
        mapping m_family;
        if( me->query("class") != "knight" )
        {
                if( userp(me) && dir=="east" && ob=present("jin wuwang", this_object()) ) 
                {
                        if( !me->query_temp("marks/give_jin_gold"))                
                                return notify_fail("金无望一言不发，身形微动，挡在你的身前。\n");
                }
        }
        return 1;
}     

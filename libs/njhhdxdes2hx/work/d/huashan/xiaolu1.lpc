// Room : /d/huashan/xiaolu1.c
//by www 



inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
你走在一条小路上，小路一侧是悬崖，另一侧则是峭壁。路上若有两人相对而行，
必须侧身才能通过。路上寸草未生，你向上一看，有一些小松从峭壁中伸出。
LONG
        );
        
        set("exits", ([
                   "southeast" : __DIR__"square",
                "west" : __DIR__"xiaolu2",
        ]));
        set("objects", ([
                CLASS_D("huashan") + "/gao" : 1]));

        setup();
        set("no_clean_up", 0);
        setup();


}
int valid_leave(object me, string dir)
{
        if( this_player()->query_temp("marks/思1") ) {
                this_player()->set_temp("marks/思1", 0);
        }
        return 1;
}

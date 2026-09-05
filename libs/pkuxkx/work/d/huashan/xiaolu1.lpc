// Room : /d/huashan/xiaolu1.c
//by www



inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
这里是一条小路，通向华山后山。
LONG
        );

        set("exits", ([
                   "southeast" : __DIR__"square",
                "west" : __DIR__"xiaolu2",
        ]));
        set("no_hsnewbiejob",1);
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

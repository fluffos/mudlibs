inherit ROOM;
void create()
{
        set("short", "后花园");
        set("long", @LONG
这里是华山派的后花园，种满了花草。园中有个水井
可以用来装水。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"buwei2",
   "west" : __DIR__"shufang",
  "south" : __DIR__"sleeproom",
  "east":__DIR__"houhuayuan1",
  ]));

        set("objects", ([
                CLASS_D("huashan") + "/liang-fa" : 1]));

        set("resource/water",1);
        set("no_clean_up", 0);
        set("outdoors", "xx" );
        setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);  
    if (me->query_temp("hsnewbiejob/xunlian"))
    {
        return ::valid_leave(me,dir);
    }
        if ( dir == "north" && objectp(present("liang fa", environment(me)))
            && living(present("liang fa", environment(me))))
            return notify_fail("梁发喝道：那里是家师寝室，不得入内。\n");
        return ::valid_leave(me, dir);
}

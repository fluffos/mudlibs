//by binlang
// lvliu1.c
inherit ROOM;
void create()
{
        set("short", "绿柳山庄大门");
        set("long", @LONG
这是绿柳山庄的大门，门旁有几个庄丁。
LONG
        );
        set("exits", ([
            "north" : __DIR__"xiaoyuan",
            "northwest" : __DIR__"tolvliu2",
        ]));
        set("objects", ([
            __DIR__"npc/ding2" : 2,
         ]) );
        set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{
    int i;
    object *ob;
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);  
    if ( dir != "north" || me->query_temp("marks/庄"))
        return ::valid_leave(me, dir);
    ob = all_inventory( environment( me ));
    for(i=0; i<sizeof(ob); i++) 
    {
        if( living(ob[i]) && ob[i]->query("id") == "zhuang ding" )
            return notify_fail("庄丁挡住了你：喂，你总该意思意思吧？\n");
    }
    return ::valid_leave(me, dir);
}

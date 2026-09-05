inherit ROOM;
void create()
{
        set("short", "走廊");
        set("long", @LONG
处处暖云处处歌，这可以看到的是无限的美景，不尽的风流。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
    "east" : __DIR__"xiangfang1",
    "west" : __DIR__"xiangfang2",
    "north" : __DIR__"garden",
    "south" : __DIR__"corror1",
]));
       set("objects", ([
                
__DIR__"npc/baobiao" :1,
        ]));
	   set("no_newbie_task",1);

        setup();
}
int valid_leave(object me, string dir)
{
    object bao;
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);  
    if((dir == "north") &&  this_player()->query("class") != "officer"
    && objectp( bao = present("bao biao", environment(me))) && living(bao))
    {
        if (me->query("combat_exp")>1000000)
        {
        bao->kill_ob(me);        
        return notify_fail("保镖向你吼道：小杂种，这也是你来的地方?\n");
        }
        return notify_fail("保镖向你吼道：小杂种，这也是你来的地方?\n");
    }
    else
    return::valid_leave(me,dir);
}

// xiaowu.c
inherit ROOM;
void create()
{
        set("short", "");
        set("long", @LONG
这是牛家村小屋，屋里零乱的堆放了些东西，已经好久没人住了。
LONG
        );
        
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"neishi",
  "south" : __DIR__"dalu",
]));
        set("objects", ([
               __DIR__"npc/shagu" : 1,
                ]));
        
        set("no_clean_up", 0);
        setup();
        

}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");
        if ((!myfam || myfam["family_name"] != "桃花岛") && dir == "north" &&
                objectp(present("sha gu", environment(me))))
           return notify_fail("傻姑喝道：你不是桃花岛弟子，不得入内。\n");
        return ::valid_leave(me, dir);
}

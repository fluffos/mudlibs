// zoulang.c 走廊
// zoulang1.c 走廊
// by binlang
//last edit by black,防止外派弟子进入休息室
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "走廊");
        set("long", @LONG
你走在一条走廊上，北面是休息室，东边是走廊，不时的有人走过
西面是一间饭厅，时时飘来一股香气。
LONG
        );
        set("exits", ([
                "north" : __DIR__"xiuxishi",
                "west" : __DIR__"fanting",
                "east" : __DIR__"zoulang",
        ]));
 setup();
}
int valid_leave(object me,string dir)
{
     if(dir=="north"&&(string)me->query("family/family_name")!="明教")
    return notify_fail("明教休息室，外派弟子不得入内!!\n");
    return ::valid_leave(me,dir);
}

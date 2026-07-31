// Room of wizard that haven't modify own workroom
// Updated by Lonely

#include <ansi.h>
#include <room.h> 
inherit CREATE_CHAT_ROOM; 

int is_chat_room() { return 1; } 

void create()
{
        set("short", HIB"流星虚夜"NOR);
        set("long", @LONG
你现在置身于一个毫不着力的空间，在你的头顶上方有一个很大
的光球，正缓缓转动着，散发出柔和的银光。据说那里就是带给人间
无数希望的流星的源泉，也是流星操控者司马流星离开人间时，暂时
休憩的所在。
LONG );

        set("exits", ([ /* sizeof() == 1 */
                "north" : "/d/wizard/wizard_room",
        ]));
        
        set("valid_startroom", 1);
        set("no_fight", "1");
        set("no_clean_up", 0);
        setup();
       "/clone/board/meteor_b"->foo();
}

int valid_leave(object me, string dir)
{
        if (dir == "north" && ! wizardp(me))
                return notify_fail("那里只有巫师才能进去。\n");
                
        return ::valid_leave(me, dir);
}

void init()
{
        add_all_action(); 
}


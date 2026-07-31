// Room: /d/huashan/xiaowu.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "林间小屋");
        set("long", @LONG
这里就是华山剑宗的的根本之地。二十五年来，剑宗弟子卧薪尝胆，
只是为了夺回华山门派掌门，为此，付出了极大牺牲。
    屋里陈设极为简陋。这么多年来一直没有长久隐匿的念头使得剑宗弟
子能忍辱负重，只待重开生天。
LONG );
        set("exits", ([ /* sizeof() == 4 */
             "west": __DIR__"pingdi",
        ]));
        set("objects", ([
             CLASS_D("huashan") + "/feng-buping": 1,
        ]));
        set("valid_startroom","1");
//        set("no_clean_up", 0);

        setup();
        "/clone/board/jianzong_b"->foo();
        replace_program(ROOM);
}


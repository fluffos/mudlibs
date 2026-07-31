#include <room.h>

inherit ROOM;

void create()
{
    set("short", "桃花山庄前院");
    set("long", @LONG
你现在正站在一个宽敞的院子中。院子原来是作为练武场用
的。但自从桃花岛弟子被黄药师逐出岛外，就已经没人在此练武。
东面是兵器室，西面是厨房，往南就是桃花山庄正厅了。
LONG );
    set("exits", ([
        "north" : __DIR__"damen",
        "south" : __DIR__"dating",
        "east"  : __DIR__"bingqi",
        "west"  : __DIR__"chufang",
    ]));
    set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
	set("objects", ([
           "/quest/menpai/taohua/shi" : 1,
           "/d/taohua/npc/puren" : 2,
           "/d/taohua/npc/binu" : 1,
           	]) );    

    set("outdoors", "taohua");
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}

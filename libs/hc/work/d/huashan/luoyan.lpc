// Room: /d/huashan/luoyan.c

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "落雁峰");
        set("long", @LONG
南峰又名落雁峰，是华山最高峰。峰头题刻极多，如“太华峰头”、“竣
极于天”、“袖拂天星”等，极言华岳之高。环顾四周，皆在足下。寇准诗赞
曰：只有天在上，更无山与齐；举头红日近，回首白云低。传说五代时候的隐
士陈抟就隐居在这里。宋太祖曾经下诏征他出山作官，他便在这里写下谢诏表
说：“一片野心都被白云锁住，九重宠诏休教丹凤衔来”，表示不愿出山做官。
LONG
        );
        set("objects", ([
//            CLASS_D("huashan") + "/feng-qingyang":1,
            CLASS_D("huashan") + "/feng" : 1,
        ]));
        set("exits", ([ /* sizeof() == 4 */
           "northdown" : __DIR__"zhandao",
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "huashan");
        setup();
        replace_program(ROOM);
}

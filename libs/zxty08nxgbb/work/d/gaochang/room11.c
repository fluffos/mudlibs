// Room: /u/mei/room11.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "大漠风沙");
        set("long", @LONG
你现在处在酷热如烘炉的沙漠中，热的令人连气都透不出。除了满耳呼呼
的风声，你什么也听不见；除了满眼滚滚的飞沙，你什么也看不见；天地间
仿佛只剩下你一个人。你脚下缓缓而动的流沙给你如履薄冰的感觉。
LONG
        );
        set("exits", ([ /* sizeof() == 8 */
  "south" : __DIR__"room13",
  "southwest" : __DIR__"room13",
  "north" : __DIR__"room12",
  "northeast" : __DIR__"room13",
  "east" : __DIR__"room13",
  "southeast" : __DIR__"room13",
  "west" : __DIR__"room13",
  "northwest" : __DIR__"room10",
]));
        set("no_new_clean_up", 0);

        setup();
}
int valid_leave(object me, string dir)
{
        int current_water;
        current_water = me->query("water");
        if (current_water==0) {
        }
        if (current_water>0 && current_water<20) {
            me->set("water",0);
        }
        if (current_water>20) {
            me->set("water",current_water-20);
        }

    return 1;
}


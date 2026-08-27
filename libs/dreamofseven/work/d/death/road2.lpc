// Room: /d/death/road2.c
 
inherit ROOM;
 
void create()
{
        set("short", "鬼門大道");
        set("long", @LONG
你走在一條陰森森的路上, 濃濃的霧環繞在你的四周, 好像永
遠都不會散去似的. 整條路前後只看到零星的幾盞燈籠........
 
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/death/road3",
  "south" : "/d/death/road1",
]));
 
        setup();
}
int valid_leave(object me, string dir)
{
        int i;
        if (dir == "north") {
                i = (int)me->query_temp("long_road");
                i = i + 1;
                if (i == 5) {
                me->delete_temp("long_road");
                return 1;
                }
                else {
                        me->set_temp("long_road",i);
                        return notify_fail("你走著走著..... 發現四周景色居然都沒有變....\n");
                }
        }
        else {
        if (dir == "south") {
                me->delete_temp("long_road");
                return 1;
                }
        return 1;
        }
}

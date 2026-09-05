inherit ROOM;
void create()
{
        set("short", "客厅");
        set("long", @LONG
这里是郭靖家的客厅，郭大侠常年操劳军务，家中无人照管。
客厅里摆着很简朴的家具，有一个中年女佣正在打扫卫生。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"houyuan",
  "south" : __DIR__"xyeast2",
  ]));

        set("objects", ([
                __DIR__"npc/nvyong" : 1]));

        set("no_clean_up", 0);
        set("outdoors", "xx" );
        setup();
}


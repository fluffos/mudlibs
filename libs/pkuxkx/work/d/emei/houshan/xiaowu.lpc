// Room: /u/cuer/emei/xiaowu.c

inherit ROOM;

void create()
{
        set("short", "小屋");
        set("long", @LONG
这里是静修庵后的小屋。小门中站着一位服侍灭绝师太的姑娘。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"jxan",

]));            

        set("objects", ([
            __DIR__"npc/fblin" : 1,
            __DIR__"npc/guoxiang" : 1,
            ]));
        set("no_task",1);
        setup();
        replace_program(ROOM);
}

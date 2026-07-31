inherit ROOM;
void create()
{
        set("short", "南偏厅");
        set("long", @LONG
厅中一大台，酒肴已设。佳肴异果，罗列满案。酒味醇美，其甘如饴。此时月色
倍明，室中照耀，如同白日。满座芳香，螓首粉面。主客尽情欢笑。再往南则是一条
长长的走廊。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"corror",
  "north" : __DIR__"tading",
]));

       set("objects", ([
        __DIR__"npc/tianbg" : 1,
        __DIR__"npc/peijiunu" : 4,
                        ]) );

        setup();
}

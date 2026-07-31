// Room: /d/snow/schoolhall.c
inherit ROOM;
void create()
{
        set("short", "淳风武馆大厅");
        set("long", @LONG
这里是淳风武馆的正厅，五张太师椅一字排开面对著门口，这
是武馆中四位大师傅与馆主柳淳风的座位，和一般武馆不同的是，
墙上竟然挂著几幅风骨颇为不俗的书画，显示这里的主人并非大字
不识的粗汉，而是文武双全的高人。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
//  "south" : "/d/wizard/bigroom",
  "west" : __DIR__"school2",
  "east" : __DIR__"inneryard",
]));
       set("no_sleep_room",1);
       set("no_beg",1);
//        set("objects", ([ /* sizeof() == 1 */
//  "/daemon/class/swordsman/master" : 1,
//  "/d/snow/npc/masterli" :1,
// "/d/snow/npc/masterliu" :1,
// ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
/*
void init()
{
        object me,obj;
        obj=present("master",this_object());
        if (objectp(obj))
        {
                obj->prevent_in(this_player());
        }
}
*/

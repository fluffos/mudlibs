//Create by whuan@pkuxkx
//铁掌帮
inherit ROOM;

void create()
{
        set("short", "石阶");
        set("long", @LONG
你沿着石阶向上走，朝北边望去，在山腰似乎有一座小亭。
LONG    );
        set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shijie2",
  "northup" : __DIR__"xiaoting",
]));
        set("no_clean_up", 0);
        set("outdoors", "tiezhang");

        setup();
        replace_program(ROOM);
}
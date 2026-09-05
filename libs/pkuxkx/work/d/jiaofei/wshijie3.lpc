//Create by whuan@pkuxkx
//铁掌帮
inherit ROOM;

void create()
{
        set("short", "石阶");
        set("long", @LONG
这是一条通往峰顶的石阶，修缮极好，沿着石阶很容易就能攀到峰顶。
LONG    );
        set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"whouyuan", 
  "northup" : __DIR__"wshijie4", 
]));
        set("no_clean_up", 0);
        set("outdoors", "tiezhang");

        setup();
        replace_program(ROOM);
}
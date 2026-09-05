//Create by whuan@pkuxkx
//铁掌帮
inherit ROOM;

void create()
{
        set("short", "烽火台");
        set("long", @LONG
这是一座烽火台，台的正中央放着一堆半干的柴火及马粪，一经点燃，浓烟
滚滚，方圆五里之内皆清晰可见，用来传递消息再合适不过了。
LONG    );
        set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"xfengding", 
  "westdown" : __DIR__"xdshanlu1", 
]));
        set("no_clean_up", 0);
        set("outdoors", "tiezhang");

        setup();
        replace_program(ROOM);
}
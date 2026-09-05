//Create by whuan@pkuxkx
//铁掌帮
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这是往无名峰去的山路。两边是茂密的树林，你仔细一看似乎其中暗藏五形
八卦之理。 
LONG    );
        set("exits", ([ 
  "northup" : __DIR__"wshulin1",
  "southwest" : __DIR__"jiulongtang", 
]));

        set("no_clean_up", 0);
        set("outdoors", "tiezhang");

        setup();
        replace_program(ROOM);
}
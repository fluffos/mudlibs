//Create by whuan@pkuxkx
//铁掌帮
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这是一条通往食指峰的山路，路旁深深的杂草中，漏出半截石碑（bei）。 
LONG    );
        set("item_desc", ([
        "bei" : "这是一块大理石做成的石碑，经过岁月的冲刷，碑上文字已"
        	+"模糊不堪。\n你仔细看了看，似乎写着“食指峰”。\n",
        ]));
        set("exits", ([ 
  "northup" : __DIR__"sshanlu2",
  "southeast" : __DIR__"jiulongtang", 
]));
        set("no_clean_up", 0);
        set("outdoors", "tiezhang");

        setup();
        replace_program(ROOM);
}
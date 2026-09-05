//Create by whuan@pkuxkx
//铁掌帮
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
顺着山路过去便是其他四峰，山势渐行渐险，树木也稀少起来。
东边是一个山谷，隐约能听到风的呼啸传来。
LONG    );
        set("exits", ([ 
  "southwest" : __DIR__"xiaoting",
  "northup" : __DIR__"jiulongtang", 
  "east": __DIR__"zhaoze_config/entry"
]));
        set("no_clean_up", 0);
        set("outdoors", "tiezhang");

        setup();
        replace_program(ROOM);
}
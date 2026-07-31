#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "堂屋");
        set("long", @LONG
一间宽敞的堂屋，左右两排太师椅都是檀香木制成。正中那把尺寸大
一倍的雕花太师椅更是不凡。堂上正中挂有一匾额(bian)。左右偏堂的房
门半掩，看不清里面。
LONG);
        set("item_desc", ([
                "bian" : HIW"
            ※※※※※※※※※※※※※※※※※※※※※※
            ※※※※　　　　　　　　　　　　　　※※※※       
            ※※※※    白    驼    山    庄    ※※※※
            ※※※※　　　　　　　　　　　　　　※※※※
            ※※※※※※※※※※※※※※※※※※※※※※\n"NOR,                
          ]));
        set("exits", ([
              "southdown" : __DIR__"kongdi",
              "west" : __DIR__"yaofang",
              "north" : __DIR__"tuitang",
        ]));
        setup(); 
}

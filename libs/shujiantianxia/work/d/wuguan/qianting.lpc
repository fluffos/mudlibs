//qianting.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"武馆前厅"NOR);
        set("long", @LONG
这是一间完全用花岗岩砌成的房子，两旁的墙壁上插着松油火把，把大厅
照的通亮，寂静的大厅中不时响起火把噼啪的燃烧声。大厅的正中摆放着一张
太师椅，两旁分列着十几把椅子，正面的墙上挂着一面缕金的横匾(bian)。再
往北去就是武馆的前院了。
LONG
        );
        
	set("item_desc",([
            "bian" : HIY"				 
            ※※※※※※※※※※※※※※※※※※
            ※※※※　　　　　　　　　　※※※※
            ※※※※　                  ※※※※
            ※※※※   襄  阳  武  馆   ※※※※
            ※※※※　                  ※※※※     
            ※※※※　　　　　　　　　　※※※※
            ※※※※※※※※※※※※※※※※※※\n"NOR,
		]));
	 
        set("exits", ([
            "south" : __DIR__"menlang",
            "north" : __DIR__"dayuan",
        ]));         
        
        setup();
}

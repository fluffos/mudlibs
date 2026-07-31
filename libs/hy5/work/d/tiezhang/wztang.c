// Room: /u/zqb/tiezhang/wztang.c
#include <ansi.h>

inherit ROOM;
string look_bian();

void create()
{
	set("short", "五指堂");
	set("long", @LONG
    这是一间完全用花岗岩砌成的大厅，透出阵阵逼人的寒气。整座房
屋没有窗户，显得阴森黑暗。两旁的墙壁上插着松油火把，散发出昏黄的光
亮，寂静的大厅中不时响起火把噼啪的燃烧声。大厅的正中摆放着帮主的宝
座，两旁分列着十几把椅子，只有遇到帮中大事时，帮主才会在这里与部下
商议。在正面的墙上挂着一面缕金的横匾(bian)。北面有一扇小门通向后面
。
LONG	);
        set("item_desc", ([ 
        "bian"       :       (: look_bian :),
]));

set("roomif","$botten#修补工作|工具|完成任务:ask qiu about work|ask qiu about tools|task ok$#");

	set("exits", ([ 
  "east" : __DIR__"zoulang-1",
  "southdown" : __DIR__"guangchang.c",
  "west" : __DIR__"zoulang-2.c",
  "north" : __DIR__"hxfang.c",
]));
    set("objects", ([ 
  __DIR__"npc/qqren" : 1,
  __DIR__"npc/xiaotong" : 1,
  "quest/menpaijob/tiezhang/postman" : 1,

]));

	set("no_clean_up", 0);

	setup();
	
}
string look_bian()
{
    return
    "\n"
               HIY"          ####################################\n"
                  "          ####                            ####\n"
                  "          ####    五    指    擎    天    ####\n"  
                  "          ####                            ####\n"
                  "          ####################################\n"NOR;
    "\n";
}
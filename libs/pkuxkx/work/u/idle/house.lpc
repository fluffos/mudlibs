inherit ROOM;

#include <ansi.h>
void create ()
{

  set ("short", "云中城堡");
     set ("long", 

"这是Tower的高级生物泰坦居住的地方，墙上挂着曾随泰坦征战多年的"+CYN"泰坦战甲(Titan's Cuirass)"NOR+"和"+YEL"泰坦之剑(Titan's Gladius)"NOR+"，桌子上放着一堆仰慕这位大侠的ppmm寄来的情书(Letter)。\n"
);

  set("no_steal", "1");
  set("no_beg", "1");

  set("exits", ([ 
  "down" : "/u/idle/workroom",
]));

        set("objects", ([
                  "/u/idle/titan" : 1,
        ]));
  set("item_desc", ([ 
                "Titan's Cuirass" : "\n一件金光闪闪的无敌战甲，曾挡住了多少敌人的攻击啊！\n" ,
                "Titan's Gladius" : "\n一把杀气逼人的利器宝剑，曾饮无数英雄豪杰的献血呢！\n" ,
                "Letter"   : "\n美眉写的情书嘛，仰慕的话如滔滔江水～～，^_^\n"
        ]));

  setup();
  replace_program(ROOM);
}

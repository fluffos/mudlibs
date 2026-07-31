// Room: /d/sandboy/shandao 
#include <ansi.h>
inherit ROOM; 
 
void create ()
{
  set ("short", "山道");
  set ("long", @LONG
这是一条幽静的山道。太阳暖洋洋地在头上，溪水活泼泼地在脚边流过。 
小鸟儿唧唧叫着飞过不远的树林，前面路边有个破庙。 
LONG);

set("outdoors","/d/jiangnan");
  set("item_desc", ([ /* sizeof() == 3 */
  "树林" : "一片杂树林，大约有好几十棵。 
",
  "破庙" : "远看去，这间破庙摇摇欲坠，随时都可能蹋下来。 
",
  "溪水" : "山泉从高处流下，形成的小溪流。 
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shandao2",
  "south" : __DIR__"shandao1",
  "northdown":__DIR__"sidehill",
]));

  setup();
}
void init()
{
   message("vision",HIC+"从远处的破庙中传来一股烤鸡的香味!\n"+NOR,this_object());
}

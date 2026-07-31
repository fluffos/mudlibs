//Room: /d/dali/majiu.c
#include <room.h>
inherit TRANS_ROOM;

void create()
{
      set("short","马厩");
      set("long",@LONG
这是军营边上的马厩，常年供应新鲜草料。据说此地民风淳朴，
客人只要带马来，马夫们就会把马牵到马厩好生照看，将它们喂饱饮
足，再洗刷得干乾净净。一直伺候到客人离城上路。马厩雨檐下的烂
木柱上钉着一块破木牌。
    马厩中堆放著几堆草料，正中有一口泔槽。
LONG);
      set("outdoors", "dali");
      set("no_fight", 1);
      set("objects", ([
	       "/clone/horse/zaohongma": 1,
	       "/clone/horse/huangbiaoma": 1,
	       "/clone/horse/ziliuma": 1,
	       "/clone/npc/mafu": 1,
	     
      ]));
      set("exits",([ /* sizeof() == 1 */
		"east"  : __DIR__"bingying",
      ]));
      setup();
      //replace_program(TRANS_ROOM);
}

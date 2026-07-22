#include <room.h>
inherit ROOM;

void create()
{
      set("short","灵剑山庄");
      set("long",@LONG
这里便是江湖上传闻灵剑公子修心习武的地方,正对着你的是个
门阁,两边向外延伸的是红色的围墙,门阁上方的牌匾上书着飞
扬挺拔的四个大字[$RED$ 灵剑山庄].在门阁旁边是两棵高过门阁的
大树,细而密的枝叶伸展在每个的上面,美而浓的树阴把门阁笼罩
起来,使整个山庄显得含蓄而有风度.
LONG);
      set("outdoors", "xx");
      set("exits",([ /* sizeof() == 2 */
          "north" : __DIR__"path",
      ]));
      setup();
}


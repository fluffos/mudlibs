
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","长白瀑布");
  set ("long", @LONG
由于山大坡陡，水势湍急，一眼望去，象一架斜立的天梯。瀑布口
有一巨石，将瀑布分为两股。瀑布状如白练，从天而降，雷霆万钧，如
玉龙扑向谷底，其景象蔚为壮观。急流跌水，瀑布下形成深约二十丈的
水潭。
LONG);

  set("exits", ([ 
 "northup":__DIR__"baiyun-feng",
 "southdown":__DIR__"shanlu2",
 "eastup":__DIR__"shanlu6",
 "westup":__DIR__"longmen-feng",
        ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}


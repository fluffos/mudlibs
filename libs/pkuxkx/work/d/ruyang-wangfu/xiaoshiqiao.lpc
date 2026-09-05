//xiaoshiqiao.c -- 小石桥
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"小石桥"NOR);
  set("long", @LONG
这里有个不很深的水池，后花园小溪的水流到这里算是到了头。水池
里，红鲫、五花鲫、锦鲤还有各色金鱼，不时簇做一团，争抢食物。一座
平整的石桥，横跨水池，连通两岸。石桥上汉白玉石的栏杆，精雕细琢，
在阳光的照耀下，更显得晶莹剔透。过了桥，再往北走几步，就是王府的
后花园了。
LONG
  );

  set("exits", ([     
      "south" : __DIR__"chengqinglou",   
      "north" : __DIR__"houhuayuan", 
  ]));

  set("outdoors", "luoyang");
  setup();
  replace_program(ROOM);
}

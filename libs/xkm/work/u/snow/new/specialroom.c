// snow 特为设计第九空间而制作

inherit room;
#include <ansi.h>;

void create()
{
      set("short",第九空间);
      set("long",由空间主人飘雪的无穷法力创造而出的虚幻世界。);
      set("exits",([
          "out": "/u/snow/workroom" ,
      ]));

          setup();
}

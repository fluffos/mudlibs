inherit ROOM;

void create()
{
      set("short","密道");
      set("long",@LONG
你顺着洞口爬了下去，发现这里其实就是山石之间的缝隙，你双腿
紧紧的蹬着左右的山壁，慢慢的向下爬去，也不知爬了多远，忽然
你的双脚一空，掉到下面的空地上，你定了定神，仔细看了看，发
觉前面有一条路!
LONG);
         set("exits",([ /* sizeof() == 2 */
          "north" : __DIR__"shandong",
         
      ]));
      setup();
}


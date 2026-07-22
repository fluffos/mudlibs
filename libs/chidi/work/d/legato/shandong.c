inherit ROOM;

void create()
{
      set("short","山洞");
      set("long",@LONG
这里是一条细长的山洞，里面很黑，你摸着两边的山壁，很潮湿
不时还有水珠渗出来，山洞很小，你只能弯着腰，用手摸着一点
点向前走，渐渐的你看到一丝光亮从前方传了过来!
LONG);
          set("exits",([ /* sizeof() == 2 */
          "south" : __DIR__"midao",
         "north" : __DIR__"mangdong",
      ]));
      setup();
}


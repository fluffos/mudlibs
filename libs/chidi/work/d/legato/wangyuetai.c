inherit ROOM;

void create()
{
      set("short","望月台");
      set("long",@LONG
望月台其实就是一个大石头，镶嵌在半山腰，你看了看脚下，平坦光滑
，左边是陡峭的山壁，前边的苍松翠柏，郁郁葱葱，遮住了你的视线
你用手扶着山壁，小心翼翼的向前走着！
LONG);
      set("outdoors", "xx");
      set("exits",([ /* sizeof() == 2 */
          "northup": __DIR__"xianrensong",
          "southdown": __DIR__"shanlu2"
        ]));
      setup();
}


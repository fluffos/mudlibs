inherit ROOM;


void create()
{
   set("short","都江堰");
   set("long",@LONG
都江堰是秦朝巴蜀太守李冰主持修建的。一千多年来，它一直灌溉着这附近
的万亩良田。东去几十里就是成都城；向西跨过岷江，有一座高山。
LONG);
   set("exits",([
      "southeast"   : __DIR__"pingyuan7",
      "west"  : __DIR__"qingcheng_shan",
      "east"  : "/d/chengdu/nanheqiaow",
   ]));
   setup();
        set("outdoors","xinan");
}

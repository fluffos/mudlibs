inherit ROOM;


void create()
{
   set("short","山路");
   set("long",@LONG
由此向南就是秦岭了。北面是八百里平川的关中平原，一条宽阔平坦的大道
笔直地向东西延伸开去，不时有行人走过。南面，秦岭山脉高大的山峰挡住了视
线。
LONG);
   set("exits",([
      "northeast"   : "/d/zhongyuan/guandao2",
      "southup"       : __DIR__"shanlu2",
   ]));
   setup();
        set("outdoors","xinan");
}

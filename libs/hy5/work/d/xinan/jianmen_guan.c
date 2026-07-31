inherit ROOM;


void create()
{
   set("short","剑门关");
   set("long",@LONG
剑门关处于大小剑山之间，有“一夫当关，万夫莫开”之势。南面就是剑阁了。
    常言道，“蜀道难，难于上青天”。入蜀的山道狭窄崎岖，三步一关，五步
一险，稍一不留神，就会失足跌下山涧，摔得粉身碎骨。
LONG);
   set("exits",([
      "north"   : __DIR__"qipan_guan",
      "south"  : __DIR__"jianmen_shan",
   ]));
   setup();
        set("outdoors","xinan");
}

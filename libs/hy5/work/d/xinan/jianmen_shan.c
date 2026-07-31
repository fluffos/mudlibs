inherit ROOM;


void create()
{
   set("short","剑门山");
   set("long",@LONG
剑门山东西一百余里，有剑门七十二峰，峭壁中断，两崖相嵌，形似剑门，
故得此名。三国时，蜀国大将姜维曾在此与钟会对峙。往南去就是著名的剑阁古
道。
LONG);
   set("exits",([
     "north"   : __DIR__"jianmen_guan",
      "southwest"  : __DIR__"gudao1",
   ]));
   setup();
        set("outdoors","xinan");
}

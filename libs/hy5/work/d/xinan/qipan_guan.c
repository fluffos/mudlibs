inherit ROOM;


void create()
{
   set("short","七盘关");
   set("long",@LONG
七盘关座落于七盘岭上，是入蜀的重要关口之一。
    常言道，“蜀道难，难于上青天”。入蜀的山道狭窄崎岖，三步一关，五步
一险，稍一不留神，就会失足跌下山涧，摔得粉身碎骨。
LONG);
   set("exits",([
      "northeast"   : __DIR__"yangping_guan",
      "south"  : __DIR__"jianmen_guan",
   ]));
   setup();
        set("outdoors","xinan");
}

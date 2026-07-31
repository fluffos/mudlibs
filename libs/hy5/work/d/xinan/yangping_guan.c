inherit ROOM;


void create()
{
  set("short","阳平关");
  set("long",@LONG
阳平关南倚鸡公山，北傍嘉陵江，形势险要，自古为汉中入蜀的交通咽喉。
    常言道，“蜀道难，难于上青天”。入蜀的山道狭窄崎岖，三步一关，五步
一险，稍一不留神，就会失足跌下山涧，摔得粉身碎骨。
LONG);
  set("exits",([
    "northdown"   : __DIR__"shanlu3",
    "southwest"  : __DIR__"qipan_guan",
  ]));
  setup();
        set("outdoors","xinan");
}

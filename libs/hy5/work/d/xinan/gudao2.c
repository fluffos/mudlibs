inherit ROOM;


void create()
{
   set("short","剑阁古道");
   set("long",@LONG
常言道，“蜀道难，难于上青天”。入蜀的山道狭窄崎岖，三步一关，五步
一险，稍一不留神，就会失足跌下山涧，摔得粉身碎骨。三国时期，诸葛武候开
凿剑山，设栈道三十余里，“连天绝险，飞阁通阙”。栈道均嵌于悬崖半途，宽
不足五尺，一直是戍守要地。
LONG);
   set("exits",([
      "northup"   : __DIR__"gudao1",
      "southwest"  : __DIR__"gudao3",
   ]));
   setup();
        set("outdoors","xinan");
}

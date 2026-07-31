inherit ROOM;


void create()
{
   set("short","剑阁古道");
   set("long",@LONG
三国时期，诸葛武候开凿剑山，设栈道三十余里，“连天绝险，飞阁通阙”.
栈道均嵌于悬崖半途，宽不足五尺，一直是戍守要地。脚下是奔腾的江水，咆哮
之声响彻山谷。南面下了山是一片广阔的平原。
LONG);
   set("exits",([
      "northeast"   : __DIR__"gudao2",
     "southdown"  : __DIR__"pingyuan1",
   ]));
   setup();
        set("outdoors","xinan");
}

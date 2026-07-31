inherit ROOM;


void create()
{
   set("short","东川平原");
   set("long",@LONG
四川盆地气候温暖湿润，土地肥沃深厚；山青水秀，物产丰富，一向有“天
府之国”的美称。近年来天公作美，风调雨顺，虽然官府多勒收苛捐杂税，日子
也还很过得去。
    北面是一片高耸的群山；南面则是一片大平原。
LONG);
   set("exits",([
      "east"  : __DIR__"pingyuan1",
       ]));
   setup();
        set("outdoors","xinan");
}

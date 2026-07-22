//room: xiaojing2.c
inherit ROOM;

void create()
{
  set("short","小径");
  set("long",@LONG
突然一阵莲花的香气避人,你顺着香气看去，右面居
然是一片莲花池，左面是莲花阁！地上长满了鲜花，十分
美丽!
LONG
     );
  set("outdoors", "yihua");
  set("exits",([
      "east" : __DIR__"midao_out",
      "west" : __DIR__"lianhuachi",
     ]));

 setup();
 replace_program(ROOM);
}
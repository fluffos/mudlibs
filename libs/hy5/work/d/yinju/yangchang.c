inherit ROOM;

void create()
{
  set("short","羊肠小道");
  set("long",@LONG
这是一块从山崖向横突出的小道，长约二丈余，三面无所凭依，
除非有绝高胆色的人，普通人一般都不敢通过。
LONG);
  set("outdoors","yinju");
 set("exits",([
   "westdown"    : __DIR__"aishu",
   "eastup"      : __DIR__"doulu",
        ]));
  setup();
}
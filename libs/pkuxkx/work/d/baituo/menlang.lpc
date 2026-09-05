inherit ROOM;
void create()
{
  set("short","门廊");
  set("long",
      "这是个门廊，门廊的飞檐上挂着一串串的小铜铃，在清风中发出\n"
  "清脆动听的铃声，甚是好听，一位中年人正站在这里，不知道在想些\n"
  "什么？看他这个样子，还是别打扰他了吧！\n"
      );
  set("exits",([
      "north" : __DIR__"huayuan",
      "south" : __DIR__"liangong",
     ]));
  set("objects",([
    __DIR__"npc/guanjia" : 1,
    ]));
 set("outdoors","baituo");
 setup();
 replace_program(ROOM);
}

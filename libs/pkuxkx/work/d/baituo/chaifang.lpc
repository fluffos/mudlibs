//room: caifang.c
inherit ROOM;
void create()
{
  set("short","柴房");
  set("long",
          "这是间狭小的柴房，木柴已经快烧光了，墙角放着几把柴刀。柴\n"
      "房里只有一个孤伶伶的老人，目光呆滞，看来是个无儿无女的孤老头\n"
      "子。每天就和柴禾住在一起，真是可怜！\n"     );
  set("exits",([
      "west" : __DIR__"chufang",
     ]));
  set("objects",([
    __DIR__"npc/laocai" : 1,
    ]));
 setup();
 replace_program(ROOM);
}

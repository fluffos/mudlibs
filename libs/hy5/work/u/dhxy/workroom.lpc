// Room: /d/wizard/wizard_room.c

inherit ROOM;

void create()
{
      set("short", "水帘洞")
;
      set("long", @LONG
这里是闻名天下的水帘洞，这股水乃是桥下冲贯石桥，倒挂下来遮闭门户的,
桥边有花有树，乃是一座石房,房内有石窝、石灶、石碗、石盆、石床、石凳,
中间一块石;碣上，镌着‘花果山福地，水帘洞洞天。这里有一个巫师留言簿(board)。
LONG )
;
       set("valid_startroom", 1)
;

    set("exits", ([ /* sizeof() == 1 */
     "kj" : "/d/wizard/work",
    "down" : "/d/city/guangchang",
   ]))
;
    set("no_fight", "1")
;
   set("no_clean_up", 0)
;
   setup()
;
"/u/dhxy/board"->foo()
;
  replace_program(ROOM)
;
}

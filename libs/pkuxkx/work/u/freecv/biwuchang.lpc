// biwuchang.cg.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"比武场"NOR );
        set("long", HIY@LONG
说英雄谁是英雄。这里是扬州城里唯一的比武场，四周旗杆林立
到处都是观战的人群，不时发出一阵阵喝彩声。比武台中央站着江湖
上黑白两道皆敬畏的老侠“铁手丹心”。
LONG NOR
        );
        set("objects",([
                "/u/freecv/miejue" : 1,
               "/kungfu/class/btshan/ouyangke":1,
        ]));
        set("exits", ([ /* sizeof() == 1 */
//              "up" : "/u/freecv/wizard_room_freecv",
        ]));
       set("no_die", 1);
        set("no_clean_up", 0);
        set("outdoors", "xx" );
    set("sleep_room",1);
        setup();
	call_other("/clone/board/fight_b", "???");
}

// changed by akuma 
// 防止有人利用比武来练功

void init()
{
	object me=this_player();
	add_action("do_quit",({"quit","suicide"}));
     add_action("do_new","new");
  add_action("do_up","up");
}
int do_up()
{
  this_player()->move("/u/freecv/wizard_room_freecv");
  return 1;
}

int do_none()
{
	write("对不起，比武场中请不要练功。\n");
	return 1;
}
int do_quit()
{
          this_player()->move("/adm/room/quitroom");
        return 1;
}



int do_new()
{
    object ob;
    ob = new("/u/freecv/miejue");
    ob->move("/u/freecv/biwuchang");
    return 1;
}

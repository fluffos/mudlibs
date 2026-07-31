// shanlu9.c By River 98/09

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", YEL"山路"NOR);
    set("long", @LONG
你不觉已到了谷东自来极少人行之处，抬头见一座山峰冲天而起，正是绝
险之地的绝情峰。这山峰峰腰处有一处山崖，不知若干年代之前有人在崖上刻
了“断肠崖”三字。山崖下临深渊，自渊口下望，黑黝黝的深不见底。
LONG
        );

    set("exits", ([ 
		"westdown"  : __DIR__"shanlu5",
  		"eastup"  : __DIR__"shanlu10",                 	
    ]));

    set("outdoors", "绝情谷");
    setup();
    replace_program(ROOM);
}

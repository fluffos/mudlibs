// Room: /d/suzhou/mroom.c
//changed by dwolf
//97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED "红娘庄" NOR);
	set("long","你现在正站在" + RED "红娘庄" NOR + "里，这里是专门替人" + RED "缔结婚约" NOR + "和" + GRN "解除婚约" NOR + "的地方，\n镇里所有的夫妇都是在这里" + RED "喜结良缘" NOR + "的，就连附近镇子也有许多慕名而来的\n靠近门口的地方有一块红木雕成的" + RED "招牌" NOR +"(sign)。\n");

        set("exits", ([ 
  		"east" : __DIR__"sroad1",
	]));

        set("item_desc", ([ 
  		"sign" : RED "缔结或解除婚约。\n" NOR,
	]));

        set("objects", ([ 
 		 __DIR__"npc/meipo" : 1,
	]));

        set("no_clean_up", 0);

        setup();
}


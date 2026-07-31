
// weapony.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        
	set("coor",({2120,3900,0}));
	set("short", "兵器屋");
        set("long",
"你现在正站在兵器屋里靠近门口的地方有一块乌木雕成的招牌(sign)。\n"
);
        set("exits", ([
               	"west"          : __DIR__"nroad1",
			])  );

        set("objects", ([
                __DIR__"npc/weaponor" : 1,
 ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "招牌写著：专卖各式兵器\n";
}


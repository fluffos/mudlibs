
// marry_room.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("coor",({2000,3820,0}));
	set("short", "红娘庄");
        set("long",
"你现在正站在红娘庄里，这里是专门替人缔结婚约和解除婚约的地方，镇里所有的夫妇都是\n"
"在这里喜结良缘的，就连附近镇子也有许多慕名而来的靠近门口的地方有一块乌木雕成的招\n"
"牌(sign)。\n"
);
        set("exits", ([
                "south"          : __DIR__"wroad1", 
         ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        set("objects", ([
//                __DIR__"npc/mei_po" : 1,
        ]) );
 
        setup();

}

string look_sign(object me)
{
        return "缔结或解除婚约。\n";
}


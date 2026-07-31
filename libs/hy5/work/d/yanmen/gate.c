#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "雁门关"NOR);
        set("long",
"这里就是「大宋」军营了，一面大旗高高树起，上面书着一个斗大的\n"
"隶书「宋」字，前面不远就是宋军元帅的帐营了。这里驻守的宋军是为了\n"
"阻止辽国难下入侵的关键屏障，一旦这里被契丹攻破，那么大宋就岌岌可\n"
"危了！\n"
);

        set("no_fly", "1");
        set("exits", ([ /* sizeof() == 5 */
              "south" :   "/d/guanwai/laolongtou",
               "north" :   __DIR__"shance",
        ]));
        set("objects", ([
            "d/city/npc/wujiang" : 1,
            "d/city/npc/bing" : 5,
	]));


        setup();
        replace_program(ROOM);
}



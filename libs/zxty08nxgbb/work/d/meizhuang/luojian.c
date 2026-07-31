#include <room.h>
inherit ROOM;
void create()
{
    set("short", HIY "落剑堂" NOR);
    set("long", @LONG
一块巨大的牌坊横架在立柱之间，牌坊正上方刻着三个
斗大的字：『落剑堂』。字迹有些剥落，看上去年代久远，但
确是用真金打造的。旁边树立着一块木扁(bian)。
LONG
    );
        set("item_desc", ([
        "bian": HIY"                             
            ※※※※※※※※※※※※※※※※※※
            ※※※※　      落          ※※※※
            ※※※※                    ※※※※
            ※※※※                    ※※※※
            ※※※※        剑          ※※※※
            ※※※※                    ※※※※
            ※※※※                    ※※※※
            ※※※※        堂          ※※※※
            ※※※※※※※※※※※※※※※※※※\n"NOR,
        ]));
    set("exits", ([
        "north" : __DIR__"qianting",
        "south" : __DIR__"lang1",
    ]));
    set("no_fight", "1");
    set("objects",([
               __DIR__"npc/shilingwei" : 1,
    ]));
    setup();
//    replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
    object *inv;
    object ob;
    mapping myfam;
    int i;
    myfam = (mapping)me->query("family");
    if ((!myfam || myfam["family_name"] != "梅庄" ) && dir == "north") {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop") && (inv[i]->query("equipped")))
                { ob=present("shi lingwei", environment(me));
      if (ob && living(ob) )
                    return notify_fail("施令威拦住你说道：这位" +
                        RANK_D->query_respect(me) + "请放下兵刃。梅庄的"
                        "规矩，外客\n不得持兵刃进入。\n");
           }
    }
    return 1;
}


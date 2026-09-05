/* /d/xiakedao/biguan.c 闭关室
 * 用于自创武功
 * vast@pkuxkx 2003.3
 */

#include <ansi.h>
#include <command.h>
inherit ROOM;

void create()
{
        set("short", "闭关室");
        set("long", @LONG

    这是一间很小的房间，四周都是燃烧的蜡烛。旁边的架子上放了些
武器，中间有一块垫子，看起来好像有人在这里坐过。这里十分清静，
看来是个闭关思考的好地方。

LONG
        );
        set("createskill_room",1);
        set("no_fight", 1);

        set("exits", ([
		"east" : __DIR__"garden",
        ]));
        
	set("objects", ([
		"/clone/weapon/changjian":1,
		"/clone/weapon/changbian":1,
		"/clone/weapon/gangdao":1,
		"/clone/weapon/gangzhang":1,
		"/d/village/npc/obj/hammer":1,
		] ) );
        setup();
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i;
        if(dir == "east")
		{
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) {
                        DROP_CMD->do_drop(me, inv[i]);
        }

        message( "channel:" + "rumor",HIY + "【江湖传闻】 据说" + me->query("name") + "闭关修炼，" + HIB + "自创出一门新的武功。\n"
                        NOR, users() );
		tell_object(me,"\n\n经过多年的潜心研究，你终于开关出室了。\n");
		tell_object(me,"由于你多年闭关未踏足江湖，你的武林声望降低了。\n\n");
		me->add("repute", -10000);
		}
        return ::valid_leave(me, dir);
}

 //      shanpo.c 问天台

#include <ansi.h>

inherit ROOM;


void create()
{
        set("short",HIW"问天台"NOR);
        set("long",@LONG 
这是个方圆不过四五丈的天然平台，此处已接近大雪山顶峰，俯瞰脚下，
群山银妆素裹，白云片片环绕，令人心胸开阔，豪气顿生。传说这里接近天
界，大声说话可以直达天庭。仰头望向凌霄绝顶，就在眼前不远，可峭壁直
耸，没有路了。
LONG);
        set("exits",([
                "southdown": __DIR__"xuelu3",
                "east": __DIR__"binglinfeng"
        ]));

        setup();
}

void init()
{

        mixed *local;

        local = localtime(time() * 60);
        if (local[2] < 11 || local[2] > 13) {
	message_vision(HIW
"狂风夹着雪花劈头盖脸打了过来，吹得$N睁不开眼。突然从山崖边落下一大块积雪，$N躲闪不及正砸在头上！\n"NOR,this_player());
	message_vision(HIR"$N脚下不稳，顺着山崖跌落下去。\n"NOR,this_player());
    this_player()->move(__DIR__"xuegu");
    this_player()->unconcious();
        }
	add_action("do_climb","climb");
}

int do_climb(string arg)
  {
        object me ;
	int skill;
        me = this_player();
	skill = me->query_skill("dodge");
        if ( arg != "up" ) 
             return notify_fail("你要攀登那里？\n");

	if (me->is_fighting())
		return notify_fail("你还是先把敌人解决了吧。\n");

	if (skill<100)
		return notify_fail("风大路滑，你轻功大打折扣，看来还需要再练练才行。\n");

        if ((!present("bing gao", this_player())) || (!present("ding xie", this_player()))) 
                return notify_fail("石壁上覆盖了厚厚冰层，太滑了，根本无从借力。\n");

		message_vision("$N施展轻功，手脚并用，小心翼翼地朝绝壁爬了上去。\n", me);
		me->move(__DIR__"jueding");
		return 1;
}	


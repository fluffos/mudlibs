#include <ansi.h>

inherit WQA_ROOM;

void create()
{
	set("short", "现  实");
 	set("long", @LONG
								
    这里是现实时空。嘿嘿嘿....
LONG
	);
// Key: 1999-03-02 add
	set("objects", ([
//		__DIR__"npc/master-wqa": 1,
	]) );
// end
        ::create();
}

// Key: 1999-03-02 改为让wqa控制转换
void greeting(object ob)
{
       
        if( !ob || environment(ob) != this_object() ) return;

        message_vision( MAG "\n游戏精灵对$N说道：欢迎来到现实世界，我送你回去领取奖励吧。\n" NOR, ob);
       

        ob->set_temp("wqa's room/flag", 0);
        ob->set_temp("wqa's room/change", 0);
        ob->delete_temp("bidd");
        ob->move("/quest/game/start");


}

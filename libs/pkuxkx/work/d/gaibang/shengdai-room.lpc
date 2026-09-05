// shengdai-room
//丐帮升袋室

inherit ROOM;
#include <ansi.h>
#include <command.h>

void create()
{
        set("short","丐帮升袋室");
        set("long","这里是丐帮升袋专用的升袋室。丐帮弟子如果想升到下一级袋位，都
要到这里与相应的人比武。升袋室中间空出一块较大的范围供比武用，两边
摆了一些兵器和护具。门口的匾额上写着「"+HIC+"好好练武，天天向上"+HIG+"  洪七公"+NOR+"」
几个大字，是丐帮帮主洪七公题来鼓励弟子刻苦练武的。\n\n"
        );
        
        set("objects",([
                "/clone/armor/tiejia" : 1,
                "/clone/weapon/gangdao" : 2,
        ]));
        set("exits", ([
                "out" : "/d/city/gbandao",
        ]));
        set("no_die",1);
        set("no_task",1);

        setup();
}
int valid_leave(object me, string dir)
{
        object *inv;
		object temproom;
        int i;
        
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) {
                if( (string)inv[i]->query("name") != "青竹令")
                        DROP_CMD->do_drop(me, inv[i]);
        }
        me->delete_temp("fight_ok_" + me->query("dai"));
        if (me->query_temp("have_win") != 1)
                message( "channel:" + "chat",HIY + "【江湖公告】" + me->query("name") + "放弃挑战，" + HIB + "升袋失败。\n"
                        NOR, users() );
		if (objectp(temproom = me->query_temp("shengdai/temproom")))
		{
			inv = all_inventory(temproom);
	        for(i=0; i<sizeof(inv); i++) {
				inv[i]->move(me);
			}
			tell_object(me,"保管你物品的丐帮弟子把东西又还给了你。\n");
			"/cmds/std/wear"->main(me,"all");
			destruct(temproom);
			me->delete_temp("shengdai/temproom");
		}
        return ::valid_leave(me, dir);
}



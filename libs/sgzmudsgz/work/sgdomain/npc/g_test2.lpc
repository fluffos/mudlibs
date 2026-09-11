// g_test2.c "吴菲"
#include <mudlib.h>
#include <ansi.h>
inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
string *query_channel_list() {
    return ({ "plyr_gossip" });
}
void setup()
{
    set_name("liumei", "吴菲");
    set_gender(0);
    set_proper_name("吴菲");
    set_in_room_desc("六妹 "+MAG+"吴菲"+NOR+"(liumei)");
    set_long("她一张圆脸，淡淡的眉毛，鼻梁左侧还有一客小痣，
真是可爱之极。她穿着一件深红的外套，双手不停
的玩这一只画笔，或许是你看她让她有点紧张。");
     add_pattern("%s突然出现在一阵烟雾中。",function(){
        if ($1=="长街")
        {
                respond("say 你总算回来了，人家等了你一整天了。");
        }
        else
        {
                respond("say 你看到长街没有？");
        }
        });
}

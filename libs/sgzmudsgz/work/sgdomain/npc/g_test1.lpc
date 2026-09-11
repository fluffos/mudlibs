// g_test1.c "八妹小琛"
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
    set_name("bamei", "小琛");
    set_gender(0);
    set_proper_name("小琛");
    set_in_room_desc("八妹 "+MAG+"小琛"+NOR+"(bamei)");
    set_long("她总是微微低着头，很羞涩的看着别人。她的上
衣口袋里放着一本浅蓝色的笔记本，胸前还有一支
钢笔，大概随时都准备写些什么。");
     add_pattern("%s突然出现在一阵烟雾中。",function(){
        if ($1=="长街")
        {
                respond("say 哥，你回来了。");
        }
        else
        {
                respond("smile");
        }
        });
}

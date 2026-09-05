inherit NPC;
#include <ansi.h>

string *msg = ({
"赌局开始派彩，正确结果为，1号房：西班牙胜；2号房：西班牙为冠军，请及时兑奖！\n",
// "赌局开放中，1号房：德国 VS  西班牙，最后决赛了，欢迎大家前去投注！\n",
});

void create()
{
        set_name(HIW"赌球精灵"NOR, ({"jingling"}));
        set("gender", "男性" );
        set("age", 13);
        set("title", "赌局新闻发布官");
        set("env/invisibility",1);
        set("long", "一个可爱的小精灵。\n");
        set("combat_exp", 200);
        set("attitude", "friendly");
        set_skill("dodge", 10);
        set("per", 30);
        set("max_qi", 1500000);
        set("qi",1500000);
        set("jing",1500000);
        set("max_jing", 1500000);
        setup();
        remove_call_out("dujumsg");
        call_out("dujumsg",1);
}

void dujumsg()
{
        if (environment(this_object()))
        {
        CHANNEL_D->do_channel(this_object(), "jy", msg[random(sizeof(msg))], -1);
        remove_call_out("dujumsg");
        call_out("dujumsg",3600);
    }
}


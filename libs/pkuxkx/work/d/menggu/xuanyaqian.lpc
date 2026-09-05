// Room: menggubao.c
// created by Zine 30 Aug 2010
#include <ansi.h>
inherit ROOM;
string look_diao();
void create()
{
	set("short", "悬崖前");
	set("long", @LONG
这里是一片空地，眼前一座悬崖直插天际，巍峨高耸。
LONG
	);

	set("exits", ([
		
		"southwest" : __DIR__"shanqian",
        "northeast": __DIR__"shanqian2",
        "westup" : __DIR__"buerhan-2",
	]));
	set("objects", ([
        	//__DIR__"obj/ba" : 1,
	]));
    set("outdoors", "menggu_e");
	setup();
}

int diao_story4(object me,object tmz,object tuo,object hua)
{
    object ob=this_object();
    if (!me||environment(me)!=ob)
    {
        return 1;
    }
    if (!tmz||environment(tmz)!=ob)
    {
        return 1;
    }
    message_vision("$N微微一笑，弯硬弓，搭铁箭，嗖的一声，飞箭如电，正穿入一头黑雕的身\n中，众人齐声喝彩。\n",tmz);
    tmz->say_shang(me);
    return 1;
}

int diao_story3(object me,object tmz,object tuo,object hua)
{
    object ob=this_object();
    if (!me||environment(me)!=ob)
    {
        return 1;
    }
    if (!tmz||environment(tmz)!=ob)
    {
        return 1;
    }
    if (!hua||environment(hua)!=ob)
    {
        return 1;
    }
    message_vision("这时白雕落单，不敌十多头黑雕的围攻，虽然又啄死了一头黑雕，终于身受重伤，\n堕在崖上，众黑雕扑上去乱抓乱啄。$N与拖雷、$n都十分着急，$n\n甚至哭了出来，连叫：“爹爹，快射黑雕。”\n",me,hua);
    call_out("diao_story4",3,me,tmz,tuo,hua);
    return 1;
}
int diao_story2(object me,object tmz,object tuo,object hua)
{
    object ob=this_object();
    if (!me||environment(me)!=ob)
    {
        return 1;
    }
    if (!tmz||environment(tmz)!=ob)
    {
        return 1;
    }
    tell_room(ob,"只剩下一头黑雕，高低逃窜，被余下那头白雕逼得狼狈不堪。眼见那黑雕难逃性\n命，忽然空中怪声急唳，十多头黑雕从云中猛扑下来，齐向白雕啄去。\n");
    tmz->say_good();
    call_out("diao_story3",2+random(3),me,tmz,tuo,hua);
    return 1;
}
int diao_story1(object me,object tmz,object tuo,object hua)
{
    object ob=this_object();
    if (!me||environment(me)!=ob)
    {
        return 1;
    }
    tell_room(ob,"过了一会，又有三头黑雕也掉头急向东方飞逃，一头白雕不舍，随后赶去，片刻\n间都已飞得影踪不见。\n");
    call_out("diao_story2",2+random(3),me,tmz,tuo,hua);
    return 1;
}

int after_diao_appear(object me,object hua)
{
    object ob=this_object();
    object tmz=new(__DIR__"npc/tmz");
    object tuo=new(__DIR__"npc/tuolei");
    if (!me||environment(me)!=ob)
    {
        return 1;
    }
    tmz->set("owner",me);
    tuo->set("owner",me);
    tmz->move(ob);
    tuo->move(ob);
    message_vision("只见有十七八头黑雕围攻那对白雕，双方互啄，只打得毛羽纷飞。白雕身形既\n大，嘴爪又极厉害，一头黑雕闪避稍慢，被一头白雕在头顶正中一啄，立即毙命，\n从半空中翻将下来，落在$N马前。\n",hua);
    call_out("diao_story1",2+random(2),me,tmz,tuo,hua);
    return 1;
}

int diao_appear(object me,object hua)
{
    set("long","这里是一片空地，眼前一座悬崖直插天际，巍峨高耸。有几只大雕(diao)在打架。\n");
    delete_temp("mixed_long");
    message_vision("$N道：快看快看！\n",hua);
    tell_object(me,"你心道：看就看"+HIR+"(look diao)"+NOR+"吧。有啥好奇怪的。\n");
    message_vision("$N看到一行人从远处走了过来。\n",me);
    set("item_desc", ([
		"diao" : (:look_diao:), 
	]));
    return 1;
}

string look_diao()
{
    object hua,me=this_player();
    if (!me->query_temp("shediaoquest/shediao_step4"))
    {
        return "悬崖上住有一对白雕，身形奇巨，比之常雕大出倍许，实是异种。\n";
    }
    else
    {
        if (!hua=present("huazheng gongzhu",this_object()))
        {
            return "华筝都已经走了，你还看什么看？\n";
        }
        if (hua->query("quest_owner")!=me)
        {
            return "崖上住有一对白雕，身形奇巨，比之常雕大出倍许，实是异种。\n";
        }
        me->delete_temp("shediaoquest/shediao_step4",1);
        me->set_temp("shediaoquest/shediao_step5",1);
        this_object()->delete("item_desc");
        this_object()->set("long","这里是一片空地，眼前一座悬崖直插天际，巍峨高耸。\n");
        this_object()->delete_temp("mixed_long");
        call_out("after_diao_appear",1,me,hua);
        return "崖上住有一对白雕，身形奇巨，比之常雕大出倍许，实是异种。雕羽白色本已稀\n有，而雕身如此庞大，蒙古族中纵是年老之人，也说从所未见，都说是一对“神\n鸟”，愚鲁妇人竟有向之膜拜的。\n";
    }
}

void init()
{
    object me=this_player();
    object hua;
    if (!hua=present("huazheng gongzhu",this_object()))
    {
        return;
    }
    if (!me->query_temp("shediaoquest/shediao_step3"))
    {
        return;
    }
    me->delete_temp("shediaoquest/shediao_step3");
    me->set_temp("shediaoquest/shediao_step4",1);
    diao_appear(me,hua);
    return;
}

int valid_leave(object me,string dir)
{
    if (dir=="westup"&&me->query("id")!="zine")
    {
        return notify_fail("悬崖几乎笔直，你想走上去？？\n");
    }
    return ::valid_leave(me,dir);
}
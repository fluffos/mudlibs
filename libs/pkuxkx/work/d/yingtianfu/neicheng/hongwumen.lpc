//城门
// By Zine 23 Nov 2010
#include <title.h>
inherit ROOM;
//#include "/d/yingtianfu/neicheng/npc/promote.h"
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "洪武门");
        set("long", "这里皇城的南门，很多御林军在巡弋，南面通向正阳门，门上贴出了一张告\n示(gaoshi)。\n");
        set("exits", ([
        
                "north" : __DIR__"damingmen",
                "south" : __DIR__"yudao3",
                "west" : __DIR__"wu_zhifang",
                "east" : __DIR__"wen_zhifang",
        ]));
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	    ]));
        set("no_reset",1);
        set("no_clean_up", 1);
        set("bang",0);
        set("jinji",0);
        set("event",0);
        set("objects", ([
                __DIR__"npc/bing1" : 2,
        ]));
        set("outdoors", "yingtianfu");
        setup();
       // "/clone/board/daming_b"->foo();
}

/*void init()
{
    add_action("do_jie","jie");
    add_action("do_fuming","fuming");
    add_action("do_jinji","jinji");
}

int do_jinji()
{
    object ob=this_object();
    object me=this_player();
    if (!ob->query("jinji"))
    {
        return notify_fail("还没选拔结束你就来晋级？\n");
    }
    if (me->query("id")!=ob->query("leastpl"))
    {
        return notify_fail("哪里来的山野村夫，居然敢冒名晋级。\n");
    }
    else
    {
		me->set("mingpin",8);
		me->set("ming/pro","武");
		position_me(me);
		message_vision("几个小吏跑了出来，宣读吏部行文：$N考验合格，获封"+me->query("title")+"。\n"NOR);
		message("chat",HIW"【大明】"+me->query("name")+"考验合格，获封"+me->query("title")+"\n"NOR,users());
		return 1;
    }
}

int do_fuming()
{
    object me=this_player();
    object ob=this_object();
    object gaoshi;
    if (!me->query_temp("mingtask/entry/start"))
    {
        return notify_fail("你什么时候揭下的告示？\n");
    }
    if (me->query("mingpin"))
    {
        return notify_fail("朝廷为了边事才特简拔官员，大人就不要凑热闹了。\n");
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (!present("gao shi",me))
    {
        return notify_fail("你揭去的告示呢？\n");
    }
    gaoshi=present("gao shi",me);
    if (gaoshi->query("owner")!=me->query("id"))
    {
        return notify_fail("你的告示哪里捡的？\n");
    }
    if (me->query("family/family_name")=="朝廷")
    {
        tell_object(me,"难道你就是传说中的奸细？\n");
        return 1;
    }
    if ((int)(me->query("jobs/completed/huyidao")-me->query_temp("mingtask/entry/huyidao"))>=4
        &&(int)(me->query("jobs/completed/hubiao")-me->query_temp("mingtask/entry/hubiao"))>=4
        &&(int)(me->query("jobs/completed/xiaofeng")+me->query("jobs/completed/task")-me->query_temp("mingtask/entry/xiaofeng")-me->query_temp("mingtask/entry/task"))>=2
        &&(int)(me->query("newjobs/completed/pyh")-me->query_temp("mingtask/entry/pyh"))>=1
        &&(int)(me->query("newjobs/completed/hyw")-me->query_temp("mingtask/entry/hyw"))>=6
        &&time()-(int)me->query_temp("mingtask/entry/start")>0)
        {
            message_vision("$N得意洋洋地回来复命。\n",me);
            tell_object(me,"巡城士兵接过了你手中的告示。\n");
            destruct(gaoshi);
            tell_object(me,"士兵道：你就回去等消息吧。\n");
            tell_object(me,"士兵道：试炼结果将在两小时后公布。\n");
            if ((int)(3600+(int)me->query_temp("mingtask/entry/start")-time())>ob->query("leasttime"))
            {
                ob->set("leasttime",(int)(3600+(int)me->query_temp("mingtask/entry/start")-time()));
                ob->set("leastpl",me->query("id"));
                ob->set("leastperson",me->query("name"));
            }
            return 1;
        }
    else
    {
        return notify_fail("你的试炼任务失败了。\n");
    }
}

int do_jie(string arg)
{
    object me=this_player();
    object ob=this_object();
    object gaoshi;
    if (!arg||(arg!="gaoshi" && arg!="告示"))
    {
        return notify_fail("你要揭什么？\n");
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    else
    {
        if (me->query("mingpin"))
        {
            return notify_fail("朝廷为了边事才特简拔官员，大人就不要凑热闹了。\n");
        }
        if (me->query("zhusantimes")<15)
        {
            return notify_fail("朝廷这次需要的是孔武之士，你先去老夫子那里证明一下自己的实力吧。\n");
        }
        if (me->query("family/family_name")=="朝廷")
        {
            return notify_fail("大胆奸细，朝廷这次简拔官员就是为了对付你们女真人。\n");
        }
        if (!ob->query("event"))
        {
            return notify_fail("这次简拔已经结束了，你下次趁早吧。\n");
        }
        if ((int)ob->query("bang")<1)
        {
            return notify_fail("所有告示都已经被人揭完了。\n");
        }
        if (me->query_temp("mingtask/entry/bang"))
        {
            return notify_fail("你已经拿过了，留点机会给别人吧。\n");
        }
        else
        {
            message_vision("$N从围观人群中挤出来，大喊着：“让我试试。”揭下了一张告示。\n",me);
            ob->add("bang",-1);
            me->set_temp("mingtask/entry/huyidao",me->query("jobs/completed/huyidao"));
            me->set_temp("mingtask/entry/hubiao",me->query("jobs/completed/hubiao"));
            me->set_temp("mingtask/entry/xiaofeng",me->query("jobs/completed/xiaofeng"));
            me->set_temp("mingtask/entry/task",me->query("jobs/completed/task"));
            me->set_temp("mingtask/entry/pyh",me->query("newjobs/completed/pyh"));
            me->set_temp("mingtask/entry/hyw",me->query("newjobs/completed/hyw"));
            me->set_temp("mingtask/entry/start",time());
            me->set_temp("mingtask/entry/bang",1);
            gaoshi=new(__DIR__"obj/gaoshi");
            gaoshi->set("owner",me->query("id"));
            gaoshi->move(me);
            return 1;
        }
    }
}

string look_gaoshi()
{
    object ob=this_object();
    if (ob->query("event"))
    {
        if ((int)ob->query("bang")>=1)
        {
            return "告示上写着：边事危急，非常之时行非常之事，大明特简拔官员。还有"+chinese_number(ob->query("bang"))+"张告示可以撕(jie)。\n";
        }
        else
        {
            return "告示上写着：边事危急，非常之时行非常之事，大明特简拔官员。可惜所有的告示都被人揭掉了。\n";
        }
    }
    else
    {
	    return "告示上写着：边事危急，非常之时行非常之事，大明特简拔官员。\n";
    }
}
*/
int valid_leave(object me,string dir)
{
    object* inv;    
    int i;
    inv = deep_inventory(me);
	if (dir=="north"||dir=="west"||dir=="east")
    {
        if (!me->query("mingpin")&&!me->query("ming/tj/pin")&& !present("entry permit",me))
        {
            return notify_fail("你不是大明官员，皇城岂可随意进入。\n");
        }
        if (me->query("mingpin")>6)
        {
            return notify_fail("你的官职太低，皇城岂可随意进入。\n");
        }
        for(i=sizeof(inv)-1; i>=0; i--)
            {
                if(userp(inv[i]))
                {
                    me->unconcious();
                    return notify_fail(HIR"竟敢带外人入宫，下次再犯，定斩不赦！”\n"NOR);
                }
            }
    }
	if ((dir=="west"||dir=="east")&&!userp(me))
	{
		return notify_fail("\n");
	}
	return ::valid_leave(me, dir);
}

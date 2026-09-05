//yading.c	黑木崖顶
//by bing
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short",WHT"黑狱"NOR);
	set("long",@LONG 
这里是一间漆黑潮湿的监狱，不知关着什么人。
LONG
	);
	set("exits", ([
		"out"	: __DIR__"guodao1",
	]));
    set("no_task",1);
    set("is_prison",1);
	set("objects", ([
                __DIR__"npc/prisoner2": 1,
        ]));
	/*set("item_desc",([
  	"zhu lou" : "这是一个竹子编成的大篓，大概可以装得下一个人，上面连着一根粗绳子。",
  	"lou" : "这是一个竹子编成的大篓，大概可以装得下一个人，上面连着一根粗绳子。", 	   ]));
*/
	
	setup();
}

int do_xiuxi()
{
    object me=this_player();
	if (me->query_temp("rynewbiejob/prison/action"))
	{
		tell_object(me,"稍微休息一下吧。\n");
		return 1;
	}
    if (me->query_temp("rynewbiejob/prison/start")!=3)
    {
        return 0;
    }
    tell_object(me,HIG+"你坐在地上，大口喘着粗气。\n"+NOR+"犯人一声不吭地看着你。\n");
    if (me->query_temp("rynewbiejob/prison/kaoda")!=3)
    {
        me->add_temp("rynewbiejob/prison/kd_degree",-1);
    }
    me->set_temp("rynewbiejob/prison/action",1);
    return 1;
}

int do_linshui()
{
    object me=this_player();
	if (me->query_temp("rynewbiejob/prison/action"))
	{
		tell_object(me,"稍微休息一下吧。\n");
		return 1;
	}
    if (me->query_temp("rynewbiejob/prison/start")!=3)
    {
        return 0;
    }
    tell_object(me,HIW+"你举起一盆冷水，浇向犯人。\n"+NOR+"犯人一个激灵，醒了过来。\n");
    if (me->query_temp("rynewbiejob/prison/kaoda")!=2)
    {
        me->add_temp("rynewbiejob/prison/kd_degree",-1);
    }
    else
    {
        me->add_temp("rynewbiejob/prison/kd_degree",1);
    }
	me->set_temp("rynewbiejob/prison/action",1);
    return 1;
}

int do_zhongda()
{
    object me=this_player();
	if (me->query_temp("rynewbiejob/prison/action"))
	{
		tell_object(me,"稍微休息一下吧。\n");
		return 1;
	}
    if (me->query_temp("rynewbiejob/prison/start")!=3)
    {
        return 0;
    }
    tell_object(me,HIR+"你使出浑身力气，狠狠抽打犯人。\n"+NOR+"犯人痛苦地呻吟了一声。\n");
    if (me->query_temp("rynewbiejob/prison/kaoda")!=1)
    {
        me->add_temp("rynewbiejob/prison/kd_degree",-1);
    }
    else
    {
        me->add_temp("rynewbiejob/prison/kd_degree",1);
    }
	me->set_temp("rynewbiejob/prison/action",1);
    return 1;
}
int kaoda(object me)
{
    int n=random(1000);
    string *kd1=({"犯人恶狠狠看了你一眼，并不屈服。\n","犯人道：再重点，给爷爷挠痒痒呢？\n","犯人悠闲地哼起了小曲。\n"});
    string *kd2=({"犯人快晕了，想办法让他清醒点。\n","犯人已经没有知觉了，需要清醒一下。\n","犯人竟然睡着了，淋他一头水让他清醒点。\n"});
    string *kd3=({"犯人没什么，你自己倒是打累了。\n","犯人笑嘻嘻的望着你，你想想，等会再收拾他。\n","犯人和你都累了，歇会再打吧。\n"});
    if (!me)
    {
        return 1;
    }
    if (base_name(environment(me))!="/d/riyuejiao/prison")
    {
        tell_object(me,"你跑哪去了？\n");
        return 1;
    }
    if (me->query_temp("rynewbiejob/prison/kd_degree")>12+random(3))
    {
        tell_object(me,"犯人颤声道：我受不了了，什么都招啊！\n你可以回狱卒那里看看还有什么其他事。\n");
        me->delete_temp("rynewbiejob/prison/kd_degree");
        me->delete_temp("rynewbiejob/prison/kaoda");
        me->delete_temp("rynewbiejob/prison/room");
        me->delete_temp("rynewbiejob/prison/start");
        me->delete_temp("rynewbiejob/prison/startkaoda");
        me->add_temp("rynewbiejob/prison/degree",1);
        return 1;
    }
    if (n>666)
    {
        tell_object(me,kd1[random(sizeof(kd1))]);
        me->set_temp("rynewbiejob/prison/kaoda",1);
        call_out("kaoda",9+random(3),me);
		me->delete_temp("rynewbiejob/prison/action");
        return 1;
    }
    else if (n>333)
    {
        tell_object(me,kd2[random(sizeof(kd2))]);
        me->set_temp("rynewbiejob/prison/kaoda",2);
        call_out("kaoda",9+random(3),me);
		me->delete_temp("rynewbiejob/prison/action");
        return 1;
    }
    else
    {
        tell_object(me,kd3[random(sizeof(kd3))]);
        me->set_temp("rynewbiejob/prison/kaoda",3);
        call_out("kaoda",9+random(3),me);
		me->delete_temp("rynewbiejob/prison/action");
        return 1;
    }

}
int do_kaoda()
{
    object me=this_player();
    object *all=all_inventory(me);
    
    if (me->query("family/family_name")!="日月神教")
    {
        tell_object(me,"狱卒没让你去送饭啊？\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query_temp("rynewbiejob/prison/start")!=3)
    {
        tell_object(me,"狱卒没让你去拷打犯人啊？\n");
        return 1;
    }
    if (me->query_temp("rynewbiejob/prison/startkaoda"))
    {
        tell_object(me,"你已经开始拷打犯人了。\n");
        return 1;
    }
    if (me->query_temp("rynewbiejob/prison/room")!=me->query_temp("rynewbiejob/prison/cur_room"))
    {
        tell_object(me,"狱卒让你拷打的犯人不在这个房间。\n");
    }
    else
    {
        me->set_temp("rynewbiejob/prison/startkaoda",1);
        tell_object(me,"马上你要开始拷问犯人了，注意别弄死人了。你可以选择拷打：“zhongda”，淋水：“linshui”或者休息：“xiuxi”\n");
        call_out("kaoda",3,me);
    }
    return 1;
}

int do_songfan()
{
    object me=this_player();
    object *all=all_inventory(me);
    object shihe;
    int i;
    if (me->query("family/family_name")!="日月神教")
    {
        tell_object(me,"狱卒没让你去送饭啊？\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query_temp("rynewbiejob/prison/start")!=1)
    {
        tell_object(me,"狱卒没让你去送饭啊？\n");
        return 1;
    }
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("is_shihe"))
        {
            shihe=all[i];
        }
    }
    if (!shihe)
    {
        tell_object(me,"你身上没有食盒，怎么送饭啊？\n");
        return 1;
    }
    destruct(shihe);
    message_vision("$N把身上的食盒交给这里的囚犯。\n囚犯狼吞虎咽的吃完了食盒里的饭菜。\n",me);
    if (me->query_temp("rynewbiejob/prison/room")!=me->query_temp("rynewbiejob/prison/cur_room"))
    {
        tell_object(me,"可惜你送错了狱卒交代你的房间。\n");
    }
    else
    {
        tell_object(me,"可以去看看狱卒有没有其他事情需要你做。\n");
        me->delete_temp("rynewbiejob/prison/room");
        me->delete_temp("rynewbiejob/prison/start");
        me->add_temp("rynewbiejob/prison/degree",1);

    }
    return 1;
}

void init()
{
    object me=this_player();
    add_action("do_songfan","songfan");
    add_action("do_kaoda","kaoda");
    add_action("do_zhongda","zhongda");
    add_action("do_linshui","linshui");
    add_action("do_xiuxi","xiuxi");
    if (me->query_temp("rynewbiejob/prison/lastroom")=="/d/riyuejiao/guodao1")
    {
        if (me->query_temp("rynewbiejob/prison/lastdir")=="west")
        {
            me->set_temp("rynewbiejob/prison/cur_room","子");
        }
        if (me->query_temp("rynewbiejob/prison/lastdir")=="east")
        {
            me->set_temp("rynewbiejob/prison/cur_room","丑");
        }
    }
    if (me->query_temp("rynewbiejob/prison/lastroom")=="/d/riyuejiao/guodao3")
    {
        if (me->query_temp("rynewbiejob/prison/lastdir")=="west")
        {
            me->set_temp("rynewbiejob/prison/cur_room","寅");
        }
        if (me->query_temp("rynewbiejob/prison/lastdir")=="east")
        {
            me->set_temp("rynewbiejob/prison/cur_room","卯");
        }
    }
    if (me->query_temp("rynewbiejob/prison/lastroom")=="/d/riyuejiao/guodaoa")
    {
        if (me->query_temp("rynewbiejob/prison/lastdir")=="north")
        {
            me->set_temp("rynewbiejob/prison/cur_room","辰");
        }
        if (me->query_temp("rynewbiejob/prison/lastdir")=="south")
        {
            me->set_temp("rynewbiejob/prison/cur_room","巳");
        }
    }
    if (me->query_temp("rynewbiejob/prison/lastroom")=="/d/riyuejiao/guodaob")
    {
        if (me->query_temp("rynewbiejob/prison/lastdir")=="north")
        {
            me->set_temp("rynewbiejob/prison/cur_room","午");
        }
        if (me->query_temp("rynewbiejob/prison/lastdir")=="south")
        {
            me->set_temp("rynewbiejob/prison/cur_room","未");
        }
    }
    if (me->query_temp("rynewbiejob/prison/lastroom")=="/d/riyuejiao/guodaoc")
    {
        if (me->query_temp("rynewbiejob/prison/lastdir")=="north")
        {
            me->set_temp("rynewbiejob/prison/cur_room","申");
        }
        if (me->query_temp("rynewbiejob/prison/lastdir")=="south")
        {
            me->set_temp("rynewbiejob/prison/cur_room","酉");
        }
    }
    if (me->query_temp("rynewbiejob/prison/lastroom")=="/d/riyuejiao/guodaod")
    {
        if (me->query_temp("rynewbiejob/prison/lastdir")=="north")
        {
            me->set_temp("rynewbiejob/prison/cur_room","戌");
        }
        if (me->query_temp("rynewbiejob/prison/lastdir")=="south")
        {
            me->set_temp("rynewbiejob/prison/cur_room","亥");
        }
    }
}

int valid_leave(object me,string dir)
{
    object exit;
    if (!me->query_temp("rynewbiejob/prison"))
    {
        return notify_fail("你在这里叫天不应，叫地不灵的。\n");
    }
    if (me->query_temp("rynewbiejob/prison/lastroom"))
    {
        exit=load_object(me->query_temp("rynewbiejob/prison/lastroom"));
        me->move(exit);
        return notify_fail("你向外离开了黑狱。\n");
    }
    return notify_fail("你在这里叫天不应，叫地不灵的，出不去咯。\n");
}
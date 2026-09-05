// 空地
// by zine Oct 6 2010

inherit ROOM;
#include <ansi.h>
#include <localtime.h>
int adv();
void create()
{
	set("short", "空地");
	set("long", @LONG
只见中间老大一块空地，地下插了一面锦旗(flag)，白底红花，绣着『比武
招亲』四个金字，旗下两人正自拳来脚去的得热闹。你要在往前挤(ji)一点才能
看清。
LONG
	);
	set("exits", ([ 
		"out" : __DIR__"changjie",
	]));
	set("item_desc", ([
		"flag" : "一面大旗，上面写着：比武招亲。\n", 
	]));
    set("no_task",1);
	set("objects", ([
				__DIR__"npc/liumang" : random(3),
                __DIR__"npc/munianci" : 1,
				__DIR__"npc/muyi" : 1,
				__DIR__"npc/dahan" : 1,
        ]));

	setup();
    call_out("adv",1);
}

int adv()
{
    mixed* timeinfos= localtime(time());
    int minute = timeinfos[LT_MIN];
    if (minute>10&&minute<=41)
    {
        CHANNEL_D->do_channel(this_object(), "jh", HIW"木易父女来到北京，比武招亲，以待贤婿。", -1);
    }
    call_out("adv",1800);
    return 1;
}

void init()
{
    object changjie=load_object(__DIR__"changjie");
    object room=this_object();
    object me=this_player();
	add_action("do_ji", ({ "ji" }));
    if (userp(me) && !room->query("blockdir"))
    {
        call_other(changjie,"blockdir");
        room->set("blockdir",1);
        
    }
    remove_call_out("reopen");
    call_out("reopen",240);
}



int do_ji()
{
	object me=this_player();
    if (me->query_temp("shediaoquest/jied"))
    {
        tell_object(me,RED"你已经很靠前了，还要往哪里挤？\n"NOR);
        return 1;
    }
    else if ((int)me->query("level")<16)
    {
        tell_object(me,WHT"似乎好戏已经散场了。\n"NOR);
        return 1;
    }
    else
    {
        if (present("da han", environment(me))&& present("hongyi nvzi", environment(me)))
        {
            tell_object(me,"你终于挤到了最前面，这时。。。\n");
            message_vision(CYN"拆斗数招，那红衣少女卖个破绽，上盘露空。\n"NOR,me);
            message_vision(WHT"那大汉大喜，一招“双蛟出洞”，双拳呼地出，直取对方胸口。\n"NOR,me);
            remove_call_out("scene1");
            me->set_temp("shediaoquest/jied",1);
            call_out("scene1",2,me);
            return 1;
        }
        else
        {
            tell_object(me,WHT"似乎好戏已经散场了。\n"NOR);
            return 1;
        }
    }
}

int reopen()
{
    int i;
    object* all=all_inventory(this_object());
    object changjie=find_object(__DIR__"changjie");
    for (i=0;i<sizeof(all);i++)
    {
        if (!userp(all[i]))
        {
            destruct(all[i]);
        }
        else
        {
            
            all[i]->move(__DIR__"changjie");
            tell_object(all[i],HIC"人群渐渐散去，你也随着人群向外走去，再也没什么好戏可以看了。\n"NOR);
        }
    }
    
    this_object()->delete("blockdir");
    call_other(changjie,"reopen");
    
}

int scene1(object me)
{
	int i;
	object dahan;
	object* all=all_inventory(this_object());
	message_vision(CYN"那少女身形略偏，当即滑开，左臂横扫，蓬的一声，大汉背上中招。\n"NOR,me);
	message_vision(WHT"那大汉收足不住，向前直跌出去，只跌锝灰头土脸，爬起身来，满脸羞惭，挤入人丛中去了。\n"NOR,me);
	for (i=0;i<sizeof(all);i++)
	{
		if (all[i]->query("id")=="da han")
		{
			dahan=all[i];
			destruct(dahan);
		}
	}
	remove_call_out("scene2");
	call_out("scene2",5,me);
	return 1;
}

int scene2(object me)
{
	int i;
	object muyi;
	object munianci;
	object* all=all_inventory(this_object());
    
	for (i=0;i<sizeof(all);i++)
	{
		if (all[i]->query("id")=="mu yi")
		{
			muyi=all[i];
		}
	}
    if (!muyi)
    {
        return 1;
    }
    message_vision(HIG"一个中年汉子走了出来，向在场众人一一抱拳行礼。\n"NOR,me);
    call_other(muyi,"intro");
	for (i=0;i<sizeof(all);i++)
	{
		if (all[i]->query("id")=="hongyi nvzi")
		{
			munianci=all[i];
			munianci->set("name","穆念慈");
		}
	}
	remove_call_out("scene3");
	call_out("scene3",8,me,munianci);
	return 1;
}

int scene3(object me,object munianci)
{
	object kang=new(__DIR__"npc/wanyankang");
	message_vision(HIW"忽听锝鸾铃响动，数十名健仆拥着一个少年公子驰马而来。\n"NOR,me);
    if (kang)
	kang->move(this_object());
    call_other(kang,"visit");
    if (present("wanyan kang", this_object())&& present("hongyi nvzi", this_object()))
    {
        call_other(kang,"bwzq");
        call_other(munianci,"blush");
        munianci->fight_ob(kang);
        kang->fight_ob(munianci);
        remove_call_out("scene4");
        call_out("scene4",10,me,munianci);
        return 1;
    }
    else
    {
        call_other(kang,"chit");
        return 1;
    }
}

int scene4(object me,object munianci)
{
	munianci->set("qi",2000);
	remove_call_out("scene5");
	call_out("scene5",3,me);
	return 1;
}

int scene5(object me)
{
	message_vision(HIM"穆念慈被完颜康拦在怀里。\n"NOR,me);
	message_vision(HIM"穆念慈急了，飞脚向完颜康太阳穴踢去，要叫彵不能不放开了。\n"NOR,me);
	message_vision(HIW"完颜康右臂松脱，举手一挡，反腕钩出，又已拿住了她踢过来的右脚。\n"NOR,me);
	message_vision(HIM"穆念慈坐在地下，含羞低头，摸着白布的袜子。\n"NOR,me);
	message_vision(HIW"完颜康转身想离开，却被你拦住了。\n"NOR,me);
	tell_object(me,"你觉得完颜康的行为有违侠义正道，是"+HIW+"不对"+NOR+"的，准备质问与他。\n");
	me->set_temp("shediaoquest/askkang1",1);
	return 1;
}
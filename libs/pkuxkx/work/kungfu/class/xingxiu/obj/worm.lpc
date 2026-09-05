
inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_dingwei", "dingwei");
		add_action("do_zhao", "xunzhao");
}

void create()
{
        set_name("一罐"HIB"寻香虫"NOR, ({ "xunxiang chong","chong","worm"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "罐");
                set("long", "这是一个小罐子，里面装了几只寻香虫，可以循着神木王鼎的特殊香气定位(dingwei)它的位置。\n"
				+"找到目的地之后，还可以让寻香虫帮你寻找(xunzhao)它。\n");
                set("value", 0);
				set("no_give", 1);
				set("no_steal", 1);
				set("use_times", 3);
                set("material", "wood");
        }
        setup();
}

int do_zhao(string arg)
{
    object me = this_player();
	if (me->query_busy())
		return notify_fail("你正忙着呢，先忙完手头的事情再说吧！\n");
	tell_object(me, HIC"你按照寻香虫的提示，趴在地上疯狂地寻找起来……\n"NOR);	
	me->start_busy(5);
	remove_call_out("find_result");
	call_out("find_result",4,me);
	return 1;
}
 
void find_result(object me)
 {
 	object ob = this_object();
	object here, box;
	me->start_busy(0);
	here = environment(me);
	if (!objectp(here))
	{
		tell_object(me, HIY"你找了半天，啥也没找到，只好失望地站了起来。\n"NOR);
		return;
	}
	if ((time()-me->query("bingcan-duzhang/last_shenmuding"))<7200)
	{
		tell_object(me, HIY"你疯狂地找了半天，啥也没找到。莫非寻香虫给的提示是错的？你气得想把罐子给砸了……\n"NOR);
		return;
	}
	if (COLOR_D->uncolor(here->query("short")) == ob->query("shenmuding_place_short")
		&& TASK_D->place_belong(here) == ob->query("shenmuding_place_belong"))
	{
		box=new(__DIR__"shenmuding");
		if (objectp(box))
		{
			box->set("owner", me->query("id"));
			box->move(me);
			tell_object(me, HIW"你忽然眼前一亮：神木王鼎！赶紧一把揣到怀里，生怕被人发现了。\n"NOR);
			tell_object(me, HIB"在碰到神木王鼎的一瞬间，寻香虫的罐子忽然爆裂开来，罐底几只小虫趁机一哄而散。\n"NOR);
			me->set("bingcan-duzhang/last_shenmuding",time());
			destruct(ob);
			return ;
		}
		else 
			tell_object(me, HIR"你发现有点不对劲了，可是又说不上来哪有问题，还是赶紧向巫师求助吧。\n"NOR);
	}
	else
		tell_object(me, HIY"你找了半天，啥也没找到，只好失望地站了起来。\n"NOR);	
 }
 
int do_dingwei(string arg)
{
	string *biaodian=({
		"，",
		"。",
		"“",
		"”",
		"！",
		"？",
		"（",
		"）",
		"：",
		"；",
		"、",
		"《",
		"》",
		"〉",
		"〈",
		"’",
		"‘",
	});
    object me = this_player();
	object ob = this_object();
	object where;
	string msg, des, *exits, *ch=({});
	int i, tmp;
	if (ob->query("belong_user")!= me->query("id"))
		return notify_fail("寻香虫懒洋洋地躲在罐子里不肯动。\n");
	if (ob->query("use_times")<=0)
		return notify_fail("罐子里的寻香虫被你烦透了，再也不肯飞出来了。\n");
	ob->add("use_times", -1);
	if (!objectp(where = load_object(ob->query("shenmuding_place"))))
		return notify_fail("一只寻香虫从罐子里爬了出来，在空中漫无目的地飞了两圈，啪叽一下掉在地上不动了。\n");
	tell_object(me, HIB"你打开了罐子，一只寻香虫飞了出来，在空中飞舞着……\n"NOR);
	msg = HIY"你仔细辨认了一下，它好像在告诉你：\n"HIC"神木王鼎位于一个";
	i = sizeof(where->query("exits"));
	if (i<=0) msg+="没有出口的地方，";
	else if (i==1) msg+="只有一个出口的地方，";
	else 
	{
		exits = keys(where->query("exits"));
		msg+="有"+chinese_number(i)+"个出口的地方，其中一个是"+exits[random(i)]+"，";
	}
	des=where->query("long");
	if(sizeof(des)!=0) 
	{
		for(i=0;i<sizeof(des);i++)
		{
			if(des[i]>160&&des[i]<255)
			{
				if(member_array(des[i..i+1],biaodian)==-1)
				{
					ch+=({des[i..i+1]});
				}
				i++;
			}
		}
	}
	if(sizeof(ch)==0) msg+="那地方没有什么可描述的。\n";
	else if(sizeof(ch)==1) 
		msg+="那地方说起来只有一个字："+ch[0]+"。\n";
	else		
	{		
		tmp=random(sizeof(ch));
		if(tmp+1==sizeof(ch)) tmp=0;
		msg+="那地方说起来包含“"+ch[tmp]+ch[tmp+1]+"”";
		tmp+=random(5)+1;
		if(tmp>=sizeof(ch)-1) tmp=0;
		msg+="和“"+ch[tmp]+ch[tmp+1]+"”这些字词。\n";		
	}
	msg+=HIR"          快去那里找到它吧！\n\n"NOR;
	tell_object(me, msg);
	return 1;
}


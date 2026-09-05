#include <ansi.h>
#include <title.h>
void init()
{
	add_action("do_suikao","mokan");
}
int baoxiao_require(object me,int point)
{
	float *index=({1.3,1.25,1.2,1.18,1.15,1.1,1.08,1.05});
	int pin=DASONG_D->get_my_pin(me);
	if (pin<=0||pin>=9)
	return point;
	return to_int(to_float(point)*index[pin-1]);
}
int do_suikao()
{
    object me=this_player(),*ob;
    int age=me->query("mud_age");
    string zhengji,renmai,title,title_place;
    int p;
    if (!DASONG_D->get_my_pin(me)||!me->query("song/pro"))
    return 0;
	/*if (DASONG_D->get_my_pin(me)==1)
	{
		tell_object(me,"一品大员无需磨勘。\n");
        return 1;
	}*/
	if (me->query("song/pro")!=this_object()->query("profession"))
	return notify_fail("你似乎不应该在这里完成磨勘。\n");
	if (DASONG_D->get_my_pin(me)<this_object()->query("mokan_high")||DASONG_D->get_my_pin(me)>this_object()->query("mokan_low"))
	return notify_fail("你似乎不应该在这里完成磨勘。\n");
    if (!me->query("song/suikao/time"))
    {
        command("tell "+me->query("id")+" 第一次接受磨勘吗？朝廷其实对官员第一次都不算苛责，你取得了两个“中”。");
        command("tell "+me->query("id")+" 磨勘分每年的政绩和报效国家部门两个部分。");
        command("tell "+me->query("id")+" 政绩就是大宋的功勋度，现在正和蒙古人打着仗，在不同的部门报效一些东西肯定有收获的。");
        command("tell "+me->query("id")+" 记住，有钱能使鬼推磨，如果是古玩字画类效果也可能不错。");
        me->set("song/suikao/time",age);
        return 1;
    }
    if (me->query("mud_age")-me->query("song/suikao/time")<86400)
    {
        tell_object(me,"你今年已经接受过磨勘了。\n");
        return 1;
    }
    me->set("song/suikao/time",age);
    if (me->query("song/suikao/renmaipoint")>baoxiao_require(me,5000000)||DASONG_D->identification(me,({"翰林学士","知制诰","翰林学士承旨","御史大夫","御史中丞",})))
    {
        renmai="优";
        me->set("song/suikao/r_renmai",3);
    }
    else if (me->query("song/suikao/renmaipoint")>baoxiao_require(me,2500000))
    {
        renmai="中";
        me->set("song/suikao/r_renmai",2);
    }
    else 
    {
        renmai="差";
        me->set("song/suikao/r_renmai",1);
    }
	me->set("song/suikao/renmaipoint",0);
    if (me->query("song/credit")-me->query("song/suikao/zhengji/lastpoint")>8&&me->query("song/credit")-me->query("song/suikao/zhengji/lastpoint")>(9-DASONG_D->get_my_pin(me))*5)
    {
        zhengji="优";
        me->set("song/suikao/z_zhengji",3);
    }
    else if (me->query("song/credit")-me->query("song/suikao/zhengji/lastpoint")>8&&me->query("song/credit")-me->query("song/suikao/zhengji/lastpoint")>(9-DASONG_D->get_my_pin(me))*2)
    {
        zhengji="中";
        me->set("song/suikao/z_zhengji",2);
    }
    else
    {
        zhengji="差";
        me->set("song/suikao/z_zhengji",1);
    }
    me->set("song/suikao/zhengji/lastpoint",me->query("song/credit"));
    tell_object(me,"你今年岁考政绩为"+zhengji+"，报效数额为"+renmai+"。\n");
    if (me->query("song/suikao/r_renmai")+me->query("song/suikao/z_zhengji")<3)
    {
        tell_object(me,"你被记大过一次，有可能影响自己的仕途。\n");
        me->add("song/credit",-(1+random(10)));
        me->add("song/suikao/overall",-1);
    }
    else if (me->query("song/suikao/r_renmai")+me->query("song/suikao/z_zhengji")<5)
    {
        tell_object(me,"无功无过，又是一年。\n");
    }
    else
    {
        tell_object(me,"你今年政绩突出且受众人交口称赞。\n");
        p=2+random(6);
        me->add("song/credit",p);
        me->set("song/suikao/excellent_year",age);
        tell_object(me,HIC"磨勘全优，你的大宋功勋增加了"+chinese_number(p)+"点。\n"NOR);
        me->add("song/suikao/overall",1);
		me->add("song/suikao/overall_forjue",1);
		if (me->query("song/suikao_longtime_not_in"))
		{
			me->delete("song/suikao_longtime_not_in");
			tell_object(me,"本次岁考之后你获得了重新回到中枢的机会，并开始发放各种俸禄。\n");
		}
    }
    /*if (DASONG_D->get_my_pin(me)==2&&me->query("song/suikao/overall")>8&&me->query("song/credit")>=3500&&!random(5)&&!me->query("song/2to1"))//2pin升1pin quest
    {
        me->set("song/2to1",1);
        tell_object(me,HIW+BLINK+"岁考连年是优，听说现在朝廷一品大员致仕的很多，这次是你的机会了。\n"NOR);
        return 1;
    }*/
    if ((me->query("song/xunjue/rank")&&me->query("song/suikao/overall_forjue")>4*(13-me->query("song/xunjue/rank")))||(!me->query("song/xunjue/rank")&&me->query("song/suikao/overall_forjue")>4))
    {
		//ob=DASONG_D->song_all();
        me->set("song/suikao/overall_forjue",0);
		DASONG_D->give_jue(me,0);
		CHANNEL_D->do_channel(this_object(), "dasong", "吏部司勋司行文："+me->query("name")+"被加封"+me->get_title(TITLE_SONG5)+"！", -1);
        return 1;
    }
	if (me->query("song/suikao/z_zhengji")==3)
	{
		if (random(10)==0)
		{
			me->set_temp("song/mokan_promote",1);
			DASONG_D->set_me_duty(me);
		}
		else
		{
			me->add("song/duty_promote/promote_time",-3600*2);
			tell_object(me,"因为政绩出众，你在"+chinese_number(DASONG_D->get_my_pin(me))+"品任上的迁转时间被缩短了。\n");
		}
	}
    if (me->query("song/suikao/overall")<-4)
    {
        tell_object(me,"你连续被发现严重失职，将被停发所有俸禄。\n");
    }
    return 1;
}


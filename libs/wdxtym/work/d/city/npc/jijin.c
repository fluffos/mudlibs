#include <ansi.h>
#include <localtime.h>

inherit NPC;
int do_shimen();
int do_chaxun();
int do_chaxun1();
void create()
{
	set_name(HIR"财神爷"NOR,({"caishen"}));
	set("gender","男性");
	set("long","小投资，大回报。");
	set("per",20);
	set("age",15);
	set("combat_exp",100);
	set("inquiry", ([
                "1.选购基金" : (: do_shimen :),
                "2.领取基金" : (: do_chaxun :),
                "3.查询基金" : (: do_chaxun1 :),
        ]));
	setup();
}
init ()
{
	add_action("do_choose","choose");
	add_action("do_choose1","choose1");
	add_action("do_choose2","choose2");
	add_action("do_choose3","choose3");
	add_action("do_choose4","choose4");

}


int do_shimen()
{
	string str;
			str = ZJOBLONG+ZJSIZE(30)+HIG"初级基金：投入2000灵石，连续7天每天"HIR"450"HIG"灵石"NOR+ZJBR+ZJSIZE(30)+HIG"中级基金：投入5000灵石，连续7天每天"HIR"1000"HIG"灵石"NOR+ZJBR+ZJSIZE(30)+HIG"高级基金：投入10000灵石，连续7天每天"HIR"2200"HIG"灵石"NOR+ZJBR+ZJSIZE(30)+HIG"特级基金：投入20000灵石，连续7天每天"HIR"4300"HIG"灵石"NOR+ZJBR+HIG"请选择！"+NOR+"\n"+ZJOBACTS2+ZJMENUF(1,1,8,28);
			str += HIY"手动输入选购基金:choose"+ZJSEP;

			write(str+"\n");
		return 1;
}
int do_chaxun()//基金领取
{
	string str;
			str = ZJOBLONG+ZJSIZE(30)+HIG"初级基金：连续7天每天领取"HIR"450"HIG"灵石"NOR+ZJBR+ZJSIZE(30)+HIG"中级基金：连续7天每天领取"HIR"1000"HIG"灵石"NOR+ZJBR+ZJSIZE(30)+HIG"高级基金：连续7天每天领取"HIR"2200"HIG"灵石"NOR+ZJBR+ZJSIZE(30)+HIG"特级基金：连续7天每天领取"HIR"4300"HIG"灵石"NOR+ZJBR+HIG"请选择！"+NOR+"\n"+ZJOBACTS2+ZJMENUF(2,2,8,30);
			str += HIY"领取初级基金:choose1 1"+ZJSEP;
			str += HIY"领取中级基金:choose2 1"+ZJSEP;
			str += HIY"领取高级基金:choose3 1"+ZJSEP;
			str += HIY"领取特级基金:choose4 1"+ZJSEP;

			write(str+"\n");
		return 1;
}
int do_chaxun1(string arg)//基金查询
{
	int flag;
	string str;
	object ob1,ob2;
	object me = this_player();
		if(me->is_fighting())
	{tell_object(me,"请先脱离战斗。\n");
		return 1;}
		if(me->is_busy())
	{tell_object(me,"你正忙。\n");
		return 1;}

    if(me->query("jijin/ss1")==1)
	{
       tell_object(me,HIG"你当前购买的初级基金剩余情况如下：\n" +
		HIC"每日领取："HIW+chinese_number(450) + "灵石\n" +
        HIC"剩余天数："HIW+chinese_number(7 - me->query("jijin/lingqu1")) + "天\n" +
        NOR);		
	}else	{tell_object(me,ZJSIZE(26)+HIR"你尚未购买初级基金。\n"+NOR);
		}
    if(me->query("jijin/ss2")==1)
	{
       tell_object(me,HIG"你当前购买的中级基金剩余情况如下：\n" +
		HIC"每日领取："HIW+chinese_number(1000) + "灵石\n" +
        HIC"剩余天数："HIW+chinese_number(7 - me->query("jijin/lingqu2")) + "天\n" +
        NOR);		
	}else	{tell_object(me,ZJSIZE(26)+HIR"你尚未购买中级基金。\n"+NOR);
		}
    if(me->query("jijin/ss3")==1)
	{
       tell_object(me,HIG"你当前购买的高级基金剩余情况如下：\n" +
		HIC"每日领取："HIW+chinese_number(2200) + "灵石\n" +
        HIC"剩余天数："HIW+chinese_number(7 - me->query("jijin/lingqu3")) + "天\n" +
        NOR);		
	}else	{tell_object(me,ZJSIZE(26)+HIR"你尚未购买高级基金。\n"+NOR);
		}
    if(me->query("jijin/ss4")==1)
	{
       tell_object(me,HIG"你当前购买的特级基金剩余情况如下：\n" +
		HIC"每日领取："HIW+chinese_number(4300) + "灵石\n" +
        HIC"剩余天数："HIW+chinese_number(7 - me->query("jijin/lingqu4")) + "天\n" +
        NOR);		
	}else	{tell_object(me,ZJSIZE(26)+HIR"你尚未购买特级基金。\n"+NOR);
		}		
	return 1;
}
int do_choose(string arg)//基金购买
{
	int shimen,flag,dj;
	string str;
    string a;
	object ob1,ob2;
	object me = this_player();
	shimen = me->query("shimen/today");
dj=me->query("zjvip/all_pay")/10;

        if (! arg) 

        return notify_fail(INPUTTXT(ZJSIZE(25)HIW BBLK"请手动输入你要购买的基金,例："NOR+ZJBR+ZJSIZE(25)+HIY"购买初级基金  ||  购买中级基金"NOR+ZJBR+ZJSIZE(25)+HIY"购买高级基金  ||  购买特级基金"NOR,"choose $txt#")+"\n");
		if(me->is_fighting())
	{tell_object(me,"请先脱离战斗。\n");
		return 1;}
		if(me->is_busy())
	{tell_object(me,"你正忙。\n");
		return 1;}
//	sscanf(arg,"%d",flag);
	switch (arg) {
	  case "购买初级基金" :
	  if(me->query("yuanbao")<100000000)
	  {
				tell_object(me,"一周仅开放一天购买。\n");
				return 1;
	  }
			if(me->query("yuanbao") >= 2000 && me->query("jijin/ss1") != 1)
			{
				me->add("yuanbao",-2000);
				me->set("jijin/ss1",1);
				tell_object(me,"购买成功，连续7天，每天可来我这领取450灵石。\n");
				return 1;
			}else
	{message_vision(HIG"你的灵石不足或者已经购买过了。"NOR"\n", me);
	    return 0;}
		break;
	  case "购买中级基金" :
	  if(me->query("yuanbao")<100000000)
	  {
				tell_object(me,"一周仅开放一天购买。\n");
				return 1;
	  }
			if(me->query("vipdj") < 2)
			{
				tell_object(me,"购买中级基金需要vip等级达到2级。\n");
				return 1;
			}
			if(me->query("yuanbao") >= 5000 && me->query("jijin/ss2") != 1)
			{
				me->add("yuanbao",-5000);
				me->set("jijin/ss2",1);
				tell_object(me,"购买成功，连续7天，每天可来我这领取1000灵石。\n");
				return 1;
			}else
	{message_vision(HIG"你的灵石不足或者已经购买过了。"NOR"\n", me);
	    return 0;}
		break;
	  case "购买高级基金" :
	  if(me->query("yuanbao")<100000000)
	  {
				tell_object(me,"一周仅开放一天购买。\n");
				return 1;
	  }
			if(me->query("vipdj") < 4)
			{
				tell_object(me,"购买高级基金需要vip等级达到4级。\n");
				return 1;
			}
			if(me->query("yuanbao") >= 10000 && me->query("jijin/ss3") != 1)
			{
				me->add("yuanbao",-10000);
				me->set("jijin/ss3",1);
				tell_object(me,"购买成功，连续7天，每天可来我这领取2200灵石。\n");
				return 1;
			}else
	{message_vision(HIG"你的灵石不足或者已经购买过了。"NOR"\n", me);
	    return 0;}
		break;
	  case "购买特级基金" :
	  if(me->query("yuanbao")<100000000)
	  {
				tell_object(me,"一周仅开放一天购买。\n");
				return 1;
	  }
			if(me->query("vipdj") < 6)
			{
				tell_object(me,"购买特级基金需要vip等级达到6级。\n");
				return 1;
			}
			if(me->query("yuanbao") >= 20000 && me->query("jijin/ss4") != 1)
			{
				me->add("yuanbao",-20000);
				me->set("jijin/ss4",1);
				tell_object(me,"购买成功，连续7天，每天可来我这领取4300灵石。\n");
				return 1;
			}else
	{message_vision(HIG"你的灵石不足或者已经购买过了。"NOR"\n", me);
	    return 0;}
		break;
	  default :
		message_vision(HIC "请输入正确的基金名称，例如：购买初级基金。\n" NOR,me);
		return notify_fail("请输入正确的基金名称，例如：购买初级基金。\n");
	}		

			
//	tell_object(me,"还未到领取时间！\n");
	return 1;
}
int do_choose1(int arg)//初级基金领取
{
	object ob, me,env ,bing , obj1,obj2,obj3,obj4;
	mixed *localtime, *localtime2;
	string writeFile, ip, ip2, *meFilePach, meFile, item_max, id, room, target;
	int i, fen, j, ok, day, month, size, data,flag;
        int level;
			ob = this_object();
        	me = this_player();

    if(me->query("jijin/ss1")!=1)
	{
		tell_object(me,CYN"你尚未购买该基金。\n"NOR);
		return 1;
	}
    if(me->query("jijin/lingqu1")>=7)
	{
		tell_object(me,CYN"该基金你已经7天全部领完了。\n"NOR);
		return 1;
	}
	if (ob->query_temp("qiandao_time") >time())
	{
		tell_object(me,CYN"财神爷说道：等一会再来。\n"NOR);
		return 1;
	}
	data = me->query("jijinss1/time");
	localtime = localtime(data);
	localtime2 = localtime(time());

	if(data && localtime[LT_MDAY]  == localtime2[LT_MDAY])
	{
		tell_object(me, CYN"财神爷说道：你今天已经领过基金奖励了，明天再来吧。\n"NOR);
		return 1;
	}
	if(localtime[LT_MON] + 1 != localtime2[LT_MON] + 1)//月份
	{
		me->delete("jijinss1");
	}
	ob->set_temp("jijinss1_time", time() + 2);//因该方式采取读写硬盘，故稍做限制
	if(writeFile)
	{
		meFile = read_file(writeFile);
		if(meFile)
			meFilePach = explode(meFile,"\n");
		size = sizeof(meFilePach);
		ip = query_ip_number(me);
		item_max = sprintf("ID:%s$Ip:%s$Day:%d$Month:%d", me->query("id"), ip, localtime2[LT_MON] + 1, localtime2[LT_MDAY]);
		for(i=0; i<size; i++)
		{
			sscanf(meFilePach[i], "ID:%s$Ip:%s$Day:%d$Month:%d", id, ip2, day, month);
			if (ip == ip2 && localtime2[LT_MON] + 1 == day && localtime2[LT_MDAY] == month)//相同文件内容表示本IP已经有人签到
			{
				ok =1;
				break;
			} else if (ip == ip2) {//只是IP相同，并没有签到
				ok =2;
				meFilePach[i] = "";
				break;
			} else
				ok =0;
		}
	}
	if (ok == 1)
	{
		tell_object(me, CYN"财神爷：这个IP今天已经有人领过奖励了。\n"NOR);
		return 1;
	}
	if (ok == 2)
	{
		write_file(writeFile, "", 1);//初始化该文件
		//重写文件
		for(i=0; i<size; i++)
		{
			if(meFilePach[i] == "") continue;//去掉IP相同的内容
			write_file(writeFile, sprintf("%s\n", meFilePach[i]));//重写所有内容
		}
	}

	message("channel:chat", HIR BBLK"【财神爷】："+ me->query("name")+"领取了初级基金每日450灵石奖励。\n"NOR,users());
	me->add("yuanbao",450);
	me->add("jijinss1/cishu", 1);
	me->add("jijin/lingqu1",1);
	me->set("jijinss1/time", time());
        tell_object(me,HIW"领取成功，你获得了：\n" +
        450 + "灵石\n" +
        NOR);
	return 1;

}
int do_choose2(int arg)//中级基金领取
{
	object ob, me,env ,bing , obj1,obj2,obj3,obj4;
	mixed *localtime, *localtime2;
	string writeFile, ip, ip2, *meFilePach, meFile, item_max, id, room, target;
	int i, fen, j, ok, day, month, size, data,flag;
        int level;
			ob = this_object();
        	me = this_player();
    if(me->query("jijin/ss2")!=1)
	{
		tell_object(me,CYN"你尚未购买该基金。\n"NOR);
		return 1;
	}
    if(me->query("jijin/lingqu2")>=7)
	{
		tell_object(me,CYN"该基金你已经7天全部领完了。\n"NOR);
		return 1;
	}
	if (ob->query_temp("qiandao_time") >time())
	{
		tell_object(me,CYN"财神爷说道：等一会再来。\n"NOR);
		return 1;
	}
	data = me->query("jijinss2/time");
	localtime = localtime(data);
	localtime2 = localtime(time());

	if(data && localtime[LT_MDAY]  == localtime2[LT_MDAY])
	{
		tell_object(me, CYN"财神爷说道：你今天已经领过基金奖励了，明天再来吧。\n"NOR);
		return 1;
	}
	if(localtime[LT_MON] + 1 != localtime2[LT_MON] + 1)//月份
	{
		me->delete("jijinss2");
	}
	ob->set_temp("jijinss2_time", time() + 2);//因该方式采取读写硬盘，故稍做限制
	if(writeFile)
	{
		meFile = read_file(writeFile);
		if(meFile)
			meFilePach = explode(meFile,"\n");
		size = sizeof(meFilePach);
		ip = query_ip_number(me);
		item_max = sprintf("ID:%s$Ip:%s$Day:%d$Month:%d", me->query("id"), ip, localtime2[LT_MON] + 1, localtime2[LT_MDAY]);
		for(i=0; i<size; i++)
		{
			sscanf(meFilePach[i], "ID:%s$Ip:%s$Day:%d$Month:%d", id, ip2, day, month);
			if (ip == ip2 && localtime2[LT_MON] + 1 == day && localtime2[LT_MDAY] == month)//相同文件内容表示本IP已经有人签到
			{
				ok =1;
				break;
			} else if (ip == ip2) {//只是IP相同，并没有签到
				ok =2;
				meFilePach[i] = "";
				break;
			} else
				ok =0;
		}
	}
	if (ok == 1)
	{
		tell_object(me, CYN"财神爷：这个IP今天已经有人领过奖励了。\n"NOR);
		return 1;
	}
	if (ok == 2)
	{
		write_file(writeFile, "", 1);//初始化该文件
		//重写文件
		for(i=0; i<size; i++)
		{
			if(meFilePach[i] == "") continue;//去掉IP相同的内容
			write_file(writeFile, sprintf("%s\n", meFilePach[i]));//重写所有内容
		}
	}

	message("channel:chat", HIR BBLK"【财神爷】："+ me->query("name")+"领取了中级基金每日1000灵石奖励。\n"NOR,users());
	me->add("yuanbao",1000);
	me->add("jijinss2/cishu", 1);
	me->add("jijin/lingqu2",1);

	me->set("jijinss2/time", time());
        tell_object(me,HIW"领取成功，你获得了：\n" +
        1000 + "灵石\n" +
        NOR);
	return 1;

}
int do_choose3(int arg)//高级基金领取
{
	object ob, me,env ,bing , obj1,obj2,obj3,obj4;
	mixed *localtime, *localtime2;
	string writeFile, ip, ip2, *meFilePach, meFile, item_max, id, room, target;
	int i, fen, j, ok, day, month, size, data,flag;
        int level;
			ob = this_object();
        	me = this_player();
    if(me->query("jijin/ss3")!=1)
	{
		tell_object(me,CYN"你尚未购买该基金。\n"NOR);
		return 1;
	}
    if(me->query("jijin/lingqu3")>=7)
	{
		tell_object(me,CYN"该基金你已经7天全部领完了。\n"NOR);
		return 1;
	}
	if (ob->query_temp("qiandao_time") >time())
	{
		tell_object(me,CYN"财神爷说道：等一会再来。\n"NOR);
		return 1;
	}
	data = me->query("jijinss3/time");
	localtime = localtime(data);
	localtime2 = localtime(time());

	if(data && localtime[LT_MDAY]  == localtime2[LT_MDAY])
	{
		tell_object(me, CYN"财神爷说道：你今天已经领过基金奖励了，明天再来吧。\n"NOR);
		return 1;
	}
	if(localtime[LT_MON] + 1 != localtime2[LT_MON] + 1)//月份
	{
		me->delete("jijinss3");
	}
	ob->set_temp("jijinss3_time", time() + 2);//因该方式采取读写硬盘，故稍做限制
	if(writeFile)
	{
		meFile = read_file(writeFile);
		if(meFile)
			meFilePach = explode(meFile,"\n");
		size = sizeof(meFilePach);
		ip = query_ip_number(me);
		item_max = sprintf("ID:%s$Ip:%s$Day:%d$Month:%d", me->query("id"), ip, localtime2[LT_MON] + 1, localtime2[LT_MDAY]);
		for(i=0; i<size; i++)
		{
			sscanf(meFilePach[i], "ID:%s$Ip:%s$Day:%d$Month:%d", id, ip2, day, month);
			if (ip == ip2 && localtime2[LT_MON] + 1 == day && localtime2[LT_MDAY] == month)//相同文件内容表示本IP已经有人签到
			{
				ok =1;
				break;
			} else if (ip == ip2) {//只是IP相同，并没有签到
				ok =2;
				meFilePach[i] = "";
				break;
			} else
				ok =0;
		}
	}
	if (ok == 1)
	{
		tell_object(me, CYN"财神爷：这个IP今天已经有人领过奖励了。\n"NOR);
		return 1;
	}
	if (ok == 2)
	{
		write_file(writeFile, "", 1);//初始化该文件
		//重写文件
		for(i=0; i<size; i++)
		{
			if(meFilePach[i] == "") continue;//去掉IP相同的内容
			write_file(writeFile, sprintf("%s\n", meFilePach[i]));//重写所有内容
		}
	}

	message("channel:chat", HIR BBLK"【财神爷】："+ me->query("name")+"领取了高级基金每日2200灵石奖励。\n"NOR,users());
	me->add("yuanbao",2200);
	me->add("jijinss3/cishu", 1);
	me->add("jijin/lingqu3",1);

	me->set("jijinss3/time", time());
        tell_object(me,HIW"领取成功，你获得了：\n" +
        2200 + "灵石\n" +
        NOR);
	return 1;

}
int do_choose4(int arg)//特级基金领取
{
	object ob, me,env ,bing , obj1,obj2,obj3,obj4;
	mixed *localtime, *localtime2;
	string writeFile, ip, ip2, *meFilePach, meFile, item_max, id, room, target;
	int i, fen, j, ok, day, month, size, data,flag;
        int level;
			ob = this_object();
        	me = this_player();
    if(me->query("jijin/ss4")!=1)
	{
		tell_object(me,CYN"你尚未购买该基金。\n"NOR);
		return 1;
	}
    if(me->query("jijin/lingqu4")>=7)
	{
		tell_object(me,CYN"该基金你已经7天全部领完了。\n"NOR);
		return 1;
	}
	if (ob->query_temp("qiandao_time") >time())
	{
		tell_object(me,CYN"财神爷说道：等一会再来。\n"NOR);
		return 1;
	}
	data = me->query("jijinss4/time");
	localtime = localtime(data);
	localtime2 = localtime(time());

	if(data && localtime[LT_MDAY]  == localtime2[LT_MDAY])
	{
		tell_object(me, CYN"财神爷说道：你今天已经领过基金奖励了，明天再来吧。\n"NOR);
		return 1;
	}
	if(localtime[LT_MON] + 1 != localtime2[LT_MON] + 1)//月份
	{
		me->delete("jijinss4");
	}
	ob->set_temp("jijinss4_time", time() + 2);//因该方式采取读写硬盘，故稍做限制
	if(writeFile)
	{
		meFile = read_file(writeFile);
		if(meFile)
			meFilePach = explode(meFile,"\n");
		size = sizeof(meFilePach);
		ip = query_ip_number(me);
		item_max = sprintf("ID:%s$Ip:%s$Day:%d$Month:%d", me->query("id"), ip, localtime2[LT_MON] + 1, localtime2[LT_MDAY]);
		for(i=0; i<size; i++)
		{
			sscanf(meFilePach[i], "ID:%s$Ip:%s$Day:%d$Month:%d", id, ip2, day, month);
			if (ip == ip2 && localtime2[LT_MON] + 1 == day && localtime2[LT_MDAY] == month)//相同文件内容表示本IP已经有人签到
			{
				ok =1;
				break;
			} else if (ip == ip2) {//只是IP相同，并没有签到
				ok =2;
				meFilePach[i] = "";
				break;
			} else
				ok =0;
		}
	}
	if (ok == 1)
	{
		tell_object(me, CYN"财神爷：这个IP今天已经有人领过奖励了。\n"NOR);
		return 1;
	}
	if (ok == 2)
	{
		write_file(writeFile, "", 1);//初始化该文件
		//重写文件
		for(i=0; i<size; i++)
		{
			if(meFilePach[i] == "") continue;//去掉IP相同的内容
			write_file(writeFile, sprintf("%s\n", meFilePach[i]));//重写所有内容
		}
	}

	message("channel:chat", HIR BBLK"【财神爷】："+ me->query("name")+"领取了特级基金每日4300灵石奖励。\n"NOR,users());
	me->add("yuanbao",4300);
	me->add("jijinss4/cishu", 1);
	me->add("jijin/lingqu4",1);
	me->set("jijinss4/time", time());
        tell_object(me,HIW"领取成功，你获得了：\n" +
        4300 + "灵石\n" +
        NOR);
	return 1;

}


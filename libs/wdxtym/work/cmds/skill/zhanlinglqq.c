// giveall.c
inherit F_DBASE;
inherit F_CLEAN_UP;
#include <ansi.h>
#define REDBAO "/u/aliyun/obj/bao"
void create()
{
seteuid(getuid());
}
int main(object me, string arg)
{
	    object obj,ob,obj1,obj2,obj3,obj4;
        int count,mengxin;
        string a;
		me = this_player();
		a = "浮生若梦";
        if (! arg) 

        return notify_fail(INPUTTXT(ZJSIZE(18)MAG BBLK"？"NOR,"zhanling $txt#")+"\n");
		if(me->is_fighting())
	{
		tell_object(me,"请先脱离战斗。\n");
		return 1;
	}
		if(me->is_busy())
	{
		tell_object(me,"你正忙。\n");
		return 1;
	}
		if(me->query("zhanling/goumai")!=10)
	{
		tell_object(me,"你尚未购买高级战令，联系巫师购买。\n");
		return 1;
	}
	switch (arg) {
	  case "1" :
			if(me->query("zhanling/dj") >= 1 && me->query("zhanlinglq/ss1") != 1)
			{
			me->add("yuanbao",500);
			me->add("jifeng",2000);	
				me->set("zhanlinglq/ss1",1);
				tell_object(me,"领取成功，你获得了500灵石和2000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "2" :
			if(me->query("zhanling/dj") >= 2 && me->query("zhanlinglq/ss2") != 1)
			{
			me->add("yuanbao",500);
			me->add("jifeng",2000);	
				me->set("zhanlinglq/ss2",1);
				tell_object(me,"领取成功，你获得了500灵石和2000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "3" :
			if(me->query("zhanling/dj") >= 3 && me->query("zhanlinglq/ss3") != 1)
			{
			me->add("yuanbao",500);
			me->add("jifeng",2000);			
				me->set("zhanlinglq/ss3",1);
				tell_object(me,"领取成功，你获得了500灵石和2000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "4" :
			if(me->query("zhanling/dj") >= 4 && me->query("zhanlinglq/ss4") != 1)
			{
			me->add("yuanbao",500);
			me->add("jifeng",2000);	
				me->set("zhanlinglq/ss4",1);
				tell_object(me,"领取成功，你获得了500灵石和2000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "5" :
			if(me->query("zhanling/dj") >= 5 && me->query("zhanlinglq/ss5") != 1)
			{
			me->add("yuanbao",500);
			me->add("jifeng",2000);	
				me->set("zhanlinglq/ss5",1);
				tell_object(me,"领取成功，你获得了500灵石和2000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "6" :
			if(me->query("zhanling/dj") >= 6 && me->query("zhanlinglq/ss6") != 1)
			{
			me->add("yuanbao",500);
			me->add("jifeng",2000);	
			me->set("zhanlinglq/ss6",1);
				tell_object(me,"领取成功，你获得了500灵石和2000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "7" :
			if(me->query("zhanling/dj") >= 7 && me->query("zhanlinglq/ss7") != 1)
			{
			me->add("yuanbao",500);
			me->add("jifeng",2000);	
			me->set("zhanlinglq/ss7",1);
				tell_object(me,"领取成功，你获得了500灵石和2000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "8" :
			if(me->query("zhanling/dj") >= 8 && me->query("zhanlinglq/ss8") != 1)
			{
			me->add("yuanbao",500);
			me->add("jifeng",2000);	
			me->set("zhanlinglq/ss8",1);
				tell_object(me,"领取成功，你获得了500灵石和2000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "9" :
			if(me->query("zhanling/dj") >= 9 && me->query("zhanlinglq/ss9") != 1)
			{
			me->add("yuanbao",500);
			me->add("jifeng",2000);	
			me->set("zhanlinglq/ss9",1);
				tell_object(me,"领取成功，你获得了500灵石和2000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "10" :
			if(me->query("zhanling/dj") >= 10 && me->query("zhanlinglq/ss10") != 1)
			{
			me->add("yuanbao",500);
			me->add("jifeng",2000);	
			me->set("zhanlinglq/ss10",1);
				tell_object(me,"领取成功，你获得了500灵石和2000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "11" :
			if(me->query("zhanling/dj") >= 11 && me->query("zhanlinglq/ss11") != 1)
			{
			me->add("yuanbao",500);
			me->add("jifeng",2000);	
			me->set("zhanlinglq/ss11",1);
				tell_object(me,"领取成功，你获得了500灵石和2000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "12" :
			if(me->query("zhanling/dj") >= 12 && me->query("zhanlinglq/ss12") != 1)
			{
			me->add("yuanbao",500);
			me->add("jifeng",2000);	
			me->set("zhanlinglq/ss12",1);
				tell_object(me,"领取成功，你获得了500灵石和2000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "13" :
			if(me->query("zhanling/dj") >= 13 && me->query("zhanlinglq/ss13") != 1)
			{
			me->add("yuanbao",500);
			me->add("jifeng",2000);	
			me->set("zhanlinglq/ss13",1);
				tell_object(me,"领取成功，你获得了500灵石和2000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "14" :
			if(me->query("zhanling/dj") >= 14 && me->query("zhanlinglq/ss14") != 1)
			{
			me->add("yuanbao",500);
			me->add("jifeng",2000);	
			me->set("zhanlinglq/ss14",1);
				tell_object(me,"领取成功，你获得了500灵石和2000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "15" :
			if(me->query("zhanling/dj") >= 15 && me->query("zhanlinglq/ss15") != 1)
			{
			me->add("yuanbao",500);
			me->add("jifeng",2000);	
			me->set("zhanlinglq/ss15",1);
				tell_object(me,"领取成功，你获得了500灵石和2000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "16" :
			if(me->query("zhanling/dj") >= 16 && me->query("zhanlinglq/ss16") != 1)
			{
			me->add("yuanbao",1000);
			me->add("jifeng",4000);	
			me->set("zhanlinglq/ss16",1);
				tell_object(me,"领取成功，你获得了1000灵石和4000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "17" :
			if(me->query("zhanling/dj") >= 17 && me->query("zhanlinglq/ss17") != 1)
			{
			me->add("yuanbao",1000);
			me->add("jifeng",4000);	
			me->set("zhanlinglq/ss17",1);
				tell_object(me,"领取成功，你获得了1000灵石和4000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "18" :
			if(me->query("zhanling/dj") >= 18 && me->query("zhanlinglq/ss18") != 1)
			{
			me->add("yuanbao",1000);
			me->add("jifeng",4000);	
			me->set("zhanlinglq/ss18",1);
				tell_object(me,"领取成功，你获得了1000灵石和4000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "19" :
			if(me->query("zhanling/dj") >= 19 && me->query("zhanlinglq/ss19") != 1)
			{
			me->add("yuanbao",1000);
			me->add("jifeng",4000);	
			me->set("zhanlinglq/ss19",1);
				tell_object(me,"领取成功，你获得了1000灵石和4000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "20" :
			if(me->query("zhanling/dj") >= 20 && me->query("zhanlinglq/ss20") != 1)
			{
			me->add("yuanbao",1000);
			me->add("jifeng",4000);	
			me->set("zhanlinglq/ss20",1);
				tell_object(me,"领取成功，你获得了1000灵石和4000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "21" :
			if(me->query("zhanling/dj") >= 21 && me->query("zhanlinglq/ss21") != 1)
			{
			me->add("yuanbao",1000);
			me->add("jifeng",4000);	
			me->set("zhanlinglq/ss21",1);
				tell_object(me,"领取成功，你获得了1000灵石和4000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "22" :
			if(me->query("zhanling/dj") >= 22 && me->query("zhanlinglq/ss22") != 1)
			{
			me->add("yuanbao",1000);
			me->add("jifeng",4000);	
			me->set("zhanlinglq/ss22",1);
				tell_object(me,"领取成功，你获得了1000灵石和4000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "23" :
			if(me->query("zhanling/dj") >= 23 && me->query("zhanlinglq/ss23") != 1)
			{
			me->add("yuanbao",1000);
			me->add("jifeng",4000);	
			me->set("zhanlinglq/ss23",1);
				tell_object(me,"领取成功，你获得了1000灵石和4000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "24" :
			if(me->query("zhanling/dj") >= 24 && me->query("zhanlinglq/ss24") != 1)
			{
			me->add("yuanbao",1000);
			me->add("jifeng",4000);	
			me->set("zhanlinglq/ss24",1);
				tell_object(me,"领取成功，你获得了1000灵石和4000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "25" :
			if(me->query("zhanling/dj") >= 25 && me->query("zhanlinglq/ss25") != 1)
			{
			me->add("yuanbao",1000);
			me->add("jifeng",4000);	
			me->set("zhanlinglq/ss25",1);
				tell_object(me,"领取成功，你获得了1000灵石和4000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "26" :
			if(me->query("zhanling/dj") >= 26 && me->query("zhanlinglq/ss26") != 1)
			{
			me->add("yuanbao",2000);
			me->add("jifeng",8000);	
			me->set("zhanlinglq/ss26",1);
				tell_object(me,"领取成功，你获得了2000灵石和8000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "27" :
			if(me->query("zhanling/dj") >= 27 && me->query("zhanlinglq/ss27") != 1)
			{
			me->add("yuanbao",3000);
			me->add("jifeng",12000);	
			me->set("zhanlinglq/ss27",1);
				tell_object(me,"领取成功，你获得了3000灵石和12000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "28" :
			if(me->query("zhanling/dj") >= 28 && me->query("zhanlinglq/ss28") != 1)
			{
			me->add("yuanbao",4000);
			me->add("jifeng",16000);	
			me->set("zhanlinglq/ss28",1);
				tell_object(me,"领取成功，你获得了4000灵石和16000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "29" :
			if(me->query("zhanling/dj") >= 29 && me->query("zhanlinglq/ss29") != 1)
			{
			me->add("yuanbao",5000);
			me->add("jifeng",20000);	
			me->set("zhanlinglq/ss29",1);
				tell_object(me,"领取成功，你获得了5000灵石和20000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  case "30" :
			if(me->query("zhanling/dj") >= 30 && me->query("zhanlinglq/ss30") != 1)
			{
			me->add("yuanbao",10000);
			me->add("jifeng",50000);	
			me->set("zhanlinglq/ss30",1);
				tell_object(me,"领取成功，你获得了10000灵石和50000点券。\n");
				return 1;
			}else
	{message_vision(HIG"你的战令等级不足或者已经领取过一次了。"NOR"\n", me);
	    return 1;}
		break;
	  default :
		message_vision(HIC "领取错误，请联系巫师。\n" NOR,me);
	}		
              sscanf(arg, "%s ", a);


        return 1;
}

int help(object me)
{
        write(@HELP
指令格式：giveall 物品路径

给在线的所有玩家红包。
HELP
        );
        return 1;
}

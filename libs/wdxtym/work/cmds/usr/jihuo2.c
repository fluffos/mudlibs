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
	    object obj,ob;
        int count,mengxin;
        string a;
		me = this_player();
        if (! arg) 

        return notify_fail(INPUTTXT(ZJSIZE(24)HIR"请输入礼包码：中秋礼包"NOR,"jihuo2 $txt#")+"\n");
	switch (arg) {
	  case "中秋礼包" :
		me->add_temp("sword",1);
		write("哦豁！\n");
		message("vision","礼包码正确！"+me->name()+"！\n",me);
		
		break;
	  default :
		return notify_fail("礼包码错误，请前往官方QQ群获取输入正确的礼包码\n");

	}		
              sscanf(arg, "%s ", a);



  if(me->query("jihuom/s2")>0)
	{
		tell_object(me, HIR"每个礼包码只能使用一次！\n"NOR);
        return 1;
	}


              CHANNEL_D->do_channel(this_object(),"rumor",
                HIY+me->name() + "激活了中秋礼包码！"NOR);
//	me->add("combat_exp",100000);
	me->add("potential",5000000);
//	me->add("max_neili", 500);
//	me->add("max_jingli", 500);

	me->set("jihuom/s2",1);
//		ob = new("clone/zhongqiu/50jing");
//	ob->move(me);
//		ob = new("clone/zhongqiu/jiuzhuan");
//                ob->set_amount(10);
//	ob->move(me);
//		ob = new("clone/zhongqiu/wannian");
//	ob->move(me);
		ob = new("clone/zhongqiu/shimen1000");
	ob->move(me);
	
	write("礼包码正确，你获得了以下奖励!\n");
        tell_object(me,HIW"你获得了：\n" +
//        1 + "颗+50精炼石\n" +
		1 + "张师门1000次数卡\n" +
//        10 + "颗九转金丹。\n"+
//        1 + "个万年灵芝。\n"+
        500 + "万潜能。\n"+

        NOR);
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

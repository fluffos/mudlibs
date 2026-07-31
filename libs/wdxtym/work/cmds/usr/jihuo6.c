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

        return notify_fail(INPUTTXT(ZJSIZE(24)HIR"请输入礼包码：更新补偿B"NOR,"jihuo6 $txt#")+"\n");
	switch (arg) {
	  case "更新补偿B" :
		me->add_temp("sword",1);
		write("哦豁！\n");
		message("vision","礼包码正确！"+me->name()+"！\n",me);
		
		break;
	  default :
		return notify_fail("礼包码错误，请前往官方QQ群获取输入正确的礼包码\n");

	}		
              sscanf(arg, "%s ", a);
  if(me->query("jihuom/s6")>0)
	{
		tell_object(me, HIR"每个礼包码只能使用一次！\n"NOR);
        return 1;
	}


              CHANNEL_D->do_channel(this_object(),"rumor",
                HIY+me->name() + "领取了更新补偿B！"NOR);
//	me->add("combat_exp",100000);
//	me->add("clone\vip2\qilin.c",5);
    me->add("dajif",100);
//	me->add("max_neili", 500);
//	me->add("max_jingli", 500);

	me->set("jihuom/s6",1);

	ob = new("clone/vip2/qilin");
    ob->set_amount(6);
	ob->move(me);

	ob = new("clone/vip2/xuanling");
    ob->set_amount(6);
	ob->move(me);

	ob = new("clone/vip2/tianling");
    ob->set_amount(6);
	ob->move(me);
	
	write("礼包码正确，你获得了以下奖励!\n");
        tell_object(me,HIW"你获得了：\n" +
        6 + "麒麟丹\n" +
        6 + "玄灵丹\n" +
        12 + "天灵丹\n" +
        100 + "钻石\n" +
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

// giveall.c
inherit F_DBASE;
inherit F_CLEAN_UP;
#include <ansi.h>
#define REDBAO "/clone/7yue/zanzhu1"
void create()
{
	seteuid(ROOT_UID);
	set("channel_id", HIW"武动仙途公告"NOR);
//	CHANNEL_D->do_channel( this_object(), "sys", "公共boss。");

}
int main(object me, int arg)
{
        object *ob,*players,player1,player2;
        string str,note;
        int count,num,rdm,n,i;
         int m;
        int bmoney,avmoney,lfmoney;
        
        if  (!wizardp(me))
        return  notify_fail("你没有权力使用这个指令。\n");
        if (! arg) 

        return notify_fail(INPUTTXT("请输入发放红包金额(黄金)然后留言(默认恭喜发财)，如：50 你好","givezz $txt#")+"\n");
                note="恭喜发财！";
              sscanf(arg, "%d %s", count,note);
              if(me->query("balance")*10<count) return notify_fail("你的钱不够了！赶快去找巫师py交易！\n");

        if (count<0) return notify_fail("你想让别人给你倒贴钱吗？！！\n");

        if (count<50) return notify_fail("你也太小气了吧。\n");

//              CHANNEL_D->do_channel(this_object(),"笑傲",
 //              ""+ HIW + ZJSIZE(24)+HIR"请在武庙巫师处领取2021.9.16维护补偿"+HIC"！"NOR);
//              CHANNEL_D->do_channel(this_object(),"笑傲",
//               ""+ HIW + ZJSIZE(24)+HIR"请在武庙巫师处领取2021.9.16维护补偿"+HIC"！"NOR);
	CHANNEL_D->do_channel(this_object(), "chat", ZJSIZE(27)+BLK HBCYN"快捷处新增初始礼包。");
//	CHANNEL_D->do_channel(this_object(), "chat", ZJSIZE(27)+BLK HBCYN"中秋节开启寻宝活动，活动结束后第一至第十名有奖励。");

               num = sizeof(users());

               players = users();

               ob = allocate(num);
               count *= 10000;

        str=sprintf("共有%d位玩家收到讯息。\n",sizeof(users()));
        tell_object(me,str);
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

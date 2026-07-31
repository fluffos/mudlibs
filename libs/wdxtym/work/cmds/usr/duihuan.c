// giveall.c
inherit F_DBASE;
inherit F_CLEAN_UP;
#include <ansi.h>
void create()
{
seteuid(getuid());
}
int main(object me, int arg)
{
	    object obj;
		object yao;
        int count,mengxin,exp;
        	me = this_player();
        	exp = 15000000+me->query("zhuanshii")*1000000+me->query("guizhen")*1000000;

        if (! arg) 

        return notify_fail(INPUTTXT("请输入你想要用潜能兑换修为的数量，"ZJBR"比例是10250潜能==1修为值，单次最多兑换1万修为","duihuan $txt#")+"\n");
              sscanf(arg, "%d %s", count);

      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

  if(me->query("potential") < 10250)
	{
		tell_object(me, HIR"潜能不足。\n"NOR);
        return 1;
	}

        if (count<1) return notify_fail("gjb？！\n");
        if (count>10000) return notify_fail("单次最多兑换1万！\n");



        if (  (count*10250) > me->query("potential")  )
		{
			tell_object(me, sprintf(HIR + "你的潜能不够兑换"+
		chinese_number(count)+ "点修为值，你需要"+
		chinese_number(count*10250)+ "潜能才能兑换修为值。\n"NOR));
        return 1;

		}
//			return notify_fail("你的修为不够兑换+chinese_number""！\n");
//              CHANNEL_D->do_channel(this_object(),"rumor",
//               HIY+me->name() + "扫荡了日常七剑副本！"NOR);
//	me->add("combat_exp",exp*count);
//	me->add("potential",888888*count);
//	me->add("weapon_max",3*count);
//	me->add("weapon/lv",3*count);
//	me->add("qijian",-count);
	me->add("potential",-10250*count);
	me->add("combat_exp",count);
//	me->start_busy(2);

        tell_object(me,HIW"你获得了：\n" +
        count + "点修为值\n" +
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

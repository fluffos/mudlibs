//D:\xkx\d\liuxiu-shanzhuang\newbie_village.h
//labaz 2012/10/23
#ifndef __NEWBIE_H__
#define __NEWBIE_H__
#include <ansi.h>

#define NEWBIE_VILLAGE_INDEX "newbie_village/quest_index"
#define __DOMAIN_DIR__ "/d/newbie_lxsz/"

string *quest_newbie = ({
"你来到这个陌生的地方，前途未卜，请先用hp命令检查自己的身体情况",
"使用look river或者l river命令，根据提示先让自己喝饱吃足。地上的野果也可以捡起来充饥。(get ye guo;eat ye guo)",
"用east、west、south等方向命令来探索未明谷周围的三块地方，并回到未明谷",
"使用look path命令，根据提示离开未明谷",
"拿着刻有“柳秀山庄”的葫芦去柳秀山庄一问究竟",
"ask yahuan about 葫芦，向丫鬟询问有关“葫芦”的事情",
"再次敲门(knock gate)，去见山庄庄主",
// "follow yahuan，跟随丫环去见山庄庄主",
"give hulu to you kunyi，把葫芦交给游鲲翼",
"向游鲲翼依次打听，here、name、葫芦、闯荡江湖",
"使用follow a shu命令跟随丫鬟阿姝，然后她会带你熟悉一下山庄",
"把脏衣服脱了，在浴室洗个澡",
"洗完穿上衣服，向游鲲翼打听闯荡江湖",//"洗完穿上衣服，到厢房睡一觉",
//"向游鲲翼打听闯荡江湖",
"尚武堂找武师比武，fight wushi",
"回到厢房睡一觉补充体力",
"向游鲲翼打听闯荡江湖！",
"使用localmaps命令查看票号的位置",
"到票号把钱都给取出来",
"去药铺买药(buy yao)，吃药(eat yao)把身上的伤完全治好",
"向游鲲翼打听闯荡江湖！！",
"找武师拜师学艺，bai wushi",
"帮武师去铁匠铺买一把钢剑，去酒铺买一壶烧刀子酒，回来交给武师",
"再去酒铺买个鸡腿，去杂货铺买个食盒，把鸡腿放到食盒里交给武师",
"bai wushi,查看武师技能，cha wushi",
"学习武师身上所有基本功夫到5级，所有高级功夫到5级",
"激发内功为太乙神功、轻功为太乙轻功、掌法为太乙掌法、剑法为太乙剑法、招架为太乙剑法",
"指定平时要用的空手技能-太乙掌法",
"尚武堂找武师再次比武",
"练习一级太乙剑法，学会用太乙剑法的一个绝招",
"向游鲲翼打听闯荡江湖！！！",
"去未明谷的树林除掉老虎",
"向游鲲翼打听闯荡江湖！！！！",
"去藏书阁读江湖掌故",
"向游鲲翼打听闯荡江湖！！！！！",
"去杏子林和游鲲翼道别",
"到南面的车马行坐马车去扬州",
});

int show_quest()
{
	object me;
	int index;

	me=this_player();
	index=(int)me->query(NEWBIE_VILLAGE_INDEX);

	if (( index>=1 ) && ( index<=(sizeof(quest_newbie)) ))
	{
		write(HIG+quest_newbie[index-1]+"\n"NOR);
	}
	else
	{
		write(HIW"你的新手村数据异常。\n"NOR);
	}
	return 1;
}

int get_questindex(string job_secr)
{
	int i;
	for (i=0;i<sizeof(quest_newbie);i++) 
	{
		if (job_secr == quest_newbie[i])
		{
			return i+1;
		}
	}
	return 0;
}

int check_questindex(object me, string cur_quest)
{
	if (me->query(NEWBIE_VILLAGE_INDEX)==get_questindex(cur_quest))
	{
		return 1;
	}
	else if (me->query(NEWBIE_VILLAGE_INDEX)>get_questindex(cur_quest))
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

void quest_gain(object me, int exp, int pot, string hint)
{
    int rpot;

	if (objectp(me))
	{
		me->add("combat_exp", exp);
        rpot = pot+random(10);
		me->add("potential", rpot);
        me->add("pot/lxsz", rpot);
		tell_object(me,HIC"\n干的不错，你被奖励了"+chinese_number(exp)+"点经验，"+chinese_number(pot)+"点潜能！\n\n"NOR+hint+"\n"NOR);
        CHANNEL_D->do_channel(load_object(__DOMAIN_DIR__"npc/youkunyi"), "sys_misc", sprintf("%s在柳秀山庄第%d步任务中获得经验：%d、潜能：%d。", me->name(), me->query(NEWBIE_VILLAGE_INDEX), exp, pot));
		me->add(NEWBIE_VILLAGE_INDEX, 1);
	}
	else
	{
		write("参数一不是对象物件\n");
	}
}

string quest_desc(string text)
{
	string desc;
	desc=HIG+text+NOR+"\n"+GRN"你可以用"NOR+HIY"quest"NOR+GRN"命令了解你现在应该做些什么。\n\n"NOR;
	return desc;
}

int set_nextquest(object me, string cur_quest, string next_desc, int add_exp, int add_pot)
{
	string text;
	
	if (!objectp(me)) return 0;
	
	if (get_questindex(cur_quest) == me->query(NEWBIE_VILLAGE_INDEX))
	{
		text=quest_desc(next_desc);
		quest_gain(me, add_exp, add_pot, text);
		return 1;
	}
	else
	{
		return 0;
	}
}

#endif

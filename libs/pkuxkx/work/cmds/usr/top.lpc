// top.c created by jun
inherit F_CLEAN_UP;

#include <ansi.h>

int ask_family_repute()
{
	string* fams;
	int i;
	fams = FAMILY_D->get_repute_top(20);
	write(HIY"                北大侠客行门派威望排行榜\n"NOR);
	for(i=0;i<sizeof(fams);i++)
	{
		write("        ");
		if(i<3)
		{
			write(BRED+HIY);
		}
		else
		{
			write(HIW);
		}
		write(sprintf("天下第%-10s %-15s %d",chinese_number(i+1),fams[i],FAMILY_D->get_repute(fams[i])));
		write("\n"NOR);
	}
	return 1;
}

int ask_family_dadizi()
{
	mapping data;
	string* fams;
	int i;

	data = FAMILY_D->query("dadizi");
	if(!mapp(data))
	{
		command("say 宇宙初现，混沌未开。");
	}
	else
	{
		fams = keys(data);
		write(HIY"           天下门派掌门大弟子\n"NOR);
		for(i=0;i<sizeof(fams);i++)
		{
			write("        ");
			
			write(HIW);

			write(sprintf("%-15s %s(%s)",fams[i],FAMILY_D->get_dadizi_name(fams[i]),FAMILY_D->get_dadizi(fams[i])));
			write("\n"NOR);

		}
	}
	return 1;
}

int top_emote()
{
    string* emotes;
    int i=0;
    emotes = EMOTE_D->query_top_emote_list();
    printf(HIR"=============北侠最热表情================\n"NOR);
    for(i=0;i<sizeof(emotes);i++)
    {
        printf("\t\t%s\n",emotes[i]);
    }
    printf(HIR"========================================\n"NOR);
}

int main(object me,string arg)
{
        if(!wizardp(me) && time()-me->query_temp("scan_time") < 5)
		        return notify_fail("等等，系统喘气中......\n");
        me->set_temp("scan_time",time());
        if (!arg)
        {
                if ( wizardp(me) )
                        write(TOP_D->show_top()+"\n");
                else
                        write(TOP_D->show_top1()+"\n");
                return 1;
        }
        else if(arg == "fullme" && !wizardp(me))
        {
            return notify_fail("对不起，你无法查询这种排行榜！\n");
        }		
        else if(arg != "family" && arg != "ddz"  && arg != "emote")
		{
                write(TOPTEN_D->topten_query(arg) + "\n");
		}
		else if(arg == "family")
		{
			ask_family_repute();
		}
		else if(arg == "ddz")
		{
			ask_family_dadizi();
		}
		else if(arg == "emote" && wizardp(me))
		{
			top_emote();
		}		
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式：top <类型>，如果没有类型则列出15大高手。

rich：    十大富翁
exp：     十大高手
combat:   十大宗师
pker：    十大杀手
age：     十大老手
beauty：  十大美女
handsome：十大帅哥
repute：  十大名人
neili:    十大内力高手
jingli:   十大精力高手
level:    十大等级高手
qixue:    十大气血高手
jingshen: 十大精神高手
petkiller:十大宠物杀手
badrp:    十大倒霉蛋
score:    十大义士
family:   门派威望排行
ddz:	  掌门大弟子

这个指令让你查看当前玩家排行榜。
HELP
        );
        return 1;
}


// profession职业系统 by Vast@pkuxkx 2009-06

#include <ansi.h>

int main(object me, string arg)
{
        object ob;
        mapping skl, lrn, map,aa;
        string *sname, *mapped, skill, msg, type, str1, str2;
        int i,j;
        string usage, *sk;
        int opt_spec,opt_base;

        seteuid(getuid());

        if(!arg)
                ob = me;
        else{
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
        if (wizardp(me))  {
        if( !ob ) ob = LOGIN_D->find_body(arg);
        }
                if (!ob) return notify_fail("周围有这个人吗？只有巫师，夫妻能察看他人的职业技能。\n");
        }

        if( ob!=me && !wizardp(me) && me->query("marry/lover") != ob->query("id") )
                return notify_fail("周围有这个人吗？只有巫师，夫妻能察看他人的技能。\n");

        skl = ob->query_profs();
        if(!sizeof(skl)) {
                write( (ob==me ? "你" : ob->name()) + "目前并没有学会任何职业技能。\n");
                return 1;
        }
        msg = sprintf( HBBLU + HIY + (ob==me ? "你" : ob->name()) + HBBLU + HIY + "目前共学过"+chinese_number(sizeof(skl))+"类职业技能\n\n"NOR);
				sname  = sort_array( keys(skl), (: strcmp :) );


 				sk = keys(skl);
				for(i=0; i<sizeof(skl); i++) 
				{
					if( sizeof(skl[sk[i]]) <= 0 )
						{
							map_delete(skl, sk[i]);
						}
				}
				
        for(i=0; i<sizeof(skl); i++)
				{
					msg += sprintf(GRN"┌"+BGRN"%21s(%|4d)    "+ BBLK + GRN "───────────────────┐\n"NOR, WHT + chinese_number(sizeof(skl[sk[i]]))+"项"+to_chinese(sk[i]), ob->query_skill(sk[i], 1));
					mapped = sort_array( skl[sk[i]], (: strcmp :) );
					for(j = 0; j < sizeof(skl[sk[i]]); j++)
					{
						str1 = to_chinese(mapped[j]) + " (" + mapped[j] + ")";
						j++;
						if(j < sizeof(skl[sk[i]]))
							str2 = to_chinese(mapped[j]) + " (" + mapped[j] + ")";
						else
							str2 = "";
						msg += sprintf(GRN"│%-32s"NOR + GRN"%-32s│\n"NOR, str1, str2, );
					}
        	if(j>0) { msg +=  sprintf(GRN"└────────────────────────────────┘\n"NOR);}
        }
       write(msg);
       return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : professions|prof 

北大侠客行的职业技能查询指令，可列出目前学会的所有职业技能。

相关命令: survey, cook
HELP
	);
	return 1;
}

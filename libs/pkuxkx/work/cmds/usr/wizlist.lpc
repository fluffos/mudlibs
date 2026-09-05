#pragma save_binary
// wizlist.c
#include <ansi.h>

inherit F_CLEAN_UP;

string* wiz_levels=({
    "(admin)",
    "(arch)",
    "(wizard)",
    "(apprentice)",    
    "(guider)",
    "(player)",
 });

string* respect=({
    HIW "【 天  仙 】" NOR,
    HIY "【 大  仙 】" NOR,
    HIG "【 巫  师 】" NOR,
    HIC "【巫师学徒】" NOR,    
    HIR "【新手导师】" NOR,
    HIC "【 玩  家 】" NOR,  
   });


//string* color=({ HIW,HIG,HIM,HIY,CYN,HIB,BLK,});


int main(object me, string arg)
{
	string *list;
        string id,lvl;
        string ids;

        int i,j;
        write(HIG"北大侠客行于1996年创建自北美侠客行，直接渊源为北大侠客行PKUXKX。"NOR);
        write(HIY"侠客行"HIW"开山祖师"NOR"-"HIR"方舟子\n"NOR);
        write(HIC + MUD_NAME + NOR + "目前的巫师有：\n");
	list = sort_array(SECURITY_D->query_wizlist(), 1);
        for( j=0 ; j<sizeof(wiz_levels) ; j++)
          {
             ids = "";
             for(i=0; i<sizeof(list); i++)
              {
                id = list[i];
                lvl = SECURITY_D->get_status(id);
                if(lvl==wiz_levels[j]) ids += id+"  ";
               }
             if(sizeof(ids))
               printf("%-35s%s%s%c",respect[j] + wiz_levels[j]," : ",ids,'\n');
             
           }
		//printf("%-15s%c", list[i], (i%5==4) ? '\n' : ' ');
	write("\n");
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : wizlist

用途 : 列出目前所有的巫师名单。
HELP
     );
     return 1;
}


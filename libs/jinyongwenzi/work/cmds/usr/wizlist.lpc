// wizlist.c
// by snowman@SJ

#include <ansi.h>

inherit F_CLEAN_UP;

mapping hoodname=([
	"(admin)" :  "【"HIW" 天  神"NOR" 】",
	"(assist)" : "【"HIR" 神  官 "NOR"】",
	"(arch)" : "【"HIY" 龙  神 "NOR"】",
	"(wizard)" : "【"HIG" 仙  人 "NOR"】",
	"(apprentice)" : "【"HIC" 巫  师 "NOR"】",
	"(immortal)" : "【"HIM" 顾  问 "NOR"】"
]);

int level(mixed, mixed);

int imm(string wizid)
{
	return wiz_level(wizid) == 5;
}

int main(object me, string arg)
{
        string *list, hood = "", str;
        int i, j;

        list = sort_array(SECURITY_D->query_wizlist(), (: level :));
	if (!wiz_level(me)) list = filter_array(list, (: imm :));
        str = sprintf("\n╭%-30s───────────────────╮\n",
        	WHT"·书剑目前共有" + chinese_number(sizeof(list)) + "位巫师·"NOR);
	str = replace_string(str, "  ", "─");
	str += "│                                                                    │";
        i = sizeof(list);
        while(i--) {
                if (hood != wizhood(list[i])) {
                        hood = wizhood(list[i]);
                        if( j ){
                        	while(j > 6) j -= 6;
                        	j = 6 - j;
                        	if( j > 0){
                        		while(j--) str += "         ";
					str += "│";
                        	}
                        	else str += "│";
                        }
                        str += sprintf("\n│%-12s："NOR, hoodname[hood]);
                        j = 0;
                }

                j++;
                if( j > 6 && j%6==1 )
                	str += "│\n│\t\t";
		str += sprintf("%-9s", capitalize(list[i]));
        }

        if( j ){
                while(j > 6) j = j - 6;
                j = 6 - j;
                if( j > 0) {
                	while(j--) str += "         ";
			str += "│";
                }

                else str += "│";
        }
        str += "\n│\t\t\t\t\t\t\t\t      │\n";
        str += "╰─────────────────────────────── "WHT"SJ"NOR" ─╯";
        write(str+"\n");
        return 1;
}

int level(mixed ob1, mixed ob2)
{
        if (wiz_level(ob1) != wiz_level(ob2))
                return wiz_level(ob1) - wiz_level(ob2);
        return ob1 > ob2?-1:1;
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

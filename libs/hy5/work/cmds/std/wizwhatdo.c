// wizlist.c
#include <ansi.h>
inherit F_CLEAN_UP;

string *mission;
int level(mixed, mixed);
string get_mission( string );

int main(object me, string arg)
{
        string *list, hood = "", str;
        int j = 0;

        mission = explode(read_file("/adm/daemons/wizmission"), "\n");
        list = sort_array(SECURITY_D->query_wizlist(), (: level :));
        str = HIG"◎ " + HIM MUD_NAME + HIG"目前共有 " + sizeof(list) + " 位巫师：\n"NOR;
        str +=HIW"≡"+HIC"─────────────────────────────────"+HIW"≡\n"NOR;
        for(int i=0; i<sizeof(list); i++, j++) {
                if (hood != wizhood(list[i])) {
                        hood = wizhood(list[i]);
                        switch (hood) { 
                                case "(admin)": str +=HIY"\n【 admin 】\n"NOR;j=0;break;
                                case "(hufa)": if(j%3!=0) str += "\n";str +=HIG"\n【 hufa 】\n"NOR;j=0;break;
 case "(arch)": if(j%3!=0) str += "\n";str +=HIM"\n【 arch 】\n"NOR;j=0;break;
  case "(wizard)": if(j%3!=0) str += "\n";str +=HIC"\n【 wizard  】\n"NOR;j=0;break;
 case "(wiz)": if(j%3!=0) str += "\n";str +=HIC"\n【 wiz 】\n"NOR;j=0;break;
   case "(apprentice)": if(j%3!=0) str += "\n";str +=HIC"\n【 apprentice  】\n"NOR;j=0;break;
case "(immortal)": if(j%3!=0) str += "\n";str +=HIC"\n【 immortal 】\n"NOR;j=0;break;  
                      }
                }
                str += sprintf("%-2s%s %c", list[i], get_mission( list[i] ), (j%3==2) ? '\n' : ' ');
        }
        str +=HIW"\n\n≡"+HIC"────────────────────────"+HIY"巨星泥塘"+HIC"─────"+HIW"≡\n"NOR;

        me->start_more(str);
        return 1;
}

int level(mixed ob1, mixed ob2)
{
        if (wiz_level(ob1) != wiz_level(ob2))
                return wiz_level(ob2) - wiz_level(ob1);
        return ob1 < ob2?-1:1;
}

string get_mission( string wiz)
{
        int i;
        string wname,wmin;
        for(i=0; i<sizeof(mission); i++) {
                if( mission[i][0]=='#' || sscanf(mission[i], "%s %s",
                        wname, wmin)!=2 ) continue;
                if(wname==wiz) return wmin;
        }
        return "(任务未定)";
}

int help(object me)
{
write(@HELP
指令格式 : wizlist

用途 : 列出目前所有的巫师名单及巫师当前任务。
HELP
     );
     return 1;
}

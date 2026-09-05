//modified by icer@pkuxkx
//modified by iszt@pkuxkx, 2007-01-18
//modified by iszt@pkuxkx, 2007-03-30, changed printf to write, error when emote contains %

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object ob,string arg)
{
    //还要加上直接list emote的。。
//    mapping emote;
    int sum = 0;
    if(arg)
    {
        string ke = EMOTE_D->query_all_emote();
        foreach ( string k in ke ) {
            mapping m = EMOTE_D->query_emote(k);
            foreach( string a, string b in m ) {
            if (!b) {
                printf(HIR"emote: %s为空，请报告巫师。\n"NOR,k);
                continue;
            }
                if ( strsrch( b, arg ) >= 0 ) {
                        write(sprintf("符合条件的emote：   %s\n", k));
                        write(b);
                        write("\n");
                    sum ++;
                    break;
                }
            }
            if ( sum > 10 && (!wizardp(this_player()) || sum > 100)) {
//              printf("\nToo many matches, exiting.\n");
                write(HIG"\n查询结果过多，请缩小关键词范围试试。\n"NOR);
                return 1;
            }
        }
        if ( !sum ) {
//          printf("\n No matches.\n");
                write(HIY"系统告诉你：没有找到……\n"NOR);
        }
    return 1;
    }
//    write("Usage: femote <pattern>\nused to find a emote by a pattern\n");
        write("你要查询什么emote？\n");
    return 1;
}
 
int help(object me)
{
        write(@HELP
指令格式: femote <pattern>
 
这个指令可以让你查询符合预设条件的emote。
 
范例: femote 我好喜欢你
结果为 
    符合条件的emote：   wa
    $N对着$n大叫一声：哇徕，好酷哦,我好喜欢你哎！！
 
相关指令: emote semote cemote
 
HELP
    );
    return 1;
}

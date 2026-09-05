// vemote.c ,查看emote
// by whuan@pkuxkx
inherit F_CLEAN_UP;
#include <ansi.h>
string repstr(object me, string arg);
int main(object me, string arg)
{
       mapping emote;
       if( !arg ) 
          return notify_fail("你要察看什么 emote？\n");

       emote = EMOTE_D->query_emote(arg);
       if (sizeof(emote)==0) return notify_fail("没有这个emote！\n");
       printf("Emote："+arg+"    作者：%s\n", emote["updated"]);
       printf("─────────────
不指定对象使用时你看到的信息：
    %s
    
不指定对象使用时别人看到的信息：
    %s

对自己使用的时候自己看到的：
    %s
    
对自己使用的时候别人看到的：
    %s

对别人使用的时候自己看到的：
    %s
    
对别人使用的时候使用对象看到的：
    %s
    
对别人使用的时候其他人看到的：
    %s\n",
       repstr(me,emote["myself"]), 
       repstr(me,emote["others"]), 
       repstr(me,emote["myself_self"]),
       repstr(me,emote["others_self"]), 
       repstr(me,emote["myself_target"]), 
       repstr(me,emote["target"]),
       repstr(me,emote["others_target"]));
       return 1;
}

string repstr(object me, string arg) //替换关键字
{
             string result;
             result = arg;
             if (arg){
             result = F_NAME->replace_color(result);
             result = replace_string(result, "$n", "某人");
             result = replace_string(result, "$N", me->name(1));
             result = replace_string(result, "$P", "你");
             result = replace_string(result, "$p", "(他/她)");
             result = replace_string(result, "$S", RANK_D->query_self(me));
             result = replace_string(result, "$s", RANK_D->query_self_rude(me));
             result = replace_string(result, "$R", "壮士");
             result = replace_string(result, "$r", "臭贼");
             result = replace_string(result, "$C", "愚兄我");
             result = replace_string(result, "$c", "哥哥");
             }
             return result;
}       

int help(object me)
{
write(@HELP
指令格式 : viewemote <emote>
用来察看emote。
 
HELP
          );
          return 1;
}

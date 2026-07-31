// to.c
inherit F_CLEAN_UP;
// Don't want this command be cleaned up while typing long string.
int help(object me);
int do_to(object me, string arg, string str)
{
if(!arg || arg=="chat" || arg=="es" || arg=="rumor" || arg=="mud" || arg=="to" || arg=="say")
        if (!wizardp(me))
           return help(me);
        seteuid(getuid());
        if (strlen(str)>900) str=str[0..900];
        if(arg) me->force_me(arg + " " + str);
        else me->force_me(str);
        return 1;
}
int main(object me, string arg)
{
        if (!arg) return help(me);
        me->edit( (: do_to, me, arg :) );
        return 1;
}
int help(object me)
{
write(@HELP
指令格式 : to <指令>
可以一次输出多行以上的文字, <指令>通常是输出讯息的指令如
say , tell , describe , chat , reple ........等。
范例 : 
 to say
 结束离开用 '.'，取消输入用 '~q'，使用内建列编辑器用 '~e'。
 —————————————————————————————
 江湖风云小混混 : 风雪
 江湖风云小流氓 : 比云天
江湖风云检察院院长 : 风月
江湖风云派出所所长 : 江枫
 .
输出到萤幕上的结果则是 :
自己试一试就知道了
HELP
    );
    return 1;
}


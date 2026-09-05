int main(object me, string arg)
{
 if(me->query("age") < 18)
    {
     write("你至少要到18岁才能一次说这么多话。\n");
     return 1;
    }
 me->edit( (: call_other, __FILE__, "do_to", me, arg :) );
 return 1;
}

void do_to(object me, string arg, string str)
{
 seteuid(getuid());
 if(arg) me->force_me(arg + " " + str);
 else me->force_me(str);
}


int help(object me)
{
write(@HELP
指令格式 : to <指令>

可以一次输出多行以上的文字, <指令>通常是输出讯息的指令如
say , tell , describe , chat , reple ........等。
□例 :
 to say

 ----------------------------------------------------------
 东方神教教主 : 安尼席洛特尔
 教主大夫人暨发呆部部长 : Elon
 教主小老婆暨摸鱼部部长 : 梦忆
 大弟子暨打混部部长 : 风火血舞
 x

输出

你说道：东方神教教主 : 安尼席洛特尔
教主大夫人暨发呆部部长 : Elon
教主小老婆暨摸鱼部部长 : 梦忆
大弟子暨打混部部长 : 风火血舞
HELP
    );
       return 1;
}


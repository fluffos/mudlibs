// /cmds/usr/news.c
// build for news system
// command for reading (players) and editing (wizards) news
// first written by akuma@pkuxk
// ver 1.0
// date 2001/05/22

// plan:
// first we need a newsd.o and a newsd to record what news title we have
// and by what file name they record...
// next what to do is to make some

#include <ansi.h>


int main(object me, string arg)
{
        string titles;
        string onoff;
        int result;
        if(!arg || arg=="")
        {
                NEWS_D->news_list(me);
                return 1;
        }
        if( sscanf(arg,"%s %s",onoff,arg)==2 )
        {
                switch(onoff)
                {
                        case "-e":
                        case "-p":      result=NEWS_D->post_news(me,arg);
                                        switch(result)
                                        {
                                                case -1:
                                                case -2:
                                                case -3:        write("你无权编辑新闻！\n");
                                                                break;
                                                case  1:        write("新闻编辑成功！\n");
                                                                break;
                                        }
                                        break;
                        case "-d":      result=NEWS_D->do_discard(me,arg);
                                        switch(result)
                                        {
                                                case -1:        write("待删除新闻编号错误！\n");
                                                                break;
                                                case -2:        write("没有此条新闻！\n");
                                                                break;
                                                case -3:        write("你无权删除新闻！\n");
                                                                break;
                                                case  1:        write("删除新闻成功！\n");
                                                                break;
                                        }
                                        break;
                }
        }
        else
        {
                result=NEWS_D->read_news(me,arg);
                switch (result)
                {
                        case 1: break;
                        case -1:write("您确定有此条新闻么？\n");
                                break;
                        case -2:write("新闻系统没有这条记录。\n");
                                break;
                }

        }
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : news [编号]

这个指令让用户可以阅读系统新闻，这对您来说可能很重要，因为关于这个游戏的重要通知
可能都会在这里有所说明。在用户每次进入系统的时候，系统将会提示用户有多少未读新闻，
请注意阅读。

具体的使用方法是，直接使用news，则列出所有系统新闻的标题目录，使用news 编号，则
将会显示该条新闻的具体内容。

巫师可以用news [开关] [标题|编号]来对系统新闻进行管理。具体来说:
news -e|-p 标题，可以让巫师编辑新的新闻，
news -d 编号，可以让巫师砍掉系统已经存在的老新闻。
相应的，以后的新闻编号将会从新排列。



HELP
    );
    return 1;
}



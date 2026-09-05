// setfrd.c
#include <ansi.h>
#define MAX_FRIENDS	10

inherit F_CLEAN_UP;


int main(object me, string arg)
{
        int i,number;
    string *terms;
	mapping friends;


	friends = me->query("friends");

	if( !arg || arg=="" ) {
		write("你目前设定的好友名单如下：\n");
		if( !mapp(friends) || !sizeof(friends) )
			write("\t没有设定任何好友。\n");
		else {
			terms = keys(friends);
			for(i=0; i<sizeof(terms); i++)
				printf("%s  ", terms[i]);
                        printf("\n");
		}
		return 1;
	}
        if ( strsrch(arg,"/") != -1 )
                return notify_fail("对不起，你不允许使用这样的设置！\n");

	if( arg && arg!="" ) {
	    if( mapp(friends) && undefinedp(friends[arg]) && sizeof(friends) >= MAX_FRIENDS )
		return notify_fail("你设的好友太多了，请先用 unsetfrd 删掉几个吧。\n");
            me->set("friends/" + arg, 1);
            printf("增加好友：%s  \n", arg);
            return 1;
	}
	return 0;
}
 
int help(object me)
{
        write(@HELP
指令格式:  setfrd <玩家ID>
 
这个指令可以让你设置你的好友名单。
无参数时显示当前好友名单。
 
相关指令: unsetfrd
 
HELP
    );
    return 1;
}

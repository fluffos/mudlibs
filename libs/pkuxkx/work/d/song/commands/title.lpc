// chazhang.c 
// Zine 2012/10/14
inherit F_CLEAN_UP;
#include <ansi.h>
#include <title.h>
int help(object me);
int main(object me,string str)
{
	string title1,title2,*rtype=({"song1","song2","song3","song4","song5"});
	mapping title=(["song1":TITLE_SONG1,"song2":TITLE_SONG2,"song3":TITLE_SONG3,"song4":TITLE_SONG4,"song5":TITLE_SONG5,]);
	if (str=="-h")
	return help(me);
	if ( sscanf(str, "%s %s", title1, title2)!=2  )
    return notify_fail("大宋头衔必须选择两个同时显示。\n");
    if ( !me->check_title(title[title1]) || (title2 && !me->check_title(title[title2])) )
	return notify_fail("错误的头衔类型编号。\n");
	if (member_array(title1,rtype)==-1)
	return notify_fail(title1+"不能通过手动设定为大宋头衔显示。\n");
	if (stringp(title2)&&member_array(title2,rtype)==-1)
	return notify_fail(title2+"不能通过手动设定为大宋头衔显示。\n");
	if ( !me->get_title(title[title1]) ||
	(title2 && !me->get_title(title[title2]) ) )
	return notify_fail("输入的头衔中你并没有全部拥有。\n");
	if (me->get_title(title[title1])==""||me->get_title(title[title2])=="")
	return notify_fail("输入的头衔不能为空的。\n");
	if ( title1==title2 )
	return notify_fail("不能将相同的头衔重复显示。\n");
	if ( !title2 )
	me->set("multi_title", ({HIR"大宋"NOR,title[title1]}));
	else
	me->set("multi_title", ({HIR"大宋"NOR,title[title1], title[title2]}));
	printf("新的大宋头衔显示设置成功。\n");
	printf(BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(me), me->short(1));
	return 1;
}
int help(object me)
{
    write("
指令格式 : title <TITLE_SONGx> 
设定大宋头衔。
"    );
    return 1;
}

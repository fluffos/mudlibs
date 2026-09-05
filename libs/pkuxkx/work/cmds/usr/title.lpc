// title.c (Mon  09-04-95)
// Modified by kiden@pkuxk (2007-11-29) to check other players

#include <ansi.h>
#include <title.h>
inherit F_CLEAN_UP;
int main(object me, string str)
{
    object ob;
    string *ttype=({TITLE_RANK, TITLE_MASTER, TITLE_GROUP,TITLE_MJOB1, TITLE_MJOB2, TITLE_MJOB3, 
    	              TITLE_QUEST1, TITLE_QUEST2, TITLE_QUEST3, TITLE_QUEST4, TITLE_QUEST5,
    	              TITLE_QUEST6, TITLE_QUEST7, TITLE_QUEST8, TITLE_QUEST9, TITLE_QUEST10,
    	              TITLE_TOP1, TITLE_TOP2, TITLE_TOP3, TITLE_TOP4, TITLE_TOP5, 
    	              TITLE_TOP6, TITLE_TOP7, TITLE_TOP8, TITLE_TOP9, TITLE_TOP10, 
    	              TITLE_COMP, TITLE_USER, TITLE_HONOR, TITLE_GRANDM, TITLE_OTHER,TITLE_BANG,
					TITLE_SONG1,TITLE_SONG2,TITLE_SONG3,TITLE_SONG4,TITLE_SONG5}), title1, title2;
    string *ctype=({TITLE_MJOB2, TITLE_MJOB3, TITLE_QUEST2, TITLE_QUEST3, TITLE_QUEST4, TITLE_QUEST5,
    	              TITLE_QUEST6, TITLE_QUEST7, TITLE_QUEST8, TITLE_QUEST9, TITLE_QUEST10, TITLE_TOP2, 
    	              TITLE_TOP3, TITLE_TOP4, TITLE_TOP5, TITLE_TOP6, TITLE_TOP7, TITLE_TOP8, TITLE_TOP9, 
    	              TITLE_TOP10,TITLE_GROUP,TITLE_BANG,TITLE_SONG1,TITLE_SONG2,TITLE_SONG3,TITLE_SONG4,TITLE_SONG5});
	string *rtype=({TITLE_SONG1,TITLE_SONG2,TITLE_SONG3,TITLE_SONG4,TITLE_SONG5});//禁止玩家手工用title命令添加，必须特定情况下触发，zine 2013-4-6
    int lp;
    
    ob=me;
    if ( wizardp(me) && str && !me->check_title(str) )
      ob=find_player(str);

    if ( str && !(wizardp(me) && objectp(ob) && ob!=me) && str!="cancel" )
    {
    	if ( sscanf(str, "%s %s", title1, title2)!=2  )
    		title1=str;
    	if ( !me->check_title(title1) || (title2 && !me->check_title(title2)) )
        return notify_fail("错误的头衔类型编号。\n");
      if ( !me->get_title(title1) ||
      	   (title2 && !me->get_title(title2) ) )
      	return notify_fail("输入的头衔中你并没有全部拥有。\n");
      if (me->get_title(title1)==""||me->get_title(title2)=="")
        return notify_fail("输入的头衔不能为空的。\n");
      if ( title1==title2 )
      	return notify_fail("不能将相同的头衔重复显示。\n");
	  if (member_array(title1,rtype)!=-1)
		return notify_fail(title1+"不能通过手动设定为头衔显示。\n");
	  if (member_array(title2,rtype)!=-1)
		return notify_fail(title2+"不能通过手动设定为头衔显示。\n");
      ob=me;
    }
    else if ( str=="cancel" )
    {
    	me->delete("multi_title");
    	printf("取消头衔显示，头衔显示还原。\n");
    	printf(BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(me), me->short(1));
    	return 1;
    }

    if ( !ob )
        return notify_fail("你要查看谁的头衔？\n");
    
    if ( !wizardp(me) && ob!=me ) 
    	return notify_fail("只有巫师才可以查看他人的头衔?\n");
    
    if ( !title1 )
    {
      printf(BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(ob), ob->short(1));
      if ( ob==me )
        printf("\n"HIC"你目前获取的头衔列表：\n"NOR);
      else
    	  printf("\n"HIC+ob->query("name")+"目前获取的头衔列表：\n"NOR);
      for(lp=0;lp<sizeof(ttype);lp++)
      {
      	if ( member_array(ttype[lp],ctype)>=0 && 
      		   !ob->get_title(ttype[lp]) )
          continue;
        printf(HIY"%12s"NOR" %-40s - %-80s\n", 
               ttype[lp], ob->check_title(ttype[lp]), 
               (ob->get_title(ttype[lp])?ob->get_title(ttype[lp]):"未获得此头衔"));
      }
    }
    else
    {

    	if ( !title2 )
    		me->set("multi_title", ({title1}));
    	else
    		me->set("multi_title", ({title1, title2}));
    	printf("新的头衔显示设置成功。\n");
      printf(BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(ob), ob->short(1));
    }
    
    return 1;
}
 
int help(object me)
{
    write(@HELP
指令格式: title <对象> or title <头衔ID> <头衔ID> or title cancel
显示对象目前的阶级和头衔。
或者设置两个头衔列表中存在的头衔进行显示。
或者取消新的头衔显示方式，选择默认的显示方式。
 
HELP
    );
}

// player.c 显示大宋在线玩家
// Zine 2012/10/14
inherit F_CLEAN_UP;
#include <ansi.h>
#include <title.h>
int help(object me);
int sort_user(mapping user1,mapping user2)
{
	if(user1["true_pin"] &&user2["true_pin"]  &&user1["true_pin"]  !=user2["true_pin"] )
		return user2["true_pin"]  - user1["true_pin"] ;
	if( user1["credit"] != user2["credit"]  )
		return user1["credit"] - user2["credit"];
	return strcmp(user2["id"], user1["id"]);
}
string stars(int rank)
{
	switch (rank)
	{
	case 0:
	return "";
	case 1:
	return HIY+"★★★★★";
	case 2:
	return HIY+"★★★★☆";
	case 3:
	return HIY+"★★★★";
	case 4:
	return HIY+"★★★☆";
	case 5:
	return HIY+"★★★";
	case 6:
	return HIY+"★★☆";
	case 7:
	return HIY+"★★";
	case 8:
	return HIY+"★☆";
	case 9:
	return HIY+"★";
	case 10:
	return HIY+"☆";
	case 11:
	return "";
	case 12:
	return "";
	}
}
mapping record_newuser(object me)
{
	mapping new_user=(["name":"","id":"","pro":"","title":"","pin":"","deco":"","jue":"","player":0,"credit":0,"true_pin":0]);
	new_user["name"]=me->query("name");
	new_user["id"]=me->query("id");
	if (me->query("song/pro")=="文")
	new_user["pro"]=HBBLU+HIW+"●文臣●"+NOR;
	else if (me->query("song/pro")=="武")
	new_user["pro"]=HBRED+HIW+"●武将●"+NOR;
	else if (me->query("song/pro")=="宦")
	new_user["pro"]=HBMAG+HIW+"●中官●"+NOR;
	else
	new_user["pro"]=HBGRN+HIW+"●散官●"+NOR;
	if (me->get_title(TITLE_SONG1)) 
	new_user["title"]=me->get_title(TITLE_SONG1);
	else if (me->get_title(TITLE_SONG2))
	new_user["title"]=me->get_title(TITLE_SONG2);
	new_user["pin"]=HIR+"大宋 "+HIW+DASONG_D->my_pin(me)+NOR;
	if (stars(me->query("song/xunjue/rank"))!="")
	new_user["deco"]=stars(me->query("song/xunjue/rank"))+NOR;
	if (me->get_title(TITLE_SONG5))
	new_user["jue"]=me->get_title(TITLE_SONG5)+NOR;
	new_user["player"]=me;
	new_user["true_pin"]=DASONG_D->get_my_pin(me);
	new_user["credit"]=me->query("song/credit");
	return new_user;
}
int main(object me, string arg)
{
		string dm_title,str;
		mapping *list;
		int j,len,wen=0,wu=0,huan=0;
		if (arg=="-h")
		return help(me);
		if (time()>1422709200&&time()<1423321200&&!wizardp(me))
		return notify_fail("等等，系统喘气中......\n");
		list=DASONG_D->get_online_users();
		if (list==({}))
		return notify_fail("大宋官员列表错误。\n");
		list=sort_array(list,"sort_user");
		me->set_temp("scan_time",time());
		str =sprintf("%|94s\n","「" +HIR+ "大宋在线官员列表" + NOR + "」");
		str += "------------------------------------------------------------------------------\n";
		j = sizeof(list);
		while( j-- ) 
		{
                        // Skip those users in login limbo.
			if(!list[j]["player"]|| !environment(list[j]["player"])||!me->visible(list[j]["player"]) ) continue;
			if (strsrch(list[j]["pro"],"文")!=-1)
			wen+=1;
			if (strsrch(list[j]["pro"],"武")!=-1)
			wu+=1;
			if (strsrch(list[j]["pro"],"中")!=-1)
			huan+=1;
			dm_title=list[j]["title"];
			if (stringp(list[j]["deco"])&&list[j]["deco"]!="")
			dm_title+=list[j]["deco"];
			if (stringp(list[j]["jue"])&&list[j]["jue"]!="")
			dm_title+="  ";
			dm_title+=list[j]["jue"];
			dm_title+=NOR;
			str+= sprintf("%|26s%s%|35s%s%s",COLOR_D->uncolor(list[j]["name"])+"("+list[j]["id"]+")","|",list[j]["pro"],"|",list[j]["pin"]+" "+dm_title);
			str+="\n";
		}
		str += "------------------------------------------------------------------------------\n";
		str +=sprintf("%|94s\n",HIR+"大宋"+NOR+"此刻共有"+chinese_number(wen)+"位文臣，"+chinese_number(wu)+"位武将，"+chinese_number(huan)+"位中官在线。",);
		tell_object(me,str);
		return 1;
}
int help(object me)
{
    write("
指令格式 : song players
显示大宋在线玩家。
"    );
    return 1;
}

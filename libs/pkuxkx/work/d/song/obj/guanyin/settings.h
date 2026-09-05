#include <ansi.h>
#define RECORD "/d/song/record/other"
#define SZ   HIY"██████████████████████████████████████████████\n"NOR
int to_do_list(object me);
int is_song_player(object me)
{
	if (!me||!userp(me)||DASONG_D->get_my_pin(me)<1||DASONG_D->get_my_pin(me)>9)
	return 0;
	return 1;
}

int checK_position(object me)
{
	object ob=load_object("/d/song/record/positions");
	mapping *title;
	if (!is_song_player(me))
	return 1;
	if (ob->query("give_titles"))
	title=ob->query("give_titles");
	else
	title=DASONG_D->upper_title();
	for (int i=0;i<sizeof(title);i++)
	{
		if (title[i]["title"]==me->query("song/title")&&title[i]["pro"]!=me->query("song/pro"))
		{
			me->set_temp("song/hor_promote",2);
			DASONG_D->position_me(me);
			return 1;
		}
	}
	if (DASONG_D->get_my_pin(me)>0&&DASONG_D->get_my_pin(me)<=3)
	{
		for (int i=0;i<sizeof(title);i++)
		{
			if (title[i]["title"]==me->query("song/title")&&title[i]["pro"]==me->query("song/pro"))
			{
				if (title[i]["owner"]=="")
				{
					title[i]["owner"]=me->query("id");
					title[i]["owner_name"]=me->query("name");
				}
				if (arrayp(title[i]["owner"])&&title[i]["vacacy"]>0)
				{
					title[i]["vacacy"]-=1;
					title[i]["owner"]+=({me->query("id")});
					title[i]["owner_name"]+=({me->query("name")});
				}
			}
		}
		ob->set("give_titles",title);
		ob->save();
	}
	return 1;
}
int judge_extra_room(object me)
{
	object song=load_object(RECORD);
    string *names=({});
	if (!is_song_player(me))
	return 1;
	if (song->query("extra_home_list"))
	names=song->query("extra_home_list");
	if (member_array(me->query("id"),names)==-1)
	{
		if (me->query("song/extra_room_by_gongbu"))
		{
			me->delete("song/extra_room_by_gongbu");
			tell_object(me,"工部拆除了你储物间中扩建的部分。\n");
		}
	}
	else
	{
		if (!me->query("song/extra_room_by_gongbu"))
		{
			me->set("song/extra_room_by_gongbu",1);
			tell_object(me,"工部扩建了你的储物间。\n");
		}
	}
	return 1;
}
int notice(object me)
{
	int i,num,news_num,flag=0;
	mapping* notes;
	string msg;
	object notice;
	if (!is_song_player(me))
	return 1;
	notice=load_object("/clone/board/dasong_notice_b");
	num=me->query("song/news_notice/nums");
	notes=notice->query("notes");
	if (DASONG_D->get_my_pin(me)!=1&&me->query("song/suikao/time")&&me->query("mud_age")-me->query("song/suikao/time")>3600*24*2)
	{
		if (me->query("song/suikao/time")&&me->query("mud_age")-me->query("song/suikao/time")>3600*24*4)
		{
			tell_object(me,BLINK+HIR+"你已经超过四次没有参加岁考了。\n"+NOR);
			return 1;
		}
		tell_object(me,"你已经超过两次没有参加岁考了。\n");
		return 1;
	}
	if (!notes)
	return 1;
	news_num=sizeof(notes)-1;
	msg="\n\n"+SZ+HIY+"门下：\n"NOR;
	me->set("song/news_notice/nums",news_num);
	for (i=num;i<=news_num;i++)
    {
		if (i!=num)
		{
			msg+=HBWHT+HIR+"【大宋更新】"+notes[i]["title"]+NOR;
			msg+="\n";
		}
        flag=1;
        if (num==news_num)
        {
            flag=0;
        }
    }
    msg+=sprintf("\n%100s\n",HIY+"御押"+NOR);
    msg+=SZ;
    if (flag==1)
	tell_object(me,msg);
	return 1;
}


int deal(string arg,object ob,object me,int i)
{
	object pl;
	if (arg=="yes"||arg=="y"||arg=="Yes"||arg=="Y")
	{
		ob->set("todo_list/"+me->query("song/depart")+"/"+i+"/state","同意");
		tell_object(me,"你同意了这个请求。\n");
		if (pl=find_player(ob->query("todo_list/"+me->query("song/depart")+"/"+i+"/from")))
		tell_object(pl,"你的"+ob->query("todo_list/"+me->query("song/depart")+"/"+i+"/what")+"要求，被"+me->query("name")+"同意了。\n");
	}
	else
	{
		ob->set("todo_list/"+me->query("song/depart")+"/"+i+"/state","拒绝");
		tell_object(me,"你拒绝了这个请求。\n");
		if (pl=find_player(ob->query("todo_list/"+me->query("song/depart")+"/"+i+"/from")))
		tell_object(pl,"你的"+ob->query("todo_list/"+me->query("song/depart")+"/"+i+"/what")+"要求，被"+me->query("name")+"拒绝了。\n");
	}
	ob->save();
	for (i=0;i<1000;i++)
	{
		if (ob->query("todo_list/"+me->query("song/depart")+"/"+i)&&ob->query("todo_list/"+me->query("song/depart")+"/"+i+"/state")=="pending")
		to_do_list(me);
	}
	return 1;
}
int to_do_list(object me)
{
	object ob=load_object(RECORD);
	int i,flag=0;
	string msg="现在急需要你处理的事务：\n";
	if (!is_song_player(me)||DASONG_D->get_my_pin(me)>3)
	return 1;
    for (i=0;i<1000;i++)
    {
        if (ob->query("todo_list/"+me->query("song/depart")+"/"+i)&&ob->query("todo_list/"+me->query("song/depart")+"/"+i+"/state")=="pending")
        {
            msg+="["+i+"]";
            msg+=ob->query("todo_list/"+me->query("song/depart")+"/"+i+"/from")+"\t";
            msg+=ob->query("todo_list/"+me->query("song/depart")+"/"+i+"/what");
            tell_object(me,"请选择处理意见。(Yes or No)");
            input_to( (: deal :),ob,me,i);
            return 1;
        }
    }
}

int check_me_in(object me)
{
	call_out("checK_position",4,me);
    call_out("judge_extra_room",2,me);
    call_out("notice",3,me);
    call_out("to_do_list",6,me);
}
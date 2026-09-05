#include <ansi.h>
mapping *meeting_details=({
(["file":"/d/song/shangshu1-2","place":"政事堂值房","attendees":({"同中书门下平章事","参知政事"}),"meeting_name":"政事堂例会","respect_attendee":"宰相","annunciate_pre":"【大宋】政事堂：即将继续政事堂例会，请你赶紧到政事堂出席例会。本次例会将由","annunciate_post":"主持。\n"]),
});
object *real_attendees()
{
	object *attendees=DASONG_D->song_all();
	for (int i=0;i<sizeof(attendees);i++)
	{
		if (!DASONG_D->identification(attendees[i],({"同中书门下平章事","参知政事"})))
		attendees-=({attendees[i]});
		if (!present(attendees[i],this_object()))
		attendees-=({attendees[i]});
	}
	return attendees;
}
string *get_candidates(string place)
{
	mapping *titles=({});
	string *ids=({});
	if (place=="政事堂值房")
	{
		if (arrayp("/d/song/record/positions"->query("give_titles")))
		titles="/d/song/record/positions"->query("give_titles");
		for (int i=0;i<sizeof(titles);i++)
		{
			if (titles[i]["title"]=="同中书门下平章事"||titles[i]["title"]=="参知政事")
			ids+=titles[i]["owner"];
		}
	}
	return ids;
}
mapping pre_allocate(string place)
{
	string libu="NPC",gongbu="NPC",bingbu="NPC",hubu="NPC",libu2="NPC",xingbu="NPC",taijian="NPC";
	mapping pre_leaders=(["吏部尚书":libu,"工部尚书":gongbu,"兵部尚书":bingbu,"户部尚书":hubu,"礼部尚书":libu2,"刑部尚书":xingbu,"御史中丞":taijian,]);
	mapping place_id=(["政事堂值房":"ZhengShi","三司使":"SanSi","枢密院":"ShuMi"]);
	string pl,*candidates,*departs,depart;
	if (place=="政事堂值房")
	{
		candidates=get_candidates("政事堂值房");
		departs=({"吏部尚书","工部尚书","兵部尚书","户部尚书","礼部尚书","刑部尚书","御史中丞"});
		if (sizeof(candidates))
		{
			while (sizeof(candidates))
			{
				depart=departs[random(sizeof(departs))];
				departs-=({depart});
				pl=candidates[random(sizeof(candidates))];
				candidates-=({pl});
				pre_leaders[depart]=pl;
			}
		}
	}
	"/d/song/record/positions"->set("TopLevel/"+place_id[place]+"/details",pre_leaders);
	"/d/song/record/positions"->set("TopLevel/"+place_id[place]+"/time",time());
	"/d/song/record/positions"->save();
	return pre_leaders;
}
int allocate(object me,string place)
{
	mapping result;
	string msg,*departs,*leaders;
	message_vision("$N看了一眼与会众人，道：“我们今天讨论一下分管工作”。\n",me);
	result=pre_allocate(place);
	leaders=values(result);
	departs=keys(result);
	msg="分管将分配如下，\n";
	for (int i=0;i<sizeof(leaders);i++)
	{
		if (leaders[i]=="NPC")
		continue;
		else
		msg+=HIR+capitalize(leaders[i])+NOR+"掌"+CYN+replace_string(replace_string(departs[i],"尚书",""),"中丞","")+NOR+"\n";
	}
	tell_room(this_object(),msg);
	return 1;
}
object *get_attendees(string * attendees)
{
	object *results=({}),*all_pl=all_inventory(this_object());
	all_pl = DASONG_D->song_players();
	for (int i=0;i<sizeof(all_pl);i++)
	{
		if (DASONG_D->identification(all_pl[i],attendees))
		results+=({all_pl[i]});
	}
	return results;
}
int do_meeting()
{
	int flag=0;
	string *attendees,place,meeting_name,respect_attendee,pre,post;
	object me=this_player(),*true_attendees=({});
	for (int i=0;i<sizeof(meeting_details);i++)
	{
		if (meeting_details[i]["file"]==base_name(this_object()))
		{
			place=meeting_details[i]["place"];
			attendees=meeting_details[i]["attendees"];
			meeting_name=meeting_details[i]["meeting_name"];
			respect_attendee=meeting_details[i]["respect_attendee"];
			pre=meeting_details[i]["annunciate_pre"];
			post=meeting_details[i]["annunciate_post"];
			flag=1;
			break;
		}
	}
	if (!flag)
	return -1;
	if (query("host")&&query("host")!=me)
	{
		tell_object(me,"这里的会议将有"+query("host")->query("name")+"主持。\n");
		return 1;
	}
	if (!DASONG_D->identification(me,attendees))
	{
		tell_object(me,"你没有资格主持一次"+meeting_name+"。\n");
		return 1;
	}
	if (DASONG_D->load_time(place+"_meeting")!=-1&&time()-DASONG_D->load_time(place+"_meeting")<604800)
	{
		tell_object(me,place+"不久前才举行过一次例会，还需要等到"+CHINESE_D->chinese_period(604800+DASONG_D->load_time(place+"_meeting")-time())+"后才能举行下次例会。\n");
		return 1;
	}
	true_attendees=get_attendees(attendees);
	if (sizeof(true_attendees)<2)
	{
		tell_object(me,"举行例会至少得有两位"+respect_attendee+"在场吧？\n");
		return 1;
	}
	set("attendee_type",attendees);
	set("attendees",true_attendees);
	set("host",me);
	message("chat",HIR+pre+me->query("name")+HIR+post+NOR,true_attendees,({me}));
	tell_object(me,"你发起召集开始例会的官文，其他"+respect_attendee+"们应该很快就会收到。\n");
	return 1;
}
int do_discuss(string arg)
{
	object me=this_player();
	string *legal_issues=({"allocate"});
	if (query("host")!=me)
	return notify_fail("只有主持例会的人才能决定讨论议题。\n");
	if (sizeof(get_attendees(query("attendee_type")))<2)
	return notify_fail("至少要有两名与会者才能开始讨论议题。\n");
	if (!arg)
	return notify_fail("你想在例会上讨论什么？\n");
	if (query("meeting_start"))
	return notify_fail("例会已经开始了。\n");
	if (member_array(arg,legal_issues)==-1)
	return notify_fail(arg+"不是一个可行的议题，你可以用host命令了解今天的议题。\n");
	set("meeting_start",1);
	DASONG_D->save_time(COLOR_D->uncolor(this_object()->query("short"))+"_meeting");
	if (arg=="allocate")
	return allocate(me,COLOR_D->uncolor(environment(me)->query("short")));
}

string get_issues()
{
	string *issue=({"分管工作(discuss allocate)"});
	string msg="本次例会议题：\n";
	msg+=issue[random(sizeof(issue))]+"\n";
	return msg;
}
int do_host()
{
	object me=this_player();
	string issues;
	if (!query("attendees"))
	return 0;
	if (member_array(me,query("attendees"))==-1)
	return 0;
	if (query("host")!=me)
	return notify_fail("本次例会不是交由你主持。\n");
	issues=get_issues();
	write(issues);
	return 1;
}

void init()
{
	add_action("do_host","host");
	add_action("do_meeting","meeting");
	add_action("do_discuss","discuss");
}
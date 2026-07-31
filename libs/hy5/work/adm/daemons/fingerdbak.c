// fingerd.c
// change for netplay@CCTX

#include <net/dns.h>
#include <mudlib.h>

int query_only_ip(object *ob);

//add by jackyboy for finger display!
int online_time(object);
int online_time_total(object);

void create() { seteuid( getuid() ); }

string age_string(int time)
{
	int month, day, hour, min, sec;

	sec = time % 60;
	time /= 60;
	min = time % 60;
	time /= 60;
	hour = time % 24;
	time /= 24;
	day = time % 30;
	month = time / 30;
	return (month?month + "m":"") + (day?day + "d":"") + 
	(hour?hour + "h":"") + min + "m";
}

int online_time(object body)
{
	return time() - (int)body->query_temp("temp_time");
}
int online_time_total(object body)
{
	return body->query("time_aged")+time()-(int)body->query_temp("temp_time");
}
string finger_all()
{
	object *ob;
	string msg, fip,*str;
	int i,ips;

	//ob = users();
	ob = sort_array(users(), "ip_name", this_object());
	msg = "";
	if ( !wizardp(this_player()) )  // player finger
	{
		for(i=0; i<sizeof(ob); i++) {
			if( this_player() && !this_player()->visible(ob[i]) ) continue;
			msg = sprintf("%s%-14s%-14s%-14s\n",
				msg, ob[i]->query("name"), ob[i]->query("id"),
				query_idle(ob[i]) + "s");
		}
		return "◎ "+CHINESE_MUD_NAME+" ◎\n" + 
		"——————————————————\n"
		+ "姓名          帐号          发呆\n" +
		"——————————————————\n"
		+ msg +
		"——————————————————\n";
	} else  	// wizard finger
	{
		for(i=1; i<sizeof(ob); i++) {
			if( this_player() && !this_player()->visible(ob[i]) ) continue;
			msg = sprintf("%s%-14s%-14s%-14s%-7s%s\n",
				msg, ob[i]->query("name"), ob[i]->query("id"),
				age_string( (int)ob[i]->query("mud_age")), 
				query_idle(ob[i]) + "s", wizardp(ob[i])?"未知":query_ip_number(ob[i]));
//				query_idle(ob[i]) + "s", query_ip_name(ob[i]));

				}
if (this_player())
		ips=query_only_ip(ob);
else ips=40+random(40);
			return "◎ "+CHINESE_MUD_NAME+" ◎\n" 
                         "排除由同一IP登录的人后，实际有："+ips+"人\n"
		"—————————————————————————————————————\n"
		+ "姓名          帐号          年龄          发呆   连线\n" +
		"—————————————————————————————————————\n"
		+ msg +
		"—————————————————————————————————————\n"
		+"排除由同一IP登录的人后，实际有："+ips+"人\n";
	}
}
	
string finger_user(string name)
{
	object ob, body;
	string msg, mud;
string wiz_status;
	int public_flag;
//本函数由JackyBoy重新编写并优化！
	if( sscanf(name, "%s@%s", name, mud)==2 ) {
		GFINGER_Q->send_finger_q(mud, name, this_player(1));
		return "网路指令传送过程可能需要一些时间，请稍候。\n";
	}

	ob = new(LOGIN_OB);
	ob->set("id", name);
	if( !ob->restore() ) 
		return "没有这个玩家。\n";
	if( objectp(body = find_player(name)) && geteuid(body)==name )
	{
		if(wizardp(this_player()))
			public_flag=1;
		else
			public_flag =body->query("env/public")?1:0;
	}
	else 
	{
		if( !ob) 
			return "没有这个玩家。\n";

		body = LOGIN_D->make_body(ob);
		if( !body) 
			return "没有这个玩家。\n";
		if( !body->restore() ) 
			return "没有这个玩家。\n";
		if(wizardp(this_player()))
			public_flag=1;
		else
			public_flag =body->query("env/public")?1:0;
		destruct(body);
	}		
	msg =  sprintf("\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
		"电子邮件地址：\t%s\n上次连线：\t%s\n\n",
		ob->query("id"),
		ob->query("name"),
		SECURITY_D->get_status(name),
		public_flag?ob->query("email"):"不告诉你",
		"("+(wizardp(this_player(1))?ob->query("last_from"):"未知")+") "+
		ctime(ob->query("last_on")));
	if(!ob->query("profile")||ob->query("profile")=="")
		msg+="没有自我介绍。\n\n";
	else
		msg+=ob->query("profile")+"\n\n";
	if( objectp(body = find_player(name)) && geteuid(body)==name && 
		this_player()->visible(body))
	{
	wiz_status = SECURITY_D->get_status(body);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
{
		msg += sprintf("\n%s目前正从%s连线中。\n", body->name(1),
			wizardp(this_player(1))?query_ip_number(body):"未知");
}
else
{	wiz_status = SECURITY_D->get_status(this_player(1));
	if( wiz_status == "(admin)")
{
		msg += sprintf("\n%s目前正从%s连线中。\n", body->name(1),
			wizardp(this_player(1))?query_ip_number(body):"未知");
}
else 	msg += sprintf("\n%s目前正从保密处连线中。\n", body->name(1));
}
	}
		destruct(ob);
	return msg;
}

varargs string remote_finger_user(string name, int chinese_flag)
{
	object ob, body;
	string msg;
	ob = new(LOGIN_OB);
	ob->set("id", name);
	if( !ob->restore() )
		return chinese_flag ? "没有这个玩家。\n" : "No such user.\n";
	if( chinese_flag ) msg =  sprintf(
		"\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
		"电子邮件地址：\t%s\n上次连线地址：\t%s( %s )\n\n",
		ob->query("id"),
		ob->query("name"),
		SECURITY_D->get_status(name),
		ob->query("email"),
		"未知",
		ctime(ob->query("last_on")));
	else msg =  sprintf(
		"\nName\t: %s\nStatus\t: %s\nEmail\t: %s\nLastOn\t: %s( %s )\n\n",
		capitalize(ob->query("id")),
		SECURITY_D->get_status(name),
		ob->query("email"),
		wizardp(this_player(1))?ob->query("last_from"):"Unknow",
		ctime(ob->query("last_on")));
	if(!ob->query("profile")||ob->query("profile")=="")
		msg+="没有自我介绍。\n\n";
	else
		msg+=ob->query("profile")+"\n";
	if( body = find_player(name) ) {
		if( !this_player() || this_player()->visible(body) )
		{
			if(chinese_flag)
			{
				msg+="\n" + ob->query("name") + "目前正在连线。\n";
			}
			else
				msg+="\n" + capitalize(name) + " is currently connected.\n";
		}
	}
	destruct(ob);
	return msg;
}

object acquire_login_ob(string id)
{
	object ob;

	if( ob = find_player(id) ) {
		// Check if the player is linkdead
		if( ob->query_temp("link_ob") )
			return ob->query_temp("link_ob");
	}
	ob = new(LOGIN_OB);
	ob->set("id", id);
	return ob->restore() ? ob : 0;
}

string get_killer()
{
	int i;
	string msg;
	object *ob = users();

	msg = "";
	for (i = 0; i < sizeof(ob); i++)
		if ((int)ob[i]->query_condition("killer"))
			msg += (ob[i]->short() + "\n");
	if (msg == "")
		return "本城治安良好。\n";
	else
		return "现在本城正在缉拿以下人犯：\n\n" + msg;
}
/*
string get_win_mengzhu()
{
	int i;
	object mengzhu, *ob = users();
        string name;

        mengzhu = load_object("/clone/npc/meng-zhu");
        name = mengzhu->query("winner");

	for (i = 0; i < sizeof(ob); i++)
        if ((int)ob[i]->query("win_mengzhu")> 0) {
              if ( ob[i]->query("id") != name ) {
                 (int)ob[i]->delete("win_mengzhu");
              } else { return 0;}
        } else { return 0;}
}*/
//以下函数排除同一个IP连线的
//write by JackyBoy@CuteRabbits Studio for CCTX 1999/4/9
int query_only_ip(object *ob)
{	
	int i,j,k,count,total,sl;
  string ipa,ipb;
	total=sizeof(ob);
	sl=sizeof(ob);
	for ( i=0; i<sizeof(ob); i++)
	{
		count=1;k=sizeof(ob);
		for (j=0; j<k;j++)
  			if ( j!=i && query_ip_name(ob[i])==query_ip_name(ob[j]) )
			{
				ob=ob-({ob[j]});
				count++;
				k=sizeof(ob);
			}
		total=total-count+1;
	}
	return total;
}

int ip_name(object ob1, object ob2)
{
        string name1, name2;
        
        name1 = query_ip_name(ob1);
        name2 = query_ip_name(ob2);

        if (intp(name1)) name1 = "";
        if (intp(name2)) name2 = "";
        if (name1 > name2) return -1;
        if (name1 < name2) return 1;

        return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}


// fingerd.c
//fix by yhzzyahoo,开放可以对导师finger
#include <net/dns.h>
#include <ansi.h>

void create() { seteuid( ROOT_UID ); }
int query_only_ip(object *ob)
{       
        int i,j,k,count,total;

        total=sizeof(ob);
        reset_eval_cost();
        for ( i=0; i<sizeof(ob); i++)
        {
                count=1;k=sizeof(ob);
                for (j=k-1; j>i;j--)
                        if (query_ip_number(ob[i])==query_ip_number(ob[j]) )
                        {
                                ob=ob-({ob[j]});
                                count++;
                                k=sizeof(ob);
                        }
                total=total-count+1;
        }
        return total;
}

int sort_user(object ob1, object ob2)
{
		string ipfrom1,ipfrom2;
	
        reset_eval_cost();
        if( wizardp(ob1) && !wizardp(ob2) ) return 1;
        
        if( wizardp(ob2) && !wizardp(ob1) ) return -1;

        if( wizardp(ob1) && wizardp(ob2) )
                return (int)SECURITY_D->get_wiz_level(ob1) 
                        - (int)SECURITY_D->get_wiz_level(ob2);
        if( ob1->query("id") && !ob2->query("id") )
                return 1;

        reset_eval_cost();
        if( ob2->query("id") && !ob1->query("id") )
                return -1;

        if( !ob1->query("id") && !ob2->query("id") )
                return (int)ob1->query("combat_exp") - (int)ob2->query("combat_exp");
		ipfrom1 = ob1->query_temp("ip_from/from1");
		ipfrom2 = ob2->query_temp("ip_from/from1");
		if (!ipfrom1) ipfrom1 = "";
		if (!ipfrom2) ipfrom2 = "";
		if (ipfrom1 == ipfrom2)
        	return strcmp(query_ip_number(ob1),query_ip_number(ob2));
        else return strcmp(ipfrom1,ipfrom2);
}


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
        return (month?month + "月":"") + (day?day + "天":"") + 
        (hour?hour + "小时":"") + min + "分";
}

string finger_all()
{
        object *ob;
        string msg, fip;
        int i,ips;

        ob = users();
        msg = "";
        reset_eval_cost();
        if ( !wizardp(this_player()) )  // player finger
        {
                reset_eval_cost();
                for(i=0; i<sizeof(ob); i++) {
                        if( this_player() && !this_player()->visible(ob[i]) || ob[i]->query_temp("apply/name") ) continue;
                        msg = sprintf("%s%-14s%-14s%-14s\n",
                                msg, ob[i]->query("name"), ob[i]->query("id"),
                                query_idle(ob[i]) + "s");
                }
                 return "《北大侠客行》\n" +
                "------------------------------------\n"
                + "姓名          帐号          发呆\n" +
                "------------------------------------\n"
                + msg +
                "------------------------------------\n";
        } else          // wizard finger
        {
                ob = sort_array(users(), "sort_user", this_object());
                for(i=0; i<sizeof(ob); i++) {
                reset_eval_cost();
                        if( this_player() && !this_player()->visible(ob[i]) || ob[i]->query_temp("apply/name")  ) continue;
                        msg = sprintf("%s%-14s%-14s%-19s%-7s%-19s%s\n",
                                msg, ob[i]->query("name"), ob[i]->query("id"),
                                age_string( (int)ob[i]->query("mud_age")), 
                                query_idle(ob[i]) + "s", (i<1?query_ip_number(ob[i]):
(query_ip_number(ob[i])==query_ip_number(ob[i-1])?HIR+query_ip_number(ob[i])+NOR:
                                query_ip_number(ob[i]))),(i<1?ob[i]->query_temp("ip_from/from1") 
                                + " " + ob[i]->query_temp("ip_from/from2"):
(query_ip_number(ob[i])==query_ip_number(ob[i-1])?"":
                                ob[i]->query_temp("ip_from/from1") 
                                + " " + ob[i]->query_temp("ip_from/from2"))));
//query_ip_number(ob[i]));
                }
                ips=query_only_ip(ob);
                 return "《北大侠客行》\n" +
                "--------------------------------------------------------------------------------------------------\n"
                + "姓名           帐号          上线时间         发呆        连线            来自\n" +
                "--------------------------------------------------------------------------------------------------\n"
                + msg +
                "--------------------------------------------------------------------------------------------------\n"

                +"注：排除由同一IP连线，实际登陆有 "+ips+" 人。\n";
        }
}
        
string finger_user(string name)
{
        object ob, body;
        string msg, mud, status;
        int public_flag;
        int wiz_flag,i;
        string logintime,sameip,myip;
        object *users;

/*      if( sscanf(name, "%s@%s", name, mud)==2 ) {
                GFINGER_Q->send_finger_q(mud, name, this_player(1));
                return "网路指令传送过程可能需要一些时间，请稍候。\n";
        }
*/
        ob = new(LOGIN_OB);
        ob->set("id", name);
        if( !ob->restore() ) return "没有这个玩家。\n";
        
        
        status = SECURITY_D->get_status(name);
        if( objectp(body = find_player(name)) && geteuid(body)==name )
        {
                public_flag = body->query("env/public")?1:0;
//                if (body->query("nowiz")) status = "(player)";
        } else 
        {
                        body = LOGIN_D->make_body(ob);
                        if( !body->restore() ) return "没有这个玩家。\n";
                        public_flag = body->query("env/public")?1:0;
//                if (body->query("nowiz")) status = "(player)";
                        destruct(body);
        }               
        if ( !wizardp(this_player()) || SECURITY_D->get_wiz_level(this_player()) <= SECURITY_D->get_wiz_level(name) )  // player finger
        {
            if(status != "(player)") {
				if (status !="(guider)")
				{
		            logintime = "不告诉你";
				}
				else
				{
	            logintime = ctime(ob->query("last_on"));
				}

            } else
            {
            logintime = ctime(ob->query("last_on"));
            }
                
                msg =  sprintf("\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
                        "电子邮件地址：\t%s\n上次连线：\t%s\n\n",
                        ob->query("id"),
                        ob->query("name"),
                        status,
                        public_flag?ob->query("email"):"不告诉你",
                        logintime
                );
           if( objectp(body = find_player(name)) && geteuid(body)==name 
                  && this_player()->visible(body) && !body->query_temp("apply/name") ) {
                        msg += sprintf("\n%s目前正在连线中。\n", body->name(1));
                }
        } else          // wizard finger
        {
                msg =  sprintf("\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
                        "电子邮件地址：\t%s\n上次连线地址：\t%s( %s )\n\n",
                        ob->query("id"),

                        ob->query("name"),
                        status,
                        ob->query("email"),
                        ob->query("last_from"),
                        ctime(ob->query("last_on"))
                );
                myip = ob->query("last_from");
                if( (objectp(body = find_player(name))||objectp(body = find_living(name))) && geteuid(body)==name && this_player()->visible(body) ) 
                {
                        msg += sprintf("\n%s的IP是 %s ，", body->name(1),
                                body->query_temp("ip"));
                        if (!query_ip_number(body))
                        {
                            msg += sprintf("目前已断线!\n");
                        }
                        else
                        {
                            msg += sprintf("目前正在连线中!\n");
                        }

                     	sameip = "";
                     	users = users();
                     	myip = body->query_temp("ip");
                     	for (i=0;i<sizeof(users);i++)
                     		if ((users[i]->query_temp("ip")==myip) && (users[i] != body))
                     			sameip += users[i]->query("name") + "(" + users[i]->query("id") + ") ";
                     	if (sameip != "")
                     		msg += "与" + name + "在同一IP连线的有：" + sameip + "\n";
                }	
              //  tell_object(this_player(),load_object("/adm/daemons/webd")->query_web(this_player(),myip,"IP"));
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
                ob->query("last_from"),
                ctime(ob->query("last_on"))
        );
        else msg =  sprintf(
                "\nName\t: %s\nStatus\t: %s\nEmail\t: %s\nLastOn\t: %s( %s )\n\n",
                capitalize(ob->query("id")),
                SECURITY_D->get_status(name),
                ob->query("email"),
                ob->query("last_from"),
                ctime(ob->query("last_on"))
        );
        if( body = find_player(name) ) {
                if( !this_player() || this_player()->visible(body) )
                        msg += chinese_flag ?
                                ("\n" + ob->query("name") + "目前正在线上。\n"):
                                ("\n" + capitalize(name) + " is currently connected.\n");
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

//搜索犯人仅限于使用killer这种condition的人犯（主要是扬州）
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

//适合所有犯人的搜索
string get_killer_ext(string cond)
{
        int i;
        string msg;
        object *ob = users();

        msg = "";
        for (i = 0; i < sizeof(ob); i++)
                if ((int)ob[i]->query_condition(cond))
                        msg += (ob[i]->short() + "\n");
        if (msg == "")
                return "本城治安良好。\n";
        else
                return "现在本城正在缉拿以下人犯：\n\n" + msg;
}

string finger_ip()
{
	int ips;
	ips=query_only_ip(users());
	return "排除由同一IP连线，实际登陆有 "+ips+" 人。\n";
}

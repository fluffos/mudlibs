// ban.c
// Created by Xiang@XKX

// #include <net/telnet.h>

#define BANNED_SITES "/adm/etc/banned_sites"
#define BANNED_USERS "/adm/etc/banned_users"

void load_sites();
void load_users();
void add(string pattern);
void add_user(string pattern);
void remove(string pattern);
int  is_banned(string site);
string user_is_banned(string id);
void print();

string *Sites;
string *Users;

mapping banuser_dict = ([]);

void create()
{
        seteuid(getuid());
        load_sites();
        load_users();
}

int check_ml(object ob)
{
        object *usr;
        string* proxy_ip;
        object player;
        string myip,ip,proxy_ip_file;
        int i,j,number,limit_num,isproxy;

        number = 0;
        isproxy = 0;
        usr = users();
        proxy_ip_file = read_file("/adm/etc/PROXY_IP");
    if (wiz_level(ob->query("id"))) { return 0;}
        if (!proxy_ip_file)
                proxy_ip = ({ });
        else proxy_ip = explode(proxy_ip_file,"\n");
         if ( sizeof(usr)>50 )
        {
                i = sizeof(usr);
                myip = query_ip_number(ob);
                while (i--)
                {
// 断线，非正常玩家除外
                        if( environment(usr[i]) && ( usr[i]->query_temp("netdead")==0 ) )
                        {
                                if ( query_ip_number(usr[i]) == myip )
                                {
                                        number++;
                                        if ( sizeof(usr) > 50 )
                                        {
                                                for (j = 0; j < sizeof(proxy_ip); j++)
                                                {
                                                        sscanf(proxy_ip[j],"%s %d",ip,limit_num);
                                                        if (ip == myip) //是用proxy的玩家
                                                        {
                                                                isproxy = 1;
                                                                if (number >= limit_num)
                                                                        return 1;
                                                        }
                                                }
                                         }
//是自己(reconnect).
                         if (usr[i]->query("id") == ob->query("id"))
                             {}
//不是用proxy的玩家
                          else if (!isproxy)
                                        {
                                                if (sizeof(usr) > 50)
                                                        return 1;
                                                 else if ( (sizeof(usr) > 20) && (number > 1) ) 

                                                                return 1;
                                         }
                                               
                                }
                        }
                }
        }

        return 0;
}

int add_proxy_ip(string arg)
{
        write_file("/adm/etc/PROXY_IP",arg + "\n");
        return 1;
}

void load_sites()
{
        string *tmp, file;
        int loop;

        Sites = ({});
        
        // reads in the list of the banned sites

        file = read_file(BANNED_SITES);
        if (!file) return;
         return; 
        tmp = explode(file, "\n");
        for(loop=0; loop<sizeof(tmp); loop++)
                if(tmp[loop] == "" || tmp[loop][0] == '#' || tmp[loop][0] == '\n' )
                        continue;
                else Sites += ({ tmp[loop] });
}

void load_users()
{
        string *tmp, file;
        int loop;

        Users = ({});
        
        // reads in the list of the banned users

        file = read_file(BANNED_USERS);
        if (!file) return;
        
        tmp = explode(file, "\n");
        for(loop=0; loop<sizeof(tmp); loop++)
                if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
                        continue;
                else Users += ({ tmp[loop] });
}

int is_banned(string site)
{
        string *line;
        int i;

        line = ({});
        line += ({site});

        for (i = 0; i < sizeof(Sites); i++)
                if (sizeof(regexp(line, Sites[i])) == 1)
                        return 1;
        return 0;
}       

string user_is_banned(string id)
{
	int i,ban_time,j;
	string reason,days_left,strbanned_users;
	
	for (i = 0; i < sizeof(Users); i++)
		if (explode(Users[i]," ")[0] == id)
		{
			reason = explode(Users[i]," ")[2];
			sscanf(explode(Users[i]," ")[1],"%d",ban_time);
			if (time() > ban_time)
			{
				//过期，重写banned_user，去掉当前user
				strbanned_users = "";
				for (j = 0; j < sizeof(Users); j++)
				{
					if (i != j)
						strbanned_users += Users[j] + "\n";
					write_file(BANNED_USERS,strbanned_users,1);
				}
				return "";
			}
			days_left = CHINESE_D->chinese_number( (ban_time - time())/(3600*24) + 1);
			return days_left + "天 " + reason;
		}
	return "";
}

void print()
{
        int i;
        for (i = 0; i < sizeof(Sites); i++)
                write(Sites[i] + "\n");
}

void add(string site)
{
        int i;
        
        Sites += ({site});
        write_file(BANNED_SITES, Sites[sizeof(Sites)-1] + "\n", 0);
}

void add_user(string pattern)
{
        Users += ({pattern});
        write_file(BANNED_USERS, Users[sizeof(Users)-1] + "\n", 0);	
}

void remove(string site)
{
        write("请修改 " + BANNED_SITES + " 解禁。\n");
}


int vote_banuser_dict(string id)
{
    if(undefinedp(banuser_dict[id]))
    {
        banuser_dict[id] = 1;
    }
    else
    {
        banuser_dict[id] = banuser_dict[id] + 1;
    }
    return banuser_dict[id];
}

void clear_banuser_dict(string id)
{
    map_delete(banuser_dict,id);
}

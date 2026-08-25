// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
// Rust 2-6-94
#include <mudlib.h>
#include <daemons.h>
#include <playerflags.h>
#include <ansi.h>

inherit CMD;

#define DIVIDER     "%^H_CYAN%^─────────────────────────────────────%^RESET%^"
#define USER_DESC   "%%^H_WHITE%%^─＝%%^H_YELLOW%%^玩家列表%%^H_WHITE%%^＝─%%^RESET%%^  "
#define WHO_FORMAT  "%%^H_MAGENTA%%^※ %%^H_GREEN%%^%s%%^H_MAGENTA%%^ ※%%^RESET%%^  %%^H_WHITE%%^（当地时间：%s）\n%s%%^H_WHITE%%^目前总人数：%d人%%^RESET%%^\n%s\n"

string get_who_string(string arg)
{
    object* 	u;
    int		bits, i;
    string 	name, extra, retval, *ids, site;
    mixed  	info;

    if ( !arg||arg==""||!stringp(arg) ) arg = "-i";
    extra = retval = "\n";
    u     = filter_array( users(), (: $1->query_body() :));
    sscanf( arg, "%s @%s", arg, site);

    if ( arg[0]=='@' ) {
	site = arg[1..];
	arg = "-i";	//原来这个双引号中是-i
    }
    if ( stringp(site)&&site!=mud_name() ) {
	if( member_array(site, IMUD_D->query_up_muds()) == -1 )
	    return "与“"+site+"”连接失败！\n";
        else 
	    IMUD_D->do_who(site, arg);
        return "向“"+site+"”发送讯息，请稍候。";
    }

    switch ( arg ) {
	    case "-i":
            	extra = "%^H_WHITE%^─＝%^H_YELLOW%^ID列表%^H_WHITE%^＝─%^RESET%^  ";
            	retval += sprintf(WHO_FORMAT, mud_name(),CHINESE_D->chinese_time(time()), extra, sizeof(users()),DIVIDER);
            	return retval+ sprintf("%-#79s\n", implode(users()->query_body()->query_who_name()-({0}), "\n"));
            case "-p":
		extra = USER_DESC + "\n";
                u = filter_array(users(), (: !wizardp($1) :));
		break;
            case "-w":
		extra = "巫师列表";
                u = filter_array(users(), (: wizardp :));
		break;
            case "-a":
		extra = "所有在线人物";
                if ( wizardp(this_user()) ) u = users();
                break;
            case "-m":
		extra = "发呆者列表";
		u = filter_array(u, (: query_idle($1)>60 :) );
                break;
            case "-n": 
                ids = u->query_body()->query_primary_id();
                ids = sort_array(ids, (: (( CHAR_D->get_char($1,"nation")+"0" > 
                      CHAR_D->get_char($2,"nation")+"0" ) ? 1 : -1) :));
                u=({});
		extra = "按国家排序";
                foreach(string id in ids) {
                    u+=({find_user(id)});
                }
                break;
            case "-ip": 
		extra = "按IP地址排序";
                ids = u->query_body()->query_primary_id();
		ids-= ({0});
                ids = sort_array(ids, (:  query_ip_name(find_user($1)) > 
                    query_ip_name(find_user($2))  ? 1 : -1 :));
                u=({});
                foreach(string id in ids) {
                          u+=({find_user(id)});
                }
                break;
            case "-r": 
		extra = "按声望排序";
                ids= u->query_body()->query_primary_id();
                ids= sort_array(ids, (: (( CHAR_D->get_char($1,"reputation") > 
                     CHAR_D->get_char($2,"reputation") ) ? 1 : -1):));
                u=({});
                foreach(string id in ids) {
                    u+=({find_user(id)});
                }
		break;
            case "-l": 
		extra = "按官职排序";
                ids = u->query_body()->query_primary_id();
                ids = sort_array(ids, (: (( CHAR_D->get_char($1,"level") > 
                CHAR_D->get_char($2,"level") ) ? 1 : -1) :));
                u=({});
                foreach(string id in ids) {
                    u+=({find_user(id)});
                }
		break;
            default :
                arg = replace_string(arg[1..], "_", " ");
                if( member_array(arg,COUNTRY_D->list_countries() )==-1 )
		    return "用法错误，用 help who 查看帮助。\n";
		else {
		    extra = COUNTRY_D->get_country(arg, "name")+"列表";
                    ids = u->query_body()->query_primary_id();
                    ids = filter_array(ids, (: CHAR_D->get_char($1, "nation")==$(arg) :));
                    u=({});
                    foreach(string id in ids) {
                            u+=({find_user(id)});
                    }
                }
    }

    retval += sprintf(WHO_FORMAT, mud_name(), CHINESE_D->chinese_time(time()), "%^H_WHITE%^─＝%^H_YELLOW%^"+extra+"%^H_WHITE%^＝─%^RESET%^", sizeof(u), DIVIDER);
    i = sizeof(u);
    if ( !i ) retval += sprintf("%|70s\n","对不起，没有名单。");

    while ( i-- ) {
        if ( !objectp(u[i]) ) continue;
        if ( !u[i]->query_body() ) continue;
        name = u[i]->query_body()->in_room_desc();
        //bits = u[i]->query_body()->get_flags(PLAYER_FLAGS);
        if(!name) name = u[i]->query_userid();
        if( !(u[i]->query_body()->is_visible()) ) name = "("+name+")";
        if( u[i]->query_body()->test_flag(F_IN_EDIT) ) name += HIM + " -编辑中-" + NOR;
        if( u[i]->query_body()->test_flag(F_INACTIVE) ) name += HIM + " -离线中-" + NOR;
        retval += sprintf("%s%s\n", CHENGHU_D->query_char_jun_who(u[i]->query_body()->query_primary_id()) ,name);
    }

    return retval + DIVIDER;
}
private void main(string arg)
{
    if( arg == "" )
        arg = 0;
    out(get_who_string(arg));
}
void player_menu_entry()
{
    bare_init();
    main(0);
    done_outputing();
}

mixed* get_who_list()
{
	object* alluser;
	string name;
	int num;
	mixed* out = ({});
	mixed * one = allocate(3);
	
	alluser = users();
	num = sizeof(alluser);
	//tell_user("huaer",sprintf("num = %d\n",num));
	out = allocate(num);
	
	for(int i=0; i<num; i++)
	{
		//tell_user("huaer",sprintf("objectp = %d\n",objectp(alluser[i])));
        if ( !objectp(alluser[i]) ) {
			//tell_user("huaer","objectp这里返回\n");
			continue;
		}
		//tell_user("huaer",sprintf("alluser = %O\n",alluser[i]));
		//tell_user("huaer",sprintf("query_body = %O\n",alluser[i]->query_body()));
        if ( !alluser[i]->query_body() ) {
			//tell_user("huaer","query_body这里返回\n");
			out[i] = ({"登录中",0,""});
			continue;
		}
        name = alluser[i]->query_body()->in_room_desc();
		//tell_user("huaer",sprintf("name = %O\n",name));
        if(!name) name = alluser[i]->query_userid();
 		//tell_user("huaer",sprintf("name = %O\n",name));
		if(!(alluser[i]->query_body()->is_visible())) name = "("+name+")";
		//tell_user("huaer",sprintf("name = %O\n",name));
		one[0] = sprintf("%s%s\n", CHENGHU_D->query_char_jun_who(alluser[i]->query_body()->query_primary_id()) ,name);
		one[1] = 0;
		one[2] = "hello";
		//tell_user("huaer",sprintf("i=%O, one = %O\n",i,one));
		out[i] = one;
		//tell_user("huaer",sprintf("out = %O\n",out));
		one = allocate(3);
	}
	
	//tell_user("huaer",sprintf("最终的out = %O\n",out));
	return out;
}
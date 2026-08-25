// updated by tset on 12 Jan, 2000
#include <mudlib.h>
#include <daemons.h>
#include <log.h>
#define DO_CHAT(x) 	tell(users(),"%^H_WHITE%^【投票】"+x+"%^RESET%^\n")
#define MAX_CHAN_NUM 	4
inherit CMD;
private mapping votes;
void show_help();
void do_check(string str);
void do_close(string str);
void do_open(string str);
void do_time();
void create()
{
	::create();
    	no_redirection();
	set_privilege(1);
	votes = (["close":([ ]), "open":([ ]), ]);
	call_out("do_time", 20);
	return;
}
void main(string str)
{
	string id, what, who;
	id = this_body()->query_primary_id();
	if( !str||!stringp(str)||str=="" ){
		show_help();
		return;
	}
	if (str=="board")
	{
 new("/sgdomain/menu/votetool")->begin_reading();
	 return;
	}
	sscanf(str, "%s %s", what,who);
	if( !mapp(votes) ) votes = (["close":([ ]), "open":([ ]), ]);
	if (!what||!stringp(what)||what==""||what=="help") show_help();
	else if( !CHAR_D->char_exist(id) && !wizardp(id) )
		write("只有游戏角色才有权投票！\n");
	else if( what=="check" ) do_check(who);
	else if( what=="close" ) do_close(who);
	else if( what=="open"  ) do_open(who);
	else 
		write("不合理的选择！\n");
	return;
}
void do_check(string str)
{
	mapping tmp;
	object ob;
	string tt, ss;
	if( str=="open"){
		tmp = votes["open"];
		ss = "正在举行对以下玩家开启交谈频道的表决：\n";
	} else if( str=="close" ){ 
		tmp = votes["close"];
		ss = "正在举行对以下玩家关闭交谈频道的表决：\n";
	} else {
		write("不合理的选择！\n");
		return;
	}
	foreach(string s in keys(tmp)){
		ob = find_body(s);
		if( !objectp(ob) ) tt = "某某("+s+")";
		else tt = ob->query_name()+"("+s+")";
		ss+=sprintf("%-20s：由%s提议，%s人支持，还差%s票通过！\n",
			tt, tmp[s]["player"], chinese_number(sizeof(tmp[s]["who"])),
			chinese_number(tmp[s]["no"]+1-sizeof(tmp[s]["who"])),
			);
	}
	write(ss+"\n");
}
void do_time()
{
	mapping tmp, tmp1;
	remove_call_out("do_time");
	call_out("do_time", 20);
	if( !sizeof(votes) )return;
	tmp = votes["close"];
	if( sizeof(tmp) ){
		foreach(string ss in keys(tmp) ){
			tmp1 = tmp[ss];
			if( !mapp(tmp1)||tmp1["time"]+600<time() ){
				map_delete(tmp, ss);
				DO_CHAT("由于太久不能达成统一的意见，对"+(objectp(find_body(ss))?find_body(ss)->query_name():ss)+"("+ss+")投票取消了！");
			}
		}
		votes["close"] = tmp;
	}
	tmp = votes["open"];
        if( sizeof(tmp) ){
                foreach(string ss in keys(tmp) ){
                        tmp1 = tmp[ss];
                        if( !mapp(tmp1)||tmp1["time"]+600<time() ){
                                map_delete(tmp, ss);
                                DO_CHAT("由于太久不能达成统一的意见，对"+(objectp(find_body(ss))?find_body(ss)->query_name():ss)+"("+ss+")投票取消了！");
                        }
                }
                votes["open"] = tmp;
        }
}
void do_close(string str)
{
	object ob;
	mapping tmp;
	string *ids;
	if( !objectp(ob=find_body(str)) )
		write("没有\""+str+"\"这个玩家！\n");
	else if( ob->chan_disabled() )
		write("他的交谈频道已经被关闭了！\n");
	else if (wizardp(str))
		write("无法关闭巫师的交谈频道。\n");
	else {
		tmp = votes["close"];
		tmp = tmp[str];
		ids = users()->query_body()->query_primary_id();
                ids = filter_array(ids, (: CHAR_D->char_exist($1) :));
		if( !tmp||!mapp(tmp) ){
			if( sizeof(votes["close"])>MAX_CHAN_NUM ){
				write("已经有太多的投票正在进行，请稍等！\n");
				return;
			}
			tmp = (["time":time(), "who":({ }),"whoip":({ }), "no": sizeof(ids)/2,"player":this_body()->query_primary_id() ]);
			tmp["who"]-=({ this_body()->query_primary_id() });
                        tmp["who"]+=({ this_body()->query_primary_id() });
                        tmp["whoip"]-=({ query_ip_number(this_user()) });
                        tmp["whoip"]+=({ query_ip_number(this_user()) });
			votes["close"][str] = tmp;
			DO_CHAT(this_body()->query_name()+"提议关闭"+ob->query_name()+"的交谈频道！\n");
			LOG_D->log(LOG_VOTE, 
				sprintf("%s attemp to close %s's channel at %s\n",
				this_body()->query_primary_id(), str, ctime(time())));
		} else if(( member_array(this_body()->query_primary_id(), tmp["who"])!=-1 )||
		         ( member_array(query_ip_number(this_user()), tmp["whoip"]) !=-1 )) {
			write("你已经投过一票了！\n");
		} else {
			tmp["who"]-=({ this_body()->query_primary_id() });
			tmp["who"]+=({ this_body()->query_primary_id() });
			tmp["whoip"]-=({ query_ip_number(this_user()) });
                        tmp["whoip"]+=({ query_ip_number(this_user()) });
			votes["close"][str] = tmp;
			if( sizeof(tmp["who"])>tmp["no"] ){
				DO_CHAT(this_body()->query_name()+"投票支持关闭"+ob->query_name()+"的交谈频道，决议通过了！");
				ob->disable_chan();
				tmp = votes["close"];
				map_delete(tmp, str);
				votes["close"] = tmp;
			} else {
				DO_CHAT(this_body()->query_name()+"投票支持关闭"+ob->query_name()+"的交谈频道，还差"+chinese_number(tmp["no"]+1-sizeof(tmp["who"]))+"票通过！");
			}
		}
	}
}
void do_open(string str)
{
	object ob;
        mapping tmp;
        string *ids;
        if( !objectp(ob=find_body(str)) )
                write("没有\""+str+"\"这个玩家！\n");
        else if( !ob->chan_disabled() )
                write("他的交谈频道并没有被关闭！\n");
        else {
                tmp = votes["open"];
                tmp = tmp[str];
		ids = users()->query_body()->query_primary_id();
                ids = filter_array(ids, (: CHAR_D->char_exist($1) :));
                if( !tmp||!mapp(tmp) ){
			if( sizeof(votes["open"])>MAX_CHAN_NUM ){
                                write("已经有太多的投票正在进行，请稍等！\n");
                                return;
                        }
			tmp = (["time":time(), "who":({ }), "whoip":({ }),"no": sizeof(ids)/2,"player":this_body()->query_primary_id() ]);
                        tmp["who"]-=({ this_body()->query_primary_id() });
                        tmp["who"]+=({ this_body()->query_primary_id() });
                        tmp["whoip"]-=({ query_ip_number(this_user()) });
                        tmp["whoip"]+=({ query_ip_number(this_user()) });
                        votes["open"][str] = tmp;
                        DO_CHAT(this_body()->query_name()+"提议打开"+ob->query_name()+"的交谈频道！\n");
		} else if(( member_array(this_body()->query_primary_id(), tmp["who"])!=-1 )||
		         ( member_array(query_ip_number(this_user()), tmp["whoip"]) !=-1 )) {
			write("你已经投过一票了！\n");
		} else {
                        tmp["who"]-=({ this_body()->query_primary_id() });
                        tmp["who"]+=({ this_body()->query_primary_id() });
                        tmp["whoip"]-=({ query_ip_number(this_user()) });
                        tmp["whoip"]+=({ query_ip_number(this_user()) });
                        votes["open"][str] = tmp;
                        if( sizeof(tmp["who"])>tmp["no"] ){
                                DO_CHAT(this_body()->query_name()+"投票支持打开"+ob->query_name()+"的交谈频道，决议通过了！");
                                ob->enable_chan();
				tmp = votes["open"];
                                map_delete(tmp, str);
                                votes["open"] = tmp;
                        } else {
                                DO_CHAT(this_body()->query_name()+"投票支持打开"+ob->query_name()+"的交谈频道，还差"+chinese_number(tmp["no"]+1-sizeof(tmp["who"]))+"票通过！");
                        }
                }
        }
}
void show_help()
{
        string help = @HELP
vote close xxx          --> 投票同意关闭某个玩家的交谈频道。
vote open  xxx          --> 投票同意开启某个玩家的交谈频道。
vote check close|open   --> 查看当前开启(关闭)表决的进程。
vote board              --> 参加投票版的表决
HELP;
        write(help);
}

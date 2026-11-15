// friend.c
// by luoyun 2016.11.10
// 好友系统
#include <localtime.h>

int do_list(object me, string arg);
int do_del(object me, string arg);
int do_add(object me, string arg);
int do_sms(object me, string arg);
int do_jilu(object me, string arg);
int do_apply(object me, string arg);
int do_yesno(object me, string arg);

nosave int limit = 15;

int main(object me, string arg)
{
 string  msg, type, id;

	
	if (!wizardp(me) && me->query("id") != "luoyun") {
		tell_object(me, "此功能正在编写中，开放时间请留言新闻公告。\n");
		return 1;
	}
	
	if (!arg) {
		msg = ZJOBLONG+"请选择：\n";
		msg += ZJOBACTS2+ZJMENUF(3,3,9,30);
		msg += "申请消息:friends -apply";
		msg += ZJSEP"所有离线消息:friends -jilu -all";
		msg += ZJSEP"好友列表:friends -list";
		write(msg +"\n");
	} else {
		if ( sscanf(arg, "%s %s", type, arg) == 2);
		else { 
			type = arg; 
			arg = "";
		}
				
		switch(type) {
			case "-list_a" :
				id = arg;
				msg = ZJOBLONG+"请选择：\n";
				msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
				msg += "离线消息:friends -jilu -wd " + id;
				msg += ZJSEP"发送消息:friends -sms " + id;
				msg += ZJSEP"清空记录:friends -jilu -clear "+id;
				msg += ZJSEP"历史记录:friends -jilu " + id;
				msg += ZJSEP"删除好友:friends -del " + id;
				write(msg +"\n");
			break;
			case "-list" :
				do_list(me, arg);
			break;
			case "-del" :
				do_del(me, arg);
			break;
			case "-add" :
				do_add(me, arg);
			break;
			case "-sms" :
				do_sms(me, arg);
			break;
			case "-jilu" :
				do_jilu(me, arg);
			break;
			case "-apply" :
				do_apply(me, arg);
			break;
			case "-yesno" :
				do_yesno(me, arg);
			break;
		}
	}
	
	return 1;
}

int do_list(object me, string arg)
{
	string line="", *list, msg,str;
	mapping friends;
	int i;
	
	if (friends = me->query("friends")) {
		if (sizeof(friends) < 1) {
			tell_object(me, "你还没有好友，赶紧添加一个吧。\n");
			return 1;
		}
		list = keys(friends);
		list = sort_array(list, (: strcmp :));
		
		for(i=0;i<sizeof(list);i++) {
			if (find_player(list[i]))
				str = HIG+friends[list[i]][0]+NOR;
			else
				str = NOR+WHT+friends[list[i]][0]+NOR;
			line += sprintf("%s:%s", str, "friends -list_a "+list[i]);
			if (i < sizeof(list)-1)
				line += ZJSEP;
		}
		msg = ZJOBLONG+"好友列表：\n";
		msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += line;
		write(msg +"\n");
		return 1;
	} else tell_object(me, "你还没有好友，赶紧添加一个吧。\n");
	return 1;
}

int do_del(object me, string arg)
{
	string msg,id,type;
	
	if ( sscanf(arg, "%s %s", type, id) == 2) {
		if (type == "-yes") {
			if (me->query("friends/"+id)) {
				tell_object(me, "删除好友"+(me->query("friends/"+id)[0])+"成功。\n");
				me->delete("friends/"+id);
			} else
				tell_object(me, "对方不在你的好友列表之内。\n");
		}
	} else {
		id = arg;
		if (me->query("friends/"+id)) {
			msg = ZJOBLONG+HIR"你正在进行删除好友【"HIY+(me->query("friends/"+id)[0])+HIR"】的操作："NOR"\n";
			msg += ZJOBACTS2+ZJMENUF(3,3,9,30);
			msg += "确定删除:friends -del -yes " + id;
			msg += ZJSEP"放弃删除:friends -del -no "+ id;
			write(msg +"\n");
		} else
			tell_object(me, "对方不在你的好友列表之内。\n");
	}
	
	return 1;
}
int do_yesno(object ob, string arg)
{
	string msg;
	string name, id;
	
	if (sscanf(arg, "%s %s", name, id) == 2) {
		msg = ZJOBLONG+name+"请求将你添加为好友：\n";
		msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "同意:friends -add -yes "+ id;
		msg += ZJSEP"不同意:friends -add -no "+ id;
		msg += ZJSEP"取消:friends -add -qx "+ id;
		tell_object(ob, msg +"\n");
	}
	return 1;
}

int do_add(object me, string arg)
{
	object ob;
	string type,msg;
	string id;
	int ok;
	
	if (me && arg)
	{		
		if (sscanf(arg, "%s %s", type, id) == 2) {
			if (!ob = find_player(id)) {
				if (!ob = UPDATE_D->global_find_player(id)) {
					tell_object(me, "没有这个人。\n");
					return 1;
				}
				ok = 1;
			}
			
			if (me->query("friends/"+id) && ob->query("friends/"+me->query(id)) ) {
				me->delete("Friend/temp/"+id);
				ob->delete("Friend/temp/"+me->query("id"));
				tell_object(me, "你和"+ob->name()+"已经是好友了。\n");
				if (ok == 1)
					destruct(ob);
				return 1;
			}
			if (type == "-yes") {
				if (ob->query("friend/temp/"+me->query("id"), 1)) {
					if (sizeof(me->query("friends")) < limit)
						me->set("friends/"+id, ({ob->name(), time() }) );
					else
						tell_object(me, "你的好友已经达到上限"+limit+"个，无法添加"+ob->name()+"。\n");	
					
					if (sizeof(ob->query("friends")) < limit) 
						ob->set("friends/"+me->query("id"), ({me->name(), time()}) );
					else
						tell_object(ob, "你的好友已经达到上限"+limit+"个，无法添加"+me->name()+"。\n");	
					
					ob->delete("friend/temp/"+me->query("id"));
					ob->delete("Friend/temp/"+me->query("id"));
					me->delete("friend/temp/"+id);
					me->delete("Friend/temp/"+id);
					tell_object(me, HIG"你同意添加"+ob->name()+"为好友。"NOR"\n");
					tell_object(ob, HIG+me->name()+"已经同意添加你为好友。"NOR"\n");
					if (ok == 1) {
						ob->save();
						destruct(ob);
					}
					return 1;
				}
				
				if (!me->query("friend/temp/"+id, 1)) {
					me->set("friend/temp/"+id, ({ob->name(), time()}));
					ob->set("Friend/temp/"+me->query("id"), ({me->name(), time()}));
					tell_object(me, "你向"+ob->name()+"发出了添加好友的请求，请等待回应。\n");
					ob->force_me("friends -yesno "+me->query("name")+" "+ me->query("id"));
				} else
					tell_object(me, "你已经向"+ob->name()+"发出了添加好友的请求，请耐心等待。\n");
				return 1;
			} else if (type == "-no") {
				ob->delete("friend/temp/"+me->query("id"));
				ob->delete("Friend/temp/"+me->query("id"));
				me->delete("friend/temp/"+id);
				me->delete("Friend/temp/"+id);
				tell_object(ob, me->name()+"拒绝了你添加好友的申请。\n");
				tell_object(me, "你拒绝了"+ob->name()+"添加好友的申请。\n");
				if (ok == 1) {
					ob->save();
					destruct(ob);
				}
			}
		}
		else
		if (sscanf(arg, "%s", id) == 1) {
			if (ob = find_player(id)) {
				if (!userp(ob)) return 1;
				if (!me->query("friends") || (me->query("friends") && !me->query("friends")[ob->query("id")])) {
					msg = ZJOBLONG+"请确定是否添加"+ob->name()+"为好友：\n";
					msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
					msg += "确定:friends -add -yes "+ id;
					msg += ZJSEP"取消:friends -add -qx "+ id;
					write(msg +"\n");
				}
			} else
				tell_object(me, "你想加谁为好友？\n");
		}
	}
	
	return 1;
}

int do_delmsg(object me, string id)
{
	string *line;
	mapping list;
	int i,k;
	
	if (me)
	{
		if (list = me->query("sms/"+id))
		{
			line = keys(list);
			line = sort_array(line, (: strcmp :));
			if (sizeof(line) > 50)
				k = sizeof(line) - 49;
			else
				k = 1;

			for(i=0;i<k;i++) {
				me->delete("sms/"+id + "/" + line[i]);	
			}				
		}
	}
	return 1;
}

int do_sms(object me, string arg)
{
	string msg, id, str;
	object ob;
	int ok=2;
			
	if (sscanf(arg, "%s %s", id, msg) == 2) {
		if (sizeof(msg) > 60 || sizeof(msg) < 1) {
			write(INPUTTXT("请重新输入对"+(me->query("friends/"+id)[0])+"的信息(1-30个汉字)：", "friends -sms "+id+" $txt#")+"\n");
			return 1;
		}
		if (!ob = find_player(id)) {
			if (!ob = UPDATE_D->global_find_player(id)) {
				tell_object(me, "没有这个人。\n");
				return 1;
			}
			ok = 1;
		}
		if (!ob->query("friends/"+me->query("id"))) {
			tell_object(me, "你不是对方的好友，无法发送消息。\n");
			return 1;
		}
		
		if (sizeof(me->query("sms/"+id)) >= 50)
			do_delmsg(me, id);
		if (sizeof(ob->query("sms/"+me->query("id"))) >= 50)
			do_delmsg(ob, me->query("id"));
		
		str = HIG+msg+NOR;
		
		me->set("sms/"+id+"/"+time(), ({HIW"你对"+HIY+ob->name()+HIW+"说道："NOR+str, 2}));
		ob->set("sms/"+me->query("id")+"/"+time(), ({HIY+me->name()+NOR"对你说道："+str, ok}));
		tell_object(me, HIW"你对"NOR+HIY+ob->name()+NOR+(ok==1?HIR"(离线)"NOR:"")+HIW+"说道："NOR
											+str+" "+ZJURL("cmds:friends -sms "+id)+HIC+ZJSIZE(22)+"继续"NOR"\n");
		log_file("friend", sprintf("%s  %s\n", filter_color(me->query("name") +"("+ me->query("id")+")对"+ob->query("name")+"("+id+")说:"+str), ctime(time())));
		if (ok != 1) {
			tell_object(ob, HIG+me->name()+HIW"对你说道："+str +" "+ZJURL("cmds:friends -sms "+me->query("id"))+HIC+ZJSIZE(22)+"回复"NOR"\n");
		} else {
			ob->save();
			destruct(ob);
		}
	} else {
		id = arg;
			
		write(INPUTTXT("请输入你想对"+HIG+(me->query("friends/"+id)[0])+NOR+"发送的消息：", "friends -sms "+id+" $txt#")+"\n");
	}
	return 1;
}

int do_jilu(object me, string arg)
{
	string str="",msg,id;
	mapping list;
	string *line;
	int i;
	int GMT;
	mixed *times, time;
 string type;
	int j;
	mapping list_a;
	string *linea;

	if (sscanf(arg, "%s %s", type, id) == 2) {
		if (sizeof(me->query("sms/"+id)) < 1) {
			tell_object(me, "没有聊天记录。\n");
			return 1;
		}
		if (type == "-wd") {
			if (list = me->query("sms/"+id)) {
				if (sizeof(list) > 0) {
					line = keys(list);
					line = sort_array(line, (: strcmp :));
					
					for(i=0;i<sizeof(line);i++) {
						if (list[line[i]][1] == 1) {
							GMT = to_int(line[i]);
							times = localtime(GMT);
							time = sprintf("%s-%s %s:%s:%s", (times[LT_MON] + 1)+"", times[LT_MDAY]+"", 
													times[LT_HOUR]+"", times[LT_MIN]+"", times[LT_SEC]+"");
						
							str += sprintf("%s(%s)"ZJBR, list[line[i]][0], time);
							me->set("sms/"+id+"/"+line[i], ({list[line[i]][0], 2}));
						}
					}	
					if (str !="") {
						msg = ZJOBLONG+(me->query("friends/"+id)[0])+"的离线消息列表("+(sizeof(line))+"条)："+ZJBR;
						msg += str;
					} else
						msg = "没有任何离线消息。";
					
					tell_object(me, msg +"\n");
				} else
					tell_object(me, "没有任何消息。\n");
			} else
					tell_object(me, "没有任何消息。\n");
		} else
		if (type == "-yes") {
			me->delete("sms/"+id);
			tell_object(me, "聊天记录删除完毕。\n");
		}
		else if (type == "-clear") {
			msg = ZJOBLONG+"你真的要删除和"+me->query("friends/"+id)[0]+"的聊天记录吗？\n";
			msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
			msg += "确定删除:friends -jilu -yes "+ id;
			msg += ZJSEP"取消:friends -jilu -qx "+ id;
			tell_object(me, msg +"\n");
			return 1;		
		}
	} else {
		if (arg == "-all") {
			if (list = me->query("sms")) 
			{
				if (sizeof(list) > 0)				
				{
					line = keys(list);
					for(i=0;i<sizeof(line);i++) 
					{
						list_a = list[line[i]];
						if (sizeof(list_a) > 0) 
						{
							linea = keys(list_a);
							for(j=0;j<sizeof(linea);j++) {
								if (list_a[linea[j]][1] == 1) {									
									str += sprintf("%s(未读):%s", 
										HIG+(me->query("friends/"+line[i])[0])+NOR, "friends -jilu -wd " + line[i]);
									break;
								}
							}
						}
						
						if (str != "") {
							if (i<sizeof(line)-1)
								str += ZJSEP;
						}
					}	
					if (str !="") {
						msg = ZJOBLONG+"离线消息列表：\n";
						msg += ZJOBACTS2+ZJMENUF(3, 3, 9, 30);
						msg += str;
					} else
						msg = "没有任何离线消息。";
					
					tell_object(me, msg +"\n");
				} else
					tell_object(me, "没有任何消息。\n");
			} else
					tell_object(me, "没有任何消息。\n");
				
			return 1;
		}
		id = arg;
		if (list = me->query("sms/"+id))
		{
			if (sizeof(list) > 0) {
				line = keys(list);
				line = sort_array(line, (: strcmp :));
				
				for(i=0;i<sizeof(line);i++) {
					GMT = to_int(line[i]);
					times = localtime(GMT);
					time = sprintf("%s-%s %s:%s:%s", (times[LT_MON] + 1)+"", times[LT_MDAY]+"", 
												times[LT_HOUR]+"", times[LT_MIN]+"", times[LT_SEC]+"");
					str += sprintf("%s(%s)"ZJBR, list[line[i]][0], time);
				}	
				msg = ZJOBLONG+("与"+me->query("friends/"+id)[0])+"对话的消息列表("+sizeof(line)+"条)："+ZJBR;
				msg += str+"\n";
				tell_object(me, msg +"\n");
			} else
				tell_object(me, "没有任何历史消息。\n");
		} else
			tell_object(me, "没有任何历史消息。\n");
	}
	
	return 1;
}

int do_apply(object me, string arg)
{
	mapping temp;
	string msg, str="";
	string *list;
	int i;
	
	if (temp = me->query("Friend/temp")) {
		if (sizeof(temp) < 1) {
			tell_object(me, "你没有收到任何申请信息。\n");
			return 1;
		}
		list = keys(temp);
		for(i=0;i<sizeof(list);i++) {
			str += sprintf("%s:%s", temp[list[i]][0], "friends -yesno "+ temp[list[i]][0] + " " + list[i]);
			if (i<sizeof(list)-1)
				str += ZJSEP;
		}
		
		msg = ZJOBLONG+"好友申请列表：\n";
		msg += ZJOBACTS2+ZJMENUF(2, 2, 9, 30);
		msg += str;
		
		tell_object(me, msg +"\n");
	} else
		tell_object(me, "你没有收到任何申请信息。\n");
	return 1;
}
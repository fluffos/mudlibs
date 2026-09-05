// mailbox.c
// 01/04/04 modify by chui 增加巫师隐身不被发现的限制

inherit ITEM;
inherit F_SAVE;
#include <ansi.h>

mapping *mails;

void get_mail_text(mapping mail, string str);

void create()
{
	set_name("信箱", ({ "mailbox", "box" }) );
	set("long",
		"这是一个用来寄信、收信的信箱，你可以用以下指令来处理你的邮件：\n\n"
		"mail <某人>                寄信给别人。\n"
		"forward <信件编号> <某人>   将某封信转寄给别人。\n"
		"from                      查看信箱中的信件。\n"
        "read <信件编号>            阅读一封信件。\n"
		"discard <信件编号>         丢弃一封信件。\n"
	);
	set("unit", "个");
	set("no_insert", 1);

	seteuid(getuid());
}

int set_owner(string id)
{
	set("owner_id", id);
	return restore();
}

void init()
{
	object ob;

	if ((query("owner_id")!=0) && (query("owner_id") != this_player()->query("id")))
	{
		message_vision(query("owner_id")+"的邮箱不见了。\n",this_player());
		call_out("owner_is_killed",0);
		return;
	}

	if( this_player() && environment()==this_player() ) {
		set_owner( (string)this_player()->query("id") );
		this_player()->set_temp("mbox_ob", this_object());
		set_name( this_player()->name(1) + "的信箱", ({ "mailbox", "box" }) );
		add_action("do_mail", "mail");
		add_action("do_forward", "forward");
		add_action("do_from", "from");
		add_action("do_read", "read");
		add_action("do_discard", "discard");
	}
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("owner_id")) ) return 0;

	return DATA_DIR + "mail/" + id[0..0] + "/" + id;
}

void receive_mail(mapping mail)
{
	if( !pointerp(mails) ) mails = ({ mail });
	else mails += ({ mail });
	save();
}

void send_mail(string rcvr, mapping mail)
{
	object ob, mbx,body;

	if (this_player()->query("age") == 14)
	{
		write("你才十四岁就要写信吗？还是抓紧时间学习读书写字吧！\n");
		return;
	}
	// Acquire the login object of receiver and mark the arrival of newmail.
	if (objectp(ob = find_player(rcvr)))
	{
			mbx = ob->query_temp("mbox_ob");
			if( !mbx ) {
				mbx = new(MAILBOX_OB);
				mbx->set_owner(rcvr);
                mbx->move(ob);
			}
			mbx->receive_mail(mail);
			ob->save();
			if (!ob->query("env/invisibility")||(int)ob->query("env/invisibility")==0)
			{
				message_vision("忽然一个驿站伙计急匆匆地走过来，交给$N一个邮箱，说道：您的信！然后头也不回的走掉了。\n",ob);
			}
			else
			{
				tell_object(ob,HIY"忽然一个驿站伙计急匆匆地走过来，交给$N一个邮箱，说道：您的信！然后头也不回的走掉了。\n"NOR);    
				}
		return;
	}

	ob = new(LOGIN_OB);
	ob = FINGER_D->acquire_login_ob(rcvr);
	if( !ob ) {
		write("没有这个人存在。\n");
		return;
	}
	if (objectp(body = LOGIN_D->make_body(ob)))
	if ( body->restore())
	{
                if (body->query("new_mail")>5)
                {
                    tell_object(ob,"遗憾!!太多的信件把你的新来信挤掉了.\n");
                    return;
                }
		body->add("new_mail",1);
		mbx = new(MAILBOX_OB);
		mbx->set_owner(rcvr);
		mbx->receive_mail(mail);
		body->save();
		destruct(body);
		destruct(ob);
		destruct(mbx);
	}
		

}

int do_mail(string arg)
{
	mapping mail;

	if( this_player()!=environment() ) return 0;

	if( !arg || arg=="" )
		return notify_fail("你要寄信给谁？\n");

	mail = ([
		"from":	this_player()->name(1) + "(" + this_player()->query("id") + ")",
		"title": "无题",
		"to": arg,
		"time": time(),
		"text": ""
	]);
	write("信件标题：");
	input_to("get_mail_title", mail);
	return 1;
}

void get_mail_title(string str, mapping mail)
{
	if( str!="" ) mail["title"] = str;
	write("信件内容：\n");
	this_player()->edit( (: get_mail_text, mail :) );
}

void get_mail_text(mapping mail, string str)
{
	mail["text"] = str;
	write("您自己要留一份备份吗(y/n)？[n]");
	input_to("confirm_copy", mail);
}

void confirm_copy(string yn, mapping mail)
{
	if( yn[0]=='y' || yn[0]=='Y' ) receive_mail(mail);
	send_mail(mail["to"], mail);
	write("Ok.\n");
}

int do_from()
{
	int i;

	if( !pointerp(mails) || !sizeof(mails) ) {
		write("你的信箱中目前没有任何信件。\n");
		return 1;
	}
	write("你的信箱中现在共有 " + sizeof(mails) + " 封信件：\n\n");
	for(i=0; i<sizeof(mails); i++)
		printf("%2d %-50s 寄信人：%-20s\n",
			i+1, mails[i]["title"], mails[i]["from"] );
	write("\n");
	return 1;
}

int do_read(string arg)
{
	int num;

	if( !arg || !sscanf(arg, "%d", num) )
		return notify_fail("你要读哪一封信？\n");

	if( !pointerp(mails) || num < 1 || num > sizeof(mails) )
		return notify_fail("没有这个编号的信件。\n");

	num --;

	this_player()->delete("new_mail");
	printf("信件标题：%s\n寄 信 人：%s\n\n%s\n",
		mails[num]["title"], mails[num]["from"], mails[num]["text"] );

	return 1;
}

int do_discard(string arg)
{
	int num;

	if( !arg || !sscanf(arg, "%d", num) )
		return notify_fail("你要丢弃哪一封信？\n");

	if( !pointerp(mails) || num > sizeof(mails) )
		return notify_fail("没有这个编号的信件。\n");
    if (num == 1)
    {
        mails = mails[1..sizeof(mails)-1];
        save();
        write("ok\n");
        return 1;
    }

	num --;

	mails = mails[0..num-1] + mails[num+1..sizeof(mails)-1];
	save();
	write("Ok.\n");

	return 1;
}

int do_forward(string arg)
{
	string dest;
	int num;
	mapping m;

	if (this_player()->query("age") == 14)
	{
		write("你才十四岁就要写信吗？还是抓紧时间学习读书写字吧！\n");
		return 1;
	}

	if( !arg || sscanf(arg, "%d %s", num, dest)!=2 )
		return notify_fail("你要将哪一封信转寄给别人？\n");

	if( !pointerp(mails) || num > sizeof(mails) )
		return notify_fail("没有这个编号的信件。\n");

	num --;

	m = ([]);
	m["title"] = mails[num]["title"];
	m["text"] = mails[num]["text"];
	m["time"] = mails[num]["time"];
	m["from"] = mails[num]["from"] + "/转寄自" + this_player()->query("name");
	m["to"] = dest;
	send_mail( dest, m );
	write("Ok.\n");

	return 1;
}

void owner_is_killed() { destruct(this_object()); }

inherit ROOM;

#include <ansi.h>
#include <net/dns.h>
#include <net/telnet.h>
#include <net/socket.h>
#include <net/socket_errors.h>
#include <socket_err.h>
#include <mudlib.h>

string smtp_ip="202.97.175.44 25";
string smtp_domain="mymud.com";
string sender_name="password";
string sender="password@mymud.com";

varargs void write_message(object, string, int);

void create()
{
	set("short", CHINESE_MUD_NAME+"玩家登记室");
	set("long", @LONG
============================================================
    这里是玩家登记的地方，玩家登记后才能正式开始游戏，详细步骤如
下：
    输入 [1;37mregister xxx@yyy.zzz[0;37;0m
    其中 xxx@yyy.zzz 是您的电子邮件地址。
    输入完毕后系统会将一封含新密码的邮件发送给您。
    关闭游戏软件的自动登录功能。
    用新密码登录即完成了登记过程。
    系统会在您成功登记之后恢复您原来的密码。
    如果超过十分钟还未收到密码信件，您也可以使用旧的密码再次回到
    这里来重新登记。
    为了更好地管理书剑，对给大家带来的不便敬请原谅。
================================================================
LONG);
	set("no_death", 1);
	set("no_summon_out", 1);
	set("no_save", 1);
	set("no_fight", 1);
	set("no_update", 1);
	set("sleep_room", 1);
	set("no_sleep_room", 1);
	set("indoors", "书剑");
	setup();
}

void init()
{
	object me = this_player();
	string id = me->query("id");

	if (id != "guest") add_action("do_register", "register");
	else
	{
		add_action("do_change", "change");
		call_out("show", 1, me);
	}
	add_action("do_nothing", ({ "drop", "exert", "get", "kill", "save", "chat", "chat*", "tell" }));
	add_action("do_quit", "quit");
}

void show(object me)
{
	if (me) tell_object(me, "你可以用 change 命令来转换 ID。\n");
}

int do_nothing()
{
	return 1;
}

int do_change(string arg)
{
	object me = this_player();
	string id, nid;

	if (me->is_busy())
	{
		write("请耐心等候。\n");
		return 1;
	}
	if (!arg)
	{
		write("格式：change ID\n");
		return 1;
	}

	if (sscanf(arg, "%s %s", id, nid) != 2) nid = id = arg;
	if (file_size("/log/data/login/"+ id[0..0] +"/"+ id + SAVE_EXTENSION) <0) {
		write(capitalize(id) +" 登录档案不存在，无法更换 ID。\n");
		return 1;
	}
	if (file_size("/log/data/user/"+ id[0..0] +"/"+ id + SAVE_EXTENSION) <0) {
		write(capitalize(id) +" 数据档案不存在，无法更换 ID。\n");
		return 1;
	}
	if (file_size("/data/login/"+ nid[0..0] +"/"+ nid + SAVE_EXTENSION) >0
	&& file_size("/data/user/"+ nid[0..0] +"/"+ nid + SAVE_EXTENSION) > 0)
	{
		write(capitalize(nid) +" 已经存在，请输入( change 旧ID 新ID )重新转换。\n");
		return 1;
	}
	me->add_busy(10);
	write("请输入该 ID 的口令：");
	input_to("get_pass", 1, id, nid);
	return 1;
}

void get_pass(string passwd, string id, string nid)
{
	write("\n");
	__DIR__"idroom"->do_change(id, nid, passwd);
}

int do_quit()
{
	object ob = this_player();
	object lb = ob->query_temp("link_ob");

	message_vision("$N离开游戏。\n", ob);
	if (lb) destruct(lb);
	destruct(ob);
	return 1;
}

void tell_me(object me, string msg)
{
	if (me) {
		if (msg[0..1] != "<<" && msg[0..1] != ">>") tell_object(me, msg);
		message("wizard:yuj", me->query("id") + " : " + HIG + msg + NOR, this_object());
	}
}

int do_telnet(object me)
{
	int err, sock;

	sock = socket_create( STREAM, "in_read_callback","in_close_callback" );
	if ( sock < 0 ) {
		tell_me(me, "创建套接字失败。\n" );
		return 0;
	}
	tell_me(me, "正在连接邮件服务器...");
	err = socket_connect( sock, smtp_ip , "read_callback","write_callback" );
	if( err==EESUCCESS ) {
		me->set_temp("mail/sock", sock);
		set(""+sock, me);
		tell_me(me, "成功\n现在发送信件...\n");
		return 1;
	}
	tell_me(me, "失败\n邮件服务器无法连接，请稍候再试。\n");
	return 0;
}

void close_socket(object me)
{
	int sock;

	if (me && sock = me->query_temp("mail/sock")) {
		socket_close(sock);
		delete(""+sock);
		delete("OK"+sock);
		me->delete("disable_type");
		me->delete_temp("mail");
	}
}

void read_callback(int fd, mixed message)
{
	object me = query(""+fd);

	if (!me) {
		delete(""+fd);
		return;
	}
	tell_me(me, ">> "+message);
	switch(me->query_temp("mail/status")) {
		case 0:
			if (sscanf(message,"220%*s")) {
				me->add_temp("mail/status", 1);
				write_message(me, "HELO " + smtp_domain);
				return;
			}
			break;
		case 1:
			if (sscanf(message,"250%*s") || sscanf(message,"503%*s")) {
				me->add_temp("mail/status", 1);
				write_message(me, "MAIL FROM: "+sender_name);
				return;
			}
			break;
		case 2:
			if (sscanf(message,"250%*s")) {
				me->add_temp("mail/status", 1);
				write_message(me, "RCPT TO: <" + me->query_temp("mail/rcpt") + "> NOTIFY=NEVER");
				return;
			}
			break;
		case 3:
			if (sscanf(message,"250%*s")) {
				me->add_temp("mail/status", 1);
				write_message(me, "DATA");
				return;
			}
			tell_me(me, "邮件地址错误，请检查！\n");
			break;
		case 4:
			if (sscanf(message,"354%*s")) {
				me->add_temp("mail/status", 1);
				write_message(me, me->query_temp("mail/msg")+"\n.");
				return;
			}
			break;
		case 5:
			if (sscanf(message,"451%*s")) tell_me(me, "发信出错！请稍候再试。\n");
			else {
				object linkob = me->query_temp("link_ob");

				tell_me(me, "注册信件已经正确发送了，请打开你的信箱查收。\nYu Jue@ShuJian\n");
				message_vision("$N急急忙忙地退出游戏收信去了。\n", me);
				if (linkob) {
					linkob->set("reg_time", time());
					linkob->save();
					destruct(linkob);
				}
				write_message(me, "QUIT");
				close_socket(me);
				destruct(me);
				return;
			}
	}
	if (me->query_temp("mail/status") != 5 || !sscanf(message,"250%*s")) tell_me(me, "发信出错！\n");
	write_message(me, "QUIT");
	close_socket(me);
}

void write_callback(int fd, mixed msg)
{
	object me = query(""+fd);

	if (!me) {
		delete(""+fd);
		return;
	}
	set("OK"+fd, 1);
}

varargs void write_message(object me, string arg, int i)
{
	int fd;

	if (!me) return;
	fd = me->query_temp("mail/sock");
	if (!query("OK"+fd) && i < 3) {
		call_out("write_message", 1, me, "HELO " + smtp_domain, i++);
		return;
	}
	if( !arg ) arg="";
	arg += "\n";
	if (me) {
		tell_me(me, "<< " + arg);
		socket_write(fd, arg);
	}
}

string seed = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

string make_password()
{
	int i = 8, j;
	string id = "";

	while (i--) {
		j = random(52);
		id += seed[j..j];
	}
	return id;
}

int do_register(string dest)
{
	object me, linkob;
	string pass;

	if (!dest || sscanf(dest, "%*s@%*s.%*s") != 3)
		return notify_fail("电子邮件地址格式错误。\n");
	me = this_player();
	linkob = me->query_temp("link_ob");
	if (!linkob) return notify_fail("你不是正常登录的人物，不能进行登记。\n");
	linkob->restore();
	if (linkob->query("registered") > 1) return notify_fail("你不是已经登记成功了么？快退出吧。\n");
	if (time() < linkob->query("reg_time") + 600) return notify_fail("请等候信件，耐心点。\n");
	me->set_temp("mail/rcpt", dest);
	pass = make_password();
	me->set_temp("mail/msg",
		"SUBJECT: "+CHINESE_MUD_NAME+"注册信件！\n"+
		"FROM: \""+"密码管理员@"+CHINESE_MUD_NAME+"\" <password@mymud.com>\n"+
		"TO: \""+me->name(1)+"\" <"+dest+">\n"+
		"MIME-Version: 1.0\n"+
		"DATE: "+ctime(time())+"\n"+
		"X-MAILER: LPC SMTP Client v1.0\n\n"+
		me->query("id") + " 您好！欢迎光临"+CHINESE_MUD_NAME+"！\n"+
		"请关闭自动登录功能，使用下面提供的密码登录。\n\n"+
		"你的注册密码是："+ pass +"\n\n"+
		"用注册密码登录成功后，系统会恢复您原来的密码。\n"+
		"遇到问题，请用原来的密码登录。\n"+
		"总站主页：http://www.mymud.com/\n"+
		ctime(time())
	);
	if (!do_telnet(me)) {
		me->delete_temp("mail");
		return 1;
	}
	message_vision("$N冲上前去开始办理登记手续。\n", me);
	//设置玩家的注册信息
	linkob->set("newpassword", crypt(pass, "SJ"));
	linkob->set("email", dest);
	linkob->save();
	me->set("disable_type", " <办理登记中>");
	return 1;
}

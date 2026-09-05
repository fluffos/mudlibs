//last modified by Doing Lu 1/23/98

//last modified by leon 11/21/1997 09:51:36
// a).增加banname中的wizname;
// b).去掉了"**名巫师在线上"这一句;

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_DBASE;

int wiz_lock_level = WIZ_LOCK_LEVEL;
string *banned_name = ({
        "你", "你", "我", "他", "她", "它", "自己", "管理",
        "萧峰", "乔峰", "慕容博", "慕容复", "王语嫣", "张无忌",
        "无名", "东方不败", "李逍遥", "丁丁","金庸","风清扬", 
        "岳不群", "宁中则", "岳灵珊", "令狐冲", "张三丰", "洪七公",
        "丁春秋", "鲁有脚", "彭有敬", "宋远桥", "俞莲舟", "张松溪",
        "欧阳锋", "欧阳克", "黄药师", "黄蓉", "郭靖", "杨过", "小龙女",
	"杨逍", "范遥", "韦一笑", "灭绝师太", "周芷若", "段智兴",
});

// 禁止的 ID
string *banned_id = ({
});
// 特许反复登录的的IP
string *special_ip = ({
	"127.0.0.1",
	"202.96.174.194",
        "202.96.191.124",
});

protected void get_id(string arg, object ob);
protected void confirm_id(string yn, object ob);
protected void get_passwd(string pass, object ob);
protected void confirm_relogin(string yn, object ob, object user);
protected void confirm_id(string yn, object ob);
protected void get_name(string arg, object ob);
protected void new_password(string pass, object ob);
protected void confirm_password(string pass, object ob);
protected void get_gift(string yn, object ob, mapping my);
protected void get_email(string email, object ob, mapping my);
protected void get_gender(string gender, object ob, object user);
object make_body(object ob);
//protected 
void init_new_player(object user);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
// void autosave(object user);

protected void random_gift(mapping my)
{
        int i;
        int tmpstr, tmpint, tmpcon, tmpdex;
        tmpstr = tmpint = tmpcon = tmpdex = 10;

        for (i = 0; i < 40; i++) {


                switch (random(4)) {
                case 0: tmpstr++; break;
                case 1: tmpint++; break;
                case 2: tmpcon++; break;
                case 3: tmpdex++; break;
                }
        }
        if (tmpstr <= 30) my["str"] = tmpstr; else my["str"] = 30;
        if (tmpint <= 30) my["int"] = tmpint; else my["int"] = 30;
        if (tmpcon <= 30) my["con"] = tmpcon; else my["con"] = 30;
        if (tmpdex <= 30) my["dex"] = tmpdex; else my["dex"] = 30;
        my["kar"] = 10 + random(21);
        my["per"] = 10 + random(21);
}

void create() 
{
        seteuid(getuid());
        set("channel_id", "连线精灵");
}

void logon(object ob)
{
        object *usr;
	string ip;
	int this_ip_count;
        int i, wiz_cnt, ppl_cnt, login_cnt;

        if (BAN_D->is_banned(ip = query_ip_name(ob)) == 1) {
                destruct(ob);
                return;
        }
        cat(WELCOME);
        UPTIME_CMD->main();

        usr = users();
        wiz_cnt = 0;
        ppl_cnt = 0;
        login_cnt = 0;
	this_ip_count = 0;
        for(i=0; i<sizeof(usr); i++) {
                if( !environment(usr[i]) ) login_cnt++;		
                else {
			if( wizardp(usr[i]) ) wiz_cnt++;
	                else ppl_cnt++;
			if ((query_ip_name(usr[i]) == ip)) this_ip_count ++;
		}
        }
        printf("目前共有 %d 位玩家在线上，以及 %d 位使用者尝试连线中。\n",
		ppl_cnt, login_cnt );

	printf("现在你正从 " HIR "%s" NOR " 处连线，", ip);
	if (this_ip_count)
		printf ("目前该处已经有 %d 位使用者使用。\n\n", this_ip_count);
	else
		printf ("目前该处还没有使用者连线。\n\n");

        if  (member_array(ip, special_ip) == -1 && this_ip_count >= 9)
	{
		printf ("由于该地址的玩家连线过多，请退出一位玩家再连线。\n");
		destruct(ob);
		return;
	}                

        write("您的英文名字：");
        input_to( (: get_id :), ob );
}

protected void get_id(string arg, object ob)
{
        object ppl;
	int last_time;

        arg = lower_case(arg);
        if( !check_legal_id(arg)) {
                write("您的英文名字：");
             input_to((:get_id:), ob);
                return;
        }

#ifdef MAX_USERS
if( (string)SECURITY_D->get_status(arg)=="(player)"
        && sizeof(users()) >= MAX_USERS ) {
                ppl = find_body(arg);
                // Only allow reconnect an interactive player when MAX_USERS exceeded.
                if( !ppl || !interactive(ppl) ) {
                        write("对不起，" + MUD_NAME + "的使用者已经太多了，请待会再来。\n");
                        destruct(ob);
                        return;
                }
        }
#endif

        if( wiz_level(arg) < wiz_lock_level ) {
                write("对不起，" + MUD_NAME + "目前限制巫师等级 " + WIZ_LOCK_LEVEL
                        + " 以上的人才能连线。\n");
                destruct(ob);
                return;
        }

        if( (string)ob->set("id", arg) != arg ) {
                write("Failed setting user name.\n");
                destruct(ob);
                return;
	}

         if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) {
                if( ob->restore() ) {
			if (! (last_time = ob->query("last_on")))
				last_time = 0;
			
			if (wizhood(arg) == "(player)" &&
			    time() - last_time < 10 &&
			    time() - last_time >=0 )
			{
				write("对不起，你刚刚才退出还不到十秒钟，为了减小系统负担，请稍候再登录。\n");
				destruct(ob);
				return;
			}
		
                        write("请输入密码：");
                      input_to((:get_passwd:), 1, ob);
                        return;
                }
                write("您的人物储存挡出了一些问题，请利用其他人物通知巫师处理。\n");
                destruct(ob);
                return;
        }

        write("使用 " + (string)ob->query("id") + " 这个名字将会创造一个新的人物，您确定吗(y/n)？");
      input_to((:confirm_id:), ob);
}

protected void get_passwd(string pass, object ob)
{
        string my_pass;
        object user;

        write("\n");
        my_pass = ob->query("password");
        if( crypt(pass, my_pass) != my_pass ) {
                write("密码错误！\n");
                destruct(ob);
                return;
        }

        // Check if we are already playing.
        user = find_body(ob->query("id"));
        if (user) {
                if( user->query_temp("netdead") ) {
                        reconnect(ob, user);
                        return;
                }
                write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
               input_to((:confirm_relogin:), ob, user);
                return;
	}

        if( objectp(user = make_body(ob)) ) {
                if( user->restore() ) {
                        log_file( "USAGE", sprintf("%s loggined from %s (%s)\n", user->query("name"),
                                query_ip_name(ob), ctime(time()) ) );
                        enter_world(ob, user);
                        return;
                } else {
                        destruct(user);
                }
        }
        write("请您重新创造这个人物。\n");
        confirm_id("y", ob);
}

protected void confirm_relogin(string yn, object ob, object user)
{
        object old_link;

      if (!user) {destruct(ob);return;}
        if( yn=="" ) {
                write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
              input_to((:confirm_relogin:), ob, user);
	return;
        }       

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write("好吧，欢迎下次再来。\n");
                destruct(ob);
                return;
        } else {
                tell_object(user, "有人从别处( " + query_ip_number(ob)
                        + " )连线取代你所控制的人物。\n");
                log_file( "USAGE", sprintf("%s replaced by %s (%s)\n", user->query("name"),
                        query_ip_name(ob), ctime(time()) ) );
        }

        // Kick out the old player.
        old_link = user->query_temp("link_ob");
        if( old_link ) {
                exec(old_link, user);
                destruct(old_link);
        }

        reconnect(ob, user);    
}

protected void confirm_id(string yn, object ob)
{
        if( yn=="" ) {
                write("使用这个名字将会创造一个新的人物，您确定吗(y/n)？");
               input_to((:confirm_id:), ob);
                return;
        }       

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write("好吧，那么请重新输入您的英文名字：");
              input_to((:get_id:), ob);
                return;
        }
        write( @TEXT

请输入您的高姓大名，由于这个名字代表你的人物，而且以后不能更改，
务必慎重择名（不雅观的姓名将被删除）。另：请不要选择金庸小说中
已有人物姓名。

TEXT
        );
        write("您的中文名字：");
       input_to((:get_name:), ob);
}

protected void get_name(string arg, object ob)
{
        if( !check_legal_name(arg) ) {
                write("您的中文名字：");
              input_to((:get_name:), ob);
                return;
        }
        printf("%O\n", ob);
        ob->set("name", arg);
        write("请设定您的密码：");
      input_to((:new_password:), 1, ob);
}

protected void new_password(string pass, object ob)
{
        write("\n");
        if( strwidth(pass)<5 ) {
                write("密码的长度至少要五个字元，请重设您的密码：");
             input_to((:new_password:), 1, ob);
                return;
	}
        ob->set("password", crypt(pass,0) );
        write("请再输入一次您的密码，以确认您没记错：");
       input_to((:confirm_password:), 1, ob);
}

protected void confirm_password(string pass, object ob)
{
        mapping my;
        string old_pass;
        write("\n");
        old_pass = ob->query("password");
        if( crypt(pass, old_pass)!=old_pass ) {
                write("您两次输入的密码并不一样，请重新设定一次密码：");
             input_to((:new_password:), 1, ob);
                return;
        }

        write(@TEXT

一个人物的天赋对于他或她所修习的武艺息息相关。《神行天下》中的人物
大多具有以下四项天赋：

	膂力：影响攻击能力及负荷量的大小。
        悟性：影响学习武功秘籍的速度及理解师傅的能力。
        根骨：影响体力恢复的速度及升级后所增加的体力。
        身法：影响防御及躲避的能力。

TEXT);
        my = ([]);
        random_gift(my);
        printf("\n膂力[%d]， 悟性[%d]， 根骨[%d]， 身法[%d]\n",
                my["str"], my["int"], my["con"], my["dex"]);
        write("您接受这一组天赋吗？");
       input_to((:get_gift:), ob, my);
}

protected void get_gift(string yn, object ob, mapping my)
{
        if (yn[0] != 'y' && yn[0] != 'Y') {
                random_gift(my);
                printf("\n膂力[%d]， 悟性[%d]， 根骨[%d]， 身法[%d]\n",
                      my["str"], my["int"], my["con"], my["dex"]);
                write("您同意这一组天赋吗？");
              input_to((:get_gift:), ob, my);
        }
	if (yn[0] == 'y' || yn[0] == 'Y') {
                write("\n您的电子邮件地址：");
             input_to((:get_email:), ob, my);
        }
}

protected void get_email(string email, object ob, mapping my)
{
        object user;

        write("\n");
        if (email == "" || strsrch(email, "@") == -1) {
                write("电子邮件地址需要是 id@address 的格式。\n");
                write("您的电子邮件地址：");
              input_to((:get_email:), ob, my);
                return;
        }
        ob->set("email", email);
        ob->set("registered", 1);

        // If you want do race stuff, ask player to choose one here, then you can
        // set the user's body after the question is answered. The following are
        // options for player's body, so we clone a body here.
	ob->set("body", USER_OB);
        if( !objectp(user = make_body(ob)) )
                return;
        user->set("str", my["str"]);
        user->set("dex", my["dex"]);
        user->set("con", my["con"]);
        user->set("int", my["int"]);
        ob->set("registered", 1);
        user->set("registered", 1);

        write("您要扮演男性(m)的角色或女性(f)的角色？");
      input_to((:get_gender:), ob, user);
}

protected void get_gender(string gender, object ob, object user)
{
        write("\n");
        if( gender=="" ) {
                write("您要扮演男性(m)的角色或女性(f)的角色？");
             input_to((:get_gender:), ob, user);
                return;
        }

	if( gender[0]=='m' || gender[0]=='M' )
                user->set("gender", "男性");
        else if( gender[0]=='f' || gender[0]=='F' )
                user->set("gender", "女性" );
        else {
                write("对不起，您只能选择男性(m)或女性(f)的角色：");
            input_to((:get_gender:), ob, user);
                return;
        }

        log_file( "USAGE", sprintf("%s was created from %s (%s)\n", user->query("id"),
                query_ip_name(ob), ctime(time()) ) );
        init_new_player(user);
        enter_world(ob, user);
        write("\n");
}

object make_body(object ob)
{
        string err;
        object user;
        int n;

	user = new(ob->query("body"));
        if(!user) {
                write("现在可能有人正在修改使用者物件的程式，无法进行复制。\n");
                write(err+"\n");
                return 0;
        }
        seteuid(ob->query("id"));
        export_uid(user);
        export_uid(ob);
        seteuid(getuid());
        user->set("id", ob->query("id"));
        user->set_name( ob->query("name"), ({ ob->query("id")}) );
        return user;
}

//protected 
void init_new_player(object user)
{
        user->set("title", "普通百姓");
        user->set("birthday", time() );
        user->set("potential", 99);

    user->set("channels", ({ "chat", "rumor", "tt" ,"es"}) );
}

                
varargs void enter_world(object ob, object user, int silent)
{
        object cloth, room,lover;
        string startroom,tmpstr1,tmpstr,lover_name;
        string *autoloads;
        object obj,pager;
        //
        object couple_ob;
        string couple_name; 
        int couple_flag; 
        //add by win

//      autosave ervery 10 minutes after the user entering the world
//        call_out("autosave",600,user);

        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        user->set("registered", ob->query("registered"));
        exec(user, ob);

        write("\n目前权限：" + wizhood(user) + "\n");
        user->setup();
        if (!user->query("food") && !user->query("water") && ob->query("age") == 14) {
                user->set("food", user->max_food_capacity());
	user->set("water", user->max_water_capacity());
        }

        // In case of new player, we save them here right aftre setup 
        // compeleted.
        user->save();
        ob->save();
        
        cloth = new("/clone/misc/cloth");
    if (cloth) if (cloth->move(user)) cloth->wear();

//      Give everyone a pager.  xgw 98.11
        pager= new("/clone/misc/pager");
        pager->move(user);
//add by win ，提供结婚戒指        
        if (user->query("marry/lover"))
        {
          couple_flag=1;
          if (couple_ob=find_player(user->query("marry/lover")))
             couple_flag=0;
          else
          couple_ob="/adm/daemons/fingerd"->acquire_login_ob(user->query("marry/lover"));
          if (!couple_ob) 
          {
     	     write("看来你爱人自杀了!\n"); 
     	     couple_name="";
          }
                   
          else
          {
//             if (couple_ob->query("marry/lover") != user->query("id") )
//             {
//             	write("你的爱人的爱人怎么不是你啊！\n");
//             	couple_name="";
//             }
//             else
//             {
     	        couple_name=couple_ob->query("name"); 
//     	     }
     	     if (couple_flag) destruct(couple_ob);
          }
          
          if ((!couple_name) || (couple_name == ""))
          {
             user->delete("marry");
             write("由于你的婚姻关系无法维持，删除掉你的婚姻关系。\n");
          }
          else
          {
             pager=new("/clone/misc/marry_ring");
             pager->set("long","这是一只你和你爱人"+couple_name+"的结婚戒指。\n你一看到你们的结婚戒指你不由得感觉到一阵温馨。\n" );
             pager->move(user);
          }	
        }
//add by win,提供结婚戒指        
        
        if( !silent ) {
                if (ob->query("registered") == 0) 
                        cat(UNREG_MOTD);
                else 
                        cat(MOTD);
                if( user->is_ghost() )
                        startroom = DEATH_ROOM;
                else if( !stringp(startroom = user->query("startroom")) )
                        startroom = START_ROOM;

                if( !catch(load_object(startroom)) )
                        user->move(startroom);
                else {
                        user->move(START_ROOM);
                        startroom = START_ROOM;
                        user->set("startroom", START_ROOM);
                }		
                tell_room(startroom, user->query("name") + "连线进入这个世界。\n",
                        ({user}));
        }

        if ( arrayp(autoloads = user->query("auto_load")) )
        {
                for (int i = 0; i < sizeof(autoloads); i++)
                if ( objectp(obj = new(autoloads[i])) && obj->move(user) )
                                write("\n" + obj->name() + "  loaded.\n\n");
                        else
                                write(HIY "你觉得好象失落了什么重要的东西，赶快通知巫师吧！\n\n" NOR);
        }

         if( (wizhood(user) == "(admin)") ||(wizhood(user) == "(arch)") )
                {
//                        cat(WIZ_MOTD);
                }
        if ( wiz_level(user) )
        {
                log_file("WIZ_LOGIN", ctime(time()) + "  " + user->name() + "(" + user->query("id") + ")从" + query_ip_name(user) + "连线进入。\n");
        }
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s由%s连线进入。", user->name(), query_ip_name(user)) );
        //**UPDATE_D->check_user(user);
	TOP_D->compare_status(user);

                if(!undefinedp(lover_name=user->query("marry/lover"))
                    &&(lover=find_object(lover_name)))
                  {                 
                       if ((string)lover->query("gender") != "女性") {
                           tmpstr1 = "老公"; 
                           tmpstr = "老婆";
                       }
                       else {
                           tmpstr1 = "老婆";
                           tmpstr = "老公";
                       }
                
                       write(MAG"你的"+tmpstr1+"也在这里，快去找啦...\n"NOR);
                       tell_object(lover ,
                              MAG"你的"+tmpstr+"来啦,快去接...\n"NOR);
                 }

	printf("\n你上一次连线是在 " HIB "%s" NOR " 从 " HIR "%s" NOR " 进入。\n\n", ctime(ob->query("last_on")), query_ip_name(user));
}

varargs void reconnect(object ob, object user, int silent)
{
        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        exec(user, ob);

        user->reconnect();
	if( !silent ) {
                tell_room(environment(user), user->query("name") + "重新连线回到这个世界。\n",
                ({user}));
        }
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s由%s重新连线进入。", user->query("name"), query_ip_name(user)) );
        //**UPDATE_D->check_user(user);
}

int check_legal_id(string id)
{
        int i;

        i = strwidth(id);
        
    if( member_array( id, banned_id ) != -1 )
    {
        write("这个ＩＤ会引起不必要的麻烦。\n");
        return 0;
    }

        if( (strwidth(id) < 3) || (strwidth(id) > 12 ) ) {
                write("对不起，你的英文名字必须是 3 到 12 个英文字母。\n");
	return 0;
        }
        while(i--)
                if( id[i]<'a' || id[i]>'z' ) {
                        write("对不起，你的英文名字只能用英文字母。\n");
                        return 0;
                }

        return 1;
}

int check_legal_name(string name)
{
        int i;

        i = strwidth(name);
        
        if( (strwidth(name) < 1) || (strwidth(name) > 7 ) ) {
                write("对不起，你的中文名字必须是 1 到 7 个中文字。\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
	write("对不起，你的中文名字不能用控制字元。\n");
                        return 0;
                }
                if(  !is_chinese(name[i..<0]) ) {
                        write("对不起，请您用「中文」取名字。\n");
                        return 0;
                }
        }
        if( member_array(name, banned_name)!=-1 ) {
                write("对不起，这种名字会造成其他人的困扰。\n");
                return 0;
        }

        return 1;
}

object find_body(string name)
{
        object ob, *body;

        if( objectp(ob = find_player(name)) )
                return ob;
        body = children(USER_OB);
	for(int i=0; i<sizeof(body); i++)
                if( clonep(body[i])
                &&      getuid(body[i]) == name ) return body[i];

        return 0;
}

int set_wizlock(int level)
{
        if( wiz_level(this_player(1)) <= level )
                return 0;
        if( geteuid(previous_object()) != ROOT_UID )
                return 0;
        wiz_lock_level = level;
        return 1;
}

// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

//
// written by Rust Jan 12, 1994
// Underwent a mighty transformation at the hands of Deathblade on
//  Apr 30, 1995 to move to new user/body system.
//


#include <mudlib.h>
#include <daemons.h>
#include <config.h>
#include <commands.h>
#include <security.h>

string query_userid();
void rcv_encoding(string arg);
void set_b5(int e);
void set_userid(string new_name);
void set_chinese_id(string cname);
void save_me();
void restore_me(string some_name, int preserve_vars);

void register_failure(string addr);
nosave private string tmp_id;

varargs void modal_push(function input_func,
            mixed prompt,
            int secure,
            function return_to_func
    );
varargs void modal_func(function input_func,
            mixed prompt,
            int secure
    );
void modal_pop();
void modal_recapture();

void begin_info_collection();

void existing_user_enter_game();
void existing_user_ready();

mixed unguarded(mixed priv, function fp);

/*
** The user's password (duh!)
*/
private string password;

/* forward declarations */
void rcv_userid(string arg);
void rcv_chinese_id(string arg);
void rcv_new_password(string arg);
void rcv_new_userid(string arg);
void rcv_check_new_user(string the_userid, string str);

string get_tmp_id() {
	return tmp_id;
}
private nomask void get_lost_now()
{
    destruct();
}

/*
** This is used when we want to get rid of somebody... we have to wait a
** bit for MudOS to flush the buffer before disconnecting them (desting
** this_object()).
*/
//### if MudOS waits before closing the socket, this system may be obsolete
private nomask void get_lost()
{
    remove_call_out();
    modal_func((: 1 :), "");    /* ignore all input */
    call_out((: get_lost_now :), 2);
}

/*
** Name and password processing
*/

nomask int matches_password(string str)
{
    return ( crypt(str, str) == password || oldcrypt(str, str) == password);
}

nomask void set_password(string str)
{
    if ( base_name(previous_object()) != CMD_OB_PASSWD )
    //error("illegal attempt to set a password\n");
    error("试图非法设定密码\n");
    password = oldcrypt(str, str);
    save_me();
}

private nomask void time_up()
{
    //write("\nSorry, you've taken too long.\n");
    write("\n对不起，你花在连线上的时间太长了，请下次再来。\n");
    get_lost();
}

private nomask int check_site()
{
    if ( BANISH_D->check_site() )
    {
    printf(//"Sorry, your site has been banished from " + mud_name() + ".  To ask for\n"
           //"a character, please mail %s.\n",
           "对不起，你的地址被" + mud_name() + "禁止连线，"
           "请 mail 到 %s 来申请玩家帐户。\n",
           ADMIN_EMAIL);

    get_lost();

    return 0;
    }

    return 1;
}


private nomask int valid_chinese_id(string str)
{
    int len, i;
    string *chars;    
//    str = trim_spaces(str);
    len = strlen(str);
    if ( len > 8 ) // fire change the maximum name from 11 to 8
    {
    write("对不起，这个姓名太长了，请换一个。\n");
    return 0;
    }

    if ( (len / 2) * 2 != len ) {
        write("对不起，请用中文输入姓名。\n");
        return 0;
    }
    for (i=0; i<len; i++)
        if ((i / 2) * 2 == i) {
            if (str[i] < 176 || str[i] > 247) {
                write("对不起，请用中文输入姓名。\n");
                return 0;
            }
        } else if (str[i] < 161 || str[i] > 254) {
                write("对不起，请用中文输入姓名。\n");
                return 0;
        }
    if (str == "某人" || BANISH_D->check_name(str)) {
        write("对不起，这个姓名被禁止使用，请换一个。\n");       
        return 0;                                               
    }
/*
    if (NAME_D->check_chinese_id(str)) {
        write("对不起，这个名字已经有人使用了，请换一个。\n");
        return 0;
    }
*/
    chars=CHAR_D->check_char("name", str);
    if(sizeof(chars)) {
        foreach(string c in chars) {
           if(CHAR_D->get_char(c,"type")==TYPE_NPC) {
              write("对不起，不能使用三国中的人物名。\n");
              return 0;

           }
        }   
    }
    return 1;
}
        
private nomask int valid_name(string str)
{
    int len;
    string *nousename=({"quit", "exit", "leave", "here", "me", "who", "new"});
    if(member_array(str,nousename) != -1) {
       write("对不起，这样的名字容易引起系统混乱，请换一个。\n");
       return 0;
    }
    if ( BANISH_D->check_name(str) )
    {
    //write("Sorry, that name is forbidden by the implementors.  Please choose another.\n");
        write("对不起，这个姓名被禁止使用，请换一个。\n");
        return 0;
    }

    if ( !check_site() )
    return 0;

    len = strlen(str);
    if ( len < 3 || len > 8 ) // fire change the maximum name from 11 to 8
    {
      //write("Sorry, that name's too long.  Try again.\n> ");
       write("对不起，这个姓名太长了，请换一个。\n> ");
       return 0;
    }

    /*
    ** We used to rely on the banish code to do this, but that is a
    ** Bad Thing as it is too easy to see those entries deleted.  In
    ** particular, we've been distributing the lib for a while now
    ** without a banish.o that contains this rule.  To use the banish
    ** code to implement a feature here is too convoluted and unintuitive.
    **
    ** So... we'll put a regex here to check the name.
    **
    ** Note that this regex matches the restriction imposed by the
    ** SECURE_D.  Also note the name is in lower case right now.
    */
    if ( !regexp(str, "^[a-z]+$") )
    {
    //write("Sorry, that name is forbidden by the implementors.  Please\n"
    //      "choose a name containing only letters.\n");
    write("对不起，这个姓名不准使用，请换一个只有字母的。\n");
    return 0;
    }

    return 1;
}


private nomask int check_special_commands(string arg)
{
    string * b;

    switch(arg)
    {
    	case "who":
        	b = bodies()->query_name();
		b -= ({ "某人" });
		if(!sizeof(b)) {
		        write("好象没人在线上哟。\n");
		        return 0;
		}	
		printf(//"The following people are logged on:\n%s\n",
	           "以下的人物现在正在连线中：\n%s\n",
        	   wrap(implode(b,", ")));
	        return 0;

    	case "":
    	case "quit":
    	case "exit":
    	case "leave":
    		//write("Bye.\n");
    		write("欢迎下次再来！\n");
    		get_lost();
    		return 0;
	case "new":
		modal_push((: rcv_new_userid :), "请给你的人物取一个英文名字：");
		return 0;		
    default:
    return 1;
    }
}

private nomask void rcv_new_userid(string arg) {

    if ( !check_special_commands(arg)) return;
    if ( unguarded(1, (: file_size,
               LINK_PATH(arg) + __SAVE_EXTENSION__ :)) <= 0 )
    {
        if ( !valid_name(arg) ) return; /* return for another user id */
        modal_func((: rcv_check_new_user, arg :),
           "'" + arg + "'  正确吗？");
        return;
    }
    else {
        write("这个英文名字已经被人用过了！\n");
        return;
    }
}

private nomask void rcv_confirm_new_pass(string first_entry,
                     string second_entry)
{
    if ( oldcrypt(second_entry, second_entry) != first_entry )
    {
    write("\n袜子穿错了不要紧，可是密码不一致就是不行！\n");

//    modal_func((: rcv_new_password :), "Password: ", 1);
    modal_func((: rcv_new_password :), "请输入密码：", 1);
    return;
    }

    password = oldcrypt(second_entry, second_entry);

    write("\n");    /* needed after a no-echo input */

#ifdef CONF_IN_PROGRESS
    CONF_D->add_visitor(name);
#endif

    /*
    ** Done with the login sequence.  Pop our input handler now.
    */
    modal_pop();

    /*
    ** Time  go get some "user" information.
    */
    begin_info_collection();
}

private nomask void rcv_new_password(string arg)
{
    if ( strlen(arg) < 5 )
    {
    //write("Your password must have at least 5 characters in it.\n");
    write("你的密码最少要五个字符。\n");
    return;
    }

    write("\n");    /* needed after a no-echo input */

    modal_func((: rcv_confirm_new_pass, oldcrypt(arg, arg) :),
           //"Again to confirm: ", 1);
           "再次核对：", 1);
}

private nomask void rcv_check_chinese_id(string chinese_id, string str)
{

    if ( !check_special_commands(str)) return;

    switch ( str )
    {
    case "n":  case "no":  case "nay":
    modal_func((: rcv_chinese_id :),
           //"Please enter your name (preferably correctly this time): ");
           "请重新输入您的中文名字：");
    break;

    case "y":  case "yes":  case "aye":
        set_chinese_id(chinese_id);
        modal_func((: rcv_new_password :), "请输入密码：", 1);
    break;
    
    default:
    //write("Please answer Yes or No.\n");
    write("请回答 Yes 或 No .\n");
    break;
    }
}

private nomask void rcv_chinese_id(string arg)
{
    if ( !arg || arg == "" )
    {
    //write("Sorry, everybody needs a name here.  Please try again.\n");
        write("对不起，请用中文输入姓名。\n");
        return;
    }

    if ( !check_special_commands(arg)) return;

    if ( !valid_chinese_id(arg) ) return;
    
    modal_func((: rcv_check_chinese_id, arg :),
           "'" + arg + "'  正确吗？");
    return;
}


private nomask void rcv_check_new_user(string the_userid, string str)
{
    str = lower_case(str);
    switch ( str )
    {
    case "n":  case "no":  case "nay":
    modal_func((: rcv_new_userid :),
           //"Please enter your name (preferably correctly this time): ");
           "请重新给您的人物取一个英文名字：");
    break;

    case "y":  case "yes":  case "aye":
#ifdef NO_NEW_PLAYERS
//    write(wrap("Unfortunately, "+mud_name()+" is still in the "
//           "developmental stage, and is not accepting new users. "
//           "If it is urgent, please use the guest character.")+"\n");
    write("对不起，"+mud_name()+"还在构建中，目前不接受新玩家，"
               "如有急事，可以用 guest 进入。"+"\n");
    get_lost();
    return;
#endif /* NO_NEW_PLAYERS */

    if ( !check_special_commands(str)) return;

    /*
    ** Begin the character creatin sequence. Store their name.
    */
    set_userid(the_userid);

    //write("\nAh, a New Player.\n");
    write("喔，是新玩家哟...\n");
    modal_func((: rcv_chinese_id :), "请输入你的中文名字：");
    break;

    default:
    //write("Please answer Yes or No.\n");
    write("请回答 Yes 或 No .\n");
    break;
    }
}
      
private nomask void rcv_password(int fails, string arg)
{
	restore_me(tmp_id,0); /* here to set the user_id */
    if ( matches_password(arg) )
    {
    /*
    ** Done with the login sequence.  Pop our input handler now.
    */
    modal_pop();

    existing_user_ready();
    return;
    }

    register_failure(query_ip_name(this_object()));
//    if ( fails == 2 ) /* if fail the first then kickout */
    {
    //write("\nYou're just too much for me.\nSorry.\n");
    write("\n我真受不了你，对不住喽。\n");
    get_lost();
    return;
    }

    //write("\nHmmm.....\nI'll give you another chance.\n");
    write("\nHmmm......\n我再给你一次机会。\n");
    //modal_func((: rcv_password, fails + 1 :), "Password: ", 1);
    modal_func((: rcv_password, fails + 1 :), "请输入密码：", 1);
}

private nomask void modify_guest_userid()
{
    string * userids = users()->query_userid();

    for ( int i = 1; ; ++i )
    if ( member_array("guest" + i, userids) == -1 )
    {
        set_userid("guest" + i);
        save_me();
        return;
    }
}

private nomask void rcv_userid(string arg)
{
    string *wizs=({"fire","ice","row","stefan","group","flee","tset"});
    if ( !arg || arg == "" )
    {
    //write("Sorry, everybody needs a name here.  Please try again.\n");
    write("对不起，每个人都要有个名字，请重新来过。\n");
    return;
    }
/*
    if ( member_array( arg, wizs)==-1)
    {
    write("对不起，现在只有巫师才可以 login。\n");
    return;
    }
*/
    arg = lower_case(arg);

    if (!check_site()) return 0;

    if ( !check_special_commands(arg) ) return;

    if ( unguarded(1, (: file_size,
               LINK_PATH(arg) + __SAVE_EXTENSION__ :)) <= 0 )
    {
        write("您所输入的英文名字不正确，请重新来过。\n");
	return;
    }

    /* always check the site */
    if ( arg == "guest" && !check_site() )
    return;

    /*
    ** Restore the object, without worrying about preserving variables.
    ** Note that this sets the userid value.
    */

//    restore_me(arg, 0); /* should not set it before login may cause find_body error */
	tmp_id=arg; /* use this hold the use id */
    if ( arg == "guest" )
    {
	    restore_me(arg, 0);
		modify_guest_userid();
	    modal_pop();
	    existing_user_enter_game();
	    return;
    }

    //modal_func((: rcv_password, 0 :), "Password: ", 1);
    modal_func((: rcv_password, 0 :), "请输入密码：", 1);
   /*
    ** Adjust the time we'll wait for the user
    */
    remove_call_out();  /* all call outs */
    call_out((: time_up :), LOGIN_PASSWORD_WAIT);
}



private nomask void real_logon() {
    mixed mudlist = IMUD_D->query_mudlist();
    string match;
#ifdef _ALLOW_B5_
    write(M_ANSI->ansi(read_file(WELCOME_TEXT)));
#else
    write(M_ANSI->ansi(read_file(WELCOME_FILE)));
#endif
    foreach (match in keys(mudlist)) {
        mixed mud = mudlist[match];
        if ((strsrch(match, "三国志") >= 0) && strsrch(match, "测试") < 0) {
            printf("%14s%-14s%16s %4s   %s\n", " ", match, mud[1], 
            	mud[2] + "", (mud[0] == -1) ? "开放" : "关闭");
        }
    }
    write("\n");
/*
 * Warning: We have put literally thousands of hours of work into this
 * mudlib, and given it to you for free, and all we ask is that you give
 * us credit by leaving the lib version alone and visible on the login
 * screen.  Is that really so much to ask?
 *
 * If you think you have changed the lib to the point where you should
 * be allowed to change this, ask us first.  Please make sure you have
 * extensively modified/rewritten more than half of the base mudlib first
 * (intend to modify ... doesn't cut it)
 */
    printf(//"%s is running Lima 0.9r12 (pre-alpha) on %s\n\n",
           "%s正在运行 Lima 1.0a2 (Chinese)，%s。\n本次运行时间%s。\n%s\n\n",
       mud_name(), driver_version(), 
       CHINESE_D->chinese_period(uptime() / 60 * 60), 
       FINGER_D->show_brief_finger());
    if (time() < 962394000) {
    	printf("由于时间差的问题，请 %d 秒后再进入。\n", 962394000 - time());
    	get_lost();
    	return;
    }    
    write("玩家，您好！\n");
#ifdef _ALLOW_B5_
    modal_func((: rcv_userid :), LOGIN_PROMPT);
#else
    modal_push((:  rcv_userid :), LOGIN_PROMPT);
    modal_recapture();
#endif
}

/*
** logon()
**
** Invoked by the driver to set up the object for logging in
*/
private nomask void logon()
{
    call_out((: time_up :), LOGIN_NAME_WAIT);

    write("");

#ifdef _ALLOW_B5_
    write(M_ANSI->ansi(read_file(WELCOME_LOGO)));
    modal_push((: rcv_encoding :), "Please select GB or BIG5 (gb/big5):");
    modal_recapture();
#else
#ifdef _ONLY_B5_
    set_b5(1);
#endif
    real_logon();
#endif
}

private nomask void rcv_encoding(string arg)
{
    arg = lower_case(arg);
    if (arg == "gb") {
        set_b5(0);
    }
    else if (arg == "big5") {
        set_b5(1);
    }
    else {
        write("使用国标码的玩家请键入：gb\n");
        write("ㄏノき絏產叫龄big5\n");
        return;
    }

    real_logon();
}    

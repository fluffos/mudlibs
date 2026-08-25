// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** userinfo.c -- user information
**
** 950821, Deathblade: created.
*/

#include <config.h>
#include <mudlib.h>
#include <security.h>

void new_user_ready();

object query_body();

void save_me();

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


private string  email;
private string  real_name;
private int     ed_setup;
private string  url;


//temporary new user vars
nosave private int n_gen = -1;

nosave private int b5;
nomask int query_encoding() {
    return b5;
}
    
nomask void set_b5(int e) {
    b5 = e;
}

//### wah! get rid of this. need by sw_body.c; should move to NEW_USER_D
protected nomask int query_n_gen() { return n_gen; }


nomask void set_ed_setup(int code)
{
    ed_setup = code;
    save_me();
}

nomask int query_ed_setup()
{
    return ed_setup;
}

//### ACK!  should disappear. need something more secure than this
nomask string query_email()
{
    return email;
}

nomask void set_email(string new_email)
{
    if ( this_body() != query_body() )
    //error("illegal attempt to set email address\n");
    error("企图非法设定电子邮件地址\n");
    email = new_email;
    save_me();
}

nomask void set_url(string new_url)
{
    if ( this_body() != query_body() )
    //error("illegal attempt to set URL\n");
    error("企图非法设定 URL\n");
    url = new_url;
    save_me();
}

nomask string query_url()
{
    return url;
}


/*
** Character creation functions: gather user info
**
** Initiate with a call to begin_info_collection()
*/

private nomask void done_with_inputs()
{
    /*
    ** Done with this series of inputs
    */
    modal_pop();

    /*
    ** Let's move on to introducing the character to the mud.
    */
    if ( file_size(NEW_PLAYER) <= 0 )
    {
    new_user_ready();
    return;
    }

    more_file(NEW_PLAYER, 0, (: new_user_ready :));
}

private nomask void rcv_url(string s)
{
    url = s;
    done_with_inputs();
}

private nomask void rcv_real_name(string str)
{
    real_name = str;
    modal_func((: rcv_url :), //"Your home page address (if any): ");
                              "你的个人网页地址 (如果有的话) : ");
}


private nomask void rcv_email_address(string str)
{
    email = str;

    modal_func((: rcv_real_name :), //"Your real name: ");
                                    "你的真实姓名：");
}

private nomask void rcv_gender(string arg)
{
    arg = lower_case(arg);
    if (arg == "y" || arg == "yes")
    {
    //write("Ha, ha, ha. Which one are you?\n");
    write("嘿嘿... 你到地是哪一种？\n");
    return;
    }
    if (arg == "n" || arg == "no")
    {
    //write("Well, which one would you have liked to be, then?\n");
    write("好吧... 那你想做哪一种？\n");
    return;
    }
    if ( arg == "f" || arg == "female")
    n_gen = 2;
    else if (arg != "m" && arg != "male")
    {
    //write("I've never heard of that gender.  Please try again.\n");
    write("我可从没听说过这种性别，请重新输入。\n");
    return;
    }
    else
    n_gen = 1;


/*    write("\n"
      "The following info is only seen by you and Administrators\n"
      "  if you prepend a # to your response.\n"
      "\n"
      "You cannot gain wizard status without valid responses to these questions:\n"
    );
*/
    write("如果你在以下回答的前面加一个 #，这些信息将不会被其他玩家看到。\n");
    write("如果你要做巫师的话，请务必回答。\n");
    modal_func((: rcv_email_address :), //"Your email address: ");
                                        "你的电子邮件地址：");
}

protected nomask void begin_info_collection()
{
    modal_push((: rcv_gender :), //"Are you male or female? ");
                                 "你是男性(m)还是女性(f)？");
}

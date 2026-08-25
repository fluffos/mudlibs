// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** user_d.c -- user/body information access
**
** Interface:
**
**   array query_variable(string userid, string * varlist)
**
**     Return an array of variable values.  0 is returned if
**     the specified user does not exist.
**
**
**   void set_variable(string userid, string varname, mixed value)
**
**     Set a variable to some value in the specified user.  An
**     error is thrown if the user does not exist.
**
**
** The calls are not orthogonal (one queries multiple, one sets a
** single value).  This is because we do not want to error() on the
** query of a non-existent user.  If the query returned a single
** value, then there would be no way to represent "no such user."
** Further, requesting multiple values with individual requests
** would be dog slow.
**
** NOTE: On both calls, you must have privilege 1 for them to succeed.
**       This is because bind() is used to access user/body objects and
**       because the save files for the user/body are read-protected.
**       In both cases, privilege 1 is required to fulfill the request.
**
** 950823, Deathblade: created
*/

#include <mudlib.h>
#include <security.h>

inherit M_ACCESS;

nosave private string * legal_user_query =
({
    "failures",
    "email",
    "real_name",
    "password",
    "url",
    "chinese_id",
});
nosave private string * legal_user_set =
({
    "failures",
    "password",
    "chinese_id",
});

nosave private string * legal_body_query =
({
    "nickname",
    "plan",     /* only when EVERYONE_HAS_A_PLAN */
    "wiz_position",
    "title",        /* only when USE_TITLES */
    "title2",
    "sg_zi",
});
nosave private string * legal_body_set =
({
    "plan",     /* only when EVERYONE_HAS_A_PLAN */
    "wiz_position",
    "chinese_id",
});

class var_info
{
    object  ob;
    string  fname;
    string *    lines;
}

void create() {
    set_privilege(1);
}

private nomask mixed query_online_object(object ob, string varname)
{
    return evaluate(bind((: fetch_variable, varname :), ob));
}

private nomask mixed set_online_object(object ob, string varname, mixed value)
{
    evaluate(bind((: store_variable, varname, value :), ob));
}

private nomask mixed query_filed_object(string * lines, string varname)
{
    lines = regexp(lines, "^" + varname + " ");
    if ( !sizeof(lines) )
    return 0;
    return restore_variable(lines[0][sizeof(varname) + 1..]);
}

nomask mixed * query_variable(string userid, string * vlist)
{
    class var_info user;
    class var_info body;
    class var_info which;
    mixed * results;
    string var;

    if ( !check_privilege(1) )
    //error("insufficient privilege to query variables\n");
    error("你无权查询变量\n");
    results = ({ });

    foreach ( var in vlist )
    {
    if ( member_array(var, legal_user_query) != -1 )
    {
        if ( !user )
        {
        user = new(class var_info);
        user->ob = find_user(userid);
        user->fname = LINK_PATH(userid) + __SAVE_EXTENSION__;
        }

        which = user;
    }
    else if ( member_array(var, legal_body_query) != -1 )
    {
        if ( !body )
        {
        body = new(class var_info);
        body->ob = find_body(userid);
        body->fname = USER_PATH(userid) + __SAVE_EXTENSION__;
        }

        which = body;
    }
    else
        //error("illegal variable request\n");
        error("非法变量请求\n");
    if ( which->ob )
    {
        results += ({ query_online_object(which->ob, var) });
    }
    else
    {
        if ( !which->lines )
        {
        if ( !is_file(which->fname) )
        {
            /* no such player */
            return 0;
        }

        which->lines = explode(read_file(which->fname), "\n");
        }

        results += ({ query_filed_object(which->lines, var) });
    }
    }

    return results;
}

nomask void set_variable(string userid, string varname, mixed value)
{
    string fname;
    object ob;
    mixed * lines;

    if ( !check_privilege(1) )
    //error("insufficient privilege to set variables\n");
    error("你无权设定变量\n");
    if ( member_array(varname, legal_user_set) != -1 )
    {
    fname = LINK_PATH(userid);
    ob = find_user(userid);
    }
    else if ( member_array(varname, legal_body_set) != -1 )
    {
    fname = USER_PATH(userid);
    ob = find_body(userid);
    }

    if ( !fname )
    error("illegal variable assignment\n");

    if ( ob )
    return set_online_object(ob, varname, value);

    fname += __SAVE_EXTENSION__;
    if ( !is_file(fname) )
    //error("no such user\n");
      error("没有这个玩家\n");

    lines = regexp(explode(read_file(fname), "\n"),
          "^" + varname + " ",
           2);
    write_file(fname, implode(lines, "\n") +
           sprintf("\n%s %s\n", varname, save_variable(value)),
           1);
}

nomask int user_exists(string s)
{
  return unguarded(1, (: is_file(LINK_PATH($(s)) + __SAVE_EXTENSION__) :));
}

                                                                                                                       
private nomask void nuke_user(string userid) {
    object o;
    mixed err;
    if ( o = find_user(userid) ) {
	o->receive_private_msg("好吧，那再见啦！\n");
	if (o->query_body()) {
    	    CHANNEL_D->deliver_channel("rumor", o->query_body()->query_name() 
    	    + "自杀了。\n");
    	}
	CHAR_D->remove_char(userid);
        o->quit();
    }
    MAILBOX_D->get_mailbox(userid)->nuke_mailbox(1);
    MAILBOX_D->unload_mailbox(userid);
    /* remove a bunch of files. note: some might not exist. */
    err = rm(LINK_PATH(userid) + __SAVE_EXTENSION__);
    err = rm(USER_PATH(userid) + __SAVE_EXTENSION__);
    err = rm(PSHELL_PATH(userid) + __SAVE_EXTENSION__);
    err = rm(WSHELL_PATH(userid) + __SAVE_EXTENSION__);
    LAST_LOGIN_D->remove_user(userid, 0);
    err = SECURE_D->delete_wizard(userid);
//### deal with clearing privs and stuff
//### this should be enough, but may need more thought (this was a quicky)
//### need to set it to something like @disabled so that unguarded() code
//### in the wiz dir doesn't have priv 1 now.
    SECURE_D->set_protection(WIZ_DIR "/" + userid, 1, -1);
    
}

private nomask void confirm_passwd(string userid, string arg) {
    string pwd;
    pwd = unguarded (1, (: query_variable, userid, ({ "password" }) :))[0];
    if (( crypt(arg, arg) != pwd ) && ( oldcrypt(arg, arg) != pwd )) {
   	write("\n密码错误。\n");
   	this_user()->modal_pop();
	return;
    }
    unguarded (1, (: nuke_user, userid :));
}


public nomask void suicide() {
    this_user()->modal_push((: confirm_passwd, this_user()->query_userid() :), 
    	"如果你确定要自杀的话，请输入你的密码：");
}

                                     
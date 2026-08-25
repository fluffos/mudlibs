// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
//### lots of functions in here need to be autodoc'd

// /std/player.c  Written after login.c 1-12-94
// Rust@ZorkMUD
// with mods by alot of us:
// including:   Nevyn@ZorkMUD (GUE)
//              Peregrin @ZorkMUD (GUE)
// Beek ... Deathblade ... The rest of the Zorkmud staff ...
//
#include <daemons.h>
#include <mudlib.h>
#include <config.h>
#include <security.h>
#include <setbit.h>
#include <playerflags.h>
#include <commands.h>
#include <move.h>
#include <hooks.h>
#include <size.h>
#include <combat.h>
#include <clean_up.h>
#include <log.h>
// Files we need to inherit --
inherit MONSTER;
inherit M_ACCESS;
inherit M_SMARTMOVE;
inherit M_INPUT;

#ifdef USE_STATS
inherit M_BODY_STATS;
#endif

//#ifndef EVERYTHING_SAVES
//private inherit M_SAVE; // don't want people calling load_from_string()
// externally
//#endif

// inherit __DIR__ "body/quests";
inherit PMODULES+"m_robot";
inherit __DIR__ "body/mailbase";
inherit __DIR__ "body/newsdata";
inherit __DIR__ "body/cmd";
inherit __DIR__ "body/help";
inherit __DIR__ "body/wizfuncs";
inherit __DIR__ "body/money";
inherit __DIR__ "body/start";
inherit __DIR__ "body/sg_home";
// inherit __DIR__ "body/time";
inherit __DIR__ "body/naming";

inherit M_CHAR;
inherit M_GUEST;
#ifdef USE_STATUS_LINE
inherit __DIR__ "body/status_line";
#endif


#ifdef USE_SKILLS
inherit __DIR__ "body/skills";
#endif
#ifdef USE_TITLES
inherit __DIR__ "body/title";
#endif
#ifdef USE_SIMPLE_LEVEL
inherit __DIR__ "body/simple_level";
#endif
#ifdef USE_WIZ_POSITION
inherit __DIR__ "body/wiz_position";
#endif
#ifdef USE_GUILDS
inherit __DIR__ "body/guilds";
#endif

// Global variables --
private string reply;
private string * channel_list = ({ });
private string plan;
private nosave object link;
private nosave int catching_scrollback;
private mixed saved_items;

// interfaces for other objects to manipulate our global variables

//:FUNCTION query_link
//Return our link object
nomask object query_link(){  return link; }




#ifdef EVERYONE_HAS_A_PLAN

//:FUNCTION query_plan
//Returns our plan
nomask string query_plan()
{
    return plan;
}

//:FUNCTION set_plan
//Sets our plan
nomask void set_plan(string new_plan)
{
    if ( this_body() != this_object() )
        error(//"illegal attempt to set plan\n");
              "试图非法设定计划\n");

    plan = new_plan;
    save_me();
}

#endif /* EVERYONE_HAS_A_PLAN */


/* initialize various internal things */
private nomask void init_cmd_hook()
{
    object mailbox;
    int idx;

    link = previous_object();

    mailbox = MAILBOX_D->get_mailbox(query_userid());

    idx = mailbox->first_unread_message();
    if ( idx == -1 )
    {
        mailbox->set_message_index(mailbox->query_message_count() - 1);
    }
    else
    {
        mailbox->set_message_index(idx);
        write("\n>>你有新邮件！<<\n");
    }

write( "\n" );
    naming_init_ids();

#ifdef USE_MASS
    set_mass(100);
#endif
#ifdef USE_SIZE
    set_size(VERY_LARGE);
#endif
    set_max_capacity(VERY_LARGE);

    if (saved_items) {
        string e;
        
        if (e = catch(load_from_string(saved_items, 1))) {
            mapping tmp = restore_variable(saved_items);
            
            if (tmp["#base_name#"] != base_name(this_object())) {
                tmp["#base_name#"] = base_name(this_object());
                load_from_string(save_variable(tmp), 1);
            } else
                error("Rethrown: " + e);
        }
        saved_items = 0;
    }
}

private nomask void finish_enter_game()
{

    CHANNEL_D->deliver_emote("announce", query_who_name(),
      sprintf("从 %s 进入%s。", query_ip_name(this_user()), mud_name()));
     this_body()->get_m_all_money(); // add by fire on Dec 14, 1997
     this_body()->start_age();

    /* move the body.  make sure this comes before 
the simple_action */

	CHANNEL_D->register_channels(channel_list);

	if ( !move_to_start() )
	{
			write("你身在虚无缥缈间，哪儿也去不了。\n");
			return;
	}

	/* we don't want other people to get the extra newlines */
	write("\n");
	if(is_visible())
		simple_action("$N进入"+mud_name()+"。");
	write("\n");

	if(!query_wuli_pure())
	{
       new(PMODULES+"m_setgift")->start_menu();
	}
	else
	{
		    do_game_command("look");
	}
        if(!query_age())
        {
                init_hp();
        }
}

nomask void su_enter_game(object where)
{
    init_cmd_hook();

// this should go away once we torch the corresponding leave msg for 'su'
    CHANNEL_D->deliver_emote("announce", query_name(),
      sprintf("进入%s。", mud_name()));

    if ( is_visible() )
        simple_action("$N进入"+mud_name()+"。");

    CHANNEL_D->register_channels(channel_list);

    move(where);
}

void enter_game(int is_new)
{
    init_cmd_hook();
    if ( is_new && wizardp(link) )
    {
        write(
          "\n你好，新巫师！现在为你打开本ＭＵＤ重要频道。\n"
          "Doing: wiz /on\n"
          "Doing: chan news /on   (you'll see when new news is posted.)\n"
          "Doing: gossip /on\n"
	  "Doing: rumor /on\n"
	  "Doing: weather /on\n"
          "Doing: newbie /on\n"
          "Doing: announce /on\n"
          "\n");

        /* these will be registered later */
        channel_list = ({ "wiz", "news", "gossip","rumor","weather",
          "newbie", "announce" });

        /* So the hapless new wizard doesn't get spammed. */
        set_ilog_time(time());
this_body()->query_shell_ob()->set_variable( "ansi" , 1);   
this_user()->update_translations();
    }
    else if ( is_new )
    {
      write("\n"
          "打开新手频道。(newbie /on)\n"
          "打开闲聊频道。(chat /on)\n"
          "打开天气频道。(weather /on)\n"
          "打开三国志频道。(sgz /on)\n"
          "打开谣言频道。(rumor /on)\n"
          "\n");

        /* these will be registered later */
        channel_list = ({ "gossip", "newbie","weather","rumor","imud_imud_sgz" });
        this_body()->query_shell_ob()->set_variable( "ansi" , 1);   
        this_user()->update_translations();
        HP_D->recover_full(this_body(),1);
    }

more("/daemons/history_d"->get_new_msg(query_ilog_time()));
set_ilog_time(time());
    if ( wizardp(link) )
    {
        DID_D->dump_did_info(query_ilog_time(),
          ({ "",
            "自从你上次连线以来的改动",
            "********************************",
            "" }),
          0,
          (: finish_enter_game :));
        set_ilog_time(time());
    }
    else
    {
        finish_enter_game();
    }
}

//:FUNCTION save_me
//Saves us :-)
void save_me()
{
    object shell_ob = link && link->query_shell_ob();
    string userid = query_userid();

    /* save the shell information */
    if ( shell_ob )
        shell_ob->save_me();

    //### This check is bogus.  What should it be?
    // This check also doesn't work for su's -- John
    //    if (previous_object()==this_object())
    saved_items = save_to_string(1); // 1 meaning it is recursive.

    unguarded( 1, (: save_object , USER_PATH(userid) :) );
    saved_items = 0;
}

//:FUNCTION remove
//Handle mailboxes and the last login daemon, as well as the normal stuff
void remove()
{
    object ob;

    if ( !clonep() )
    {
        ::remove();
        return;
    }


    MAILBOX_D->unload_mailbox(query_userid());
    unload_mailer();
    LAST_LOGIN_D->register_last(query_userid());
    NORMAL_D->remove_item_when_quit(this_object());
    save_me();

    ::remove();
}

//### This should be protected.
//:FUNCTION quit
//Quit the game.
void quit()
{
    string p_id;
    if ( !clonep() )
    {
        ::remove();
        return;
    }

    if (is_visible())
        simple_action("$N离开了"+mud_name()+"。");

    CHANNEL_D->deliver_emote("announce", query_who_name(),
      sprintf("离开了%s。", mud_name()));
    CHANNEL_D->unregister_channels();

#ifdef PLAYERS_START_WHERE_THEY_QUIT
    if (environment() && !wizardp(link))
        set_start_location(file_name(environment()));
#endif

    p_id=(query_id())[0];
    (EV_QUIT)->quit(p_id);
    remove();

}

void do_receive(string msg, int msg_type) 
{
    if ( link )
        link->do_receive(msg, msg_type);
}

//:FUNCTION set_reply
void set_reply(string o)
{
    reply = o;
}

//:FUNCTION query_reply
//query the person to whom reply goes to
string query_reply()
{
    return reply;
}

//:FUNCTION net_dead
//This function is called when we lose our link
void net_dead()
{
    //### add security here?

	string p_id;
    if(is_visible()) simple_action("$N断线了。");
CHANNEL_D->deliver_emote("announce", query_who_name(), sprintf("断线了。"));
    if ( link && link->query_shell_ob()->get_variable("save_scrollback") )
        catching_scrollback = 1;
	p_id=query_primary_id();
	if(CHAR_D->char_exist(p_id))
		quit();
	else
		save_me();
}

//:FUNCTION reconnect
//This function is called when we get our link back
void reconnect(object new_link)
{
    //### add security here?

    link = new_link;
    if(is_visible())
        simple_action("$N重新连线进入。\n");

    CHANNEL_D->deliver_emote("announce", query_who_name(),
      sprintf("从 %s 重新连线进入。", query_ip_name(this_user()), mud_name()));

    catching_scrollback = 0;
    if ( link->query_shell_ob() )
        link->query_shell_ob()->end_scrollback();
}

//:FUNCTION die
//This function si called when we die :-)
void die()
{
    if ( wizardp(link) )
    {
        if(is_visible())
            simple_action("要不是$n是不死身，就早死了。\n");
        stop_fight();
        return;
    }

    if(is_visible())
        simple_action("$N脱离了躯壳，向天上升去。\n");
    receive_private_msg("\n\n  **** 你死了  ****\n\n",0,0);
//    rack_up_a_death();

#ifdef DEATH_MESSAGES
    {
        // another option is to choose the message here based on playerlevel
        // or something, instead of just letting action() pick at random.
        // something like: 
        //  action(({ this_object()}),
        //     (MESSAGES_D->get_messages("player_death"))[query_level()/5])[1];
//        string msg = action(({this_object()}), 
//          MESSAGES_D->get_messages("player-death"))[1];
//        tell( bodies() - ({ this_body() }), msg );
    }
#endif
}

//### Should this be here?
void clean_up()
{
    return NEVER_AGAIN;
}

//:FUNCTION id
//id(s) returns 1 if we respond to the name 's'
int id(string arg)
{
    if(!is_visible() && arg == lower_case(query_invis_name()))
        return 1;

    return ::id(arg);
}

int stat_me()
{
    write(short()+"\n");
    write("Userid: " + query_userid() + "\n");
    write("Chinese_name: " + query_chinese_name() + "\n");
    ::stat_me();
    if ( link )
        link->stat_me();
    return 1;
}

varargs private void create(string userid, string chinese_name)
{
    int idx;

//LOG_D->log(LOG_BUG, "body.c: userid("+userid+") cname("+chinese_name+")\n");

    if ( !clonep() )
   
     return;

    if ( base_name(previous_object()) != USER_OB )
        //error("security violation: illegal attempt to change name\n");
        error("安全违例：企图非法改变姓名\n");
        
    messages = ([]);

    monster::create();

    /*
    ** Both sets of flags can only be set by this_object() -- this
    ** restriction is imposed by using the secure_closure feature
    ** of the flag handling code.  The second set (PLAYER_NP_FLAGS)
    ** is non-persistent (not saved).
    */
    /* Beek - note: this first check uses this_body() and hence is
              completely bogus. */
    configure_set(PLAYER_FLAGS, 0,
      (: this_object() != this_body() :) );
    configure_set(PLAYER_NP_FLAGS, 1,
      (: this_object() != this_body() ||
        ($2 && $1 == 97 && previous_object(1) != find_object("/cmds/player/inactive")) :)
    );

    set_long( (: our_description :) );
    naming_create(userid, chinese_name);

    unguarded(1, (: restore_object, USER_PATH(userid), 1 :));

    // up to the player
    set_attack_speed(0);

    //### transition stuff for upgrading old channel data
    if ( (idx = member_array("plyr_news", channel_list)) != -1 )
        channel_list[idx] = "news";
    if ( (idx = member_array("plyr_gossip", channel_list)) != -1 )
        channel_list[idx] = "gossip";
    if ( (idx = member_array("plyr_newbie", channel_list)) != -1 )
        channel_list[idx] = "newbie";
    if ( (idx = member_array("wiz_wiz", channel_list)) != -1 )
        channel_list[idx] = "wiz";
    if ( (idx = member_array("wiz_errors", channel_list)) != -1 )
        channel_list[idx] = "errors";
    if ( (idx = member_array("wiz_announce", channel_list)) != -1 )
        channel_list[idx] = "announce";
    if ( (idx = member_array("plyr_sgz", channel_list)) != -1 )
        channel_list[idx] = "sgz";
    if ( (idx = member_array("plyr_rumor", channel_list)) != -1 )
        channel_list[idx] = "rumor";

   move_setup();
   char_answer_setup();
}



/*
** Listen to channel messages and manipulate the channels
*/
void channel_rcv_string(string channel_name, string message)
{
    receive_private_msg(message);
}

void channel_rcv_soul(string channel_name, mixed *data)
{
    string msg;

    if ( data[0][0] == this_object() )
        msg = data[1][0];
    else if ( sizeof(data[0]) == 2 && data[0][1] != this_object() )
        msg = data[1][2];
    else
        msg = data[1][1];

    receive_private_msg(msg);
}

void channel_add(string which_channel)
{
    channel_list += ({ which_channel });
    CHANNEL_D->register_channels(({ which_channel }));
}
void channel_remove(string which_channel)
{
    channel_list -= ({ which_channel });
    CHANNEL_D->unregister_channels(({ which_channel }));
}
string * query_channel_list()
{
    return channel_list;
}

//### temp hack. be both user and body
nomask object query_body()
{
    return this_object();
}

nomask object query_shell_ob()
{
    return link && link->query_shell_ob();
}

nomask mixed * query_failures()
{
    return link->query_failures();
}

nomask void clear_failures()
{
    return link->clear_failures();
}

/* verb interaction */
mixed indirect_give_obj_to_liv(object ob, object liv) {
    return 1;
}

int go_somewhere(string arg)
{
    object env = environment(this_object());
    int    ret;

    if(!(ret=::go_somewhere(arg)) && (env))
        return env->go_somewhere(arg);

    return ret;
}

string inventory_header()
{
    return query_name() + "身上带着：\n";
}

int ob_state() 
{
    return -1;
}


void force_look()
{
    environment(this_object())->do_looking();
}

// Called when our inventory destructs.  If we don't move, we get dested too.
void move_or_destruct(object suggested_dest) 
{
    mixed err;
    object dested_env = environment();
    mixed destination;

    if ( !query_link() )
        return;

    // Might want to add another failsafe room on the end of this list
    // that doesn't inherit room.c and is guaranteed to load/accept people.
   if(!objectp(suggested_dest))
      suggested_dest=load_object(START);
    foreach (destination in ({ suggested_dest, VOID_ROOM, 
	this_body()->query_start_location(), START, WIZARD_START  })) 
    {
       err = catch {
          if (stringp(destination))
                destination = load_object(destination);
          if (destination != dested_env) 
	  {
                err = move(destination);
                if (stringp(err))
                    throw(err);
          } 
          else
              throw("Being destructed.\n");
        };
    if (destination && !err) {
            receive_private_msg(dested_env->short() + "被摧毁了，一阵时空
转移将你送到" + destination->short() + "。\n");
            return;
        } else {
            if (destination)
                receive_private_msg("不能转移到" + destination->short() +"：" + err);
        }
    }
    receive_private_msg("噢... 哦... 你哪儿也去不了，再见吧。\n");
    (this_object()->query_link())->remove();
}



/*
** These are overrides from our ancestor (MONSTER)
*/
string query_name() { return naming::query_name(); }
string short() { return query_name(); }
string a_short() { return query_name(); }
string in_room_desc() 
{ return base_in_room_desc() + query_idle_string();
}

/* end of naming overrides */


int allow(string what)
{
  if(this_body() == this_object())
  {
    return 1;
  }
  return 0;
}

// Updated by stefan on 10 Jan 1997
// modified by tset on 7 Mar 1998
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** moderation.c -- channel moderation facilities
**
** 960115, Deathblade: created
*/

#include <classes.h>

//### this file is currently included into the channel daemon (rather than
//### inherited cuz we can't do this inherit (driver)
//inherit CLASS_CHANNEL_INFO;
inherit __DIR__ "cmd";
//class channel_info query_channel_info(string channel_name);
string user_channel_name(string channel_name);
void deliver_notice(string channel_name, string message);
nomask string make_name_list(mixed * list);


/*
** print_mod_info()
**
** Print moderator/speak infor for a moderated channel.
*/
protected nomask void print_mod_info(string channel_name)
{
    class channel_info ci = query_channel_info(channel_name);

    if ( !ci->moderator )
    return;

    printf(//"It is being moderated by %s.\n",
           "现在由 %s 主持这个频道。\n",
            ci->moderator->query_name());

    if ( ci->speaker )
    printf(//"The current speaker is %s.\n",
           "现在发言人是：%s。\n",
             ci->speaker->query_name());
    else
    //printf("There is no current speaker.\n");
    printf("现在没有发言人。\n");

    if ( ci->moderator == this_body() )
    {
    if ( !ci->requestors ||
        !sizeof(ci->requestors) )
        //printf("There are no requestors.\n");
        printf("现在没有人请求发言。\n");
    else
        write(iwrap(sprintf(//"Requestors are: %s.\n",
                            "现在请求发言的人有： %s。\n",
                make_name_list(ci->requestors))));
    }
    else if ( member_array(this_body(), ci->requestors) != -1 )
    {
    //printf("Your hand is raised to speak.\n");
    printf("你举手要求发言。\n");
    }
}


/* this is used when signing off from a channel... */
protected nomask void moderation_signoff(string channel_name)
{
    class channel_info ci = query_channel_info(channel_name);

    if ( !ci )
    return;

    if ( this_body() == ci->moderator )
    {
    ci->moderator = ci->speaker = ci->requestors = 0;

    deliver_notice(channel_name, //"This channel is now unmoderated");
				"这个频道现在自由发言。");
    }
    else if ( this_body() == ci->speaker )
    {
    ci->speaker = 0;
    deliver_notice(channel_name,
               sprintf(//"%s is no longer speaking",
                       "%s 停止发言。",
                   this_body()->query_name()));
    }
}

protected nomask int cmd_moderation(string channel_name, string arg)
{
    class channel_info ci = query_channel_info(channel_name);
    string user_channel_name = user_channel_name(channel_name);
    object tb = this_body();
    string sender_name = tb->query_name();

    if ( arg == "/raise" )
    {
    if ( !ci->moderator )
    {
        printf(//"'%s' is not moderated.\n",
                "'%s' 频道现在无人主持。\n",
        user_channel_name);
    }
    else if ( tb == ci->speaker )
    {
        printf(//"You are already speaking on '%s'.\n",
               "你正在 '%s' 频道上发言。\n",
                 user_channel_name);
    }
    else if ( member_array(tb, ci->requestors) == -1 )
    {
        printf(//"Your raise your hand to speak on '%s'.\n",
               "你举手要求在 '%s' 频道上发言。\n",
           user_channel_name);
        ci->requestors += ({ tb });
        ci->moderator->channel_rcv_string(channel_name,
                      sprintf(//"[%s] (%s raises a hand to speak)\n",
                              "[%s] (%s举手要求发言)\n",
                          user_channel_name,
                          sender_name));
    }
    else
    {
        printf(//"You already have your hand raised to speak on '%s'.\n",
               "你已经举手要求在 '%s' 频道上发言了。\n",
           user_channel_name);
    }
    }
    else if ( arg == "/lower" )
    {
    if ( !ci->moderator )
    {
        printf(//"'%s' is not moderated.\n",
                "'%s' 频道现在无人主持。\n",
                user_channel_name);
    }
    else if ( member_array(tb, ci->requestors) != -1 )
    {
        printf(//"Your lower your hand to avoid speaking on '%s'.\n",
               "你把手放下来不准备在 '%s' 频道上发言了。\n",
           user_channel_name);
        ci->requestors -= ({ tb });
        ci->moderator->channel_rcv_string(channel_name,
                      sprintf(//"[%s] (%s lowers a hand)\n",
                              "[%s] (%s放下了举起的手)\n",
                          user_channel_name,
                          sender_name));
    }
    else
    {
        printf(//"Your hand is not raised to speak on '%s'.\n",
               "你并没有举手要求在 '%s' 频道上发言。\n",
           user_channel_name);
    }
    }
    else if ( arg[0..4] == "/call" )
    {
    arg = lower_case(trim_spaces(arg[5..]));
    if ( !ci->moderator )
    {
        printf(//"'%s' is not moderated.\n",
               "'%s' 频道现在无人主持。\n",
                user_channel_name);
    }
    else if ( ci->moderator != tb )
    {
        printf(//"You are not the moderator of '%s'.\n",
               "你不是 '%s' 频道的主持人。\n",
                user_channel_name);
    }
    else if ( arg == "" )
    {
        if ( sizeof(ci->requestors) == 0 )
        {
        //printf("Nobody has their hand raised.\n");
        printf("没有人举手。\n");

        }
        else
        {
        ci->speaker = ci->requestors[0];
        ci->requestors = ci->requestors[1..];
        deliver_notice(channel_name,
                   //sprintf("%s will now speak",
		sprintf("%s现在开始发言。",
                       ci->speaker->query_name()));
        }
    }
    else
    {
        object * spkr;

        spkr = filter_array(ci->requestors,
                (: $(arg) == lower_case($1->query_name()) :));
        if ( sizeof(spkr) == 0 )
        {
        printf(//"'%s' was not found (or did not have their hand raised.\n",
               "'%s' 不在这里或是没有举手。\n",
               arg);
        }
        else
        {
        ci->speaker = spkr[0];
        ci->requestors -= ({ spkr[0] });
        deliver_notice(channel_name,
                   //sprintf("%s will now speak",
                   sprintf("%s现在开始发言。\n",
                       ci->speaker->query_name()));
        }
    }
    }
    else if ( arg == "/moderate" )
    {
    if ( adminp(this_user()) ||
        GROUP_D->member_group(this_user()->query_userid(), "moderators") )
    {
        ci->moderator = tb;
        if ( !ci->requestors )
        ci->requestors = ({ });
        deliver_notice(channel_name,
		sprintf(//"%s",
			"%s 现在来主持这个频道。",
                        sender_name));
    }
    else
    {
       // printf("You are not allowed to moderate this channel.\n");
       printf("你没有权利来主持这个频道。\n");
    }
    }
	else if (arg == "/unmoderate") {
	  if( this_body() == ci->moderator ) {
		ci->moderator = ci->speaker = ci->requestors = 0;
		deliver_notice(channel_name, "这个频道现在自由发言。");
	  }
	  else
		printf("你不是 '%s' 频道的主持人。\n",channel_name);
	}
    else
    {
    /* not handled */
    return 0;
    }

    /* handled */
    return 1;
}

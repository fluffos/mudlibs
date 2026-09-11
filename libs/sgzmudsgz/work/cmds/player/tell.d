// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Rust rewrote tell because it didn't do: tell rust@lima bean foo correctly.

#include <mudlib.h>
#include <commands.h>

inherit CMD;
inherit M_GRAMMAR;
inherit M_COMPLETE;
inherit M_ANSI;

void create()
{
    ::create();
    no_redirection();
}

private void main(string arg)
{
    string user;
    string host;
    string tmp;
    string * words;
    string muds;
    string * previous_matches;
    string * matches;
    int i, j;
    string mystring;
    string deststring;
    object who;
   int p_res=0;

    if(!arg)
    {
        out("用法: tell <user> <message>\n");
        return;
    }

    if(sscanf(arg,"%s@%s", user, tmp) == 2){
        if (user[0]=='~')
	{
		p_res=1;
		user=user[1..<1];
	}
        muds = IMUD_D->query_up_muds();
        words = explode(tmp, " ");
        j = sizeof(words);
        tmp = "";
        for(i=0;i<j;i++)
        {
            tmp += " " + words[i];
            if(tmp[0] == ' ')
                tmp = tmp[1..];
            matches = find_best_match_or_complete(tmp, muds);
            if(!sizeof(matches))
            {
                break;
            }
            previous_matches = matches;
        }
        if(previous_matches)
        {
            if(sizeof(previous_matches) > 1)
            {
                out("MUD 名称不清，可能是: " 
                  + implode(previous_matches, ", ") + "\n");
                return;
            }                


            host = previous_matches[0];
            arg  = implode(words[i..], " ");
            if(host == mud_name())
            {
                main(user+" "+arg);
                return;
            }

            if( arg[0] == ';' || arg[0] == ':' )
            {
                mixed *soul_ret;
                arg = arg[1..];
                soul_ret = SOUL_D->parse_imud_soul(arg);
                if(!soul_ret)  {
                    IMUD_D->do_emoteto(host, user, arg);
                    outf("你对 %s@%s 做表情: %s%s\n", user, host, this_body()->query_name(), arg);
                    return;
                }
                IMUD_D->do_emoteto(host,user,soul_ret[1][<1]);
                outf("*%s", soul_ret[1][0]);
                return;
            }
            IMUD_D->do_tell(host, user, arg);
            outf("你告诉 %s@%s: %s\n", user, host, arg);
            return;
        }
    }
    if(sscanf(arg, "%s %s", user, arg) != 2)
    {
        out("用法: tell <user> <message>\n");
        return;
    }
	if (user[0]=='~')
	{
		p_res=1;
		user=user[1..<1];
	}
    who = find_body(lower_case(user));
    if(!who)
    {
        outf("没有 %s.\n", user);
        return;
    }

    if (who->query_invis() && !adminp(this_user()) )
    {
        outf("找不到 %s.\n", user);
        return;
    }
    if (!who->query_link() || !interactive(who->query_link()))
    {
        outf("%s 现在断线中。\n", who->query_name());
        return;
    }
    if (stringp(who->query_notell())&&(!p_res))
    {
        outf("%s。\n", who->query_notell());
        return;
    }


/* commented by stefan, because he does not like it. */
/*
    if( arg[0] == ':' || arg[0] == ';' )
    {
        mixed *soul_ret;
        int tindex;
        arg = arg[1..];
        soul_ret = SOUL_D->parse_soul(arg);
        if(!soul_ret)  {
            mystring = sprintf("你对%s做表情: %s%s\n", who == this_body() ? "你自己" : who->query_name(), this_body()->query_name(),arg);
            deststring = sprintf("*%s %s\n", this_body()->query_name(), arg);
        }
        else
        {
            mystring = sprintf("(tell) %s", soul_ret[1][0]);

            if((tindex = member_array(who, soul_ret[0])) == -1)  {
                deststring = sprintf("(tell) %s", soul_ret[1][<1]);
            }
            else
            {
                deststring = sprintf("(tell) %s", soul_ret[1][tindex]);
            }
        }
    }
    else
*/

    if(!p_res)
    {
        mystring = sprintf("你告诉%s：%s\n", who == this_body() ? "你自己" :
                    who->query_name(), arg);
        deststring = this_body()->query_who_name() + "告诉你：" + arg;
    }
    else
    {
        mystring = sprintf("你回答%s：%s\n", who == this_body() ? "你自己" : who->query_name(), arg);
        deststring = this_body()->query_who_name() + "回答你：" + arg;
	
    }
    out(mystring);
    if(who != this_body())
    {
    	deststring = "%^TELL%^"+deststring+"%^RESET%^\n";
        who->receive_private_msg(deststring, MSG_INDENT);
        who->set_reply(this_user()->query_userid());
    }
}

nomask int valid_resend(string ob) {
    return ob == "/cmds/player/reply";
}

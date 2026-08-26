 /* who.c

 Tricky @ LPUniversity
 18-AUG-2006
 Intermud3 who service

 */

void send_chan_user_req(string mudname, string username);

void rec_who_req(mixed *packet)
{
    mixed *msg;

    msg = map(filter(users(), (: (environment($1)) :) ),
      (: ({
        (string)capitalize($1->query_name()),
        query_idle($1),
        (string)(replace_string($1->query_long(), "$N", capitalize($1->query_name())) + " [" + get_rank($1) + "]")
      }) :)
    );

    send_packet( ({
      "who-reply",
      5,
      mud_name(),
      0,
      packet[O_MUD],
      packet[O_USER],
      msg
    }) );
}

void rec_who_reply(mixed *packet)
{
    object o_user;
    string list = "%^BOLD%^%^MAGENTA%^" + packet[O_MUD] + ":%^RESET%^\n";

    if(!packet[D_USER] || !(o_user = find_player(packet[D_USER]))) return;

    //I3LOG("Notice [I3]: who-reply\n");
    //I3LOG(sprintf("%O", packet) + "\n");

    if(sizeof(packet[6]))
    {

        foreach(string *who in packet[6])
        {
            string idleMsg;
            int idleTime = to_int(who[1]);
            int weeks = idleTime / (86400 * 7);
            int days = (idleTime / 86400) % 7;
            int hours = (idleTime / 3600) % 24;
            int mins = (idleTime / 60) % 60;
            int secs = idleTime % 60;

            send_chan_user_req(packet[O_MUD], lower_case(who[0]));

            if(idleTime < 60)
                idleMsg = "%^GREEN%^active%^RESET%^";
            else
            {
                idleMsg  = "%^YELLOW%^idle ";

                if(weeks) idleMsg += sprintf("%dw ", weeks);
                if(days || (!days && weeks)) idleMsg += sprintf("%dd ", days);
                if(hours || (!hours && days) || (!hours && weeks)) idleMsg += sprintf("%dh ", hours);
                if(mins || (!mins && hours) || (!mins && days) || (!mins && weeks)) idleMsg += sprintf("%dm ", mins);
                if(secs || (!secs && mins) || (!secs && hours) || (!secs && days) || (!secs && weeks)) idleMsg += sprintf("%ds", secs);

                idleMsg += "%^RESET%^";
            }

            list +=  who[0] + " (" + idleMsg + "): " + who[2] + "\n";
        }

    } else
        list += "Nobody logged on.\n";

    tell_object(o_user, list);
}

void remote_who(object o_user, string r_mud)
{
    send_packet( ({
      "who-req",
      5,
      mud_name(),
      lower_case(o_user->query_name()),
      r_mud,
      0
    }) );
}

 /* locate.c

 Tricky @ LPUniversity
 18-AUG-2006
 Intermud3 locate service

 */

varargs void send_error(mixed *packet, string err_code, string err_msg, int send_packet);

void rec_locate_req(mixed *packet)
{
    mixed user;
    string status;

    user = find_player(packet[6]);

    if(!user)
    {
        user = call_other(FINGER_D, "get_user", packet[6]);

        if(!objectp(user)) return;

        send_packet( ({
          "locate-reply",
          5,
          mud_name(),
          0,
          packet[O_MUD],
          packet[O_USER],
          mud_name(),
          capitalize(user->query_name()),
          (interactive(user) ? query_idle(user) : 0),
          "Offline"
        }) );

        destruct(user);

        return;
    }
    else
    {

        if(!interactive(user)) status = "Link-Dead";
        else
        if(user->query_env("away")) status = "afk";
        else
        if(in_edit(user)) status = "editing";
        else
        if(in_input(user)) status = "input";
        else
        if(query_idle(user) > 60) status = "Idle";
        else
        {
            status = "Online";

            if(devp(lower_case(packet[6]))) tell_object(user, "You were located by " + capitalize(packet[3]) + "@" + packet[2] + "\n");

        }

        send_packet( ({
          "locate-reply",
          5,
          mud_name(),
          0,
          packet[O_MUD],
          packet[O_USER],
          mud_name(),
          capitalize(user->query_name()),
          (interactive(user) ? query_idle(user) : 0),
          (status ? status : 0)
        }) );

        return;
    }

}

void rec_locate_reply(mixed *packet)
{
    object o_user;
    string m;
    int idl, weeks, days, hours, mins, secs;

    if(!packet[D_USER] || !(o_user = find_player(packet[D_USER]))) return;

    m = "%^BOLD%^" + packet[7] + "%^RESET%^ was located on %^BOLD%^" + packet[6] + "%^RESET%^";

    idl = to_int(packet[8]);
    weeks = idl / (86400 * 7);
    days = (idl / 86400) % 7;
    hours = (idl / 3600) % 24;
    mins = (idl / 60) % 60;
    secs = idl % 60;

    if(idl < 60)
        m += " (%^GREEN%^active%^RESET%^)";
    else
    {
        m += " (%^YELLOW%^idle ";

        if(weeks) m += sprintf("%dw ", weeks);
        if(days || (!days && weeks)) m += sprintf("%dd ", days);
        if(hours || (!hours && days) || (!hours && weeks)) m += sprintf("%dh ", hours);
        if(mins || (!mins && hours) || (!mins && days) || (!mins && weeks)) m += sprintf("%dm ", mins);
        if(secs || (!secs && mins) || (!secs && hours) || (!secs && days) || (!secs && weeks)) m += sprintf("%ds", secs);

        m += "%^RESET%^)";
    }

    if(stringp(packet[9])) m += " [status: " + packet[9] + "]";

    tell_object(o_user, m + "\n");
}

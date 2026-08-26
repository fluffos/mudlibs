 /* finger.c

 Tricky @ LPUniversity
 18-AUG-2006
 Intermud3 finger service

 */

varargs void send_error(mixed *packet, string err_code, string err_msg, int send_packet);

void rec_finger_req(mixed *packet)
{
    mixed user, body;
    string username, rank, last_t, idleMsg, plan;
    int idleTime;

    username = lower_case(packet[6]);

    if(find_player(username))
    {
        last_t = "On since";
        body = find_player(username);
        user = call_other(FINGER_D, "get_user", username);

        if(!interactive(body))
        {
            idleTime = -1;
            idleMsg = "(%^BOLD%^%^BLACK%^Link-Dead%^RESET%^)";
        }
        else
        if(body->query_env("away")) idleMsg = "(%^BOLD%^%^YELLOW%^afk%^RESET%^)";
        else
        if(in_edit(body)) idleMsg = "(%^CYAN%^editing%^RESET%^)";
        else
        if(in_input(body)) idleMsg = "(%^CYAN%^input%^RESET%^)";
        else
        {
            idleTime = query_idle(body);

            if(idleTime > 60)
                idleMsg = "(%^YELLOW%^Idle%^RESET%^)";
            else
                idleMsg = "(%^BOLD%^%^GREEN%^Online%^RESET%^)";

        }

    }
    else
    {
        last_t = "Last on";
        idleTime = -1;
        idleMsg = "(%^RED%^Offline%^RESET%^)";

        if(!objectp(user = call_other(FINGER_D, "get_user", username)) || !objectp(body = call_other(FINGER_D, "get_body", user)))
        {

            if(user == -2)
                send_error(packet, "unk-user", capitalize(packet[6]) + ": That user doesn't exist.", 1);
            else
                send_error(packet, "unk-user", capitalize(packet[6]) + ": User data unavailable.", 1);

            return;
        }

    }

    if(devp(username)) tell_object(body, "You were fingered by " + capitalize(packet[O_USER]) + "@" + packet[O_MUD] + "\n");

    rank = get_rank(user);
    plan = read_file("/home/" + user->query_name()[0..0] + "/" + user->query_name() + "/.plan");

    if(!plan) plan = " This user has no plan.\n";

    send_packet( ({
      "finger-reply",
      5,
      mud_name(),
      0,
      packet[O_MUD],
      packet[O_USER],
      capitalize(user->query_name()),
      replace_string(body->query_long(), "$N", capitalize(user->query_name())) + " " + idleMsg,
      0,
      user->query("email"),
      body->query("last_login") ? ctime(body->query("last_login")) : 0,
      idleTime,
      query_ip_number(body),
      rank,
      "Plan:\n" + plan
    }) );
}

void rec_finger_reply(mixed *packet)
{
    object o_user;
    mixed *finger_data;
    string idle, mesg;
    int idleTime;

    if(!packet[D_USER] || !(o_user = find_player(packet[D_USER])))
    {
        send_error(packet, "unk-user", "Returned finger-reply to unknown user '" + packet[D_USER] + "@" + packet[D_MUD] + "'");
        return;
    }

    /* Get the rest of the finger data */
    finger_data = packet[D_USER + 1..<1];

    /* Make sure it is the correct size by padding */
    if(sizeof(finger_data) < 9) finger_data += allocate(9 - sizeof(finger_data));

    if(finger_data[1] == "") finger_data[1] = 0;
    if(finger_data[2] == "") finger_data[2] = 0;
    if(finger_data[3] == "") finger_data[3] = 0;
    if(finger_data[4] == "") finger_data[4] = 0;
    //finger_data[5] is an int.
    if(finger_data[6] == "") finger_data[6] = 0;
    if(finger_data[7] == "") finger_data[7] = 0;
    if(finger_data[8] == "") finger_data[8] = 0;

    mesg = "%^GREEN%^" + packet[O_MUD] + "%^RESET%^";

    mesg += sprintf("\nName: %-25sRank: %s\n",
      "%^BOLD%^" + finger_data[0] ? capitalize(finger_data[0]) : "<unknown>" + "%^RESET%^",
      finger_data[7] ? finger_data[7] : "<unknown>");

    if(finger_data[2])
        mesg += sprintf("%' '31sIn real life: %s\n", "", finger_data[2]);

    if(finger_data[3])
        mesg += sprintf("%' '31sEmail: %s\n", "", finger_data[3]);

    mesg += sprintf("\nTitle: %s\n",
      finger_data[1] ? replace_string(finger_data[1], "$N", finger_data[0] ? capitalize(finger_data[0]) : "<unknown>") : "<unknown>");

    if(finger_data[5] == -1)
    {

        if(finger_data[4] && finger_data[6])
            mesg += sprintf("Left at %s from %s\n", finger_data[4], finger_data[6]);
        else if(finger_data[4])
            mesg += sprintf("Left at %s\n", finger_data[4]);
        else if(finger_data[6])
            mesg += sprintf("Last login from %s\n", finger_data[6]);
        else
            mesg += "Not logged on.\n";

    } else {
        idleTime = finger_data[5];

        if(idleTime > 60)
        {
            int weeks, days, hours, mins, secs;

            weeks = idleTime / (86400 * 7);
            days = (idleTime / 86400) % 7;
            hours = (idleTime / 3600) % 24;
            mins = (idleTime / 60) % 60;
            secs = idleTime % 60;

            idle = "%^YELLOW%^Idle: ";

            if(weeks) idle += sprintf("%dw ", weeks);
            if(days || (!days && weeks)) idle += sprintf("%dd ", days);
            if(hours || (!hours && days) || (!hours && weeks)) idle += sprintf("%dh ", hours);
            if(mins || (!mins && hours) || (!mins && days) || (!mins && weeks)) idle += sprintf("%dm ", mins);
            if(secs || (!secs && mins) || (!secs && hours) || (!secs && days) || (!secs && weeks)) idle += sprintf("%ds", secs);

            idle += "%^RESET%^\n";

        } else
            idle = "";

        if(finger_data[4] && finger_data[6])
            mesg += sprintf("On since %s from %s\n%s", finger_data[4], finger_data[6], idle);
        else if(finger_data[4])
            mesg += sprintf("On since %s\n%s", finger_data[4], idle);
        else if(finger_data[6])
            mesg += sprintf("On from %s\n%s", finger_data[6], idle);

    }

    if(finger_data[8])
        mesg += "\n" + finger_data[8];

    tell_object(o_user, mesg + "\n");
}

 /* channel.c

 Tricky @ LPUniversity
 18-AUG-2006
 Intermud3 channel service

 */

varargs void setHistory(string key, string *val, int append);
varargs void send_error(mixed *packet, string err_code, string err_msg, int send_packet);
void addUserCache(string mudname, string username, string visname, int gender);

int channel_filter(string channel)
{
    /* THIS FUNCTION ALLOWS US TO DISALLOW CERTAIN CHANNELS MUD-WIDE */
    /* FOR NOW ALL CHANNELS WILL HAVE TO BE WHITELISTED */
    /* COMMENT EVERYTHING OUT AND RETURN 1 TO DISABLE */
    /* NEXT RELEASE WILL INCLUDE ADMIN-FRONTEND */

    if(member_array(channel, allow_list) == -1)
        return 0;
    else
        return 1;

}

staticf void send_channel_listen(string channel, int flag)
{
    send_packet( ({
      "channel-listen",
      5,
      mud_name(),
      0,
      data["router_list"][0][0],
      0,
      channel,
      flag
    }), 1); /* Don't log this */
}

void send_chan_who_req(mixed m_user, string mudname, string chan)
{
    string user;

    if(objectp(m_user)) user = lower_case(m_user->query_name());
    else
    if(stringp(m_user)) user = lower_case(m_user);
    else return;

    send_packet( ({
      "chan-who-req",
      5,
      mud_name(),
      user,
      mudname,
      0,
      chan
    }) );
}

void send_chan_user_req(string mudname, string username)
{
    send_packet( ({
      "chan-user-req",
      5,
      mud_name(),
      0,
      mudname,
      0,
      username
    }) );
}

void send_channel_add(object o_user, string chan, int type)
{
    tell_object(o_user, "Adding/Updating '%^BOLD%^" + chan + "%^RESET%^' to the router.\n");

    send_packet( ({
      "channel-add",
      5,
      mud_name(),
      lower_case(o_user->query_name()),
      data["router_list"][0][0],
      0,
      chan,
      type
    }) );
}

void send_channel_remove(object o_user, string chan)
{
    tell_object(o_user, "Removing '%^BOLD%^" + chan + "%^RESET%^' from the router.\n");

    send_packet( ({
      "channel-remove",
      5,
      mud_name(),
      lower_case(o_user->query_name()),
      data["router_list"][0][0],
      0,
      chan
    }) );
}

void send_channel_admin(object o_user, string chan, string *add, string *remove)
{

    if(!add) add = ({ });
    else
    if(sizeof(add))
    {
        tell_object(o_user, "Adding these muds to the allowed/banned list for '%^BOLD%^" + chan + "%^RESET%^'\n");
        tell_object(o_user, sprintf("  %-=70s\n", implode(add, ", ")));
    }

    if(!remove) remove = ({ });
    else
    if(sizeof(remove))
    {
        tell_object(o_user, "Removing these muds from the allowed/banned list for '%^BOLD%^" + chan + "%^RESET%^'\n");
        tell_object(o_user, sprintf("  %-=70s\n", implode(remove, ", ")));
    }

    send_packet( ({
      "channel-admin",
      5,
      mud_name(),
      lower_case(o_user->query_name()),
      data["router_list"][0][0],
      0,
      chan,
      add,
      remove
    }) );
}

void rec_chanlist_reply(mixed *packet)
{
    string *localList, indexStr;
    int i, index;

    if(packet[O_MUD] != data["router_list"][0][0]) return;

    localList = CHAN_D->getChls("I3");

    for(i = 0; i < sizeof(localList); i++)
    {

        if(member_array(localList[i], keys(packet[7])) == -1) CHAN_D->removeCh(localList[i]);

        remHistory(localList[i]);
    }

    data["chanlist_id"] = packet[6];

    if(!chanIndex)
        if(file_exists(CHANINDEX_FILE + ".o"))
            chanIndex = restore_variable(read_file(CHANINDEX_FILE + ".o"));

    foreach(mixed key, mixed val in packet[7])
    {

        if(!val && sizeof(keys(data["chanlist"])) && sizeof(data["chanlist"][key]))
        {
            I3LOG("Notice [I3]: Deleting channel '" + key + "' from the chanlist.\n");
            map_delete(data["chanlist"], key);
        }
        else
        if(val)
        {

            if(sizeof(keys(data["chanlist"])))
            {

                if(sizeof(data["chanlist"][key]))
                    I3LOG("Notice [I3]: Updating data for channel '" + key + "' in the chanlist.\n");
                else
                    I3LOG("Notice [I3]: Adding channel '" + key + "' to the chanlist.\n");

                data["chanlist"] += ([ key: val ]);
            }
            else
            {
                I3LOG("Notice [I3]: Adding channel '" + key + "' to the chanlist.\n");
                data["chanlist"] = ([ key: val ]);
            }

        }

        if(!channel_filter(key)) continue;

        I3LOG("Notice [I3]: Registering channel '" + key + "' with module I3.\n");

        CHAN_D->registerCh("I3", key);

        if(!chanIndex) chanIndex = ([ key: 0 ]);

        if(member_array(key, keys(chanIndex)) == -1) chanIndex[key] = 0;

        index = chanIndex[key];

        if(index > 0)
        {
            indexStr = sprintf("%08i", index - 1);

            if(file_exists(HISTORY_DIR + "/" + key + "-" + indexStr))
            {
                string *arr_lines = ({ }), lines = read_file(HISTORY_DIR + "/" + key + "-" + indexStr);

                foreach(string line in explode(lines, "\n")) arr_lines += ({ line + "\n" });

                setHistory(key, arr_lines, 0);
            }
            else
                setHistory(key, ({ }), 0);

        }

        indexStr = sprintf("%08i", index);

        if(file_exists(HISTORY_DIR + "/" + key + "-" + indexStr))
        {
            string *arr_lines = ({ }), lines = read_file(HISTORY_DIR + "/" + key + "-" + indexStr);

            foreach(string line in explode(lines, "\n")) arr_lines += ({ line + "\n" });

            setHistory(key, arr_lines, 1);
        }
        else
            setHistory(key, ({ }), 1);

    }

    save_object(I3_DATA_FILE);
}

void rec_channel_m(mixed *packet)
{
    string chan_msg;

    if(packet[O_MUD] == mud_name()) return;

    chan_msg = sprintf("[%s] %s@%s: %s\n", "%^BOLD%^%^" + channelColour(packet[6]) + "%^" + packet[6] + "%^RESET%^", packet[7], packet[O_MUD], packet[8]);
    CHAN_D->rec_msg(packet[6], chan_msg);
    addHistory(packet[6], ({ chan_msg }) );
}

void rec_channel_e(mixed *packet)
{
    string message, chan_msg;

    if(packet[O_MUD] == mud_name()) return;

    message = packet[8];
    message = replace_string(message, "$N", sprintf("%s@%s", packet[7], packet[O_MUD]));
    chan_msg = sprintf("[%s] %s\n", "%^BOLD%^%^" + channelColour(packet[6]) + "%^" + packet[6] + "%^RESET%^", message);
    CHAN_D->rec_msg(packet[6], chan_msg);
    addHistory(packet[6], ({ chan_msg }) );
}

void rec_channel_t(mixed *packet)
{
    string message, chan_msg;

    if(packet[O_MUD] == mud_name()) return;

    if(find_player(packet[8]) && packet[7] == mud_name() )
    {
        message = packet[10];
        message = replace_string(message, "$N", sprintf("%s@%s", packet[11], packet[O_MUD]));
        message = replace_string(message, "$O", packet[12]);
    }
    else
    {
        message = packet[9];
        message = replace_string(message, "$N", sprintf("%s@%s", packet[11], packet[O_MUD]));
        message = replace_string(message, "$O", packet[12] + "@" + packet[7]);
    }

    chan_msg = sprintf("[%s] %s\n", "%^BOLD%^%^" + channelColour(packet[6]) + "%^" + packet[6] + "%^RESET%^", message);
    CHAN_D->rec_msg(packet[6], chan_msg);
    addHistory(packet[6], ({ chan_msg }) );
}

void rec_chan_who_req(mixed *packet)
{
    string *listeners = ({ }), *tmp = CHAN_D->getTuned(packet[6]);

    if(!sizeof(tmp))
    {
        send_error(packet, "unk-channel", "Never heard of '%^BOLD%^" + packet[6] + "%^RESET%^'", 1);
        return;
    }

    foreach(string user in tmp) listeners += ({ capitalize(user) });

    send_packet( ({
      "chan-who-reply",
      5,
      mud_name(),
      0,
      packet[O_MUD],
      packet[O_USER],
      packet[6],
      listeners
    }) );
}

void rec_chan_who_reply(mixed *packet)
{
    object user;

#ifdef CHECK_NEW_LPUNI_MUD
    if(packet[D_USER] == "admin")
    {

        if(!checkNewLPUniMuds) checkNewLPUniMuds = ([ packet[O_MUD]: ({ packet[7], 0}) ]);
        else checkNewLPUniMuds += ([ packet[O_MUD]: ({ packet[7], 0 }) ]);

        return;
    }
#endif

    if(!(user = find_player(packet[D_USER])))
    {
        send_error(packet, "unk-user", packet[D_USER] + "@" + packet[D_MUD] + " was not found!", 1);
        return;
    }

    if(!sizeof(packet[7]))
    {
        tell_object(user, sprintf("'%s' has never heard of '%s'\n",
          "%^BOLD%^" + packet[O_MUD] + "%^RESET%^",
          "%^BOLD%^" + packet[6] + "%^RESET%^"
        ) );
        return;
    }

    tell_object(user, sprintf("The following user%s at '%s', %s tuned into '%s':\n",
      sizeof(packet[7]) == 1 ? "" : "s",
      "%^BOLD%^" + packet[O_MUD] + "%^RESET%^",
      sizeof(packet[7]) == 1 ? "is" : "are",
      "%^BOLD%^" + packet[6] + "%^RESET%^"
    ) );
    tell_object(user, sprintf("  %-=70s\n", implode(packet[7], ", ")) );
}

void rec_chan_user_req(mixed *packet)
{
    int gender;
    object user = find_player(packet[6]);

    if(!user)
    {
        send_error(packet, "unk-user", packet[6] + "@" + packet[D_MUD] + " was not found!", 1);
        return;
    }

    if(user->query("gender") == "male") gender = 0;
    else
    if(user->query("gender") == "female") gender = 1;
    else gender = 2;

    send_packet( ({
      "chan-user-reply",
      5,
      mud_name(),
      0,
      packet[O_MUD],
      0,
      query_privs(user),
      capitalize(user->query_name()),
      gender
    }) );
}

void rec_chan_user_reply(mixed *packet)
{
    addUserCache(packet[O_MUD], packet[6], packet[7], packet[8]);
}

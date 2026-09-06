#define INTERMUD3       "/secure/sockets/i3/intermud3"

int main(string str)
{
    string chan, it, *channels = this_player()->query_env_var("i3_channels");
    int emote;

    msg("~CBRTNote:~CDEF I3 is being migrated over to the normal chat system, so this verb will eventually be replaced.");

    if (!str) {
	msg("You wanted to say something?");
	return 1;
    }

    if (str == "/help") {
        command("help ichat");
        return 1;
    }

    if (str == "/list") {
        if (!channels) {
           msg("You are not currently listening to any I3 channels.");
           return 1;
        } else {
           string buf = "~CTITYour I3 Channels~CDEF";
           foreach (chan: channels)
              buf += "\n  ~CBRT"+chan;
           msg(buf+"~CDEF");
           return 1;
        }
    }

    if (sscanf(str,"%s %s",chan,str) != 2) {
	msg("Basic syntax = ~CCOMichat <channel> <message/command>~CDEF");
        msg("For more info, read ~CCOMhelp ichat~CDEF and ~CCOMhelp intermud~CDEF.");
	return 1;
    }

    if (str == "/off")
    {
        if (member(channels, chan) == -1) {
           msg("You weren't listening to ~CCOM"+chan+"~CDEF in the first place.");
           return 1;
        }
        channels -= ({ chan });
        this_player()->set_env_var("i3_channels",channels);
        msg("I3 channel ~CCOM"+chan+"~CDEF turned off.");
        return 1;
    }

    if (str == "/on")
    {
        if (member(channels, chan) != -1) {
           msg("You are already listening to ~CCOM"+chan+"~CDEF!");
           return 1;
        }
        channels += ({ chan });
        this_player()->set_env_var("i3_channels",channels);
        msg("I3 channel ~CCOM"+chan+"~CDEF turned on.");
        return 1;
    }

    if (sscanf(str, "/who @%s", str))
    {
        it = INTERMUD3 -> get_mud_name(str);
        if (!it) {
            msg("Unknown mud: ~CBRT" + str +"~CDEF");
            return 1;
        }
        if (!INTERMUD3 -> query_mud_info(it)[11]["channel"]) {
            msg("~CBRT"+it+"~CDEF does not support intermud channels.");
            return 1;
        }
        INTERMUD3 -> send_channel_who_request(chan, it);
        write("Request transmitted.\n");
        return 1;
    }

    if (member(channels, chan) == -1) {
       msg("You must have a channel turned on in order to use it!");
       return 1;
    }

    emote = sscanf(str, ":%s", str);

    if (emote)
        INTERMUD3 -> send_channel_emote(this_player()->query_cap_name(), chan, "$N " + str);
    else
        INTERMUD3 -> send_channel_message(this_player()->query_cap_name(), chan, str);
    return 1;
}

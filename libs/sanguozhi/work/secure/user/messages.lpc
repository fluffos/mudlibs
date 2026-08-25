/* Do not remove the headers from this file! see /USAGE for more info. */

/* %^RESET%^ gets used early in the login sequence by tell() */
private mapping translations = (["RESET" : ""]);
#ifdef CONFIGURABLE_COLOUR
private mapping colours;
#endif
int is_net_dead();
void save_me();
object query_shell_ob();

int screen_width;

void set_screen_width( int width )
{
    screen_width = width;
    this_user()->save_me();
}

int query_screen_width()
{
    return screen_width ? screen_width : 80;
}

void update_translations() {
#ifdef CONFIGURABLE_COLOUR
    /* handle new people, old save files, or save files for which this
     * option was disabled */
    if (!colours) colours = ([]);
    /* defaults; we take advantage of the fact that mapping addition
     * chooses the second when there is an overlap.
     */
    colours = ([
        "ROOM_EXIT" : "magenta",
        "TELL" : "bold",
        "NEWBIE_CHANNEL" : "yellow",
        "GOSSIP_CHANNEL" : "h_green",
        "WEATHER_CHANNEL" : "h_blue",
        "RUMOR_CHANNEL" : "orange",
        "IMUD_IMUD_SGZ_CHANNEL" : "h_white",
        "MORE" : "bold",
        ]) + colours;

    if (wizardp(this_user()))
        colours = ([
          "ANNOUNCE_CHANNEL" : "h_red",
          "WIZ_CHANNEL" : "cyan",
          "NEWS_CHANNEL" : "h_blue",
          "CONF_CHANNEL" : "cyan"
        ]) + colours;

#endif

    if (query_shell_ob()->get_variable("ansi"))
        translations = M_ANSI->query_translations()[0];
    else
        translations = M_ANSI->query_translations()[1];
#ifdef CONFIGURABLE_COLOUR
    translations = copy(translations);
    foreach (string code, string value in colours) {
        string * parts = map(explode(value, ","), (: upper_case :));
        string val = "";
        
        foreach (string item in parts) {
            if (translations[item])
                val += translations[item];
        }
        translations[code] = val;
    }
#endif
}

#ifdef CONFIGURABLE_COLOUR
void set_colour(string which, string what) {
    colours[upper_case(which)] = what;
    update_translations();
    save_me();
}

void query_colour(string which) {
    return colours[which];
}

mixed * query_colours() {
    return keys(colours);
}

void remove_colour(string which) {
    map_delete(colours, upper_case(which));
    /* just in case */
    map_delete(colours, lower_case(which));
    map_delete(colours, which);
    update_translations();
    save_me();
}
#endif

void do_receive(string msg, int msg_type) {
    if (is_net_dead()) return;
#ifdef _ALLOW_B5_
    msg = CONVERT_D->output(msg, this_object());
#else
#ifdef _ONLY_B5_
    msg = CONVERT_D->output(msg, this_object());
#endif
#endif
    if (msg_type & NO_ANSI) {
        if (msg_type & NO_WRAP)
            receive(msg);
        else
            receive(wrap(msg, query_screen_width()));
    } else {
        int indent = (msg_type & MSG_INDENT) ? 4 : 0;
        int wrap = (msg_type & NO_WRAP) ? 0 : query_screen_width();

        receive(terminal_colour(msg + "%^RESET%^", 
            translations, wrap, indent));
    }
}

void receive_inside_msg(string msg, object * exclude, int message_type,
  mixed other)
{
    do_receive(msg, message_type);
}

void receive_outside_msg(string msg, object * exclude, int message_type,
  mixed other)
{
    do_receive(msg, message_type);
}

void receive_remote_msg(string msg, object * exclude, int message_type,
  mixed other)
{
    do_receive(msg, message_type);
}

void receive_private_msg(string msg, int message_type, mixed other)
{
    do_receive(msg, message_type);
}


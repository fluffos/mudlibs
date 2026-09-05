/// @file messages.c
/// @brief message system
///
/// borrowed from lima
/// @author ???
/// @version 0.0.0
/// @date 2016-01-29
/// @History
/// 16-Jan-29 Gwenhwyvar:  heavyly modified for Sagenwelt

#include <player/shell.h>

/* %^RESET%^ gets used early in the login sequence by message */
private nosave mapping translations    = (["RESET" : ""]);
private nosave string  receive_classes;
private        mapping colours;

void   save_me(void);
mixed  get_env(string);

public nomask void update_translations(void)
{
    string term = get_env("TERM");

    if(!colours)
        colours = ([]);

    // defaults; we take advantage of the fact that mapping addition chooses
    // the second when there is an overlap.
    colours      = (mapping)TERM_D->defaults() + colours;
    translations = copy((mapping)TERM_D->query_translations(term));

    foreach(string code, string value in colours)
    {
        string array parts = map(explode(value, ","), (: upper_case :));
        string val = "";

        foreach(string item in parts)
        {
            if(translations[item])
                val += translations[item];
        }
        translations[code] = val;
    }
}

public nomask void set_colour(string which, string what)
{
    colours[upper_case(which)] = what;
    update_translations();
    save_me();
}

public nomask void query_colour(string which)
{
    return colours[which];
}

public nomask string *query_colours(void)
{
    return keys(colours);
}

public nomask void remove_colour(string which)
{
    map_delete(colours, upper_case(which));

    // just in case
    map_delete(colours, lower_case(which));
    map_delete(colours, which);
    update_translations();
    save_me();
}

// add_receive_class
// --------------------------------------------------------------------------
/// @brief add_receive_class
///
/// adds given class to those we might receive
/// @Param msg_class
/// @Returns
// --------------------------------------------------------------------------
public nomask void add_receive_class(int msg_class)
{
    msg_class &= MSGCLASS_MASK;
    if(!receive_classes)
        receive_classes = set_bit("", MSGCLASS_SYSTEM);
    receive_classes = set_bit(receive_classes, msg_class);
}

// --------------------------------------------------------------------------
/// @brief remove_receive_class
///
/// removes given class from those we might receive
/// @Attention MSGCLASS_SYSTEM can't be removed!!!
/// @Param msg_class
/// @Returns
// --------------------------------------------------------------------------
public nomask void remove_receive_class(int msg_class)
{
    msg_class &= MSGCLASS_MASK;
    if(!receive_classes)
        receive_classes = set_bit("", MSGCLASS_SYSTEM);
    if(msg_class != MSGCLASS_SYSTEM)
        receive_classes = clear_bit(receive_classes, msg_class);
}

// --------------------------------------------------------------------------
/// @brief receive_message
///
/// The message() efun calls this method in the player object.  The msg_class
/// parameter is typically used to indicate the class (say, tell, emote,
/// combat, room description, etc) of the message.  The receive_message()
/// apply together with the message() efun can provide a good mechanism for
/// interfacing with a "smart" client.
/// @Param msg_class
/// @Param message
/// @Returns
// --------------------------------------------------------------------------
private nomask void receive_message(string msg_class, string message)
{
    int indent = (msg_class & MSG_INDENT) ? get_env("INDENT") : 0;
    int wrap   = (msg_class & MSG_WRAP)   ? get_env("WIDTH")  : 0;

    msg_class &= ~(MSG_INDENT|MSG_WRAP);

    if(!receive_classes)
        receive_classes = set_bit("", MSGCLASS_SYSTEM);

    if(test_bit(receive_classes, msg_class))
        receive(terminal_colour(msg + "%^RESET%^", translations, wrap, indent));
}

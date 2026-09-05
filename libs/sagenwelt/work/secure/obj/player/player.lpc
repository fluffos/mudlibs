/// @file connection.c
/// @brief secondary connection object / player object
/// @author Gwenhwyvar
/// @version 0.0.0
/// @date 2016-02-01

#include <pragmas.h>
#include <connection.h>
#include <player/inp_sys.h>
#include <player/messages.h>
#include <player/shell_sys.h>
#include <menus.h>

inherit P_INPUT;
inherit P_MESSAGE;
inherit P_SHELL;

private mapping _env;

// mud lib api
// --------------------------------------------------------------------------
/// @brief get_env
/// like C-library function
/// @Param var
/// @Returns
// --------------------------------------------------------------------------
public mixed get_env(string var)
{
    return _env[var];
}

// --------------------------------------------------------------------------
/// @brief set_env
/// like C-library function
/// @Param var
/// @Returns
// --------------------------------------------------------------------------
public mixed set_env(string var, mixed val)
{
     _env[var] = val;
}

public void save_me(void)
{
}

public int initialize(mapping player_info, mapping env)
{
    object po = PO();

    // only a login object is allowed to call us!
    if(!po || (origin() != ORIGIN_CALL_OTHER) || (member_array(po, children(LOGIN_OB)) == -1))
        error("illegal call to connection::initialize");

    // first setup our environment with what we got from upstream
    _env = env;

    // then check if we're a new player
    if(!sizeof(player_info[MI_PI_PWD]))
    {
        write("\nNow that you're in the game we need to setup a new character " +
              "for you, but first you need a password to secure your character...\n" +
              "");
    }
}

// helper functions
public void change_password(int state, mixed extra, string input)
{
    switch(state)
    {
        case CP_START:
            write("When choosing a password you should follow following rules:\n" +
                  "It should be nothing you use elsewhere...\nNothing you " +
                  "might find in some dictionary...\nA mix of letters, " +
                  "numbers and punctuation signs...\nAnd at least " +
                  itoa(MIN_LEN_PASSWD) + " symbols long...\n\n");
            modal_func((: change_password, NEW_PASSWD, extra :), NPWD_PROMPT, TRUE);
    }
}

// --------------------------------------------------------------------------
/// @brief login_handler
///
/// this function asks for all parameters needed for a player to login...
/// be it just name/email & password for an existing player, be it all things
/// necessary to setup a new player...
/// @Param state
/// @Param extra
/// @Param input
/// @Returns
// --------------------------------------------------------------------------
private void login_handler(int state, mixed extra, string input)
{
    switch(state)
    {
        case CONFRM_NEW:
            {
                // make sure arg contains only lower case characters and neither begins
                // nor ends with whitespace
                if(!input)
                    input = "";
                else
                    input = lower_case(trim(input));
                switch(input)
                {
                    // well...
                    case "q": case "quit":
                        write("See you later...\n");
                        destruct();
                        return;
                    // apparently not correct, try again
                    case "":
                    case "n": case "no":
                        write("Please try again with the correct name...\n");
                        modal_func((: login_handler, GET_NAME, 0 :), LOGIN_PROMPT);
                        return;
                    // yep, we have a new player...
                    // first we need a password...
                    case "y": case "yes":
                        write("Welcome " + capitalize(extra[MI_PI_NAME]) + "\n" +
                              "Just some questions and you may start to play...\n" +
                              "Most important: you need a password!\n" +
                              "It should be nothing you use elsewhere...\n" +
                              "Nothing you might find in some dictionary...\n" +
                              "A mix of letters, numbers and punctuation signs...\n" +
                              "And at least " + itoa(MIN_LEN_PASSWD) + " symbols long...\n\n");
                        modal_func((: login_handler, NEW_PASSWD, extra :), NPWD_PROMPT, TRUE);
                        return;
                }
            }
            break;
        case NEW_PASSWD:
            {
                // a little short the password...
                if(strlen(input) <= MIN_LEN_PASSWD)
                {
                    write("\nSorry, your password is too short...\n");
                    return;
                }
                // without any letter? not good...
                else if(!sizeof(regexp(({input}), "[a-zA-Z]")))
                {
                    write("\nPlease use at least one letter (a-zA-Z)...\n");
                    return;
                }
                // neither without any number...
                else if(!sizeof(regexp(({input}), "[0-9]")))
                {
                    write("\nPlease use at least one number (0-9)...\n");
                    return;
                }
                // possible other checks too?
                // think of passwords like 'password' or 'secret'!!!
                // even with a number and some punctuation added they are much
                // too simple...

                // ok, all checks passt
                extra[MI_PI_PWD] = input;
                // now we need to male sjre there aren't any typos in that
                // password
                modal_func((: login_handler, CONFIRM_PASSWD, extra :), CNPWD_PROMPT, TRUE);
                return
            }
            break;
        case CONFIRM_PASSWD:
            {
                // apparently there was a typo...
                if(extra[MI_PI_PWD] != input)
                {
                    write("\nMismatch...\nPlease try again...\n");
                    modal_func((: login_handler, NEW_PASSWD, extra :), NPWD_PROMPT, TRUE);
                    return;
                }
                // hopefully not two times the same typo ;)
                extra[MI_PI_PWD] = crypt(input);
                write("\nNext it would be a good idea to give an email address...\n" +
                      "Having a registered address helps should you forget your password ;)\n" +
                      "We'll send an email to the given address asking for confirmation " +
                      "to finish the registration of that address...\nIf you " +
                      "don't want to register an address just press return...\n\n");
                modal_func((: login_handler, EMAIL, extra :), EMAIL_PROMPT);
                return;
            }
            break;
        case EMAIL:
            {
                string ret;

                // make sure arg contains only lower case characters and neither begins
                // nor ends with whitespace
                if(!input)
                    input = "";
                else
                    input = lower_case(trim(input));

                if(input != "")
                {
                    // try to get a character name associated with the address
                    // even if we can't get one, we know if the address is a valid
                    // one...
                    ret = (string)MUD_INFO_D->get_name_email(arg);

                    // that apparently wasn't a valid email address
                    if(ret == MI_EMAIL_INVALID)
                    {
                        write("That was apparently no valid email address...\n" +
                              "Should that assumption be wrong please inform " +
                              __ADMIN_MAIL + "\n" +
                              "Regardless you may try again once your in the game " +
                              "using the 'set email' commamd...\n");
                    }
                    else
                    {
                        extra[MI_PI_EMAIL] = input;
                        write("Good!\nPlease don't forget to reply to the email " +
                              "we send to you...\n");
                    }
                }
                else
                    write("Ok!\nBut should you change your mind you might " +
                          "set an address using the 'set email' commamd " +
                          "within the game...\n");
                write("That's all we need to know about yourself.\n" +
                      "Next comes the character generation...\n");
                setup_connection(extra);
                return;
            }
            break;
    }
}

// interactive applies
// --------------------------------------------------------------------------
/// @brief catch_tell
///
/// If INTERACTIVE_CATCH_TELL is defined in options.h, whenever the driver has
/// something to tell an object due to say(), shout(), tell_object(), etc.
/// catch_tell in the player object will be called with the message to be
/// printed.  The message can be displayed, discarded, or modified in any way
/// desired.  This is a useful way to have flexible earmuffs, or to support
/// intelligent clients.
/// @Param msg
/// @Returns
// --------------------------------------------------------------------------
private void catch_tell(string msg)
{
    receive(message);
}

// --------------------------------------------------------------------------
/// @brief logon
///
/// This apply is called on the object returned by the connect() master apply.
/// It should set up the new user.
/// @Returns
// --------------------------------------------------------------------------
private object logon(void)
{
    login_handler(START, 0);
}

// --------------------------------------------------------------------------
/// @brief net_dead
///
/// If an interactive object (i.e. the player object) suddenly loses its
/// connection (i.e. it goes "net dead"), then the driver calls this function
/// on that object giving it a chance to clean up, notify its environment etc.
/// Be aware that functions that depend on the object being interactive will
/// not work as expected.
/// @Returns
// --------------------------------------------------------------------------
private void net_dead(void)
{
    // we don't have anything to loose
    destruct();
}

// --------------------------------------------------------------------------
/// @brief telnet_suboption
///
/// This apply is called on the interactive object with the parameter given by
/// the SE telnet suboption, for mudlib defined processing.  For example, this
/// allows for future support of terminal types.
///
/// The first byte of the buffer is typically a type descriptor, ie
/// TELOPT_TTYPE. The next byte is a procession option, such as TELQUAL_IS.
/// Following this is the type dependent data.  In the case of a terminal type
/// call, the data will be routed through the terminal_type() apply instead.
///
/// Possible suboptions:
///
/// #define TELQUAL_IS    0 // option is...
/// #define TELQUAL_SEND  1 // send options
/// #define TELQUAL_INFO  2 // ENVIRON: informational version of IS
/// #define TELQUAL_REPLY 3 // AUTHENTICATION: client version of IS
/// #define TELQUAL_NAME  4 // AUTHENTICATION: client version of IS
/// @Param buffer
/// @Returns
// --------------------------------------------------------------------------
private void telnet_suboption(string buffer)
{
}

// --------------------------------------------------------------------------
/// @brief terminal_type
///
/// This apply is called on the interactive object with term set to the
/// terminal type for the user, as reported by telnet negotiation.  If the
/// user's client never responds (it's not telnet, for example) this will
/// never be called.
/// @Param term
/// @Returns
// --------------------------------------------------------------------------
private void terminal_type(string term)
{
    // if we get some terminal type we may use it...
    set_env("TERM", term);
}

// --------------------------------------------------------------------------
/// @brief window_size
///
/// This apply is called on the interactive object with term set to the
/// terminal type for the user, as reported by telnet negotiation.  If the
/// user's client never responds (it's not telnet, for example) this will
/// never be called.
/// @Param term
/// @Returns
// --------------------------------------------------------------------------
private void window_size(int width, int height)
{
    set_env("WIDTH", width);
    set_env("HEIGHT", height);
}

// --------------------------------------------------------------------------
/// @brief receive_environ
///
/// This apply is called on the interactive object with arg set to the
/// contents of the users environment, packaged into a single string with
/// key-value devided by ascii 0x01 and each key-value prepended with ascii
/// 0x1e
/// @Param env
/// @Returns
// --------------------------------------------------------------------------
private void receive_environ(string env)
{
    mapping user_env = ([]);

    // each key-value pair starts with ascii 0x1e
    foreach(string var in (explode(env, "") - ({ "" })))
    {
        // each key-value pair is devided by ascii 0x01
        string *t = explode(var, "");
        int     st = sizeof(t);

        switch(st)
        {
            // shouldn't happen, but who knows ;)
            case 0:     break;
            // var is set, but without any value
            case 1:     user_env[t[0]] = 0; break;
            // this is the standard case
            case 2:     user_env[t[0]] = t[1]; break;
            // someone managed to get an ascii 0x01 into key and/or value, let's
            // hope it's just the value...
            default:    user_env[t[0]] = implode(t[1..], ""); break;
        }
    }
    set_env("USER_ENV", user_env);
}

// std applies
private void create(void)
{
    // we need to read files and later to change our id for export_uid
    init_eids();
    // some sane defaults for our enviroment
    env = ([
            "TERM"  : "",
            "WIDTH" : DFLT_SCR_WIDTH,
            "INDENT": DFLT_SCR_INDENT
            ]);
    // we may receive logon messages
    add_receive_class(MSGCLASS_LOGON);
}

// event handler
public void event_destruct(void)
{
    if(origin() != ORIGIN_EFUN)
        return;
    // remove the timeout
    remove_call_out();
    write("\nSorry, but someone is playing around with the login process...\nPlease try again in a few minutes...\n");
    destruct();
}

public void event_shutdown(void)
{
    if(origin() != ORIGIN_EFUN)
        return;
    // remove the timeout
    remove_call_out();
    write("\nSorry, we're shutting down...\nPlease try again in a few minutes...\n");
    destruct();
}

/// @file login.c
/// @brief primary connection object
/// @author Gwenhwyvar
/// @version 0.0.0
/// @date 2016-01-27

#include <pragmas.h>
#include <messave.h>

// interactive applies {{{
// catch_tell {{{
// --------------------------------------------------------------------------
/// @brief catch_tell
///
/// If INTERACTIVE_CATCH_TELL is defined in options.h, whenever the driver has
/// something to tell an object due to say(), shout(), tell_object(), etc.
/// catch_tell in the player object will be called with the message to be
/// printed.  The message can be displayed, discarded, or modified in any way
/// desired.  This is a useful way to have flexible earmuffs, or to support
/// intelligent clients.
/// @Param msg
/// @Returns
// --------------------------------------------------------------------------
private void catch_tell(string msg)
{
    receive(message);
}
// }}}
// net_dead {{{
// --------------------------------------------------------------------------
/// @brief net_dead
///
/// If an interactive object (i.e. the player object) suddenly loses its
/// connection (i.e. it goes "net dead"), then the driver calls this function
/// on that object giving it a chance to clean up, notify its environment etc.
/// Be aware that functions that depend on the object being interactive will
/// not work as expected.
/// @Returns
// --------------------------------------------------------------------------
private void net_dead(void)
{
    // we don't have anything to loose (yet)
    destruct();
}
// }}}
// receive_snoop {{{
// --------------------------------------------------------------------------
/// @brief receive_snoop
///
/// If RECEIVE_SNOOP is defined in options.h, whenever a user is snooping
/// another user, all snoop text is sent to receive_snoop() in his user
/// object.  Inside of this function, you can do as you wish with the text.
/// A common activity would be to receive() it.
/// @Param message
/// @Returns
// --------------------------------------------------------------------------
private void receive_snoop(string message)
{
}
// }}}
// terminal_type {{{
// --------------------------------------------------------------------------
/// @brief terminal_type
///
/// This apply is called on the interactive object with term set to the
/// terminal type for the user, as reported by telnet negotiation.  If the
/// user's client never responds (it's not telnet, for example) this will
/// never be called.
/// @Param term
/// @Returns
// --------------------------------------------------------------------------
private void terminal_type(string term)
{
}
// }}}
// write_prompt {{{
// --------------------------------------------------------------------------
/// @brief write_prompt
///
/// If write_prompt is present in the player object, the driver will call it
/// whenever the default prompt would normally be printed.  The driver will
/// not call write_prompt when the player is in input_to or ed.
/// @Returns
// --------------------------------------------------------------------------
private void write_prompt(void)
{
}
// }}}
// }}}

// event handler {{{
// destruct {{{
public void event_destruct(void)
{
    if(origin() != ORIGIN_EFUN)
        return;
}
// }}}
// shutdown {{{
public void event_shutdown(void)
{
    if(origin() != ORIGIN_EFUN)
        return;
}
// }}}
// }}}

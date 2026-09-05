/// @file login.c
/// @brief primary connection object
/// @author Gwenhwyvar
/// @version 0.2.0
/// @date 2016-01-27

#include <pragmas.h>
#include <player/login.h>

inherit P_INPUT;
inherit P_MESSAGE;
inherit P_SHELL;

private mapping env;
private object  np_menu;

// states for login_handler
#define TIMEOUT     0
#define START       1
#define GET_NAME    2
#define GET_PASSWD  3
#define CONFIRM_NEW 4

// mud lib api
// --------------------------------------------------------------------------
/// @brief get_env
/// like C-library function
/// @Param var
/// @Returns
// --------------------------------------------------------------------------
public mixed get_env(string var)
{
    return env[var];
}

// --------------------------------------------------------------------------
/// @brief set_env
/// like C-library function
/// @Param var
/// @Returns
// --------------------------------------------------------------------------
public mixed set_env(string var, mixed val)
{
     env[var] = val;
}

// save? during login??
public void save_me(void) {}

public void quit(void)
{
    object po = PO();

    // master (master::crash) or new ppayer menu can force us to log out
    if((po == master()) || (po == np_menu))
        destruct();
}

// helper functions
private void setup_player(mapping info)
{
    object  player = new(PLAYER_OB);

    // we don't need a timeout any more...
    // either we're in the game in a moment or we've got some problems and are
    // out of it...
    remove_call_out();

    // init uid:gid for the new connection
    if(info[MI_PI_CRED] != "")      // existing player
        efun::seteuid(info[MI_PI_CRED]);
    else                            // new player
        efun::seteuid(info[MI_PI_NAME] + ":" __PLAYER_DOMAIN__);
    export_uid(player);

    // initialize the final connection
    if((int)player->initialize(info, env))
    {
        // setup finished, switch connection
        if(exec(player, TO()))
        {
            // but don't forget to inform the parser ;)
            master()->parse_info_refresh();
            destruct();
            return;
        }
    }
    write("Sorry!\nThere was a problem setting up your connection...\n" +
            "Please try again later or, if the problem persits, inform " +
            __ADMIN_EMAIL + "\n");
    destruct();
}

private int check_special_commamds(string cmd)
{
    mapping p_info;

    switch(cmd)
    {
        case MSSP_USER:
            // stop timeout...
            remove_call_out();
            // give requested information
            write((string)MUD_INFO_D->mssp_login());
            // restart timeout
            call_out((: login_handler, TIMEOUT :), LOGIN_TIMEOUT);
            // continue with login process
            return 0;
        case "g":
        case "guest":
            // get next free guest id and setup the connection
            p_info = (mapping)MUD_INFO_D->get_player_info("guest");
            setup_player(p_info);
            return 0;
        case "n":
        case "new":
            // new player? we need a little more time
            remove_call_out();

            // start the new player menu
            np_menu = new(NP_MENU);
            efun::move_object(np_menu, TO());       // makes the menu easier to code ;)
            np_menu->start_menu(player_info, (: setup_player :));
            return 0;
        case "":
        case "q":
        case "quit":
        case "bye":
            write("see you later...\n");
            destruct();
            return 0;
        default:
            // nothing special found...
            return 1;
    }
}

// --------------------------------------------------------------------------
/// @brief login_handler
///
/// this function asks for all parameters needed for a player to login...
/// name/email & password for an existing player and just the name for a new
/// player, additional questions and character generation are handled by the
/// connection object
/// @Param state
/// @Param extra
/// @Param input
/// @Returns
// --------------------------------------------------------------------------
private void login_handler(int state, mixed extra, string input)
{
    switch(state)
    {
        case TIMEOUT:
            {
                // we aren't interactive anymore?
                if(!interactive(TO()))
                    destruct();
                // timeout reached?
                else if(query_idle(TO()) > LOGIN_TIMEOUT)
                {
                    write("Timeout\nClosing connection...\n");
                    destruct();
                }
                // restart timeout
                else
                    call_out( (: login_handler, TIMEOUT :), LOGIN_TIMEOUT);
            }
            break;
        case START:
            {
                string buf;

                // display welcome message
                buf  = "Welcome to " __MUD_NAME__ "\n";
                buf += "This mud is using SagenweltLib " __LIB_VERSION " on " __VERSION__ "\n";
                buf += "Parts of this Mudlib are inspired by deadsouls, lima and tmi.\n\n"
                buf += "MSSP-info available via login as " MSSP_USER "\n\n";
                buf += "You may either [q]uit your connection...\n";
                buf += "Login as a [g]uest...\n";
                buf += "Create a [n]ew character...\n";
                buf += "Or login using either your character name or your registered email-address.\n\n";

                write(buf);

                // prepare input handler
                modal_push((: login_handler, GET_NAME, 0 :), LOGIN_PROMPT);
                modal_recapture();

                // start timeout
                call_out((: login_handler, TIMEOUT :), LOGIN_TIMEOUT);
            }
            break;
        case GET_NAME:
            {
                mapping p_info;

                // make sure arg contains only lower case characters and neither begins
                // nor ends with whitespace
                if(!input)
                    input = "";
                else
                    input = lower_case(trim(input));

                // got nothing? try again...
                if(input == "")
                {
                    write("You must supply either a user name or your email address...\n" +
                            "Or you can login as a [g]uest character...\nOr [q]uit...\n");
                    return;
                }
                if(!check_special_commands(input))
                    // already handled...
                    return;

                // contains an '@'? must be an email address...
                if(strsrch(arg, '@') != -1)
                {
                    // try to get the character name associated with the address
                    input = (string)MUD_INFO_D->get_name_email(arg);

                    // that apparently wasn't a valid email address
                    if(input == MI_EMAIL_INVALID)
                    {
                        write("Invalid mail address! Please try again...\n");
                        return;
                    }
                    else if(input == "")
                    {
                        write("Your mail address is not yet registered, please " +
                                "use your (desired) character name instead!\n");
                        return;
                    }
                }

                // now we got a name, check it and, if known, get it's
                // associated information
                p_info = (mapping)MUD_INFO_D->get_player_info(input);
                // do we have a character for this name?
                if(p_info[MI_PI_REG])
                {
                    // obviously not, but we can create one...
                    if(p_info[MI_PI_INVALID] = "")
                        modal_func((: login_handler, CONFIRM_NEW, p_info :),
                                "Is "+ capitalize(input) + " correct [y/N)? ");
                    // ouch... this name is for some reason invalid
                    else
                    {
                        write(p_info[MI_PI_INVALID] + "\n");
                        modal_func((: login_handler, GET_NAME, 0 :), LOGIN_PROMPT);
                        return;
                    }
                }
                // good, we know this one, now we need a password...
                modal_func((: login_handler, GET_PASSWD, p_info :), PASSWD_PROMPT, TRUE);
                return;
            }
            break;
        case GET_PASSWD:
            {
                string pwd = extra[MI_PI_PWD];

                // password ok
                if(crypt(input, pwd) == pwd)
                {
                    write("\nPassword OK...\nSetting up character...\n");
                    setup_player(extra);
                    return;
                }
                // Password not ok...
                else
                {
                    if(extra[MI_PI_PWDC]--)
                    {
                        write("\nWrong password...\nPlease try again...\n");
                        return;
                    }
                    write("\nIf you can't remember your password, please inform " +
                            __ADMIN_EMAIL + "\n");
                    destruct();
                    return;
                }
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
            // someone managed to get an ascii 0x01 into key or value, let's
            // hope it's the value...
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

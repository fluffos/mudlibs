// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/simul_efun/interactive.inc
// Description: Interactive-Simulation fuer InterMUD-Gaeste
// Author:	Gnomi (11.12.20012
//
// $Log: interactive.inc,v $
// Revision 1.2  2015/08/26 21:40:30  gnomi
// Anpassungen an LDMud 3.5.0
//
// Revision 1.1  2012-12-11 22:09:20  gnomi
// users() und query_idle() nach interactive.inc ausgelagert.
//

varargs object* caller_stack(int add_interactive)
{
    object ti = efun::this_interactive();
    object *stack = efun::caller_stack(add_interactive)[1..];

    if(!ti || load_name(ti) != PORTAL_CONNECTION)
        return stack;

    ti = previous_object(efun::caller_stack_depth()-3);
    if(ti && load_name(ti) == PORTAL_GUEST)
        return stack[0..<4];

    return stack;
}

int caller_stack_depth()
{
    object ti = efun::this_interactive();

    if(!ti || load_name(ti) != PORTAL_CONNECTION)
        return efun::caller_stack_depth() - 1;

    ti = previous_object(efun::caller_stack_depth()-3);
    if(ti && load_name(ti) == PORTAL_GUEST)
        return efun::caller_stack_depth() - 4;

    return efun::caller_stack_depth() - 1;
}

int interactive(varargs mixed* args)
{
    object ob = sizeof(args) ? args[0] : previous_object();
    if(efun::interactive(ob))
        return 1;

    if(load_name(ob) == PORTAL_GUEST && ob->is_intermud_guest())
        return 1;

    return 0;
}

int query_idle(object ob)
{
    if(!efun::interactive(ob) && ob->is_intermud_guest())
        return ({int})ob->query_intermud_idle();
#if __EFUN_DEFINED__(interactive_info)
    return efun::interactive_info(ob, II_IDLE);
#else
    return efun::query_idle(ob);
#endif
}

int query_once_interactive(object ob)
{
#if __EFUN_DEFINED__(query_once_interactive)
    if(efun::query_once_interactive(ob))
#else
    if(efun::object_info(ob, OI_ONCE_INTERACTIVE))
#endif
        return 1;

    if(load_name(ob) == PORTAL_GUEST && ob->is_intermud_guest())
        return 1;

    return 0;
}

void remove_interactive(object ob)
{
    if(load_name(ob) == PORTAL_GUEST && ob->is_intermud_guest())
        ob->quit();
    else
        efun::remove_interactive(ob);
}

mixed set_prompt(mixed prompt, varargs object* args)
{
    object ob = sizeof(args) ? args[0] : this_player();
    if(load_name(ob) == PORTAL_GUEST && ob->is_intermud_guest())
        return ob->set_intermud_prompt(prompt);
    else
#if __EFUN_DEFINED__(set_prompt)
        return efun::set_prompt(prompt, args...);
#else
    {
        mixed oldprompt = efun::interactive_info(ob, IC_PROMPT);

        if(!intp(prompt))
            efun::configure_interactive(ob, IC_PROMPT, prompt);

        return oldprompt;
    }
#endif
}

object this_interactive()
{
    object ti = efun::this_interactive();

    if(!ti || load_name(ti) != PORTAL_CONNECTION)
        return ti;


    // -1: PORTAL_CONNECTION
    // -2: PORTAL_SERVER
    // -3: PORTAL_GUEST
    ti = previous_object(efun::caller_stack_depth()-3);
    if(ti && load_name(ti) == PORTAL_GUEST)
        return ti;

    return 0;
}

object *users()
{
   return filter(efun::users(),
       (:
           string on = object_name($1);

           return strstr(on, "/obj/player#") == 0 ||
                  strstr(on, "/obj/newplayer#") == 0;
       :))
       + (({object*})PORTAL_SERVER->query_guests() || ({}));
}

#if __EFUN_DEFINED__(interactive_info)
nomask mixed interactive_info(object ob, int what)
{
    switch(what)
    {
        /* Diese sind harmlos und uninteressant... */
        case IC_MAX_WRITE_BUFFER_SIZE:
        case IC_SOCKET_BUFFER_SIZE:
        case IC_COMBINE_CHARSET_AS_STRING:
        case IC_COMBINE_CHARSET_AS_ARRAY:
        case IC_CONNECTION_CHARSET_AS_STRING:
        case IC_CONNECTION_CHARSET_AS_ARRAY:
        case IC_QUOTE_IAC:
        case IC_TELNET_ENABLED:
        case IC_MCCP:
        case IC_MAX_COMMANDS:
        case IC_MODIFY_COMMAND:
        case II_MCCP_STATS:
        /* Zwar interessant, aber noch nicht fuer
         * InterMUD-Gaeste implementiert.
         */
        case II_EDITING:
        case II_SNOOP_NEXT:
        case II_SNOOP_PREV:
        case II_SNOOP_ALL:
           /* Der Master->valid_snoop() wird gefragt, richtiges Objekt setzen: */
           efun::set_this_object(previous_object());
           return efun::interactive(ob) && efun::interactive_info(ob, what);

        /* Diese sind interessant genug,
         * um sie fuer InterMUD-Gaeste zu simulieren.
         */
        case IC_PROMPT:
            if(efun::interactive(ob))
                return efun::interactive_info(ob, what);
            else if(load_name(ob) == PORTAL_GUEST && ob->is_intermud_guest())
                return ob->set_intermud_prompt(0);
            break;

        case II_INPUT_PENDING:
            return (playerp(ob) && ob->query_pending_input_to()) ||
                (efun::interactive(ob) && efun::interactive_info(ob, II_INPUT_PENDING));
            break;

        case II_IDLE:
            if(efun::interactive(ob))
                return efun::interactive_info(ob, what);
            else if(load_name(ob) == PORTAL_GUEST && ob->is_intermud_guest())
                return ob->query_intermud_idle();
            break;

        /* Diese Information sind geheim. */
        case II_IP_NAME:
            return "leider.nicht.mehr.verfuegbar";
        case II_IP_NUMBER:
            return "0.0.0.0";
        case II_IP_PORT:
        case II_IP_ADDRESS:
        case II_MUD_PORT:
           return 0;
    }
}
#endif

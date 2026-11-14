//
// Wunderland Mudlib
//
// secure/sefun/set_prompt.c -- set_prompt fuer ldmud 3.5
//
// $Log: set_prompt.c,v $
// Revision 1.1  2021/03/25 16:07:06  Fuchur
// Update auf ldmud 3.6.3
//

/* This sefun is to provide a replacement for the efun set_prompt().
 * Feel free to add it to your mudlibs, if you have much code relying on that.
 */

#if ! __EFUN_DEFINED__(set_prompt)

#include <configuration.h>

varargs string|closure set_prompt(string|closure|int prompt, object ob)
{
    ob ||= efun::this_player();

    mixed oldprompt = efun::interactive_info(ob, IC_PROMPT);

    if(!intp(prompt))
        efun::configure_interactive(ob, IC_PROMPT, prompt);

    return oldprompt;
}

#endif

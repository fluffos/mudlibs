#if ! __EFUN_DEFINED__(strlen)
int strlen(string str)
{
    return sizeof(str);
}
#endif

/* This sefun is meant to replace the deprecated efun cat().
 * Feel free to add it to your mudlibs, if you have much code using cat() or
 * want to use cat(). 
 */
#define CAT_MAX_LINES 50
nomask void tell_object(object ob, string str);

varargs int cat(string file, int start, int num)
{
    mixed *result = funcall(function mixed*() : int ex_call = extern_call()
    {
        if (ex_call)
            set_this_object(previous_object(1));

        int more;

        if (num < 0 || !this_player())
            return 0;

        if (!start)
            start = 1;

        if (!num || num > CAT_MAX_LINES) {
            num = CAT_MAX_LINES;
            more = sizeof(read_file(file, start+num, 1));
        }

        string txt = read_file(file, start, num);
        if (!txt)
            return 0;
        
	return ({txt, more});
    });

    if (!result)
        return 0;

    tell_object(this_player(), result[0]);

    if (result[1])
        tell_object(this_player(), "***** GEKUERZT ****\n");

    return sizeof(result[0] & "\n");
}

/* This sefun is meant to replace the deprecated efun tail().
 * Feel free to add it to your mudlibs, if you have much code using tail() or
 * want to use tail().
 */

#include <files.h>

#define TAIL_MAX_BYTES 1000

varargs int tail(string file)
{
    string result = funcall(function string() : int ex_call = extern_call()
    {
        int fs;
        string txt;

        if (ex_call)
            set_this_object(previous_object(1));

        if (!stringp(file) || (fs = file_size(file)) < 1 || !this_player())
            return 0;

        if (fs < TAIL_MAX_BYTES + 80)
            txt = read_file(file); 
        else
        {
            txt = read_bytes(file, -(TAIL_MAX_BYTES + 80), (TAIL_MAX_BYTES + 80));

            if (!stringp(txt))
                return 0;

            // cut off first (incomplete) line
            int index = strstr(txt, "\n");
            if (index > -1)
            {
                if (index + 1 < sizeof(txt))
                    txt = txt[index+1..];
                else
                    txt = "";
            }
        }

        return txt;
    });

    if (!result)
        return 0;

    tell_object(this_player(), result);

    return 1;
}

#if ! __EFUN_DEFINED__(enable_commands)

void enable_commands()
{
    object ob = efun::previous_object();

    efun::configure_object(ob, OC_COMMANDS_ENABLED, 1);
    efun::set_this_player(ob);
}

#endif

#if ! __EFUN_DEFINED__(disable_commands)

void disable_commands()
{
    object ob = efun::previous_object();

    efun::configure_object(ob, OC_COMMANDS_ENABLED, 0);
    efun::set_this_player(0);
}

#endif

#if ! __EFUN_DEFINED__(query_limits)

varargs int* query_limits(int def)
{
    return efun::driver_info(def ? DC_DEFAULT_RUNTIME_LIMITS : DI_CURRENT_RUNTIME_LIMITS);
}

#endif

#if ! __EFUN_DEFINED__(query_load_average)

string query_load_average()
{
    return efun::sprintf("%.2f cmds/s, %.2f comp lines/s",
        efun::driver_info(DI_LOAD_AVERAGE_COMMANDS),
        efun::driver_info(DI_LOAD_AVERAGE_LINES));
}

#endif

#if ! __EFUN_DEFINED__(set_combine_charset)

void set_combine_charset(int *|string charset)
{
    object ob = efun::this_interactive();
    if(!efun::interactive(ob))
        return;

    if(stringp(charset))
        efun::configure_interactive(ob, IC_COMBINE_CHARSET_AS_STRING, charset);
    else
        efun::configure_interactive(ob, IC_COMBINE_CHARSET_AS_ARRAY, charset);
}

int *|string get_combine_charset(int mode)
{
    object ob = efun::this_interactive();
    if(!efun::interactive(ob))
        return 0;

    if(mode == CHARSET_STRING)
        return efun::interactive_info(ob, IC_COMBINE_CHARSET_AS_STRING);
    else if(mode == CHARSET_VECTOR)
        return efun::interactive_info(ob, IC_COMBINE_CHARSET_AS_ARRAY);
    else
        raise_error(sprintf("Bad arg 1 to get_combine_charset(): %d, "
              "expected CHARSET_VECTOR (%d) or CHARSET_STRING (%d)\n"
             , mode, CHARSET_VECTOR, CHARSET_STRING));
}

#endif

#if ! __EFUN_DEFINED__(set_heart_beat)

int set_heart_beat(int flag)
{
    object ob = previous_object();
    int hb = efun::object_info(ob, OC_HEART_BEAT);

    if (!flag == !hb)
        return 0;

    efun::configure_object(ob, OC_HEART_BEAT, flag);

    return 1;
}

#endif

#if ! __EFUN_DEFINED__(query_shadowing)

object query_shadowing(object ob)
{
    return efun::object_info(ob, OI_SHADOW_PREV);
}

object shadow(object ob, int flag)
{
    if(flag)
    {
        object shadower = efun::previous_object();
        efun::set_this_object(shadower);

        if (efun::shadow(ob))
            return efun::object_info(shadower, OI_SHADOW_PREV);
        else
            return 0;
    }
    else
        return efun::object_info(ob, OI_SHADOW_NEXT);
}

#endif

#if ! __EFUN_DEFINED__(query_editing)

int|object query_editing(object ob)
{
    if(!efun::interactive(ob))
        return 0;

    return efun::interactive_info(ob, II_EDITING);
}

#endif

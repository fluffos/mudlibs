
// wimpy cmd from player.c, now external. Morgoth 7/Mar/95
// Changed: if you type "wimpy" without a number, or with an out of range
//          number, it will now show you the actual setting, without changing
//          it, after warning you. The old version would not show it in either
//          case, and would set it to 0 in the latter case.

#include <standard.h>
#include <cmd.h>
//#include <player.h>

inherit CMD_BASE;

int wimpy;

void setup()
{
        position = 0;
}

string query_usage()
{
        return "wimpy <num>";
}

string query_short_help()
{
        return "You'll run away when your hp go below <num>%, and will lose "+
                "<num>% of the gained xp.";
}

string wimpy_str(object me)
{
        return "It is currently set to "+me->query_wimpy()+"%.";
}

protected int cmd (string str, object me)
{
        if (!str)
        {
                notify_fail("Usage: "+query_usage()+". "+wimpy_str(me)+"\n");
                return 0;
        }
        else
        {
                if (sscanf(str, "%d", wimpy) != 1)
                {
                        notify_fail("You must set wimpy to a number.\n");
                        return 0;
                }
                if (wimpy < 0 || wimpy > 100)
                {
                        notify_fail("Wimpy must be in the range 0-100. "+
                                        wimpy_str(me)+"\n");
                        return 0;
                }
        }
        if (wimpy)
                tell_object (me, "You are in wimpy mode, you will run away "+
                        "at "+wimpy+"% of your max hps.\n");
        else
                tell_object (me, "You are in brave mode.\n");
        me->set_wimpy(wimpy);
        return 1;
}



/* kill command from player.c externalized by Baldrick.
 */

#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

void setup()
{
}

string query_usage()
{
        return "interwho <mud>";
}

string query_short_help()
{
        return "Pregunta al mud especificado quien hay online.";
}

int cmd (string str, object me)
{
  int i;
  object *obs;

  if (!str || str == "")
    {
    notify_fail("Uso: interwho <mud>\n");
    return 0;
    }

  //str = lower_case(str);

"/net/intercre"->interwho(me->query_name(),str);

  return 1;
}

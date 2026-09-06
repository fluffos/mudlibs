#include <cmd.h>
#include <daemons.h>

nomask int
version_cmd(string arg)
{
    TP->tell_me((string)DESC_D->query_mud_name());
    TP->tell_me("Driver version: " + version());
    return 1;
}

#include <cmd.h>

nomask int
mud_cmd(string arg)
{
    "/bin/pub/_channel"->channel_cmd("mud send" + (arg?" "+arg:""), TP);
    return 1;
}

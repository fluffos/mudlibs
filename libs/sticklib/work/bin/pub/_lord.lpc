#include <cmd.h>

nomask int
lord_cmd(string arg)
{
    "/bin/pub/_channel"->channel_cmd("lord send" + (arg?" "+arg:""), TP);
    return 1;
}

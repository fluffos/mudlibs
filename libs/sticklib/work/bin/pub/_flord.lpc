#include <cmd.h>

nomask int
flord_cmd(string arg)
{
    "/bin/pub/_channel"->channel_cmd("flord send" + (arg?" "+arg:""), TP);
    return 1;
}

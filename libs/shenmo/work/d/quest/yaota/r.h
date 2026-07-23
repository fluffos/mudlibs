#include <ansi.h>

void init()
{
::init();
add_action("do_none","set");
}

int do_none()
{
write(HIR"\n不能在这里使用此命令!\n\n"NOR);
return 1;
}

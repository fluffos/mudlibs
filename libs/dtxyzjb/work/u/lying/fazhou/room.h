
#include <ansi.h>

void init()
{
add_action("do_none","cast");
add_action("do_none","move");
add_action("do_none","burn");

}

int do_none()
{
message_vision(HIW"\n此事还是作罢，在这儿是不行的！\n"NOR);
return 1;
}


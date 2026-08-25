#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup()
{
position = 1;
}


protected int cmd(string str, object me) {
    object ob;

    ob = new("/obj/handlers/post");
    ob->move(me);
    ob->start_mail(str);
    return 1;
}
 

// Modified by iszt@pkuxkx, 2007-03-21, added log
// Modified by iszt@pkuxkx, 2007-05-09, removed anner

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        if (!arg) {
            return 0;

        }
        if(objectp(ob=present(arg,this_player())))
        {
            write(file_name(ob));
            write("\n");
        }

        if(objectp(ob=present(arg,environment(this_player()))))
        {
            write(file_name(ob));
            write("\n");
        }
        return 1;
}



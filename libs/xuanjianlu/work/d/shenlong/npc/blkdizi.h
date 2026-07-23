

#include <ansi.h>

void init()
{

call_out("clear", 600);

}

void clear(object dizi)
{
        dizi=this_object();
        message_vision("$N急急忙忙地离开了。\n", dizi);
        destruct(dizi);


}


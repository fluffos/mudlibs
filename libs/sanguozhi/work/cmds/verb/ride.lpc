#include <mudlib.h>
#include <move.h>
#include <setbit.h>
inherit VERB_OB;

void do_qi_obj(object what)
{
    what->ride();
}

void do_ride_obj(object what)
{
  what->ride();
}

void do_xia_obj(object what)
{
    mixed s;
    string err;
    if(what != environment(this_body()))

    {
        write("你不在它上面。\n");
        return;
    }
    if(s = what->unride())
    {
        if(!stringp(err=this_body()->move(environment(what))))
        {
            if(stringp(s))
                this_body()->simple_action(s);
            else
                this_body()->simple_action("$N从" + what->short()+
                  "上下来。");
        }
        else
        {
            write(err+"\n");
        }

    }
    else
    {
        write("你已经站在地上了。\n");
    }
}
void do_unride_obj(object what)
{
  do_xia_obj(what);
}
int do_xia()
{
    "/cmds/verbs/stand"->do_stand();
}

int do_unride()
{
    "/cmds/verbs/stand"->do_stand();
}

mixed * query_verb_info()
{
      return ({ ({ "OBJ"}) });
}

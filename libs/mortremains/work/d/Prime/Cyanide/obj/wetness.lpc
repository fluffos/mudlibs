#include <mudlib.h>
inherit OBJECT;

void
create ()
{
        set ("id", ({ "wet_obj" } ));
        set ("author", "cyanide");
        set ("prevent_drop", 1);
        set ("extra_look", "$N is soaking wet and smells terrible!\n");
}

init()
{
  object ob;

  ob = environment(this_object());
  if (ob && living(ob))
    {
    dryout1();
    }
  else
            {
    this_object()->remove();
    }

}
dryout1()
{
  tell_object(environment(this_object()),"You are soaking wet and smell "+
    "nasty.\n");
  return(1);
}

dryout2()
{
  remove_call_out("dryout2");
  tell_object( environment(this_object()),"You feel a little drier.\n");
  call_out("dryout3",150);
  return(1);
}

dryout3()
{
  remove_call_out("dryout3");
  tell_object(environment(this_object()),
  "You are now totally dry, and only stink as much as you did originally.\n");
  this_object()->remove();
  return(1);
}

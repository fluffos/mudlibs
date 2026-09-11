// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** dismount.c
*/


inherit VERB_OB;


void do_dismount(object what)
{
  mixed s;
  string err;

  if(!objectp(what))
    what = environment(this_body());

  if(what != environment(this_body()))
    {
      write("你不在它上面。\n");
      return;
    }
  if(s = what->dismount())
    {
      if(!stringp(err=this_body()->move(environment(what))))
        {
          if(stringp(s))
            this_body()->simple_action(s);
          else
            this_body()->simple_action("$N从" + what->short()+
                                       "下来。");
        }
      else
        {
          write(err+"\n");
        }
    }
  else
    {
      if(!environment(environment(this_body())))
        write("你已经是站着的了。\n");
      else
        write("You're have no mount of which to speak.\n");
    }
} 

void do_dismount_obj(object o)
{
  do_dismount(o);
}

mixed * query_verb_info()
{
    return ({ ({ "", "OBJ" }) });
}



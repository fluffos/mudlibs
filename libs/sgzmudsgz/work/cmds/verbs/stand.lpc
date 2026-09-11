// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** stand.c
*/


inherit VERB_OB;

//### for now.  We need a better system to tell check_condition() what to
//### ignore.
mixed can_stand_up() {
    return default_checks();
}

mixed can_stand() {
    return default_checks();
}

void do_stand()
{
  mixed s;
  string err;

    if (this_body()->query_prone()) {
        if (this_body()->get_up())
            this_body()->simple_action("$N站了起来。");
        return;
    }
  if(s = environment(this_body())->stand())
    {
      if(!stringp(err=this_body()->move(environment(environment(this_body())))))
        {
          if(stringp(s))
            this_body()->simple_action(s);
          else
            this_body()->simple_action("$N站起来。");
        }
      else
        {
          write(err+"\n");
        }
    }
  else
    {
      if(environment(environment(this_body())))
        {
          write("你站不起来。\n");
        }
      else
        {
          write("你已经是站着的了。\n");
        }
    }
} 

void do_stand_up()
{
  do_stand();
}

mixed * query_verb_info()
{
    return ({ ({ "" }), ({"unride"}) });
}



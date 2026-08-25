// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */


inherit VERB_OB;

//### Odd.  This never uses 'ob'.
void do_exit(object ob)
{
  mixed s;
  string err;
  object last_loc;

  if(objectp(ob) && ob != environment(this_body()))
    {
      write("你不在那里面。\n");
      return;
    }
  last_loc = environment(this_body());

  if(s = environment(this_body())->exit())
    {
      if(!stringp(err=this_body()->move(environment(environment(this_body())))))
        {
          if(stringp(s))
            this_body()->simple_action(s);
          else
            this_body()->simple_action("$N离开了$o.", last_loc);
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
          write("你此刻无法离开。\n");
        }
      else
        {
          write("没有离开的方向。\n");
        }
    }
} 

void do_exit_obj(object ob)
{
  do_exit(ob);
}


mixed * query_verb_info()
{
    return ({ ({ "OBJ", "" }), ({ "leave", "disembark" }) });
}

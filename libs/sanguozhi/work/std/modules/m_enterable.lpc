// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

string short();

private nosave string on_enter_msg;
private nosave string on_exit_msg;

void set_on_enter_msg(string s)
{
  on_enter_msg = s;
}

void set_on_exit_msg(string s)
{
  on_exit_msg = s;
}

string get_on_enter_msg()
{
  return on_enter_msg;
}

string get_on_exit_msg()
{
  return on_exit_msg;
}

string handle_exit_msgs(object last_loc)
{
  return get_on_enter_msg() || //"$N $venter "+short()+".\n";
                               "$N进入了"+short()+"。\n";
}

int direct_enter_obj()
{
  return 1;
}

int do_enter()
{
  if(environment(this_body()) == this_object())
    {
      //write("You are already there.\n");
      write("你已经在那儿了。\n"); 
      return 1;
    }
  this_body()->move_to(file_name(this_object()), short());
}

int direct_get_in_obj()
{
  return 1;
}

int get_in_obj()
{
  do_enter();
}

int direct_exit_obj()
{
  return 1;
}


mixed exit()
{
  return get_on_exit_msg() || //"$N $vexit " + short() + ".\n";
                              "$N离开了"+short()+"。\n";
}


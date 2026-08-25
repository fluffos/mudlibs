/* Do not remove the headers from this file! see /USAGE for more info. */

private
nosave int interval = 1;

int is_stateful()
{
   return 1;
}

int state_update()
{
   return 1;
}

void internal_add_to_queue()
{
   STATE_D->add_to_queue(this_object());
}

//: FUNCTION set_call_interval
// int set_call_interval(int i)
// Set call interval in minutes.
int set_call_interval(int i)
{
   interval = i;
}

int query_call_interval()
{
   return interval;
}

void mudlib_setup()
{
   call_out("internal_add_to_queue", 1);
}
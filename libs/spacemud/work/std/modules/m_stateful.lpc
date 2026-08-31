/* Do not remove the headers from this file! see /USAGE for more info. */

private
nosave int interval = 1;

//: FUNCTION is_stateful
// Override this to make the object stateful depending on what happens.
// E.g. a torch might be stateful when lighted, but not when it's dark.
// The *extra* is the argument parsed to STATE_D when registered.
varargs int is_stateful(mixed extra)
{
   return 1;
}

//: FUNCTION state_update
// This function must return 1 by stateful objects to keep being called by STATE_D. If they do not, they're removed from
// the queue. If they do, they're added to the queue again by STATE_D and set to be called after query_call_interval()
// minutes has passed.
// The *extra* is the argument parsed to STATE_D when registered.
varargs int state_update(mixed extra)
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

//: FUNCTION query_call_interval
// Return the call internal in minutes.
int query_call_interval()
{
   return interval;
}

void mudlib_setup()
{
   call_out("internal_add_to_queue", 0);
}
/*  -*- LPC -*-  */
// m_clean_up.c:  Function for object self-removal
// Tim 23 Apr 96

int no_clean;   /* 1 if we don't want cleaned up */

nomask void
set_no_clean(int x)
{
  no_clean = x;
}

// if item is inherited, has environment, or contains living objects, then
// don't destruct it.

nomask int
clean_up(int inh)
{
  if( no_clean ) return 0;
  if( inh ) return 1;
  if( environment() ) return 1;
  if( sizeof(filter_array(all_inventory(this_object()), (: living :))) )
    return 1;

  destruct();
}

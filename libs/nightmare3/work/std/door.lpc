/*    /std/door.c
 *    from Nightmare 3.3
 *    an inheritable door object to go in rooms
 *    created by Rust 940923
 */

#include <std.h>

inherit OBJECT;

int __Open, __Locked;
string __KeyID;

void create() {
    Object::create();
    __Open = 0;
    __Locked = 0;
    __KeyID = "skeleton";
}

void init() {
    Object::init();
    add_action("cmd_open", "open");
    add_action("cmd_close", "close");
    add_action("cmd_lock", "lock");
    add_action("cmd_unlock", "unlock");
  add_action("open", "A_open");
  add_action("close", "A_close");
  add_action("lock", "A_lock");
  add_action("unlock", "A_unlock");

}

void set_key(string key) { __KeyID = key; }

string query_key() { return __KeyID; }

void set_locked(int state) { __Locked = state; }

int query_locked() { return __Locked; }

void set_open(int state) { __Open = state; }

int query_open() { return __Open; }

nosave
varargs
int
open( string with )
{
  if( __Open )
        write( "You open the "+query_short()+".\n" );
        say( this_player()->query_cap_name() + " opens the "+query_short()+".\n" );
        return 1;

  if( __Locked )
  {
        if( with == __KeyID )
        {
          write( "You unlock and open the "+query_short()+".\n" );
         say( this_player()->query_cap_name() + " unlocks and opens the "+query_short()
+".\n" );
        __Open = 1;
        __Locked = 0;
        return 1;
   }
    notify_fail( "The key doesn't fit the lock.\n" );
    return 0;
  }
  __Open = 1;
  return 1;
}

nosave
int
close()
{
  if( !__Open )


    return (void)notify_fail("It's already closed, ninny!\n");

  __Open = 0;
  write( "You close the "+query_short()+".\n" );
  say( this_player()->query_cap_name()+" closes the "+query_short()+".\n" );
  return 1;
}

nosave
int
lock( string with )
{
  if( __Locked )
        return (void)notify_fail("It's already closed, ninny!\n");

  if( with != __KeyID )
        return (void)notify_fail("The key doesn't fit the lock.\n");

  __Locked = 1;
  write( "You lock the "+query_short()+".\n" );
  say( this_player()->query_cap_name()+" locks the "+query_short()+".\n" );
  return 1;
}

nosave
int
unlock( string with )
{
  if( !__Locked )
        return (void)notify_fail("It's already unlocked.\n");
  if( __KeyID != with )
        return (void)notify_fail("The key doesn't fit the lock.\n");

  write("You unlock the "+query_short()+".\n");
  say( this_player()->query_cap_name()+" unlocks the "+query_short()+".\n" );

  __Locked = 0;
  return 1;
}


nosave
int
A_open( string arg )

{
  string        key;

  if( sscanf( arg, "%s with %s", arg, key) == 2 )
  {
    if( !id( arg ) )
      return 0;

    return open( key );
  }

  if( !id( arg ) )
    return 0;

  return open();
}

nosave
int
A_close( string arg )
{
  if( !id(arg) )
    return 0;

  return close();
}

nosave
int
A_lock( string arg )
{
  string        key;

  if( sscanf( arg, "%s with %s", arg, key ) != 2 )
    return 0;

  if( !id(arg) )
    return 0;

  return lock( key );
}

nosave
int
A_unlock( string arg )
{
  string        key;

  if( sscanf( arg, "%s with %s", arg, key ) != 2 )
    return 0;

  if( !id(arg) )
    return 0;

  return unlock( key );
}

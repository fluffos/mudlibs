// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// An object that can be opened, closed, locked, and unlocked.
//
// NOTE: this should only be mixed into classes that have
//       M_OPENABLE, too.
// NOTE: due to a bug in the driver(?), you must inherit M_OPENABLE
//       _after_ inheriting M_LOCKABLE.
//

#include <mudlib.h>
#include <hooks.h>

string short();
void hook_state(string, function, mixed);
mixed call_hooks(string, int);

private string locked, key_type;

string unlock_msg = //"$N $vunlock the $o with $p $o1.\n";
                    "$N用$o1打开了$o。\n";
string unlock_fail = //"$N $vtry to unlock the $o, but $p $o1 doesn't fit.\n";
                     "$N试图用$o1打开$o，但白费了半天力气。\n";
string lock_msg = //"$N $vlock the $o with $p $o1.\n";
                  "$N用$o1把$o锁上了。\n";
string lock_fail = //"$N $vtry to lock the $o, but $p $o1 doesn't fit.\n";
                   "$N试图用$o1把$o锁上，但白费了半天力气。\n";
string pick_msg = //"$N $vpick open the $o.\n";
                   "$N把$o撬开了。\n";
string pick_fail = //"$N $vtry to pick open the $o, but $vfail.\n";
                   "$N想把$o撬开，但没有成功。\n";
function my_open_hook = (: short() + //" is locked.\n"
                                                    "锁上了。\n"    
                        :);

int is_lockable() { return 1; }
string query_locked() { return locked; }

string query_key_type() { return key_type; }

varargs void set_locked(string x, string y) {
    locked = x;
    if (nullp(y)) 
        key_type = x;
    else
        key_type = y;
    hook_state("prevent_open", my_open_hook, locked);
}

#ifdef USE_SKILLS
int strength_vs_magic;
int resistance_to_picking;

void set_strength_vs_magic(int s)
{
  strength_vs_magic = s;
}

int get_strength_vs_magic()
{
  return strength_vs_magic;
}

void set_resistance_to_picking(int s)
{
  resistance_to_picking = s;
}

int get_resistance_to_picking()
{
  return resistance_to_picking;
}

#endif

mixed magic_unlock()
{
  mixed ex;
  int   i;


  if(!locked)
    return //"It's not locked.\n";
           "它没有锁上。\n";     


//:HOOK prevent_magic_unlock
//A yes/no/error hook which can prevent an object from being magically
//unlocked.  However, if your mud uses skills, use set_strength_vs_magic() 
//instead, unless you're doing something complex.


  ex = call_hooks("prevent_magic_unlock", HOOK_YES_NO_ERROR);


  if(!ex) ex = //"Your magic seems to have no effect on it.\n";
               "你的魔法对它似乎没有丝毫作用。\n"; 
  if(stringp(ex))
    {
      return ex;
    }
#ifdef USE_SKILLS
  i = SKILL_D->test_skill("spell/unlock", this_body(),
                                  get_strength_vs_magic());
  if(!i)
  {
    return 0;
  }
  
#endif
  set_locked(0, "magic");
  return 1;
}

mixed pick()
{
  mixed ex;
  int   i;


  if(!locked)
    //write("It's not locked.\n");
    write("它没有锁上。\n");     


//:HOOK prevent_picking
//A yes/no/error hook which can prevent an object from being picked
//open.  However, if your mud uses skills, use set_resistance_to_picking() 
//instead, unless you're doing something complex.


  ex = call_hooks("prevent_picking", HOOK_YES_NO_ERROR);


  if(!ex) ex = //"You can't seem to get it open.\n";
               "你无法把它弄开。\n"; 
  if(stringp(ex))
    {
      write(ex);
      return;
    }
#ifdef USE_SKILLS
  i = SKILL_D->test_skill("misc/lockpick", this_body(),
                                  get_resistance_to_picking());
  if(!i)
  {
    this_body()->simple_action(pick_fail, this_object());
    return;
  }
  
#endif
  set_locked(0, "picked");
  this_body()->simple_action(pick_msg, this_object());
}

void unlock_with(object ob)
{
//:HOOK prevent_unlock
//A yes/no/error hook which can prevent an object from being unlocked.
    mixed ex = call_hooks("prevent_unlock", HOOK_YES_NO_ERROR);
    if (!ex) ex = //"You can't seem to unlock it.\n";
                  "你无法把这锁打开。\n";
    if (stringp(ex)) {
        write(ex);
        return;
    }

    if (ob->key_type() == key_type)
    {
        this_body()->simple_action(unlock_msg, this_object(), ob);
        set_locked(0, key_type);
        hook_state("prevent_open", my_open_hook, locked);
    }
    else
    {
        this_body()->simple_action(unlock_fail, this_object(), ob);
    }
}

void unlock() {
    object ob = present("key", this_body());
    //write("(with " + ob->short() + ")\n");
    write("(用"+ob->short() + ")\n");
    unlock_with(ob);
}


void lock_with(object ob) {
//:HOOK prevent_lock
//A yes/no/error hook which can prevent an object from being locked.
    mixed ex = call_hooks("prevent_lock", HOOK_YES_NO_ERROR);
    if (!ex) ex = //"You can't seem to lock it.\n";
                  "你无法把它锁上。\n";
    if (stringp(ex)) {
        write(ex);
        return;
    }
    
    if (ob->key_type() == key_type) {
        this_body()->simple_action(lock_msg, this_object(), ob);
        set_locked(key_type);
    }
//:FIXME if the lock type is picked or magic, it should probably
// open.
    else {
        this_body()->simple_action(lock_fail, this_object(), ob);
    }
}

void lock() {
    object ob = present("key", this_body());
    //write("(with " + ob->short() + ")\n");
    write("(用"+ ob->short() + ")\n");
    lock_with(ob);
}

/*********************************************************/
/*    verb interactions                                   */
/**********************************************************/

mixed direct_pick_obj(object ob)
{
    if (!locked)
        return //"It isn't locked.\n";
               "它没有锁上。\n";
    return 1;
}

mixed direct_unlock_obj(object ob) {
    if (!locked)
        return //"It isn't locked.\n";
               "它没有锁上。\n"; 
    if (present("key", this_body()))
        return 1;
    return //"With what?\n";
           "用什么？\n";     
}

mixed direct_lock_obj(object ob) {
    if (locked)
        return //"It is already locked.\n";
               "它已经被锁上了。\n";
    if (present("key", this_body()))
        return 1;
    return //"With what?";
           "用什么？\n";    
}

mixed direct_unlock_obj_with_obj(object ob1, object ob2) {
    return 1;
}

mixed direct_pick_obj_with_obj() {
  return 1;
}

mixed direct_lock_obj_with_obj() {
    return 1;
}

int can_pick_obj()
{
  return 1;
}

int can_pick_obj_with_obj()
{
  return 1;
}

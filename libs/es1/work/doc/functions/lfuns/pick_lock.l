
PICK_LOCK(L)            LOCAL FUNCTIONS              PICK_LOCK(L)

NAME
     pick_lock - attempts to pick a lock

SYNOPSIS
     void pick_lock(object me, int n);

DESCRIPTION
     pick_lock() is defined in /std/lock.c and  will  usually  be
     redefined by an inheriting object.

     An object which you wish to have a lock on it should inherit
     /std/lock.c.   The  pick_lock()  defined  in  there does not
     check the lock picking skill or any other attribute  of  the
     player,  so  it should be redefined.  If the picking is suc-
     cessful, set("lock", n)  should  be  called  in  the  locked
     object.   See  lock(l)  for  details  of  this - basically n
     should be -1 to unlock or 1 to lock the object.  The follow-
     ing arguments should be passed to pick_lock():
       object me: The player trying to open the lock.
       int n: The state of  'lockedness'  the  player  wishes  to
             leave the lock in - see lock(l) for details.

EXAMPLE
     chest->pick_lock(this_player(), -1);

     The chest might define the function like this:
       void pick_lock(object me, int n) {
           if (me->query_skill("Theft") > random(100)) {
               set("lock", n);
       }

SEE ALSO
     lock_func(l)

AUTHOR
     Blue@Atmos


TMI-2 Release 0.9         Last change:                   4-2-93


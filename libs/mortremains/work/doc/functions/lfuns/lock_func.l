
LOCK_FUNC(L)            LOCAL FUNCTIONS              LOCK_FUNC(L)

NAME
     lock_func - determines whether a particular  key  can  open
     this object

SYNOPSIS
     int lock_func(string str);

DESCRIPTION
     lock_func() is defined in /std/lock.c and  will  usually  be
     redefined by an inheriting object.

     lock_func()  will  be  called  in   an   object   inheriting
     /std/lock.c,  when someone tries to lock or unlock it.  (The
     object's init() should call lock::init() so  that  the  com-
     mands  for this are avaiable.)  The following arguments will
     be passed to lock_func():
       string str: the string identifying the key or other
     object  attempting  to  unlock  the  object.  If lock_func()
     returns non-zero, the lock will accept the key.   Otherwise,
     it will not.

PROPERTIES
     Defined in key: query("lock_turn") should return an  integer
     indicating  how  far  the  lock  will be turned by that key.
     query("to_lock") should return a string identifying the  key
     so  that  the  locked  object can check if it is the correct
     one.  This is the string passed to lock_func().

     Defined in locked object:  query("lock")  should  return  an
     integer   indicating  'how  locked'  the  lock  is.   -1  is
     unlocked, 1 is locked  normally.   query("max_lock")  should
     return the maximum amount the lock can be turned to - again,
     normally 1.  query("key") should return the object that  the
     lock can be opened by - an alternative to using lock_func().
     query("current_key")  should  return  the  object  that   is
     currently  being  used to open the lock.  This is set by the
     lock object internally and  will  usually  not  need  to  be
     changed,  unless  you  are  coding something like a skeleton
     key.

EXAMPLE
     In code of key:
       set("to_lock", "iron key"); Automatically called in locked
     object:
       lock_func("iron key"); Function as coded in locked object:
       int lock_func(string str) {
           return (str=="iron key") || (str=="skeleton key");
       }


TMI-2 Release 0.9         Last change:                   4-2-93

LOCK_FUNC(L)            LOCAL FUNCTIONS              LOCK_FUNC(L)

SEE ALSO
     pick_lock(l)

AUTHOR
     Blue@Atmos

Sun Release 4.1           Last change:                          2


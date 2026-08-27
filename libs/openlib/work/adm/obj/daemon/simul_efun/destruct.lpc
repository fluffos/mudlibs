/*  -*- LPC -*-  */
/*
 * If remove() in an object returns non-zero it will prevent it's destruction
 * unless 'force' is passed as the 2nd arg to destruct()
 */

varargs int
destruct(object ob, int force)
{
  string err;
  int val;

  if( !ob ) ob = previous_object();

  err = catch(val = ob->remove());

  if( !force &&  val )
    return 0;
  else
    efun::destruct(ob);

  if( err ) error(err);

  return 1;
}

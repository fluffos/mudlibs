/*
 * add_sign(string long, string read_mess)
 *
 * This file can be inherited and will return a sign that can be used
 * by a room or object in any way it sees fit.  This function was the
 * brainchild of Wyrm - 7 Feb '92
 */

object add_sign (string long, string mess)
{
  object sign;

  sign = clone_object("/std/object");
  sign-> set_name ("signo");
  sign-> set_short ("signo");
  sign-> set_long (long);
  sign-> set_read_mess (mess);
  sign-> set_main_plural ("signos");
  sign-> reset_get ();
  sign-> move (this_object());
  return sign;
}

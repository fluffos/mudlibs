/*  -*- LPC -*-  */
// override of printf() to use message()

varargs
void
printf(string format, mixed* arr ... )
{
  return message("write", sprintf(format, arr ... ), this_player());
}

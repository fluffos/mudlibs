/* Do not remove the headers from this file! see /USAGE for more info. */

//: COMMAND
//$$ see: socketinfo
// USAGE: ``netstat``
//
// Displays a list of sockets with (stat) info on each one.
//
// .. TAGS: RST

inherit CMD;

private
void main()
{
   object *sockets;
   // Do not return output with emojis and ANSI
   set_output_flags(NO_ANSI);

   sockets = children(SOCKET);
   if (!sockets || sockets == ({}))
   {
      out("No sockets active.\n");
   }
   else
   {
      for (int i = 0; i < sizeof(sockets); i++)
         out("" + sockets[i]->stat_me());
   }
}

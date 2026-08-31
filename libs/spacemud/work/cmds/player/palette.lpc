/* Do not remove the headers from this file! see /USAGE for more info. */

//: PLAYERCOMMAND
//$$see: colours, mode, frames
// USAGE
//    ``palette``
//
// Show even more possible colours you can use.
//
// .. TAGS: RST

inherit CMD;
inherit M_COLOURS;

void do_print(string which)
{
   int index = 16;
   string line = "";

   write("Extended color palette\n----------------------\n");
   for (int k = 0; k < 3; k++)
   {
      for (int j = 0; j <= 5; j++)
      {
         for (int i = 0; i < 6; i++)
         {
            line += "<" + sprintf("%0.3d", (index + (i * 6))) + ">" + sprintf("%0.3d", (index + (i * 6))) + "<res>  ";
         }
         index += 36;
         for (int i = 5; i >= 0; i--)
         {
            line += "<" + sprintf("%0.3d", (index + (i * 6))) + ">" + sprintf("%0.3d", (index + (i * 6))) + "<res>  ";
         }
         line += "\n";
         index -= 35;
      }
      index += 66;
   }

   for (int i = 0; i < 24; i++)
   {
      line += "<" + sprintf("%0.3d", (index + i)) + ">" + sprintf("%0.3d", (index + i)) + "<res>  ";
      if ((i + 1) % 12 == 0)
         line += "\n";
   }
   index = 0;
   for (int i = 0; i < 16; i++)
   {
      line += "<" + sprintf("%0.3d", (index + i)) + ">" + sprintf("%0.3d", (index + i)) + "<res>  ";
      if ((i + 1) % 8 == 0)
         line += "\n";
   }
   out(line + "\n");
}

nomask private void main(string str)
{
   do_print(0);
}

void player_menu_entry(string str)
{
   bare_init();
   main(str);
   done_outputing();
}
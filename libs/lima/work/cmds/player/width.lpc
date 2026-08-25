/* Do not remove the headers from this file! see /USAGE for more info. */

//: PLAYERCOMMAND
// USAGE width
//       width <number>
//       width auto
//
// Allows you to see (or set) what the mud will use as your screen width when
// formatting information. Some clients send the width of the terminal window,
// and if yours do that, you can use 'width auto' to set your width automatically.
// It's probably a good idea to set it to the same as your client' setting,
// so they don't get confused when talking to each other.

inherit CMD;

void main(mixed width)
{
   if (width == "auto")
   {
      this_user()->set_screen_width(0);
      out("Screen width set to <120>automatic detection<res>.\n\n" +
          "Set your client to not wrap or wrap at 5000 or more chars - " + mud_name() + " will take it from here.\n\n");
      return;
   }

   width = to_int(width);
   if (!intp(width))
   {
      out("Must set screen width to an integer or 'auto'.\n");
      return;
   }

   if (!width)
   {
      out("Your current screen width is " + this_user()->query_screen_width() +
          (this_user()->is_width_auto() ? " (auto)" : "") + ".\n");
      return;
   }

   if (width < 10)
   {
      out("Screen width must be 10 or greater.\n");
      return;
   }
   this_user()->set_screen_width(width);
   out("Screen width set to " + width + ".\nConsider using 'width auto' if your client supports it.\n");
}

void player_menu_entry(string str)
{
   bare_init();
   main(str);
   done_outputing();
}
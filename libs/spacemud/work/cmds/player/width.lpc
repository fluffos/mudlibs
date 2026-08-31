/* Do not remove the headers from this file! see /USAGE for more info. */

//: PLAYERCOMMAND
// USAGE
//
//   |    ``width``
//   |    ``width <number>
//   |    ``width auto
//   |    ``width nowrap
//
// Allows you to see (or set) what the mud will use as your screen width when
// formatting information. Some clients send the width of the terminal window,
// and if yours do that, you can use ``width auto`` to set your width automatically.
// It is probably a good idea to set it to the same as your client' setting,
// so they don't get confused when talking to each other.
//
// .. TAGS: RST

#define MIN_WIDTH 30

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
   if (width == "nowrap")
   {
      this_user()->set_screen_width(-1);
      out("Wrapping disabled entirely. This can be useful for screen readers that do not like wrapped " +
          "text or read it weirdly.\n\n");
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

   if (width < MIN_WIDTH)
   {
      out("Screen width must be " + MIN_WIDTH + " or greater.\n");
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
/* Do not remove the headers from this file! see /USAGE for more info. */

//: PLAYERCOMMAND
//$$ see: color, colours, ansi, emoji
// USAGE
//
//   |   ``frames``
//   |   ``frames styles``
//   |   ``frames style <name>``
//   |   ``frames themes``
//   |   ``frames theme <name>``
//
// Use ``frames styles`` to show which frame styles are supported.
// Use ``frames style single`` to set your frame style to 'single'.
// Use ``frames theme dusk`` to set your frame theme to 'dusk'.
//
// .. TAGS: RST

inherit CMD;
inherit M_WIDGETS;
inherit M_FRAME;

string frames_help()
{
   return "Valid arguments:\n\n'styles' to see other style options.\n" + "'style <style>' to see other options.\n" +
          "'themes' to list the colour themes.\n" + "'theme <theme>' to select a colour theme.\n" + "\n";
}

private
void main(string arg)
{
   string *styles = query_frame_styles();
   string *colours = query_frame_colour_themes();
   string col;
   string usertheme = this_user()->frames_style();
   string usercoltheme = this_user()->frames_colour();
   frame_init_user();

   if (!arg || arg == "")
   {
      string simplestate;
      set_frame_title("Frame settings");
      set_frame_header("<bld>Frame style is:<res> " + (usertheme || "ascii") + ".\n" + "<bld>Frame theme is:<res> " +
                       (usercoltheme || "none") + ".\n" +
                       (i_simplify() ? "Frames are off, since you have simplify on.\n" : ""));

      set_frame_content(frames_help());
      set_frame_footer("<bld>These settings will change most UI on " + mud_name() + " to this style.<res>");
      out(frame_render());
      return;
   }

   else if (sscanf(arg, "style %s", col) == 1)
   {
      if (member_array(col, styles) != -1)
      {
         this_user()->query_shell_ob()->set_variable("frames", col);
         out("Frame style set to '" + col + "'.\n");
      }
      else
         out("Unknown frame style.\n");
   }
   else if (sscanf(arg, "theme %s", col) == 1)
   {
      if (member_array(col, colours) != -1)
      {
         this_user()->query_shell_ob()->set_variable("frame_colour", col);
         out("Frame colours set to '" + col + "'.\n");
         return;
      }
      else
         out("Unknown theme colours.\n");
   }
   else if (arg == "themes")
   {
      printf("The following frame themes are supported:\n\n");
      printf("<bld>  %-10.10s %s %s %s %s<res>", "Name", "Title", "Accent", "Warn", "Example");

      foreach (string c in colours)
      {
         string titlec = query_frame_title(c);
         string accent = query_frame_accent(c);
         string warning = query_frame_warning(c);

         printf("  %-10.10s %s %s %s %s\n", c, (titlec != "" ? "#" + titlec + "#  <res>" : "  ") + "   ",
                (accent != "" ? "#" + accent + "#  <res>" : "  ") + "    ",
                (warning != "" ? "#" + warning + "#  <res>" : "  ") + "  ",
                (c != "none" ? frame_colour_demo(usertheme, c, 67) : ""));
      }
      printf("\n\n");
   }
   else if (arg == "styles")
   {
      printf("The following frame styles are supported:\n\n");
      printf("\t<bld>%-15.15s %s<res>", "Name", "Example");

      foreach (string t in styles)
      {
         printf("\t%-15.15s %s\n", t, frame_demo_string(t, 20));
      }
      printf("\n\n");
   }
   else
   {
      out("Usage:\n" + frames_help() + ".\n");
      return;
   }
}

void player_menu_entry(string str)
{
   bare_init();
   main(str);
   done_outputing();
}
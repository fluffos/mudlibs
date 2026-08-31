/* Do not remove the headers from this file! see /USAGE for more info. */

#include <commands.h>

inherit ADMTOOL_BASE;
inherit M_FRAME;

mapping colours;

#define FRAME_INCLUDE_FILE "/include/frame_themes.h"

nomask string module_name()
{
   return "frames";
}

nomask string module_key()
{
   return "f";
}

nomask string module_user()
{
   return "[admin]";
}

void stat_frames()
{
   write("** Only shows themes written to config!\n");
   CMD_OB_FRAMES->player_menu_entry("themes");
}

void show_palette()
{
   CMD_OB_PALETTE->player_menu_entry("");
}

int valid_theme(string t)
{
   if (!colours)
      colours = query_themes();
   return colours[t] ? 1 : 0;
}

void show_theme(string theme)
{
   if (!valid_theme(theme))
   {
      write("No such theme.");
      return;
   }
   set_style(this_user()->frames_style());
   set_theme(theme);
   set_width(this_user()->query_screen_width());
   write("Frame colour example:\n" + frame_colour_demo(0, theme, this_user()->query_screen_width() / 3 - 20) + "\n\n");
   write("Frame colour array  : " + implode(map(explode(colours[theme][0], ","), (
                                                                                     : "<" + $1 + ">" + $1 + "<res>"
                                                                                     :)),
                                            ","));
   write("Frame title colour  : " + "<" + colours[theme][1] + ">" + colours[theme][1] + "<res>");
   write("Frame accent colour : " + "<" + colours[theme][2] + ">" + colours[theme][2] + "<res>");
   write("Frame warning colour: " + "<" + colours[theme][3] + ">" + colours[theme][3] + "<res>");
}

void add_theme(string theme)
{
   if (!colours)
      colours = query_themes();

   colours[theme] = ({"088,089,090,091,092,093", "228", "045", "197"});
   write("Theme '" + theme + "' added with default values. Use 's " + theme + "' to show it.\n");
}

void change_colour(string colour, string theme, string p)
{
   if (!valid_theme(theme))
   {
      write("No such theme.");
      return;
   }
   switch (colour)
   {
   case "gradient":
      colours[theme][0] = p;
      TBUG(theme);
      TBUG(p);
      break;
   case "title":
      colours[theme][1] = p;
      TBUG(theme);
      TBUG(p);
      break;
   case "accent":
      colours[theme][2] = p;
      TBUG(theme);
      TBUG(p);
      break;
   case "warning":
      colours[theme][3] = p;
      TBUG(theme);
      TBUG(p);
      break;
   }
   write((colour != "gradient" ? "<" + p + ">" : "") + capitalize(colour) + "<res> has been updated for '" + theme +
         "' theme.");
}

void write_config()
{
   string content =
       "/* Do not remove the headers from this file! see /USAGE for more info. */\n\n// Automatically generated file, do not edit by hand. Use admtool.
\n\n\nprivate nosave "
                      "mapping colours =\n";
   if (!colours)
   {
      write("Nothing changed, nothing to save.");
      return;
   }
   content += sprintf("%O", colours) + ";\n\n// Automatically generated file, do not edit by hand. Use admtool.\n";
   write_file(FRAME_INCLUDE_FILE, content, 1);
   write(FRAME_INCLUDE_FILE + " updated.");
}

nomask class command_info *module_commands()
{
   return ({
       new (class command_info, key
            : "l", desc
            : "list frame themes", action
            : (
                : stat_frames:)),
       new (class command_info, key
            : "p", desc
            : "palette", action
            : (
                : show_palette:)),
       new (class command_info, key
            : "a", proto
            : "[theme]", args
            : ({"Theme: "}), action
            : (
                  : add_theme:),
              desc
            : "add new theme"),
       new (class command_info, key
            : "s", proto
            : "[theme]", args
            : ({"Theme: "}), action
            : (
                  : show_theme:),
              desc
            : "show theme details"),
       new (class command_info, key
            : "g", proto
            : "[theme] [colour]", args
            : ({"Theme: ", "Gradient (CSV): "}), action
            : (
                  : change_colour, "gradient"
                  :),
              desc
            : "change theme GRADIENT colour (comma seperated list)"),
       new (class command_info, key
            : "t", proto
            : "[theme] [colour]", args
            : ({"Theme: ", "Colour: "}), action
            : (
                  : change_colour, "title"
                  :),
              desc
            : "change theme TITLE colour"),
       new (class command_info, key
            : "a", proto
            : "[theme] [colour]", args
            : ({"Theme: ", "Colour: "}), action
            : (
                  : change_colour, "accent"
                  :),
              desc
            : "change theme ACCENT colour"),
       new (class command_info, key
            : "w", proto
            : "[theme] [colour]", args
            : ({"Theme: ", "Colour: "}), action
            : (
                  : change_colour, "warning"
                  :),
              desc
            : "change theme WARNING colour"),
       new (class command_info, key
            : "W", action
            : (
                  : write_config:),
              desc
            : "write to .h file (do you have a backup?)"),
   });
}

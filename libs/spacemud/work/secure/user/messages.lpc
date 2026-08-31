/* Do not remove the headers from this file! see /USAGE for more info. */

/* %^RESET%^ gets used early in the login sequence by tell() */
private
nosave mapping translations = (["RESET":""]);
private
mapping colours;
private
int debug;
void save_me();
object query_shell_ob();
int *query_window_size();

int screen_width;

void set_screen_width(int width)
{
   screen_width = width;
   this_user()->save_me();
}

int set_output_debug(int d)
{
   debug = d;
   return debug;
}

int query_screen_width()
{
   return screen_width ? screen_width : query_window_size()[0];
}

int is_width_auto()
{
   return screen_width == 0;
}

mapping query_translations()
{
   return translations;
}

string terminal_mode()
{
   string mode;
   if (query_shell_ob())
      mode = query_shell_ob()->get_variable("mode");
   return mode || "plain";
}

string frames_style()
{
   string mode;
   if (query_shell_ob())
   {
      object shell = query_shell_ob();
      int simplify = shell->get_variable("simplify") != 0;
      if (simplify)
         return "none";
      mode = shell->get_variable("frames");
   }
   return mode || "ascii";
}

string frames_colour()
{
   string mode;
   if (query_shell_ob())
   {
      object shell = query_shell_ob();
      int simplify = shell->get_variable("simplify") != 0;
      if (simplify)
         return "none";
      mode = shell->get_variable("frame_colour");
   }
   return mode || "steel";
}

void update_translations()
{
   /* handle new people, old save files, or save files for which this
    * option was disabled */
   if (!colours)
      colours = ([]);
   /* defaults; we take advantage of the fact that mapping addition
    * chooses the second when there is an overlap.
    */
   colours = ANSI_D->defaults() + colours;
   if (terminal_mode() != "plain")
      translations = ANSI_D->query_translations()[0];
   else
      translations = ANSI_D->query_translations()[1];
   translations = copy(translations);
   foreach (string code, string value in colours)
   {
      string *parts = map(explode(value, ","), ( : upper_case:));
      string val = "";

      foreach (string item in parts)
      {
         if (translations[item])
            val += translations[item];
      }
      translations[code] = val;
   }
}

void set_colour(string which, string what)
{
   colours[upper_case(which)] = what;
   update_translations();
   save_me();
}

void query_colour(string which)
{
   return colours[which];
}

mixed *query_colours()
{
   return keys(colours);
}

mapping query_colour_mapping()
{
   return colours;
}

void remove_colour(string which)
{
   map_delete(colours, upper_case(which));
   /* just in case */
   map_delete(colours, lower_case(which));
   map_delete(colours, which);
   update_translations();
   save_me();
}

void do_receive(string msg, int msg_type)
{
   string *lines = explode(msg, "\n");

   // Force message type to be NO_WRAP and NO_ANSI if we simplify (use a screen reader).
   if (query_shell_ob() && query_shell_ob()->get_variable("simplify") == 1)
   {
      msg_type = NO_WRAP + NO_ANSI;
   }

   if (msg_type & NO_ANSI)
   {
      if (msg_type & NO_WRAP)
      {
         // Get rid of any pinkfish and other strange characters.
         lines = map(lines, ( : XTERM256_D->substitute_colour($1, $2) :), "plain");
      }
      else
      {
         lines = map(lines, ( : wrap:), query_screen_width());
      }
   }
   else
   {
      int indent = (msg_type & MSG_INDENT) ? 4 : 0;
      int wrap = (msg_type & NO_WRAP) ? 0 : query_screen_width();

      // Only do XTERM/ANSI parsing if needed.
      if (wrap)
      {
         lines = map(lines, ( : XTERM256_D->xterm256_wrap($1, $(wrap), $(indent)) :));
      }
      lines = map(lines, ( : XTERM256_D->substitute_colour($1, $2) :), terminal_mode());
   }

   msg = implode(lines, "\n");

   if (!(msg_type & MSG_PROMPT))
   {
      msg += "\n";
   }

   if ((msg_type & EMOJI_MSG) && query_shell_ob() && query_shell_ob()->get_variable("emoji") == 1)
      msg = EMOJI_D->emoji_replace(msg, msg_type);

   if (debug)
      msg = "[Debug: " + msg_type + "]\n" + msg;
   receive(msg);
}

//: FUNCTION receive_message
// Receive message is used in connection with the message() efun, which is not
// available when using the LIMA mudlib. Read the help pages for M_MESSAGES instead.
void receive_message(string type, string message)
{
   error("LIMA does not use interactive->receive_message().\nSee documentation for M_MESSAGES.");
}

/*
void do_receive(string msg, int msg_type) {
    if (msg_type & NO_ANSI) {
    if (msg_type & NO_WRAP)
        receive(msg);
    else
        receive(wrap(msg, query_screen_width()));
    } else {
    int indent = (msg_type & MSG_INDENT) ? 4 : 0;
    int wrap = (msg_type & NO_WRAP) ? 0 : query_screen_width();

    receive(terminal_colour(msg + "%^RESET%^",
        translations, wrap, indent));
    }
}
*/

varargs void receive_inside_msg(string msg, object *exclude, int message_type, mixed other)
{
   do_receive(msg, message_type);
}

varargs void receive_outside_msg(string msg, object *exclude, int message_type, mixed other)
{
   do_receive(msg, message_type);
}

varargs void receive_remote_msg(string msg, object *exclude, int message_type, mixed other)
{
   do_receive(msg, message_type);
}

varargs void receive_private_msg(string msg, int message_type, mixed other)
{
   do_receive(msg, message_type);
}

/* Do not remove the headers from this file! see /USAGE for more info. */

/* This file optimizes prompt displaying.*/

#define P_HISTORY 1
#define P_ROOM 2
#define P_PWD 3
#define P_DATE 4
#define P_DAY 5
#define P_NAME 6
#define P_TIME 7
#define P_VITALS 8

private
nosave int *replacements;

private
nosave string prompt;

int get_command_number();
mixed get_variable(string);

protected
void set_prompt(string s)
{
   string *bits;
   int i;

   s = replace_string(s, "%_", "\n");
   s = replace_string(s, "%m", mud_name());
   s = replace_string(s, "%N", this_user()->query_userid());
   if (s[0] == '"' && s[ < 1] == '"')
      s = s[1.. < 2];
   prompt = s;

   replacements = ({});
   bits = explode("%" + s, "%");
   if (!sizeof(bits))
      return;
   for (i = 1; i < sizeof(bits); i++)
   {
      if (bits[i] == "")
      {
         i++;
         continue;
      }
      switch (bits[i][0])
      {
      case 'h':
         replacements += ({P_HISTORY});
         break;
      case 'r':
         replacements += ({P_ROOM});
         break;
      case 'p':
         replacements += ({P_PWD});
         break;
      case 'd':
         replacements += ({P_DATE});
         break;
      case 'D':
         replacements += ({P_DAY});
         break;
      case 'n':
         replacements += ({P_NAME});
         break;
      case 't':
         replacements += ({P_TIME});
         break;
      case 'v':
         replacements += ({P_VITALS});
         break;
      }
   }
   replacements = clean_array(replacements);
}

string smart_path(string pwd_string)
{
   pwd_string = replace_string(pwd_string, wiz_dir(this_user()), "~");
   pwd_string = shorten_filename(pwd_string);

   return pwd_string == "/" ? "/" : pwd_string + "/";
}

// This code matches the critical_bar in M_WIDGETS used by the 'hp' command.
string pretty_percent(int p)
{
   switch (p)
   {
   case 0..9:
      return "%^MAGENTA%^" + p + "%^RESET%^%";
   case 10..29:
      return "%^RED%^" + p + "%^RESET%^%";
   case 30..69:
      return "%^YELLOW%^" + p + "%^RESET%^%";
   case 70..89:
      return "%^WHITE%^" + p + "%^RESET%^%";
   default:
      return "%^GREEN%^" + p + "%^RESET%^%";
   }
}

string vitals_str()
{
   object b = this_body();
   float head, head_max, torso, torso_max;
   head = b->query_health("head") + 0.0;
   head_max = b->query_max_health("head");
   torso = b->query_health("torso") + 0.0;
   torso_max = b->query_max_health("torso");

   // ### Fix, hardcoded to torso and head
   return sprintf("Head: %s Torso: %s Reflex: %s", pretty_percent(to_int(head / head_max * 100)),
                  pretty_percent(to_int(torso / torso_max * 100)),
                  pretty_percent(to_int((1.0 * b->query_reflex() / b->max_reflex()) * 100)), );
   // return "> ";
}

protected
string get_prompt()
{

   string s;
   int rep;
   int i;
   string path;

   if (!prompt)
   {
      set_prompt(get_variable("PROMPT") || "? for shell help> ");
   }

   s = prompt;

   foreach (rep in replacements)
   {
      switch (rep)
      {
      case P_PWD:
         path = get_variable("pwd") || "(No pwd!)";
         path = smart_path(path);
         s = replace_string(s, "%p", path);
         continue;
      case P_TIME:
         s = replace_string(s, "%t", ctime(time())[11..15]);
         continue;
      case P_HISTORY:
         s = replace_string(s, "%h", sprintf("%d", get_command_number()));
         continue;
      case P_ROOM:
         if (environment(this_body()))
         {
            s = replace_string(s, "%r", file_name(environment(this_body())));
         }
         else
            s = replace_string(s, "%r", "<nowhere>");
         continue;
      case P_DATE:
         s = replace_string(s, "%d", ctime(time())[4..9]);
         continue;
      case P_DAY:
         s = replace_string(s, "%D", ctime(time())[0..2]);
         continue;
      case P_NAME:
         s = replace_string(s, "%n", capitalize(this_body()->query_name()));
         continue;
      case P_VITALS:
         s = replace_string(s, "%v", vitals_str());
         continue;
      }
   }
   return s;
}

protected
void create()
{
   this_object()->add_variable_hook("PROMPT", ( : set_prompt:));
}
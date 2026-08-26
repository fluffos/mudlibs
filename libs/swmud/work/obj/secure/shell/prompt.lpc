// Last modified by deforce on 11-21-2007
#define P_HISTORY       1
#define P_ROOM          2
#define P_PWD           3
#define P_DATE          4
#define P_DAY           5
#define P_NAME          6
#define P_TIME          7
#define P_HP            8
#define P_MHP           9
#define P_EXP           10
#define P_TEAM          11
#define P_JEDI          12
#define P_CRED          13
#define P_BANKCRED      14

int get_command_number();
mixed get_variable(string);

private nosave int* replacements;
private nosave string prompt;

protected void set_prompt(string s)
{
   string* bits;
   int i;

   s = replace_string(s, "%_", "\n");
   s = replace_string(s, "%M", mud_name());
   s = replace_string(s, "%N", this_user()->query_userid());

   if ((s[0] == '"') && (s[<1] == '"')) { s = s[1..<2]; }

   prompt = s;

   replacements = ({ });
   bits = explode("%" + s, "%");

   if (!sizeof(bits)) { return; }

   for (i = 1; i < sizeof(bits); i++)
   {
      if (bits[i] == "")
      {
         i++;
         continue;
      }

      switch (bits[i][0])
      {
         case 'H':
            replacements += ({P_HISTORY});
            break;
         case 'r':
            replacements += ({P_ROOM});
            break;
         case 'P':
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
         case 'T':
            replacements += ({P_TIME});
            break;
         case 'h':
            replacements += ({P_HP});
            break;
         case 'm':
            replacements += ({P_MHP});
            break;
         case 'e':
            replacements += ({P_EXP});
            break;
         case 'c':
            replacements += ({P_CRED});
            break;
         case 'b':
            replacements += ({P_BANKCRED});
            break;
         case 't':
            replacements += ({P_TEAM});
            break;
         case 'j':
            replacements += ({P_JEDI});
            break;

      }
   }

   replacements = clean_array(replacements);
}

protected string get_prompt()
{
   string      s;
   int         rep;
   int         i;

   if (!prompt)
   {
      set_prompt(get_variable("PROMPT") || "> ");
   }

   s = prompt;

   foreach (rep in replacements)
   {
      switch (rep)
      {
         case P_PWD:
            s = replace_string(s, "%P", get_variable("pwd") || "(no pwd!)");
            continue;
         case P_TIME:
            s = replace_string(s, "%T", ctime(time())[11..15]);
            continue;
         case P_HISTORY:
            s = replace_string(s, "%H", sprintf("%d", get_command_number()));
            continue;
         case P_ROOM:
            if (environment(this_body()))
            {
               s = replace_string(s, "%r", file_name(environment(this_body())));
            }
            else { s = replace_string(s, "%r", "<nowhere>"); }
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
         case P_HP:
            s = replace_string(s, "%h", sprintf("%i", this_body()->query_health()));
            continue;
         case P_MHP:
            s = replace_string(s, "%m", sprintf("%i", this_body()->query_max_health()));
            continue;
         case P_EXP:
            s = replace_string(s, "%e", sprintf("%i", this_body()->query_experience()));
            continue;
         case P_TEAM:
            s = replace_string(s, "%t", sprintf("%i", this_body()->query_team_alignment()));
            continue;
         case P_JEDI:
            s = replace_string(s, "%j", sprintf("%i", this_body()->query_jedi_alignment()));
            continue;
         case P_CRED:
            s = replace_string(s, "%c", sprintf("%i", this_body()->query_amt_money("credits")));
            continue;
         case P_BANKCRED:
            s = replace_string(s, "%b", sprintf("%i", this_body()->query_amt_money("bank_credits")));
            continue;
      }
   }

   return s;
}

protected void create()
{
    this_object()->add_variable_hook("PROMPT", (:set_prompt:));
}
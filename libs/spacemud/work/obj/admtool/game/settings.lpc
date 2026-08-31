/* Do not remove the headers from this file! see /USAGE for more info. */

inherit ADMTOOL_BASE;
inherit "/std/classes/config";

#define CONFIG_FILES "/include/config/"

string *configs;
object config_ed;
mapping settings, new_settings = ([]);

private
varargs void configure_file(string);

nomask string module_name()
{
   return "settings";
}

nomask string module_key()
{
   return "S";
}

private
void list_configs()
{
   int x = 1;
   foreach (string file in configs)
   {
      write(" [" + x + "] " + file + "\n");
      x++;
   }
}

private
void get_config_setting(string key, class config c, mixed result)
{
   int i = to_int(result);

   if (stringp(result) && result == "q")
   {
      write("Aborting ...");
      return;
   }

   switch (c.type)
   {
   case "integer":
      if (c.range)
      {
         int j, k;
         if (sscanf(c.range, "%d-%d", j, k) == 2)
         {
            if (i > k || i < j)
            {
               write("** Invalid selection, old value kept.");
            }
            else
               c.current_value = "" + i;
         }
         else
            c.current_value = "" + i;
      }
      break;
   case "boolean":
      if (!stringp(result) || (result != "y" && result != "n" && result != "yes" && result != "no"))
      {
         write("** Invalid selection, old value kept.");
      }
      else if (result == "y" || result == "yes")
         c.define = 1;
      else if (result == "n" || result == "no")
         c.define = -1;
      break;
   case "string":
      if (!stringp(result) || strlen(result) == 0)
      {
         write("** Invalid selection, old value kept.");
      }
      else
         c.current_value = "\"" + result + "\"";
      break;
   default:
      error("Unknown type " + c.type);
   }

   new_settings[key] = c;
   map_delete(settings, key);
   configure_file();
}

private
void save_config(string input)
{
   if (input == "y" || input == "yes")
   {
      string file_contents = config_ed->create_config(new_settings);
      string file_name = new_settings["config"];
      unguarded(1, ( : write_file, file_name, file_contents, 1 :));
      write("Saved to " + file_name + ".");
      settings = 0;
      new_settings = ([]);
      return;
   }
   write("Aborting ...");
   settings = 0;
   new_settings = ([]);
}

private
varargs void configure_file(string selection)
{
   int s = to_int(selection);
   class config c;
   string key;

   if (!settings && selection)
   {
      if (s <= 0 || s > sizeof(configs))
      {
         write("* Invalid selection '" + selection + "'.");
         return;
      }
      s--;
      settings = config_ed->read_config(CONFIG_FILES + configs[s]);
      new_settings["config"] = settings["config"];
   }

   if (!sizeof(keys(settings)))
   {
      input_one_arg("%^YELLOW%^Save changes?%^RESET%^ (y/N): ", ( : save_config:));
      return;
   }

   key = sort_array(keys(settings), 1)[0];
   if (key == "config")
   {
      map_delete(settings, "config");
      configure_file();
      return;
   }
   c = settings[key];

   write("\n\nSetting <032>" + sizeof(new_settings) + "/" + (sizeof(new_settings) + sizeof(settings) - 2) +
         "<res>: <bld>" + c.name + "<res>\n");
   write(c.text);
   switch (c.type)
   {
   case "integer":
      write("(Default: " + c.default_value + ", Value: " + c.current_value + ")");
      input_one_arg("[" + c.range + "]: ", ( : get_config_setting, key, c:));
      break;
   case "boolean":
      write("(Default is: " + c.default_value + ", Value: " + (c.define == 1 ? "yes" : "no") + ")");
      input_one_arg("[y/n]: ", ( : get_config_setting, key, c:));
      break;
   case "string":
      write("(Default is: \"" + c.default_value + "\", Value: " + (c.current_value) + ")");
      input_one_arg("(String): ", ( : get_config_setting, key, c:));
      break;
   }
}

private
void select_file()
{
   write("%^YELLOW%^You will be asked to confirm your choices before saving "
         "the changes. After changing settings here, reboot " +
         mud_name() + ".\nType 'q' at any time to abort.%^RESET%^\n");
   list_configs();
   input_one_arg("Which file do you want to configure? ", ( : configure_file:));
}

nomask class command_info *module_commands()
{
   configs = sort_array(get_dir(CONFIG_FILES + "*.h"), 1);
   config_ed = new (CONFIG_EDITOR);

   return ({
       new (class command_info, key
            : "l", desc
            : "list config files", action
            : (
                : list_configs:)),
       new (class command_info, key
            : "c", desc
            : "configure config file", action
            : (
                : select_file:)),
   });
}

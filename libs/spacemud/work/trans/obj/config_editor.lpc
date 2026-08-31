/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
inherit "/std/classes/config";

#define DEFAULT_PREAMBLE "// Default:"
#define RANGE_PREAMBLE "// Range:"
#define TYPE_PREAMBLE "// Type:"
#define CONFIG_STAMP "// Automatically generated file, do not edit by hand. Use admtool."

private
string *create_header(mapping config)
{
   string *out = ({});
   string include_name = upper_case(replace_string(depath(config["config"]), ".", "_"));

   out += ({"/* Do not remove the headers from this file! see /USAGE for more info. */", "", CONFIG_STAMP});

   out += ({"#ifndef __" + include_name + "__", "#define __" + include_name + "__"});

   return out;
}

private
string *create_footer(mapping config)
{
   string include_name = upper_case(replace_string(depath(config["config"]), ".", "_"));
   return ({"", "#endif /* __" + include_name + "__ */", ""});
}

string *create_config(mapping config)
{
   string *out;
   if (!config || !mapp(config) || undefinedp(config["config"]))
      error("Invalid config mapping.");

   out = create_header(config);

   foreach (string key in sort_array(keys(config), 1))
   {
      class config c = config[key];
      if (key == "config")
         continue;
      out += ({"", "// " + c.text, DEFAULT_PREAMBLE + " " + c.default_value});
      if (c.range)
         out += ({RANGE_PREAMBLE + " " + c.range});
      out += ({TYPE_PREAMBLE + " " + c.type});
      out += ({"#" + (c.define == 1 ? "define " : "undef ") + c.name +
               (c.type == "boolean" ? "" : " " + c.current_value)});
   }

   out += create_footer(config);

   return implode(out, "\n");
}

mapping read_config(string f)
{
   mapping config = ([]);
   string helptext, default_value, range;
   string *lines;
   int count = 1;
   int valid = 0;

   lines = explode(read_file(f), "\n");
   config["config"] = f;

   foreach (string line in lines)
   {
      string type = "integer";
      if (line == CONFIG_STAMP)
         valid = 1;
      else if (!helptext && line[0..1] == "//")
         helptext = trim(line[3..]);
      else if (strlen(line) > 10 && line[0..10] == DEFAULT_PREAMBLE)
         default_value = line[12..];
      else if (strlen(line) > 10 && line[0..8] == RANGE_PREAMBLE)
         range = line[10..];
      else if (strlen(line) > 10 && line[0..7] == TYPE_PREAMBLE)
         type = line[9..];
      else if (helptext && default_value && line[0] == '#')
      {
         string define, name, value;
         class config c = new (class config);
         if (sscanf(line, "#%s %s %s", define, name, value) == 3)
         {
            c.name = name;
            c.current_value = value;
            c.define = (define == "define" ? 1 : -1);
            c.text = helptext;
            c.range = range;
            c.default_value = default_value;
            c.type = (default_value == "yes" || default_value == "no" ? "boolean"
                                                                      : (strsrch(value, "\"") != -1 ? "string" : type));

            helptext = default_value = range = type = 0;
            config["" + sprintf("%3.3d", count)] = c;
            count++;
         }
         else if (sscanf(line, "#%s %s", define, name) == 2)
         {
            c.name = name;
            c.define = (define == "define" ? 1 : -1);
            c.text = helptext;
            c.range = range;
            c.default_value = default_value;
            c.type = (default_value == "yes" || default_value == "no" ? "boolean" : type);

            helptext = default_value = range = type = 0;
            config["" + sprintf("%3.3d", count)] = c;
            count++;
         }
      }
   }
   return valid ? config : 0;
}

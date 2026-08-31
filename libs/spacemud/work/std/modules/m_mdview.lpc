/* Do not remove the headers from this file! see /USAGE for more info. */

//: MODULE
// Inherit this module to gain access to Markdown text functions for formatting
// and creating layout suitable for the MUD. The MD source is parsed into colour
// enhanced strings, C code is rudimentarily formatted and colourized.
//
// This module requires M_COLOURS.

private
string *keywords = ({"void ", "mixed ", "string ", "int ", "object ", "function "});

private
int is_synopsis(string l)
{
   string *parts = explode(trim(l), " ");
   string tmp1, tmp2, tmp3;

   if (sizeof(parts) > 3 && member_array(parts[0] + " ", keywords) != -1 && strsrch(parts[1], "(") != -1 &&
       parts[ < 1] == ");")
   {
      return 1;
   }
   return 0;
}

private
string replace_types(string s, string replace, string with)
{
   string out;
   string *pieces = explode(s, replace);
   out = implode(pieces, with);

   if (strsrch(s, replace) == 0)
      out = with + out;

   return out;
}

//: FUNCTION md_format
// From an array of string lines, format all the lines as markdown text with
// colour markup and return a string.
string md_format(string *file, string searchtext)
{
   string *output = ({});
   string out;
   string *code;
   int lines = 0;

   foreach (string line in file)
   {
      if (!lines)
         line = "<bld>[Markdown file: <220>" + line[2..] + ".md<res><bld>]<res>";

      if (is_synopsis(line))
      {
         string fun;
         fun = explode(explode(line, "(")[0], " ")[ < 1];
         line = replace_string(line, fun, "<221><ul1>" + fun + "<ul0><res> ");

         foreach (string k in keywords)
            line = replace_types(line, k, "<039>" + k + "<res>");
      }

      line = replace_string(line, "#include", "<212>#include<214>");
      line = replace_string(line, "//", "<035>//");
      line = replace_string(line, "###", "<208>") + "<res>";

      output += ({line});
      lines++;
   }

   return implode(output, "\n");
}

//: FUNCTION md_format_file
// Read a file, and format the contents as markdown text with colour markup.
varargs string md_format_file(string f, string searchtext)
{
   string *file = explode(read_file(f), "\n");
   return md_format(file, searchtext);
}

/* Do not remove the headers from this file! see /USAGE for more info. */

//: MODULE
// Inherit this module to gain access to reStructured text functions for formatting
// and creating layout suitable for the MUD. The RST source is parsed into colour
// enhanced strings, C code is rudimentarily formatted and colourized.
//
// This module requires M_COLOURS.

private
string *keywords = ({"void ", "mixed ", "string ", "int ", "object ", "function "});
private
string *decls = ({"inherit ", "static ", "private ", "nosave ", "varargs "});

private
string replace_decl(string s, string replace, string with)
{
   if (strsrch(s, replace) == 0)
      s = with + s[strlen(replace)..];

   return s;
}

private
int is_fun(string l)
{
   string tmp1, tmp2, tmp3;
   int result = sscanf(l, "%s %s(%s)", tmp1, tmp2, tmp3);
   if (result == 3 && (strlen(tmp1) > 1 || strlen(tmp2) > 1 || strlen(tmp3) > 1))
      return 1;
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

private
string header_type(string line)
{
   string part = strlen(line) > 3 ? line[0..2] : 0;
   if (!part)
      return 0;

   switch (part)
   {
   case "###":
      return "<rev><015>";
   case "***":
      return "<bld><220>";
   case "===":
      return "<bld><208>";
   case "---":
      return "<210>";
   case "^^^":
      return "<212>";
   case "\"\"\"":
      return "<201>";
   }
}

private
string replace_inv(string s)
{
   string *parts = explode(s, "``");
   string out = "";
   int on = 1;
   foreach (string p in parts)
   {
      if (!on)
      {
         out += "<073>" + p;
         on = 1;
      }
      else
      {
         out += "<res>" + p;
         on = 0;
      }
   }
   return out;
}

private
string replace_backslash(string s)
{
   string *parts = explode(s, "\\");
   string out = "";
   int on = 1;
   foreach (string p in parts)
   {
      if (!on)
      {
         out += "<213>\\" + p + "\\";
         on = 1;
      }
      else
      {
         out += "<res>" + p;
         on = 0;
      }
   }
   return out;
}

private
string replace_quote(string s)
{
   string *parts = explode(s, "\"");
   string out = "";
   int on = 1;
   foreach (string p in parts)
   {
      if (!on)
      {
         out += "<213>\"" + p + "\"";
         on = 1;
      }
      else
      {
         out += "<res>" + p;
         on = 0;
      }
   }
   return out;
}

private
string replace_italic(string s)
{
   string *parts;
   string out = "";
   int on = 1;
   s = replace_string(s, "\\*", "[ESC_STAR]");
   parts = explode(s, "*");

   // Don't replace stars in function lines.
   if (is_fun(s))
      return s;

   foreach (string p in parts)
   {
      if (!on)
      {
         out += "<it1>" + p;
         on = 1;
      }
      else
      {
         out += "<it0>" + p;
         on = 0;
      }
   }

   out = replace_string(out, "[ESC_STAR]", "*");
   return out;
}

private
string replace_curly_begin(string s)
{
   if (XTERM256_D->colourp(s))
      return s;
   if (strsrch(s, "{") == 0)
      s = "<132>{<res>" + s[1..];
   return implode(explode(s, "{"), "<132>{<res>");
}

private
string replace_curly_end(string s)
{
   if (XTERM256_D->colourp(s))
      return s;
   if (strsrch(s, "}") == 0)
      s = "<132>}<res>" + s[1..];
   return implode(explode(s, "}"), "<132>}<res>");
}

private
string replace_comments(string s)
{
   string out;
   out = implode(explode(s, "//"), "<034>//") + "<res>";
   if (strsrch(s, "//") == 0)
      out = "<034>//" + s[2..];

   out = implode(explode(out, "/*"), "<034>/*") + "<res>";
   if (strsrch(s, "/*") == 0)
      out = "<034>/*" + s[2..];

   return out;
}

// Main replace function for string
private
string replace_function(string line)
{
   if (strlen(line) > 20 && line[0..15] == ".. c:function:: ")
   {
      string fun;
      line = line[16..];
      fun = explode(explode(line, "(")[0], " ")[ < 1];
      line = replace_string(line, fun, "<221><ul1>" + fun + "<ul0><res> ");

      foreach (string k in keywords)
         line = replace_types(line, k, "<039>" + k + "<res>");

      foreach (string k in decls)
         line = replace_decl(line, k, "<061>" + k + "<res>");
   }

   return line;
}

private
string *replace_code(string *lines, string searchtext)
{
   for (int i = 0; i < sizeof(lines); i++)
   {
      string fun;
      if (!strlen(lines[i]))
         continue;
      if (is_fun(lines[i]))
      {
         fun = explode(explode(lines[i], "(")[0], " ")[ < 1];
         fun = trim(fun);
         if (fun == searchtext)
            lines[i] = replace_string(lines[i], fun, "<ul1><010>" + fun + "<ul0><res> ");
         else
            lines[i] = replace_string(lines[i], fun, "<ul1><221>" + fun + "<ul0><res> ");
      }
      foreach (string k in keywords)
         lines[i] = replace_types(lines[i], k, "<039>" + k + "<res>");

      foreach (string k in decls)
         lines[i] = replace_decl(lines[i], k, "<061>" + k + "<res>");

      lines[i] = replace_quote(lines[i]);
   }

   return lines;
}

private
string reformat_see(string line)
{
   // ## Ack! My deepest apoligies for this one. Let me know if you figure out what it does, I might have a job for you.
   return implode(map(filter_array(explode(replace_string(line, "Command: ", ""), " "), (
                                                                                            : $1[0] != '<'
                                                                                            :)),
                      (
                          : $1[1..]
                          :))[1..],
                  ", ") +
          "\n";
}

private
string mark_bad_reference(string line)
{
   string *cmds = explode(trim(line), ", ");
   string *existing_cmds = CMD_D->query_cmds();
   string out = "";

   foreach (string cmd in cmds)
   {
      if (member_array(cmd, existing_cmds) == -1)
         out += "<009>" + cmd + "<res>, ";
      else
         out += cmd + ", ";
   }
   return out[0.. < 3] + "<res>.";
}

//: FUNCTION rst_format
// From an array of string lines, format all the lines as reStructured text with
// colour markup and return a string.
string rst_format(string *file, string searchtext)
{
   string *output = ({});
   string out;
   string *code;
   int lines = 0;

   foreach (string line in file)
   {
      // Handle if functions
      line = replace_function(line);

      // Skip 'File generated by' line
      if (strlen(line) > 18 && strsrch(line, "File generated by ") >= 0)
         continue;

      if (strlen(line) > 5 && line[0..3] == "See:")
      {
         line = reformat_see(line);
         line = mark_bad_reference(line);
         line = "<227>See<res>: " + line;
      }

      // Code blocks
      if (line == ".. code-block:: c")
      {
         code = ({});
         continue;
      }

      // Skip other blocks we don't know
      if (strlen(line) > 4 && line[0..2] == ".. ")
         continue;

      // If we're in code block mode:
      if (arrayp(code))
      {
         if (strlen(line) > 3 && line[0] != ' ')
         {
            code = replace_code(code, searchtext);
            output += code + ({""});
            lines += sizeof(code) + 1;
            code = 0;
         }
         else
         {
            code += ({line});
            continue;
         }
      }

      // If this is a header line, make the previous line into appropriate header.
      if (header_type(line))
      {
         if (lines - 1 < 0)
            continue;
         output[lines - 1] = "\n" + header_type(line) + output[lines - 1][5..];
         continue;
      }

      // If we have a pipe in the first empty space, trim it out, don't touch the rest.
      if (strlen(line) > 3 && strlen(trim(line)) > 0 && trim(line)[0] == '|' && line[0] != '|')
         line = "<066>" + implode(explode(line, "|")[1..], "|") + "<res>";

      line = replace_italic(line); // Handles *italic* markers
      line = replace_inv(line);    // Handles `` markers
      if (searchtext)
         line = replace_string(line, searchtext, "<010>" + trim(searchtext) + "<res>");
      output += ({line});
      lines++;
   }

   out = implode(output, "\n");
   out = replace_string(out, "\n\n\n", "\n\n");
   return out + "<res>";
}

//: FUNCTION rst_format_file
// Read a file, and format the contents as reStructured text with colour markup.
varargs string rst_format_file(string f, string searchtext)
{
   string *file = explode(read_file(f), "\n");
   return rst_format(file, searchtext);
}

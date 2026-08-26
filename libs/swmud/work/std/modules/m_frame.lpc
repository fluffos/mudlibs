/* Do not remove the headers from this file! see /USAGE for more info. */

/*
 * Frame layout module for fancy frames.
 * Tsath 2022/2023. Heavily inspired by frame layouts done by Diavolo@Merentha.
 */

#define TRD 0  // Right down
#define TH 1   // Horisontal
#define THD 2  // Horisontal down
#define TLD 3  // Left down
#define TD 4   // Down
#define TDR 5  // Down right
#define TX 6   // Cross
#define TDL 7  // Down left
#define TRU 8  // Right up
#define THU 9  // Horisontal up
#define TLU 10 // Left up

#define FALLBACK_THEME "ascii"
#define COL_GRADIENT 0
#define COL_TITLE 1
#define COL_ACCENT 2
#define COL_WARNING 3

private
nosave mapping themes = (["single":({"┌", "─", "┬", "┐", "│", "├", "┼", "┤", "└", "┴", "┘"}),
                          "double":({"╔", "═", "╦", "╗", "║", "╠", "╬", "╣", "╚", "╩", "╝"}),
                           "ascii":({"+", "-", "-", "+", "|", "|", "|", "|", "+", "-", "+"}),
                           "lines":({"-", "-", "-", "-", " ", " ", "-", " ", "-", "-", "-"}),
                            "none":({" ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "})]);

private
nosave mapping colours = (["fire":({"160,166,172,178,184,190,226,220,214,208,202,196", "208", "015", "197"}),
                          "steel":({"239,240,241,242,255,237,238,239,240,241", "117", "015", "197"}),
                          "fairy":({"093,099,105,111,117,123,159,153,147,141,135,129", "175", "015", "197"}),
                           "cool":({"021,027,033,039,045,051,087,081,075,069,063,057", "159", "015", "197"}),
                           "pink":({"165,171,177,183,189,195,231,225,219,213,207,201", "231", "015", "197"}),
                          "blues":({"058,059,060,061,062,063", "105", "229", "197"}),
                           "dusk":({"130,131,132,133,134,135", "220", "223", "197"}),
                          "sunny":({"226,227,228,229,230,231", "214", "015", "197"}),
                           "neon":({"088,089,090,091,092,093", "228", "045", "197"}),
                         "nature":({"022,028,034,040,046,083,077,071,065,059", "192", "015", "197"}), // Nature
                           "none":({"", "", "", ""}), ]);                                             // And none
private
nosave string *bits;

/* Strings */
private
string title, header_content, footer_content, content, theme;
/* Ints */
private
nosave int width, // Width of the frame, default user screen width
    title_margin, // Margin the header takes from left side, default 2
    text_margin;  // Margin around header text
/* Booleans*/
private
nosave int add_header, add_footer, left_header;

// Colour configuration storage.
private
nosave string *hcolours;

//: FUNCTION colour_strlen
// Gives the length of the visible portion of s.  Colour
// codes (e.g. %^GREEN%^ <123>) are ignored.
int colour_strlen(string str)
{
   return strlen(XTERM256_D->substitute_colour(str, "plain"));
}

//: FUNCTION use_colour
// Returns the colour in the colour array, cols, to use given the position
// out of the width (typically screen width).
string use_colour(string *cols, int position, int width)
{
   int col_index = floor(sizeof(cols) * ((0.0 + position) / (width || 1)));

   col_index = CLAMP(col_index, 0, sizeof(cols) - 1);
   return cols[col_index] != "" ? "<" + cols[col_index] + ">" : "";
}

void select_theme(string t)
{
   theme = t;

   if (member_array(theme, keys(themes)) != -1)
      bits = themes[theme];
   else
      bits = themes[FALLBACK_THEME];
}

string *query_frame_colour_themes()
{
   return sort_array(keys(colours), 1);
}

string *query_frame_themes()
{
   return keys(themes);
}

void set_frame_left_header()
{
   left_header = 1;
}

private
string colour_str(string t, string col)
{
   if (!col || strlen(col) != 3)
      return t;
   return "<" + col + ">" + t + "<res>";
}

string title(mixed t)
{
   return colour_str("" + t, hcolours[COL_TITLE]);
}

string accent(mixed t)
{
   return colour_str("" + t, hcolours[COL_ACCENT]);
}

string raw_accent()
{
   return hcolours[COL_ACCENT];
}

string warning(mixed t)
{
   return colour_str("" + t, hcolours[COL_WARNING]);
}

void set_frame_title(string s)
{
   if (XTERM256_D->colourp(s))
      title = s;
   else if (hcolours && hcolours[COL_TITLE] != "")
      title = "<" + hcolours[COL_TITLE] + ">" + s + "<res>";
   else
      title = s;
}

void set_width(int w)
{
   width = CLAMP(w,10,1000);
}

void set_title_margin(int hm)
{
   title_margin = hm;
}

void set_text_margin(int tm)
{
   text_margin = tm;
}

void frame_init_user()
{
   set_width(this_user()->query_screen_width() ? this_user()->query_screen_width() - 2 : 79);
   hcolours = (this_user()->frames_colour() != "none" ? colours[this_user()->frames_colour()] : colours["none"]);
   select_theme(this_user()->frames_theme());
   title_margin = 2;
   text_margin = 1;
   add_header = 0;
   add_footer = 0;
   left_header = 0;
}

void set_frame_header(string hc)
{
   string *header_lines;
   int i = 0;

   if (!hc)
   {
      add_header = 0;
      return;
   }
   header_lines = explode(hc, "\n");
   while (i < sizeof(header_lines))
   {
      string line = header_lines[i];
      if (!XTERM256_D->colourp(line) && hcolours[COL_ACCENT] != "")
         line = "<" + hcolours[COL_ACCENT] + ">" + rtrim(line) + "<res>";
      else
         line = rtrim(line);
      header_lines[i] = line;
      i++;
   }
   header_content = implode(header_lines, "\n");
   add_header = 1;
}

void set_frame_footer(string fc)
{
   footer_content = fc;
   add_footer = 1;
}

void set_frame_content(string c)
{
   content = c;
}

void set_frame_hcolours(string *hc)
{
   hcolours = hc;
}

private
string simple_header()
{
   string out = "";
   out += bits[TRD] + repeat_string(bits[TH], width - 2) + bits[TLD] + "\n";
   return out;
}

private
string create_header()
{
   string out = "";
   int i = 0;
   int simple_header = theme == "lines" || theme == "none";
   int header_width = colour_strlen(title) + (text_margin * 2);
   string *headers = explode(header_content || "", "\n");

   if (!title)
      return simple_header();

   if (add_header && title_margin == 1)
      title_margin = 2;

   if (!simple_header)
   {
      out += repeat_string(" ", title_margin) + bits[TRD];
      while (i < header_width)
      {
         out += bits[TH];
         i++;
      }

      out += bits[TLD] + "\n";
   }

   out += bits[TRD] + (add_header ? bits[THD] : "") + repeat_string(bits[TH], title_margin - (add_header ? 2 : 1)) +
          bits[TDL] + repeat_string(" ", text_margin) + title + repeat_string(" ", text_margin) + bits[TDR] +
          repeat_string(bits[TH], width - header_width - title_margin - (add_header ? 4 : 3)) +
          (add_header ? bits[THD] : "") + bits[TLD] + "\n";

   if (!simple_header)
   {
      out +=
          bits[TD] + (add_header ? bits[TD] : "") + repeat_string(" ", title_margin - (add_header ? 2 : 1)) + bits[TRU];

      i = 0;
      while (i < header_width)
      {
         out += bits[TH];
         i++;
      }
      out += bits[TLU] + repeat_string(" ", width - header_width - title_margin - (add_header ? 4 : 3)) +
             (add_header ? bits[TD] : "") + bits[TD] + "\n"; // End of Title box section
   }

   foreach (string h in headers)
   {
      int col_lendiff = strlen(h) - colour_strlen(h);
      int content_width = width - 6 + col_lendiff;
      if (title_margin > 0)
         out += bits[TD] + (add_header && !simple_header ? bits[TD] : " ") + " " +
                sprintf("%-" + content_width + "." + content_width + "s", h) + " " + (add_header ? bits[TD] : "") +
                bits[TD] + "\n";
   }

   if (simple_header)
      out += "";
   else if (add_header)
      out += bits[TD] + (add_header ? bits[TRU] : "") + repeat_string(bits[TH], width - 4) +
             (add_header ? bits[TLU] : "") + bits[TD] + "\n";
   return out;
}

private
string create_footer()
{
   string out = "";
   int i = 0;
   string *footers = explode(footer_content || "", "\n");

   out += bits[TD] + bits[TRD] + repeat_string(bits[TH], (width - 4)) + bits[TLD] + bits[TD] + "\n";

   foreach (string f in footers)
   {
      int col_lendiff = strlen(f) - colour_strlen(f);
      int content_width = width - 6 + col_lendiff;
      out += bits[TD] + bits[TD] + " " + sprintf("%-" + content_width + "." + content_width + "s", f) + " " + bits[TD] +
             bits[TD] + "\n";
   }

   out += bits[TRU] + bits[THU] + repeat_string(bits[TH], width - 4) + bits[THU] + bits[TLU] +
          "\n"; // End of Title box section

   return out;
}

private
string create_left_header()
{
   string out = "";
   string *headers = explode(header_content || "", "\n");
   int header_width, max_header_width, i = 0;
   string *contents = explode(content || "", "\n");
   int content_length = max(({sizeof(headers), sizeof(contents)}));

   if (title)
      header_width = colour_strlen(title) + (text_margin * 2);

   max_header_width = max(map_array(headers, ( : colour_strlen($1) :)));
   max_header_width = max_header_width + (2 * text_margin);

   // Line 1 - title only
   if (title)
      out += repeat_string(" ", title_margin + max_header_width + 1) + bits[TRD] +
             repeat_string(bits[TH], header_width) + bits[TLD];
   out += "\n";

   // Line 2 - both cases
   if (title)
      out += repeat_string(" ", max_header_width + 1) + bits[TRD] + repeat_string(bits[TH], text_margin) + bits[TDL] +
             repeat_string(" ", text_margin) + title + repeat_string(" ", text_margin) + bits[TDR] +
             repeat_string(bits[TH], width - max_header_width - 6 - header_width) + bits[TLD] + "\n";
   else
      out += repeat_string(" ", max_header_width + 1) + bits[TRD] +
             repeat_string(bits[TH], width - max_header_width - 3) + bits[TLD] + "\n";

   // Line 3
   if (title)
      out += bits[TRD] + repeat_string(bits[TH], max_header_width) + bits[TDL] + repeat_string(" ", title_margin - 1) +
             bits[TRU] + repeat_string(bits[TH], header_width) + bits[TLU] +
             repeat_string(" ", width - max_header_width - header_width - 6) + bits[TD] + "\n";
   else
   {
      string c = contents[0];
      int col_lendiff = strlen(c) - colour_strlen(c);
      int content_width = width - max_header_width + col_lendiff - 5;
      out += bits[TRD] + repeat_string(bits[TH], max_header_width - 2) + repeat_string(bits[TH], title_margin) +
             bits[TDL] + " ";
      out += sprintf("%-" + content_width + "." + content_width + "s", c) + " " + bits[TD] + "\n";
      contents = contents[1..];
      content_length = max(({sizeof(headers), sizeof(contents)}));
   }

   while (i < content_length)
   {
      string head, cont;
      int col_lendiff;
      int content_width;
      head = i < sizeof(headers) ? headers[i] : "";
      cont = i < sizeof(contents) ? contents[i] : "";
      col_lendiff = strlen(cont) - colour_strlen(cont);
      content_width = width - max_header_width + col_lendiff - 5;

      if (i < sizeof(headers)) // Header content | Stuff |
         out += bits[TD] + repeat_string(" ", text_margin) + head + "<res>" +
                repeat_string(" ", max_header_width - text_margin - colour_strlen(head)) + bits[TD] + " ";
      else if (i == sizeof(headers)) // End of header
         out += bits[TRU] + repeat_string(bits[TH], max_header_width) + "<res>" + bits[TDL] + " ";
      else // No header, just spacing.
         out += repeat_string(" ", max_header_width + 1) + bits[TD] + " ";

      // Content
      out += sprintf("%-" + content_width + "." + content_width + "s", cont) + " " + bits[TD] + "\n";
      i++;
   }

   if (i <= sizeof(headers))
      out += bits[TRU] + repeat_string(bits[TH], max_header_width) + "<res>" +
             (i == sizeof(contents) ? bits[THU] + repeat_string(bits[TH], width - max_header_width - 3) + bits[TLU]
                                    : bits[TDL] + repeat_string(" ", width - max_header_width - 3) + bits[TD]) +
             "\n";

   if (i != sizeof(contents) || sizeof(contents) > sizeof(headers))
      out += repeat_string(" ", max_header_width + 1) + bits[TRU] +
             repeat_string(bits[TH], width - max_header_width - 3) + bits[TLU] + "\n";

   return out;
}

private
string create_content()
{
   string out = "";
   string *contents = explode(content || "", "\n");

   foreach (string c in contents)
   {
      int col_lendiff = strlen(c) - colour_strlen(c);
      int content_width = width - 4 + col_lendiff;
      out += bits[TD] + " " + sprintf("%-" + content_width + "." + content_width + "s", c) + " " + bits[TD] + "\n";
   }
   return out;
}

private
string end_frame()
{
   string out = "";
   out += bits[TRU] + repeat_string(bits[TH], width - 2) + bits[TLU] + "\n"; // End of Title box section
   return out;
}

varargs private string h_colours(string output, mixed colstring)
{
   string frames = implode(bits, "");
   mixed *pieces = pcre_assoc(output, ({"[" + frames + "]"}), ({1}));
   string *bits = pieces[0];
   string *matches = pieces[1];
   string new_out = "";
   string *colours;
   int i = 0;
   int position = 0;

   colours = explode((arrayp(colstring) ? colstring[COL_GRADIENT] : colstring) || hcolours[COL_GRADIENT], ",");

   if (!sizeof(colours))
      return output;
   while (i < sizeof(bits))
   {
      if (strsrch(bits[i], "\n") != -1)
         position = 0;

      new_out += (matches[i] ? use_colour(colours, position, width) + bits[i] + "<res>" : bits[i]);
      position += strlen(bits[i]);
      i++;
   }

   return new_out;
}

string query_frame_title(string theme)
{
   return colours[theme][COL_TITLE];
}

string query_frame_accent(string theme)
{
   return colours[theme][COL_ACCENT];
}

string query_frame_warning(string theme)
{
   return colours[theme][COL_WARNING];
}

string frame_demo_string(string theme, int w)
{
   return themes[theme][TRD] + themes[theme][TH] + themes[theme][TH] + themes[theme][TH] +
          repeat_string(themes[theme][TH], (w / 2) - 6) + themes[theme][THD] + themes[theme][TH] + themes[theme][TH] +
          themes[theme][TH] + repeat_string(themes[theme][TH], (w / 2) - 6) + themes[theme][TH] + themes[theme][TH] +
          themes[theme][TH] + themes[theme][TLD];
}

string frame_colour_demo(string theme, string colour, int w)
{
   if (member_array(theme, keys(themes)) == -1)
      theme = "single";
   return h_colours(frame_demo_string(theme, w), colours[colour]);
}

string frame_render()
{
   string out = "";

   if (!bits)
      error("Need to set frame theme before render() using frame->set_theme().\n" +
            "Current themes: " + format_list(query_frame_themes()) + ".");

   if (left_header)
   {
      if (!header_content)
         error("Cannot generate left header frame without content.");
      out += create_left_header();
   }
   else
   {
      out = create_header();

      if (content)
         out += create_content();

      if (footer_content)
         out += create_footer();
      else
         out += end_frame();
   }

   if (hcolours && this_user()->terminal_mode() != "plain")
      out = h_colours(out);
   return out;
}
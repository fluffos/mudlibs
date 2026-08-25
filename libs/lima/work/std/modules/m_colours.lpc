/* Do not remove the headers from this file! see /USAGE for more info. */

//: FUNCTION terminal_mode
// Returns "xterm", "ansi", or "vt100" or nothing if the user
// has turned colours off.
nomask string terminal_mode()
{
   return get_user_variable("mode");
}

//: FUNCTION colour_strlen
// Gives the length of the visible portion of s.  Colour
// codes (e.g. %^GREEN%^ <123>) are ignored.
int colour_strlen(string str)
{
   return strlen(XTERM256_D->substitute_colour(str, "plain"));
}

string colour_center(string str)
{
   int len = colour_strlen(str);
   return repeat_string(" ", (this_user()->query_screen_width() - len) / 2) + str;
}

//: FUNCTION colour_truncate
// Returns a string which consists of len or
// fewer visible characters, not counting colour codes.
string colour_truncate(string str, int len)
{
   string result;
   int idx;

   // result = XTERM256_D->xterm256_wrap(str,len);
   result = wrap(str, len);

   if ((idx = member_array('\n', result)) == -1)
      return result;

   return result[0..idx - 1];
}

//: FUNCTION use_colour
// Returns the colour in the colour array, cols, to use given the position
// out of the width (typically screen width).
string use_colour(string *cols, int position, int width)
{
   int col_index = floor(sizeof(cols) * ((0.0 + position) / (width || 1)));

   col_index = CLAMP(col_index, 0, sizeof(cols) - 1);
   return "<" + cols[col_index] + ">";
}

//: FUNCTION gradient_string
// Given a string, spread the colour array equally over the string length.
// Example::
//   gradient_string("Hello world",({"118","119","120","121","122","123"}))
string gradient_string(string str, string *cols)
{
   int i = 0;
   string *exstr = explode(str, "");
   while (i < strlen(str))
   {
      exstr[i] = use_colour(cols, i, strlen(str)) + exstr[i];
      i++;
   }
   return implode(exstr, "") + "<res>";
}

varargs string colour_table(string *items, int width, int num_horiz)
{
   int max_len = 0;
   int n = sizeof(items);
   int size_horiz;
   int num_vert;
   int *lens = allocate(n);
   mixed *lists;
   int i;

   for (i = 0; i < sizeof(items); i++)
   {
      lens[i] = colour_strlen(items[i]);
      if (lens[i] > max_len)
         max_len = colour_strlen(items[i]);
   }

   if (num_horiz == 0)
   {
      num_horiz = width / (max_len + 2);

      if (num_horiz == 0)
         num_horiz = 1;
      /* This moves some entries from the right side
       * of the table to fill out the last line,
       * which makes the table look a bit nicer.
       * E.g.
       * (n=13,p=6)      (l=3,p=5)
       * X X X X X X     X X X X X
       * X X X X X X.X X X X X
       * X               X X X X
       *
       */
      num_vert = (n - 1) / num_horiz + 1;
      if (n > num_horiz && n % num_horiz)
         num_horiz -= (num_horiz - n % num_horiz) / num_vert;
   }
   else
   {
      num_vert = (n - 1) / num_horiz + 1;
   }

   size_horiz = width / num_horiz;

   if (n < num_horiz)
      num_horiz = n;

   lists = map(allocate(num_vert), ( : allocate($(num_horiz)) :));

   for (i = 0; i < sizeof(items); i++)
   {
      string tmp;

      if (lens[i] > size_horiz)
      {
         tmp = colour_truncate(items[i], size_horiz);
      }
      else
      {
         tmp = items[i] + repeat_string(" ", size_horiz - lens[i]);
      }
      lists[i % num_vert][i / num_vert] = tmp;
   }

   return implode(map(lists, ( : implode($1, "") :)), "\n");
}

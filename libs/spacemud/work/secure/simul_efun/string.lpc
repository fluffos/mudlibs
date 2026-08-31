/* Do not remove the headers from this file! see /USAGE for more info. */

string chr(int i);

nosave private string ascii = "";
nosave private string whitespace = " \t\n\r";
nosave private string lowercase = "abcdefghijklmnopqrstuvwxyz";
nosave private string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

nosave private string _lower, _upper, _swapcase;

protected
void create()
{
   int i;

   for (i = 1; i < 255; i++)
   {
      if (i == 0)
         ascii += " ";
      ascii += chr(i);
   }

   _lower = ascii[0..('A' - 1)] + lowercase + ascii[('Z' + 1)..];
   _upper = ascii[0..('a' - 1)] + uppercase + ascii[('z' + 1)..];
  _swapcase = _upper[0..'A'-1] + lowercase + _upper['Z'+1..];
}

//: FUNCTION add_article
// Adds article to things, i.e.::
//   add_article("torch") -> "a torch"
//   add_article("apple") -> "an apple"
string add_article(string str)
{
   switch (str[0])
   {
   case 'a':
   case 'e':
   case 'i':
   case 'o':
   case 'u':
      return "an " + str;
   }
   return "a " + str;
}

//: FUNCTION punctuate
// Adds a period to a sentence if needed.
// Also not after URLs (http/https/ftp).
// Original by Rust in M_GRAMMAR.
string punctuate(string str)
{
   int last_char;
   string url_detect;

   if (!stringp(str) || !strlen(str))
      return "";

   while (strlen(str) && str[ < 1] == ' ')
      str = str[0.. < 2];
   if (!strlen(str))
      return "";

   url_detect = explode(str, " ")[ < 1];
   if (strlen(url_detect) > 5 &&
       (url_detect[0..7] == "https://" || url_detect[0..6] == "http://" || url_detect[0..5] == "ftp://"))
      return str;

   // For the purposes of this, we consider '^' as a letter
   // since the string may end in ANSI codes. Clearly a hack
   // but very effective since punctuate() is widely used, and
   // we do not want to enage the ANSI engine here.
   last_char = str[ < 1];
   if ((last_char >= 'a' && last_char <= 'z') || (last_char >= 'A' && last_char <= 'Z') || (last_char == '^'))
      return str + ".";

   return str;
}

private
int strstr(string s, string lookfor, int start)
{
   int x;

   x = strsrch(s[start..], lookfor);
   if (x == -1)
      return -1;
   return start + x;
}

#define DEFAULT_WIDTH 75
#define DEFAULT_INDENT 4

//: FUNCTION wrap
// Takes the string to wrap, and optionally a width to wrap it
// to and optionally an indent for any line after the first.
varargs string wrap(string str, int width, int indent)
{
   if (!indent)
      return sprintf("%-=*s", width || DEFAULT_WIDTH, str);

   return sprintf("%s%-=*s", str[0..indent - 1], (width || DEFAULT_WIDTH) - indent, str[indent..]);
}

//: FUNCTION iwrap
// Indented wrapping. Takes the string to wrap. This is really
// just a shortcut for::
//
//    wrap(str, 0, DEFAULT_INDENT);
string iwrap(string str)
{
   return wrap(str, 0, DEFAULT_INDENT);
}

//: FUNCTION chr
// Return a string from a character.
// Example:
//
//    chr(120) -> "x"
string chr(int i)
{
   return sprintf("%c", i);
}

//: FUNCTION ord
// Return a char value from a single length string.
// Example:
//
//    ord("x") -> 120
int ord(string x)
{
   if (strlen(x) != 1)
      error("bad type arg to simul_efun ord()");
   return x[0];
}

//: FUNCTION swapcase
// Swaps uppercase to lowercase and lower to upper.
// Example:
//
//    swapcase("jOHN") -> "John"
string swapcase(string s)
{
   return map(s, ( : _swapcase[$1] :));
}

//: FUNCTION count_substrings
// Returns a count of how many times the substring (minimum length 2) was part of the main string.
// Optionally, takes a position where to begin the search.
varargs int count_substrings(string s, string sub, int i)
{
   int n, m, r;

   if (strlen(sub) < 2)
      return -1;

   if (i < 0)
      i += strlen(s);
   n = strlen(sub);
   m = strlen(s) + 1 - n;
   if (!n)
      return m - i;
   n--;

   r = 0;
   while (i < m)
   {
      if (sub == s[i..(i + n)])
      {
         r++;
         i += n;
      }
      else
      {
         i++;
      }
   }
   return r;
}

//: FUNCTION ljust
// Left justify a string to a certain width.
string ljust(string s, int width)
{
   int n;

   n = width - strlen(s);
   if (n <= 0)
      return s;

   return s + repeat_string(" ", n);
}

//: FUNCTION ljust
// Right justify a string to a certain width.
string rjust(string s, int width)
{
   int n;

   n = width - strlen(s);
   if (n <= 0)
      return s;
   return repeat_string(" ", n) + s;
}

string center(string s, int width)
{
   int n, half;

   n = width - strlen(s);
   if (n <= 0)
      return s;
   half = n >> 1;
   if (n % 2 && width % 2)
      half++;
   return repeat_string(" ", half) + s + repeat_string(" ", n - half);
}

//: FUNCTION truncate
// Note that truncate adds an elipsis ("...") to the end if it
// truncates. String must be longer than 1.
string truncate(string s, int length)
{
   length -= 3;
   if (length < 1)
      error("truncate:  value too low");

   if (strlen(s) <= length)
      return s;
   return s[0..length - 1] + "...";
}

//: FUNCTION is_letter
// Test whether a character value is a letter (true) or something else (false).
int is_letter(int c)
{
   return strsrch(lowercase + uppercase, c) != -1;
}

//: FUNCTION format_list
// Formats an array of strings into a string seperated by commas and ended by "and" as a default seperator.
// Example:
//
//   format_list(({"apple","pear","banana"})) -> "apple, pear, and banana"
string format_list(string *list, string separator)
{
   if (!separator)
      separator = "and";
   if (sizeof(list) == 0)
      return "";
   if (sizeof(list) == 1)
      return list[0];
   if (sizeof(list) == 2)
      return list[0] + " " + separator + " " + list[1];
   return implode(list[0.. < 2], ", ") + ", " + separator + " " + list[ < 1];
}

//: FUNCTION tidy_list
// Formats an array of strings into a formatted list including count of items.
// Example:
//
//  tidy_list(({"apple","pear","banana","apple"})) -> "a pear, 2 apple, and a banana"
string tidy_list(mixed items, string separator)
{
   mapping tmp = ([]);
   string *list = ({});

   foreach (mixed item in items)
   {
      if (objectp(item))
         item = item->short();
      if (!stringp(item))
         continue;
      if (member_array(item, keys(tmp)) < 0)
         tmp += ([item:1]);
      else
         tmp[item]++;
   }
   foreach (string name, int num in tmp)
   {
      if (num == 1)
         list += ({add_article(name)});
      else
         list += ({sprintf("%d %s", num, name)});
   }
   return format_list(list, separator);
}

//: FUNCTION title_capitalize
// Return the incoming string with the appropriate words capitalized
// for a title.
string title_capitalize(string instring)
{
   /* Always capitalize the first word. The normal capitalize() handles this */
   string *inarr = explode(capitalize(instring), " ");
   string *out = ({});
/* There are more in parse_command_prepos_list() than is necessary, but
 * they are all two word preps, so they will never be matched, thus this
 * works */
#define UNCAPPED                                                                                                       \
   ({                                                                                                                  \
       "a",                                                                                                            \
       "an",                                                                                                           \
       "the",                                                                                                          \
       "is",                                                                                                           \
       "and",                                                                                                          \
       "but",                                                                                                          \
       "or",                                                                                                           \
   }) + master()->parse_command_prepos_list()

   foreach (string word in inarr)
   {
      if (member_array(word, UNCAPPED) > -1)
         out += ({word});
      else
         out += ({capitalize(word)});
   }

   return implode(out, " ");
}

//: FUNCTION time_to_string
// Return a nicely string formatted version of a number of seconds.
// Default is long format short=1 for shorter format.
// Examples:
//
//   time_to_string(500)   -> "8 minutes, 20 seconds"
//   time_to_string(500,1) -> "8m 20s"
//
// Months, Days, hours, minutes and seconds are supported.
// A month is calculated as 30 days.
string time_to_string(int num, int short)
{
   string timestr = "";
   int months, days, hours, minutes;

   if (num > 2591999)
      months = num / 2592000;
   num -= months * 2592000;
   if (num > 86399)
      days = num / 86400;
   num -= days * 86400;
   if (num > 3599)
      hours = num / 3600;
   num -= hours * 3600;
   if (num > 59)
      minutes = num / 60;
   num -= minutes * 60;

   if (short)
      timestr = (months > 0 ? months + "M " : "") + (days > 0 ? days + "d " : "") + (hours > 0 ? hours + "h " : "") +
                (minutes > 0 ? minutes + "m " : "") + (num > 0 ? num + "s" : "");
   else
      timestr = (months > 0 ? (months == 1 ? months + " month" : days + " months") + ", " : "") +
                (days > 0 ? (days == 1 ? days + " day" : days + " days") + ", " : "") +
                (hours > 0 ? (hours == 1 ? hours + " hour" : hours + " hours") + ", " : "") +
                (minutes > 0 ? (minutes == 1 ? minutes + " minute" : minutes + " minutes") + ", " : "") +
                (num > 0 ? (num == 1 ? num + " second" : num + " seconds") : "");

   return timestr[ < 2..] == ", " ? timestr[0.. < 3] : timestr;
}

//: FUNCTION weight_to_string
// Converts a measure in kg to a nicely formatted string
// in metric or emperial measures. Default is metric.
// Two decimals max. The function returns grams if you
// give weight below a kilo.
//
// If imperial = 1, we convert to imperial not metric.
//
// The default behaviour of this function can be changed by modifying #METRIC
// in config.h.
varargs string weight_to_string(float w, int imperial)
{
   string ret;
   w = w * 1.0;
#ifdef METRIC
   if (imperial)
   {
      w = w * KG_TO_LBS;
      ret = sprintf("%.2f lbs", w);
   }
   else
      ret = w >= 1 ? sprintf("%.2f kg", round(w * 100) / 100) : sprintf("%d g", to_int(w * 1000.0));
   return replace_string(ret, ".00", "");
#endif
#ifndef METRIC
   if (imperial)
      ret = sprintf("%.2f lbs", w);
   else
   {
      w = w * LBS_TO_KG;
      ret = w >= 1 ? sprintf("%.2f kg", round(w * 100) / 100) : sprintf("%d g", to_int(w * 1000.0));
      return replace_string(ret, ".00", "");
   }
#endif
}

//: FUNCTION shorten_filename
// Shortens a filename by introducing ^ as /domains/ and ~ as /wiz/.
string shorten_filename(mixed ob)
{
   return replace_string(replace_string(explode(stringp(ob) ? ob : sprintf("%O", ob), " ")[0], "/domains/", "^"),
                         WIZ_DIR + "/", "~");
}

//: FUNCTION filename_ellipsis
// Tries to shorten the filepath of a file to fit within the max length
// by adding .. and replacing the ends of long directory names. It never
// touches the filename at the end. The string is first run through
// shorten_filename(s).
string filename_ellipsis(string fpath, int max)
{
   string file = shorten_filename(fpath);
   string *parts = explode(file, "/");
   int saved = 0;
   int partnum = 0;
   while (strlen(file) - saved > max && partnum < sizeof(parts))
   {
      int len = strlen(parts[partnum]);
      if (len > 5 && partnum < sizeof(parts) - 1)
      {
         parts[partnum] = parts[partnum][0..2] + "..";
         saved = len - 5;
      }
      partnum++;
   }
   return (file[0] == '/' ? "/" : "") + implode(parts, "/");
}

//: FUNCTION drunk_speak
// Turns a string into a drunken slurry string.
// Drunk ranges from 0-10, where 0 is comatose and 10 is sober.
string drunk_speak(string s, int drunk)
{
   string *words = explode(s, " ");
   string drunkstr;
   string *rand_letters = ({"ai", "esh", "as", "is", "ish", "aie", "uurr", "aaashh", "eeigg", "aaaaa", "eeeeeesh"});

   for (int i = 0; i < sizeof(words); i++)
   {
      int chance = random(10);
      int n = sizeof(words[i]);
      string *letters = explode(words[i], "");

      if (chance >= drunk && sizeof(letters))
      {
         int pick = random(sizeof(letters));
         letters[pick] = rand_letters[random(sizeof(rand_letters))];
      }

      chance = random(20) - 10;

      if (chance >= drunk && sizeof(letters))
      {
         int pick = random(sizeof(letters) - 2);
         int pick2 = random(sizeof(letters));
         string save;

         if (pick < 0)
            pick = 0;

         save = letters[pick];
         letters[pick] = letters[pick2];
         letters[pick2] = save;

         if (drunk < 8)
            sort_array(letters, ( : random(3) - 1 :));
         if (drunk < 7)
            sort_array(letters, ( : random(3) - 1 :));
      }
      words[i] = implode(letters, "");
   }

   return implode(words, " ");
}
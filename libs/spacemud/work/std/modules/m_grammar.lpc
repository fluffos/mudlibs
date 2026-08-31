/* Do not remove the headers from this file! see /USAGE for more info. */

/* Note: this is now a wrapper for the efun, allowing "on the fly"
 * modification */
#define VOWELS ({'a', 'e', 'i', 'o', 'u'})

//: MODULE
// The grammar module contains a number of functions for producing high
// quality english output.

//: FUNCTION pluralize
// Convert a noun to it's plural form.  Oddly enough, it's also quite
// good at converting verbs to their singular form, since going from plural to
// singular often entails adding an 's'.  Eg, they run, he runs.

string pluralize(string str)
{
   switch (str)
   {
   case "were":
      return "was";
   case "don't":
      return "doesn't";
   case "aren't":
      return "isn't";
   case "possum":
      return "possums";
   case "staff":
      return "staves";
   case "die":
      return "dies";
   case "laf":
      return "lafs";
   case "barf":
      return "barfs";
   case "snarf":
      return "snarfs";
   case "hum":
      return "hums";
   }

   if (str[ < 2.. < 1] == "ff") /* e.g. "bluff" */
      return str + "s";
   if (str[ < 5.. < 1] == "penis")
      return str + "es";

   return efun::pluralize(str);
}

//: FUNCTION number_of
// Handles the common operation: "0 bogs", "1 bog", "2 bogs", ...
string number_of(int num, string what)
{
   if (num == 1)
      return "1 " + what;
   return num + " " + pluralize(what);
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

//: FUNCTION number_word
// num == 1 returns "one", etc. If num > 9, the number is returned as a string
// (num == 10 returns "10", for example), which is consistent with most English
// style guidelines
string number_word(int num)
{
   switch (num)
   {
   case 0:
      return "no"; //Rarely used for inventory, but used for COUNT_EXITS.
   case 1:
      return "one";
   case 2:
      return "two";
   case 3:
      return "three";
   case 4:
      return "four";
   case 5:
      return "five";
   case 6:
      return "six";
   case 7:
      return "seven";
   case 8:
      return "eight";
   case 9:
      return "nine";
   default:
      return num + "";
   }
}

string genetive(mixed o)
{
   string s;
   if (objectp(o))
      s = o->query_name();
   else
      s = o;

   if (!s)
      return "Nobody's";

   if (s[ < 1] == 's' || s[ < 1] == 'x')
      return s + "'";
   else
      return s + "'s";
}
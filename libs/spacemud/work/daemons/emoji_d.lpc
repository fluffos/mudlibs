/* Do not remove the headers from this file! see /USAGE for more info. */

//: MODULE
// EMOJI_D by Tsath April 2020
// (Had to do something while under lockdown)
//
// The EMOJI_D stores emoji names along with an array pair of
//     ({  THE UTF char   , Replacement string  })
//
// It also has a supporting function called
//  string emoji_replace(string s);
//
// This function replaces the replacements in whatever string it is
// given. You can use the emoji_replace to add emoji support to specific
// things like channels or say.
//
// The daemon is controlled via the admtool.

#include <mudlib.h>
#include <security.h>

inherit M_DAEMON_DATA;

#define PRIV_NEEDED "Mudlib:daemons"

private
mapping emoji_map = (["beaming face with smiling eyes":({
                                                           "😁",
                                                           "^^",
                                                       }),
                                        "neutral face":({
                                                           "😐",
                                                           ":|",
                                                       }),
                                             "ok hand":({
                                                           "👌",
                                                           ":ok:",
                                                       }),
                              "face screaming in fear":({
                                                           "😱",
                                                           ":O",
                                                       }),
                                       "grinning face":({
                                                           "😀",
                                                           ":D",
                                                       }),
                                          "woozy face":({
                                                           "🥴",
                                                           ":S",
                                                       }),
                                          "starstruck":({
                                                           "🤩",
                                                           ":starstruck:",
                                                       }),
                                    "downwards button":({
                                                           "🔽",
                                                           ":down:",
                                                       }),
                                      "upwards button":({
                                                           "🔼",
                                                           ":up:",
                                                       }),
                        "smiling face with sunglasses":({
                                                           "😎",
                                                           "B)",
                                                       }),
                              "slightly frowning face":({
                                                           "🙁",
                                                           ":(",
                                                       }),
                                       "middle finger":({
                                                           "🖕",
                                                           ":middle finger:",
                                                       }),
                                        "winking face":({
                                                           "😉",
                                                           ";)",
                                                       }),
                                "slightlysmiling face":({
                                                           "🙂",
                                                           ":-)",
                                                       }),
                                           "thumbs up":({
                                                           "👍",
                                                           "(Y)",
                                                       }),
                                    "face with tongue":({
                                                           "😛",
                                                           ":P",
                                                       }),
                                        "growingheart":({
                                                           "💗",
                                                           "<3",
                                                       }),
                       "rolling on the floor laughing":({
                                                           "🤣",
                                                           ":lol:",
                                                       }),
                                                 "zzz":({
                                                           "💤",
                                                           ":zzz:",
                                                       }),
                                        "pouting face":({
                                                           "😡",
                                                           ":-(",
                                                       }),
                                 "face blowing a kiss":({
                                                           "😘",
                                                           ":*",
                                                       }),
                                           "nerd face":({
                                                           "🤓",
                                                           "8)",
                                                       }),
]);

nomask void remove_emoji(string emoji)
{
   if (!check_privilege(PRIV_NEEDED))
      error("illegal attempt to remove a system emoji\n");

   map_delete(emoji_map, emoji);
   save_me();
}

nomask void add_emoji_data(string emoji, string utfchar, string replacement)
{
   if (!check_privilege(PRIV_NEEDED))
      error("illegal attempt to add a data to a system emoji\n");

   if (!emoji_map[emoji])
   {
      emoji_map[emoji] = ({});
   }

   emoji_map[emoji] = ({utfchar, replacement});
   save_me();
}

nomask void remove_emoji_data(string emoji)
{
   if (!check_privilege(PRIV_NEEDED))
      error("illegal attempt to remove a member from a system emoji\n");

   if (emoji_map[emoji])
   {
      emoji_map[emoji] = ({});
      save_me();
   }
}

nomask mixed get_emoji(string emoji)
{
   mixed res;

   if (!stringp(emoji))
      return 0;
   if (emoji[0] == '(' && emoji[ < 1] == ')')
      emoji = emoji[1.. < 2];
   else
      return emoji;
   emoji = lower_case(emoji);
   if (!(res = emoji_map[emoji]))
   {
      if (this_body() && (res = this_body()->query_perm("emojis")))
      {
         return res[emoji] ? copy(res[emoji]) : emoji;
      }
   }

   return res ? copy(res) : emoji;
}

nomask string *process_list(string *name_list)
{
   return decompose(map_array(name_list, ( : get_emoji:)));
}

nomask mixed get_emoji_data()
{
   return copy(emoji_map);
}

string emoji_replace(string input, int msg_type)
{
   int replacements = -1;

   if (keys(emoji_map) == 0)
      return input;

   while (replacements)
   {
      replacements = 0;
      foreach (string key, string * arr in emoji_map)
      {
         if (strlen(arr[1]) && strsrch(input, arr[1]) != -1)
         {
            input = replace_string(input, arr[1], arr[0]);
            replacements++;
         }
      }
   }
   return input;
}

string *emoji_replace_array(string *input, int msg_type)
{
   string *out = ({});
   foreach (string i in input)
      out += ({emoji_replace(i, msg_type)});
   return out;
}

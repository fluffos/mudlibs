#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

position = 1;

}
nosave mapping blue;

int stats_sort_array(string str, string str2) {
  if (blue[str]["moves"] > blue[str2]["moves"])
    return 1;
  if (blue[str]["moves"] < blue[str2]["moves"])
    return -1;
  return 0;
} /* stats_sort_array() */
 int stats_filter_array(string ind) {
  return blue[ind]["moves"]+blue[ind]["heart_beats"]+blue[ind]["worth"]+
         blue[ind]["array_size"]+blue[ind]["errors"]+blue[ind]["objects"];
} /* stats_filter_array() */

string string_stats(mapping map) {
  string *inds, str;
  int i;

  str = sprintf("%20-s %7|s %7|s %7|s %7|s %7|s %7|s\n",
           "name", "moves", "hbs", "worth", "arr", "errors", "objects");
  inds = keys(map);
  blue = map;
  inds = sort_array(filter_array(inds, "stats_filter_array", this_object()),
                    "stats_sort_array", this_object());
  blue = ([ ]);
  for (i=0;i<sizeof(inds);i++) {
    str += sprintf("%20-s %7|d %7|d %7|d %7|d %7|d %7|d\n", inds[i],
                   map[inds[i]]["moves"],
                    map[inds[i]]["heart_beats"], map[inds[i]]["worth"],
                   map[inds[i]]["array_size"], map[inds[i]]["errors"],
                   map[inds[i]]["objects"]);
  }
  return str;
} /* print_stats() */


protected int cmd(string str, object me) {
  mapping bit;

  if (str)
    bit = ([ str: author_stats(str) ]);
  else
    bit = author_stats();
  me->more_string(string_stats(bit));
  return 1;
} /* do_author() */


 

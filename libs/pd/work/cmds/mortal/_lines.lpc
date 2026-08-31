// lists or changes status of all lines
// 'wide' concept and original code by Ironman
// adapted by Nulvect 20081123

#include <std.h>

class Indicator {
  string on;
  string off;
}

inherit DAEMON;

class Indicator long_ind;
class Indicator wide_ind;

int per_row = 5;

string line_status(object, string, class Indicator);
void toggle_lines(object, string *, int);
void show_lines(object, string *, int);

void create() {
  ::create();
  if (!long_ind) {
    long_ind = new(class Indicator);
    long_ind->on = "%^GREEN%^*%^RESET%^";
    long_ind->off = "%^BOLD%^%^BLACK%^-%^RESET%^";
  }
  if (!wide_ind) {
    wide_ind = long_ind;
  }
}    

void help() {
  message("help",
    "Syntax: <lines [long | wide | on | off]>\n\n"
    "This command will display all communication lines to which you have "
    "access, along with their status (on or off) and current color settings.\n"
    "Specifying 'wide' will show "+cardinal(per_row)+" lines per row. "
    "The default is 'long' which shows one line per row.\n"
    "Using 'on' or 'off' will turn all lines on or off.\n\n"
    "See also: customize, buddylist, enemylist",
    this_player() );
}

int cmd_lines(string str) {
  object tp = this_player();
  string *args;
  string *lines;
  string action;
  
  lines = sort_array(tp->query_channels(), 1);

  if (!str || !strlen(str))
    action = "long";
  else {
    args = explode(str, " ");
    if (member_array("on", args) != -1)
      action = "on";
    else if (member_array("off", args) != -1)
      action = "off";
    else if (member_array("wide", args) != -1)
      action = "wide";
    else
      action = "long";
  }

  switch (action) {
    case "on":
      toggle_lines(tp, lines, 1);
    break;

    case "off":
      toggle_lines(tp, lines, 0);
    break;

    case "wide":
      show_lines(tp, lines, 1);
    break;

    case "long":
      show_lines(tp, lines, 0);
    break;
  }

  return 1;
}

void toggle_lines(object tp, string *lines, int blocked) {
  foreach (string l in lines)
    if (tp->query_blocked(l) == blocked)
      tp->set_blocked(l);
}

void show_lines(object tp, string *lines, int wide_list) {
  string output;
  class Indicator show;

  if (wide_list)
    show = wide_ind;
  else
    show = long_ind;

  lines = map(lines, (: line_status($2, $1, $3) :),
    tp, show);

  if (wide_list)
    output = "\n"+format_page(lines, per_row);
  else
    output = implode(lines, "\n");

  output =
    "%^BLUE%^=+=+=%^BOLD%^(%^RESET%^%^BOLD%^ Lines %^BLUE%^)%^RESET%^"
    "%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
    "%^RESET%^\n"
    "Key: "+show->on+"on "+show->off+"off\n"
    + output +
    "\n%^RESET%^%^BLUE%^"
    "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
    "%^RESET%^";
  message("info", output, tp);
}

string line_status(object tp, string line, class Indicator show) {
  int blocked = tp->query_blocked(line);
  string color = tp->query_line_color(line);

  line = color + line + "%^RESET%^";

  if (blocked) {
    line = show->off + line;
  }
  else {
    line = show->on + line;
  }

  return line;
}


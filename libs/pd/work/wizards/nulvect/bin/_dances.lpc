#include <std.h>
#include <dirs.h>

#define DDIR "/cmds/dances/"

inherit DAEMON;

int cmd_dances(string str) {
  object tp=this_player();
  string *files;
  mapping types = ([
    "attack" : ([
      "color" : "%^BOLD%^%^RED%^",
      "canuse" : ({}),
      "output" : ""
    ]),
    "beneficial" : ([
      "color" : "%^BOLD%^%^MAGENTA%^",
      "canuse" : ({}),
      "output" : ""
    ]),
    "detrimental" : ([
      "color" : "%^BOLD%^%^GREEN%^",
      "canuse" : ({}),
      "output" : ""
    ]),
    "other" : ([
      "color" : "%^BOLD%^%^CYAN%^",
      "canuse" : ({}),
      "output" : ""
    ])
  ]);

  // make sure DDIR ends with a /
  files = get_dir(DDIR);
  // this makes sure the dances show in alphabetical order
  files = sort_array(files, -1);
  foreach (string f in files) {
    object dance;
    dance=new(DDIR+f);
    if (!objectp(dance)) continue;
    if (!(dance->dance())) continue;
    if (dance->query_type())
      types[dance->query_type()]["canuse"] += ({dance->query_dance_name()});
  }

  foreach (string k in keys(types)) {
    string tmp="";
    int s;
    types[k]["output"] += types[k]["color"]+capitalize(k)+":%^RESET%^\n";
    if (!(s=sizeof(types[k]["canuse"])))
      types[k]["output"] += "  (none)";
    else {
      for (s--; s >= 0; s--) {
        tmp += arrange_string("  "+types[k]["canuse"][s], 32);
        if (s > 0) {
          s--;
          tmp += types[k]["canuse"][s];
          if (s > 0) tmp += "\n";
        }
      }
      types[k]["output"] += tmp;
    }
  }

  message("info",
    "%^RESET%^%^BLUE%^+=+=%^BOLD%^( %^WHITE%^Dances %^BLUE%^)%^RESET%^%^BLUE%^"
    "+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n"+
    types["attack"]["output"]+"\n"+
    types["beneficial"]["output"]+"\n"+
    types["detrimental"]["output"]+"\n"+
    types["other"]["output"],
    tp);
  
  return 1;
}

void help() {
  message("help",
    "Syntax: <dances>\n\n"
    "This command displays what dances you currently know.",
    this_player());
}


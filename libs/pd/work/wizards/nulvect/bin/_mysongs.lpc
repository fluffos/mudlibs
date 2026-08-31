#include <std.h>
#include <dirs.h>

#define SDIR "/cmds/song/"

inherit DAEMON;

int cmd_mysongs(string str) {
  object tp=this_player();
  string *files;
  mapping types = ([
    "attack" : ([
      "color" : "%^BOLD%^%^RED%^",
      "cansing" : ({}),
      "output" : ""
    ]),
    "beneficial" : ([
      "color" : "%^BOLD%^%^MAGENTA%^",
      "cansing" : ({}),
      "output" : ""
    ]),
    "detrimental" : ([
      "color" : "%^BOLD%^%^GREEN%^",
      "cansing" : ({}),
      "output" : ""
    ]),
    "other" : ([
      "color" : "%^BOLD%^%^CYAN%^",
      "cansing" : ({}),
      "output" : ""
    ])
  ]);

  // make sure SDIR ends with a /
  files = get_dir(SDIR);
  foreach (string f in files) {
    object song;
    song=new(SDIR+f);
    if (!objectp(song)) continue;
    if (!(song->check(tp))) continue;
    if (song->query_type())
      types[song->query_type()]["cansing"] += ({song->query_song_name()});
  }

  foreach (string k in keys(types)) {
    string tmp="";
    int s;
    types[k]["output"] += "\n"+types[k]["color"]+capitalize(k)+":%^RESET%^";
    if (!(s=sizeof(types[k]["cansing"])))
      types[k]["output"] += "\n   (none)";
    else {
      for (s--; s >= 0; s--) {
        tmp += "\n"+arrange_string("   "+types[k]["cansing"][s], 30);
        if (s > 0) {
          s--;
          tmp += types[k]["cansing"][s];
        }
      }
      types[k]["output"] += "\n"+tmp;
    }
  }

  message("info",
    "%^RESET%^%^BLUE%^+=+=%^BOLD%^( %^WHITE%^Songs %^BLUE%^)%^RESET%^%^BLUE%^"
    "+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="+
    types["attack"]["output"]+
    types["beneficial"]["output"]+
    types["detrimental"]["output"]+
    types["other"]["output"],
    tp);
  
  return 1;
}

void help() {
  message("help",
    "Syntax: <songs>\n\n"
    "This command displays what songs you currently know.",
    this_player());
}


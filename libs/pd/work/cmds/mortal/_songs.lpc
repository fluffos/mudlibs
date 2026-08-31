#include <std.h>
#include <dirs.h>

#define SDIR "/cmds/song/"

inherit DAEMON;

int cmd_songs(string str) {
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
  // this makes sure the songs show in alphabetical order
  files = sort_array(files, -1);
  foreach (string f in files) {
    object song;
    song=new(SDIR+f);
    if (!objectp(song)) continue;
    if (!(song->song())) continue;
    if (song->query_type())
      types[song->query_type()]["cansing"] += ({song->query_song_name()});
  }

  foreach (string k in keys(types)) {
    string tmp="";
    int s;
    types[k]["output"] += types[k]["color"]+capitalize(k)+":%^RESET%^\n";
    if (!(s=sizeof(types[k]["cansing"])))
      types[k]["output"] += "  (none)";
    else {
      for (s--; s >= 0; s--) {
        tmp += arrange_string("  "+types[k]["cansing"][s], 32);
        if (s > 0) {
          s--;
          tmp += types[k]["cansing"][s];
          if (s > 0) tmp += "\n";
        }
      }
      types[k]["output"] += tmp;
    }
  }

  message("info",
    "%^RESET%^%^BLUE%^+=+=%^BOLD%^( %^WHITE%^Songs %^BLUE%^)%^RESET%^%^BLUE%^"
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
    "Syntax: <songs>\n\n"
    "This command displays what songs you currently know.",
    this_player());
}


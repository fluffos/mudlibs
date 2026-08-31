
#include <rest.h>
#include <daemons.h>
#include <guild.h>

#define CLASS_NO_WRAP ({\
  "Nsystem", "Nwrite", "snoop",\
  "prompt", "talk", "no_wrap",\
  "room_description",\
})

#define CLASS_NO_SNOOP ({\
  "tell", "emoteto",\
})

#define CLASS_OVERRIDE_IGNORE ({\
  "broadcast", "info", "more",\
  "room_description", "room_exits", "smell",\
  "listen", "write", "say",\
  "system", "prompt", "tell",\
  "system", "Nsystem",\
  "combat", "magic",\
  "inanimate_item", "living_item",\
})

#define CLASS_SLEEP ({ "info", "sleep" })

#define DEFAULT_COLORS ([\
  "say" : "%^CYAN%^", \
  "whisper" : "%^BOLD%^%^CYAN%^", \
  "yell" : "%^MAGENTA%^", \
  "shout" : "%^BOLD%^%^BLUE%^", \
  "tell" : "%^BOLD%^%^RED%^", \
  "party" : "%^BOLD%^%^RED%^", \
  "buddylist" : "%^BOLD%^%^CYAN%^", \
  "enemylist" : "%^BOLD%^%^RED%^", \
  "lines" : "%^MAGENTA%^", \
])

mapping blocked;
mapping line_colours;
static mapping term_info;
string *Buddies;
string *Enemies;
string *Ignoring;
int earmuffs;

void receive_message(mixed msg_class, mixed msg);
void receive_snoop(string str);
void reset_terminal();
int set_earmuffs();
string *query_full_ignore();
void change_ignore(string str);
int query_ignoring(string str);
void set_line_color(string line, string color);
string query_line_color(string line);
string *query_full_buddy();
string *query_full_enemy();
int query_buddy(string who);
int query_enemy(string who);
int remove_buddy(string who);
int remove_enemy(string who);
void add_buddy(string who);
void add_enemy(string who);
void set_blocked(string str);
int query_blocked(string str);
nomask string *query_channels();
void update_channels();
void register_channels();

void create() {
  blocked = ([]);
  term_info = ([]);
  Buddies = ({});
  Enemies = ({});
  Ignoring = ({});
  line_colours = ([]);
  earmuffs = 0;
}

void receive_message(mixed msg_class, mixed msg) {
    object to=this_object();
    string pas;
    string str, pre, post;
    string channel;
    string tmp;
    string color;
    string name;
    int x;

    if (!stringp(msg)) return;

    if (!stringp(msg_class)) msg_class = "info";
    
    if (!interactive(this_object())) return;
    
    if (to->query_rest_type() == SLEEP && member_array(msg_class, CLASS_SLEEP) == -1) return;

    if (present("harass_logger", this_object()))
      "/cmds/mortal/_harass"->add_harass(this_object()->query_name(), msg);
      
    if(!stringp(str=to->getenv("SCREEN"))) str = "80";

    x = atoi(str)-1;
    
    if (member_array(msg_class, CLASS_NO_WRAP) == -1)
      msg = wrap(msg, x);

    // this stuff is in pueblo.c
    if (to->query_pueblo_version() && msg_class != "html")
      msg = to->modify_output(msg);
    
    if (msg_class == "info_line" && query_blocked("info")) return;
    
    if ((query_blocked(msg_class) || query_blocked(msg_class+" line")) &&
      member_array(msg_class, CLASS_OVERRIDE_IGNORE) == -1) return;

    // lines
    if (sscanf(msg_class, "%s line", channel) == 1) {
      
      if (query_blocked(channel)) return;

      if (sscanf(msg, "%s <"+channel+"> %*s", name) == 2 ||
          sscanf(msg, "<"+channel+"> %s %*s", name) == 2) {
            name = lower_case(name);
            switch (channel) {
              case "buddylist":
                if (!query_buddy(name)) return;
              break;
              case "enemylist":
                if (!query_enemy(name)) return;
              break;
              default:
                if (query_ignoring(name)) return;
            }
      }

      if (!(color = query_line_color(channel))) color = DEFAULT_COLORS["lines"];

      msg = replace_string(msg, "<"+channel+">", color+"<"+channel+">%^RESET%^");

      if (member_array(channel, VALID_GUILDS) != -1) {
        msg = replace_string(msg, "<", color+"<%^RESET%^", 1);
        msg = replace_string(msg, ">", color+">%^RESET%^", 1);
      }
    }

    else {

      msg = CENSOR_D->censor(this_object(), msg_class, msg);

      // colors
      switch (msg_class) {

      case "say":
      case "whisper":
      case "yell":
      case "tell": 
      case "shout":
      case "party":
          if (sscanf(msg, "%s %*s", name) == 2 &&
              name != "You" &&
              query_ignoring(lower_case(name))) return;

          color = query_line_color(msg_class);
          if (!color || !strlen(color))
            color = DEFAULT_COLORS[msg_class];
          if(sscanf(msg, "%s:%s", pre, post) == 2)
            msg = color+pre+":%^RESET%^"+post;
          break;
      case "room_exits": msg = "%^GREEN%^"+msg; break;
      case "smell": msg = "%^ORANGE%^"+msg; break;
      case "listen": msg = "%^CYAN%^"+msg; break;
      case "taste": msg = "%^BOLD%^%^MAGENTA%^"+msg; break;
      case "touch": msg = "%^YELLOW%^"+msg; break;
      case "search": msg = "%^WHITE%^"+msg; break;
      case "read": msg = "%^BOLD%^%^WHITE%^"+msg; break;
      case "snoop":
          pas = "%^RED%^%^BOLD%^%%^RESET%^";
          msg = TERMINAL_D->no_colours(msg);
          msg = pas+msg;
          break;
      case "mmin": case "min": case "mmout": case "mout":
          msg = "%^BOLD%^GREEN%^"+msg; break;
      case "living_item": msg = "%^BOLD%^RED%^"+msg; break;
      case "inanimate_item": msg = "%^BOLD%^MAGENTA%^"+msg; break;

      }
    }

    if (!term_info) reset_terminal();
    msg = terminal_colour(msg, term_info);
    
    if (to->query_prompt()) {
        to->set_prompt(0);
        message("prompt", "\n", this_object());
    }

    if (sizeof(msg+term_info["RESET"]) >= 8191) {
        receive("Printable strings limited to length of 8191.  String len="+sizeof(msg+term_info["RESET"]));
    } else
        receive(msg+term_info["RESET"]); 
}

static void receive_snoop(string str)  { 
    receive_message("snoop", str);
}

void reset_terminal() {
  string type = (string)this_object()->getenv("TERM");
  if (!strlen(type)) type = "unknown";
  term_info = (mapping)TERMINAL_D->query_term_info(type); 
}


/*
void catch_tell(string str) {
    if(earmuffs) {
        if(sscanf(str, "%*s shouts %*s")) return;
    }
    receive(str);
}
*/

// don't think this is even used anymore
int set_earmuffs() {
    if( earmuffs ) {
        earmuffs = 0;
        message("my_action", "Your earmuffs are now off.",
          this_object());
    }
    else
    {   
        message("my_action", "Your earmuffs are now on.", this_object());
        earmuffs = 1;
    }
    return earmuffs;
}

string *query_full_ignore() { return Ignoring || ({}); }

void change_ignore(string str) {
  if (!sizeof(Ignoring)) Ignoring = ({});
  if (member_array(str, query_full_ignore()) == -1)
    Ignoring += ({ str });
  else
    Ignoring -= ({str});
}
int query_ignoring(string str) {
  return member_array(str, query_full_ignore()) != -1;
}

void set_line_color(string line, string color) {
  if (!line_colours) line_colours = ([]);
  line_colours[line] = color; 
}
string query_line_color(string line) {
  if (!sizeof(line_colours) || !line_colours[line]) {
    if (member_array(line, keys(DEFAULT_COLORS)) != -1)
      return DEFAULT_COLORS[line];
    else
      return DEFAULT_COLORS["lines"];
  }

  return line_colours[line];
}

string *query_full_buddy() { return Buddies; }
string *query_full_enemy() { return Enemies; }

int query_buddy(string who) {
  return member_array(who, Buddies) != -1 ||
         member_array("all", Buddies) != -1;
}
int query_enemy(string who) {
  return member_array(who, Enemies) != -1;
}

int remove_buddy(string who) {
  int s = sizeof(Buddies);
  Buddies -= ({ who });
  return s != sizeof(Buddies);
}
int remove_enemy(string who) {
  int s = sizeof(Enemies);
  Enemies -= ({ who });
  return s != sizeof(Enemies);
}

void add_buddy(string who) {
  if (member_array(who, Buddies) == -1)
    Buddies += ({ who });
}
void add_enemy(string who) {
  if (member_array(who, Enemies) == -1)
    Enemies += ({ who });
}

void set_blocked(string str) {
    blocked[str] = !blocked[str];
    if(blocked[str]) message("info", "You are now blocking "+str+".",
          this_object());
    else message("info", "You are no longer blocking "+str+".",this_object());
}

int query_blocked(string str) {
    if(blocked["all"]) return blocked["all"];
    else return blocked[str];
}

nomask string *query_channels() { return CHAT_D->query_channels(this_object()); }

void update_channels() {
    CHAT_D->remove_user(query_channels(), this_object());
    register_channels();
}

// this code was moved into the chat daemon
void register_channels() {
  CHAT_D->register_channels(this_object());
}



#pragma strong_types

#include <server.h>
#include <intermud.h>
#include <imud3.h>
#include <udp.h>

inherit "basic/dependence";

object ob;
string name, mud, emstr, emstr2, service, other_msg, channel;
int    channel_emote, tm_type;

string query_name() {
  return name + "@" + mud;
}

string query_real_name() {
  return query_name();
}

string query_vis_name() {
  return name + "@" + mud;
}

string short() {
  return name;
}

int query_no_article() {
  return 1;
}

int query_npc() {
  return 1;
}

void set_transmission_type(int p) {
  tm_type = p;
}

#ifdef INTERMUD3
void set_channel_emote(int z) {
  channel_emote = z;
}

void set_channel(string c) {
  channel = c;
}

// this function _must_ be called after a set_emoteto()
void set_other_msg(string msg) {
  // "[Coogan nods at Foobar@Blamud.]"  or  "[Coogan nods.]"
  // cut the '[' + ']'
  msg = msg[1..<2];
  msg = regreplace(msg, "^"+(ob||this_player())->query_vis_name()+" ", "$N ",1);
  msg = regreplace(msg, " "+(ob||this_player())->query_vis_name()+" "," $N ",1);
  other_msg = msg;
}
#endif

void set_emoteto(string n, string m) {
  ob   = this_player();
  n && (name = capitalize(n));
  mud  = m;
  set_living_name(query_name());
}

void set_service(string s) {
  service = s;
}

void set_mud_name(string m) {
  mud = m;
}

string query_username() {
  return name;
}

string query_usermud() {
  return mud;
}

string* query_emote_string() {
  return ({ emstr, emstr2 });
}

void create() {
  dependence::create();
  enable_commands();
  if (clonep())
    call_out("selfdestruct", 0);
}

void catch_tell(string str) {
  int i;
  string adv_str;

  if (str[<1] == '\n')
    str = str[0..<2];
#ifdef INTERMUD3  // Coogan, 23-May-02
  if (tm_type == INTERMUD_3)  // cut the '[' + ']'
    str = str[1..<2];
#endif
  str = regreplace(str, "^From afar, ", "", 1);
  if (str[0] == ' ' && // Coogan, 15-Jan-99
      tm_type != INTERMUD_3)
    str = str[1..];
  switch (service) {
  case "tell":
    str = regreplace(str, "^"+ob->query_vis_name(), "", 1);
    adv_str = 0;
    i = strstr(str, " tell");
    adv_str = (i > 0) && str[0..i-1];
    str = str[strstr(str, " you:")+6..];
    SE_INTERMUD->send_request("tell", mud,
                                ({ name, str, adv_str }), tm_type);
    break;
  case "emoteto":
  default:
    str = regreplace(str, "^"+ob->query_vis_name() + " ", "", 1);
    if (str[<1] != '.' && str[<1] != '!' && str[<1] != '?')
      str += ".";
    if (!channel_emote)
      SE_INTERMUD->send_request("emoteto", mud, ({ name, str }), tm_type);
    break;
#ifdef INTERMUD3
  case "channel-t":
    if ((IMUD3->query_channels())[channel]) {
      str = regreplace(str, ob->query_vis_name(), "$N", 1);
      other_msg = regreplace(other_msg, name+"@"+mud, "$O", 1);
      IMUD3"/channel"->send_channel_target_emote(channel,
                                       query_username(), mud, str, other_msg);
    }
    break;
  case "channel-e":
    if ((IMUD3->query_channels())[channel]) {
    // str = "$N" + str;
      IMUD3"/channel"->send_channel_emote(channel, other_msg); // str);
    }
    break;
#endif
  }
}

void selfdestruct() {
  destruct(this_object());
}


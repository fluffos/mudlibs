// Petrarch
// Merentha Lib 1.0
// socials.c
// smile:smiles:$N smiles happily.:$N smiles happilly at $O.:$N smiles $V.

#include <std.h>

inherit DAEMON;

mapping socials=(["wink":({"winks","$N winks knowingly.","$N winks at $O.","$N winks $V."})]);

int get_message(string str) {
object env,ob;
string social, misc, you, me, them;
  if(!str) return 0;
  if(!env=environment(this_player())) return 0;
  if(sscanf(str, "%s %s", social, misc)!=2) {
    if(!socials[str]) return 0;
    them=replace_string(socials[str][1],"$N",this_player()->query_cap_name());
    me=replace_string(socials[str][1],"$N","You");
    me=replace_string(me,socials[str][0],str);
    message("emote", me, this_player());
    message("emote", them, env, this_player());
    return 1;
  }
  if(!socials[social]) return 0;
  if(ob=present(misc,env)) {
    you=replace_string(socials[social][2],"$N",this_player()->query_cap_name());
    you=replace_string(you,"$O","you");
    them=replace_string(socials[social][2],"$N",this_player()->query_cap_name());
    them=replace_string(them,"$O",ob->query_cap_name());
    me=replace_string(socials[social][2],"$N","You");
    me=replace_string(me,"$O",ob->query_cap_name());
    me=replace_string(me,socials[social][0],social);
    message("emote", me, this_player());
    message("emote", you, ob);
    message("emote", them, env, ({this_player(),ob}));
    return 1;
  }
  them=replace_string(socials[social][3],"$N",this_player()->query_cap_name());
  them=replace_string(them,"$V",misc);
  them=replace_string(them,"\n", "");
  me=replace_string(socials[social][3],"$N","You");
  me=replace_string(me,"$V",misc);
  me=replace_string(me,socials[social][0],social);
  me=replace_string(me,"\n", "");
  message("emote", me, this_player());
  message("emote", them, env, this_player());
  return 1;
}

void load_socials() {
string str, *s;
int i=0;
  while(str=read_file("/cfg/socials.o", i, 1)) {
    if(sizeof(s=explode(str,":"))==5) socials[s[0]]=s[1..4];
    i++;
  }
}

void create() {
  load_socials();
}


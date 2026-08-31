#include <guild.h>
# define ACCOUNTS_DIR "/d/guilds/guild/data/member"
mapping member;
void promote_member(string str, object tp, object position) {
tp = this_player();
load_object("/d/guilds/darksouls/data/roster.o");
write("You promote "+str->query_cap_name()+" in your guild!");
tell_object(str, "You have been promoted to +position+ in your guild!");
write_file("/d/guilds/guild/data/promote", tp->query_cap_name()+" promoted "+
str+" to +position+\n");
member["seeker"]["promotion"] = 1;
save_object(ACCOUNTS_DIR+"/"+str);
}
void induct_member(string who) {
    
    member = this_player()->query_name()+(([ "level":0 ]));
    save_object("/d/guilds/darksouls/data/roster.o");
}

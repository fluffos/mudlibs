#ifndef l_guild_h
#define l_guild_h


class GuildClass {
  string leader;
  string name;
  string objectName;
  string *skill;
  int MagicGuild;
}

nosave void create();
nosave void init();

mixed CanJoin(object ob);
string SetLeader(string str);
string GetLeader();
string SetGuildName(string str);
string GetGuildName();
string SetGuildObject(string str);
string GetGuildObject();
string SetGuildSkills(string str);
string GetGuildSkills();
int SetMagicGuild(int);
int GetMagicGuild();

int eventBring(string str);
int eventInitiate(string str);
void eventJoin(object ob);
int eventRetire(string str);
void eventUnjoin(object ob);
void eventWelcome(object ob);


#endif /* l_guild_h */

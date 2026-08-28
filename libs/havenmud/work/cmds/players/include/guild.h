#ifndef l_guild_h
#define l_guild_h


class GuildClass {
  string leader;
  string name;
  string objectName;
  string skill;
}

nosave void create();
nosave void init();



int eventInitiate(string str);
void eventJoin(object ob);
int eventRetire(string str);
int eventPromote(string who);
int eventDemote(string who);


#endif /* l_guild_h */

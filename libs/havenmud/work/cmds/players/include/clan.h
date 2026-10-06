#ifndef l_clan_h
#define l_guild_h


class ClanClass {
  string leader;
  string name;
  string objectName;
  string skill;
}

protected void create();
protected void init();



int eventInitiate(string str);
void eventJoin(object ob);
int eventRetire(string str);
int eventPromote(string who);
int eventDemote(string who);


#endif /* l_clan_h */

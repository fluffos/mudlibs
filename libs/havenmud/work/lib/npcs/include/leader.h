#ifndef l_leader_h
#define l_leader_h

nosave void create();
mixed eventAsk(object who, string what);
void eventConvert(object who, string args);
void eventPreview(object who, string args);
void eventBestowTitles(object who, string args);
void eventJoin(object who, string args);
int eventPreAttack(object ob);
mapping SetPlayerTitles(mapping);
mapping SetUniqueSkills(mapping);
mapping GetUniqueSkills();
mapping GetPlayerTitles();
string *SetTaughtSpheres(string *spheres);
string *GetTaughtSpheres();
int eventOldTeachPlayer(object, string);
string GetPlayerTitle(string);
mapping SetFreeEquip(mapping);
mapping GetFreeEquip();
int GetRaceRestricted();
int SetRestrictRace(int);
int SetNoJoin(int);
int GetNoJoin();
/* backwards compat ones */
string SetNewbieTitle(string);
int SetNewbieEquip(string);

#endif /* l_leader_h */

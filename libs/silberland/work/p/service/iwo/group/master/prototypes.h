/*
  prototypes.h
    Function prototypes for groupmaster

    Iwo@SL
*/
 

// grpmaster.c
void create();
void reset();
void heart_beat();
void remove();

// parse.c
int MasterCommand (string str);
int ParseGCommand (string str);


// internals.c
string strmul      (string a, int x);
void CheckPresence ();
varargs void CheckPresence2 (string grp, string leader, mapping members);
varargs void CheckLeaderPresence (string s_pl);
void CheckEmpty    (string grp);
void AddTask       (int delay, int count, string function, mixed *args);
void CheckGobjVersion (object gobj, string version);
void CheckFollow (object pl, object lastenv, string cmd);
varargs void CheckMembers   (string grp);
varargs void CheckXp        (string pl, string grp);
varargs void NotifyXpChange (string pl, int value, string grp); 
varargs void RecalcXp       (string pl, int value, string grp); 
varargs void RunTask        (string pid, int next, int type, int delay, int count, string function, mixed *args);
void RegisterGobj  (object gobj);
void UnRegisterGobj(object gobj);
private nosave void FindAllGobjs  ();
private nosave void CheckGobjs    ();
private nosave void ResetAllGobjs ();
private nosave void NotifyGobjs   ();

// status.c
int IsInGroup       (object pl);
int IsGroup         (string grp);
int IsMember        (string grp, string pl);
int IsLeader        (string grp, string pl);
int IsPublic        (string grp);
int NumMembers      (string grp);
int PrintGroupStatus(object pl, string grp, mapping stati);
int GroupStatus     (object pl, string grp);
int LocateMembers   (object pl);
int GroupAvgLvl     (string grp);

string QueryLeader (string grp);
string GroupAffiliation (object pl);
string *GroupMembers (string grp);
private nosave int ListGroups          (object pl);
private nosave int HasGroupAbility     (object pl);
void NotifyHpChange (string grp, object pl);


// comm.c
varargs int TellP   (object pl, string txt, string istr);
varargs int TellPnb (object pl, string txt);
varargs int ShoutMembers    (object pl, string txt, int emote);
varargs int GroupMsg(string grp, string txt, string indent, int emote);
varargs int ShoutHist       (object pl, mixed len);
int TellHelp        (object pl);
private nosave int TellMasterHelp      (object pl);
int MasterInfo      (string txt);


// control.c
int SetLeader       (string grp, string pl);
int BreakGroup      (string grp, int method);
int BreakByMember   (object pl, string grp);
int JoinGroup       (object pl, string grp);
int InvitePlayer    (object pl, string s_ipl);
int FireMember      (object pl, string s_fpl);
int LeaveGroup      (object pl, int silent);
int NewGroup        (object pl, string grp);
void ToggleOpen     (object pl);
void ToggleFollow   (object pl);
void TogglePublic   (object pl);
int ChangeLeader    (object pl, string newleader);
int SetAttackCommand     (object pl, string command);
int ExecuteAttackCommand (object pl);

// admin.c
int ToggleGobjDestruct    (object pl);
private nosave int ListTasks ();
private nosave int EnableGroupAbility  (string s_pl);
private nosave int DisableGroupAbility (string s_pl);


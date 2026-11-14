/* object */ _get_owner();
/* int */ ForMe();
/* int */ Allowed();
/* void */ Write (string str);
mixed *get_aliases();
void set_aliases (mixed al);
string get_histchars();
void set_histchars (string str);
int get_maxhist();
void set_maxhist (int i);
int get_maxrecur();
void set_maxrecur (int i);
varargs void AddActions (int parseonly);
void init();
#if 0
DoHeartBeat ( object lroom, object lowner, object* linv, object *lrinv
            , object room, object owner, object *inv, object *rinv
            )
#endif
void heart_beat();
/* int */ Command(string str);
void get_data();
void qmode_on (int mode);
void qmode_off (int mode);
int qmode (int mode); return qmode & mode; }
nosave string DoHistory (string line);
nosave string DoAlias (string arg);
/* void */ NotifyForce (string command);
varargs int CommandScan (string arg, int isline);
int q_alias (string arg);
int q_unalias (string str);
int q_history (string str);
int q_do (string str);
string *long_get_dir (string pat, int all);
int q_for (string str);
void _qexecfile(int line);
int q_sh (string str);
int q_mode (string str);



/* more flags that could be stored in 1 int */
int is_guest;           /* guests have reduced abilities */

string logon_object;    /* hack - object to start up with */
int monitor;            /* HP monitor mode */
string forward_to;      /* who to forward mail to */
nosave object myself;   /* Ourselfs. */
nosave object soul;     /* Our soul */
nosave array souls;     /* The souls we carry around always */
string title;           /* Our official title. Wiz's can change it. */
string password;        /* This players crypted password. */
nosave string password2;/* Temporary when setting password */
array gods;             /* all the gods worshipped */
nosave array caution = ({ });  /* cute message at the end in "who" */
int intoxicated;        /* How many intervals to stay intoxicated. */
int stuffed,weakness;   /* amount of food in stomach. */
int headache, max_headache;
string called_from_ip;  /* IP number used last time */
array quests = ({ });   /* list of all solved quests */
string home;            /* players/wizards home (starting) location */
nosave int power;       /* used in power get, power drop, etc.*/
string description;     /* players definable description */
int muffled;
int time_stamp;         /* last time logged on */
string it;              /* Last thing referenced. */
int k_tmstmp;        
string access_list;
string termtype;        /* terminal type of this player */
string pager;           /* the pager name */
#if 0
array death_hook;
#endif
int untrustworthy;      /* set if this player is to be logged */
                        /* hardcoded hack for wizards */
string pretitle;        /* the string before the person's name */

int scar;               /* scars we have */
string current_action;  /* current action others see you doing */
array catch_buf;        /* buffer for catching stuff we miss */

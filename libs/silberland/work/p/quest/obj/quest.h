// SilberLand MUDlib
//
// sys/quest.h
//
// quests header
//
//
// 03.02.2003 Cirion    Initial Revision
//

#define QM                "/p/quest/obj/questmaster"
#define QO                "/p/quest/obj/quest"

#ifdef WANT_QM_TYPES

#define MAINTAINER  "cirion"
#define __DEBUG__ 1

// Type declarations

#define call_t            mixed    // Format: ({string objname, string fun})
#define time_t            int      // Sekunden seit 1970
#define percent_t         int      // 0..100
#define bool_t            int      // true, false

#define false             0
#define true              1

#define boolp(x) (intp(x) && ((x) == false || (x) == true))
#define percentp(x) (intp(x) && (x) > -1 && (x) < 101)
#define timep(x) (intp(x) && (x) > -1)
#define callp(x) (pointerp(x) && sizeof(x) == 2 && stringp((x)[0]) && stringp((x)[1]))

#define blue_name(x) (explode(file_name(x),"#")[0])

#define foreach(x,y) for(y=sizeof(x);y-->0;)

#ifdef __DEBUG__
#define DB(x) if (find_player(MAINTAINER)) tell_object(find_player(MAINTAINER),"DEBUG(QMQO): "+x+"\n")
#else
#define DB(X)
#endif

#undef WANT_QM_TYPES
#endif // WANT_QM_TYPES

// Properties

// Quest Flags
#define QF_MULTI          1
#define QF_OLDSTYLE       2   // old-style quest
#define QF_DEBUG          4   // debug mode
#define QF_VERBOSE        8   // verbose mode, spams quest maintainer(s)
#define QF_VVERBOSE      16   // very verbose (you won't need this)
#define QF_LOGVERBOSE    32   // verbose log mode
#define QF_ALL_FLAGS      (QF_MULTI|QF_OLDSTYLE|QF_DEBUG|QF_VERBOSE|\
                           QF_VVERBOSE|QF_LOGVERBOSE)

// Error severity
#define QE_INFO           0
#define QE_WARN           1
#define QE_ERROR          2
#define QE_FATAL          3

// spezielle Task-IDs
#define QTI_START         1
#define QTI_END           9999

// Return codes
#define Q_TRUE                    1
#define Q_FALSE                   0
#define Q_SUCCESS                 0
#define Q_NOT_ENOUGH_QP          -1
#define Q_KEY_INVALID            -2
#define Q_KEY_EXISTS             -3
#define Q_QP_INVALID             -4
#define Q_XP_INVALID             -5
#define Q_ALLOWEDOBJ_INVALID     -6
#define Q_INFO_INVALID           -7
#define Q_LEVEL_INVALID          -8
#define Q_REQUIRED_INVALID       -9
#define Q_ACTIVE_INVALID        -10
#define Q_WIZARDS_INVALID       -11
#define Q_SOLVED_INVALID        -12
#define Q_QUESTOBJ_INVALID      -13
#define Q_DESCRIPTION_INVALID   -14
#define Q_PLAYERS_INVALID       -15
#define Q_FLAGS_INVALID         -16
#define Q_ACCESS_DENIED         -17
#define Q_UID_INVALID           -18
#define Q_QUEST_NOT_FOUND       -19
#define Q_ALREADY_INACTIVE      -20
#define Q_ALREADY_ACTIVE        -21
#define Q_TASKID_INVALID        -22
#define Q_REQUIREMENT_INVALID   -23
#define Q_VERIFY_INVALID        -24
#define Q_TRIGGERS_INVALID      -25
#define Q_ACCESS_INVALID        -26
#define Q_PERCENT_INVALID       -27
#define Q_RESET_INVALID         -28
#define Q_DESC_INVALID          -29
#define Q_NO_TASKS              -30
#define Q_PLAYER_NOT_FOUND      -31
#define Q_QO_NOT_FOUND          -32
#define Q_REQ_NOT_FULLFILLED    -33
#define Q_ALREADY_STARTED       -34
#define Q_NOT_STARTED           -35
#define Q_NO_PERCENT_TASK       -36

#define QERRORS ([\
  Q_SUCCESS:\
    "Erfolg",\
  Q_NOT_ENOUGH_QP:\
    "zu wenig Abenteuerpunkte",\
  Q_KEY_INVALID:\
    "Questid ungueltig",\
  Q_KEY_EXISTS:\
    "Questid existiert bereits",\
  Q_QP_INVALID:\
    "ungueltige Abenteuerpunktzahl",\
  Q_XP_INVALID:\
    "ungueltige Erfahrungspunktezahl",\
  Q_ALLOWEDOBJ_INVALID:\
    "ungueltiges Zugriffsobjekt oder Zugriffsobjektliste",\
  Q_INFO_INVALID:\
    "ungueltige Information",\
  Q_LEVEL_INVALID:\
    "ungueltige Stufe",\
  Q_REQUIRED_INVALID:\
    "ungueltiges Flag (verpflichtend/optional)",\
  Q_ACTIVE_INVALID:\
    "ungueltiges Flag (aktiv/inaktiv)",\
  Q_WIZARDS_INVALID:\
    "ungueltige Magier (Betreuer der Quest)",\
  Q_SOLVED_INVALID:\
    "ungueltiger Wert fuer die Anzahl der Questdurchlaeufe",\
  Q_QUESTOBJ_INVALID:\
    "ungueltiges Questobjekt",\
  Q_DESCRIPTION_INVALID:\
    "ungueltige Beschreibung",\
  Q_PLAYERS_INVALID:\
    "ungueltige Spieleranzahl",\
  Q_FLAGS_INVALID:\
    "ungueltige sonstige Flags",\
  Q_ACCESS_DENIED:\
    "Zugriff verweigert",\
  Q_UID_INVALID:\
    "ungueltige UID",\
  Q_QUEST_NOT_FOUND:\
    "Quest nicht gefunden",\
  Q_ALREADY_INACTIVE:\
    "Quest bereits aktiv",\
  Q_ALREADY_ACTIVE:\
    "Quest bereits inaktiv",\
  Q_TASKID_INVALID:\
    "Taskid existiert bereits oder ist ungueltig",\
  Q_REQUIREMENT_INVALID:\
    "ungueltige Vorraussetzungen",\
  Q_VERIFY_INVALID:\
    "ungueltiger Verify Callback",\
  Q_TRIGGERS_INVALID:\
    "ungueltiger Trigger Callback",\
  Q_ACCESS_INVALID:\
    "ungueltige Zugriffsliste",\
  Q_PERCENT_INVALID:\
    "ungueltige Prozentangabe",\
  Q_RESET_INVALID:\
    "ungueltige Resetzeit",\
  Q_NO_TASKS:\
    "die Taskliste ist leer",\
  Q_PLAYER_NOT_FOUND:\
    "Spieler nicht gefunden oder ungueltig",\
  Q_QO_NOT_FOUND:\
    "Questobjekt nicht gefunden",\
  Q_REQ_NOT_FULLFILLED:\
    "Vorraussetzungen nicht erfuellt",\
  Q_ALREADY_STARTED:\
    "Quest bereits begonnen",\
  Q_NOT_STARTED:\
    "Quest noch nicht begonnen",\
  Q_NO_PERCENT_TASK:\
    "Task nicht prozentual"\
  ])

#define QError(x) QERRORS[x]

#ifdef NEED_QO_PROTOTYPES

// Indices des Steps-Mappings
#define QOI_STATUS        0
#define QOI_WHO           1
#define QOI_TIME          2

int AddTask(int taskid,              // eindeutige Taskid, beginnend mit 1
            int * requires,          // Taskids
            call_t * verify,         // Callbacks zur Pruefung der Vorrauss.
            call_t * triggers,       // call_others die getriggert werden
            string * access,         // objekte, die den Task setzen duerfen
            bool_t percent,          // ist Taskfortschritt prozentual
            int players,             // Anzahl noetiger Spieler
            time_t reset,            // Zeit bis zum Reset des Tasks
            string description);     // Beschreibung des Tasks fuer Debug


#undef NEED_QO_PROTOTYPES
#endif // NEED_QO_PROTOTYPES

#ifdef NEED_QM_PROTOTYPES

// Indices des Quest-Mappings
#define QMQ_ACTIVE        0
#define QMQ_WIZARD        1
#define QMQ_QP            2
#define QMQ_XP            3
#define QMQ_LEVEL         4
#define QMQ_ALLOWEDOBJ    5
#define QMQ_SOLVED        6
#define QMQ_INFO          7
#define QMQ_REQUIRED      8
#define QMQ_OBJECT_FILE   9 //new
#define QMQ_DESCRIPTION  10 //new
#define QMQ_PLAYERS      11 //new
#define QMQ_FLAGS        12 //new
#define QMQ_TASKS        13 //new
#define QMQ_VARIABLES    14 //new
#define QMQ_OBJECTS      15 //new
#define QMQ_SIZE         16 // increment with every new key

// Indices des Request-Mappings
#define QMR_WIZARD        0
#define QMR_DOMAIN        1
#define QMR_QP            2
#define QMR_XP            3
#define QMR_FLAGS         4
#define QMR_LEVEL         5
#define QMR_INFO          6
#define QMR_DIR           7
#define QMR_START         8
#define QMR_DOC           9
#define QMR_DESCRIPTION  10
#define QMR_SPECIALS     11
#define QMR_NOTES        12
#define QMR_SIZE         13 // increment with every new key

// Indices des Task-Mappings
#define QMT_REQUIRES      0
#define QMT_VERIFY        1
#define QMT_TRIGGERS      2
#define QMT_ACCESS        3
#define QMT_PERCENT       4
#define QMT_PLAYERS       5
#define QMT_RESET         6
#define QMT_DESCRIPTION   7
#define QMT_SIZE          8 // increment with every new key

//XP threshold
#define XP_NEEDED_FOR_WIZ 1000000

// the quests file
#define QUESTS            "/p/quest/obj/quests"
// percentage of max_QP which is needed to become wizard
#define QP_PERCENT       80

// quest groups
#define QGROUP_1 26
#define QGROUP_2 56
// #define QGROUP_3 100
#define QGROUPS ({ 0, QGROUP_1, QGROUP_2 })

// special macros
#define task_access(task)\
   ( (-1 != (member(quests[questid, QMQ_TASKS][task,QMT_ACCESS],\
            blue_name(previous_object()))))\
  || ((previous_object() == this_object()) && (!is_call) )\
  || (secure()) )

#define ERROR(x,lvl) qmessage(questid, x, lvl)

int AddTask(int taskid,              // eindeutige Taskid, beginnend mit 1
            int * requires,          // Taskids
            call_t * verify,         // Callbacks zur Pruefung der Vorrauss.
            call_t * triggers,       // call_others die getriggert werden
            string * access,         // objekte, die den Task setzen duerfen
            bool_t percent,          // ist Taskfortschritt prozentual
            int players,             // Anzahl noetiger Spieler
            time_t reset,            // Zeit bis zum Reset des Tasks
            string description);     // Beschreibung des Tasks fuer Debug

int StartQuest(string questid, mixed player);
int StopQuest(string questid, mixed player);
int SetTask(string questid, mixed player, int task);
int SetTaskTO(string questid, mixed player, int task, int percent);
int AddTaskPercent(string questid, mixed player, int task, int percent);
int SubTaskPercent(string questid, mixed player, int task, int percent);
int ToggleTask(string questid, mixed player, int task);
int QueryTask(string questid, mixed player, int task);
int QueryTaskPercent(string questid, mixed player, int task);

nosave bool_t secure();
nosave void save();

#undef NEED_QM_PROTOTYPES
#endif // NEED_QM_PROTOTYPES

/** predefined tasks */
#define QTASK_START(triggers,access,players,reset)\
  QTI_START,({}),({}),triggers,access,Q_FALSE,players,reset,"Questbeginn"
#define QTASK_END(requires,verify,triggers,access)\
  QTI_END,requires,verify,triggers,access,Q_FALSE,0,0,"Questende")
//
//  void AddTask(int id,                  eindeutige Taskid, beginnend mit 1
//               int * requires,          Taskids
//               call_t * verify,         Callbacks zur Pruefung der Vorrauss.
//               call_t * triggers,       call_others die getriggert werden
//               object * access,         objekte, die den Task setzen duerfen
//               bool_t percent,          ist Taskfortschritt prozentual
//               int players,             Anzahl noetiger Spieler
//               time_t reset,            Zeit bis zum Reset des Tasks
//               string description)      Beschreibung des Tasks fuer Debug

/** predefined calls */
#define QCALL_SOLVED\
  ({QM,"OnSolved"})
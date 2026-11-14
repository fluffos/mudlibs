/********************************************************************
 * Header: Headerfile fuer allgemeine Haustiere                     *
 * Datei: /p/service/angel/haustiere/std_pet.h                      *
 * Letzte Ueberarbeitung: 14.12.2002                                *
 ********************************************************************/

/* Aenderungen nach 14.12.2002:
 *
 * 2004-11-17 Koomi - Eintrag von fliegenden/schwimmenden NPC 
 *                    eigentlich gehoert das nach /sys/class.h
 *                  - Einbau von Versionsnummer ins std_pet zwecks
 *                    Debugging.
 */

// Properties:

// Privat:
#define P_PET_OWNER_NAME      "pet_owner_name"
#define P_PET_RENAME_DELAY    "pet_rename_delay"
#define P_PET_RETURN_DELAY    "pet_return_delay"
#define P_PET_LOYALITY        "pet_loyality"
#define P_PET_FOOD            "pet_food"
#define P_PET_ENEMIES         "pet_enemies"
#define P_PET_PRICE           "pet_price"
#define P_PET_LEVEL           "pet_level"
#define P_PET_NOATTACK_MSG    "pet_noattack_msg"
#define P_PET_FOLLOW_MSG      "pet_follow_msg"
#define P_PET_STOP_MSG        "pet_stop_msg"
#define P_PET_FORBIDDEN_CMDS  "pet_forbidden_cmds"
#define P_PET_XP              "pet_xp"
#define P_PET_ATTACK_MSG      "pet_attack_msg"
#define P_PET_TRIUMPH_MSG     "pet_triumph_msg"
#define P_PET_VERSION         "pet_version"

// Bewegungstypen
//   per default (0, bzw 'unset') gehen sie
#define PM_WALKING	      0
#define PM_FLYING	      1
#define PM_SWIMMING           2

// Einstellbar:
#define P_PET_DEFEAT_MSG      "pet_defeat_msg"
#define P_PET_REPORT_MSG      "pet_report_msg"
#define P_PET_GREETS_OWNER    "pet_greets_owner"
#define P_PET_GREETS_FRIEND   "pet_greets_friend"
#define P_PET_GREETS_STRANGER "pet_greets_stranger"
#define P_PET_COMMANDS        "pet_commands"
#define P_PET_REACTIONS       "pet_reactions"
#define P_PET_MOVINGTYPE      "pet_moving_type"

// Fuer die Tierhandlung:
#define P_PET_KONFIG_TOOL     "pet_konfig_tool"

// Defines
#define SAVEFILE_DIR    "/p/service/angel/haustiere/save/"
#define SLEEPING_PETS   "/p/service/angel/haustiere/pet_room.lpc"
#define REACTION_GROUPS ({ "fies", "aergerlich", "traurig", "albern", "neutral", "intim", "froh", "aengstlich", "frech", "nett" })

// Prototypes:

int AddPet( string name, string fn );
int RemovePet( string name );
int GetPrice( string key );
int BuyPet ( string key );
string GetPriceList();
string FindPet( string uid );
mixed GetAvaliableRaces();
void SetGuildRestriction ( mixed value );
void SetRaceRestriction ( mixed value );
mixed GetGuildRestriction ();
mixed GetRaceRestriction ();

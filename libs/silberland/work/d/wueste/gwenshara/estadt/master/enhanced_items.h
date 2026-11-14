// Master
#define ENHMASTER "/d/wueste/gwenshara/estadt/master/enhmaster"

// Das Savefiles fuer den Master
#define SAVEFILE_ITEMS    "/d/wueste/gwenshara/estadt/saves/enhanced_items"
#define SAVEFILE_INITDATA "/d/wueste/gwenshara/estadt/saves/enhanced_items_initdata"

// Switches fuer Load & Save
#define SAVE_ITEMS    1
#define SAVE_INITDATA 2

// Check return codes
#define CHECK_PLAYER_OK       0
#define CHECK_PLAYER_NOPLAYER 2
#define CHECK_PLAYER_NOXP     4

#define CHECK_ITEM_OK         0
#define CHECK_ITEM_NOITEM     8
#define CHECK_ITEM_HAS_EFFECT 16
#define CHECK_ITEM_NOMAGIC    32
#define CHECK_ITEM_NOARMOUR   64
#define CHECK_ITEM_WRONGMAT   128
#define CHECK_ITEM_NOAUTOL    256
#define CHECK_ITEM_ALREADY    512

// apply return codes
#define APPLY_OK 0
#define APPLY_NOT_PREPARED 1
#define APPLY_NO_ITEM      2
#define APPLY_NO_MULTI     3
#define APPL_NO_PLAYER     4

// properties
#define P_BACKUP(x) x + "_backup"
#define P_MAGIC_THREADS "magic_threads"

// include/config.h - 全域常數定義

// ── 屬性常數 ────────────────────────────────────────────
#define STAT_STR    "str"
#define STAT_DEX    "dex"
#define STAT_INT    "int"
#define STAT_CON    "con"
#define STAT_WIS    "wis"
#define STAT_CHA    "cha"

// ── 戰鬥相關 ────────────────────────────────────────────
#define MAX_HP_PER_CON  10
#define BASE_ATTACK     10
#define BASE_DEFENCE    5
#define HIT_RATE_BASE   75
#define CRIT_RATE_BASE  5
#define CRIT_MULTIPLIER 2

// ── 物品種類 ────────────────────────────────────────────
#define ITEM_WEAPON     "weapon"
#define ITEM_ARMOUR     "armour"
#define ITEM_CONSUMABLE "consumable"
#define ITEM_MISC       "misc"

// ── 武器類型 ────────────────────────────────────────────
#define WPN_SWORD       "sword"
#define WPN_AXE         "axe"
#define WPN_STAFF       "staff"
#define WPN_BOW         "bow"
#define WPN_DAGGER      "dagger"
#define WPN_SPEAR       "spear"
#define WPN_HAMMER      "hammer"
#define WPN_WAND        "wand"

// ── 武器飛行/射程屬性 ───────────────────────────────────
#define RANGE_MELEE     "melee"    // 近戰（無射程）
#define RANGE_THROWN    "thrown"   // 投擲武器（可飛行一次）
#define RANGE_RANGED    "ranged"   // 遠程武器（弓、弩）
#define RANGE_MAGIC     "magic"    // 魔法射程（法杖、魔杖）

// ── 防具部位 ────────────────────────────────────────────
#define SLOT_HEAD       "head"
#define SLOT_BODY       "body"
#define SLOT_HANDS      "hands"
#define SLOT_FEET       "feet"
#define SLOT_WEAPON     "weapon"
#define SLOT_SHIELD     "shield"
#define SLOT_LEGS       "legs"     // 腿甲
#define SLOT_SHOULDER   "shoulder" // 肩甲
#define SLOT_WAIST      "waist"    // 腰帶
#define SLOT_NECK       "neck"     // 頸環/項鍊
#define SLOT_RING       "ring"     // 戒指（可配戴雙手）
#define SLOT_BACK       "back"     // 背部（斗篷/背甲）
#define SLOT_OFFHAND    "offhand"  // 副手（匕首/盾牌替代）

// ── NPC 棲息地類型 ──────────────────────────────────────
#define HABITAT_LAND    "land"     // 陸地（預設）
#define HABITAT_WATER   "water"    // 水中
#define HABITAT_UNDERGROUND "underground" // 地下/土裡
#define HABITAT_SKY     "sky"      // 天空
#define HABITAT_CAVE    "cave"     // 洞穴

// ── NPC 行為模式 (Bitflags) ──────────────────────────────────
#define BEHAV_PASSIVE      0
#define BEHAV_AGGRESSIVE   1    // 主動攻擊
#define BEHAV_GUARD        2    // 守衛（保護特定範圍）
#define BEHAV_PATROL       4    // 巡邏
#define BEHAV_WANDER       8    // 隨機移動
#define BEHAV_FLEE        16    // 逃跑

// ── 幣值常數 ────────────────────────────────────────────
#define COIN_COPPER     1
#define COIN_SILVER     100
#define COIN_GOLD       10000
#define COIN_COOL_GOLD  1000000

// ── 經驗值與等級 ────────────────────────────────────────
#define MAX_LEVEL       50
#define BASE_EXP_PER_LV 1000

// ── 路徑常數 ────────────────────────────────────────────
#define START_ROOM      "/area/settlements/minxiong.lpc"
#define MASTER_FILE     "/master.lpc"
#define ISSUE_FILE      "/etc/issue"

// ── Fantasy Space P2P 識別 ─────────────────────────────
// mudlib 名稱：英文單字，最多四個，總長最多64字母
// 識別字格式：以點分隔，例如 "fantasy.space"
// 玩家 identity 格式：username@mudlib_id，例如 wade@fantasy.space
#define FS_MUDLIB_NAME   (load_object("/daemon/system_d")->query_mudlib_name())
#define FS_MUDLIB_ID     (load_object("/daemon/system_d")->query_mudlib_id())
#define FS_HUB_URL       "wss://wade-fs-fsmud-hub.hf.space/ws"

// 遠端 clone 緩存路徑
#define FS_CACHE_DIR     "/data/fs_cache"

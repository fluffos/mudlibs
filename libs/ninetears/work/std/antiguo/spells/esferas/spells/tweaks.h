#define SPELLS "/std/spells/cleric/" 
/* 
#define ETO environment(this_object()) 
*/ 
#define ETP environment(this_player()) 
#define PO previous_object() 
 
// Stinking cloud 
#define STINK_LEVELX 2 
#define STINK_GP 10 
#define STINK_LOCKOUT 10 
 
#define IMMORTLOCK 1 
 
// Blade Barrier 
#define BBARIER_GP 15 
#define BBARIER_LOCKOUT 10 
#define BBARIER_LEVELX 8 
#define BLADE_DAMAGE 10 
// Blade Barrier 
#define THEDGE_GP 15 
#define THEDGE_LOCKOUT 50 
#define THEDGE_LEVELX 8 
#define THEDGE_DAMAGE 10 
// Confusion 
#define CONFUSE_GP 15 
#define CONFUSE_LOCKOUT 30 
#define CONFUSE_LEVELX 5 
 
// Cloud Kill 
#define CLOUD_KILL_GP 20 
#define CLOUD_KILL_LEVELX 8 
#define CLOUD_KILL_LOCKOUT 50 
// Power word die 
#define PWK_CALLOUT 10 
#define PWK_LOCKOUT 100 
#define PWK_COST 40 
 
// dispell magic 
#define DISPELL_MAGIC_GP 10 
 
// Poison 
#define POISON_LEVELX 5 
#define POISON_MOD 2 
// Neutralise poison 
#define NEUTRALISE_POISON_GP 4 
 
// Clerical silence 
#define SILENCE_GP 10 
#define SILENCE_LEVELX 5 
// Stoneskin 
#define STONESKIN_FRACTION 1/2 
#define STONESKIN_SHADOW "/std/spells/cleric/stoneskin_sh.lpc" 
#define STONESKIN_DURATION_LEVELX 1 
#define STONESKIN_DURATION_BASE 0 
#define STONESKIN_GP 10 
 
// Wall of Fire  
#define WALLFIRE_LEVELX 6 
#define WALLFIRE_LOCKOUT 40 
#define WALLFIRE_DURATION_LEVELX 2 
#define WALLFIRE_FAIL_DAMAGE 20 
#define WALLFIRE_SUCCESS_DAMAGE 40 
#define WALLFIRE_GP 10 
 
// Regeneration 
#define REGEN_LEVELX 6 
#define REGEN_GP 10 
#define REGEN_DURATION_LEVELX 3 
#define REGEN_NUM_HB 2 
#define REGEN_AMOUNT_LEVELX 8 
 
// Withering 
#define WITHER_GP 12 
#define WITHER_LEVELX 6 
#define WITHER_AMOUNT_LEVELX 8 
#define WITHER_DURATION_LEVELX 3 
#define WITHER_NUM_HB 2 
 
// Unholy Word 
#define UNHOLY_GP 30 
#define UNHOLY_LEVELX 6 
#define UNHOLY_AMOUNT_LEVELX 8 
#define UNHOLY_DURATION_LEVELX 3 
#define UNHOLY_NUM_HB 2 
// Pacify 
#define PACIFY_GP_COST 10 
#define PACIFY_DURATION_BONUS 1 
#define PACIFY_DURATION_BASE 50 
#define PACIFY_DURATION_LEVELX 2 
 
// Hold Person 
#define HOLD_COST 10 
#define HOLD_DURATION_BONUS 1/6 
#define HOLD_DURATION_BASE 0 
#define HOLD_DURATION_LEVELX 1/3 
 

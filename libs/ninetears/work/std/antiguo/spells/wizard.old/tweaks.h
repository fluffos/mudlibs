#define SPELLS "/std/spells/wizard/"
#define SPELLS "/std/spells/wizard/"
#define ETO environment(this_object())
#define ETP environment(this_player())
#define TP this_player()
#define TO this_object();

// Stinking cloud
#define STINK_LEVEL 2
#define STINK_GP 4
#define STINK_LOCKOUT 10

#define IMMORTLOCK 1

// Blade Barrier
#define BBARIER_GP 15
#define BBARIER_LOCKOUT 10
#define BBARIER_LEVEL 8
#define BLADE_DAMAGE 10
// Confusion
#define CONFUSE_GP 15
#define CONFUSE_LOCKOUT 30
#define CONFUSE_LEVEL 5

// Cloud Kill
#define CLOUD_KILL_GP 20
#define CLOUD_KILL_LEVEL 8
#define CLOUD_KILL_LOCKOUT 50
// Finger of death
#define FD_LOCKOUT 100
#define FD_COST 40
#define FD_DELAY 10
// spirit armour
#define SPIRIT_ARMOUR_SHADOW "/std/spells/wizard/sp_armour_sh.lpc"
#define SPIRIT_ARMOUR_GP_COST 6
#define SPIRIT_ARMOUR_PROPERTY "spirit_armour_prop"
#define SP_AR_DURATION_BONUS 30
#define SP_AR_DURATION_BASE 200
#define SPIRIT_ARMOUR_GP_COST 6
#define SP_AR_DURATION_LEVEL_MULT 20
#define SPIRIT_ARMOUR_BASE 3
#define SPIRIT_ARMOUR_LEVEL_MOD 5

#define WRAITHFORM_GP_COST 20
#define WRAITH_PROPERTY "wraithform_on"
#define WRAITH_SHADOW "/std/spells/wizard/wraithform_sh.lpc"
#define WRAITH_MONSTER "/std/spells/wizard/wraith.lpc"
#define WRAITH_DURATION_BONUS 2
#define WRAITH_DURATION_BASE 50
#define WRAITH_DURATION_LEVEL 2


// Dispell magic
#define DISPELL_MAGIC_GP 6

// Silence
#define SILENCE_GP 6
#define SILENCE_LEVEL 4

// Fumble
#define FUMBLE_GP_COST 8
#define FUMBLE_CASTER_ADJ 2
#define FUMBLE_TARGET_ADJ 3

// Pacify
#define PACIFY_GP_COST 10
#define PACIFY_DURATION_BONUS 5
#define PACIFY_DURATION_LEVEL 2
#define PACIFY_DURATION_BASE 20
#define PACIFY_PROPERTY "pacify_on"
#define PACIFY_SHADOW "/std/spells/wizard/pacify_sh.lpc"

#define MIRROR_SHADOW "/std/spells/wizard/mirror_sh.lpc"
#define MIRROR_IMAGES_PER_LEVEL 5
#define MIRROR_DESTROY_ALL_BASE 35
#define MIRROR_GP 10

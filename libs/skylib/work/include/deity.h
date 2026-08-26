/**
 * These are the defines for deities/rituals/other faith related things.
 * @author Sandoz
 */

#define SYMBOL_DIR    OBJ_DIR     "/faith/symbols/"
#define RITUAL_DIR    OBJ_DIR     "/rituals/"
#define SHADOWS       SHADOWS_DIR "/rituals/"
#define EFFECTS       EFFECTS_DIR "/rituals/"
#define BASIC_RITUAL  EFFECTS     "basic_ritual"
#define BASIC_HEALING EFFECTS     "basic_healing"
#define BASIC_GRANT   RITUAL_DIR  "basic_grant"

#define NONLIVING 1
#define LIVING    2
#define SELF      4
#define MULTIPLE  8
#define GROUP    16
#define NOTARGET 32
#define ROOM     64
#define CHECKED 128
#define GHOST   256
#define NO_MOVE 512

#define REPLACE   ({ "restore vitality", \
                     "drain energy",     \
                     "drain life",       \
                     "aura of light",    \
                     "divine cloak",     \
                     "grant wisdom",     \
                     "grant vigor",      \
                     "grant might",      \
                     "grant wit",        \
                     "grant nimbleness", \
                     "Rifilian's Reptile Reflexes", \
                     })

#define RITUALS   ({ RITUAL_DIR "restore_vitality", \
                     RITUAL_DIR "grant_wis", \
                     RITUAL_DIR "grant_int", \
                     RITUAL_DIR "grant_str", \
                     RITUAL_DIR "grant_dex", \
                     RITUAL_DIR "grant_con", \
                     RITUAL_DIR "light", \
                     RITUAL_DIR "divine_cloak", \
                     RITUAL_DIR "replenishing_rune", \
                     RITUAL_DIR "greater_restore_vitality", \
                     })

#define PT_RITUALS ( RITUALS + ({ \
                     RITUAL_DIR "drain_life", \
                     RITUAL_DIR "drain_energy", \
                     RITUAL_DIR "nurture_body", \
                     RITUAL_DIR "suggestion", \
                     RITUAL_DIR "resolve_attitude", \
                     }) )

/* sacrifice defines */
#define SACRIFICE_LEVEL 15
#define SACRIFICE_SKILL "faith.rituals.special"

/* used by the deity handler amongst other things */
#define ALL_DEITIES   ({ "Lumen", "Savons", "Visam", "Dilabi", "Elytra" })

/* the stat of the deity */
#define DEITY_STAT    ([ "Lumen"  : "wis", \
                         "Savons" : "int", \
                         "Visam"  : "str", \
                         "Dilabi" : "con", \
                         "Elytra" : "dex"  \
                         ])

/* the colour of the deity */
#define DEITY_COLOURS ([ "Lumen"  : ({ "pure",   "white" }), \
                         "Savons" : ({ "light",  "grey" }),  \
                         "Visam"  : ({ "pale",   "blue" }),  \
                         "Dilabi" : ({ "forest", "green" }), \
                         "Elytra" : ({ "deep",   "red" }),   \
                         ])

/* Used for holy dust creation and ritual messages. */
#define D_ADJ(x)       DEITY_COLOURS[x][0]
#define D_COL(x)       DEITY_COLOURS[x][1]
#define D_COLOUR(x)    (D_ADJ(x)+" "+D_COL(x))

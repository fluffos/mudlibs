#define SKILLMASTER "/p/daemon/skillmaster/skillmaster"

#define SKMDIR "/p/daemon/skillmaster/"
#define SKMSAVE "/p/daemon/skillmaster/skillmaster"

#define SK_DIR SKMDIR+"skills/"

#define SK_SEWING "sk_sewing"
#define SK_TANNING "sk_tanning"
#define SK_DIGGING "sk_digging"
#define SK_PROSPECT "sk_prospect"
#define SK_LUCK     "sk_luck"
#define SK_FLIPPING "sk_flipping"
#define SK_ARMOURSMITHING "sk_armoursmithing"
#define SK_HERBALLORE "sk_herballore"
#define SK_SENSE "sk_sense"
#define SK_JEWELRY "sk_jewelry"
#define SK_BAKING "sk_baking"
#define SK_BUTCHER "sk_butcher"
#define SK_READ "sk_read"

#define SK_SEWING_NAME "naehen"
#define SK_TANNING_NAME "gerben"
#define SK_DIGGING_NAME "graben"
#define SK_PROSPECT_NAME "schuerfen"
#define SK_LUCK_NAME "glueck haben"
#define SK_FLIPPING_NAME "schnippen"
#define SK_ARMOURSMITHING_NAME "ruestungsschmieden"
#define SK_HERBALLORE_NAME "pflanzenkunde"
#define SK_SENSE_NAME "sinnesschaerfe"
#define SK_JEWELRY_NAME "juwelier"
#define SK_BAKING_NAME "kochen"
#define SK_BUTCHER_NAME "ausweiden"
#define SK_READ_NAME "lesen"

#define SKILL2NAME ([\
        SK_SEWING:SK_SEWING_NAME,\
        SK_TANNING:SK_TANNING_NAME,\
        SK_DIGGING:SK_DIGGING_NAME,\
        SK_PROSPECT:SK_PROSPECT_NAME,\
        SK_LUCK:SK_LUCK_NAME,\
        SK_FLIPPING:SK_FLIPPING_NAME,\
        SK_ARMOURSMITHING:SK_ARMOURSMITHING_NAME,\
        SK_HERBALLORE: SK_HERBALLORE_NAME,\
        SK_SENSE: SK_SENSE_NAME,\
        SK_JEWELRY: SK_JEWELRY_NAME,\
        SK_BAKING: SK_BAKING_NAME,\
        SK_BUTCHER: SK_BUTCHER_NAME,\
        SK_READ: SK_READ_NAME,\
        ])

#define NAME2SKILL ([\
        SK_SEWING_NAME:SK_SEWING,\
        SK_TANNING_NAME:SK_TANNING,\
        SK_DIGGING_NAME:SK_DIGGING,\
        SK_PROSPECT_NAME:SK_PROSPECT,\
        SK_LUCK_NAME:SK_LUCK,\
        SK_FLIPPING_NAME:SK_FLIPPING,\
        SK_ARMOURSMITHING_NAME:SK_ARMOURSMITHING,\
        SK_HERBALLORE_NAME: SK_HERBALLORE,\
        SK_SENSE_NAME: SK_SENSE,\
        SK_JEWELRY_NAME: SK_JEWELRY,\
        SK_BAKING_NAME: SK_BAKING,\
        SK_BUTCHER_NAME: SK_BUTCHER,\
        SK_READ_NAME: SK_READ,\
        ])

#define SK_MAXSKILL 10000

#define IS_VALID_SKILL(sk) (member( ({SK_SEWING, SK_TANNING, SK_DIGGING, \
        SK_PROSPECT, SK_LUCK, SK_FLIPPING, SK_ARMOURSMITHING, \
        SK_HERBALLORE, SK_SENSE, SK_JEWELRY, SK_BAKING, SK_BUTCHER, SK_READ,\
        }), sk) != -1)

#define P_EXTERNAL_SKILLS "external_skills"
#define P_SKILL_MOD "skill_mod"

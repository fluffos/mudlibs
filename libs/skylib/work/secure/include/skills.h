/**
 * The main skills header file.  This contains the skill tree and any bits
 * relating to the skill tree.
 * @author Pinkfish
 * @see /std/skills.c
 * @see /std/living/skills.c
 */
#ifndef __SYS__SKILLS
/** @ignore yes */
#define __SYS__SKILLS

/** The index corresponding to the skill name in the skill array. */
#define SKILL_NAM 0
/** The index corresponding to the skill level in the skill array. */
#define SKILL_LVL 1
/** The index corresponding to the skill exp in the skill array. */
#define SKILL_EXP 2
/** The index corresponding to the array of sub skills in the skill array. */
#define SKILL_BIT 3
/** The size of the skill array. */
#define SKILL_ARR_SIZE 4
/** The maximum level that you can teach someone else too. */
#define SKILL_MAX_TEACH 600

/*
 * These are used in /std/living/skills.c for the training/learning of skills.
 */
/** @ignore yes */
#define O_SKILL 0
/** @ignore yes */
#define O_NUM 1
/** @ignore yes */
#define O_LVL 2
/** @ignore yes */
#define O_XP 3
/** @ignore yes */
#define O_OTHER_PER 4

/** @ignore yes */
#define STD_SKILLS_1 ({ \
        "covert", 0, 0, ({ \
            "stealth", 0, 0, ({ \
                "inside", 0, 0, ({ }), \
                "outside", 0, 0, ({ }), \
                "underwater", 0, 0, ({ }), \
            }), \
            "hiding", 0, 0, ({ \
               "person", 0, 0, ({ }), \
               "object", 0, 0, ({ }), \
            }), \
            "lockpick", 0, 0, ({ \
                "doors", 0, 0, ({ }), \
                "safes", 0, 0, ({ }), \
                "traps", 0, 0, ({ }), \
            }), \
            "manipulation", 0, 0, ({ \
                "sleight-of-hand", 0, 0, ({ }), \
                "stealing", 0, 0, ({ }), \
            }), \
            "casing", 0, 0, ({ \
                "person", 0, 0, ({ }), \
                "place", 0, 0, ({ }), \
            }), \
            "items", 0, 0, ({ \
                "poisons", 0, 0, ({ }), \
                "traps", 0, 0, ({ }), \
                "weapons", 0, 0, ({ }), \
            }), \
        }), \
        "crafts", 0, 0, ({ \
            "smithing", 0, 0, ({ \
                "jewellery", 0, 0, ({ }), \
                "black", 0, 0, ({ \
                    "tools", 0, 0, ({ }), \
                    "weapons", 0, 0, ({ }), \
                    "armour", 0, 0, ({ }), \
                }), \
                "sharpening", 0, 0, ({ \
                    "sharp", 0, 0, ({ }), \
                    "pierce", 0, 0, ({ }), \
                }), \
                "decorating", 0, 0, ({ \
                    "engraving", 0, 0, ({ }), \
                    "inlaying", 0, 0, ({ }), \
                    "insetting", 0, 0, ({ }), \
                }), \
                "examining", 0, 0, ({ \
                    "temperature", 0, 0, ({ }), \
                    "edge", 0, 0, ({ }), \
                    "composition", 0, 0, ({ }), \
                }), \
            }), \
            "carpentry", 0, 0, ({ \
                "furniture", 0, 0, ({ }), \
                "weapons", 0, 0, ({ }), \
                "coopering", 0, 0, ({ }), \
                "turning", 0, 0, ({ }), \
                "whittling", 0, 0, ({ }), \
            }), \
            "pottery", 0, 0, ({ \
                "forming", 0, 0, ({ \
                    "throwing", 0, 0, ({ }), \
                    "shaping", 0, 0, ({ }), \
                }), \
                "glazing", 0, 0, ({ }), \
                "firing", 0, 0, ({ }), \
            }), \
            "materials", 0, 0, ({ \
                "tanning", 0, 0, ({ }), \
                "weaving", 0, 0, ({ }), \
                "sewing", 0, 0, ({ }), \
                "skinning", 0, 0, ({ }), \
                "spinning", 0, 0, ({ }), \
            }), \
        }), \
        "faith", 0, 0, ({ \
            "rituals", 0, 0, ({ \
                "offensive", 0, 0, ({ \
                    "area", 0, 0, ({ }), \
                    "target", 0, 0, ({ }), \
                }), \
                "defensive", 0, 0, ({ \
                    "area", 0, 0, ({ }), \
                    "self", 0, 0, ({ }), \
                    "target", 0, 0, ({ }), \
                }), \
                "curing", 0, 0, ({ \
                    "self", 0, 0, ({ }), \
                    "target", 0, 0, ({ }), \
                }), \
                "misc", 0, 0, ({ \
                    "area", 0, 0, ({ }), \
                    "self", 0, 0, ({ }), \
                    "target", 0, 0, ({ }), \
                }), \
                "special", 0, 0, ({ }), \
            }), \
            "items", 0, 0, ({ \
                "rod", 0, 0, ({ }), \
                "scroll", 0, 0, ({ }), \
            }), \
        }), \
    })
/** @ignore yes */
#define STD_SKILLS_2 ({ \
        "fighting", 0, 0, ({ \
            "combat", 0, 0, ({ \
                "melee", 0, 0, ({ \
                    "sharp", 0, 0, ({ }), \
                    "pierce", 0, 0, ({ }), \
                    "blunt", 0, 0, ({ }), \
                    "unarmed", 0, 0, ({ }), \
                }), \
                "range", 0, 0, ({ \
                    "thrown", 0, 0, ({ }), \
                    "fired", 0, 0, ({ }), \
                }), \
                "parry", 0, 0, ({ \
                    "melee", 0, 0, ({ }), \
                    "range", 0, 0, ({ }), \
                }), \
                "dodging", 0, 0, ({ \
                    "melee", 0, 0, ({ }), \
                    "range", 0, 0, ({ }), \
                }), \
                "special", 0, 0, ({ \
                    "weapon", 0, 0, ({ }), \
                    "unarmed", 0, 0, ({ }), \
                    "tactics", 0, 0, ({ }), \
              }), \
            }), \
        }), \
        "magic", 0, 0, ({ \
            "spells", 0, 0, ({ \
                "offensive", 0, 0, ({ }), \
                "defensive", 0, 0, ({ }), \
                "misc", 0, 0, ({ }), \
                "special", 0, 0, ({ }), \
            }), \
            "methods", 0, 0, ({ \
                "elemental", 0, 0, ({ \
                    "air", 0, 0, ({ }), \
                    "earth", 0, 0, ({ }), \
                    "fire", 0, 0, ({ }), \
                    "water", 0, 0, ({ }), \
                }), \
                "mental", 0, 0, ({ \
                    "animating", 0, 0, ({ }), \
                    "channeling", 0, 0, ({ }), \
                    "charming", 0, 0, ({ }), \
                    "convoking", 0, 0, ({ }), \
                    "cursing", 0, 0, ({ }), \
                }), \
                "physical", 0, 0, ({ \
                    "binding", 0, 0, ({ }), \
                    "brewing", 0, 0, ({ }), \
                    "chanting", 0, 0, ({ }), \
                    "dancing", 0, 0, ({ }), \
                    "enchanting", 0, 0, ({ }), \
                    "evoking", 0, 0, ({ }), \
                    "healing", 0, 0, ({ }), \
                    "scrying", 0, 0, ({ }), \
                }), \
                "spiritual", 0, 0, ({ \
                    "abjuring", 0, 0, ({ }), \
                    "banishing", 0, 0, ({ }), \
                    "conjuring", 0, 0, ({ }), \
                    "divining", 0, 0, ({ }), \
                    "summoning", 0, 0, ({ }), \
                }), \
            }), \
            "items", 0, 0, ({ \
                "held", 0, 0, ({ \
                    "wand", 0, 0, ({ }), \
                    "rod", 0, 0, ({ }), \
                    "staff", 0, 0, ({ }), \
                    "broom", 0, 0, ({ }), \
                }), \
                "worn", 0, 0, ({ \
                    "amulet", 0, 0, ({ }), \
                    "ring", 0, 0, ({ }), \
                }), \
                "scroll", 0, 0, ({ }), \
                "talisman", 0, 0, ({ }), \
            }), \
        }), \
    })
/** @ignore yes */
#define STD_SKILLS_GENERAL ({ \
        "general", 0, 0, ({ \
            "tracking", 0, 0, ({ }), \
            "swimming", 0, 0, ({ }), \
            "riding", 0, 0, ({ \
                 "horse", 0, 0, ({ }), \
                 "camel", 0, 0, ({ }), \
            }), \
            "climbing", 0, 0, ({ \
                 "tree", 0, 0, ({ }), \
                 "rock", 0, 0, ({ }), \
                 "rope", 0, 0, ({ }), \
            }), \
            "valueing", 0, 0, ({ \
                "gems", 0, 0, ({ }), \
                "jewellery", 0, 0, ({ }), \
                "weapons", 0, 0, ({ }), \
                "armour", 0, 0, ({ }), \
                "clothing", 0, 0, ({ }), \
                "misc", 0, 0, ({ }), \
            }), \
            "evaluating", 0, 0, ({ \
                "weapons", 0, 0, ({ }), \
                "armour", 0, 0, ({ }), \
            }), \
            "perception", 0, 0, ({ }), \
            "direction", 0, 0, ({ }), \
            "health", 0, 0, ({ }), \
            "points", 0, 0, ({ }), \
        }), \
    })
/**
 * The complete standard skill tree.  This should be avoided being used
 * if possible.
 * @see /std/skills.c
 * @see /std/living/skills.c
 */
#define STD_SKILLS ( STD_SKILLS_1 + STD_SKILLS_2 + STD_SKILLS_GENERAL )

#endif /* __SYS__SKILLS */

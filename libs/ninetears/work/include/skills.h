#define SKILL_NAM 0
#define SKILL_LVL 1
#define SKILL_EXP 2
#define SKILL_BIT 3
#define SKILL_ARR_SIZE 4
#define SKILL_OB "/std/skills"
#define COST_DIV 10

/*
 * These are used in /std/living/skills.c for the training/learning of skills.
 * The skilltree, or just the base of it, the rest is added upon needs
 * Instead of a global skilltree, we will have a skilltree for ever player.
 * Baldrick, july '95.
 */
#define O_SKILL 0
#define O_NUM 1
#define O_LVL 2
#define O_XP 3
#define O_OTHER_PER 4
#define DEFAULT_COST 500
#define DEFAULT_XP_COST 2000
#define STD_SKILLS ({ \
  "str", 0, 0, ({ \
  }), \
  "dex", 0, 0, ({ \
  }), \
  "con", 0, 0, ({ \
  }), \
  "int", 0, 0, ({ \
  }), \
  "wis", 0, 0, ({ \
  }), \
  "cha", 0, 0, ({ \
  }), \
}) 

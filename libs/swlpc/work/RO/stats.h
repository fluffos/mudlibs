/*
 * This file is (now) a bit of a hack
 */

/* nosave array stat_names = [ "con", "str", "siz", "san", "pow", "int", "dex", "chu" ]; */

#define      STATNAMES [ "wis", "con", "str", "siz", "san", "pow", "int", "dex", "chu" ]

#define STATINCR  [ "wise", "robust", "strong", "large", "sane", "wise", "smart", "agile", "cool" ]
#define STATDECR  [ "foolish", "wimpy", "weak", "small", "insane", "foolish", "stupid", "clumsy", "dorkish" ]

/* used internally by living */

#define POW (index(STATNAMES, "pow"))


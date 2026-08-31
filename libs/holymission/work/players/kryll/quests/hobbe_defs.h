#ifndef __HOBBE_DEFS_H__

#define __HOBBE_DEFS_H__

#define HOBBE_DIR        "/players/kryll/quest/hobbe/"

#define HOBBE_ITEM1      HOBBE_DIR + "maul"
#define HOBBE_ITEM2      HOBBE_DIR + "axe"
#define HOBBE_ITEM3      HOBBE_DIR + "oil"
#define HOBBE_ITEM4      HOBBE_DIR + "rope"
#define HOBBE_ITEM5      HOBBE_DIR + "scroll"

#define HOBBE_CAUSE1     "boulder:maul"
#define HOBBE_CAUSE2     "tree:axe"
#define HOBBE_CAUSE3     "branch:axe"
#define HOBBE_CAUSE4     "rope:rope"
#define HOBBE_CAUSE5     "rust:oil"
#define HOBBE_CAUSE6     "spell:scroll"

#define HOBBE_LOCATION1  HOBBE_DIR + "path2"
#define HOBBE_LOCATION2  HOBBE_DIR + "path3"
#define HOBBE_LOCATION3  HOBBE_DIR + "path4"
#define HOBBE_LOCATION4  HOBBE_DIR + "mill"
#define HOBBE_LOCATION5  HOBBE_DIR + "pond"
#define HOBBE_LOCATION6  HOBBE_DIR + "path5"
#define HOBBE_LOCATION7  HOBBE_DIR + "path1"
#define HOBBE_LOCATION8  HOBBE_DIR + "upstairs"
#define HOBBE_LOCATION9  HOBBE_DIR + "cellar"
#define HOBBE_LOCATION10 HOBBE_DIR + "under_bridge"
#define HOBBE_LOCATION11 HOBBE_DIR + "down_path"

#define HOBBE_CAUSE1_IDS ({ "boulder", "rock", "large boulder" })
#define HOBBE_CAUSE2_IDS ({ "tree", "log", "large tree" })
#define HOBBE_CAUSE3_IDS ({ "branch", "stuck branch", "branch stuck" })
#define HOBBE_CAUSE4_IDS ({ "rope", "ropes", "broken rope" })
#define HOBBE_CAUSE5_IDS ({ "rods", "iron rods", "rust", "rusted", "oil" })
#define HOBBE_CAUSE6_IDS ({ "nothing", "nothing moving" })

#define HOBBE_CAUSE1_DESC "A large boulder is blocking the flow of the "\
  "stream. It looks like it would be too heavy to lift out of the way."
#define HOBBE_CAUSE2_DESC "A large tree has fallen, blocking the flow "\
  "of water. It looks much too heavy to move out of the way."
#define HOBBE_CAUSE3_DESC "There appears to be a branch stuck in the "\
  "wheel. It does not look like it will budge."
#define HOBBE_CAUSE4_DESC "One of the ropes attached to the millstone "\
  "have broken. It looks like it will have to be replaced."
#define HOBBE_CAUSE5_DESC "Some of the iron rods connected to the "\
  "millstone have rusted. It looks like some oil is needed to help the "\
  "millstone move again."
#define HOBBE_CAUSE6_DESC "Nothing appears wrong here, except that "\
  "absolutely nothing is moving!"

#endif // __HOBBE_DEFS_H__

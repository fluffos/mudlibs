#ifndef __SKILLS_H__
#define __SKILLS_H__

///////////////////////////////////////////////////////////////////////////
// List all skills in categories here

#define COMBAT_SKILLS ({"attack","defense","double wielding","two handed","melee"})
#define WEAPON_SKILLS ({"axe","bow","club","knife","staff","spear","sword","whip"})
#define MAGIC_SKILLS ({"healing","attack magic","defense magic","illusion","conjuring","faith"})
#define NATURE_SKILLS ({"survival","climbing","riding","swimming","hunting","fishing"})
#define DECEPTION_SKILLS ({"stealing","stealth","bargaining"})
#define SCIENCE_SKILLS ({"medicine","navigation","alchemy","botany","languages"})

///////////////////////////////////////////////////////////////////////////
// Gender Adjustments

#define MALE_GREAT_SKILLS ({"hunting"})
#define MALE_GOOD_SKILLS ({"riding","climbing"})
#define MALE_BAD_SKILLS ({"faith","conjuring","attack magic","defense magic"})
#define MALE_TERRIBLE_SKILLS ({"healing","stealth","bargaining"})

#define FEMALE_GREAT_SKILLS ({"bargaining"})
#define FEMALE_GOOD_SKILLS ({"swimming","medicine"})
#define FEMALE_BAD_SKILLS ({"sword","spear","attack","two handed"})
#define FEMALE_TERRIBLE_SKILLS ({"club","axe","melee"})

///////////////////////////////////////////////////////////////////////////
// Class Adjustments

#define HEALER_GREAT_SKILLS ({"defense magic","healing","riding","swimming","hunting","fishing","medicine","climbing"})
#define HEALER_GOOD_SKILLS ({"attack magic","conjuring","melee","faith","bargaining"})
#define HEALER_AVG_SKILLS ({"attack","defense","double wielding","two handed","staff"})
#define HEALER_BAD_SKILLS ({"axe","bow","club","knife","spear","sword","whip"})
#define HEALER_TERRIBLE_SKILLS ({"stealing","stealth"})

#define MAGE_GREAT_SKILLS ({"attack magic","defense magic","conjuring"})
#define MAGE_GOOD_SKILLS ({"healing","faith","bargaining","riding","swimming","hunting","fishing","climbing"})
#define MAGE_AVG_SKILLS ({"attack","defense","double wielding","two handed","melee","medicine"})
#define MAGE_BAD_SKILLS ({"axe","bow","club","knife","staff","spear","sword","whip"})
#define MAGE_TERRIBLE_SKILLS ({"stealing","stealth"})

#define MONK_GREAT_SKILLS ({"attack","defense","melee","faith"})
#define MONK_GOOD_SKILLS ({"axe","bow","club","knife","staff","spear","sword","whip","double wielding","two handed","medicine","climbing"})
#define MONK_AVG_SKILLS ({"defense magic","healing","bargaining","riding","swimming","hunting","fishing"})
#define MONK_BAD_SKILLS ({"attack magic","conjuring"})
#define MONK_TERRIBLE_SKILLS ({"stealing","stealth"})

#define FIGHTER_GREAT_SKILLS ({"attack","defense","double wielding","two handed"})
#define FIGHTER_GOOD_SKILLS ({"axe","bow","club","knife","staff","spear","sword","whip"})
#define FIGHTER_AVG_SKILLS ({"healing","bargaining","riding","swimming","hunting","fishing","climbing"})
#define FIGHTER_BAD_SKILLS ({"attack magic","defense magic","conjuring","melee","faith","medicine"})
#define FIGHTER_TERRIBLE_SKILLS ({"stealing","stealth"})

///////////////////////////////////////////////////////////////////////////
// Race Adjustments

#define HUMAN_GOOD_SKILLS ({"bargaining","stealth"})
#define HUMAN_BAD_SKILLS ({"conjuring","healing"})

#define ELF_GOOD_SKILLS ({"attack magic","defense magic","conjuring","swimming"})
#define ELF_BAD_SKILLS ({"two handed","double wielding"})

#define FAIRY_GOOD_SKILLS ({"attack magic","defense  magic","defense","climbing"})
#define FAIRY_BAD_SKILLS ({"attack","sword","axe","staff"})

#define GNOME_GOOD_SKILLS ({"conjuring","attack magic","defense magic"})
#define GNOME_BAD_SKILLS ({"stealth","stealing"})

#define GIANT_GOOD_SKILLS ({"attack","defense","sword","club"})
#define GIANT_BAD_SKILLS ({"attack magic","defense magic","conjuring","healing"})

#define DWARF_GOOD_SKILLS ({"attack","defense"})
#define DWARF_BAD_SKILLS ({"attack magic","defense magic"})


///////////////////////////////////////////////////////////////////////////
// MISC

#define ALL_SKILLS COMBAT_SKILLS+WEAPON_SKILLS+MAGIC_SKILLS+NATURE_SKILLS+DECEPTION_SKILLS+SCIENCE_SKILLS

#endif


/* compiled by Blitz@Dead Souls and Mikla@Dead Souls */

// The SOBER_COMBAT define is intended to make combat messages a
// bit less emo. The problem with the original combat messages is
// that if you have, say, two robots fighting, it's weird and 
// jarring to see them foaming at the mouth or grunting angrily.
// Just remove the define for the old-style behavior, if you want
// the bellowing and ranting back. -Crat 05Nov2007

#define SOBER_COMBAT

#ifndef SOBER_COMBAT

#define MOVE_TYPES ({\
({ "feint deceptively", "feints deceptively" }),\
({ "dance around", "dances around" }),\
({ "lunge quickly", "lunges quickly" }),\
({ "duck low", "ducks low" }),\
({ "move fast", "moves fast" }),\
({ "strike rapidly", "strikes rapidly" }),\
({ "sidestep nimbly", "sidesteps nimbly" }),\
({ "growl menacingly", "growls menacingly" }),\
({ "grin sadistically", "grins sadistically" }),\
({ "grunt angrily", "grunts angrily" }),\
({ "bellow loudly", "bellows loudly" }),\
({ "swing blindly", "swings blindly" }),\
({ "shout profanities", "shouts profanities" }),\
({ "swell with ferocity", "swells with ferocity" }),\
({ "rally with determination", "rallies with determination" }),\
({ "spit derisively", "spits derisively" }),\
({ "glare contemptuously", "glares contemptuously" }),\
({ "stumble fortuitously", "stumbles fortuitously" }),\
({ "scream, \"Die!\"", "screams, \"Die!\"" }),\
({ "foam at the mouth", "foams at the mouth" }),\
({ "rant, \"Aahrrg!\"", "rants, \"Aahrrg!\"" }),\
({ "execute a diving roll maneuver", "executes a diving roll maneuver" }),\
({ "attack with renewed frenzy", "attacks with renewed frenzy" }),\
({ "yell, \"Look!! Behind you!\"", "yells, \"Look!! Behind you!\"" }),\
({ "go completely berserk", "goes completely berserk" }),\
({ "rage violently", "rages violently" }),\
({ "gyrate energetically", "gyrates energetically" }),\
({ "whirl around quickly", "whirls around quickly" }),\
({ "whirl blurringly", "whirls blurringly" }),\
({ "see an opening", "sees an opening" }),\
({ "do a cunning move", "does a cunning move" }),\
({ "twirl with finesse", "twirls with finesse" }),\
})

#else

#define MOVE_TYPES ({\
({ "feint", "feints" }),\
({ "twist swiftly", "twists swiftly" }),\
({ "lunge quickly", "lunges quickly" }),\
({ "duck", "ducks" }),\
({ "move fast", "moves fast" }),\
({ "strike rapidly", "strikes rapidly" }),\
({ "sidestep", "sidesteps" }),\
({ "gyrate briskly", "gyrates briskly" }),\
({ "whirl around quickly", "whirls around quickly" }),\
({ "whirl blurringly", "whirls blurringly" }),\
})

#endif

 
#define BLADE_DEGREES ({\
({\
({ "%^BOLD%^%^RED%^prick%^RESET%^", "pricks" }),\
({ "lightly", "superficially", "just barely" })\
}),\
({\
({ "%^BOLD%^%^RED%^scratch%^RESET%^", "scratches" }),\
({ "mildly", "barely", })\
}),\
({\
({ "%^BOLD%^%^RED%^jab%^RESET%^", "jabs" }),\
({ "quickly", "meanly", })\
}),\
({\
({ "%^BOLD%^%^RED%^cut%^RESET%^", "cuts" }),\
({ "painfully" }),\
}),\
({\
({ "%^BOLD%^%^RED%^slice%^RESET%^", "slices" }),\
({ "deeply" }),\
}),\
({\
({ "%^BOLD%^%^RED%^pierce%^RESET%^", "pierces" }),\
({ "wickedly" }),\
}),\
({\
({ "%^BOLD%^%^RED%^slash%^RESET%^", "slashes" }),\
({ "expertly" }),\
}),\
({\
({ "%^BOLD%^%^RED%^stab%^RESET%^", "stabs" }),\
({ "fiercely" }),\
}),\
({\
({ "%^BOLD%^%^RED%^carve%^RESET%^", "carves" }),\
({ "to pieces" }),\
}),\
({\
({ "%^BOLD%^%^RED%^cleave%^RESET%^", "cleaves" }),\
({ "cruelly" }),\
}),\
({\
({ "%^BOLD%^%^RED%^wound%^RESET%^", "wounds" }),\
({ "greviously" }),\
}),\
({\
({ "%^BOLD%^%^RED%^devastate%^RESET%^", "devastates" }),\
({ "completely" }),\
}),\
({\
({ "%^BOLD%^%^RED%^destroy%^RESET%^", "destroys" }),\
({ "utterly", }),\
}),\
})
 
#define PROJECTILE_DEGREES ({\
({\
({ "%^BOLD%^%^RED%^prick%^RESET%^", "pricks" }),\
({ "lightly", "superficially", "just barely" })\
}),\
({\
({ "%^BOLD%^%^RED%^scratch%^RESET%^", "scratches" }),\
({ "mildly", "barely", }),\
}),\
({\
({ "%^BOLD%^%^RED%^graze%^RESET%^", "grazes" }),\
({ "sharply" }),\
}),\
({\
({ "%^BOLD%^%^RED%^gash%^RESET%^", "gashes" }),\
({ "deeply" }),\
}),\
({\
({ "%^BOLD%^%^RED%^tear%^RESET%^", "tears" }),\
({ "painfully" }),\
}),\
({\
({ "%^BOLD%^%^RED%^pierce%^RESET%^", "pierces" }),\
({ "wickedly" }),\
}),\
({\
({ "%^BOLD%^%^RED%^shear%^RESET%^", "shears" }),\
({ "to ribbons" }),\
}),\
({\
({ "%^BOLD%^%^RED%^puncture%^RESET%^", "punctures" }),\
({ "deeply", "with a quick thrust" }),\
}),\
({\
({ "%^BOLD%^%^RED%^rip%^RESET%^", "rips" }),\
({ "apart", "to pieces" }),\
}),\
({\
({ "%^BOLD%^%^RED%^impale%^RESET%^", "impales" }),\
({ "without mercy" }),\
}),\
({\
({ "%^BOLD%^%^RED%^wound%^RESET%^", "wounds" }),\
({ "greviously" }),\
}),\
({\
({ "%^BOLD%^%^RED%^devastate%^RESET%^", "devastates" }),\
({ "completely" }),\
}),\
({\
({ "%^BOLD%^%^RED%^destroy%^RESET%^", "destroys" }),\
({ "utterly" }),\
}),\
})
 
#define BLUNT_DEGREES ({\
({\
({ "%^BOLD%^%^RED%^brush%^RESET%^", "brushes" }),\
({ "lightly", "softly", "with little force" }),\
}),\
({\
({ "%^BOLD%^%^RED%^bruise%^RESET%^", "bruises" }),\
({ "mildly" }),\
}),\
({\
({ "%^BOLD%^%^RED%^hit%^RESET%^", "hits" }),\
({ "hard" }),\
}),\
({\
({ "%^BOLD%^%^RED%^pound%^RESET%^", "pounds" }),\
({ "solidly" }),\
}),\
({\
({ "%^BOLD%^%^RED%^hammer%^RESET%^", "hammers" }),\
({ "painfully" }),\
}),\
({\
({ "%^BOLD%^%^RED%^pummel%^RESET%^", "pummels" }),\
({ "soundly" }),\
}),\
({\
({ "%^BOLD%^%^RED%^thrash%^RESET%^", "thrashes" }),\
({ "viciously" }),\
}),\
({\
({ "%^BOLD%^%^RED%^smash%^RESET%^", "smashes" }),\
({ "forcefully" }),\
}),\
({\
({ "%^BOLD%^%^RED%^crush%^RESET%^", "crushes" }),\
({ "violently" }),\
}),\
({\
({ "%^BOLD%^%^RED%^slam%^RESET%^", "slams" }),\
({ "powerfully" }),\
}),\
({\
({ "%^BOLD%^%^RED%^wound%^RESET%^", "wounds" }),\
({ "greviously" }),\
}),\
({\
({ "%^BOLD%^%^RED%^devastate%^RESET%^", "devastates", }),\
({ "completely" }),\
}),\
({\
({ "%^BOLD%^%^RED%^destroy%^RESET%^", "destroys" }),\
({ "utterly" }),\
}),\
})

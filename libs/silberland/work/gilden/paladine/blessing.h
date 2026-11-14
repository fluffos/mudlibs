#ifndef _PALA_BLESSING_H
#define _PALA_BLESSING_H

#define BLESSING_BLAZING_GAZE    0 // done
#define BLESSING_GLIMMER_OF_HOPE 1 // done
#define BLESSING_COURAGE         2 // done
#define BLESSING_REBUKE          3 // done
#define BLESSING_HEALING_HANDS   4 // done
#define BLESSING_ANATHEMA        5 // done
#define BLESSING_PROTECTOR       6 // noch offen und inaktiv - implementierung fraglich
#define BLESSING_VITALITY        7 // done
#define BLESSING_HOLY_ARMOUR     8 // done
#define BLESSING_BLESSED_BLADE   9 // done
#define BLESSING_RESTORATION     10 // done 
#define BLESSING_REVELATION      11 // done
#define BLESSING_HARRIER         12 // done
#define BLESSING_CLEANSING       13 // noch offen und inaktiv - implementierung fraglich
#define BLESSING_PUNISHMENT      14 // done
#define BLESSING_INNER_FIRE      15 // done
#define BLESSING_UNUSED_1        16 // offen fuer talisman
#define BLESSING_SHIELD_OF_FAITH 17 // done
#define BLESSING_ANGELIC_AURA    18 // done
#define BLESSING_STEADFASTNESS   19 // done
#define MAX_TALENT_NR 20

#define P_TMP_PALADINE_BLAZING_GAZE    "tmp_paladine_blazing_gaze" // merkt sich im paladin wer zuletzt durchleuchtet wurde
#define P_TMP_PALADINE_LAST_REBUKE     "tmp_paladine_last_rebuke" // damit wir einen gegner mit verbannung nicht komplett laehmen
#define P_TMP_PALADINE_ANATHEMA        "tmp_paladine_anathema" // verhindert doppeltes anathema
#define P_TMP_PALADINE_REVELATION_END  "tmp_paladine_revelation_end" // letzte meditation mit offenbarung
#define P_TMP_PALADINE_LAST_SMITE      "tmp_paladine_last_smite" // damit merken wir uns im opfer wann der letzte smite/divine punishment effekt kam

#define ID_BLESSING_IMPROVED           "\npaladin_blessing_improved" // markiert waffen und ruestungen die verbessert wurden
#define ID_BLESSING_ANGEL           "\npaladin_angelic_aura" // markiert waffen und ruestungen die verbessert wurden

#define BLESSING_GROUP_1 ({BLESSING_BLAZING_GAZE, BLESSING_GLIMMER_OF_HOPE, BLESSING_COURAGE, BLESSING_REBUKE, BLESSING_HEALING_HANDS})
#define BLESSING_GROUP_2 ({BLESSING_ANATHEMA, BLESSING_VITALITY, BLESSING_HOLY_ARMOUR})
#define BLESSING_GROUP_3 ({BLESSING_BLESSED_BLADE, BLESSING_RESTORATION, BLESSING_REVELATION, BLESSING_HARRIER})
#define BLESSING_GROUP_4 ({BLESSING_PUNISHMENT, BLESSING_INNER_FIRE})
#define BLESSING_GROUP_5 ({BLESSING_SHIELD_OF_FAITH, BLESSING_ANGELIC_AURA, BLESSING_STEADFASTNESS})
#define BLESSING_GROUPS ({BLESSING_GROUP_1, BLESSING_GROUP_2, BLESSING_GROUP_3, BLESSING_GROUP_4, BLESSING_GROUP_5})

#define BLESSING_NAMES ({"Lodernder Blick", "Hoffnungsschimmer", "Tapferkeit", "Schelte", "Heilende Haende", \
                         "Anathema", 0, "Vitalitaet", "Heilige Wehr", "Geweihte Klinge", "Widerherstellung", \
                         "Offenbarung", "Bodenweihe", 0, "Goettliche Strafe", "Inneres Feuer", 0, \
                         "Schild des Glaubens", "Engelsgleiche Aura", "Standhaftigkeit"})

#define HAS_BLESSING(x, y) call_other("/gilden/paladine/master/talentmaster", "HasTalent", x, y)
#define BLESSING_POWER(x) 1.0
#endif
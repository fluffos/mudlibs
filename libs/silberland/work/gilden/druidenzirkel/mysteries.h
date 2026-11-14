#ifndef _DRUID_MYSTERIES_H
#define _DRUID_MYSTERIES_H

#define MYSTERY_ELEMENTAL_WRATH 0 // done
#define MYSTERY_HARMONIZED_AURA 1
#define MYSTERY_ELEMENTAL_ADJUSTMENT 2 // done
#define MYSTERY_ELEMENTAL_RESISTANCE 3 // done
#define MYSTERY_SPECIALISATION 4 // done
#define MYSTERY_MASTER_SORCERER 5 // done
#define MYSTERY_MINOR_ELEMENTAL 6
#define MYSTERY_FORCE_TRANSFORMATOR 7 // done

#define MYSTERY_POWER_OF_THE_SOIL 8 // done
#define MYSTERY_THORNS 9 // done
#define MYSTERY_PLANT_GROWTH 10
#define MYSTERY_NATURAL_HEALING 11 // done
#define MYSTERY_GROW_ROOTS 12 // done
#define MYSTERY_LIFELINK 13 // done
#define MYSTERY_POISIONOUS_THORNS 14 // done
#define MYSTERY_SPORES 15 // done

#define MYSTERY_HOT_FUSION 16 // done
#define MYSTERY_IGNITE 17 // done
#define MYSTERY_SPARKS 18 // done
#define MYSTERY_HOT_SPOTS 19 // done
#define MYSTERY_PYROCLASM 20
#define MYSTERY_SHOCKWAVE 21 // Done
#define MYSTERY_HEAT_ADJUSTED 22 // done
#define MYSTERY_FLAMEGHOST 23 // done

#define MYSTERY_COLD_FUSION 24 // done
#define MYSTERY_FREEZE 25 // done
#define MYSTERY_ICICLES 26 // done
#define MYSTERY_FROZEN_HEART 27 // done
#define MYSTERY_COLD_ADJUSTMENT 28 // done
#define MYSTERY_RIME 29 // done
#define MYSTERY_COLD_POLE 30
#define MYSTERY_SNOW_LAYER 31 // done

#define MYSTERY_BODY_OF_STONE 32 // dome
#define MYSTERY_IRON_AURA 33 // done
#define MYSTERY_SHATTERING_STRIKES 34 // done
#define MYSTERY_PHYSICAL_SPELLS 35 // done
#define MYSTERY_SPELL_PENENTRATION 36 // done
#define MYSTERY_WALL_OF_STONE 37 // done
#define MYSTERY_PETRIFICATION 38 // done
#define MYSTERY_MAGNETISM 39

#define MYSTERY_WATERBREATH 40 // done
#define MYSTERY_REFRESHING_CURRENT 41 // done
#define MYSTERY_DROWN 42 // done
#define MYSTERY_FIND_WEAKNESS 43 // done
#define MYSTERY_BE_LIKE_WATER 44 // done
#define MYSTERY_RAIN 45 // done
#define MYSTERY_SHIFTING_CURRENTS 46 // done
#define MYSTERY_WATERSPELL 47

#define MYSTERY_BREATHING_TECHNIQUE 48 // done
#define MYSTERY_WEATHER_MASTERY 49 // done
#define MYSTERY_GLIDE 50 // done
#define MYSTERY_WINDGHOSTS 51 // done
#define MYSTERY_STORM_STRIKES 52 // done
#define MYSTERY_UPWIND 53
#define MYSTERY_DUSTSPRAY 54 // done
#define MYSTERY_STORMSPELL 55

#define MAX_TALENT_NR 55

#define MYSTERY_GROUP_MISC ({MYSTERY_ELEMENTAL_WRATH, MYSTERY_HARMONIZED_AURA, MYSTERY_ELEMENTAL_ADJUSTMENT, MYSTERY_ELEMENTAL_RESISTANCE, MYSTERY_SPECIALISATION, MYSTERY_MASTER_SORCERER, MYSTERY_MINOR_ELEMENTAL, MYSTERY_FORCE_TRANSFORMATOR})
#define MYSTERY_GROUP_HUMUS ({MYSTERY_POWER_OF_THE_SOIL, MYSTERY_THORNS, MYSTERY_PLANT_GROWTH, MYSTERY_NATURAL_HEALING, MYSTERY_GROW_ROOTS, MYSTERY_LIFELINK, MYSTERY_POISIONOUS_THORNS, MYSTERY_SPORES})
#define MYSTERY_GROUP_FIRE ({MYSTERY_HOT_FUSION, MYSTERY_IGNITE, MYSTERY_SPARKS, MYSTERY_HOT_SPOTS, MYSTERY_PYROCLASM, MYSTERY_SHOCKWAVE, MYSTERY_HEAT_ADJUSTED, MYSTERY_FLAMEGHOST})
#define MYSTERY_GROUP_ICE ({MYSTERY_COLD_FUSION, MYSTERY_FREEZE, MYSTERY_ICICLES, MYSTERY_FROZEN_HEART, MYSTERY_COLD_ADJUSTMENT, MYSTERY_RIME, MYSTERY_COLD_POLE, MYSTERY_SNOW_LAYER})
#define MYSTERY_GROUP_STONE ({MYSTERY_BODY_OF_STONE, MYSTERY_IRON_AURA, MYSTERY_SHATTERING_STRIKES, MYSTERY_PHYSICAL_SPELLS, MYSTERY_SPELL_PENENTRATION, MYSTERY_WALL_OF_STONE, MYSTERY_PETRIFICATION, MYSTERY_MAGNETISM})
#define MYSTERY_GROUP_WATER ({MYSTERY_WATERBREATH, MYSTERY_REFRESHING_CURRENT, MYSTERY_DROWN, MYSTERY_FIND_WEAKNESS, MYSTERY_BE_LIKE_WATER, MYSTERY_RAIN, MYSTERY_SHIFTING_CURRENTS, MYSTERY_WATERSPELL})
#define MYSTERY_GROUP_AIR ({MYSTERY_BREATHING_TECHNIQUE, MYSTERY_WEATHER_MASTERY, MYSTERY_GLIDE, MYSTERY_WINDGHOSTS, MYSTERY_STORM_STRIKES, MYSTERY_UPWIND, MYSTERY_DUSTSPRAY, MYSTERY_STORMSPELL})
#define ELEMENT_MYSTERY_MAP (["eis": MYSTERY_GROUP_ICE, "geist": MYSTERY_GROUP_HUMUS + MYSTERY_GROUP_FIRE + MYSTERY_GROUP_ICE + MYSTERY_GROUP_STONE + MYSTERY_GROUP_WATER + MYSTERY_GROUP_AIR, \
                               "humus": MYSTERY_GROUP_HUMUS, "feuer": MYSTERY_GROUP_FIRE, "erz": MYSTERY_GROUP_STONE, "wasser": MYSTERY_GROUP_WATER, "luft": MYSTERY_GROUP_AIR])

#define MYSTERY_NAMES ({"Zorn der Elemente", 0, "Elementare Gewoehnung", "Elementarer Widerstand", "Tiefere Geheimnisse", "Meister der Zauberei", 0, "Wandlung der Kraefte",\
                         "Kraft der Erde", "Dornenranken", 0, "Heilkraft der Natur", "Wurzeln schlagen", "Lebensraub", "Giftige Dornen", "Sporen und Pollenflug", \
                         "Heisse Fusion", "Entzuenden", "Funkenflug", "Glutnester", 0, "Druckwelle", "Hitzegewoehnung", "Geist der Flammen", \
                         "Kalte Fusion", "Glatteis", "Eiszapfen", "Kaltes Herz", "Kaeltegewoehnung", "Raureif", 0, "Schneeschicht",\
                         "Koerper aus Fels", "Eisenaffine Aura", "Zertruemmernde Hiebe", "Physische Zauber", "Ueberwinden des Zauberschutzes", "Felsbrocken", "Versteinerung", 0, \
                         "Wasseratem", "Erfrischende Stroemung", "Ertraenken", "Schwaeche Finden", "Sei wie Wasser", "Regen", "Wechselstroemung", 0,\
                         "Atemtechniken", "Wettermeisterschaft", "Gleiten", "Mindere Windgeister", "Stuermische Schlaege", "Aufwind", "Staubwirbel", 0})

#define HAS_MYSTERY(x, y) call_other("/gilden/druidenzirkel/master/talentmaster", "HasTalent", x, y)

#define P_TMP_DRUID_LAST_ELEMENT_SPELLS "tmp_druid_last_element_spell" // merkt sich die elemente der letzten 6 spells fuer MYSTER_FORCE_TRANSFORMATOR
#define P_TMP_DRUID_FT_UNTIL "tmp_druid_force_transform_until" // gibt an bis wann MYSTERY_FORCE_TRANSFORMATOR wirkt
#define P_TMP_DRUID_FT_POTENCY "tmp_druid_force_transform_power" // gibt die staerke der regeneration durch FORCE_TRANSFORMATION an
#define P_TMP_DRUID_ROOTED "tmp_druid__rooted" // markiert einen spieler als verwurzelt mit dem boden
#define P_TMP_DRUID_LAST_ROOT_REGENREATION "tmp_druid_last_root_regeneration" // letzer zeitpunkt der wurzelzusatzregeneration
#define P_LAST_SOIL_REGENERATION "druid_last_soild_regeneration" // letzter zeitpunkt zu dem eine regeneration durch humus erstatt wurde
#define P_LAST_WATER_REGENERATION "druid_last_water_regeneration" // letzter zeitpunkt einer regeneration durch MYSTERY_REFRESHING_CURRENT
#define P_TMP_DRUID_RESISTANCE_PROCC "druid_tmp_resistance_procc" // wenn gesetzt wird beim naechsten treffer eine resistenzaenderung getriggert
#define P_DRUID_LAST_SPELL "druid_last_spell" // zeitpunkt des letzten gezauberten druidenzaubers
#define P_TMP_DRUID_LAST_HIT_ELEMENT "tmp_druid_last_hit_element" // element des letzten zaubers der das ziel getroffen hat
#define P_TMP_DRUID_LAST_HIT "tmp_last_druid_hit_time" // zeitpunkt an dem der npc das letzte mal von einem druidenzauber getroffen wurde

#define TALENTMASTER "/gilden/druidenzirkel/master/talentmaster"

#define ID_STONESLAB "\ndruiden_erz_stoneslab"
#define ID_RAIN "\ndruiden_rain"
#define ID_WEATHERMASTERY "\ndruiden_weathermastery"
#endif
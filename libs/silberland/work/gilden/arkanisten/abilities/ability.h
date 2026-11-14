#ifndef _GUILD_arkanisten_ABILITIES_H
#define _GUILD_arkanisten_ABILITIES_H

#define P_ABILITY_NAME "watcher_ability_name"
#define P_ABILITY_DESCRIPTIPON "watcher_ability_description"
#define P_ABILITY_TYPE "watcher_ability_type"
#define ABILITY_TYPE_ACTIVE 0
#define ABILITY_TYPE_PASSIVE 1
#define P_ABILITY_BASE_ATTRIBUTE "watcher_ability_base_attribute"
#define P_ABILITY_CASTVERB "watcher_ability_castverb"
#define CAST_VERB_ACTIVATE "aktiviere"
#define CAST_VERB_THROW "wirf"
#define CAST_VERB_WIELD "zuecke"
#define CAST_VERB_LOAD "lade"
#define CAST_VERB_INJECT "injiziere"
#define CAST_VERB_DRINK "trinke"
#define P_ABILITY_GROUP "watcher_ability_group"
#define ABILITY_GROUP_GADGETS "werkzeuge"
#define ABILITY_GROUP_ALCHEMY "alchemie"
#define ABILITY_GROUP_STRATEGY "strategie"
#define ABILITY_GROUP_BIOLOGY "biology"
#define ABILITY_GROUP_BOMBS "bomben"
#define ABILITY_GROUP_GADGET_POWERUP "gadget_powerup"
#define P_ABILITY_COST "watcher_ability_cost"
#define P_ABILITY_REQUIRES "watcher_ability_requires"
#define P_ABILITY_SPELLBREAK "watcher_ability_spellbreak"
#define P_ABILITY_MIN_GUILD_LEVEL "watcher_abiltiy_min_level"
#define P_ABILITY_MODIFIES "watcher_ability_modifies"
#define MODIFY_ALL "__all__"

#define SI_ABILITY_OBJECT "si_ability_object"
#define SI_ABILITY_SILENT "si_ability_silent"
#define SI_ABILITY_NOLEARN "si_ability_nolearn"
#define SI_ABILIT_USER "si_ability_user"
#define SI_ABILITY_USER "si_ability_user"
#define SI_ABILITY_USAGE "usage"
#define SI_ABILITY_VALUE "value"
#define SI_ABILITY_SINFO "sinfo"


#define LIGHTBRINGER_COIL "lichtbringerspule"
#define SMOKEBOMB "rauchbombe"
#define HANDCROSSBOW "handkurbelarmbrust"
#define TESLA_BATON "blitzstab"
#define CLOCKWORK_SNARE "uhrwerkschlinge"
#define SPRINGLOADED_GLOVES "federmechanische handschuhe"
#define DEPLOYABLE_SHIELD "ausklappbarer handschild"
#define INFERNO_MODULE "infernomodul"
#define FLAMETHROWER_MODULE "flammenwerfermodul"
#define HIDDEN_DAGGER "versteckte klinge"
#define ASSASSINS_HANDS "haende des assassinen"
#define DOUBLE_SLICE "doppelschlag"
#define MAGNET_GRAPPLE "magnetgriff"
#define TITAN_WRESTLER "riesenringer"
#define CHOKING_HANDS "schraubzwingenfinger"
#define EXPLODING_AMMUNITION "explodierende munition"
#define FLINTLOCK_PISTOL "steinschlosspistole"
#define PISTOLERO_STANCE "zweihand-pistolero technik"
#define CLOCKWORK_ARMOUR "uhrwerkruestung"
#define GYROSCOPIC_STABILIZER "gyroskopischer stabilisator"
#define REINFORCED_BRACES "verstaerkende schienen"
#define CHAIN_LIGHTING_PROJECTOR "kettenblitzprojektor"
#define PULSE_GENERATOR "pulsgenerator"
#define ELECTRIFIED_DEFENSES "elektrifizierte verteidigung"
#define REACTIVE_DEFENSES "reaktive verteidigung"
#define GADGET_OVERDRIVE "uebertaktung"
#define TEMPORAL_DISRUPTOR "zeitverzerrer"

#define QUICK_REMEDY "schnellheilmittel"
#define ADRENALINE_SHOT "stimulanzienspritze"
#define HEALING_TONIC "heiltonikum"
#define MUTAGENIC_ELIXIR "mutagenes elixier"
#define COGNITIVE_MUTAGEN "kognitives mutagen"
#define ANTIDOTE "gegengift"
#define DRAUGHT_OF_THOUGHT "kognitarium"
#define TRANSMUTING_ELIXIR "transmutierendes elixier"
#define ACID_SPLASH "saeureflaeschchen"

#define LIGHTCOIL_ID "\narkanisten_lightcoil"
#define SMOKE_BOMB_ID "\narkanisten_smokebomb"
#define CROSSBOW_ID "\narkanisten_crossbow"
#define TESLA_BATON_ID "\narkanisten_tesla_baton"
#define SPRINGLOADED_GLOVES_ID "\narkanisten_srpingloaded_gloves"
#define MAGNET_GRAPPLE_ID "\narkanisten_mgrapple_user"
#define PISTOL_ID "\narkanisten_flintlock_pistol"
#define CAN_EXPLOSIVE_AMMO_ID "\narkanisten_expl_shot_enabled"
#define PISTOLERO_OFFHAND_ID "\narkanisten_pistol_offhand"
#define CLOCKWORK_ARMOUR_ID "\narkanisten_cw_armour"
#define REINFORCED_BRACES_ID "\narkanisten_reinf_bracers"
#define MUTAGENIC_ELIXIR_ID "\narkanisten_mutagenic_elixir"
#define TRANSMUTING_ELIXIR_ID "\narkanisten_transmuting_elixir"

#define P_WATCHER_LAST_FLAMETHROWER "arkanisten_last_flamethrower"
#define P_WATCHER_ELECTRIC_GLOVES "arkanisten_electric_gloves_time"
#define P_WATCHER_INFERNO_UNTIL "arkanisten_inferno_until"
#define P_WATCHER_EXPLODING_AMMO "arkanisten_exploding_ammo"
#define P_WATCHER_OVERDRIVE_UNTIL "arkanisten_overdrive_until"
#define P_ACTIVE_TEMPORAL_DISRUPTOR "arkanisten_active_temporal_disruptor"
#define P_ARKANIST_HEAL_OVER_TIME "arkanisten_heal_over_time"

#define EVENT_DISPATCH "/gilden/arkanisten/abilities/ability/event_dispatch"
#define EVENT_AFTER_USE 1 // am ende von use()
#define EVENT_AFTER_ATTACK 2 // machdem ein AttackSpell gemacht wurde

#define MODIFY_DAMAGE 0 // schaden veraendern
#define MODIFY_CUSTOM_VALUE 1 // beliebigen wert veraendern. ist in der payload als "usage" und der wert als "value" angegeben.
#define MODIFY_FREE_HAND_CALCULATION 2 // freie haende berechnen
#define MODIFY_SKILLCHECK_RESULT 3 // verändert das skill check ergebnis (NACHDEM success / fail festgestellt wurde)
#define MODIFY_COST 4 // kosten der faehigkeit veraendern
#define MODIFY_PREPARE_TIME 5 // vorbereitungszeit der faehigkeit veraendern

#endif
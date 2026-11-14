//** Ordnerstruktur innerhalb der Gilde ************************************//
//-- Ueberschreiben der Gebiets-defines --------------------------------------
#ifndef GUILD
#define GUILD "waldlaeufer"
#endif
#ifndef GUILD_DIR
#define GUILD_DIR "/gilden/"
#endif
#define GEBIET GUILD "/"
#define RANGER_DIR GUILD_DIR GEBIET
#define RANGER RANGER_DIR
#ifndef ZONE 
#define ZONE  RANGER 
#endif
#ifndef NPC
#define NPC   RANGER "npc/"
#endif
#ifndef OBJ
#define OBJ   RANGER "obj/"
#endif
#ifndef ROOM
#define ROOM  RANGER "room/"
#endif
#ifndef LOG
#define LOG   RANGER "log/"
#endif
#ifndef ARMOUR
#define ARMOUR  RANGER "armour/"
#endif
#ifndef WEAPON
#define WEAPON  RANGER "weapon/"
#endif

#define R_MASTER  RANGER "master/"

//-- Zusaetze ----------------------------------------------------------------
#define FOOD OBJ "food/"
#define MEMBERS_LOG RANGER "members_log/"
#define BACKUP RANGER "backup/"
#define SEQ RANGER "seq/"
#define MEMBERS RANGER "members/"
#define MEMBERS_PETS MEMBERS "pets/"
#define RANGER_FUNCTIONS RANGER"functions.h"

//-- Spellbook ---------------------------------------------------------------
#ifndef SPELLBOOKS
#define SPELLBOOKS "/spellbooks/"
#endif
#define SPELL_DIR SPELLBOOKS GUILD "/"
#define GUILD_SPELLBOOK SPELLBOOKS "waldlaeufer_spells"
#define RANGER_SPELLS GUILD_SPELLBOOK

//-- alle Master -------------------------------------------------------------
#define RANGERMASTER R_MASTER "master"
#define GUILD_MASTER RANGERMASTER

#define R_SKILLMASTER R_MASTER "skillmaster"
#define TASKMASTER R_MASTER "taskmaster"
#define PETMASTER R_MASTER "petmaster"
#define HERBS_MASTER R_MASTER "herbs_master"
#define WLR_MASTER R_MASTER "area_master"

#define R_NPC_MASTER R_MASTER "npcmaster"
#define SEQUENCER R_MASTER "sequencer"
#define R_RES_CHECKER R_MASTER "restriction_checker"
//-- externe -----------------------------------------------------------------
#define RES_CHECKER "/gilden/obj/restriction_checker"
#define SAVEMASTER "/gilden/obj/savefilemaster"
#define QUESTMASTER "/secure/questmaster"

//-- LOGs & LISTs ------------------------------------------------------------
#define MEMBERLIST MEMBERS "members"
#define MEMBERLOG MEMBERS_LOG  "member.log"
#define TOPLIST MEMBERS "toplist"
#define READ_TOPLIST MEMBERS "read_toplist"
#define F100_POINTS MEMBERS "100_points"
#define SKILL_CHANGE MEMBERS "skillchanges"
#define PATH_CHANGE MEMBERS "pathchanges"
#define ARCHENEMY_CHANGE MEMBERS "archenemychanges"
#define MEMBERBACKUP BACKUP "member_backup_"
#define GUILD_LOG_FILE "/log/gilden/waldlaeufer"
#define CHANNEL_HISTORY LOG "channel.log" 
#define MASTERPATHFILE MEMBERS "masterpath"

//#define KILL_LOG LOG "npc.kills"
//#define SKILLLIST MEMBERS "skilllist"
#define PATH_LOG LOG "path_change.log"
#define ARCHENEMY_LOG LOG "archenemy_change.log"
#define SKILLPOINT_LOG LOG "skill_points_clear.log"
#define R_HIST_LOG LOG "rhist.log"
#define R_HYMNE_LOG LOG "hymne_des_waldes.log"
#define R_HYMNE_BACKUP_LOG LOG "hymne_des_waldes_backup.log"
#define R_PET_DIETIME LOG "pet_dietime.log"
#define GET_PET_LOG LOG "get_pet.log"
#define GET_ANIMAL_LOG LOG "get_animal.log"

//-- Gildenmagier ------------------------------------------------------------
#define MASTER_MAGES ({"lilyth","angrox","torian","delgo"})
#define GUILD_MAGES MASTER_MAGES

//-- Namen -------------------------------------------------------------------
#define GUILDNAME "waldlaeufer"
#define KREIS_1 "Schueler"
#define KREIS_2 "Waldlaeufer"
#define KREIS_3 "Hueter"
#define KREIS_4 "Meister"

//-- GuildNPC (Raziel) -------------------------------------------------------
#define GUILD_NPC "Raziel"
#define GUILD_NPC_LONG "Raziel der Halbelf, Oberster Anfuehrer der Waldlaeufer"
#define GUILD_NPC_ID "\nranger_guild_npc"

//-- Gildenraum --------------------------------------------------------------
#define GUILD_ROOM GUILD_DIR GUILD

//-- Diverse Defines ---------------------------------------------------------
#define BSA(x, y) break_string(x, 78, y)
#define BSC(x) break_string(x, caster->QueryProp(P_SCREENWIDTH))
#define DBL(x) if(find_player("lilyth")) tell_object(find_player("lilyth"),(""+x+"\n"))
#define DBT(x) if(find_player("torian")) tell_object(find_player("torian"),(""+x+"\n"))
#define DBD(x) if(find_player("delgo")) tell_object(find_player("delgo"),(""+x+"\n"))
//**************************************************************************//



//** RangerProperties ******************************************************//
//-- Allegmeine Properties ---------------------------------------------------
#define P_RANGER_REPORT_LEVEL "ranger_report_level"
#define P_GUILD_ITEM_VERSION "guild_item_version"
#define P_RANGER_SHOW_COMBOS "ranger_show_combos"
#define P_RANGER_NEED_QUEST "ranger_need_quest"


//-- Modifications -----------------------------------------------------------
#define P_RANGER_ARCHENEMY "ranger_archenemy"
#define P_RANGER_COMBO "ranger_combo_points"
#define P_RANGER_NO_MAGIC_DEFENSE "ranger_no_magic_defense"
#define SI_COMBO_COUNTER "si_combo_counter"

//-- Skillpoint-Properties ---------------------------------------------------
#define P_RANGER_SKILLPOINTS "ranger_skillpoints"
#define P_RANGER_FREE_SKILLPOINTS "ranger_free_skillpoints"

//-- Spell-Properties --------------------------------------------------------
#define P_RANGER_PET_RACE "ranger_pet_race" 
#define P_RANGER_PET_OWNER "ranger_pet_owner" 
#define P_RANGER_LAST_PET_DEAD "ranger_last_pet_dead"
#define P_RANGER_MAX_PET_LEVEL "ranger_max_pet_level"
#define P_RANGER_LAST_PET_DEFENCE "ranger_last_pet_defence"
#define P_RANGER_COLD_FLAME "ranger_cold_flame"
#define P_RANGER_SPEED_ACTIVE "ranger_speed_active"
#define P_RANGER_BLAUE_FLAMME_ACTIVE "ranger_blaue_flamme_active"
#define P_RANGER_VIOLETTE_FLAMME_ACTIVE "ranger_violette_flamme_active"
#define P_RANGER_ODE_DES_STURMES_ACTIVE "ranger_ode_des_sturmes_active"
#define P_RANGER_LAST_HYMNE_DES_WALDES "last_hymne_des_waldes"
#define P_RANGER_LAST_HUNT "ranger_last_hunt"
#define P_RANGER_LAST_SWOOP "ranger_last_sturzflug"
#define P_RANGER_LAST_NET "ranger_last_net|slow"
#define P_RANGER_NEXT_BOREON "ranger_next_boreon"
#define P_RANGER_NEXT_TEKKI "ranger_next_tekki"
#define P_RANGER_NEXT_ANKSUNAMUN "ranger_next_ank'su'namun"
#define P_RANGER_EVISCERATED_UNTIL "ranger_eviscerated_until" // opfer wurde ausgeweidet und blutet
#define P_RANGER_NEXT_ANIMAL_ATACK "ranger_next_animal_attack" // next_spell fuer tiere
#define P_RANGER_LIFE_SENSE "ranger_life_sense" // bei den augen -> damit werden die LP des gegners angezeigt
#define P_RANGER_TRANCE_ROUND "ranger_trance_round" // runde in der trance des spielers (zB ebertrance) fuer verschiedene Boni
#define P_RANGER_HERBMIX_ACTIVATED "ranger_herbmix_activated"
#define P_RANGER_PET_RENAMED "ranger_pet_renamed"
#define P_RANGER_PET_SUPPORT "ranger_pet_support" // gesetzt wenn die support action aktiv ist ({dauer, chance})
#define P_RANGER_FALCONEYES "ranger_falcon_eyes" // blick des falken ({endzeit, gegner, multiplikator})
#define P_RANGER_PET_SPEED_UNTIL "ranger_pet_speed_until" // Ende des speed boosts durch "wut der bestie"
#define P_RANGER_HYMN_OF_WOODS_ACTIVE "ranger_hymn_woods_active" // im raum gesetzt wenn er aktiv transformiert wird
//**************************************************************************//



//** Einige MappingKeys/Values *********************************************//
//-- Gildenkommunikation -----------------------------------------------------
#define HIST_NAME  0
#define HIST_TIME  1
#define HIST_MSG   2
#define HIST_INVIS 3
#define HIST_EMOTE 4

#define M_HIST_NAME 0
#define M_HIST_TIME 1
#define M_HIST_MSG  2

#define CHANGE_FLAG_PATH 0
#define CHANGE_FLAG_SKILL 1
#define CHANGE_FLAG_ARCHENEMY 2
//**************************************************************************//



//** Spellobjekte/npc ******************************************************//
//-- Tiere des Waldes --------------------------------------------------------
#define ANIMAL_ID "\n_ranger_animal"
#define ANIMAL_CONTROL_ID "\nanimal_control"

#define BEERE "ranger_beere"
#define NUSS "ranger_nuesse"
#define FLEISCH "ranger_fleisch"

//-- Wolf/Baer/Adler/Spinne --------------------------------------------------
#define SUMMON_ID "\n_ranger_summon"
#define WOLF_ID "\nranger_wolf"
#define HAWK_ID "\nranger_hawk"
#define BEAR_ID "\nranger_bear"
#define SPIDER_ID "\nranger_spider"
#define SHADOW_WOLF_ID "\nranger_shadow_wolf"
#define GIANT_HAWK_ID "\nranger_giant_hawk"
#define GRIZZLY_ID "\nranger_grizzly"
#define SWORD_SPIDER_ID "\nranger_sword_spider"
#define BOREON_ID "\nranger_boreon"
#define TEKKI_ID "\nranger_tekki"
#define ANKSUNAMUN_ID "\nranger_anksunamun"
#define SUMMON_SWARM_ID "\nranger_summoned_swarm"
#define WOODSPIRIT_ID "\nranger_summoned_spirit"

// report bits
#define P_RANGER_ACTIVE_SPELLS "ranger_active_spells"
#define TB_RINDENHAUT 0
#define TB_VISION 1
#define TB_KRAFT_DES_TIERES 2
#define TB_EBER_TRANCE 3
#define TB_AVATARA 4
#define TB_BLUTDORN 5
#define TB_ODS 6
#define TB_MDO 7

//-- Zaehmung ----------------------------------------------------------------
#define PET_ID "\nranger_pet"

//-- Pakt der Schatten -------------------------------------------------------
#define SHADOW_CONTROL_ID "\nranger_shadow_control"
#define SHADOW_NPC_ID "\nranger_schadow_npc"

//-- Kraeutersuche -----------------------------------------------------------
#define KRAUT_ID "\nranger_kraut"
#define FOOD_ID "\nranger_food"

//-- Blaue Flamme/Violette Flamme --------------------------------------------
#define FLAME_CONTROL_ID "\nranger_flame_controll"

//-- Augen des Jaegers -------------------------------------------------------
#define DAYVISION_ID "\nranger_dayvision"
#define NIGHTVISION_ID "\nranger_nightvision"
#define VISION_ID "\nranger_vision"

//-- Fangfalle/Fesselfalle/Stolperdraht/Pfeilfalle ---------------------------
#define FALLE_ID "\nranger_falle"
#define FESSELFALLE_ID "\nranger_fesselfalle"
#define FANGFALLE_ID "\nranger_fangfalle"
#define STOLPERDRAHT_ID "\nranger_stolperdraht"
#define PFEILFALLE_ID "\nranger_pfeilfalle"

//-- Rindenhaut --------------------------------------------------------------
#define RINDENHAUT_ID "\nranger_rindenhaut"

//-- Kraft des Tieres --------------------------------------------------------
#define KRAFT_DES_TIERES_ID "\nranger_kraft_des_tieres"

//-- Melodien ----------------------------------------------------------------
#define AVATARA_ARMOUR_ID "\nranger_avatara_armour"
#define MELODIE_DES_OSTENS_ID "\nranger_dex_melodie"

//-- Mehrere Verwendungen ----------------------------------------------------
#define INVIS_ARMOUR_ID "\nranger_invis_armour"
#define INVIS_BONUS_ID "\nranger_invis_bonus"
#define PLAYER_DAMAGE_ID "\nranger_player_damage"
#define NPC_POISON_ID "\nranger_npc_poison"
#define HEAL_OBJ_ID "\nranger_heal"
#define BLUTDORN_ID "\nranger_blutdorn"
#define ODE_OF_STORMS_ID "\nranger_ode_des_sturms"
#define PANTHER_ASPECT_ID "\nranger_aspect_of_the_panther"

#define SPIDER_KOKON_ID "\nranger_spider_kokon"
#define SPELLSUPPORT "\nranger_spellsupport"
#define HYMNEN_SPAWNER "\nranger_hymn_spawner"
#define EDGE_SOUL_ID "\nranger_seele_der_klinge"
#define MELODY_OF_CHANGE_ID "\nranger_melodie_der_veraenderung"
#define MELODY_TIME_ID "\nranger_melodie_der_zeit"

#define PENETRATING_SHOT_ID "\nranger_penetrating_shot"

//-- Externe -----------------------------------------------------------------
#define WATERBREATH_ID "\nwaterbreath"
//**************************************************************************//



//** Items *****************************************************************//
//-- GildenItems -------------------------------------------------------------
#define GUILD_OBJ_ID "\nranger_koecher"
#define FOOD_CONTAINER_ID "\nranger_food_container"
#define IAMA_ID "\nranger_iama"
#define SICHEL_ID "\nranger_sichel"
#define RANGER_ARMOUR_ID "\nranger_armour"
#define RANGER_ITEMS ({GUILD_OBJ_ID, FOOD_CONTAINER_ID, IAMA_ID, SICHEL_ID, \
                       TRAP_BELT_ID, RANGER_ARMOUR_ID})
#define TASK_OBJECT_ID "\nranger_task_object"
#define EXAM_NPC_ID "\nranger_exam_npc"

//-- default_ranger ----------------------------------------------------------
#define DEFAULT_RANGER_ID "\ndefault_ranger_npc"

//-- Externe -----------------------------------------------------------------
#define MALARIA_OBJECT "/d/dschungel/dante/weg/obj/dmala"

#define MSTONE_ID "\nmagiestein"
#define SCHUPPEN_ID "\nschupp"
#define DIAMANT_ID "diamant" //nur per id/present testen


#define NOZAEHMUNG "NOZAEHMUNG"
#define NOWIMPY "NOWIMPY"
#define NODESTRUCT "NODESTRUCT"
#define NOUNCURSE "NOUNCURSE"
#define NOCONTROL "NOCONTROL"
#define NOT_LIVING "NOT_LIVING"
#define NO_MUMMY "NO_MUMMY"
#define NOFALLDOWN "NOFALLDOWN"
#define QUEYTOBJ "QUESTOBJ"
#define SKILL_NOLEARN "SKILL_NOLEARN"

#define SCHUPPEN_WUSCHEL "SCHUPPEN_WUSCHEL"
#define FEDERN_WUSCHEL "FEDERN_WUSCHEL"
#define FELL_WUSCHEL "FELL_WUSCHEL"
#define MAEHNE_WUSCHEL "MAEHNE_WUSCHEL"
#define HAARE_WUSCHEL "HAARE_WUSCHEL"
//**************************************************************************//



//** Spells und Skills *****************************************************//
//--Kraeuterkunde (Herbs_master)----------------------------------------------
#define SI_ENVIRONMENT "si_environment"

#define HERBS_HEAL "hp_heal"
#define HERBS_REFRESH "sp_heal"
#define HERBS_FROG "re_frog"
#define HERBS_ALCOHOL "alcohol_enttanken"
#define HERBS_DRINK "drink_enttanken"
#define HERBS_FOOD "food_enttanken"
#define HERBS_POISON "entgiften"
#define HERBS_BLIND "entblinden"
#define HERBS_DEAF "enttauben"
#define HERBS_MV "erschoepfung"
#define HERBS_WATER "unterwasseratmung"
#define HERBS_MALARIA "malaria_behandeln"

//-- FertigkeitsPunkte -------------------------------------------------------
#define SPEED_ONE "Verbesserte Geschwindigkeit"                             
#define KLINGENMEISTER "Klingenmeister"
#define SINNE_DES_JAEGERS "Sinne des Jaegers"
#define BOGENMEISTER "Bogenmeister"
#define ERSTE_STICHE "Die ersten Stiche"
#define MEISTER_DER_GIFTE "Meister der Gifte"
#define VERBESSERTE_ZAEHMUNG "Verbesserte Zaehmung"
#define GROSSWILDJAEGER "Grosswildjaeger"
#define VERBESSERTER_PAKT "Verbesserter Pakt"
#define GEWALT_DER_URAHNEN "Gewalt der Urahnen"
#define MESSERKAMPF "Der Messerkampf"
#define GUNST_DER_FLAMME "Gunst der Flamme"
#define BOGENKAMPF "Der Bogenkampf"
#define KOERPERBEHERRSCHUNG "Koerperbeherrschung"
#define TIER_ATTACKEN "Die Attacken der Tiere"
#define SCHUTZ_DES_WALDES "Schutz des Waldes"
#define TIER_VERTEIDIGUNG "Die Verteidigung der Tiere"
#define RUHEHORT "Hort der Ruhe"
#define AKROBATIK "Akrobatik"
#define AVATARA_NAMEN "Die Namen der Avatara"
#define KRAEUTERKUNDE "Die Kunst der Kraeuterkunde"
#define TIER_RESPEKT "Respekt der Tiere"
#define SPEED_TWO "Schnell wie der Wind"

//-- Spellnamen --------------------------------------------------------------
#define SI_SPELLNAME "si_spellname"
#define SI_PATH "si_ranger_path"

#define DURCHDRINGE "durchdringe"
#define SCHAETZ "schaetz"
#define AUGEN_DES_JAEGERS "augen des jaegers"
#define DEUTSCHUSS "deutschuss"
#define MESSERSTICH "messerstich"
#define GESCHWINDIGKEIT "geschwindigkeit"
#define PAKT_DER_SCHATTEN "pakt der schatten"
#define ZAEHMUNG "zaehmung"
#define MARKIERUNGSSCHUSS "markierung der beute"
#define KRAEUTERMIXTUR "kraeutermixtur"
#define FUSSTRITT "fusstritt"
#define TIERHEILUNG "tiere besprechen"
#define ASPEKT_DES_PANTHERS "aspekt des panthers"
#define SCHATTENSCHNITT "schattenschnitt"

#define RINDENHAUT "rindenhaut"

#define FESSELFALLE "fesselfalle"
#define FANGFALLE "fangfalle"
#define STOLPERDRAHT "stolperdraht"
#define PFEILFALLE "pfeilfalle"

#define TIERE_DES_WALDES "tiere des waldes"
#define WALDWOLF "waldwolf"
#define SCHWARZBAER "schwarzbaer"
#define ADLER "adler"
#define SPINNE "spinne"
#define WILDER_SCHWARM "wilder schwarm"
#define WALDGEIST "waldgeist"

#define MELODIE_DER_RUHE "melodie der ruhe"
#define ODE_DES_STURMES "ode des sturmes"
#define MELODIE_DER_AVATARA "melodie der avatara"
#define HYMNE_DES_WALDES "hymne des waldes"
#define MELODIE_DES_OSTENS "melodie des ostens"
#define MELODIE_DER_VERAENDERUNG "melodie der veraenderung"
#define MELODIE_DER_ZEIT "melodie der zeit"

#define KALTE_FLAMME "band des schuetzen"
#define ZIELSCHUSS "zielschuss"
#define DOPPELSCHUSS "doppelschuss"
#define PANZERBRECHENDER_SCHUSS "panzerbrechender schuss"
#define GIFTPFEIL "giftpfeil"
#define SALVE "salve"
#define BLICK_DES_FALKEN "blick des falken"
#define FREIPFEILE "freipfeile"

#define KLINGENWIRBEL "klingenwirbel"
#define MESSERWURF "messerwurf"
#define BLAUE_FLAMME "trance des wilden ebers"
#define VIOLETTE_FLAMME "klinge des blutdorns"
#define AUSWEIDEN "ausweiden"
#define SEELE_DER_KLINGE "seele der klinge"

#define TIERANGRIFF "tierangriff"
#define KAMPFGEIST "kampfgeist"
#define KRAFT_DES_TIERES "kraft des tieres"
#define KRAFT_DER_AHNEN "kraft der ahnen"
#define GEMEINSAME_ATTACKE "gemeinsame attacke"
#define WUT_DER_BESTIE "wut der bestie"
#define INKARNATION_DER_KOEIGE "inkarnation der koenige"
//**************************************************************************//



//** Balance/Zahlen fuer Spells und schnelle Anpassung *********************//
//-- Pets --------------------------------------------------------------------
#define MAX_LEVEL 40 //maximales erriechbares Level der Pets

//-- Blaue/Violette Flamme ---------------------------------------------------
#define MAX_FLAME_ROUNDS 36 //max. (gerade) anzahl der Kampfrunden mit Flamme

//-- SkillPunkte -------------------------------------------------------------
#define SKILL_POINT_LEVEL ({2,5,8,11,13,15,16,18,20})
#define MAX_SKILL_POINTS sizeof(SKILL_POINT_LEVEL)

//-- betretbare Pfade --------------------------------------------------------
#define MAX_PATH_SIZE 2

//-- Wieviel Fallenmaterial darf im Guertel lagern? --------------------------
#define MAX_FALLEN_LADUNGEN 50
//**************************************************************************//



//** DiverseDefines (u.a. fuer Topliste) ***********************************//
//-- Topliste ----------------------------------------------------------------
#define LEARNABLE_SPELLS 26
#define MAX_GUILD_LEVEL 20
#define NO_ONLINE_DAYS_FOR_TOPLIST 14*24*60*60

//-- Einschraenkung der Boni -------------------------------------------------
#define MAX_SPELLCOST 50
#define MAX_RANGER_BONUS 50
//**************************************************************************//

#define ATTACK_SPELL_NOWEAPON 0
#define ATTACK_SPELL_KNIFE 1
#define ATTACK_SPELL_BOW 2

#define pDebug(a, b) if(a->QueryProp(P_TESTPLAYER) || IS_WIZARD(a)) tell_object(a, ANSI_GREEN+b+ANSI_NORMAL);

#define WALDSCHRAT_NPC "/d/kristallwald/lilyth/tethyr/npc/waldschrat"

// aktuellste version des koechers
#define KOECHER_VERSION 11

#define SPELL_BONUS(a, b) call_other(GUILD_SPELLBOOK, "get_equip_bonus", a, b)
#define SPELL_DAMAGE_BONUS(a, b, c) call_other(GUILD_SPELLBOOK, "get_equip_damage", a, b, c)

#define P_HEAL_TYPE "heilungs_art"
#define P_HEAL_STRENGTH "heilungs_staerke"

#define P_RANGER_FREISCHUETZ "ranger_freischuetz"
#define RANGER_FREISCHUETZ_ACTIVE    0 // naechster pfeil -> freipfeil
#define RANGER_FREISCHUETZ_COUNT     1 // wieviele pfeile habe ich noch?#
#define P_RANGER_NEXT_FREIPFEILE "ranger_next_freipfeile"

// meisterfertigkeiten
#define MASTER_ABIILITY_THOUSAND_CUTS "Tausend Schnitte"
#define MASTER_ABIILITY_CRIPPLING_STRIKE "Verkrueppelnder Stoss"
#define MASTER_ABIILITY_POWERFUL_COMPANION "Maechtiger Tiergefaehrte"
#define MASTER_ABIILITY_DEEP_BOND "Tiefe Bande"
#define MASTER_ABIILITY_BACKOFF "Unmoegliches Ausweichen"
#define MASTER_ABIILITY_CRITICAL_AIM "Kritischer Schuss"
#define MASTER_ABIILITY_IMPROVED_BINDING "Verbesserte Bindung"
#define MASTER_ABIILITY_PERMANENT_SUMMON "Dauerhafte Beschwoerung"
#define MASTER_ABIILITY_VOICE_OF_NATURE "Stimme der Natur"
#define MASTER_ABIILITY_RAGE_OF_NATURE "Wildheit der Avatara"
#define MASTERABILITY_FILE MEMBERS "master_abilities"
#define P_RANGER_BOND_EFFECT "ranger_bond_effect"

#define CLOSURE(x) #'x


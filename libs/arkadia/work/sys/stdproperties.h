/*
 * /sys/stdproperties.h
 *
 * This file hold definition of all the standard properties that an object
 * can have. The documentation for the properties can all be found in the 
 * directory /doc/man/properties.
 *
 * The following prefixes are used:
 *
 * ARMOUR_ - armour property
 * CONT_   - container property
 * CORPSE_ - corpse property
 * HEAP_   - heap property
 * LIVE_   - living property
 * MAGIC_  - magic property
 * OBJ_    - object property
 * PLAYER_ - player property
 * NPC_    - npc property
 * ROOM_   - room property
 * TEMP_   - temporary property
 * WIZARD_ - wizard property
 *
 * The first infix (i.e. the part after the prefix) identifies the type
 * of the property. The following values are possible:
 *
 * AX - array of type X, where X is either of F I O S M
 * F  - function
 * I  - integer
 * O  - object
 * S  - string
 * M  - mixed
 */

#ifndef PROP_DEF
#define PROP_DEF

/* *********************************************************
 * Container properties
 */

#define ARMOUR_I_MAGIC_PARRY	"_armour_i_magic_parry"

/* *********************************************************
 * Container properties
 */

#define CONT_I_IN			"_cont_i_in"
#define CONT_M_NO_INS			"_cont_m_no_ins"
#define CONT_I_NO_REM     		"_cont_m_no_rem"
#define CONT_M_NO_REM			"_cont_m_no_rem"

#define CONT_I_ATTACH			"_cont_i_attach"
#define CONT_I_CLOSED     		"_cont_i_closed"
#define CONT_I_DONT_SHOW_CONTENTS	"_cont_i_dont_show_contents"
#define CONT_I_HEIGHT     		"_cont_i_height"
#define CONT_I_HIDDEN			"_cont_i_hidden"
#define CONT_I_LIGHT      		"_cont_i_light"
#define CONT_I_LOCK			"_cont_i_lock"
#define CONT_I_RIGID			"_cont_i_rigid"
#define CONT_I_TRANSP     		"_cont_i_transparent"
#define CONT_I_VOLUME     		"_cont_i_volume"
#define CONT_I_WEIGHT     		"_cont_i_weight"
#define CONT_I_MAX_VOLUME		"_cont_i_max_volume"
#define CONT_I_MAX_WEIGHT		"_cont_i_max_weight"
#define CONT_I_REDUCE_VOLUME		"_cont_i_reduce_volume"
#define CONT_I_REDUCE_WEIGHT		"_cont_i_reduce_weight"

/* *********************************************************
 * Corpse properties
 */
#define CORPSE_M_RACE		"_corpse_m_race"
#define CORPSE_I_RRACE		"_corpse_i_rrace"
#define CORPSE_AS_KILLER        "_corpse_as_killer"

/* *********************************************************
 * Door properties
 */
#define DOOR_I_HEIGHT		"_door_i_height"
#define DOOR_I_KEY		"_door_i_key"

/* *********************************************************
 * Heap properties
 */
#define HEAP_I_IS          	"_heap_i_is"
#define HEAP_S_UNIQUE_ID   	"_heap_s_unique_id"
#define HEAP_I_UNIT_LIGHT  	"_heap_i_unit_light" 
#define HEAP_I_UNIT_VALUE  	"_heap_i_unit_value" 
#define HEAP_I_UNIT_VOLUME 	"_heap_i_unit_volume" 
#define HEAP_I_UNIT_WEIGHT 	"_heap_i_unit_weight" 

/* *********************************************************
 * Living properties
 */

#define LIVE_I_IS		"_live_i_is"
#define LIVE_I_ALWAYSKNOWN      "_live_i_alwaysknown"
#define LIVE_I_NEVERKNOWN	"_live_i_neverknown"
#define LIVE_I_MAX_INTOX	"_live_i_max_intox"
#define LIVE_I_MIN_INTOX	"_live_i_min_intox"
#define LIVE_I_MAX_DRINK	"_live_i_max_drink"
#define LIVE_I_MAX_EAT		"_live_i_max_eat"
#define LIVE_I_SEE_INVIS	"_live_i_see_invis"
#define LIVE_I_SEE_DARK		"_live_i_see_dark"
#define LIVE_S_SOULEXTRA        "_live_s_soulextra"
#define LIVE_AS_ATTACK_FUMBLE	"_live_as_attack_fumble"
#define LIVE_I_ATTACK_DELAY     "_live_i_attack_delay"
#define LIVE_I_STUNNED          "_live_i_stunned"
#define LIVE_I_QUICKNESS	"_live_i_quickness"
#define LIVE_O_LAST_KILL	"_live_o_last_kill"
#define LIVE_O_SPELL_ATTACK	"_live_o_spell_attack"
#define LIVE_O_ENEMY_CLING	"_live_o_enemy_cling"
#define LIVE_S_EXTRA_SHORT	"_live_s_extra_short"
#define LIVE_O_LAST_ROOM	"_live_o_last_room"
#define LIVE_S_LAST_MOVE	"_live_s_last_move"
#define LIVE_I_UNDEAD		"_live_i_undead"
#define LIVE_I_NO_CORPSE	"_live_i_no_corpse"
#define LIVE_I_NO_BODY		"_live_i_no_body"
#define LIVE_I_MEDITATES	"_live_i_meditates"
#define LIVE_I_SNEAK    	"_live_i_sneak"
#define LIVE_I_LANGUAGE         "_live_i_language"
#define LIVE_I_NO_FOOTPRINTS    "_live_i_no_footprints"
#define LIVE_I_NO_GENDER_DESC   "_live_i_no_gender_desc"
#define LIVE_I_CONCENTRATE      "_live_i_concentrate"
#define LIVE_O_CONCENTRATE      "_live_i_concentrate"
#define LIVE_S_BREAK_CONCENTRATE "_live_s_break_concentrate"
#define LIVE_M_MOUTH_BLOCKED    "_live_m_mouth_blocked"
#define LIVE_O_STEED            "_live_o_steed"

/* *********************************************************
 * Magic properties
 */

#define MAGIC_AM_ID_INFO	"_magic_am_id_info"
#define MAGIC_I_ILLUSION	"_magic_i_illusion"
#define MAGIC_AM_MAGIC		"_magic_am_magic"

#define MAGIC_I_RES_ACID	"_magic_i_res_acid"
#define MAGIC_I_RES_COLD	"_magic_i_res_cold"
#define MAGIC_I_RES_ELECTRICITY	"_magic_i_res_electricity"
#define MAGIC_I_RES_LIGHT	"_magic_i_res_electricity"
#define MAGIC_I_RES_IDENTIFY	"_magic_i_res_identify"
#define MAGIC_I_RES_MAGIC	"_magic_i_res_magic"
#define MAGIC_I_RES_POISON	"_magic_i_res_poison"

#define MAGIC_I_RES_AIR		"_magic_i_res_air"
#define MAGIC_I_RES_WATER	"_magic_i_res_water"
#define MAGIC_I_RES_EARTH	"_magic_i_res_earth"
#define MAGIC_I_RES_FIRE        "_magic_i_res_fire"
#define MAGIC_I_RES_LIFE	"_magic_i_res_life"
#define MAGIC_I_RES_DEATH	"_magic_i_res_death"

#define MAGIC_I_BREATH_WATER	"_magic_i_breath_water"

/* *********************************************************
 * Object properties
 */
#define OBJ_I_LIGHT		"_obj_i_light" 
#define OBJ_I_VALUE		"_obj_i_value" 
#define OBJ_I_VOLUME		"_obj_i_volume"
#define OBJ_I_WEIGHT		"_obj_i_weight"

#define OBJ_I_NO_GET		"_obj_m_no_get"
#define OBJ_M_NO_GET            "_obj_m_no_get"
#define OBJ_I_NO_DROP		"_obj_m_no_drop"
#define OBJ_M_NO_DROP           "_obj_m_no_drop"
#define OBJ_I_NO_GIVE		"_obj_m_no_give"
#define OBJ_M_NO_GIVE           "_obj_m_no_give"
#define OBJ_I_NO_INS		"_obj_m_no_ins"
#define OBJ_M_NO_INS            "_obj_m_no_ins"

#define OBJ_I_HIDE		"_obj_i_hide"
#define OBJ_I_INVIS		"_obj_i_invis"
#define OBJ_S_WIZINFO		"_obj_s_wizinfo"

#define OBJ_I_BROKEN		"_obj_i_broken"
#define OBJ_I_IS_MAGIC_ARMOUR	"_obj_i_is_magic_armour"
#define OBJ_I_IS_MAGIC_WEAPON	"_obj_i_is_magic_weapon"

#define OBJ_M_NO_MAGIC		"_obj_m_no_magic"
#define OBJ_I_NO_MAGIC          "_obj_m_no_magic"
#define OBJ_M_NO_TELEPORT	"_obj_m_no_teleport"
#define OBJ_I_NO_TELEPORT       "_obj_m_no_teleport"
#define OBJ_M_NO_MAGIC_ATTACK	"_obj_m_no_magic_attack"
#define OBJ_I_NO_MAGIC_ATTACK   "_obj_m_no_magic_attack"
#define OBJ_M_NO_STEAL		"_obj_m_no_steal"
#define OBJ_I_NO_STEAL          "_obj_m_no_steal"
#define OBJ_M_NO_ATTACK		"_obj_m_no_attack"
#define OBJ_I_NO_ATTACK         "_obj_m_no_attack"

#define OBJ_I_SEARCH_TIME	"_obj_i_search_time"

#define OBJ_I_CONTAIN_WATER	"_obj_i_contain_water"
#define OBJ_I_HAS_FIRE          "_obj_i_has_fire"

#define OBJ_M_NO_SELL		"_obj_m_no_sell"
#define OBJ_M_NO_BUY		"_obj_m_no_buy"

#define PRE_OBJ_MAGIC_RES       "_obj"

#define OBJ_I_RES_MAGIC         "_obj_magic_i_res_magic"
#define OBJ_I_RES_ACID          "_obj_magic_i_res_acid"
#define OBJ_I_RES_COLD          "_obj_magic_i_res_cold"
#define OBJ_I_RES_ELECTRICITY   "_obj_magic_i_res_electricity"
#define	OBJ_I_RES_LIGHT		"_obj_magic_i_res_electricity"
#define OBJ_I_RES_POISON        "_obj_magic_i_res_poison"
#define OBJ_I_RES_IDENTIFY	"_obj_magic_i_res_identify"

#define OBJ_I_RES_AIR         	"_obj_magic_i_res_air"
#define OBJ_I_RES_WATER       	"_obj_magic_i_res_water"
#define OBJ_I_RES_EARTH       	"_obj_magic_i_res_earth"
#define OBJ_I_RES_FIRE        	"_obj_magic_i_res_fire"
#define OBJ_I_RES_LIFE        	"_obj_magic_i_res_life"
#define OBJ_I_RES_DEATH       	"_obj_magic_i_res_death"
#define OBJ_I_ALIGN                "_obj_i_align"
#define OBJ_AM_POISONOUS           "_obj_am_poisonous"
#define OBJ_AM_POISONOUS_INFO      "_obj_am_poisonous_info"

/* *********************************************************
 * Player properties
 */
#define PLAYER_I_AUTOSAVE		"_player_i_autosave"
#define PLAYER_I_SEE_ERRORS             "_player_i_see_errors"
#define PLAYER_I_LASTXP			"_player_i_lastxp"
#define PLAYER_I_LAST_NOTE		"_player_i_last_note"
#define PLAYER_AS_REPLY_WIZARD          "_player_as_reply_wizard"

/*
 * Te propy nie sa juz uzywane. Ich role przejal system options.
 * Po usunieciu starego kodu do usuniecia, jak mniemam. (Slvthrc)
 */
#define PLAYER_I_MORE_LEN		"_player_i_more_len"
#define	PLAYER_I_SCREEN_WIDTH		"_player_i_screen_width"

/* *********************************************************
 * NPC properties
 */
#define NPC_M_NO_ACCEPT_GIVE	"_npc_m_no_accept_give"
#define NPC_I_NO_FEAR           "_npc_i_no_fear"
#define NPC_I_NO_LOOKS		"_npc_i_no_looks"
#define NPC_I_NO_RUN_AWAY	"_npc_i_no_run_away"

/* *********************************************************
 * Room properties
 */
#define ROOM_I_IS		"_room_i_is"
#define ROOM_I_LIGHT		"_room_i_light"
#define ROOM_I_INSIDE		"_room_i_inside"
#define ROOM_I_TYPE		"_room_i_type"
#define ROOM_NORMAL		0
#define ROOM_IN_WATER		1
#define ROOM_UNDER_WATER	2
#define ROOM_IN_AIR		3
#define ROOM_BEACH		4
#define ROOM_I_NO_EXTRA_EXIT	"_room_i_no_extra_exit"
#define ROOM_I_NO_EXTRA_ITEM	"_room_i_no_extra_item"
#define ROOM_I_NO_EXTRA_DESC	"_room_i_no_extra_desc"
#define ROOM_AS_DOORID		"_room_as_doorid"
#define ROOM_AO_DOOROB		"_room_as_doorob"
#define ROOM_I_NO_CLEANUP	"_room_i_no_cleanup"
#define ROOM_AS_DIR		"_room_as_dir"
#define ROOM_S_DARK_MSG         "_room_s_dark_msg"
#define ROOM_S_DARK_LONG        "_room_s_dark_long"
#define ROOM_I_NO_SKY		"_room_m_no_sky"
#define ROOM_M_NO_SKY		"_room_m_no_sky"

#define ROOM_I_NO_MAGIC		"_room_m_no_magic"
#define ROOM_M_NO_MAGIC		"_room_m_no_magic"
#define ROOM_I_NO_TELEPORT	"_room_m_no_teleport"
#define ROOM_M_NO_TELEPORT      "_room_m_no_teleport"
#define ROOM_I_NO_MAGIC_ATTACK	"_room_m_no_magic_attack"
#define ROOM_M_NO_MAGIC_ATTACK  "_room_m_no_magic_attack"
#define ROOM_I_NO_STEAL		"_room_m_no_steal"
#define ROOM_M_NO_STEAL         "_room_m_no_steal"
#define ROOM_I_NO_ATTACK	"_room_m_no_attack"
#define ROOM_M_NO_ATTACK        "_room_m_no_attack"

#define ROOM_I_HIDE		"_room_i_hide"

/* *********************************************************
 * Temporary properties
 */
#define TEMP_OBJ_ABOUT_TO_DESTRUCT      "_temp_obj_about_to_destruct"
#define TEMP_SUBLOC_SHOW_ONLY_THINGS    "_temp_subloc_show_only_things"
#define TEMP_STDFOOD_CHECKED 		"_temp_stdfood_checked"
#define TEMP_STDDRINK_CHECKED 		"_temp_stddrink_checked"
#define TEMP_STDREAD_CHECKED		"_temp_stdread_checked"
#define TEMP_STDTORCH_CHECKED		"_temp_stdtorch_checked"
#define TEMP_STDCORPSE_CHECKED 		"_temp_stdcorpse_checked"
#define TEMP_DRAGGED_ENEMIES		"_temp_dragged_enemies"
#define TEMP_LEFTOVER_ORGAN		"_temp_leftover_organ"
#define TEMP_STDROPE_CHECKED		"_temp_stdrope_checked"
#define TEMP_STDHERB_CHECKED		"_temp_stdherb_checked"
#define TEMP_STDPOTION_CHECKED		"_temp_stdpotion_checked"
#define	TEMP_LIBCONTAINER_CHECKED	"_temp_libcontainer_checked"
#define TEMP_BACKUP_BRIEF_OPTION        "_temp_backup_brief_option"

/* *********************************************************
 * Wizard properties
 */
#define WIZARD_AM_MAN_SEL_ARR	"_wizard_am_man_sel_arr"
#define WIZARD_S_MAN_SEL_CHAPT	"_wizard_s_man_sel_chapt"
#define WIZARD_AM_SMAN_SEL_ARR	"_wizard_am_sman_sel_arr"
#define WIZARD_S_SMAN_SEL_DIR	"_wizard_s_sman_sel_dir"
#define WIZARD_I_BUSY_LEVEL	"_wizard_i_busy_level"

/* No definitions beyond this line. */
#endif PROP_DEF

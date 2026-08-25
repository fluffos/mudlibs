/*
 * /sys/stdproperties.h
 *
 * This file hold definition of all the standard properties that an object
 * can have. The documentation for the properties can all be found in the
 * directory /doc/man/properties.
 *
 * The following prefixes are used:
 *
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

#define CONT_I_IN		"_cont_i_in"
#define CONT_I_ATTACH		"_cont_i_attach"
#define CONT_I_CLOSED     	"_cont_i_closed"
#define CONT_I_HEIGHT     	"_cont_i_height"
#define CONT_I_HIDDEN		"_cont_i_hidden"
#define CONT_I_HOLDS_COMPONENTS	"_cont_i_holds_components"
#define CONT_I_IS_QUIVER        "_cont_i_quiver"
#define CONT_I_LIGHT      	"_cont_i_light"
#define CONT_I_LOCK		"_cont_i_lock"
#define CONT_I_MAX_VOLUME	"_cont_i_max_volume"
#define CONT_I_MAX_WEIGHT	"_cont_i_max_weight"
#define CONT_I_NO_INS		"_cont_m_no_ins"
#define CONT_M_NO_INS		"_cont_m_no_ins"
#define CONT_I_NO_REM     	"_cont_m_no_rem"
#define CONT_M_NO_REM		"_cont_m_no_rem"
#define CONT_I_REDUCE_VOLUME	"_cont_i_reduce_volume"
#define CONT_I_REDUCE_WEIGHT	"_cont_i_reduce_weight"
#define CONT_I_RIGID		"_cont_i_rigid"
#define CONT_I_TRANSP     	"_cont_i_transparent"
#define CONT_I_VOLUME     	"_cont_i_volume"
#define CONT_I_WEIGHT     	"_cont_i_weight"

/* *********************************************************
 * Corpse properties
 */
#define CORPSE_S_RACE		"_corpse_s_race"
#define CORPSE_AS_KILLER        "_corpse_as_killer"
#define CORPSE_S_LIVING_FILE	"_corpse_s_living_file"

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
#define LIVE_AO_SPARRING        "_live_ao_sparring"
#define LIVE_AO_THIEF           "_live_ao_thief"
#define LIVE_AS_ATTACK_FUMBLE	"_live_as_attack_fumble"
#define LIVE_AS_POTION_ID       "_live_as_potion_id"
#define LIVE_I_ALWAYSKNOWN      "_live_i_alwaysknown"
#define LIVE_I_ATTACK_DELAY     "_live_i_attack_delay"
#define LIVE_I_ATTACK_THIEF     "_live_m_attack_thief"
#define LIVE_M_ATTACK_THIEF     "_live_m_attack_thief"
#define LIVE_I_BACKSTABBING     "_live_i_backstabbing"
#define LIVE_I_BLIND            "_live_i_blind"
#define LIVE_I_CONCENTRATE      "_live_i_concentrate"
#define LIVE_I_GOT_BACKSTABBED  "_live_i_got_backstabbed"
#define LIVE_I_HERB_INTERVAL    "_live_i_herb_interval"
#define LIVE_I_LAST_HERB        "_live_i_herb_effect"
#define LIVE_I_LAST_STEAL       "_live_i_last_steal"
#define LIVE_I_LAST_PEEK        "_live_i_last_peek"
#define LIVE_I_MAX_DRINK	"_live_i_max_drink"
#define LIVE_I_MAX_EAT		"_live_i_max_eat"
#define LIVE_I_MAX_INTOX	"_live_i_max_intox"
#define LIVE_I_MEDITATES	"_live_i_meditates"
#define LIVE_I_MIN_INTOX	"_live_i_min_intox"
#define LIVE_I_MOUTH_BLOCKED    "_live_m_mouth_blocked"
#define LIVE_M_MOUTH_BLOCKED    "_live_m_mouth_blocked"
#define LIVE_I_NEVERKNOWN	"_live_i_neverknown"
#define LIVE_I_NO_ACCEPT_GIVE   "_live_m_no_accept_give"
#define LIVE_M_NO_ACCEPT_GIVE   "_live_m_no_accept_give"
#define LIVE_I_NO_BODY          "_live_i_no_body"
#define LIVE_I_NO_CORPSE        "_live_i_no_corpse"
#define LIVE_I_NO_DRINK         "_live_m_no_drink"
#define LIVE_M_NO_DRINK         "_live_m_no_drink"
#define LIVE_I_NO_FOOTPRINTS    "_live_i_no_footprints"
#define LIVE_I_NO_GENDER_DESC   "_live_i_no_gender_desc"
#define LIVE_I_NO_INGEST        "_live_m_no_ingest"
#define LIVE_M_NO_INGEST        "_live_m_no_ingest"
#define LIVE_I_NO_MESSAGE       "_live_i_no_message"
#define LIVE_I_NO_SCRY          "_live_m_no_scry"
#define LIVE_M_NO_SCRY          "_live_m_no_scry"
#define LIVE_I_NO_STUN          "_live_m_no_stun"
#define LIVE_M_NO_STUN          "_live_m_no_stun"
#define LIVE_I_NON_FORGET       "_live_i_non_forget"
#define LIVE_I_NON_REMEMBER     "_live_i_non_remember"
#define LIVE_I_QUICKNESS        "_live_i_quickness"
#define LIVE_I_UNARMED_EXTRA_HIT    "_live_i_unarmed_extra_hit"
#define LIVE_I_UNARMED_EXTRA_PEN    "_live_i_unarmed_extra_pen"
#define LIVE_I_SEE_DARK		"_live_i_see_dark"
#define LIVE_I_SEE_INVIS	"_live_i_see_invis"
#define LIVE_I_SNEAK    	"_live_i_sneak"
#define LIVE_I_STUNNED          "_live_i_stunned"
#define LIVE_I_TEAM_NO_FOLLOW   "_live_i_team_no_follow"
#define LIVE_I_UNDEAD		"_live_i_undead"
#define LIVE_I_VICTIM_ADDED_AWARENESS "_live_i_victim_added_awareness"
#define LIVE_M_STOP_FIGHTING    "_live_m_stop_fighting"
#define LIVE_O_CONCENTRATE      "_live_i_concentrate"
#define LIVE_O_ENEMY_CLING	"_live_o_enemy_cling"
#define LIVE_O_LAST_KILL	"_live_o_last_kill"
#define LIVE_O_LAST_ROOM	"_live_o_last_room"
#define LIVE_O_SPELL_ATTACK	"_live_o_spell_attack"
#define LIVE_O_STEED            "_live_o_steed"
#define LIVE_S_BREAK_CONCENTRATE "_live_s_break_concentrate"
#define LIVE_S_EXTRA_SHORT	"_live_s_extra_short"
#define LIVE_S_LAST_MOVE	"_live_s_last_move"
#define LIVE_S_SOULEXTRA        "_live_s_soulextra"
#define LIVE_S_EXTENDED_INTOX   "_live_s_extended_intox"
#define LIVE_S_EXTENDED_STUFF   "_live_s_extended_stuff"

/* *********************************************************
 * Magic properties
 */

#define MAGIC_AM_ID_INFO	"_magic_am_id_info"
#define MAGIC_I_ILLUSION	"_magic_i_illusion"
#define MAGIC_AM_MAGIC		"_magic_am_magic"

#define MAGIC_I_RES_ACID	"_magic_i_res_acid"
#define MAGIC_I_RES_COLD	"_magic_i_res_cold"
#define MAGIC_I_RES_ELECTRICITY	"_magic_i_res_electricity"
#define MAGIC_I_RES_IDENTIFY	"_magic_i_res_identify"
#define MAGIC_I_RES_ILLUSION    "_magic_i_res_illusion"
#define MAGIC_I_RES_LIGHT	"_magic_i_res_electricity"
#define MAGIC_I_RES_MAGIC	"_magic_i_res_magic"
#define MAGIC_I_RES_POISON	"_magic_i_res_poison"

#define MAGIC_I_RES_AIR		"_magic_i_res_air"
#define MAGIC_I_RES_DEATH	"_magic_i_res_death"
#define MAGIC_I_RES_EARTH	"_magic_i_res_earth"
#define MAGIC_I_RES_FIRE        "_magic_i_res_fire"
#define MAGIC_I_RES_LIFE	"_magic_i_res_life"
#define MAGIC_I_RES_WATER	"_magic_i_res_water"

#define MAGIC_I_BREATHE_WATER   "_magic_i_breathe_water"
/* This misspelling maintained so as not to break existing code */
#define MAGIC_I_BREATH_WATER    MAGIC_I_BREATHE_WATER

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
#define OBJ_O_LOOTED_IN_ROOM    "_obj_o_looted_in_room"

#define OBJ_I_NO_ATTACK         "_obj_m_no_attack"
#define OBJ_M_NO_ATTACK		"_obj_m_no_attack"
#define OBJ_I_NO_MAGIC          "_obj_m_no_magic"
#define OBJ_M_NO_MAGIC		"_obj_m_no_magic"
/* Obsolete, redirected to "no attack" properties. */
#define OBJ_I_NO_MAGIC_ATTACK   OBJ_I_NO_ATTACK
#define OBJ_M_NO_MAGIC_ATTACK	OBJ_M_NO_ATTACK
#define OBJ_I_NO_STEAL          "_obj_m_no_steal"
#define OBJ_M_NO_STEAL		"_obj_m_no_steal"
#define OBJ_I_NO_TELEPORT       "_obj_m_no_teleport"
#define OBJ_M_NO_TELEPORT	"_obj_m_no_teleport"

#define OBJ_I_SEARCH_TIME	"_obj_i_search_time"
#define OBJ_S_SEARCH_FUN	"_obj_s_search_fun"

#define OBJ_I_CONTAIN_WATER	"_obj_i_contain_water"
#define OBJ_I_HAS_FIRE          "_obj_i_has_fire"
#define OBJ_M_HAS_MONEY         "_obj_m_has_money"

#define OBJ_I_NO_BUY		"_obj_m_no_buy"
#define OBJ_M_NO_BUY		"_obj_m_no_buy"
#define OBJ_I_NO_SELL		"_obj_m_no_sell"
#define OBJ_M_NO_SELL		"_obj_m_no_sell"

#define PRE_OBJ_MAGIC_RES       "_obj"

#define OBJ_I_RES_ACID          "_obj_magic_i_res_acid"
#define OBJ_I_RES_COLD          "_obj_magic_i_res_cold"
#define OBJ_I_RES_ELECTRICITY   "_obj_magic_i_res_electricity"
#define OBJ_I_RES_IDENTIFY	"_obj_magic_i_res_identify"
#define OBJ_I_RES_ILLUSION	"_obj_magic_i_res_illusion"
#define OBJ_I_RES_LIGHT		"_obj_magic_i_res_electricity"
#define OBJ_I_RES_MAGIC         "_obj_magic_i_res_magic"
#define OBJ_I_RES_POISON        "_obj_magic_i_res_poison"

#define OBJ_I_RES_AIR         	"_obj_magic_i_res_air"
#define OBJ_I_RES_DEATH       	"_obj_magic_i_res_death"
#define OBJ_I_RES_EARTH       	"_obj_magic_i_res_earth"
#define OBJ_I_RES_FIRE        	"_obj_magic_i_res_fire"
#define OBJ_I_RES_LIFE        	"_obj_magic_i_res_life"
#define OBJ_I_RES_WATER       	"_obj_magic_i_res_water"

#define OBJ_I_ALIGN             "_obj_i_align"

#define OBJ_I_AIDS_ACROBATIC    "_obj_i_aids_acrobatic" /* -100 to 100 */

/* *********************************************************
 * Player properties
 */
#define PLAYER_AS_REPLY_WIZARD  "_player_as_reply_wizard"
#define PLAYER_I_AUTOLOAD_TIME  "_player_i_autoload_time"
#define PLAYER_I_LAST_NOTE	"_player_i_last_note"
#define PLAYER_I_MORE_LEN	"_player_i_more_len"
#define PLAYER_I_NEWBIE_HELPER  "_player_i_newbie_helper"
#define PLAYER_I_NO_NOTES       "_player_i_no_notes"
#define PLAYER_I_SEE_ERRORS     "_player_i_see_errors"
#define PLAYER_S_TRANSED_FROM   "_player_s_transed_from"
#define PLAYER_I_SCREEN_WIDTH	"_player_i_screen_width"

/* *********************************************************
 * NPC properties
 */
#define NPC_M_NO_ACCEPT_GIVE	LIVE_M_NO_ACCEPT_GIVE
#define NPC_I_NO_FEAR           "_npc_i_no_fear"
#define NPC_I_NO_FEAR_CHECK     "_npc_i_no_fear_check"
#define NPC_I_NO_LOOKS		"_npc_i_no_looks"
#define NPC_I_NO_RUN_AWAY	"_npc_i_no_run_away"
#define NPC_I_NO_UNARMED        "_npc_i_no_unarmed"

/* *********************************************************
 * Room properties
 */
#define ROOM_I_IS		"_room_i_is"
#define ROOM_I_LIGHT		"_room_i_light"

#define ALWAYS_LIGHT_LIMIT      1000000
#define ALWAYS_LIGHT            (ALWAYS_LIGHT_LIMIT * 2)
#define ALWAYS_DARK_LIMIT       (-ALWAYS_LIGHT_LIMIT)
#define ALWAYS_DARK             (ALWAYS_DARK_LIMIT * 2)

#define ROOM_I_INSIDE		"_room_i_inside"
#define ROOM_I_TYPE		"_room_i_type"

#define ROOM_NORMAL		0
#define ROOM_IN_WATER		1
#define ROOM_UNDER_WATER	2
#define ROOM_IN_AIR		3
#define ROOM_BEACH		4

#define ROOM_AO_DOOROB          "_room_ao_doorob"
#define ROOM_AS_DOORID		"_room_as_doorid"
#define ROOM_I_ALLOW_STEED      "_room_i_allow_steed"
#define ROOM_I_HIDE		"_room_i_hide"
#define ROOM_I_NO_ALLOW_STEED   "_room_i_no_allow_steed"
#define ROOM_I_NO_CLEANUP	"_room_i_no_cleanup"
#define ROOM_I_NO_EXTRA_DESC	"_room_i_no_extra_desc"
#define ROOM_I_NO_EXTRA_EXIT	"_room_i_no_extra_exit"
#define ROOM_I_NO_EXTRA_ITEM	"_room_i_no_extra_item"
#define ROOM_S_DARK_LONG        "_room_s_dark_long"
#define ROOM_S_DARK_MSG         "_room_s_dark_msg"
#define ROOM_S_DIR		"_room_s_dir"
#define ROOM_S_EXIT_FROM_DESC   "_room_s_exit_from_desc"
#define ROOM_S_MAP_FILE         "_room_s_map_file"

#define ROOM_I_NO_ATTACK	"_room_m_no_attack"
#define ROOM_M_NO_ATTACK        "_room_m_no_attack"
#define ROOM_I_NO_MAGIC		"_room_m_no_magic"
#define ROOM_M_NO_MAGIC		"_room_m_no_magic"
/* Obsolete, redirected to "no attack" properties. */
#define ROOM_I_NO_MAGIC_ATTACK	ROOM_I_NO_ATTACK
#define ROOM_M_NO_MAGIC_ATTACK  ROOM_M_NO_ATTACK
#define ROOM_I_NO_SCRY          "_room_m_no_scry"
#define ROOM_M_NO_SCRY          "_room_m_no_scry"
#define ROOM_I_NO_STEAL		"_room_m_no_steal"
#define ROOM_M_NO_STEAL         "_room_m_no_steal"
#define ROOM_I_NO_TELEPORT	"_room_m_no_teleport"
#define ROOM_M_NO_TELEPORT      "_room_m_no_teleport"
#define ROOM_M_NO_TELEPORT_TO   "_room_m_no_teleport_to"
#define ROOM_M_NO_TELEPORT_FROM "_room_m_no_teleport_from"

/* *********************************************************
 * Temporary properties
 */
#define TEMP_BACKUP_BRIEF_OPTION        "_temp_backup_brief_option"
#define TEMP_DRAGGED_ENEMIES		"_temp_dragged_enemies"
#define TEMP_LEFTOVER_ORGAN		"_temp_leftover_organ"
#define TEMP_LIBCONTAINER_CHECKED	"_temp_libcontainer_checked"
#define TEMP_OBJ_ABOUT_TO_DESTRUCT      "_temp_obj_about_to_destruct"
#define TEMP_STDCORPSE_CHECKED 		"_temp_stdcorpse_checked"
#define TEMP_STDDRINK_CHECKED 		"_temp_stddrink_checked"
#define TEMP_STDFOOD_CHECKED 		"_temp_stdfood_checked"
#define TEMP_STDPOTION_CHECKED		"_temp_stdpotion_checked"
#define TEMP_STDREAD_CHECKED		"_temp_stdread_checked"
#define TEMP_STDROPE_CHECKED		"_temp_stdrope_checked"
#define TEMP_STDTORCH_CHECKED		"_temp_stdtorch_checked"
#define TEMP_SUBLOC_SHOW_ONLY_THINGS    "_temp_subloc_show_only_things"

/* *********************************************************
 * Wizard properties
 */
#define WIZARD_AM_MAN_SEL_ARR	"_wizard_am_man_sel_arr"
#define WIZARD_AM_SMAN_SEL_ARR	"_wizard_am_sman_sel_arr"
#define WIZARD_I_BUSY_LEVEL	"_wizard_i_busy_level"
#define WIZARD_S_MAN_SEL_CHAPT	"_wizard_s_man_sel_chapt"
#define WIZARD_S_SMAN_SEL_DIR	"_wizard_s_sman_sel_dir"

/* Default property setting, can be used in non-humanoids that want the
 * humanoid behaviour on the no-gift policy.
 */
#define DEFAULT_NO_ACCEPT_GIVE_PROP add_prop(LIVE_M_NO_ACCEPT_GIVE, mobile_deny_objects)

/* No definitions beyond this line. */
#endif PROP_DEF

// SilberLand MUDlib
//
// p/daemon/itemd/itemd.h
//
// $Date: 2009/01/19 13:12:34 $
/* $Revision: 1.29 $
 * $Log: itemd.h,v $
 * Revision 1.29  2009/01/19 13:12:34  mud
 * P_ITEMD_MIGHT (for the might of a item) added
 *
 * Revision 1.28  2006/09/01 07:23:11  Angrox
 * Anpassung an LD-Mudlib
 *
 * Revision 1.27  2005/04/15 08:44:54  Feyaria
 * TIME_ID
 *
 * Revision 1.26  2004/11/20 09:29:01  Feyaria
 * P_ITEMD_PROB_CHANGE
 *
 * Revision 1.25  2004/06/14 16:51:11  Feyaria
 * P_ITEMD_NO_SOCKETED
 *
 * Revision 1.24  2004/03/12 23:27:49  Angrox
 * RUNE_ID hinzugefuegt
 *
 * Revision 1.23  2004/02/02 08:32:51  Angrox
 * P_ITEMD_TMPMAGIC hinzugefuegt
 *
 * Revision 1.22  2003/11/26 18:43:07  Feyaria
 * teleport cost
 *
 * Revision 1.21  2003/10/16 11:13:35  Feyaria
 * P_ITEMD_TELEPORT_COST
 *
 * Revision 1.20  2003/02/28 13:22:16  Angrox
 * P_ITEMD_TIME added
 *
 * Revision 1.19  2002/11/17 12:38:39  Angrox
 * CAIN_SAVE added
 *
 * Revision 1.18  2002/09/13 16:00:06  Angrox
 * P_ITEMD_VIS_SHORT, P_ITEMD_VIS_NAME, P_ITEMD_VIS_LONG, P_ITEMD_SIGN
 *
 * Revision 1.17  2002/06/07 08:57:56  Angrox
 * P_ITEMD_VALUES added
 *
 * Revision 1.16  2001/07/03 15:56:36  Feyaria
 * P_NR_SET_ITEMS
 *
 * Revision 1.15  2001/06/07 21:15:24  Angrox
 * SOCKETED_DIR added
 *
 * Revision 1.14  2001/06/06 08:26:13  Feyaria
 * ITEMD_SET_PATH, P_SET_BONUS
 *
 * Revision 1.13  2001/06/05 12:30:41  Feyaria
 * Set Items
 *
 * Revision 1.12  2001/05/14 12:23:04  Angrox
 * P_ITEMD_SOC_OLDITEM, ITEMD_RUNE_ID, SOC_ID, SOC_M_PEARL .. SOC_M_RUNE added
 *
 * Revision 1.11  2001/04/26 16:24:23  Angrox
 * SECURE_ITEMDD = ITEMDD
 *
 * Revision 1.10  2001/04/25 10:38:55  Angrox
 * P_ITEMD_NO_MAGIC added
 *
 * Revision 1.9  2001/01/26 10:14:24  Angrox
 * ID defines for magic types added
 *
 * Revision 1.8  2001/01/20 22:20:16  Angrox
 * P_ITEMD_PRE_SUFFIX und P_ITEMD_ADDITIONAL_DAMAGE hinzugefuegt
 *
 * Revision 1.7  2000/12/27 12:46:06  Angrox
 * P_ITEMD_OLD_VALUES added
 *
 * Revision 1.6  2000/11/15 17:05:55  Angrox
 * P_ITEMD_WHO_FOUND_IT integriert
 *
 * Revision 1.5  2000/10/19 11:21:22  Angrox
 * P_ITEMD_CAIN_TIME added
 *
 * Revision 1.4  2000/10/03 20:45:53  Angrox
 * ITEMD_PROB_CHANGE, P_ITEMD_ELEMENTAL_VALUE, P_HIGHER_CHANCE, P_LOWER_CHANCE added
 *
 * Revision 1.3  1999/12/03 08:19:51  Angrox
 * ITEMD_DISABLE_LOG hinzugefuegt
 *
 * Revision 1.2  1999/11/04 08:38:10  Angrox
 * X_ATTR_MODIFICATION added
 *
 * Revision 1.1  1999/11/04 08:30:35  Angrox
 * Initial revision
 *
*/

// Changes:
// 18.09.2000 P_ITEMD_ELEMENTAL_VALUE eingebaut
//

#ifndef __ITEMD_H__
#define __ITEMD_H__

#define ITEMDD "/p/daemon/itemd/"
#define SECURE_ITEMDD ITEMDD
#define ITEMD_LOG ITEMDD+"log/"
#define ITEMD_LOGFILE ITEMDD+"log/itemd.log"
#define ITEMD_DISABLE_LOG ITEMD_LOG+"disable_items.log"
#define ITEMD ITEMDD+"itemd"
#define ITEMD_SAVEFILE ITEMDD+"itemd" 
#define CAIN_SAVE ITEMDD+"cain" 
#define ITEMD_DATA_FILE SECURE_ITEMDD+"itemd_data.h"
#define HEADERFILE ITEMD_DATA_FILE+".dump"
#define ITEMD_UNIQUE_PATH SECURE_ITEMDD+"unique/"
#define ITEMD_UNIQUE_ARMOUR ITEMD_UNIQUE_PATH+"armour/"
#define ITEMD_UNIQUE_WEAPON ITEMD_UNIQUE_PATH+"weapon/"
#define SOCKETED_DIR ITEMDD+"socketed/"
#define FUNDIR SECURE_ITEMDD+"functions/"
#define CHARGE_DIR SECURE_ITEMDD+"charge_functions/"
#define ITEMD_TOPLIST ITEMDD+"toplist/itemd_toplist"
#define ITEMD_READTOPLIST ITEMDD+"toplist/itemd_toplist.read"
#define ITEMD_TOPLISTMASTER ITEMDD+"toplist/toplistmaster"
#define ITEMD_SET_PATH SECURE_ITEMDD+"set/"

#define wh(x) write_file(HEADERFILE, x)

#define P_HIGHER_CHANCE "higher_chance"
#define P_LOWER_CHANCE "lower_chance"
#define P_VALUE_FACTOR "value_factor"
#define P_WC_FIX_OFFSET "wc_fix_offset"
#define P_WEIGHT_FACTOR "weight_factor"
#define P_WC_FACTOR "wc_factor"
#define P_AC_FACTOR "ac_factor"
#define P_QUALITY_DECAY_FACTOR "quality_decay_factor"
#define P_DAMAGE_TYPE_ADD "damage_type_add"
#define P_NR_HANDS_OFFSET "nr_hands_offset"
#define P_ITEMD "itemd"
#define P_ITEMD_NAME "itemd_name"
#define P_ITEMD_ELEMENTAL_VALUE "itemd_elemental_value"
#define P_ITEMD_CAIN_TIME "itemd_cain_time"
#define P_ITEMD_WHO_FOUND_IT "itemd_who_found_it"
#define P_ITEMD_OLD_VALUES "itemd_old_values"
#define P_ITEMD_PRE_SUFFIX "itemd_pre_suf"
#define P_ITEMD_ADDITIONAL_DAMAGE "itemd_add_dam"
#define P_ITEMD_NO_MAGIC "itemd_no_magic"
#define P_ITEMD_NO_SOCKETED "itemd_no_socketed"
#define P_ITEMD_SOC_OLDITEM "itemd_soc_olditem"
#define P_SET "set"
#define P_SET_ITEM "set_item"
#define P_SET_BONUS "set_bonus"
#define P_NR_SET_ITEMS "nr_set_items"
#define P_ITEMD_VALUES "itemd_values"
#define P_ITEMD_VIS_SHORT "itemd_vis_short"
#define P_ITEMD_VIS_NAME "itemd_vis_name"
#define P_ITEMD_VIS_LONG "itemd_vis_long"
#define P_ITEMD_SIGN "itemd_sign"
#define P_ITEMD_TIME "itemd_time"
#define P_TELEPORT_COST "teleport_cost"
// ({max,current}), wenn current resets auf 0 -> remove
#define P_ITEMD_TMPMAGIC "itemd_tmpmagic"
#define P_ITEMD_PROB_CHANGE "itemd_prob_change"
#define P_ITEMD_MIGHT "itemd_might"

#define ATTR_MODIFICATION "attr_mod"
#define X_ATTR_MODIFICATION "x_attr_mod"
#define CHARGE_MODIFICATION "charge_mod"
#define ITEMD_PROB_CHANGE "itemd_prob_change"

#define ITEMD_DIS_OBJ_ID "\nitemd_dis_obj_id"
#define ITEMD_CHARGE_OBJ_ID "\nitemd_charge_obj_id"
#define ITEMD_RUNE_ID "\nitemd_rune"
#define ITEMD_EE_MONEY_ID "\nitemd_elemental_essence"

#define HITFUNC FUNDIR+"hitfunc"
#define DEFENDFUNC FUNDIR+"defendfunc"
#define ATTR_MOD FUNDIR+"attr_mod" 
#define STR_FUNC FUNDIR+"str_fun"
#define CON_FUNC FUNDIR+"con_fun"
#define INT_FUNC FUNDIR+"int_fun"
#define DEX_FUNC FUNDIR+"dex_fun"
#define AGGR_FUNC FUNDIR+"aggr_fun"
#define CHARGE_FUNC CHARGE_DIR+"charge_"

#define LOW_MAGIC "low"
#define MED_MAGIC "med" 
#define HIGH_MAGIC "high"
#define VHIGH_MAGIC "vhigh"
#define GODLY_MAGIC "godly" 

#define WEAPON_PREFIX "weapon_prefix"
#define WEAPON_SUFFIX "weapon_suffix"
#define ARMOUR_PREFIX "armour_prefix"
#define ARMOUR_SUFFIX "armour_suffix"

#define LOW_ID 0
#define MED_ID 1
#define HIG_ID 2
#define VHG_ID 3
#define GDL_ID 4
#define RAR_ID 5
#define RST_ID 6
#define SOC_ID 7
#define UNQ_ID 8
#define SET_ID 9
#define RUNE_ID 10
#define TIME_ID 11

#define SOC_M_PEARL 0
#define SOC_M_GEM 1
#define SOC_M_MSTONE 2
#define SOC_M_GPEARL 3
#define SOC_M_GGEM 4
#define SOC_M_JEWEL 5
#define SOC_M_RUNE 6

#endif // __ITEMD_H__

/*
   mudlib: Basis
   flie: attributes.h: 
   created: 1992/07/23
   purpose: provide standardized attribute names to ensure consistency
*/

#ifndef _ATTRIBUTES_H
#define _ATTRIBUTES_H

// first 100 reserved for interfaces to driver builtins (all_inventory etc.)
#define EFUNS 0..99

// all_inventory()
#define a_contains       0
// environment()
#define a_super          1
#define a_uid            2
#define a_ip_address     3

#define a_name         100
#define a_cap_name     102
// internal long description (objects have external longs as well)
#define a_ilong        105
#define a_eshort       106
#define a_cwd          107
#define a_ishort       108
#define a_elong        109
#define a_ids          110
#define a_attached     111
// mass is in grams
#define a_mass         112
#define a_adjectives   113
#define a_quantity     114
#define a_exits        115
#define a_destination  116
#define a_leads_to     117
#define a_arrives_from 118
#define a_is_user      119
#define a_focus        120
#define a_gender       121
#define a_gravity      122
#define a_create_time  123
#define a_real_name    124

// 300..399 for interfaces to set_ and query_ style functions (which may
// or may not be nosave).  These may be useful for security reasons.
#define LFUNS 300..399
#define a_filename     300
#define a_password     301

#define MAKER_RANGE 400..499

#define USER_RANGE 500..599

#define ROOT_RANGE 700..799

#define ADMIN_RANGE 800..899
#define a_permissions   800
#define a_position      801

// 600..699 reserved by Shadowhawk for his mud
#include "attrs/weapon.h" // Attribs 600-619
#include "attrs/armor.h" // Attribs 620-629
#include "attrs/poundage.h" // Attrib 630
#include "attrs/object.h" // Attrib 631
#include "attrs/player.h" // Attribs 650-689
#include "attrs/magic.h" // Attribs from 690-699

// 900..999 reserved for graphical attributes (probably won't need this
// many)
/*
 * 3d/graphical attributes (talk to Jacques)
 */
#define a_coords      900
#define a_scale       901
#define a_rotation    902
#define a_geomfile    903

#endif /* _ATTRIBUTES_H */

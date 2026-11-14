// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /sys/properties.h
// Author:      Gnomi
// Description: Defines fuer Properties
//
// $Log: properties.h,v $
// Revision 1.11  2016/09/18 13:11:26  myonara
// Umbenennung P_CONSERVATION_NO_STORE zu P_CONSERVATION_CONSTRAINT
//
// Revision 1.10  2016/09/12 15:27:52  myonara
// P_CONSERVATION_DATA und P_CONSERVATION_NO_STORE
//
// Revision 1.9  2016/08/31 17:03:56  myonara
// neue mapping-Property P_ORIGIN inkl Schluessel
// P_ORIGIN_ROOM,P_ORIGIN_PLAYER,P_ORIGIN_CREATED_ON
//
// Revision 1.8  2016/05/06 09:49:30  myonara
// P_CONSERVATION mit Subkeys vorbereitet.
//
// Revision 1.6  2015/03/14 11:06:48  myonara
// P_DEBUG_INFO eingebaut.
//
// Revision 1.5  2014/10/18 14:52:39  myonara
// neue defines fuer P_CRACK_CHANCES und Co.
//
// Revision 1.4  2013-04-02 22:13:47  gnomi
// V-Item-Controller eingetragen.
//
// Revision 1.3  2013-03-18 21:44:39  gnomi
// Defines fuer Controllernamen.
//
// Revision 1.2  2013-03-18 20:36:41  gnomi
// Keine Notwendigkeit mehr fuer die Basisnamen.
//
// Revision 1.1  2013-03-16 15:15:20  gnomi
// Property-Implementation.
//

#ifndef __PROPERTIES_H__
#define __PROPERTIES_H__

#define P_NAMESPACE_ROOT    "Root:"

#define P_LOOK_MSG          P_NAMESPACE_ROOT "look_msg"
#define P_READ_MSG          P_NAMESPACE_ROOT "read_msg"
#define P_SMELL_MSG         P_NAMESPACE_ROOT "smell_msg"
#define P_HEAR_MSG          P_NAMESPACE_ROOT "hear_msg"
#define P_ATTACK_MSG        P_NAMESPACE_ROOT "attack_msg"
#define P_FEEL_MSG          P_NAMESPACE_ROOT "feel_msg"
#define P_TAKE_MSG          P_NAMESPACE_ROOT "take_msg"

#define P_NAHRUNG           P_NAMESPACE_ROOT "nahrung"

#define P_CRACK_CHANCES     P_NAMESPACE_ROOT "crack_chances"
#define CRACK_DEFAULT       P_CRACK_CHANCES ":default"
#define CRACK_BOMB          P_CRACK_CHANCES ":bomb"
#define CRACK_LOCK          P_CRACK_CHANCES ":lock"
#define CRACK_MAGIC         P_CRACK_CHANCES ":magic"
#define ALL_CRACK_CHANCES ({CRACK_DEFAULT,CRACK_BOMB,CRACK_LOCK,CRACK_MAGIC})

#define P_DEBUG_INFO        P_NAMESPACE_ROOT "debug_info"
#define P_DEBUG_GROUP       P_NAMESPACE_ROOT "debug_group"

#define P_CONSERVATION      P_NAMESPACE_ROOT "conservation"
#define P_CONSERVATION_PRECHECK    "conservation:precheck"
#define P_CONSERVATION_FACTORY     "conservation:factory"
#define P_CONSERVATION_IDENTIFIER  "conservation:identifier"
#define P_CONSERVATION_ITEM_TARIFF "conservation:item:tariff"
#define P_CONSERVATION_TROPHEY     "conservation:trophey"
#define ALL_P_CONSERVATION_KEYS ({P_CONSERVATION_PRECHECK, \
    P_CONSERVATION_FACTORY, P_CONSERVATION_IDENTIFIER, \
    P_CONSERVATION_ITEM_TARIFF, P_CONSERVATION_TROPHEY })
#define P_CONSERVATION_DATA     P_NAMESPACE_ROOT "conservation:data"
#define P_CONSERVATION_CONSTRAINT P_NAMESPACE_ROOT "conservation:constraint"

#define RESET_CONSERVATION_DATA set(P_CONSERVATION_DATA,({}))
#define RESET_CONSERVATION_CONSTRAINT(f) set(P_CONSERVATION_CONSTRAINT,([]))
#define RELEASE_CONSERVATION_CONSTRAINT(o) ((o)->delete( \
        P_CONSERVATION_CONSTRAINT, "GENERAL_NO" ))

#define P_ORIGIN            P_NAMESPACE_ROOT "origin"
#define P_ORIGIN_ROOM       "origin:first:room"
#define P_ORIGIN_PLAYER     "origin:first_player"
#define P_ORIGIN_CREATED_ON "origin:object:time"

#define CONTROLLER_PROPERTY_NAME(propname) regreplace((propname), "[^A-Za-z0-9_]", "__", 1)

#define MODIFY_SET(propname)       ("modify_set_"      +CONTROLLER_PROPERTY_NAME(propname))
#define FORBIDDEN_SET(propname)    ("forbidden_set_"   +CONTROLLER_PROPERTY_NAME(propname))
#define NOTIFY_SET(propname)       ("notify_set_"      +CONTROLLER_PROPERTY_NAME(propname))
#define MODIFY_QUERY(propname)     ("modify_query_"    +CONTROLLER_PROPERTY_NAME(propname))
#define MODIFY_ADD(propname)       ("modify_add_"      +CONTROLLER_PROPERTY_NAME(propname))
#define FORBIDDEN_ADD(propname)    ("forbidden_add_"   +CONTROLLER_PROPERTY_NAME(propname))
#define NOTIFY_ADD(propname)       ("notify_add_"      +CONTROLLER_PROPERTY_NAME(propname))
#define FORBIDDEN_DELETE(propname) ("forbidden_delete_"+CONTROLLER_PROPERTY_NAME(propname))
#define NOTIFY_DELETE(propname)    ("notify_delete_"   +CONTROLLER_PROPERTY_NAME(propname))

#define MODIFY_SET_V_ITEM(propname)       ("modify_set_v_item_"      +CONTROLLER_PROPERTY_NAME(propname))
#define FORBIDDEN_SET_V_ITEM(propname)    ("forbidden_set_v_item_"   +CONTROLLER_PROPERTY_NAME(propname))
#define NOTIFY_SET_V_ITEM(propname)       ("notify_set_v_item_"      +CONTROLLER_PROPERTY_NAME(propname))
#define MODIFY_QUERY_V_ITEM(propname)     ("modify_query_v_item_"    +CONTROLLER_PROPERTY_NAME(propname))
#define MODIFY_ADD_V_ITEM(propname)       ("modify_add_v_item_"      +CONTROLLER_PROPERTY_NAME(propname))
#define FORBIDDEN_ADD_V_ITEM(propname)    ("forbidden_add_v_item_"   +CONTROLLER_PROPERTY_NAME(propname))
#define NOTIFY_ADD_V_ITEM(propname)       ("notify_add_v_item_"      +CONTROLLER_PROPERTY_NAME(propname))
#define FORBIDDEN_DELETE_V_ITEM(propname) ("forbidden_delete_v_item_"+CONTROLLER_PROPERTY_NAME(propname))
#define NOTIFY_DELETE_V_ITEM(propname)    ("notify_delete_v_item_"   +CONTROLLER_PROPERTY_NAME(propname))

#endif

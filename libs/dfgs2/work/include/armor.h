// armor.h

#ifndef __ARMOR_H__
#define __ARMOR_H__

#define F_ARMOR		"/feature/armor/armor.lpc"
#define F_CLOTH		"/feature/armor/cloth.lpc"
#define F_HEAD_EQ	"/feature/armor/head_eq.lpc"
#define F_HAND_EQ	"/feature/armor/hand_eq.lpc"
#define F_FEET_EQ	"/feature/armor/feet_eq.lpc"
#define F_NECK_EQ	"/feature/armor/neck_eq.lpc"
#define F_FINGER_EQ	"/feature/armor/finger_eq.lpc"
#define F_WRIST_EQ	"/feature/armor/wrist_eq.lpc"
#define F_WAIST_EQ	"/feature/armor/waist_eq.lpc"
#define F_LEG_EQ	"/feature/armor/leg_eq.lpc"

#ifndef __WEAPON_H__
inherit ITEM;
inherit F_ATTRIBUTE;
inherit F_EQUIP;
inherit F_STATISTIC;
#endif

#endif

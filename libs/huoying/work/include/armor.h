// armor.h

#ifndef __ARMOR_H__
#define __ARMOR_H__

/*
      头： 头部(F_HEAD_EQ)  脸部(F_MASK_EQ)    颈部(F_NECK_EQ)    => 面具, 帽子, 项炼
    身体： 衣服(F_CLOTH)    铠甲(F_CLOTH)      腰部(F_WAIST_EQ)   => 铠甲, 衣服, 腰带
      手： 手掌(F_HAND_EQ)  手指(F_FINGER_EQ)  手腕(F_WRIST_EQ)   => 手套, 戒指, 护腕
      脚： 裤子(F_PANTS)    脚掌(F_FEET_EQ)    小腿(F_LEG_EQ)     => 裤子, 鞋子, 绑腿
 */
#define F_HEAD_EQ   "/feature/armor/head_eq.lpc"
#define F_FACE_EQ   "/feature/armor/face_eq.lpc"
#define F_NECK_EQ   "/feature/armor/neck_eq.lpc"

#define F_CLOTH     "/feature/armor/cloth.lpc"
#define F_ARMOR     "/feature/armor/armor.lpc"
#define F_WAIST_EQ  "/feature/armor/waist_eq.lpc"

#define F_HAND_EQ   "/feature/armor/hand_eq.lpc"
#define F_FINGER_EQ "/feature/armor/finger_eq.lpc"
#define F_WRIST_EQ  "/feature/armor/wrist_eq.lpc"

#define F_PANTS     "/feature/armor/pants.lpc"
#define F_FEET_EQ   "/feature/armor/feet_eq.lpc"
#define F_LEG_EQ    "/feature/armor/leg_eq.lpc"
	
#ifndef __WEAPON_H__
//inherit COMBINED_ITEM;
inherit ITEM;
inherit F_ATTRIBUTE;
inherit F_EQUIP;
inherit F_STATISTIC;
#endif

#endif

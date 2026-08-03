// weapon.h

#ifndef __WEAPON_H__
#define __WEAPON_H__

//#pragma no_warnings

#define F_SWORD		"/feature/weapon/sword.lpc"
#define F_BLADE		"/feature/weapon/blade.lpc"
#define F_BLUNT		"/feature/weapon/blunt.lpc"
#define F_AXE		"/feature/weapon/axe.lpc"
#define F_DAGGER	"/feature/weapon/dagger.lpc"
#define F_STAFF		"/feature/weapon/staff.lpc"
#define F_PIKE		"/feature/weapon/pike.lpc"

#ifndef __ARMOR_H__
inherit ITEM;
inherit F_ATTRIBUTE;
inherit F_EQUIP;
inherit F_STATISTIC;
#endif

#endif

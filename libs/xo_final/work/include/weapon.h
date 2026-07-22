// weapon.h

#ifndef __WEAPON__
#define __WEAPON__

#define DEFAULT_WEAPON_LIMB "右手"

#define TWO_HANDED      1
#define SECONDARY       2
#define EDGED           4
#define POINTED         8
#define LONG            16

#define EQUIP_WIELDED   1
#define EQUIP_WORN      2

#define WEAPON                  STD_DIR "weapon/weapon.lpc"

#define AXE                     STD_DIR "weapon/axe"
#define TWOHANDS_AXE            STD_DIR "weapon/twohands_axe"
#define BLADE                   STD_DIR "weapon/blade"
#define DAGGER                  STD_DIR "weapon/dagger" 
#define FAN                     STD_DIR "weapon/fan"
#define FORK                    STD_DIR "weapon/fork"
#define HAMMER                  STD_DIR "weapon/hammer"
#define HOOK                    STD_DIR "weapon/hook"
#define LONG_BLADE              STD_DIR "weapon/long_blade"
#define PEN                     STD_DIR "weapon/pen"    
#define PLATE                   STD_DIR "weapon/plate"
#define QIANG                   STD_DIR "weapon/qiang"
#define SHORT                   STD_DIR "weapon/short"
#define STICK                   STD_DIR "weapon/stick"
#define STICKWHIP               STD_DIR "weapon/stickwhip"
#define SWORD                   STD_DIR "weapon/sword"  
#define STAFF                   STD_DIR "weapon/staff"
//#define THROWING                STD_DIR "weapon/throwing"
#define WHIP                    STD_DIR "weapon/whip"
#define GUN                     "/system/std/weapon/gun"
#define CLUB                    "/system/std/weapon/club"          // 棍

#define F_AXE                   STD_DIR "weapon/_axe"
#define F_TWOHANDS_AXE            "/sysyem/std/weapon/_twohands_axe"
#define F_BLADE                 STD_DIR "weapon/_blade"
#define F_DAGGER                STD_DIR "weapon/_dagger"   
#define F_FAN                   STD_DIR "weapon/_fan"
#define F_FORK                  STD_DIR "weapon/_fork"  
#define F_HAMMER                STD_DIR "weapon/_hammer"
#define F_HOOK                  STD_DIR "weapon/_hook"
#define F_LONG_BLADE            STD_DIR "weapon/_long_blade"
#define F_PEN                   STD_DIR "weapon/_pen"   
#define F_PLATE                 STD_DIR "weapon/_plate" 
#define F_QIANG                 STD_DIR "weapon/_qiang"
#define F_SHORT                 STD_DIR "weapon/_short"
#define F_STICK                 STD_DIR "weapon/_stick"
#define F_STICKWHIP             STD_DIR "weapon/_stickwhip"
#define F_STAFF                 STD_DIR "weapon/_staff"
#define F_SWORD                 STD_DIR "weapon/_sword"
//#define F_THROWING            "/std/weapon/_throwing"
#define F_WHIP                  STD_DIR "weapon/_whip"

int init_weapon( int d, int w, int f );
void set_weapon_type( string s );
#endif


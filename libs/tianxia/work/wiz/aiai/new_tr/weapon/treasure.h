// treasure.h
// Aiai.

#ifndef __TREASURE_LOAD_ITEM__
#define __TREASURE_LOAD_ITEM__

//#define TR_DIR        "/obj/treasure/"
#define TR_DIR  "/wiz/aiai/new_tr/"

#define TR_W_AXE        TR_DIR"weapon/axe"
#define TR_W_BLADE      TR_DIR"weapon/blade"
#define TR_W_DAGGER     TR_DIR"weapon/dagger"
#define TR_W_DHAMMER    TR_DIR"weapon/dhammer"
#define TR_W_HAMMER     TR_DIR"weapon/hammer"
#define TR_W_SPEAR      TR_DIR"weapon/spear"
#define TR_W_STICK      TR_DIR"weapon/stick"
#define TR_W_SWORD      TR_DIR"weapon/sword"
#define TR_W_WHIP       TR_DIR"weapon/whip"
#define TR_W_STAFF    TR_DIR"weapon/staff"
#define TR_W_FAN      TR_DIR"weapon/fan"
#define TR_W_BRUSH    TR_DIR"weapon/brush"
#define TR_W_HOOK     TR_DIR"weapon/hook"
#define TR_W_FORK     TR_DIR"weapon/fork"
#define TR_W_BOW      TR_DIR"weapon/bow"


class weapon_args
{
        string fname;
        string name;
        string id;
        string desc;
        string wield_msg;
        string unwield_msg;
        string material;
        int damage;
        int mangle;
        int weapon_flag;
        string weapon_effect;
} 
#endif


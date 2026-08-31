#ifndef __ACIRI_H__
#define __ACIRI_H__

#define ROOMS   "/wizards/levi/aciri/deathless/"
#define OBJ     ROOMS "obj/misc/"
#define MOB     ROOMS "obj/mon/"
#define WEA     ROOMS "obj/weapon/"
#define ARM     ROOMS "obj/armour/"
#define GUARD   ROOMS "tower/guard_type.lpc"
#define TROOM   ROOMS "tower/room/tower_type.lpc"


int make(string str) { new(str)->move(this_object()); }

int set_auto(int x)  { this_object()->set("aggressive", x); }

#endif

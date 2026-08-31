#ifndef __NIGHTMARE_H__
#define __NIGHTMARE_H__
#define OBJECT "/std/object"
#define LIVING "/std/living"
#define MONSTER "/std/monster"
#define CONTAINER "/std/container"
#define ROOM "/d/nightmare/default/room"
#define DEFAULT "/d/nightmare/default/"
#define LAVA "/std/weather/lava"
#define WEATHER "/std/weather/weather"
#define DAEMON "/std/daemon"
#define BODY "/std/living/body"
#define SKILLS "/std/living/skills"
#define PIER "/std/pier"
#define VAULT "/std/vault"
#define WEAPON "/std/weapon"
#define ARMOUR "/std/armour"
#define MOUNT   "/std/ride"
#define BAG "/std/bag_logic"
#define BARKEEP "/std/barkeep"
#define BBOARD "/std/bboard"
#define MOVE "/std/move"
#define GUILD "/std/guild"

#define POISON "/std/poison"
#define SPELL "/std/spell"

#define REALMS "/d/nightmare/"
#define ROOMS REALMS
#define MOB REALMS"obj/mon/"
#define OBJ REALMS"obj/misc/"
#define WEP REALMS"obj/weapon/"
#define ARM REALMS"obj/armour/"
void make(string str) { new(str)->move(this_object()); }
#endif

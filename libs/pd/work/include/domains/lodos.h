#ifndef __LODOS_H__
#define __LODOS_H__

#define ROOMS   "/d/lodos/"
#define AMAZE     "/d/lodos/amaze/"
#define OBJ     "/d/lodos/obj/misc/"
#define MOB     "/d/lodos/obj/mon/"
#define WEA     "/d/lodos/obj/weapon/"
#define ARM     "/d/lodos/obj/armour/"

int make(string str) { new(str)->move(this_object()); }

#endif

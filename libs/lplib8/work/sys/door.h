/*
 *	door.h
 *
 *	Macros used to define doors
 *
 *	MAKE_DOOR
 *	use as:

 	#include "door.h"

	object	d1, d2, data;

	MAKE_DOOR(d1, "/room/here", ({"north"}), d2, "/room/there", ({"south"}), data);
	d1->move("/room/here");
	d1->set_id(({"oak door", "north door"}));
	d2->move("/room/there");
	d2->set_id(({"oak door", "south door"}));

 *
 *	MAKE_LOCKABLE_DOOR
 *	use as:
 *

 	#include "door.h"

	object	d1, d2, data, lock;

	MAKE_LOCKABLE_DOOR(d1, "/room/here", ({"north"}), d2, "/room/there", ({"south"}), data, lock);
	d1->move("/room/here");
	d1->set_id(({"oak door", "north door"}));
	d2->move("/room/there");
	d2->set_id(({"oak door", "south door"}));

 *
 *	MAKE_KEY
 *	use_as:
 *

	#include "door.h"

	object	key;

	MAKE_KEY(key, "yale");

 *
 *	MAKE_LOCK
 *	use_as:
 *

	#include "door.h"

	object	lock;

	MAKE_LOCK(lock, "yale");

 */
#define MAKE_DOOR(Door1, ToLocation1, Direction1, Door2, ToLocation2, Direction2, DoorData)\
	Door1 = clone_object("/obj/door");\
	Door1->set_exits(({ToLocation1}), Direction1);\
	Door2 = clone_object("/obj/door");\
	Door2->set_exits(({ToLocation2}), Direction2);\
	DoorData = clone_object("/obj/doordata");\
	DoorData->set_gateways(Door1, Door2);\
	Door1->set_door(DoorData);\
	Door2->set_door(DoorData);\
	
#define MAKE_LOCKABLE_DOOR(Door1, ToLocation1, Direction1, Door2, ToLocation2, Direction2, DoorData, LockData)\
	Door1 = clone_object("/obj/lockable_door");\
	Door1->set_exits(({ToLocation1}), Direction1);\
	Door2 = clone_object("/obj/lockable_door");\
	Door2->set_exits(({ToLocation2}), Direction2);\
	DoorData = clone_object("/obj/doordata");\
	DoorData->set_gateways(Door1, Door2);\
	Door1->set_door(DoorData);\
	Door1->set_lock(LockData);\
	Door2->set_door(DoorData);\
	Door2->set_lock(LockData);\

#define MAKE_KEY(Key, Type)\
	Key = clone_object("/obj/key");\
	Key->set_key_type(Type);\
	
#define MAKE_LOCK(Lock, Type)\
	Lock = clone_object("/obj/key_lock");\
	Lock->set_lock_type(Type);\

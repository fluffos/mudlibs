/*
** The general mages' class object.
** Now mages can have class.   ;)
** Cyanide worked all the bugs out, 23 July 1997.
*/

inherit ARMOR;

string path;

void create() {
  seteuid(getuid());
   set("id", ({ "gauntlets" }) );
           set ("short", "gauntlets Paladine") ;
        set ("long", "The Symbol of the Knights.\n") ;
        set ("bulk", 1) ;
        set ("mass", 2) ;
        set ("type", "gloves") ;
		set ("armor", 1);
			set("armor_object", 1);
	   set("prevent_get", 1);
  set("prevent_drop", 1);
  set("prevent_insert", 1);
  set("prevent_clean", 1);
}

void init() {
  add_action("kguild", "kguild");
   if (!living(environment())) remove();
}

int kguild() {
  TP->move_player("/u/d/darkgoth/private/knight/rooms/knightguild");
  return 1;
}

int query_auto_load() { return 1; } 

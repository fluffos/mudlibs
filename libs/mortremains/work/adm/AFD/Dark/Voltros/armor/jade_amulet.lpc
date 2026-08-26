/* Fixed the wear function. */


inherit ARMOR;

void create() {
  seteuid(getuid());
  set("short", "an ornate, silver amulet");
  set("long", @ENDLONG
This amulet is quite large, and is quite heavy for it's size.  It has
a very large peice of jade in the center of an archaic symbol.  Runes
are engraved into the amulet, mainly around the jade.  In the center
of the jade is a ruby in the shape of a drop of blood.
ENDLONG
  );
  set("id", ({
    "amulet",
  }));
	set("size", -1);
  set("bulk", 90);
  set("mass", 70);
  set_value(1600);
  set_type("amulet");
  set_ac(4);
  set("wear_func" , "req_func");
}
int req_func() {
  if ((int)TP->query_level()<18) {
write("You are not advanced enough to wear this amulet.\n");
return 1;
}
else{return 0;}
  }
inherit ARMOR;

void create() {
  seteuid(getuid());
  set("short", "black bracelet");
  set("long", @ENDLONG
This bracelet is crafted from black metal bands, intertwined togther in a rope-like configuration.
ENDLONG
  );
  set("id", ({
    "bracelet",
    "armor",
  }));
  set("bulk", 49);
	set("type", "gloves");
	set("size", -1);
  set("mass", 37);
  set_value(1110);
  set("armor", 4);
}
void init(){add_action("req_func", "wear");}


int req_func()
{
if((int)TP->query_level()<45){
write("A bracelet this powerful would take over your mind, inexperienced one!\n");
    return 1;
  }
else{return 0;}
}


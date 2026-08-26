inherit ARMOR;

void create() {
  seteuid(getuid());
  set("short", "black ring");
  set("long", @ENDLONG
This ring is a single black metal band.
ENDLONG
  );
  set("id", ({
    "ring",
    "armor",
  }));
  set("bulk", 23);
	set("type", "ring");
	set("size", -1);
  set("mass", 6);
  set_value(1510);
  set("armor", 4);
}
void init(){add_action("req_func", "wear");}


int req_func()
{
if((int)TP->query_level()<45){
write("The ring laughs as it slips off your finger!\n");
    return 1;
  }
else{return 0;}
}

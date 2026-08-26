inherit ARMOR;

void create() {
  seteuid(getuid());
  set("short", "black crown");
  set("long", @ENDLONG
This is a plain, black, iron crown.
ENDLONG
  );
  set("id", ({
    "helmet",
		"crown",
    "armor",
  }));
  set("bulk", 53);
	set("type", "helmet");
	set("size", -1);
  set("mass", 26);
  set_value(1880);
  set("armor", 6);
}
void init(){add_action("req_func", "wear");}


int req_func()
{
if((int)TP->query_level()<45){
write("The crown scoffs at you for trying to wear it!\n");
    return 1;
  }
else{return 0;}
}

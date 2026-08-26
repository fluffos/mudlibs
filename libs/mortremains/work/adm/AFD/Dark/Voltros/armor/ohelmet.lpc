/* Fixed the wear_func */

inherit ARMOR;

void create() {
  seteuid(getuid());
  set("short", "opal helmet");
  set("long", @ENDLONG
This is a helm that is made out of Opal.  It is shiny like glass,
and you can see reflections in it.  It is a very large size, so you
don't know if it will fit you.
ENDLONG
  );
  set("id", ({
    "helm",
    "helmet",
    "armor",
  }));
  set("bulk", 10);
	set("type", "helmet");
	set("size", -1);
  set("mass", 20);
  set_value(910);
  set("armor", 5);
}
void init(){add_action("req_func", "wear");}


int req_func()
{
if((int)TP->query_level()<18){
write("You are not seasoned enough to wear this helmet.\n");
    return 1;
  }
else{return 0;}
}

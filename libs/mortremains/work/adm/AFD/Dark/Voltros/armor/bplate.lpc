inherit ARMOR;

void create() {	
  seteuid(getuid());
  set("short", "black platemail");
  set("long", @ENDLONG
This armor is well used.  Dents and nicks riddle the
surface.  It is extremely thick, and you can tell that
it will still be very useful in combat.
ENDLONG
  );
  set("id", ({
    "platemail",
    "armor",
  }));
  set("bulk", 95);
	set("type", "body");
	set("size", -1);
  set("mass", 65);
  set_value(1810);
  set("armor", 10);
}

void init(){add_action("req_func", "wear");}


int req_func()
{
if((int)TP->query("alignment")>-50){
write("The platemail tries to crush you, but you manage to get it off.\n");
    TP->receive_damage(random(30));
    return 1;
  }
return 0;
}


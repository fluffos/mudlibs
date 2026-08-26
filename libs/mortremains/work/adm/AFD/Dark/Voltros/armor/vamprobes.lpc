inherit ARMOR;

void create() {	
  seteuid(getuid());
  set("short", "black robes trimmed with gold");
  set("long", @ENDLONG
These are plain black robes, trimmed with gold thread.  They are
made of a thick, heavy fabric.  You know that these robes would
keep you warm, but you don't know how good they would be in combat.
ENDLONG
  );
  set("id", ({
    "robes",
    "armor",
  }));
  set("bulk", 95);
	set("type", "body");
	set("size", -1);
	set("raise_stat",  "spirit");
	set("modifier", 6);
  set("mass", 60);
  set_value(1910);
  set("armor", 13);
}
void init(){add_action("req_func", "wear");}


int req_func()
{
if((int)TP->query_level()<45){
write("This armor would devour your soul if you were to wear them now!\n");
    return 1;
  }
else{return 0;}
}



inherit ARMOR;

void create() {	
  seteuid(getuid());
  set("short", "plain ringmail");
  set("long", @ENDLONG
Thie rings of this armor are very thick and are very
well made.  They have been interlocked to each other
in a way that would allow full movement.
ENDLONG
  );
  set("id", ({
    "ringmail",
    "armor",
  }));
  set("bulk", 80);
	set("type", "body");
	set("size", -1);
  set("mass", 45);
  set_value(1600);
  set("armor", 9);
}

void init(){add_action("req_func", "wear");}


int req_func()
{
if((int)TP->query("alignment")>-50){
write("You must prove your worth to Desmond before you can don this.\n");
    return 1;
  }
return 0;
}


inherit OBJECT;


void create() {
  set("short", "a leather bound log book");
  set("long", @ENDLONG
This is an ancient tome, bound in tough leather.  Ancient
Keldrosian script has been enscribed in it.  It looks
quite important, maybe you should take it to someone....
ENDLONG
);
  set("id", ({
    "book",
    "log",
    "log book",
    "leather book",
    "quest_OB",
  }));
  set("bulk", 25);
  set("mass", 30);
  set_value(5);
}
void init(){
add_action("read", "read");
}
int read(string str){
  if(!str || str !="book") return 0;
 write("The language the book was written in is impossible to read.\n");
 say(TPN+" tries to read the log book, but can't understand the writing.\n");
return 1;
}
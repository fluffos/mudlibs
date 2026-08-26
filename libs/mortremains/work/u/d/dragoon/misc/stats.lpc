inherit OBJECT;
create() {
   set("short","stat adjuster");
   set("weight",0);
}
void init() {
   add_action("powerup","powerup");
}
int powerup( string arg ) {
   this_player()->set("stat", ([ "strength" : 25, "dexterity" : 25 ]) );
   write( "Power Up complete\n");

return 1;
}

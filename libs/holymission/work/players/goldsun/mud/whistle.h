#define OPN this_player()->query_name()

whistle(){
 write("You are in forest so you desides to be quiet.\n");
 say(OPN+" tries to whistle.\n");
 return 1;
}

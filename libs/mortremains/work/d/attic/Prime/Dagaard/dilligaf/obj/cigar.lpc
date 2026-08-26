#include <mudlib.h>
inherit OBJECT;

void create(){
  seteuid(getuid());
  set( "short" , "A fine cuban cigar");
  set( "long" , @EndText
  This is one of Castro's personal cigars. Its finely rolled paper wraps
  the insides perfectly. It smells like heaven and you can't wait to
  light it. You can <light>, <smoke>, blow smoke<rings>, and <extinguish>.
  it.

EndText
  );
  set("mass" , 1);
  set("bulk" , 1);
  set("id" , ({ "cigar" }) );
}

void init() {
  add_action( "light_cigar" , "light" );
  add_action( "smoke_cigar" , "smoke" );
  add_action( "smoke_rings" , "rings" );
  add_action( "extinguish" , "extinguish");
}
int light_cigar(string str){
  if(!str){
    write("What would you like to light?\n");
  return 1;
  }
  if(str == "cigar"){
    write("You pull a lighter out of nowhere and light your cigar.\n");
    say(TPN+" pulls a lighter out of nowhere and lights a cigar.\n");
    return 1;
  }
  return 1;
}
int smoke_cigar(string str){
  if(!str){
    write("What would you like to smoke?\n");
    return 1;
  }
  if(str == "cigar"){
    write("You take a large drag of the cigar and let it out slowly.\n");
    say(TPN+" takes a large drag of their cigar and lets it out slowly.\n");
    return 1;
  }
  return 1;
}
int smoke_rings(string str){
  if(!str){
    write("You blow perfect smoke rings and watch them sail upwards.\n");
    say(TPN+" blows perfect smoke rings, then watches them float upwards.\n");
    return 1;
  }
  return 1;
}
int extinguish(string str){
  if(!str){
    write("What would you like to extinguish?\n");
    return 1;
  }
  if(str == "cigar"){
    write("You reach into another room and grab an ashtray to snuff out the cigar.\n");
    say(TPN+" reaches into another room and grabs an ashtray to snuff out their cigar.\n");
    remove ();
    return 1;
  }
  return 1;
}

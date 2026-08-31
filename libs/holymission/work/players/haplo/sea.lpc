inherit "players/cashimor/inherit/water";  

#include "/players/goldsun/gen/harb.h"  
#define TP this_player()  
#define CENTRAL_HARBOUR "players/goldsun/gen/room/central_harb"  

string *boat_land;  /*  boat(s) that land here */  
                                        
void reset(int arg) {  

    ::reset(arg);  
    if(!arg) {  
        short_desc="All at sea";  

        long_desc=  
                  "You are on a small wooden pier which leads " +  
                  "out into the sea. This place looks like a " +  
                  "good place to dive. There is a small wooden " +  
                  "sign fixed to the stage.\n";  

        items = ({  
                  "stage","A small wooden boat stage",        
                  "sign","This is a sign, maybe you should read it",  
                });  

        boat_land=({"cargo junk"});  

        set_light(1);  

        dest_dir=({  
//                   "players/beardy/east_harbour/room/road0-1","east",  
                   "room/jetty2","west"  
   
                 });  

        nodanger=1;  

        floats="room/sea_bottom";  

    }  
}  

init() {  

    int i;  
    ::init();  
    if (TP && !TP->query_npc())  
        for(i=0;i<sizeof(boat_land);i++)  
            CENTRAL_HARBOUR->call_boat(file_name(this_object()),boat_land[i]);  
    this_player()->set_smell("You smell of salty seawater.");  
    add_action("dive","dive");  
    add_action("read","read");   
    }  

read(str) {
 if (str=="sign"){ 
       write("This is the landing of the cargo junk to ezo island.\n"+ 
          "The ride is free but the captain asks that you refrain\n"+ 
          "from smoking and observe all safety precautions.\n"+ 
          "Have a safe and enjoyable voyage and try not to get\n"+ 
          "yourself killed on the island.\n");  
  }
 if (str=="read")
    write("Read what ?!\n");
    return 1;
}
int dive() {  
    this_player()->move_player("down#room/sea_bottom");  
    return 1;  
}  


#include <mudlib.h>
#include  <magic.h>

#define EQ query("equipped")
#define WD query("wielded")
#define TP this_player()
#define PN this_player()->query("cap_name")


object AP; //Armour present
object BP; //Boots present
object HP; //Helmet present
object GP; //gloves present
object RSP; //rightsword present
object LSP; //leftsword present
object JSP; //joined sword present

int AS = 0; //Wildfire armour present and worn
int items_present = 0;
int get_items();
int increase( int );
int decrease( int );


int add_bonus() {
   get_items();
   if(!AP || !AP->EQ)
   write("Add bonus call with AS.\n");
   increase(items_present);
   return 1;
}

int increase (int items) {
  // items = items-1;
   write("Bonus increase is "+items+"\n");
   if(AP && AP->EQ) {
     AP->add("bonus", items);
      write("Your armour begins to glow with power.\n");
      say(TP->query("cap_name")+"'s armour begins to glow with a fiery power.\n");
   }
   if(items == 5) {
      write("Your armour's power has reached its full potential!!\n");
     say(TP->query("cap_name")+"'s armour has reached its full potential!!\n");
   }
return 1;
}

int remove_bonus()
{
   get_items();
   if(!AP || !AP->EQ) return 1;
   decrease(items_present);
   return 1;
}

int decrease( int items ) {
   // items = items -1;
   AP->set("armour", 12);
   AP->add("bonus",items);
   write("Bonus is now "+items+".\n");
   write("Your armour loses some of its fiery glow.\n");
   say(TP->query("cap_name")+"'s armour loses some of its fiery glow.\n");
return 1;
}

int add_main() {

 //  AS = 1;  //armour is present and worn.
   get_items();
   write("TOTAL ITEMS IS "+get_items()+"\n");
   if(get_items() == 1)
   increase(items_present-1); //don't want to include armour in calc
   else
   increase(items_present);
   return 1;
}

int remove_main() {
   AP->set("armour",12);
   write("Your armour loses some of its fiery glow.\n");
   say(TP->query("cap_name")+"'s armour loses some of its fiery glow.\n");
 //  AS=0;
   return 1;
}    

int get_items() {
   items_present = 0;
   AP = present("wildfire armour", TP);
   BP = present("wildfire boots", TP);
   HP = present("wildfire helmet", TP);
   GP = present("wildfire gloves", TP);
   RSP = present("longsword of wildfire", TP);
   LSP = present("shortsword of wildfire", TP);
   JSP = present("sword of wildfire", TP);

   if(AP && AP->EQ){
       items_present++;
       write("ARMOUR!\n");
      // AS =1;
   }
   if(BP && BP->EQ)
   {
   write("BOOTS!\n");
       items_present++;
   }

   if(HP && HP->EQ)
   {
    write("HELMET\n");
       items_present++;
   }

   if(GP && GP->EQ)
   {
    write("GLOVES\n");
       items_present++;
   }
   
   if(JSP && JSP->WD)
   {
    write("WILDFIRE SWORD.\n");
       items_present= items_present+2;
   }
   else if(LSP && LSP->WD)
   {
   write("LEFT SWORD\n");
       items_present++;
   }
   else if(RSP && RSP->WD)
   {
       items_present++;
    write("RIGHT SWORD\n");
   }

   write("GET ITEMS DONE!\n");
   return items_present;
}

int everything() {
   get_items();
   if((AP && AP->EQ) && (BP && BP->EQ) && (HP && HP->EQ) && (GP && GP->EQ) && (LSP && LSP->WD) && (RSP &&RSP->WD))
      return 1;
   else if((AP && AP->EQ) && (BP && BP->EQ) && (HP && HP->EQ) && (GP && GP->EQ) && (JSP && JSP->WD))
      return 2;
   else return 0;

}
    



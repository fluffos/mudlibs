#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
#define TPRN this_player()->query_real_name()

#include "/players/cobain/closed/std/ansi.h"

/* 1. During approval: set cost, set file location */

inherit "obj/treasure";
status pagerstatus;
status wizonly;
status cansend;

reset(arg) {
  if(arg) return;
    set_id("cobain_pager");
    set_alias("pager");
    set_weight(0);
    set_value(0);   
}


extra_look() {
 string owner, viewer, temp;
 owner = (string)environment()->query_real_name();
 viewer= TPRN;
 temp = (owner==viewer)?"You have ": capitalize((string)environment()->query_real_name())+" has ";
 temp += "a "+WHT+ "pager"+NORM+" attached to ";
 temp +=((owner==viewer)?"your" : environment()->query_possessive())+" inner wrist";
 return temp;
}

long() {
write("\
A small pager attached to a metallic band. It likes like it could \n\
comfortably slide over a human's forearm. The liquid crystal display\n\
is adjoined across the band. Underneath lies a small speaker and set\n\
of buttons which can be used to page messages to other users.\n\n");

write("The pager is currently switched " +WHT+ (pagerstatus ? "on" : "off") +NORM+".\n");
if (wizonly) write("The pager accepts messages from "+WHT+"wizards only"+NORM +"\n");
write("For usage information: 'pager info'\n");
}


drop() { return 1; } /* Non Droppable */

query_auto_load() {
    return "/players/cobain/obj/dev/pager.c:";
}


init(){
   ::init();
   cansend = 1;
   pagerstatus = 1;
   add_action("pager", "pager");
   add_action("page", "page");
}


/* Pager Configuration */
pager(str) {

  if (environment() != this_player()) return 0;

  switch(str) 
  {
    case "on": { 
        if (pagerstatus == 0) {
            write("The pager display flashes as it activates.\n");
            say(TPN + "'s pager flashes momentarily. \n");
            pagerstatus = 1;
        } else write("Your pager is already on!\n");

        break; }

    case "off": { 
         if (pagerstatus == 1) {
             write("The lighted pager dulls as it deactivates.\n");
             say(TPN + "'s pager light fades away. \n");
         }
         pagerstatus = 0;
         break;}

    case "discard": { 
         write("You detach your pager and toss the pieces away after crushing it.\n");
         say(TPN + " crushes "+TPP+ " pager into pieces and throws it away.");
         destruct(this_object()); 
         break;}

    case "wizonly": { 
        if (wizonly == 0) {
             pager("on");
             wizonly = 1;
             write("Your pager is now activated and only accepts pages from wizards. \n");
         } else {  
             wizonly = 0;          
             write("Your pager is now configured to accept pages from all users. \n"); 
         }
          
         break; }


    case "info": { 
         write("\tOperational Commands: \n");
         write("\t'pager on'                 - Turns the pager on \n");
         write("\t'pager off'                - Turns the pager off \n");
         write("\t'pager wizonly'            - [toggle] Accept wizard pages only \n");
         write("\t'pager discard'            - Permantly discards the pager \n\n");
         write("\tUsage: \n");
         write("\t'page <user> <message>'    - Pages <user> with <message> \n\n"); 
         break; }

    default: pager("info");
  }

  return 1;
}

/* PAGING FUNCTION */

page(pagestring){
    object ob;
    object ob_pager;
    string msg;
    string target;


  /* SETS TARGET USERNAME AND MESSAGE STRING */
    if ( sscanf(pagestring, "%s %s", target, msg) != 2 ) {target = pagestring;}

    target = lower_case(target);
    ob = find_player(target);


  /* PRE SEND ERROR CHECKS */

    if (environment() != this_player()) 
       return (notify_fail("Pick up the pager if you wish to use it.\n"), 0);

    if (pagerstatus == 0) 
       return (notify_fail("You must turn on your pager before attempting to use it.\n"), 0);

    if (this_player()->query_ghost()) 
       return (notify_fail("You cannot page someone as a ghost!\n"), 0);

    if (!pagestring) 
       return (notify_fail("Who do you wish to page?\n"), 0);

    if (!ob || ob->query_invis() > this_player()->query_level() || ob->query_tellblock() != 0 )
       return (notify_fail("Page Failed: \n\"No contact could be made with "+capitalize(target)+"\".\n"), 0);

    if (ob->query_name() == TPN) 
       return (notify_fail("It doesn't make sense to page yourself!\n"), 0);


   /* PAGER ERROR CHECKS */

    ob_pager= present("cobain_pager", ob);

    if(!ob_pager)
       return (notify_fail("Page Failed: "+capitalize(target)+" does not possess a pager.\n"), 0);

   /* CHECKS IF MESSAGES SHOULD ONLY BE RECEIVED BY WIZ's */

    if (ob_pager->query_wizonly() == 1 && ob->query_level() > 19) 
       return (notify_fail("Page Failed: \n\"No contact could be made with "+capitalize(target)+"\".\n"), 0);
      
      
   /* MESSAGE DAEMON */ 

    switch(ob_pager->query_pagerstatus()) {

         case 0: 
           return (notify_fail(capitalize(target)+"'s pager is switched off.\n"), 0);

         case 1:
 
           /* Spam Check */
             if (cansend == 0)
              { write("Your pager is currently processing a page. Try again later !\n"); 
                break; 
              } 

           /* Send Message */
             if (!msg) 
               tell_object(ob, BEEP +YEL+"<" + TPN + ">" + NORM + " is paging you."  + NORM +"\n");
             else 
               tell_object(ob, BEEP +YEL+"<" + TPN +" pages" + "> " + NORM + "\"" +msg+ "\"\n");
               write("Your page has been sent to " + target + ".\n");
           
            /* Spam Fighter here */
             cansend = 0;
             call_out("set_cansend",5);         
             return 1;
    } 

return 1;
}


/* SET FUNCTIONS */
status set_cansend() { cansend = 1; return cansend;}

/* PUBLIC QUERIES */

status query_pagerstatus() {return pagerstatus;}
status query_wizonly() {return wizonly;}
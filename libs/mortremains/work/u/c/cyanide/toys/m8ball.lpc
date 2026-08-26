/*
** File: m8ball.c
** Purpose: Well, mostly because tarot cards are too much of a
**    bother to code...
** Credits:
**    01 Jul 97  Cyanide created the file.
**    15 Apr 98  Chronos loves it.  Makes it a new id- "8ball", makes 
**            the shake command recognize all the id's for the object. :)
**    11 Nov 98  Cyanide actualyy found all 20 CORRECT messages!
*/

#include <mudlib.h>

inherit WEAPON;

// Prototypes:
int shake (string);
void f_message();
void shaken (object);

string says;

void create() {
    set("author", "cyanide");
    set("short", "a Magic 8-Ball (tm)");    
    set ("long", "@@query_long");
    set ("mass", 1);
    set("id", ({ "ball", "8ball", "8-ball", "magic ball", "magic 8-ball", 
      "magic 8ball" }) );
    set("name", "Magic 8 Ball");
    set_weapon_type("club");
    set_verbs ( ({ "shake", "thwop", "whomp"}) );
    set("value", 100 );
    f_message();
}

void init() {
    add_action("shake", "shake");
}

int shake (string ball) {
    if (!id(ball)) {
	write("Shake what?\n");
	return 1;
    }
    say (TPN+" shakes "+POSS+" Magic 8-ball (tm).\n"); 
    write("You joyfully shake your Magic 8-ball.\n");    

    f_message();
    call_out("shaken", 2, this_player());   
    return 1;
}

void f_message() {
    switch(random(20)) {  
    case  0 : says = "Yes"; break; 
    case  1 : says = "My sources say no"; break; 
    case  2 : says = "It is certain"; break; 
    case  3 : says = "Reply hazy try again"; break; 
    case  4 : says = "Very doubtful"; break;         
    case  5 : says = "Ask again later"; break; 
    case  6 : says = "Outlook good"; break; 
    case  7 : says = "Outlook not so good"; break; 
    case  8 : says = "My reply is no"; break;
    case  9 : says = "You may rely on it"; break;
    case 10 : says = "Better not tell you now"; break;
    case 11 : says = "Signs points to yes"; break;
    case 12 : says = "Without a doubt"; break;
    case 13 : says = "Yes definitely"; break;
    case 14 : says = "Concentrate and ask again"; break;
    case 15 : says = "As I see it yes"; break;
    case 16 : says = "Most likely"; break;
    case 17 : says = "Cannot predict now"; break;
    case 18 : says = "Don't count on it"; break;
    default : says = "It is decidedly so"; break;
    }
}

void shaken (object ob) {
    tell_object(ob, "A single cryptic message slowly becomes "+
      "visible in the\nsphere's window: \n");
    tell_object(ob, "\t\""+says+"\".\n");
    return ;
}

string query_long() {
    string short;

    short = wrap("It seems to be a largish black sphere about four "+
      "inches in diameter and bearing a small round window, "+
      "opposite of which a white numeral \"8\" is painted. Within "+
      "the window is a simple, cryptic message:");

    short += "\t\""+says+"\".\n";

    return short;
}

/* 
   This form is given from a level 19 player to a level 25 (or higher) lord
   as a permission to enter the level 20. 13.12.1992 //Frobozz 

   26-Sep-96 / Graah: Now given by lvl 24 player to a level 30 (or higher)
   lord to get to level 25 (new 1st lord level).

  13-Dec-98 / Starks: Took out coder checks for the signing add_action....they can
  be defeated by a simple call, and thus are useless
*/

string who,signer;

id(str) {
    return str=="form" || str=="application form" || str=="application"
    || str=="lord_application";
}

short() {
    return "Application form";
}
query_short() { return "Application form"; }

long() {
    write("Application form of "+capitalize(who)+".\n");
    if(!signer) {
	write("\nThis is an application form that a level 24 player has to give to (at least)\na level 30 lord/lady in order to be able to advance to level 25.\n");
	write("\nNo one has signed it yet.\n");
	return;
    }
    write("\nI, "+capitalize(signer)+", have given my permission to "+capitalize(who)+" to\nadvance to level 25.\n");
    write("\nSigned: "+capitalize(signer)+"\n");
}

init() {
    if(this_player()->query_level() >= 30
      && !this_player()->query_npc())
	add_action("sign","sign");
}

sign(str) {
    if(!id(str)) return;
    if(this_player()->query_level()<30
      || this_player()->query_npc()) return;
    signer=this_player()->query_real_name();
    log_file("LORD_SIGNED",capitalize(who)+" to 25 by "+capitalize(signer)+" at "+ctime(time())+"\n");
    write("Ok.\n");
    return 1;
}

get() { return 1; }

drop() { return; }

query_signed() { return !(!signer); }
set_signed(string str) { signer = str; }

set_applyer(str) { who=str; }

void clean_up() { destruct(this_object()); }

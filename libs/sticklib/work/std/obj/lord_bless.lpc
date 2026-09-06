/* 
   This form is given from a level 24 lord to a level 30 (or higher) lord
   as a permission to enter the level 25. 19.11.1992 //Frobozz 

   26-Sep-96 / Graah: Given by level 29 lord to level 35 (or higher)
   lord to enter level 30.
*/

string who,signer;

id(str) {
    return str=="form" || str=="application form" || str=="application"
    || str=="lord_bless";
}

short() {
    return "Application form";
}

long() {
    if(who)
	write("Application form of "+capitalize(who)+".\n");
    else
	write("Empty application form.\n");
    if(!signer) {
	write("\nThis is an application form that a level 29 lord/lady has to give to\n(at least) a level 35 lord/lady in order to be able to advance to level 30.\n");
	write("\nNo one has signed it yet.\n");
	return;
    }
    write("\nI, "+capitalize(signer)+", have given my permission to "+capitalize(who)+" to\nadvance to level 30.\n");
    write("\nSigned: "+capitalize(signer)+"\n");
}

init() {
    if(this_player()->query_level()>=35 && !this_player()->query_coder_level()
      && !this_player()->query_npc())
	add_action("sign","sign");
}

sign(str) {
    if(!id(str) || !who) return;
    if(this_player()->query_level()<35 || this_player()->query_coder_level()
      || this_player()->query_npc()) return;
    if(signer) {
	write("But it is already signed by "+capitalize(signer)+".\n");
	return 1;
    }
    signer=this_player()->query_real_name();
    log_file("LORD_SIGNED",capitalize(who)+" to 30 by "+capitalize(signer)+" at "+ctime(time())+"\n");
    write("Ok.\n");
    return 1;
}

get() { return 1; }

drop() { return; }

query_signed() { return !(!signer); }

set_applyer(str) { who=str; }

void clean_up() { destruct(this_object()); }

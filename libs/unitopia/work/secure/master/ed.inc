// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/ed.inc
// Description:
//
// $Log: ed.inc,v $
// Revision 1.4  2003/01/25 17:16:49  sissi
// *** empty log message ***
//
//

#pragma strict_types

/* save_ed_setup and restore_ed_setup are called by the ed to maintain
   individual options settings. These functions are located in the master
   object so that the local gods can decide what strategy they want to use.
   suggestions:
	A setup file for every wizard.
		advantages:	transparent to the user
				independent of wizard count
		disadvantage:	extra file access at ed invocation
	An array in the master object, wizards are searched by member_array
		advantage:	easy to implement
		disadvantage:	performance degradation with high wizard counts
	An AVL-tree to access wizards by name
		advantage:	can fit any need
		disadvantage:	hard to implement, will need more overhead on
				small and medium muds than it can ever make
				good by lg(wizcount) complexity
	Dedicated flags in every wizard object, inherited from /obj/living
		advantages:	easy to implement ( as shown here)
				independent of wizard count
				Will also work for nonm-wizards.
		disadvantage:	care has to be taken to avoid collision with
				other uses of the /obj/living flags.          */

/*
 * The wizard object 'who' wants to save his ed setup.
 * Freaky: ich habe das Setup in die Wiz_soul verlegt...
 *         jetzt braucht man beim ed-start keine File-Access mehr :)
 */
int save_ed_setup(object who, int code) {

    if (!intp(code) || !objectp(who))
	return 0;
    who->set_ed_setup(code);
    return 1;
}

/*
 * Retrieve the ed setup.
 */
int retrieve_ed_setup(object who) {
    if (!objectp(who))
	return 0;
    return ({int})who->query_ed_setup();
}

/*
 * Give a file name for edit preferences to be saved in.
 */
string get_ed_buffer_save_file_name(string file) {
    string *file_ar;

    file_ar=explode(file,"/");
    file=file_ar[<1];
    return "/w/"+({string})this_player()->query_real_name()+
	"/.dead_ed_file_"+file;
}

/* Diese Funktion wird vom Parser aufgerufen, wenn ein Spieler
 * im ED das Kommando e <File> benutzt und <File> nicht mit
 * einem '/' anfaengt
 */
string make_path_absolute(string path) {
    //debug_message(sprintf("MPA: TP:%O PATH:%O CS:%O\n",this_player(),path,caller_stack(1)));
    //if (objectp(this_player()) && stringp(path))
    return ({string})this_player()->add_path(path);
}

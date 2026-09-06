// By Kieve sometime for someone...
// I don't even remember any more =)
#include <treasure.h>

#define ENV(xx)     environment(xx)
#define TP          this_player()
#define TN          TP->query_name()
#define HE          TP->query_pronoun()
#define HIM         TP->query_objective()
#define HIS         TP->query_possessive()

void create_treasure() {
    set_name("angel wings");
    set_id( ({ "wings", "angel wings" }) );
    set_short("Angel wings");
    set_long("This is a set of pure white angel wings. They flutter and "+
      "appear as light as air, and twice as soft. When not in use, they "+
      "sit majestically folded against his side. Their beauty is "+
      "that of a creation of the Gods themselves.");
    set_weight(0);
    set_value(0);
}

void init_treasure() {
    add_action("do_wembrace", "wembrace");
    add_action("do_wings", "wings");
}

status do_wembrace(string args) {
    // Hug something/someone.
    object ob;

    if(!args  ||  args == ""  ||  args == TP->query_real_name()) {
	// hug themself.
	TP->tell_me("You embrace yourself with your angel wings.");
	ENV(TP)->tell_me(TN+" wraps "+HIS+" angel wings around "+
	  HIM+"self.", TP);
	return 1;
    }
    if(!ob = present(args, ENV(TP)))
	if(!ob = present(args, TP))
	    return notify_fail("There is no "+args+" here!\n"), 0;

    TP->tell_me("You embrace "+ob->query_name()+" with your angel wings.");
    ob->tell_me("The wings of "+TN+" embrace you with a silent whisper "+
      "of feathers. Suddenly you feel very comfortable, protected "+
      "and warm. You know that faith smiles on your future, and all "+
      "shall be alright.");
    ENV(TP)->tell_here(TN+" embraces "+ob->query_name()+" with "+HIS+
      " angel wings.", ({ TP, ob }));
    return 1;
}

status do_wings(string args) {
    notify_fail("Which command did you want to do (1-6)?\n");

    if(!args || args == "")
	return 0;

    // Each case costs 20k gc
    switch(args) {
    case "1" :
	TP->tell_me("You feel depressed and drag your angel wings "+
	  "on the ground.");
	ENV(TP)->tell_here(TN+" feels depressed and drags "+HIS+
	  " angel wings on the ground.", TP);
	break;
    case "2" :
	TP->tell_me("Your angel wings shiver in ecstacy.");
	ENV(TP)->tell_here(TN+"'s angel wings shiver in ecstacy.", TP);
	break;
    case "3" :
	TP->tell_me("You move your angel wings slowly, keeping the "+
	  "room cool.");
	ENV(TP)->tell_here(TN+"'s wings move slowly, cooling the room.",
	  TP);
	break;
    case "4" :
	TP->tell_me("You leave the ground, and fly away.");
	ENV(TP)->tell_here(TN+" leaves the ground, and flies away.", TP);
	break;
    case "5" :
	TP->tell_me("You fly back to heaven.");
	ENV(TP)->tell_here(TN+" flies back to heaven.", TP);
	break;
    case "6" :
	TP->tell_me("You show the trademark of 'Kieve' on your angel "+
	  "wings");
	ENV(TP)->tell_here(TN+" shows you the trademark of 'Kieve' on "+
	  HIS+" angel wings.", TP);
	break;
    default : return 0;
    }
    return 1;
}

int catch_show(object shower, object showee) {
    showee->tell_me(query_long());
    return 1;
}

int query_prevent_steal() { return 1; }

int drop() { return 1; }
int get()  { return 0; }

string query_auto_load() {
    string fname;
    sscanf(object_name(this_object()), "%s#%~d", fname);
    return fname+":";
}

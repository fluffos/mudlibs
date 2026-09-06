#include <npc.h>

#include <treasure_defs.h>
#include <gender.h>

object crown,friend;

void reset_monster()
{
    if(!crown) {
	// It probably should be a tiny 'armour'... ?
	crown = clone_object(TREASURE_FILE);
	crown->set_name("crown");
	crown->set_value(30);
	crown->set_short("An iron crown");
	crown->set_long("It's a small iron crown.");
	move_object(crown,this_object());
    }
}
void create_monster()
{
    set_name("frog");
    set_short("A sad-looking little frog");
    set_level(1);
    set_frog();
    set_wimpy(20);
    set_wc(4);
    set_ac(2);
    load_chat(2,({"The frog says: Please kiss me.",
	"The frog says: I was a royal person.",
	"The frog says: Evil magic turned me into a frog.",
	"The frog bursts into tears."
      }));
    reset_monster();
}

void
catch_tell(string arg)
{
    string a,b;
    object from;

    if(sscanf(arg,"%s arrives%s",a,b)==2) {
	if(!a) return;
	if(find_player(lower_case(a))) {
	    if(frog) {
		environment()->tell_here("The frog says: "+a+", please help me!",
		  this_object());
		return;
	    }
	    if(find_player(a)==friend)
		environment()->tell_here("The "+name+" says: Hello, my dear friend " +
		  capitalize(a)+"!", this_object());
	}
	return;
    }
    if(!frog) return;
    if(!(from = this_player())) return;
    if((int)from->query_lord()>4) return; /* They can frog/unfrog themselves */
    if(sscanf(arg,"%s kisses you.",a)) {
	if(!frog) return;
	friend = from;
	if((int)from->query_gender()==G_FEMALE) {
	    set_name("prince");
	    set_short("A handsome prince");
	    load_chat(1,({"The prince smiles happily."}));
	    set_gender(1);
	}
	else {
	    set_name("princess");
	    set_short("A beautiful princess");
	    load_chat(1,({"The princess smiles happily."}));
	    set_gender(2);
	}
	environment() -> tell_me(
	  "There is a puff of smoke as the frog polymorphs!", this_object());
	frog_curse(0);   /* set_frog() sets always  frog = 1 */
	set_level(16);
	set_wc(20);
	set_ac(10);
	money = 100 + random(200);
	/* Give the player a small amount of xp. Can be collected just
	   once per reset (and the prince(ss) must be killed first) */
	from->add_exp(150);
	from -> tell_me("You feel more experienced!");
    }
}

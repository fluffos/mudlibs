/*
** CREATOR: Ilzarion@Nightfall's Keep
** Changes:
**    21 Jan 98  Cyanide@NK neatened it up a bit, and patch a few things.
*/

#include <mudlib.h>

inherit OBJECT;

string query_long();

void create() {
    seteuid(getuid());

    set("id", ({ "talisman", "spell talisman" }) );
    set("short", "Spell Talisman");
    set("long", "@@query_long");
    set("prevent_get", 1);
    set("prevent_drop", 1);
    set("prevent_clean", 1);
    set("prevent_sell", 1);
}

int query_auto_load() { return 1; }     

void init(){
    add_action("spstore", "spstore");
    add_action("tpstore", "tpstore");
    add_action("recover", "recover");
}

string query_long(){
    int sp, tp;
    string str;

    sp = (int)query("spstore");
    tp = (int)query("tpstore");
    str = "This is a spell talisman for storing spell or theurgy "+
     "points.\nPriests may tpstore, and mages may spstore.\n"+
     "Type \"recover\" to get the ALL points back.\nThere are ";

    if (sp) str+= sp + " spell points ";
    if (sp&&tp) str += " and ";
    if (tp) str += tp + " theurgy points ";
    str += "currently stored.";

    return(wrap(str));
}

int spstore (){
    int sp;

    sp = (TP->query_level("wizard") * 10);

    if (TP->query("spell_points") < sp){
	write ("You dont have that many sp's left!\n"+
	 "You must have at least "+sp+" spell points to "+
	 "charge the talisman.\n");
	return 1;
    }
    if (this_object()->query("spstore")){
	write ("You already have spell points stored!\n");
	return 1;
    }
    TP->set("spell_points", (TP->query("spell_points") - sp));
    this_object()->set("spstore", this_object()->query("spstore") + sp);
    write ("You store "+sp+" spell points in your talisman.\n");
    return 1;
}


int tpstore (){
    int sp;

    sp = (TP->query_level("priest") * 10);

    if (TP->query("theurgy_points") < sp){
	write ("You dont have that many tp's left!\n"+
	 "You must have at least "+sp+" theurgy points to "+
	 "charge the talisman.\n");
	return 1;
    }
    if (this_object()->query("tpstore")){
	write ("You already have theurgy points stored!\n");
	return 1;
    }

    TP->set("theurgy_points", (TP->query("theurgy_points") - sp));
    this_object()->set("tpstore", this_object()->query("tpstore") + sp);
    write ("You store "+sp+" theurgy points in your talisman.\n");
    return 1;
}

int recover (){

    write ("you recover your stored points from your talisman.\n");
    TP->set("spell_points", (this_object()->query("spstore") + 
     TP->query("spell_points")));
    if (TP->query("spell_points") > TP->query("max_sp"))
	TP->set("spell_points", (TP->query("max_sp")));
    TP->set("theurgy_points", (this_object()->query("tpstore") + 
     TP->query("theurgy_points")));
    if (TP->query("theurgy_points") > TP->query("max_tp"))
	TP->set("theurgy_points", (TP->query("max_tp")));

    this_object()->set("tpstore", 0);
    this_object()->set("spstore", 0);
    return 1;
}

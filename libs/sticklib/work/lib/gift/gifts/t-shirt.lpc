// +- Flagg
#include <treasure.h>
#define TP this_player()

string paitadesc;

void create_treasure() {
    set_name("paita");
    set_id("t-shirt","t-paita", "shirt", "t shirt");
    set_short("T-shirt with text 'WHATEVER' on it");
    set_long(
      "A nice t-shirt indeed, you can change the text on it (magik!)\
\nCommand to use is: teepaita <text> \nAnd if you get bored with it,\
command 'destaa paita' helps ... (it destructs the shirt so be careful)"
    );
    set_value(0);
    set_weight(0);
    paitadesc = "WHATEVER";
}

string query_short(int mode, object who){
    return "T-shirt with text '"+paitadesc+"' on it";
}

void init_treasure() {
    add_action("teepaita", "teepaita");
    add_action("destaa", "destaa");
}

status destaa(string str){
    if (!str || str != "paita")
	return notify_fail("DOH, destaa paita?\n"),0;
    TP->tell_me("Paita veke, jeps.");
    destruct(this_object());
    return 1;
}

status teepaita(string str){
    if(!str) return notify_fail("Pls gimme some desc, idiot.\n"),0;
    if(sizeof(str) > 40) return notify_fail("Too long desc!\n"),0;
    paitadesc = str;
    return 1;
}

int get()  { return 1; } 
int drop() { return (this_player()->query_coder_level()) ? 0:1; }

string query_auto_load() {
    return "/lib/gift/gifts/t-shirt:"+paitadesc;
}

void init_arg(string arg){
    if(!(sscanf(arg, "%s", paitadesc))) paitadesc = "HASSUA";
    return;
}

string extra_look(){
    if(environment()->query_name()==capitalize(environment()->query_real_name()) )
	return environment()->query_name()+" is wearing a COOL t-shirt with a text '"+paitadesc+"' ... you feel jealous...want one too!";
    else return "";
}


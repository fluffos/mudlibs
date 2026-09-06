#include <npc_defs.h>
#include <gender.h>

object shadowed;
string pretit;

void do_shadow(object ob, string pret, int mode) {
    if(!ob) return;
    if(!pret) return;
    shadowed = ob;
    pretit   = pret;
    shadow(shadowed);
    return;
}

void end_shadow(){
    unshadow();
    destruct(this_object());
}

string query_pretitle() {
    return pretit+" ";
}

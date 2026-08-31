#include <std.h>
#include <aziraphale.h>

void do_kill_check(object tp) {
    if(tp->query_property("killersmark") == 1) return;
    tp->add_alignment(-500);
    message("info", "\nYou have killed a Kra'toan on the sacred land of their home.\nYou shall forever bear the mark of a murderer of their people.", tp, );
    tp->set_property("killersmark", 1);
}

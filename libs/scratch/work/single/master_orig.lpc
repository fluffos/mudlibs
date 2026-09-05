
#include <globals.h>

object connect() {

    object o;
    mixed err;

    err = catch (o = new(ECHOCHAMBER));

    if (err) {
        write("Error.\n");
        write(err);
        destruct(this_object());
    }

    return o;
}

// This is a dummy object for the login.c.
// It will autodestruct itself after a short time.

nomask void
create() {
    call_out("clean_up", 1);
}

nomask int
clean_up(int ref) {
    destruct(this_object());
}

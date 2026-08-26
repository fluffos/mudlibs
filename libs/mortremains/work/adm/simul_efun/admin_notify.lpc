/*
 * Admin_notify (efun)
 * Sends a message to all admin currently on.
 * Cyanide, 17 Sep 1999
 */

void admin_notify(string str) {
    object *users = users();
    int i, sz;

    sz = sizeof(users);
    for (i=0; i<sz; i++) {
	if (adminp(users[i]))
	    tell_object(users[i], str);
    }
}

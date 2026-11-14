/*
 * No more query_password - we have query_password_ok,
 * which does the check here instead.
 */

query_password_ok(string p) 
{
    if (!password) return 1;
    string sp = "secure/crypt"->crypt(p, password[..1]);
    if (password == sp)
	return 1;
    return 0;
}

nosave set_password(string s) {
    password = "secure/crypt"->crypt(s, 0);
    }

/*
 * This one is called when the player wants to change his password.
 */

nosave change_password(arg) {
    if (password != 0 && !arg) {
	write("To change your password: \"password <old-password>\".\n");
	return 1;
    }
    if (password != 0 && !query_password_ok(arg)) {
	write("Wrong old password.\n");
	return 1;
    }
    toggle_echo();
    write("New password: ");
    password2 = 0;
    input_to("change_password2", 1);
    return 1;
}

nosave change_password2(arg) {
    if (!arg) {
	write("Password not changed.\n");
	return;
    }
    if (password2 == 0) {
	password2 = arg;
        toggle_echo();
	write("Again: ");
	input_to("change_password2", 1);
	return 1; // was return 0 - Jenna Feb 01
    }
    if (password2 != arg) {
	write("Wrong! Password not changed.\n");
	return 1;
    }
    set_password(password2);
    password2 = 0;
    write("Password changed.\n");
    return 1;
}

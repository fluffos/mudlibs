// QUick for fun.

int cmd_page( string str ) {
    object *usrs = users();
    int i;
    int num = sizeof(usrs);
    str = "An intercom clicks on and the voice of "+TPN+
    " says: " + str;
    str = iwrap(str);

    for (i=0; i < num; i++) {
	tell_object(usrs[i], str);
    }

    return 1;
}

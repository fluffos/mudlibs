inherit "/std/cmd_m";

nomask int request_privileges(object what) {

	if ((int)master()->query_member_group(geteuid(what), "root"))
		return 1;
	return 0;
}

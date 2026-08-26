/*
**  File: _testreg.c
**  Purpose: Test character registration.
**  Creator: Cyanide (But did it at Nightmask's Dungeon)
**  Changes:
**    18 Jun 98  Cyanide made it work for admin w/ multi- 
**               testers.
*/

#include <logs.h>

#define SYNTAX "Syntax: testreg <test char> to <wizard>"

void reg_log (string);

inherit DAEMON;

int cmd_testreg (string str) {
    object testr, wiz;
    string *tests;
    string testr_n, wiz_n;

    seteuid(getuid());

  if (!str) {
   write("Usage: testreg <char> to <wiz>\n") ;
   return 1;
  }
    if (sscanf(str, "%s to %s", testr_n, wiz_n) != 2) {
	write (SYNTAX+"\n");
	return 1;
    }

    if (!adminp(TP)) {
	write("You are not allowed to do that.\n");
	reg_log(TPN+" tried to register "+testr_n+" to "+
	  wiz_n);
	return 1;
    }

    testr = find_player(lower_case(testr_n));
    if (!testr) {
	write(capitalize(testr_n)+" is not on the mud.\n");
	return 1;
    }

    wiz = find_player(lower_case(wiz_n));
    if (!wiz) {
	write(capitalize(wiz_n)+" is not on the mud.\n");
	return 1;
    }

    if (testr->query("tester_of")) {
	write(testr->query("cap_name")+" is already registered to "+
	  capitalize((string)testr->query("tester_of"))+".\n");
	return 1;
    }

    if ((wizardp(testr)) && (!adminp(wiz))) {
	write ("Only administrators may have test wizards.\n");
	return 1;
    }

    if (!wizardp(wiz)) {
	write ("Ordinary mortals cannot have test characters!\n");
	return 1;
    }

    if (wiz->query("test_char")) {
	if (stringp(wiz->query("test_char")))
	    wiz->set("test_char", ({ wiz->query("test_char") }) );

	if (adminp(wiz)) {
	    tests = (string *)wiz->query("test_char");
	    tests = tests + ({ testr_n });
	    wiz->set("test_char", tests);
	} else {
	    write("Only administrators may have multiple test characters.\n");
	    return 1;
	}
    } else {
	wiz->set("test_char", ({ testr_n }) );
    }

    testr->set("tester_of", wiz_n);

    wiz_n = capitalize(wiz_n);
    testr_n = capitalize(testr_n);

    reg_log(TPN+" registered "+capitalize(testr_n)+" to "+
      capitalize(wiz_n));

    write (testr_n+" has been registered to "+wiz_n+".\n");
    tell_object(wiz,TPN+" has registered "+testr_n+" to you.\n");
    tell_object(testr,TPN+" has registered you as the test character "+
      "of "+wiz_n+".\n");
    return 1;
}

void reg_log (string log_this) {

#ifdef TESTREG_LOG
  log_file(TESTREG_LOG, iwrap(log_this+" ["+extract(ctime(time()),
	4, 15) + "]"));
#endif

} //end reg_log()

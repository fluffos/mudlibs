// shows the current students and their expire time.
// Mobydick@TMI-2, 9-21-93.

#include <mudlib.h>
#include <config.h>
#include <daemons.h>

inherit DAEMON ;

int cmd_students() {

    mapping students, sponsors ;
    int i, starttime ;
    string *names ;
    string msg ;

    students = STUDENT_D->query_student_list() ;
    sponsors = STUDENT_D->query_sponsor_list() ;
    names = keys(students) ;
    write ("Students as of "+ctime(time())+":\n") ;
    printf("%12-s %12-s %28-s %5-s\n","Name", "Sponsor", "Expire Time", "Note") ;
    for (i=0;i<sizeof(names);i++) {
	starttime = students[names[i]]+STUDENT_TIME_PERIOD ;
	msg="" ;
	if (starttime<time()) msg="EXPIRED" ;
	if (starttime+SAVE_FILES_PERIOD<time()) msg="REMOVE DIRECTORY" ;
	printf("%12-s %12-s %28-s %5-s\n", capitalize(names[i]),
		capitalize(sponsors[names[i]]),ctime(starttime),msg) ;
    }
    return 1 ;
}


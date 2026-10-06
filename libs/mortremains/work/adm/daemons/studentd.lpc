 
//	File	:  /adm/daemons/studentd.c
//	Creator	:  Watcher@TMI-2  (5/22/93)
//
//	This daemons controls the access to the student directories
//	and the individual student's access time length.

#include <uid.h>
#include <daemons.h>
#include <mudlib.h>
#include <config.h>
 
inherit SERVER;
 
#define ERROR_LOG	"STUDENT_ERROR"
#define SAVE_FILE	(STUDENT_DIR + "STUDENTS")
 
void load_students();
 
mapping students = ([]);
mapping sponsors = ([]) ;

void create() {


	seteuid(getuid(this_object()));
	load_students();

}
 
//  This function performs the retrieval of the student information
//  data from the SAVE_FILE when the create() function is called.
 
void load_students() {
   string err;
 
   err = catch( restore_object(SAVE_FILE) );

   if(err)  log_file(ERROR_LOG, "[" + extract(ctime(time()),4,15) +
		     "]  Error in load_students()\n  " + err + "\n");

}
 
 
//  This function performs the saving of the present student 
//  information data into the predefined SAVE_FILE.
 
void save_students() {
   string err;

   err = catch( save_object(SAVE_FILE) );

   if(err)  log_file(ERROR_LOG, "[" + extract(ctime(time()),4,15) +
		     "]  Error in save_students()\n  " + err + "\n");

}
 
 
//  This function will return the time the user first was made a
//  student in integer time ... it returns 0 if the user is not
//  a recognized student by the daemon.
 
int query_student(string name) {  return students[name];  }


// This one returns the name of the student's sponsor.
 
int query_sponsor (string name) {  return sponsors[name] ; }
 
//  This function adds a user to the student mapping along with the
//  time they were given student priviledges. It is only accessible
//  by ROOT or Admin status calls.

varargs
int add_student( string name, string sponsoring_person ) {

   if(!adminp(geteuid(previous_object())) &&
      geteuid(previous_object()) != ROOT_UID)   return 0;
 
   //	If no name is given, or the name is already in the student
   //	mapping, return 0 to the calling object.
 
   if(!name || students[name])  return 0;
 
   //	Add the user to the student mapping with the present time.
 
   students[name] = time();
   sponsors[name] = sponsoring_person ? sponsoring_person : this_player()->query("name") ;

   //	Save the student mapping for future use.
 
   save_students();
 
return 1; }
 
 
//  This function removes a user from the student mapping, if that
//  name is already present.  Only accessible by ROOT or Admin calls.
 
int remove_student(string name) {
 
   if(!adminp(geteuid(previous_object())) &&
      geteuid(previous_object()) != ROOT_UID)  return 0;
 
   // 	If no name is given, or the name is not in the student
   //	mapping, then return 0 to the calling object.
 
   if(!name || !students[name])  return 0;

   //	Remove the user from the student mapping.

   map_delete(students, name);
   map_delete(sponsors, name) ;
 
   //	Save the student mapping for future use.

   save_students();

return 1; }
 
 
//  This function allows the modification of a student's beginning
//  time so that they may be extended in their duration.

int modify_student(string name, int when) {

   if(!adminp(geteuid(previous_object())) &&
      geteuid(previous_object()) != ROOT_UID)  return 0;
 
   //  	If no name or time given, or no such user ... return 0;
 
   if(!name || !when || !students[name])  return 0;
 
   //	Modify the user's time setting.
 
   students[name] = when;

   //	Save the students mapping for future use.

   save_students();

return 1; }
 
 
//  This function returns the amount of time a user has left in
//  their student period. It will return -1, if the user is not a 
//  recognized student.
//  It returns a negative value if the student is over time. Note that
//  you can't tell a response of -1 meaning the person is not a student
//  from a -1 meaning the person is 1 second over time. Since the latter
//  is obviously a rare event, -1 can always be treated as meaning the
//  person is not a student.

 
int query_time_left(string name) {
   int left;

   //	If no name, or the name is not a student ... return -1

   if(!name || !students[name])  return -1;

   left = students[name] + STUDENT_TIME_PERIOD - time();

return left; }
 
 
//  This function is the simple student mapping dump. If the requester
//  isn't ROOT_UID, then give them a copy ... just in case. :)

mapping query_student_list() {

   if(geteuid(previous_object()) != ROOT_UID)
	return copy(students);

return students; }

// This function returns the list of sponsors.

mapping query_sponsor_list() {

   if(geteuid(previous_object()) != ROOT_UID)
       return copy(sponsors) ;

return sponsors ;
}

 
 
//  This function will return an array of all students who have
//  used up their student time.
 
string *query_overdue() {
   string *who;

   who = keys(students);

   who = filter_array(who, "filter_overdue", this_object());

return who; }
 
protected int filter_overdue(string name) {
   return (students[name] + STUDENT_TIME_PERIOD > time());  
}
 

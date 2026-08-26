 
//	File	:  /adm/simul_efun/user_path.c
//	Creator	:  Someone@TMI  (Sometime)
//
//	Modified for student directory use by Watcher@TMI-2 (5/93)
//      Mobydick added the is_user_path() function, 93-11-1.
 
#include <config.h>
#include <daemons.h>
 
string user_path(string name) {
 
   if(!name) return "";
 
   if(STUDENT_D->query_student(name))
	return ("/student/" + name + "/");
 
   return sprintf("/u/%c/%s/", name[0], name);
}

// This simul_efun takes a path and an optional name. If the name arg
// is passed, then it returns 1 if path is (name)'s directory and 0 if
// not. If no name is passed, it returns the name of the wizard if path
// is a valid directory for some user, and returns 0 if not.
// Note that it does not check whether that user is actually a wizard,
// or whether the directory exists or not. It only checks if the path
// can be mapped to a name, and if some player of that name exists.

varargs mixed is_user_path (string path, string name) {

    string s1,s2 ;

    if (name) {
	if (sscanf(path,"/u/%s/%s",s1,s2)!=2) {
	    if (!STUDENT_D->query_student(name)) return 0 ;
	    if (sscanf(path,"/student/%s",s1)!=1) return 0 ;
	    if (s1!=name) return 0 ;
	    return 1 ;
	}
	if (s1[0] != s2[0])  return 0;
	if (s2!=name) return 0 ;
	return 1 ;
    }
    if (sscanf(path,"/student/%s",s1)==1) {
	if (STUDENT_D->query_student(s1)) return s1 ;
	return 0 ;
    }
    if (sscanf(path,"/u/%s/%s",s1,s2)!=2) return 0 ;
    if (s1[0] != s2[0])  return 0;
    if (!user_exists(s2)) return 0 ;
    return s2 ;
}

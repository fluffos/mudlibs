string query_mvis() {

  string str;

  str = (string)this_object()->getenv("MVIS") + "";
  if ( strsrch ( str, "$N" ) == (-1) )
    str = "$N appears out of the corner of your eye.";
  str = substr( str, "$N", (string)this_object()->query("cap_name") );
  return str;
}

string query_minvis() {

  string str;

  str = (string)this_object()->getenv("MINVIS") + "";
  if ( strsrch ( str, "$N" ) == (-1) ) str = "$N seems to disappear.";
  str = substr( str, "$N", (string)this_object()->query("cap_name") );
  return str;
}
string query_mhome() {

  string str;

  str = (string)this_object()->getenv("MHOME") + "";
  if ( strsrch ( str, "$N" ) == (-1) ) str = "$N heads home.";
  str = substr( str, "$N", (string)this_object()->query("cap_name") );
  return str;
}

string query_mzap(object target, int flag) {
  string str, victim ;
  if (!target) victim = "Someone" ;
  else
  victim = target->query("cap_name") ;
  str = (string)this_object()->getenv("MZAP") + "" ;
   if (strsrch(str,"$N")==-1)
  str = "$N summons lightning that strikes $V in the chest." ;
  if (!flag) {
  str = substr(str, "$N", (string)this_object()->query("cap_name")) ;
  str = substr(str, "$V", victim) ;
  }
  if (flag==1) {
  str = substr(str, "$N", (string)this_object()->query("cap_name")) ;
  str = substr(str, "$V", "you") ;
  }
  if (flag==2) {
   str = substr(str, "$N", "You") ;
  str = substr(str, "$V", victim) ;
  }
  return str ;
}

string query_mdest(object obj) {

  string str;

  str = (string)this_object()->getenv("MDEST") + "";
  if ( strsrch ( str, "$N" ) == (-1) || strsrch ( str, "$O" ) == (-1) )
    str = "$N disintegrates $O.";
  str = substr( str, "$N", (string)this_object()->query("cap_name") );
  if ( obj == 0 || !obj -> query ("short") )
    str = substr( str, "$O", "something" );
  else
    str = substr( str, "$O", (string)obj->query("short") );
  return str;
}

string query_mhalt() {
  string str ;
  str = (string)this_object()->getenv("MHALT") + "" ;
  if (strsrch(str, "$N") == -1) 
    str = "There is a bright flash of light as $N ends his battle." ;
 str = substr(str, "$N", (string)this_object()->query("cap_name") ) ;
 return str ;
}

string query_mclone(object obj) {

  string str;

  str = (string)this_object()->getenv("MCLONE") + "";
  if ( strsrch ( str, "$N" ) == (-1) || strsrch ( str, "$O" ) == (-1) )
    str = "$N gets creative and makes $O.";
  str = substr( str, "$N", (string)this_object()->query("cap_name") );
  if ( obj == 0 || !obj -> query ("short") )
    str = substr( str, "$O", "something" );
  else
    str = substr( str, "$O", (string)obj->query("short") );
  return str;
}
/*  -*- LPC -*-  */
// This file contains the stuff for those funky movement messages you
// see when you move around... actually other people see them and not you.
// Be kind and admit that while you don't know who wrote this, that it did
// come from TMI.
// While you're at it, admit to a sneaking suspicion that Sulam may have
// been the author, although the concept probably goes back further than
// that.
// Modified to use strsrch() by Dent@TMI-2 9301009

string query_min(string dir) {

  string str;

  str = (string)this_object()->getenv("MIN") + "";
  if ( strsrch ( str, "$N" ) == (-1) ) str = "$N enters from $D.";
  str = substr( str, "$N", (string)this_object()->query("cap_name") );
  if (!dir) dir = "somewhere" ;
  if (strsrch ( str, "$D")) str = substr(str, "$D", 
      dir ) ;
  return str;
}

string query_mout(string dir) {

  string str;

  str = (string)this_object()->getenv("MOUT") + "";
  if ( strsrch ( str, "$N" ) == (-1) || strsrch ( str, "$D" ) == (-1) )
    str = "$N leaves $D.";
  str = substr( str, "$N", (string)this_object()->query("cap_name") );
  if ( dir == "" || dir == 0 ) dir = "somewhere";
  str = substr( str, "$D", dir );
  return str;
}

string query_mmin() {

  string str;

  str = (string)this_object()->getenv("MMIN") + "";
  if ( strsrch ( str, "$N" ) == (-1) ) str = "$N appears from the shadows.";
  str = substr( str, "$N", (string)this_object()->query("cap_name") );
  return str;
}

string query_mmout() {

  string str;

  str = (string)this_object()->getenv("MMOUT") + "";
  if ( strsrch ( str, "$N" ) == (-1) ) str = "$N fades into the shadows.";
  str = substr( str, "$N", (string)this_object()->query("cap_name") );
  return str;
}


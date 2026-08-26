string query_mvis() {

  string str;

  str = (string)this_object()->getenv("MVIS") + "";
  if ( strsrch ( str, "$N" ) == (-1) )
    str = "$N appears out of the corner of your eye.";
  str = replace_string( str, "$N", (string)this_object()->query("cap_name") );
  return str;
}

string query_minvis() {

  string str;

  str = (string)this_object()->getenv("MINVIS") + "";
  if ( strsrch ( str, "$N" ) == (-1) ) str = "$N seems to disappear.";
  str = replace_string( str, "$N", (string)this_object()->query("cap_name") );
  return str;
}
string query_mhome() {

  string str;

  str = (string)this_object()->getenv("MHOME") + "";
  if ( strsrch ( str, "$N" ) == (-1) ) str = "$N heads home.";
  str = replace_string( str, "$N", (string)this_object()->query("cap_name") );
  return str;
}

string query_mdest(object obj) {

  string str;

  str = (string)this_object()->getenv("MDEST") + "";
  if ( strsrch ( str, "$N" ) == (-1) || strsrch ( str, "$O" ) == (-1) )
    str = "$N disintegrates $O";
  str = replace_string( str, "$N", (string)this_object()->query("cap_name") );
  if ( obj == 0 || !obj -> query ("short") )
    str = replace_string( str, "$O", "something" );
  else
    str = replace_string( str, "$O", (string)obj->query("short") );
  return str;
}

string query_mclone(object obj) {

  string str;

  str = (string)this_object()->getenv("MCLONE") + "";
  if ( strsrch ( str, "$N" ) == (-1) || strsrch ( str, "$O" ) == (-1) )
    str = "$N gets creative and makes $O.";
  str = replace_string( str, "$N", (string)this_object()->query("cap_name") );
  if ( obj == 0 || !obj -> query ("short") )
    str = replace_string( str, "$O", "something" );
  else
    str = replace_string( str, "$O", (string)obj->query("short") );
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

string query_min() {

  string str;

  str = (string)this_object()->getenv("MIN") + "";
  if ( strsrch ( str, "$N" ) == (-1) ) str = "$N enters.";
  str = replace_string( str, "$N", (string)this_object()->query("cap_name") );
  return str;
}

string query_mout(string dir) {

  string str;

  str = (string)this_object()->getenv("MOUT") + "";
  if ( strsrch ( str, "$N" ) == (-1) || strsrch ( str, "$D" ) == (-1) )
    str = "$N leaves $D.";
  str = replace_string( str, "$N", (string)this_object()->query("cap_name") );
  if ( dir == "" || dir == 0 ) dir = "somewhere";
  str = replace_string( str, "$D", dir );
  return str;
}

string query_mmin() {

  string str;

  str = (string)this_object()->getenv("MMIN") + "";
  if ( strsrch ( str, "$N" ) == (-1) ) str = "$N appears from the shadows.";
  str = replace_string( str, "$N", (string)this_object()->query("cap_name") );
  return str;
}

string query_mmout() {

  string str;

  str = (string)this_object()->getenv("MMOUT") + "";
  if ( strsrch ( str, "$N" ) == (-1) ) str = "$N fades into the shadows.";
  str = replace_string( str, "$N", (string)this_object()->query("cap_name") );
  return str;
}



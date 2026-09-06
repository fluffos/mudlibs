#include "../bincmd.h"

inherit BASICXCMD;

QueryAbrev() { return "xgr"; }

int XGrepFile(string pat, string file) {
  int i, f;
  string tfile, *ts, t;

  if(!(pat&&file)) return 0;
  tfile="/players/"+getuid(cloner)+"/.tmp";
  for(i=1; t=read_file(file, i, 1000); i+=1000) {
    if(sizeof(ts=regexp(explode(t, "\n")-({""}), pat))) {
      if(!f++) write_file(tfile, "*** File: "+file+" ***\n");
      write_file(tfile, implode(ts, "\n")+"\n");
    }
  }
  return 1;
}

int main( string str ) {
  int i, s, t;
  string *files, *ts;

  if ( (!str) || (str=="?") )
    return notify_fail( "xgr(ep) <regexp> <filepattern>\n"),0;

  if ( ! ( ( ts = old_explode( str, " " ) ) &&
	   ( ( s = sizeof( ts ) ) > 1 ) ) ) return 0;

  str = implode( ts[0..s-2], " " );

  if ( ! ( regexp( ({ "dummy" }), str ) ) ) {
    tell_object( cloner, "Bad regular expression.\n" );
    return 1;
  }

  if(file_size("/players/"+getuid(cloner)+"/.tmp") > 0 ) 
    rm("/players/"+getuid(cloner)+"/.tmp" );

  if((t=sizeof(files=long_get_dir(XFile(ts[s-1]), 0)))&&
     (file_size(files[0])>=0)) {
    for(i=0; i<t; i++) XGrepFile(str, files[i]);
    XMoreFile( "/players/"+getuid(cloner)+"/.tmp", 0);
    rm( "/players/"+getuid(cloner)+"/.tmp" );
  }
  else
    tell_object( cloner, "Cannot read file(s).\n" );

  return 1;
}




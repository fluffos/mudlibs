#include "../bincmd.h"

inherit BASICXCMD;

QueryAbrev() { return "xfo"; }

int main( string str ) {
  int i, s, t, u, rc;
  string pat, cmd, arg, *strs, *files, fh, fr, fe, ft, ff;

  if ( (!str) || (str=="?") )
    return notify_fail( "xfo(rall) <filepattern> <command>\n"),0;

  if(sscanf(str, "%s %s", pat, arg)!=2) return 0;
  files=long_get_dir(pat, 0);
  if(!(s=sizeof(files))) {
    tell_object( cloner, "No matching files found.\n" );
    return 1;
  }
  strs=explode(files[0], "/");
  fh="/";
  if(t=sizeof(strs)-1) fh+=implode(strs[0..t-1], "/");
  for(i=0; i<s; i++) {
    ft=explode(files[i], "/")[t];
    if((u=sizeof(strs=explode(ft, ".")))&&--u) {
      ff=implode(strs[0..u-1], ".");
      fr=fh+"/"+ff;
      fe=strs[u];
    } else {
      fe="";
      ff=ft;
      fr=files[i];
    }
    cmd="/lib/string"->string_replace(arg, "!!", files[i]);
    cmd="/lib/string"->string_replace(cmd, "!e", fe);
    cmd="/lib/string"->string_replace(cmd, "!f", ff);
    cmd="/lib/string"->string_replace(cmd, "!h", fh);
    cmd="/lib/string"->string_replace(cmd, "!r", fr);
    cmd="/lib/string"->string_replace(cmd, "!t", ft);

    dispatcher->IncreaseNostore();
    rc = cloner->command_me( cmd );
    dispatcher->DecreaseNostore();
    if ( ! rc )
      break;
  }
  return 1;
}




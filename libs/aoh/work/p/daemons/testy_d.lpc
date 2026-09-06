/*--------------------------------------------------------------------------
 * /p/daemons/testy_d.c  --  The testy-daemon
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * The testy-daemon handles the testylist
 */

#include <properties.h>

#define TESTY_LIST "/etc/TESTY_LIST"

mapping tlist;

void create() {
  mixed s,list,i;

  seteuid(getuid());

  tlist=([]);

  s = read_file(TESTY_LIST);
  if ( ! s )
    return;

  list = explode( s, "\n" );

  for (i=sizeof(list)-1;i>=0;--i) {
    s = explode( norm_id(list[i])," ");
    if ( ( sizeof( s ) >= 1 ) &&
         ( sizeof(s[0]) > 1 ) &&
         ( s[0][0] != '#' ) )
      tlist[s[0]] = (sizeof(s)>1 ? s[1] : "?");
  }
}

mixed QueryTestyList() {
  return m_indices(tlist);
}

mixed CheckTesty(mixed name) {
  mixed t;
  if (objectp(name)) {
    if (!({int})name->Query(P_IS_LIVING))
      return 0;
    name=({string})name->QueryRealName();
  }
  name=lower_case(name);

  if ( t = tlist[name] )
    return t;
  return 0;
}

#include <search.h>
inherit "/std/thing";

create() {
  ::create();
  AddId("failchk");
}

magic() {
  mixed a;
  a = search(this_player(), "all", SEARCH_ENV|SM_MULTI);
  a = ( ({((a=({0})),(a[0]=a)),(a=0)})[0] = m_indices(a)[0] );
}

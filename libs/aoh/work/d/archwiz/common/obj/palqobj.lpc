/* questobject for the 'free_turanu' quest
   Cadra@nightfall 12-01-95 */

#include "path.h"

inherit "/std/thing";

string partner,code,melody;
int wandgiven,ring;

create() {
  SetShort(0);
  SetLong("");
  SetIds(({"palaceobj"}));
}

public int sort_fun(string a,string b) {
  string *arr;
  arr = explode(code,"");
  return member(arr,a)<member(arr,b);
}

SetRing() { ring=1; }
SetPartner(string name) { partner=name; }
SetCode(string str) { code=str; }
SetMelody(string str) { melody=str; }
SetWandGiven() { wandgiven=1; }

QueryPartner() { return partner; }
QueryCode() { return code; }
QueryMelody() { return melody; }
QueryWandGiven() { return wandgiven; }
QueryReverseCode() {
  return implode(sort_array(explode(code,""),#'sort_fun),"");
}
QueryRing() { return ring; }

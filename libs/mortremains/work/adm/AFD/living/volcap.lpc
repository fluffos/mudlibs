int query_capacity() ;
int query_volume() ;

int query_volume() {
// chronos removed the type cast hgere.
    return query_capacity() / 10;
}

int query_capacity() {
  int v,s;
  v = this_object()->query("stat/strength");
  s = this_object()->query("size");
/*
  s = 20 + (s*2);
   v = 450 + ((v*s)/2);

  Changed by Cyanide - going to the pound standard...
*/
    if (!(s) || (s==0)) {
      s = 1;
     }

    s = (2*s*s)+28;
    v = ((6*v*v)/10)+49;
    s = (s/100);
    if (s<1) s=1;
    v = (v*s);
    return v;
  if (wizardp(TO)) v += 3000 ;
}

int fix_volcap() {
  object *inv ;
  int i, cap, vol ;
  cap = query_capacity() ;
  vol = query_volume() ;
  inv = all_inventory(this_object()) ;
  this_object()->set("volume", vol );
  this_object()->set("capacity", cap );
  if (!inv) return 1;
  for(i=0;i<sizeof(inv);i++) {
// Chronos removed the type casts on these vars.
    cap -= inv[i]->query("mass") ;
    vol -= inv[i]->query("bulk") ;
  }
  this_object()->set("capacity", cap) ;
  this_object()->set("volume", vol) ;
  return 1;
}

int reset_stats() {
  tell_object(this_object(),
  "** Your stats have been reset by "+this_player()->query("cap_name") + 
  ".\n");
  if (!this_object()->query("stat")) 
       this_object()->set("stat", ([ ]) );
  return 
  this_object()->set("stat", this_object()->query("base_stat")) ;
  return 1;
}

int query_mass() {
  //Written by Cyanide Dec 30, 1996
  int sz;

  sz = this_object()->query("size");

  sz = (5*sz*sz)+10;

  return sz;
}

int query_bulk() {
  int mass;

  mass = this_object()->query("mass");
  mass = (mass/10);
  if (mass<1) mass = 1;

  return mass;
}


void remove() {

  int i;
  object *inv ;

  inv = all_inventory(this_object()) ;
  if (!inv || sizeof(inv) == 0) {
    ::remove() ;
   return ;
  }  // Just in case we have no inventory!
  for(i=0;i<sizeof(inv);i++) {
    inv[i]->remove() ;
  }
  :: remove() ; // this calls the original remove function to continue
                // removing this object..

}

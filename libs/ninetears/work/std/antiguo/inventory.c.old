/* Hamlet's twists on all_inventory().  DON'T DELETE.  Rod needs these. */
/* These all work similarly to all_inventory():  They receive an object */
/* (usually a room), and return a list of objects within that object.   */
 
/* living_inventory()      returns everything living.                      */
/* liv_not_creator_inv()   returns all living that isn't a creator         */
/* interactive_in_room()   returns all interactive()s in the room          */
/* players_in_room()       returns all interactive()s that aren't creators */
 
object *living_inventory(object what) {
  object *all = all_inventory(what);
  object *alive;
  int i;
  int maxi = sizeof(all);
  int *theliving = allocate(maxi);
  int j=0;
  
  for(i=0;i<maxi;i++)
    if(living(all[i])) {
      theliving[j] = i;
      j++;
    }
    
  if(!j) return alive;
  
  alive = allocate(j);
  
  for(i=0;i<j;i++)
    alive[i] = all[theliving[i]];
    
  return alive;
}
 
 
object *liv_not_creator_inv(object what) {
  object *all = all_inventory(what);
  object *alive;
  int i;
  int maxi = sizeof(all);
  int *theliving = allocate(maxi);
  int j=0;
  
  for(i=0;i<maxi;i++)
    if( living(all[i]) && !all[i]->query_creator() ) {
      theliving[j] = i;
      j++;
    }
    
  if(!j) return alive;
  
  alive = allocate(j);
  
  for(i=0;i<j;i++)
    alive[i] = all[theliving[i]];
    
  return alive;
}
 
 
object *interactive_in_room(object what) {
  object *all = all_inventory(what);
  object *inter;
  int i;
  int maxi = sizeof(all);
  int *theinter = allocate(maxi);
  int j=0;
  
  for(i=0;i<maxi;i++)
    if(interactive(all[i])) {
      theinter[j] = i;
      j++;
    }
    
  if(!j) return inter;
  
  inter = allocate(j);
  
  for(i=0;i<j;i++)
    inter[i] = all[theinter[i]];
    
  return inter;
}
 
 
object *players_in_room(object what) {
  object *all = all_inventory(what);
  object *players;
  int i;
  int maxi = sizeof(all);
  int *theplayers = allocate(maxi);
  int j=0;
  
  for(i=0;i<maxi;i++)
    if( interactive(all[i]) && !all[i]->query_creator() ) {
      theplayers[j] = i;
      j++;
    }
    
  if(!j) return players;
  
  players = allocate(j);
  
  for(i=0;i<j;i++)
    players[i] = all[theplayers[i]];
    
  return players;
}

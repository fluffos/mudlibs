#define INVLIST invlist()
invlist() { 
  int i; object *dir;
  dir=all_inventory(environment(this_player()));
  for(i=0;i<sizeof(dir);i++)
    if(dir[i]->short() && dir[i]!=this_player()) 
      write(capitalize(dir[i]->short()+"\n"));
}


status doKeep(object ob)
{
 string objName, objShort;
 object shadowObj;
 if(!ob || !(objShort = (string)ob->short()) || ob->query_auto_load())
  return 0;
 objName = (string)ob->query_name();
 if(ob->queryKept())
 {
  write("You are already keeping "+(objName?objName:objShort)+".\n");
  return 0;
 }
 shadowObj = clone_object("obj/user/keep_shadow");
 shadowObj->doShadow(ob);
 write("Keeping: "+(objName?objName:objShort)+".\n");
 return 1;
}


int cmd_keep(string str)
{
 string all, type;
 object obj, next_obj;
 if(!str)
 {
  write("Usage: 'keep <object>', 'keep eq', 'keep all'.\n");
  return 1; 
 }
 if(str == "all")
 {
  obj = first_inventory(this_player());
  write("\n\tKeeping all inventory items...\n");
  while(obj)
  {
   next_obj = next_inventory(obj);
   doKeep(obj);
   obj = next_obj;
  }
  if(!this_player()->query_invis())
   say((string)this_player()->query_name()+
    " rearranges "+possessive(this_player())+" inventory.\n");
  write("Done.\n");
  return 1;
 }
 if(str == "eq" || str == "equipment")
 {
  obj = first_inventory(this_player());
  write("\n\tKeeping all equipment...\n");
  while(obj)
  {
   next_obj = next_inventory(obj);
   if((obj->is_armor() && obj->query_worn()) || (obj->is_weapon() && (obj->query_wielded() || obj->query_offwielded())))
    doKeep(obj);
  obj = next_obj;
  }
  if(!this_player()->query_invis())
   say((string)this_player()->query_name()+
    " rearranges "+possessive(this_player())+" equipment.\n");
  write("Done.\n");
  return 1;
 }

 /* all option added by Gnar */
 if( sscanf(str, "%s %s", all, type ) == 2 ) {
   if( all == "all" ) {
     write("Keeping all "+type+"...\n");
     obj = first_inventory(this_player());
     while(obj) {
      next_obj = next_inventory(obj);
      if( obj->id(type) ) {
        doKeep(obj);
      }
      obj = next_obj;
     }
     if(!this_player()->query_invis())
       say((string)this_player()->query_name()+
         " rearranges "+possessive(this_player())+" equipment.\n");
     write("Done.\n");
     return 1;
   }
 }
 if(!(obj = present(str, this_player())) || !obj->short())
 {
  write("You don't have "+str+".\n");
  return 1;
 }
 if(!doKeep(obj))
  return 1;
 if(!this_player()->query_invis())
  say((string)this_player()->query_name()+
   " rearranges something in "+possessive(this_player())
  +" inventory.\n");
 return 1;
}

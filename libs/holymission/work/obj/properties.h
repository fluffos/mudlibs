
/* properties 

   This file puts properties into a property list in the living.
   Properties are saved in the playerfile, so please don't add
   any before speaking with an Archwiz.

   If you are Archwiz and you add a property, please write it 
   in a helpfile under /doc named properties, so that anyone
   can see which properties can be used.
                                                               */

mapping props;

/*
 This function adds a property into a living. When the property     
 already exist, it deletes the old property and adds the new one.

 Example: ob->add_property("bank_accounts",(["wukies_broker":200]));
          ob->add_property("smell","smells sexy");
          ob->add_property("magic_armour_class",100);
                                                                 */

int add_property(string prop,mixed res)
{
   int sec;
   string name;

      if (!mappingp(props))
           props = ([]);
      if (!prop || !res)  
           return 0;
      if (member(props,prop)==1)
      {
          props = m_delete(props,prop); 
          sec = 1;
      } 
      else 
          sec = 2;
      props = props + ([prop:res]);

// security log 
      if (interactive(this_object()))
      {
          if (!name = this_player()->query_real_name())
               name = file_name(this_player());
          if (sec == 1)
          {
              log_file("DELETED.PROP",
              "#"+prop+" by "+name+" of "+this_object()->query_real_name()+ 
              " at "+ctime(time())+"\n");
          }
          else 
          {
              log_file("ADDED.PROP",
              "*"+prop+" by "+name+" of "+this_object()->query_real_name()+ 
              " at "+ctime(time())+"\n");
          }
      }    
   return 1;
}
             
/*
 This function asks the living if the property exists. When true
 it returns the argument set into the property. Else it returns -1.     

  Example: if (!smell = ob->query_property("smell")) 
                write("You don't smell.\n");
           else 
                write("You smell like "+smell+".\n");
                                                                 */

mixed query_property(string prop)
{
    if (!prop)
        return 0;
    else if (!mappingp(props) || !props[prop])
        return -1;
    else 
       return props[prop];
}

     
/*
 This function removes a property from the property list. When the
 property exists it returns 1, else -1.     

 Example: if (ob->remove_property("resist_fire"))
              write("You lost your ability to restist fire.\n"); 
                                                                 */
mixed remove_property(string prop)         
{
    string name;

      if (!prop)
          return 0;
      else if (!mappingp(props) || member(props,prop)!=1)
          return -1;
      props = m_delete(props,prop);
// security log
      if (interactive(this_object()))
      {
         if (!name = this_player()->query_real_name())
              name = file_name(this_player());
         log_file("DELETED.PROP",
               "#"+prop+" by "+name+" of "+this_object()->query_real_name()+ 
               " at "+ctime(time())+"\n");
      }
   return 1;
}
  
/*
 This function returns all properties of a living in an array. 

 Example: if (sizeof(ob->property_list()) > 100)
              write("Wow, you have lots of properties.\n");
                                                                 */

string *property_list()
{
    if (!mappingp(props))
        return ({});
    return(m_indices(props));
}

/* 
    sending error object  - Mythos <12-7-97>
    file containing the list of room paths is /open/SEND_ERR
    <note: there are default mangle objects in case file is wiped
*/

#define FILE "/open/SEND_ERR"
#define DEF 6
#define FAIL_PERCENTAGE  10+random(6)      /* currently 10 - 15% failure */
#define MANGLE_PERCENTAGE 10+random(6)     /* currently 10 - 15% object is 
                                              mangled */
#define FAILED_CHOICE 30   /* this is the chance the object when 
                             failing the initial check may be sent to
                             the wrong person
                             currently 30% object is mis-sent
                             else it is dested */
#define WEP_CLASS_DOWN 5   /* if object is a weapon object class
                              is reduced by random(WEP_CLASS_DOWN) */
#define ARMOR_CLASS_DOWN 5 /* if object is an armor object class
                              is reduced by random(ARMOR_CLASS_DOWN) */
#define CLASS_CHANCE 70    /* this is the chance the object if it is a
                              weapon or armor is reduced 
                              currently 70% class is reduced
                              else it gets mangled into another object */
string path;
int num_path;

reset(arg) {
  if(arg) return;
  if(!read_file(FILE)) {
    path = allocate(DEF);
    num_path = DEF;
    pathset();
  } else {
    setting();
  }
call_out("check",1);
}

check() {
  if(environment(this_object())) destruct(this_object());
return 1; }

pathset() {
   path[0] = "obj/corpse";
   path[1] = "obj/stethoscope";
   path[2] = "obj/safe";
   path[3] = "obj/rope";
   path[4] = "obj/newspaper";
   path[5] = "obj/dice";
}

setting() {
  string reader;
  int h;
  reader = explode(read_file(FILE),"\n");
  num_path = DEF + sizeof(reader);   /* number of paths */
  path = allocate(num_path);
  pathset();
  for(h = 0;h<sizeof(reader);h++)
    path[(DEF - 1) + h] = reader[h];

}

/* function to call when sending objects player to player */

send(object ob,object tp) {
object pep,who;
object ob2;
int j,k,i,h;
   if(random(100) < FAIL_PERCENTAGE) {
      j = 0;
     if(random(100) < FAILED_CHOICE) {
      pep = users();
      who = pep[random(sizeof(pep))];
      if(who->query_level() > 19) j = 0;
      else {
        j = 1;
        tell_object(tp,"The object is sent to the wrong person!\n");
        move_obect(ob,who);
        tell_object(who,"Something has been sent to you accidentally!\n");
      }
     }
     if(!j) {
       tell_object(tp,"The object is destroyed in the transfer process!\n");
       destruct(ob);
     }
   return 0;} 
   if(random(100) < MANGLE_PERCENTAGE) {
    j = 0;
     if(ob->weapon_class() || ob->armor_class()) 
       if(random(100) < CLASS_CHANCE) {
         j = 1;
         if(ob->weapon_class()) 
           ob->set_class(ob->weapon_class() - random(WEP_CLASS_DOWN));
          else ob->set_class(ob->armor_class() - random(ARMOR_CLASS_DOWN));
       }
       if(!j) {
         k = 0;
         while(!k) {
           ob2 = clone_object(path[random(num_path)]);
           if(ob2->query_value() < ob->query_value()) k = 1;
           else k = 0;
           if(ob2->weapon_class() && ob->weapon_class()) {
             if(ob2->weapon_class() < ob->weapon_class()) k = 1;
             else k = 0; }
           if(ob2->armor_class() && ob->armor_class()) {
             if(ob2->armor_class() < ob->armor_class()) k = 1;
             else k = 0; }
         }
         destruct(ob);
         ob = ob2;
       }
   return ob; }
   return ob;
}

/* 
   thus when sendng objects one does the following:
     object before;    / this is the object that is being sent
     object after;
     if(after = call_other("obj/base_send","send",objectbeingsent,sender))
          before = after;
     send_object_before();
*/

/*  
    basically should the send() return 0 the object is either dested or
    sent to the wrong party
    else it will return an object which is then to be sent
    to the original target player... note: this object could be
    'mangled' or not.  in any case the actual sending of an 
    object is successful, but the object sent may not be exactly what 
    it was before
*/


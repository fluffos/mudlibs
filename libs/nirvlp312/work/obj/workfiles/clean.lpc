#define LOGCLEAN 0
int no_clean;
clean_up() {
  string a,b,fname;
  object thi_ob,env_ob,env_ob2,obfile;
  /* if there is a custom_clean() run it. if custom clean returns positive
     don't go further, if not continue. -Bp 
  */
  if(!this_object()) return 1;
  if(this_object()->custom_clean()) return 1;
  /* if using a custom clean as a replacement, set_no_clean should be
     used to prevent regular clean_up from working, unless of course you
     want it that way. -Bp 
  */
  if (no_clean) return 1;
  thi_ob = this_object();
  env_ob = environment(this_object());
  if(env_ob)
    env_ob2 = environment(env_ob);

  if(LOGCLEAN == 3) {
    if(thi_ob) {
      if(env_ob)
        log_file("CLEAN",ctime(time())+" "+file_name(thi_ob)+
        " clean CALLED environ:"+file_name(env_ob)+"\n");
      else
        log_file("CLEAN",ctime(time())+" "+file_name(thi_ob)+
        " clean CALLED NO ENVIRON\n");
      }
    }
  if(env_ob) {
    if(extract(file_name(env_ob),0,19)=="players/boltar/hotel") return 1;
    if(sscanf(file_name(env_ob),"%shotel%s",a,b)==2) return 1;
    if(env_ob->query_dont_clean_obs_here()) return 1;
    if(env_ob2) {
      if(sscanf(file_name(env_ob2),"%shotel%s",a,b)==2) return 1;
      if(env_ob2->query_dont_clean_obs_here()) return 1;
    }
    if(is_player_here()) return 1;
    if (call_other(env_ob, "query_npc",0)){
       /*
         env_ob->clean_up();
         Not needed, can only cause problems, let npc's clean up on their
         own. -Bp
       */
      return 1;
    }

   if (call_other(env_ob, "query_interactive",0)) return 1;
   if(environment(env_ob)) {
   if(environment(env_ob)->query_npc())
      return 1;
   if(env_ob->can_put_and_get()) return 1;
   if(environment(env_ob)->query_interactive()) return 1;
   }
 }
   if(thi_ob->query_npc())
      if(thi_ob->query_attacker()) return 1;
      dest_inv();
   fname=file_name(thi_ob);
   if(sscanf(fname, "%syers%s", a,b) == 2)
      {
      if(sscanf(fname, "%s#%s", a,b) == 2) {
         obfile=find_object("/"+a);
         if(obfile) {
           if(LOGCLEAN) log_file("CLEAN",obfile+" Cleaned Up.\n");
/* 08/21/06 Earwax: added this */
           if (function_exists("remove_object", obfile))
             catch(obfile->remove_object(this_object()));
           if (obfile)
            destruct(obfile);
          }
      }
   }
   if(LOGCLEAN) {
     log_file("CLEAN",file_name(thi_ob)+" Cleaned.");
     if(env_ob) log_file("CLEAN","  Environment: "+file_name(env_ob));
     log_file("CLEAN","\n");
   }
   if(!are_we_alone()) env_ob->clean_up();
   /*if we are the last living thing around clean up the room. */
/* 08/21/06 Earwax: added this */
  if (thi_ob && function_exists("remove_object", thi_ob))
     catch(thi_ob->remove_object(thi_ob));
   if (thi_ob)
    destruct(thi_ob);
   return 1;
}
dest_inv(){
   object obfile;
   object *list_no;
   int t,k;
   string fname,a,b;
   list_no = all_inventory(this_object());
   k = sizeof(list_no);
   t=0;
   while(t < k){
    if(list_no[t]) {
/*
      fname=file_name(list_no[t]);
      if(sscanf(fname, "%syers%s", a,b) == 2) {
         if(sscanf(fname, "%s#%s", a,b) == 2) {
            obfile=find_object("/"+a);
            destruct(obfile);
         }
         }
*/
      destruct(list_no[t]);
     }
     t += 1;
   }
   return 1;
}
set_no_clean(arg){
   no_clean=arg;
}
is_player_here() {
    object ob;
        if(!environment()) return 0;
	ob = first_inventory(environment(this_object()));
	while(ob) {
            if(ob->query_level() > 99) write("player in room abort clean\n");
            if(ob->is_player()) return 1;
	    ob = next_inventory(ob);
	}
	return 0;
    }
are_we_alone() {
    object ob;
        if(!environment(this_object())) return 1;
	ob = first_inventory(environment(this_object()));
	while(ob) {
            if(ob != this_object())
            if(ob->is_npc() && !ob->is_kid() && !ob->is_pet()) return 1;
	    ob = next_inventory(ob);
	}
	return 0;
    }

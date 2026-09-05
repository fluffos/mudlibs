/*  The Party Object Master  Version 1.0      */
/*  Created by Beck (Russ Warren)  June 1998  */
/*  Fixed 4-4-01 by Verte to display msgs properly */
/*  Verte Added 11-30-01 Histories for party channels */
/*  Boltar 3-NOV-04 Changed party shares to total_level */
 /* Illarion 29 may 05 changed minumum shares to total_level*4/5 */
/*  2007-06-19 Vital added experience rate information  */
/*  2013-02-11 Rumplemintz Temporarily changed member limit from 5 to 40 */

/* ANSI Color  */
#include <ansi.h>
#include <security.h>
#define PARTYCHAN "[ "+HIG+PartyName+OFF+" ] "
/*  All the parties on Nirvana are kept track of in a single mapping */
/*  This allows a wizard to see who is in each party with a single command */
mapping Parties;
string PartyName;
/*  A nice way to present strings */
justify(str, len) { return extract(str+"                     ",0,len-1);}


/*  Creates Parties and Adds members to Parties  */
PartyAdd( string name, string member_name, string partyname ){
   object new_object;
   object *members;
   object member;
   int i;
   if(previous_object()->QPartyFollower()){
      write("You must be the leader of your party to add another person.\n");
      return 1;
   }
   PartyName = previous_object()->QPartyName();
   if(Parties ==0){ Parties = ([ ]); }
   if(member_name == this_player()->query_real_name()){
      member = this_player();
      if(!(members = Parties[name])){
         Parties[name] = ({ member });
         tell_object(member, PARTYCHAN+"You have started "+partyname+
            " with "+member->query_total_level()+" shares.\n");
         return 1;
      }
      if(members == 0 || members == ({ })){
         Parties[name] = ({ member });
         tell_object(member, PARTYCHAN+"You have started "+partyname+
            " with "+member->query_total_level()+" shares.\n");
      }
      return 1;
   }
   if(!present(member_name, environment(this_player()))){
      write(capitalize(member_name)+" is not present to be added to the party.\n");
      return 1;
   }
   member = present(member_name, environment(this_player()));
   if(member->query_level() > 19){
      write("Wizards cannot be added to the party.\n");
      return 1;
   }
   if(member->query_attack()){
      write("You can't add party members that are in combat.\n");
      return 1;
   }
   if(!member->is_player() && !member->is_kid()){
      write(capitalize(member_name)+" cannot be added to the party.\n");
      return 1;
   }
   if(present("party_object",member)){
      write(capitalize(member_name)+" is already in a party.\n");
      return 1;
   }
   /* avoid duplicates and use empty slots */
   members = Parties[name];
#if 0
/* Rumplemintz - change party size limit for reunion */
   if(sizeof(members) > 5){ write("There is already the maximum number of party members.\n");
      return 1;
   }
#else
    if (sizeof(members) > 40) {
      write("There is already the maximum number of party members.\n");
      return 1;
    }
#endif
   if (member_array(member, members) < 0) {
      if ((i = member_array(0, members)) < 0)
         Parties[name] = members + ({ member });
      else
         members[i] = member;
      members = Parties[name];
      PartyName = partyname;
      for(i=0;i<sizeof(members);i++){
         tell_object(members[i], PARTYCHAN+capitalize(member_name)+" has been added to "+partyname+
            " with "+member->query_total_level()+" shares.\n");
       }
      new_object = clone_object("/obj/partyob.c");
      new_object->SPartyName(partyname);
      new_object->SPartyShares(member->query_total_level());
      new_object->SPartyFollower(1);
      new_object->SRealPartyName(name);
      new_object->ResetPartyTime();
      move_object(new_object,member);
      return 1;
   }
   write(capitalize(member_name)+" is already a member of your party.\n");
   return 1;
}


/*  Allows the Party's leader to remove a member  */
PartyRemove( string name, string member_name ){

   object *members;
   object member;
   int i;
   if(previous_object()->QPartyFollower()){
      write("You must be the leader of your party to remove a person.\n");
      return 1;
   }
   PartyName = previous_object()->QPartyName();
   member = find_living(member_name);
   if(!member){
      write(capitalize(member_name)+" can't be found anywhere.\n");
      return 1;
   }
   if(members = Parties[name]){
      if(member_array(member,members) < 0){
         write(capitalize(member_name)+" is not a member of your party.\n");
         return 1;
      }
      Parties[name] -= ({ member });
      destruct(present("party_object",member));
      for(i=0;i<sizeof(members);i++){
         tell_object(members[i], PARTYCHAN+capitalize(member_name)+" has been removed from the Party.\n");
      }
      return 1;
   }
   return 1;
}


/*  The Party chat line  */
PartySay(string name, string msg , string partyname, string speaker ){

   object *members;
   int i;

   if (!(members = Parties[name])) return 1;
   PartyName = partyname;
   if(msg == "history" || msg == "-h") return write("/obj/user/chistory"->query_history(PARTYCHAN));
   i = sizeof(members);
   while(i--){
      if(members[i]){
         tell_object(members[i],PARTYCHAN+speaker+" says: "+msg+"\n");
         }
   }
   "/obj/user/chistory"->add_history(PARTYCHAN, PARTYCHAN+speaker+" says: "+msg+"\n");
   return 1;
}


/*  Called by hit_player() in /obj/living.c, this allows the party to share their experience  */
ShareExp(int amount,string name,object killer, object leader){
   object *members;
   object *membershere;
   int *shareshere;
   int expshare;
   int i, j, lowlvl, powlvl;
   int shares;
   int leadshare, total;
   members = Parties[name];
   membershere = ({ });
   shareshere = ({ });
   PartyName = previous_object()->QPartyName();
   for(i=0;i<sizeof(members);i++){
     if(!members[i]) continue;
      tell_object(members[i],PARTYCHAN+RED+"The party has gained "+amount+" experience."+OFF+"\n");
      if(members[i]->query_ghost()){
         tell_object(members[i],PARTYCHAN+"Ghosts cannot receive exp.\n");
      }
      else if(present(members[i]->query_real_name(),environment(killer))){
         shares += present("party_object",members[i])->QPartyShares();
         membershere += ({ members[i] });
         shareshere += ({ present("party_object",members[i])->QPartyShares() });
      }
      else{
         tell_object(members[i], PARTYCHAN+GREEN+"You must be with the other party members to gain experience."+OFF+"\n");
       }
   }
   /* 07/12/07 Earwax: Adding this for random points adding */
   if (amount >= random(2000000))
   {
     object wax; 

     wax = find_player("earwax");
     if (wax) tell_object(wax, HIC+ctime()+": was called to add points to "+(string)leader->query_real_name()+"'s party.\n"+NORM);
     POINTSD->add_party_points(shareshere, leader);
   }
   leadshare = 6*amount/24;
   amount = amount - leadshare;
   expshare = amount/shares;
   for(j=0;j<sizeof(membershere);j++){
      if(membershere[j] == leader)
         total = expshare*shareshere[j] + leadshare;
      else
         total = expshare*shareshere[j];

/* stop power leveling -Bp */ 
      lowlvl = membershere[j]->query_exp();
      if(total > lowlvl) {
         if(lowlvl > 1500) { total = lowlvl; powlvl = 1; }
         if(lowlvl < 1501 && total > 1500) { total = 1500; powlvl = 1; }
      }

         /* new additions  - mythos <5-2-2000>*/
         if(membershere[j]->query_xpshadow()) {
		 	 if(sizeof(members) > 1) membershere[j]->add_xp(total);
         } else  /* end addition */
         membershere[j]->add_exp(total);
      tell_object(membershere[j],PARTYCHAN+RED+"You have gained "+(total)+" experience."+OFF+"\n");
      if(powlvl) 
        tell_object(membershere[j],PARTYCHAN+RED+"Note: You may not gain more than 1500 exp or your present exp amount."+OFF+"\n");
      present("party_object",membershere[j])->APartyExperience(total);
   }
}


/*  Allows a party to see how well they have done.  */
/*  Added in experience rate calculations - Vital 2007-06-19  */
PartyStatus(string name, string partyname){
   object *members;
   int i, j, x, t;
   int total_exp, combined_time;
   total_exp = 0;
   combined_time = 0;
   members = Parties[name];
   write("\n"+GREEN+partyname+OFF+"\n\n");
   write(justify("Name",15));
   write(justify("Shares",7));
   write(justify("Experience",11));
   write(justify("Rate", 10));
   write("\n\n");
   for(i=0, j=sizeof(members);i<j;i++){
    x = present("party_object",members[i])->QPartyExperience();
    if (!(t = (time() - present("party_object",members[i])->QPartyTime())/60))
      t = 1;
    write(justify(capitalize(members[i]->query_real_name()), 15));
    write(justify(present("party_object",members[i])->QPartyShares(),7));
    write(justify(x,11));
    write(justify(x / t+"/min",10));
    write("\n");
    total_exp += x;
    combined_time += t;
   }
   write("\n\tTotal Party Experience: "+BOLD+RED+total_exp+OFF+"\n\n");
   write("\tTotal Party Rate: "+BOLD+RED+(total_exp/combined_time)+
         "/min"+OFF+"\n\n");
   return 1;
}


/*  Allows the party leader to change the party name  */
PartyName( string name, string partyname){
   int i;
   object *members;
   if(previous_object()->QPartyFollower()){
      write("You must be the leader of your party to change the party name.\n");
      return 1;
   }
   if(strlen(partyname) > 16){
      write("Your party name can only be 16 characters or less.\n");
      return 1;
   }
   PartyName = partyname;
   members = Parties[name];
   for(i=0;i<sizeof(members);i++){
      present("party_object",members[i])->SPartyName(partyname);
      tell_object(members[i], PARTYCHAN+"The new Party name is: "+partyname+"\n");
   }
   return 1;
}


/*  Changes who is the party leader  */

PartyLeader(string name, string new_leader){
   int i;
   object *members;
   object leader;
   string new_name;
   if(previous_object()->QPartyFollower()){
      write("You must be the leader of your party to change the party name.\n");
      return 1;
   }
   if(name == new_leader){
      write("You are already the leader of the party.\n");
      return 1;
   }
   leader = find_player(new_leader);
   if(!leader){
      write(capitalize(new_leader)+" is not playing right now.\n");
      return 1;
   }
   members = Parties[name];
   if(member_array(leader,members) < 0){
      write(capitalize(new_leader)+" is not a member of your party.\n");
      return 1;
   }
   if(!leader->is_player()){
      write("Only players can become leaders of parties.\n");
      return 1;
   }
   PartyName = previous_object()->QPartyName();
   new_name = leader->query_real_name();
   /*  Recreate the party using the new leaders name  */
   /*  This allows the old leader to leave the party and start a new one if they choose  */
      Parties[new_name] = ({ });
   for(i=0;i<sizeof(members);i++){
      if(members[i] == leader){
         present("party_object",members[i])->SPartyFollower(0);
       }
      PartyName = previous_object()->QPartyName();
      tell_object(members[i],PARTYCHAN+capitalize(new_leader)+" is the new leader of the Party.\n");
      present("party_object",members[i])->SRealPartyName(new_name);
      Parties[new_name] += ({ members[i] });
   }
   previous_object()->SRealPartyName(new_name);
   previous_object()->SPartyFollower(1);
   Parties[name] = 0;
   return 1;
}


/*  Allows a party member to leave the party  */
PartyLeave(string name, object member){
   object *members;
   /* Next two lines added by Cosmo - 1/21/00 */
   string *member_list;
   int total_exp;
   int i;
   members = Parties[name];
   PartyName = previous_object()->QPartyName();
   if(previous_object()->QPartyFollower()){
      for(i=0;i<sizeof(members);i++){
         PartyName = previous_object()->QPartyName();
         tell_object(members[i], capitalize(PARTYCHAN+member->query_real_name())+" has left the Party.\n");
      }
      Parties[name] -= ({ member });
      destruct(previous_object());
      return 1;
   }
   else{
      /* Next line added by Cosmo - 1/21/00 */
      member_list = allocate(sizeof(members));
      for(i=0;i<sizeof(members);i++){
         /* Next two lines added by Cosmo - 1/21/00 */
         member_list[i] = members[i]->query_real_name();
         total_exp += present("party_object",members[i])->QPartyExperience();
         tell_object(members[i], PARTYCHAN+"The party has disbanded.\n");
         destruct(present("party_object",members[i]));
      }
      /* Next line added by Cosmo - 1/21/00 */
      if(i > 1)
      "obj/partylist.c"->UpdateList(PartyName, total_exp, member_list);
      Parties[name] = 0;
      return 1;
   }
   return 0;
}

/*  Allows players and wizards to see all members of all parties  */
PartyWho(){
   string *parties;
   object *members;
   int i;
   int j;
   if(!Parties){
      write("There are not any parties yet.\n");
      return 1;
   }
   parties = keys(Parties);
   write("Parties occuring now on Nirvana.\n\n");
   write(justify("Party Leader",15));
   write("Party Members\n\n");
   for(i=0;i<sizeof(parties);i++){
      if(parties[i] != 0){
         members = Parties[parties[i]];
         if(members != 0 && members != ({})){
            write(justify(capitalize(parties[i]),15));
            for(j=0;j<sizeof(members);j++){
               write(members[j]->query_real_name()+" ");
            }
            write("\n");
         }
       }
   }
   return 1;
}

PartyShare(string name, string member_name, int number){
   object *members;
   object member;
   int level;
   int i;
   if(previous_object()->QPartyFollower()){
      write("You must be the leader of your party to change a players shares.\n");
      return 1;
   }
   member = find_living(member_name);
   if(!member){
      write(capitalize(member_name)+" is not around anywhere.\n");
      return 1;
   }
   members = Parties[name];
   if(member_array(member,members) < 0){
      write("That person is not a member of your party.\n");
      return 1;
   }
   level = member->query_total_level();
   if(number > level + 10 && number > level * 2) {
      write("You cannot give "+capitalize(member_name)+" more than "+
         level+" plus 10 or times 2 whichever is greater.\n");
      return 1;
   }
   if(number < (level * 4 / 5)) {
      write("You cannot give "+capitalize(member_name)+" fewer than "+
         (level * 4 / 5)+" shares.\n");
      return 1;
   }
   if(number < 1){
      write("You cannot give anyone less than 1 share.\n");
      return 1;
   }
   PartyName = previous_object()->QPartyName();
   present("party_object",member)->SPartyShares(number);
   for(i=0;i<sizeof(members);i++){
      tell_object(members[i],PARTYCHAN+capitalize(member_name)+" will now receive "+number+" shares.\n");
   }
   return 1;
}

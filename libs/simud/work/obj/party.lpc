/** Party Object v0.1
 *  by Allaryin
 *
 * Ok, here's the deal. We don't exactly have 'xp' to split, but we canuse
 * an idea similar to Discworld's TM system - When a party member gains a
 * level in a skill as a result of using it, everyone else in the party gains
 * the same benefit.
 *
 * So, what we do is... whenever anyone actually practices a skill, there is
 * going to be a 50% chance that any present party members also practice the
 * same skill - if they have it. This means that a group of three swordsmen
 * in the same room will probably wind up filling their sword, parry, etc...
 * skill buffers 2x as fast (1 + .5 + .5) as they would alone.
 *
 * Being partied with someone will also allow you to 'auto-assist' them as
 * per the feature of the same name found in ROM and other codebases. The way
 * we will handle autoassist is fairly simple, whenever your target queue
 * changes, we update the queue of all party members in the same room to be
 * the same.
 *
 * The other thing that we will use party objects for is simple group
 * cohesion. Packs of monsters will always be partied together, thus having
 * a list of all allied monsters, etc... Then, there's the chat line, a way
 * for both players and packs of mobs to communicate.
 *
 * When a player dies, and when we implement mud-wide death shouts... we will
 * use the name of the party who inflicts the kill, not just the individual
 * player or mobile.
 */

#include <object.h>
#include <item.h>

string leader;   // person/mob who started the party
string *members; // other people and mobs in the party
string pname;     // what does the party call itself?

object query_leader() {
   object ob;

   if( !leader || !(ob=find_player(leader))) leader = environment()->query_name();
   return ob;
}

object query_leader_ob() {
   return query_leader()->query_party_object();
}

object * query_members() {
   object *oblist;

   if (environment(this_object()) == query_leader()) {
      if( !members )
         members = ({ environment(this_object())->query_name() });

      oblist = map( members, (: find_player($1) :) ) - ({ 0 });
      return oblist;
   }
   else
      return query_leader_ob()->query_members();
}

int query_is_member(object who) {
   return member(query_members(),who) != -1;
}

string query_party_name() {
   if (environment(this_object()) == query_leader())
      return pname;
   else
      return query_leader_ob()->query_party_name();
}


void pmsg(string buf) {
   object who;
   buf = "[~CTITParty~CDEF] "+buf;
   foreach (who : query_members())
      msg_object(who,buf+"~CDEF");
}


varargs void set_leader(object who, int silent) {
   if (silent)
      leader = who->query_name();
   else {
      object ob;
      pmsg(who->query_cap_name()+" is the now the party's leader.");
      foreach (ob : query_members()) {
         if (ob == who) {
            debug ("members = "+as_lpc(query_members()));
            ob->query_party_object()->set_members(query_members());
            ob->query_party_object()->set_party_name(query_party_name());
         }
         if (ob = ob->query_party_object())
            ob->set_leader(who,1);
      }
   }
}

void set_members(object *list) {
   members = map(list, (: $1->query_name() :) );
}

int add_member(object who) {
   if (member(query_members(),who) != -1)
      return 0;
   set_members ( query_members() + ({ who }) );
   return 1;
}

void remove_member(object who) {
   members -= ({ who->query_name() });
}

void set_party_name(string str) {
   pname = str;
}

string query_name() {
   return "party_ob";
}

object id( string s ) {
   return s == "party_ob"?this_object():0;
}

void create() {
   ::create();
   set_droppable(0);
   set_gettable(0);
   set_holdable(0);
}

void setup(object target, object lead) {
   move(target);
   set_leader(lead,1);
   if ( query_leader() == environment(this_object()) ) {
      set_party_name(query_leader()->query_cap_name()+"'s Party");
      set_members( ({target}) );
   } else
      query_leader_ob()->add_member(target);
}

void init() {
   add_action("do_who","pwho");
   add_action("do_quit","pquit");
   add_action("do_help","phelp");
   add_action("do_rally","rally");
   add_action("do_tell","ptell");
   add_action("do_disband","disband");
}

int do_help() {
   msg("Party Help:\n\n"+
       "~CCOMpwho~CDEF      list all members of the party\n"+
       "~CCOMpquit~CDEF     quit the party\n"+
       "~CCOMptell~CDEF     send a message to all party members\n"+
       "~CCOMdisband~CDEF   break up the party (leader only)\n"+
       "~CCOMrally~CDEF     recruit a new member into the party");
   return 1;
}

int do_tell(string arg) {
   pmsg(environment(this_object())->query_cap_name()+": "+arg);
   return 1;
}

int do_who() {
   object who;
   int hp, mhp, mana, mmana, end, mend;
   msg("~CTITParty: ~CDEF"+query_party_name());
   foreach ( who : query_members() ) {
      hp = who->query_hp();
      mhp = who->query_max_hp();
      mana = who->query_mana();
      mmana = who->query_max_mana();
      end = who->query_endurance();
      mend = who->query_max_endurance();
      msg((query_leader()==who?"*":" ")+"~CLAB"+pad(who->query_cap_name(),15,0)+
          sprintf("~CBRTHP~CDEF: %3d/%3d  ~CBRTMana~CDEF: %3d/%3d  ~CBRTEnd~CDEF: %3d/%3d",hp,mhp,mana,mmana,end,mend));
   }
   return 1;
}

int do_rally(string arg) {
   object victim;
   if ( victim = present(arg,environment(this_player())) ) {
      object ob = clone_object("/obj/party");
      add_member(victim);
      ob->setup(victim,query_leader());
      pmsg(this_player()->query_cap_name()+" rallies "+victim->query_cap_name()+" into the party.");
   }
   return 1;
}

varargs int do_quit(int silent) {
   object who;
   if (!silent) {
      pmsg(environment(this_object())->query_cap_name()+" has left the party.");
      query_leader_ob()->remove_member(environment(this_object()));
      if (query_leader() == environment(this_object()) && sizeof(query_members()))
         set_leader(query_members()[0]);
   }
   destruct(this_object());
   return 1;
}

int do_disband() {
   object who;
   if (environment(this_object()) != query_leader()) {
      msg("Only the leader can disband the party!");
      return 1;
   }
   pmsg(query_leader()->query_cap_name()+" has disbanded the party.");
   foreach ( who : query_members() )
      if (who = who->query_party_object())
         who->do_quit(1);
   destruct( this_object() );
   return 1;
}

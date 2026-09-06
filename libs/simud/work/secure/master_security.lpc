#include <saveload.h>
#include <const.h>

#pragma no_clone

string *wizards;
string *wizlist;
string *wlvls;

void set_offline_player_level( string pname, int lev );
void set_offline_player_wiz_creation_date( string pname, int time );

object id(string str) {
   return str=="master_sec_daemon"?this_object():0;
}

int add_wizard(string wiz, int lvl) {
  string temp, namecrypt;
  int i,sw,old;
  object wob;

  wiz = lower_case(wiz);

  wob = find_player(wiz);
  mkdir( HOME_DIR + wiz );

  if(!wiz || !lvl) return 0;
  if(object_name(previous_object()) != "/bin/wiz/addwizard") {
    write("Thou art a putz! ("+object_name(previous_object())+")\n");
    return 0;
  }

  sw = 0;
  for(i=0;i<sizeof(wizards);i++) {
    if(wiz == wizards[i]) sw = i;
  }
  if(sw) {
    temp = crypt((string)lvl,0);
    wlvls[sw] = temp;
  } else {
    wizards += ({wiz});
    namecrypt = crypt(wiz, 0);
    wizlist += ({namecrypt});
    namecrypt = crypt((string)lvl,0);
    wlvls += ({namecrypt});
  }
  if( wob ) {
     old = wob->query_level();
     wob->set_level( lvl );
     if (old < WIZLEVEL) {
       wob->set_wiz_creation_date( time() );
       msg_object( wob, "You are now a wizard. Enjoy it. We'll make a nice message for you later.");
     }
     else
       msg_object( wob, "Congratulations, you are now level "+lvl+".");
     msg("==> [Notice] "+wob->query_cap_name()+" is now wizard level "+lvl+".");
     wob->save_self();
  }
  else {
     msg("==> [Notice] Wizard not presently logged on. Level and wiz date changed directly in their player file.");
     set_offline_player_level( wiz, lvl );
     set_offline_player_wiz_creation_date( wiz, time() );
  }
  save_object("/secure/master_security");
  return 1;
}

int remove_wizard(string wiz) {
  int i;

  if(object_name(previous_object()) != "/bin/wiz/rmwizard") {
    write("Thou art a rotten little imp!\n");
    return 0;
  }

  for(i=0;i<sizeof(wizards);i++) {
    if(wiz == wizards[i]) {
      wizards = array_delete(wizards, i);
      wizlist = array_delete(wizlist, i);
      wlvls = array_delete(wlvls, i);
      set_offline_player_level( wiz, 1 );
      save_object("/secure/master_security");
      return 1;
    }
  }

  set_offline_player_level( wiz, 0 );
  set_offline_player_wiz_creation_date( wiz, 0 );
  return 0;
}

void create() {
  string temp;
  //if(arg) return;
  /* acius 1000
     admin 1000
     bob 100
     dinin 1000
     venger 1000
  */
  restore_object("/secure/master_security");
  /*temp = "bob";
  temp = crypt(temp, 0);*/
  if(!wizards) wizards = ({});
  if(!wizlist) wizlist = ({});
  if(!wlvls) wlvls = ({});
  /*wizlist += ({temp});
  temp = "100";
  wlvls += ({crypt(temp, 0)});
  save_object("/secure/master_security");*/
  call_out("player_check", 1);
}

void player_check() {
  object *plist;
  object ob;
  int i;

  plist = users();
  for(i=0;i<sizeof(plist);i++) {
    if(!present("sub_daemon", plist[i]) && plist[i]->query_name()) {
      ob = clone_object("/secure/sub_sec_daemon");
      ob->move(plist[i]);
      log_file("secure", "Player "+plist[i]->query_name()+" didn't have a watcher.\n");
    }
  }
  call_out("player_check", 15);
}

void check_player(string pname, int plev) {
   int i,sw;
   string temp;
   object ob;

   sw = 0;
   for(i=0;i<sizeof(wizlist);i++) {
      temp = crypt(pname, wizlist[i]);
      if(wizlist[i]==temp) {
//         debug(pname + " matches " + wizlist[i]);
         temp = (string)plev;
         temp = crypt(temp, wlvls[i]);
         if(wlvls[i]==temp) {
//            debug("Within which, " + wlvls[i] + " matches.");
            sw = 1;
         }
      }
   }
   if(!sw) {
      ob = previous_object()->query_charge();
      ob->set_level(1);
      msg_object(ob, "~[090You have been smitten for your insolence!~[070");
      log_file("secure", ob->query_name()+" has been smitten.\n");
      ob->say_all(ob->query_distant()+" has been reduced to a pair of smoking shoes by the Gods.");
      ob->quit();
   }
}

// If you make wiz levels with this, you have to add them to the wizard list as well!
void set_offline_player_level( string pname, int lev ) {
   string pfile = read_file( PLAYER_DIR + pname + ".o" );
   int plev;
   string a, b;

   if( getuid(previous_object()) != "root" ) raise_error("Thou worm, "+capitalize(""+getuid(previous_object())) + "! -- doth thy debauchery truly take thee so low?" );
   if( !pfile ) raise_error( "/secure/master_security: "+as_lpc(previous_object()) + " tried to set level of non-existent "+pname+" ... confused." );

   if( sscanf(pfile, "%s\nlevel %d%s", a, plev, b) != 3 ) return;
   rm( PLAYER_DIR + pname + ".o" );
   write_file( PLAYER_DIR + pname + ".o", a + "\nlevel " + lev + b );
}

void set_offline_player_wiz_creation_date( string pname, int time ) {
   string pfile = read_file( PLAYER_DIR + pname + ".o" );
   int wdate;
   string a, b;

   if( getuid(previous_object()) != "root" ) raise_error("Thou worm, "+capitalize(""+getuid(previous_object())) + "! -- doth thy debauchery truly take thee so low?" );
   if( !pfile ) raise_error( "/secure/master_security: "+as_lpc(previous_object()) + " tried to set wiz creation date of non-existent "+pname+" ... confused." );

   if( sscanf(pfile, "%s\nwiz_creation_date %d%s", a, wdate, b) != 3 ) return;
   rm( PLAYER_DIR + pname + ".o" );
   write_file( PLAYER_DIR + pname + ".o", a + "\nwiz_creation_date " + wdate + b );
}

// only needed until all existing players have had their creation dates set
// new players should have their dates automatically set
void set_offline_player_creation_date( string pname, int time ) {
   string pfile = read_file( PLAYER_DIR + pname + ".o" );
   int date;
   string a, b;

   if( getuid(previous_object()) != "root" ) raise_error("Thou worm, "+capitalize(""+getuid(previous_object())) + "! -- doth thy debauchery truly take thee so low?" );
   if( !pfile ) raise_error( "/secure/master_security: "+as_lpc(previous_object()) + " tried to set wiz creation date of non-existent "+pname+" ... confused." );

   if( sscanf(pfile, "%s\ncreation_date %d%s", a, date, b) != 3 ) return;
   rm( PLAYER_DIR + pname + ".o" );
   write_file( PLAYER_DIR + pname + ".o", a + "\ncreation_date " + date + b );
}

int query_player_level( string pname ) {
   string pfile = read_file( PLAYER_DIR + pname + ".o" );
   string temp;
   int i, plev;
   object ob;

   if( ob = find_player(pname) )
      ob->save_self();

// Hmm ... no good reason not to allow queries, that I can think of.
//   if( getuid(previous_object()) != "root" ) raise_error("Thou foul villain! Keep thy hands to thyself, "+capitalize(""+getuid(previous_object())) + "!" );
   if( !pfile ) return -1;

   if( sscanf(pfile, "%~s\nlevel %d%~s", plev) != 3 ) return -1;

   if( plev >= 100 ) {
      // Verify level before giving it back.
      for( i = sizeof(wizlist); i--; ) {
         temp = crypt(pname, wizlist[i]);
         if(wizlist[i] == temp) {
            temp = crypt(""+plev, wlvls[i]);
            if(wlvls[i]==temp) {
               return plev;
            }
         }
      }
      set_offline_player_level( pname, 0 );
      msg_all(capitalize(pname)+"'s voice can be heard from a distance, screaming in pain from divine retribution.");
      return -1;
   }
   return plev;
}

int query_wiz_creation_date( string pname ) {
   string pfile = read_file( PLAYER_DIR + pname + ".o" );
   string temp;
   int i, wdate;
   object ob;

   if( ob = find_player(pname) )
      ob->save_self();

   if( !pfile ) return -1;
   if( sscanf(pfile, "%~s\nwiz_creation_date %d%~s", wdate) != 3 ) return -1;

   return wdate;
}

int query_creation_date( string pname ) {
   string pfile = read_file( PLAYER_DIR + pname + ".o" );
   string temp;
   int i, date;
   object ob;

   if( ob = find_player(pname) )
      ob->save_self();

   if( !pfile ) return -1;
   if( sscanf(pfile, "%~s\ncreation_date %d%~s", date) != 3 ) return -1;

   return date;
}

int main( string param ) {
   mapping vars;
   mapping bool_toggles = ([
      "autohp": "Display your hp whenever you take damage",
      "autotake": "Automatically take anything people try to give you",
      "map": "Display room maps (highly recommended)",
      "brief": "Display only short room descriptions",
      "autobreak": "Read the help file for details",
      "ansi": "Use ANSI color",
      "autosatiate": "Satiate yourself when hungry (wizard only)",
      "noweather": "Do not display weather changes",
      "nosave": "Do not display world save messages",
	  "msp": "Mud Sound Protocol",
   ]);
   mapping word_toggles = ([
      "autoready": "Spam level of ready meter",
      "autoeat": "Eat this when hungry",
      "autodrink": "Drink this when thirsty",
   ]);
   string buf, key, val;
   int x, padlength;

   vars = this_player()->query_env_vars();
   vars = filter( vars, (: stringp($1) && $1[0] == 'T' :) );
   padlength = max(4, max(strlen(vars["Tautoeat"]), strlen(vars["Tautodrink"])));
   if( !param ) {
       buf = "~CTITYour settings:\n" +
             "~CDRK--------------\n";
       foreach( key : sort_array(m_indices(bool_toggles), #'>) ) {
          val = vars["T" + key];
	  if ( key == "autosatiate" && this_player()->query_level() < WIZLEVEL)
	    continue;
          if( val ) val = "~CBRTon~CDEF";
          else val = "~CDRKoff~CDEF";
          buf += "~CLAB" + pad(capitalize(key),12,1) + "~CDEF " + pad(val,padlength,0) + " ~CDEF" + bool_toggles[key] + "\n";
       }
       foreach( key : sort_array(m_indices(word_toggles), #'>) ) {
          val = vars["T" + key];
          if (key == "autoready") {
             switch ( this_player()->query_env_var("Tautoready") ) {
                case 1:  val = "~CBRTlow~CDEF";  break;
                case 2:  val = "~CBRTon~CDEF";   break;
                case 3:  val = "~CBRThigh~CDEF"; break;
             }
          }
          if( !val ) val = "~CDRKoff~CDEF";
          buf += "~CLAB" + pad(capitalize(key),12,1) + "~CDEF " + pad(val,padlength,0) + " ~CDEF" + word_toggles[key] + "\n";
       }
       msg( buf );
       return 1;
   }
   val = 0;
   if( sscanf( param, "%s %s", key, val ) != 2 )
      key = param;

   if (key == "autosatiate" && this_player()->query_level() < WIZLEVEL) {
      msg("~CCOMAutoSatiate is a wizard-only option. Sorry ;)~CDEF");
      return 1;
   }

   if (key == "autoready") {
      switch (val) {
         case "off":
         case "clear":  x = 0; break;
         case "low":    x = 1; break;
         case "on":
         case "default":
         case "normal": x = 2; break;
         case "high":   x = 3; break;
         default: if (!val || sscanf(val,"%d",x) != 1)
                     x = this_player()->query_env_var( "Tautoready" ) + 1;
      }
      if (x < 0 || x > 3)
         x = 0;
      this_player()->set_env_var( "Tautoready", x );
      switch (x) {
         case 0: msg("~CCOMAutoready~CDEF turned ~CBRToff~CDEF. You will no longer see your readymeter in combat."); break;
         case 1: msg("~CCOMAutoready~CDEF turned to ~CBRTlow~CDEF. You will now see a minimal readymeter in combat."); break;
         case 2: msg("~CCOMAutoready~CDEF turned to ~CBRTnormal~CDEF. You now see your normal readymeter in combat."); break;
         case 3: msg("~CCOMAutoready~CDEF turned to ~CBRThigh~CDEF. You will now see a large readymeter in combat."); break;
         default: msg("~CWRNSomething went wrong. ~CDEFResetting your readymeter to ~CCOMdefault~CDEF.");
                  this_player()->set_env_var( "Tautoready", 2 );
      }
   } else if( member(bool_toggles, key) ) {
      int target;
      if( val == "on" )
         target = 1;
      else if( val == "off" )
         target = 0;
      else
         target = !this_player()->query_env_var("T"+key);

      // start/stop sound if they toggled msp
      if( key == "msp" ) {
         debug(this_player()->query_name()+" toggled sound="+target,"audio");
         AUDIO_DAEMON->bgm_off(this_player());
         AUDIO_DAEMON->sfx_off(this_player());
      }

	  // actually set the variable
      this_player()->set_env_var( "T"+key, target );
      msg("You change the setting for ~CLAB"+key+"~CDEF. It is now "+(this_player()->query_env_var("T"+key)?"~CBRTon":"~CDEFoff")+"~CDEF.");

	  // start bgm if appropriate
      if( key == "msp" && target ) {
         debug("starting music","audio");
         AUDIO_DAEMON->start_the_music(this_player());
      }	
   } else if( member(word_toggles, key) && stringp(val) ) {
      if (val == "off" || val == "clear" || val == "none") {
         switch(key) {
         // autoready is already handled above
         case "autodrink":
            this_player()->set_autodrink(0);
            break;
         case "autoeat":
            this_player()->set_autoeat(0);
            break;
         }
         msg("~CLAB"+capitalize(key)+"~CDEF is now turned off.");
      } else {
         this_player()->set_env_var( "T" + key, val );
         msg("The setting for ~CLAB"+key+"~CDEF is now "+val+".");
      }
   }
   else {
      notify_fail("That didn't make any sense. Type 'help toggle' for information.\n");
      return 0;
   }
   return 1;
}

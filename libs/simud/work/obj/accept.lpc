/** This object is cloned up whenever anyone has to make a decision to accept something
 * or not. It is used to seal trades, give items, atone for sins, etc... it is meant to
 * be fairly generic and should be useful for any number of applications.
 *
 * The intended pattern of use is:
 * - clone the object
 * - call set_verb, set_yes, and set_no on the object
 * - call start
 *
 * Typically the accept and reject functions should be defined in the originating
 * verb. For example, /bin/give->on_accept(param).
 */

/// Verb that cloned this object in the first place
object verb;

/// Function to call in verb if the action is accepted
string yes;

/// Function to call if the action is refused
string no;

/// Parameters to pass to verb::yes()
mixed  yesparam, noparam;

/** Sets the filename (typically a verb) who is handling the request
 * (i.e. "/bin/give"). The functions given in set_yes and set_no will
 * be called in this verb.
 */
void set_verb( object v ) {
//   debug("verb set to " + as_lpc(v));
   verb = v;
}

/** Sets the action to be taken when the person accepts -- \a s is the
 * function to call, and it will be passed parameter \a p.
 */
void set_yes( string s, mixed p ) {
   // debug("yes set to "+as_lpc(s));
   yes = s;
   yesparam = p;
}

/** Sets the action to be taken then the person rejects, either from timeout
 * or direct rejection. \a s is the function, \a p its parameter.
 */
void set_no( string s, mixed p ) { no = s; noparam = p; }

/** Function moves the object into the inventory of the target player, notifies them
 * that they have a decision to make, and starts the timer (10 seconds).
 */
void start( object who ) {
   set_target( who );
   set_listener( this_player() );
   msg( "Waiting for ~targ to accept." );
   move_object( this_object(), who );
   msg_object( who, "Type ~CCOMaccept~CDEF or ~CCOMreject~CDEF." );
   call_out( "on_time_out", 20 );
}

/// Called when the player accepts the request (/bin/accept)
void on_accept() {
   remove_call_out("on_time_out");
   if( !verb || !yes ) {
      msg( "~CWRNSomething went wrong with 'accept'. Notify a wizard.~CDEF" );
      debug( "Inappropriate call to /obj/accept->on_accept() by " + (string) this_player() );
      destruct( this_object() );
   }
   call_other( verb, yes, yesparam );
   destruct( this_object() );
}

/// Called when the player rejects the request (/bin/reject)
void on_reject() {
   remove_call_out("on_time_out");
   if( !verb || !no ) {
      msg( "~CWRNSomething went wrong with 'accept'. Notify a wizard.~CDEF" );
      debug( "Inappropriate call to /obj/accept->on_reject() by " + (string) this_player() );
      destruct( this_object() );
   }
   call_other( verb, no, noparam );
   destruct( this_object() );
}

/// Called when the player doesn't respond to the request within 20 seconds.
void on_time_out() {
   msg_object( environment(this_object()), "You are not responding. Automatically rejecting the request." );
   on_reject();
}

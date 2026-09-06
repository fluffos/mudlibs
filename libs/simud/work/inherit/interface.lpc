/** Inherit this file in any object that needs to be able to use an
 * interface. Interfaces are used by things like the text editor,
 * the administration utility, etc.
 *
 * For more information about interfaces, see the add_interface,
 * drop_interface, clear_interface, and shift_interface functions
 * in simul_efun.
 */

#include <const.h>

/// Functions providing the interface
nosave string *ifuncs;
/// ... and the objects providing the interface.
nosave object *iobjs;
/// The stack of prompts provided by the interface (only relevant in line-mode)
nosave object *iprompts;
/** The interface mode. This is a bit-wise set integer with various
 * interface information. Presently implemented features:
 *  - &0x01: This interface is in charmode
 *  - &0x02: This interface wants to handle all received text (using catch_tell).
 */
nosave int *imode;

/** Adds an interface to this player's input stack. This is only
 * for line-mode interfaces; for single character interfaces, you
 * should use _interface_single_char. You normally shouldn't call
 * these functions directly, use Simul_efun::add_interface() instead.
 * \param name The function that will process the input given.
 * \param prompt The text given as a prompt. Uses Player::set_curr_prompt().
 * \param ob A pointer to the object hosting the interface.
 */
_interface_add(string name, string prompt, object ob) {
   if(!name || !prompt || !ob) return;
   if(!ifuncs) ifuncs = ({});
   if(!iobjs) iobjs = ({});
   if(!iprompts) iprompts = ({});
   if(!imode) imode = ({});
   ifuncs = ({ name }) + ifuncs;
   iprompts = ({ prompt }) + iprompts;
   iobjs = ({ ob }) + iobjs;
   imode = ({ 0 }) + imode;
   call_other(this_player(), "set_curr_prompt", prompt);
   if( sizeof(ifuncs) > 1 ) return;
   _interface_recv( -1 );
}

_interface_single_char(string name, object ob) {
   if(!name || !ob) return;
   if(!ifuncs) ifuncs = ({});
   if(!iobjs) iobjs = ({});
   if(!iprompts) iprompts = ({});
   if(!imode) imode = ({});
   ifuncs = ({ name }) + ifuncs;
   iprompts = ({ "" }) + iprompts;
   iobjs = ({ ob }) + iobjs;
   imode = ({ 1 }) + imode;
   call_other(this_player(), "set_curr_prompt", "");
   _interface_recv( -1 );
}

/** Used by shift_interface. Note that it preserves the input catch.
 */
_interface_shift(string name, string prompt, object ob) {
   if(!ifuncs || !iobjs || !iprompts || !imode) return;
   ifuncs[0] = name;
   iprompts[0] = prompt;
   iobjs[0] = ob;
   imode[0] = imode[0] & 0x02;
   call_other(this_player(), "set_curr_prompt", prompt);
}

_interface_shift_single_char(string name, object ob) {
   if(!ifuncs || !iobjs || !iprompts || !imode) return;
   ifuncs[0] = name;
   iprompts[0] = "";
   iobjs[0] = ob;
   imode[0] = 1 + (imode[0] & 0x02);
   call_other(this_player(), "set_curr_prompt", "");
}

_interface_recv(str);

_interface_drop() {
   if(!ifuncs && !iobjs && !iprompts && !imode) return;
   if(sizeof(ifuncs) == 1 || sizeof(iobjs) == 1 || sizeof(iprompts) == 1 || sizeof(imode == 1) ) {
      ifuncs = 0;
      iobjs = 0;
      iprompts = 0;
      imode = 0;
      call_other(this_player(), "set_curr_prompt");
      return;
   }
   ifuncs = ifuncs[1..sizeof(ifuncs) - 1];
   iobjs = iobjs[1..sizeof(iobjs) - 1];
   iprompts = iprompts[1..sizeof(iprompts) - 1];
   imode = imode[1..sizeof(imode) - 1];
   call_other(this_player(), "set_curr_prompt", iprompts[0]);
   _interface_recv( 0 );
}

/// Number of times in a row that escape's been pressed. Three escapes is like a 'control+break' from charmode interfaces.
nosave int escape_count;

_interface_recv(str) {
   string err;

   if( stringp(str) && str[0] == 0x1B && (imode[0] & 0x01) ) escape_count++;
   else escape_count = 0;

   if( escape_count > 2 ) {
      msg_bare("\n~[070Forced exit -- ESC pushed 3 times\n");
      escape_count = 0;
      _interface_drop();
      str = 0;
   }

   if( str == "~BAILOUT" ) {
      msg_bare("\n~[070Forced exit -- bailout requested\n");
      _interface_drop();
      str = 0;
   }

   while( sizeof(iobjs) && !iobjs[0] ) _interface_drop();
   if(!ifuncs || !iobjs || !iprompts || !imode) return;
   if( str == -1 ) {
      if( this_player()->query_prompt() != "" )
         this_player()->write_prompt();
      if( imode[0] & 0x01 )
      input_to("_interface_recv", INPUT_NOECHO|INPUT_CHARMODE|INPUT_IGNORE_BANG );
      else
      input_to("_interface_recv");
      return;
   }
   if( err = catch(call_other(iobjs[0],ifuncs[0],str)) ) {
      if( pointerp(imode) && (imode[0] & 0x01) )
         msg_bare("\nAn error occurred in this program. If you can't exit normally, try ESC-ESC-ESC.\n");
      else
         msg_bare("\nAn error occurred in this program. If you can't exit normally, type ~BAILOUT.\n");
      debug("Interface Error: "+object_name(this_object())+" using "+ifuncs[0]+" in "+object_name(iobjs[0])+": "+err);
   }
   if(!ifuncs) return;
   if( imode[0] & 0x01 )
   input_to("_interface_recv", INPUT_NOECHO|INPUT_CHARMODE|INPUT_IGNORE_BANG );
   else
   input_to("_interface_recv");
   if( this_player()->query_prompt() != "" )
      this_player()->write_prompt();
}

int _interface_set_catch( int enable, int catcher ) {
   if( !imode ) return 0;
   if( enable )
      imode[catcher] |= 0x02; // Bit 2 is the interface catch flag.
   else
      imode[catcher] &= (0xFFFF - 0x02);
   return 1;
}

_interface_catch(string str, int catcher) {
   string err;

   if( !imode || !iobjs ) err = "Catch called with no interface set!\n";
   else
      err = catch(iobjs[catcher]->catch_tell(str));

   if( err ) {
      if( imode ) _interface_set_catch( 0, catcher );
      write("Interface catch error: "+err+"\n");
      write(str);
   }
}

object query_interface() {
   if( iobjs ) return iobjs[0];
   return 0;
}

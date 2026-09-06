#include <battle.h>
#include <textdraw.h>

#define TP this_player()
#define OBJ (this_player()->query_form_object())
#define FORM (this_player()->query_form())

void do_list() {
  string name, buf, *formlist, form = FORM;

  buf = "~CTITForms~CDEF:\n";
  formlist = ({ });
  foreach (name : sort_array(m_indices(TP->query_known_forms()), #'>)) {
    if (form == name)
      formlist += ({ " *" + name + "*" });
    else
      formlist += ({ "  " + name });
    TP->set_form(name);
  }
  buf += "~CCOM" + columns( formlist, TP->query_term_width() );
  TP->set_form(form);
  // Display specific info on current form
  buf += "\n~CTITActions~CDEF:\n";
  foreach (name: OBJ->query_actions() - OBJ->query_reactions() ) {
    if (TP->query_action_enabled(name))
      buf += " ~CCOM"+pad(name,15,0)+
             "~CDEF"+OBJ->query_action_desc(name)+"\n";
    else
      buf += " ~CDRK"+pad(name,15,0)+
             "~CDEF"+OBJ->query_action_desc(name)+" (disabled)\n";
  }
  buf += "\n~CTITReactions~CDEF:\n";
  foreach (name: OBJ->query_reactions()) {
    if (TP->query_action_enabled(name))
      buf += " ~CCOM"+pad(name,15,0)+
             "~CDEF"+OBJ->query_action_desc(name)+"\n";
    else
      buf += " ~CDRK"+pad(name,15,0)+
             "~CDEF"+OBJ->query_action_desc(name)+" (disabled)\n";
  }
  msg(buf);
}

void do_change(string str) {
   string name, buf;
   if (member(TP->query_known_forms(),str) == 0) {
      buf = "Valid parameters for ~CCOMform change~CDEF are:\n";
      buf += "~CCOM[form]~CDEF to change your current form.\n";
      buf += "You know the following forms:\n";
      foreach (name: m_indices(TP->query_known_forms()))
         buf += "  "+ pad(name,12,0);
      msg(buf);
      return;
   } else {
      TP->set_form(str);
      this_player()->msg_local( "~CACT" + this_player()->query_form_object()->query_change_message() + "~CDEF" );
   }
}

void do_enable( string arg ) {
   if( this_player()->add_form_action( FORM, arg ) )
      msg( "Ok, '"+arg+"' enabled." );
   else
      msg( "Hmm ... either you're doing it already, or there's no such thing." );
}

void do_disable( string arg ) {
   if( member(this_player()->query_form_actions(), arg) < 0 )
      msg( "You aren't doing that anyway...");
   else {
      msg("All right, you will no longer use '"+arg+"'.");
      this_player()->remove_form_action( FORM, arg );
   }
}

int main(string str) {
  string command, arg;

  if (!str)
    do_list();
  else {
    if (sscanf(str,"%s %s",command,arg) != 2)
      command = str;
    switch (command) {
      case "change": do_change(arg); break;
      case "list": do_list(); break;
      case "enable": do_enable( arg ); break;
      case "disable": do_disable( arg ); break;
      default:
        msg("Sorry, can't do that with the form command! Read help form.");
    }
  }

  return 1;
}

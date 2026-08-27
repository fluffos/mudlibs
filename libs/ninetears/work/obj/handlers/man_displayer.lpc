/* Hamlet, March 1996 -- This object displays manual pages and/or lets 
                         the user navigate the manual system.
*/

#include <man.h>


object user;      /* Who owns this displayer? */
int MENUING;      /* Are we in the menu system? */
string *curpath;  /* What directory are they in? */

/* These are scratchpad sorts of things... 
   keeps us from having to re-query or recalculate. 
*/
string curmenu;
string ftext;
string *subdirs;
string *docs;

void create() {
  seteuid("Root");
  curpath = ({ });
  MENUING = 0;  /* paranoia */
}

void dest_me() {
  destruct(this_object());
}

varargs void show_menu(string file, int redisplay);
void show_document(string file);
void input_prompt(string str);
void delay_prompt(string str);

void do_query(string str, object me) {
  string *bits;
  int building;
  string fname;
  
  user = me;
  
  if(!str)
    str = "";
  else {
    bits = explode(str," ");
  
    if(sizeof(bits) > 1)
      str = implode(bits,"/");
  }
  
  building = MAN_HANDLER->doc_index_building();
  fname = MAN_HANDLER->get_doc_fname(str);
  
  if(!fname || !strlen(fname)) {
    tell_object(user,"Your subject was not found in the index.\n");
    if(building) 
      tell_object(user,"However, the system is currently loading.  "
                  "Try again in a minute or so.\n");
    return;
  }
  
  /* Okay!  We've got a match.  Do we enter the menuing system or
     just display a page?
  */
  
  bits = explode(fname,"/");
  
  if(bits[sizeof(bits)-1] == "README") {  /* It's a directory. */
    if(building) {
      tell_object(user,"The manual system is currently loading.  "
                  "Please wait a few seconds.\n");
      return;
    }
    
    if(sizeof(bits) == 2)
      curpath = ({ });
    else
      curpath = bits[1..sizeof(bits)-2];    
    
    curmenu = fname;
    
    MENUING = 1;
    show_menu(fname);
    return;
  }
  
  /* else     (it's a document.) */
  show_document(fname);
}

/* This one shows both a directory's doc file (dir/README) and a list
   of available documents and subtopics in the dir.  It relies on 
   curpath being properly set.
*/
varargs void show_menu(string file, int redisplay) {
  if(!redisplay) {
    if(file_size(MANDIR+file) > 0)
      ftext = read_file(MANDIR+file);
    else
      ftext = read_file(MANDIR+"NO_README");
      
    subdirs = MAN_HANDLER->get_subdirs(implode(curpath,"/"));
    docs = MAN_HANDLER->get_docs_in_dir(implode(curpath,"/"));
  }
  
  if(sizeof(curpath))
    tell_object(user,"\n%^BOLD%^%^BLUE%^Topic: "+implode(curpath,"/")+
                "%^RESET%^\n\n");
  else
    tell_object(user,"\n");
    
  tell_object(user,ftext+"\n");

  if(sizeof(subdirs))
    tell_object(user,"Subtopics:\n\n%^BOLD%^%^CYAN%^"+
                sprintf("  %-#*s",user->query_cols(),
                implode(subdirs,"\n"))+"\n\n%^RESET%^");
  if(sizeof(docs))
    tell_object(user,"Documents:\n\n%^CYAN%^"+
                sprintf("  %-#*s",user->query_cols(),
                implode(docs,"\n"))+"\n\n%^RESET%^");
  tell_object(user,"Type 'q' to quit.  Enter subtopic or document to "
              "continue.\n'.' will redisplay this menu.  Press <ret> "
              "to go one level lower.\n%^BOLD%^%^BLUE%^/"+
              implode(curpath,"/")+">%^RESET%^ ");
  input_to("input_prompt");
}

/* This one displays a document, more'ing it if necessary. */
void show_document(string file) {
  string *fdata;
  string data;
  
  if(file_size(MANDIR+file) == 0) {
    tell_object(user,"Oops.  That file seems to be empty.\n"
                "[Press return to continue.]");
    input_to("delay_prompt");
    return;
  }
  else {
    fdata = explode(file,"/");
    data = "\n%^BOLD%^%^BLUE%^Topic: "+
           implode(fdata[1..sizeof(fdata)],"/")+"%^RESET%^\n\n";
    data += read_file(MANDIR+file);
  
    if(sizeof(explode(data,"\n")) <= user->query_rows()) {
      tell_object(user,data+"\n");
      if(MENUING) {
        tell_object(user,"[Press return to continue.]");
        input_to("delay_prompt");
      }
      else
        dest_me();
      return;
    }
    else {
      user->set_finish_func("finish_func");
      user->more_string(data,"["+file+"]");
    }
  }
}

/* We just more'd a file.  This function gets entered when we get back. */
void finish_func() {
  if(MENUING)
    show_menu(curmenu,1);
  else
    dest_me();
}

/* Needed for files shorter than one screen. */
void delay_prompt(string str) {
  finish_func();
}

void input_prompt(string str) {
  int i;
  string doc;
  
  if(!str || !strlen(str) || (str == "..")) {  /* Drop a level. */
    if(!sizeof(curpath)) { /* exit the system */
      dest_me();
      return;
    }
    
    /* Otherwise, just go one directory shallower */
    if(sizeof(curpath) == 1)
      curpath = ({ });
    else
      curpath = curpath[0..sizeof(curpath) - 2];
      
    curmenu = MAN_HANDLER->get_doc_fname(implode(curpath,"/"));
    show_menu(curmenu);
    return;
  }
  
  /* else */
  if(str == "q") {  /* They're quitting the system. */
    dest_me();
    return;
  }
  
  /* else */
  if(str == ".") {
    show_menu(curmenu,1);
    return;
  }
  
  /* else, this is a real attempt to view a subtopic or document. */
  i = member_array(str,subdirs);
  
  if(i == -1) {
    i = member_array(str,docs);
  
    if(i == -1) { /* Dummies, they didn't type anything valid. */
      tell_object(user,"That selection is not valid.\n\n"
                  "[Press return to continue.]");
      input_to("delay_prompt");
      return;
    }
    
    /* Else, they're viewing a document. */
    if(sizeof(curpath))
      doc = implode(curpath,"/")+"/"+str;
    else
      doc = str;
    show_document(MAN_HANDLER->get_doc_fname(doc)); 
  }
  else { /* They want to view a new directory */
    if(sizeof(curpath))
      doc = implode(curpath,"/")+"/"+str;
    else
      doc = str;
    curmenu = MAN_HANDLER->get_doc_fname(doc);
    curpath += ({ str });
    show_menu(curmenu);
  }
}

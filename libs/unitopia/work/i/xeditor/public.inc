// This file ist part of Avalon Mudlib.
// Copyright 1996-99 by Avatar@Avalon. All rights reserved.
// ----------------------------------------------------------------
// File:        /i/xeditor/public.inc
// Description: Public-Funktionen
// Author:      Avatar
// Modified:
//
// $Log: public.inc,v $
// Revision 1.7  2009-03-20 08:05:04  gnomi
// Man kann die Hoehe und Breite nun auf Automatik stellen.
//
// Revision 1.6  2001/11/25 05:03:20  gnomi
// Test auf 3000-Zeilen-Maximum eingebaut.
//
// Revision 1.5  2001/04/29 14:21:48  freaky
// deprecated Funktion copy-mapping rausgenommen.
//
// Revision 1.4  2001/02/09 01:35:45  gnomi
// Funktion edit_file, um eine bestimmte Datei zu oeffnen (ohne
// Parameter-Parsing oder aehnlichem.)
//
// Revision 1.3  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//


//
// Editieren eines Files ("Kommandoschnittstelle" fuer eine add_action())
//
// 'str':        Uebergabestring (siehe Manpage zum xEd)
// 'call_at_end': Closure, die beim Verlassen des Editors aufgerufen wird
//                Deklaration: funktion(string *buffer, int esc_key)
//
varargs int edit_command(string str, closure call_at_end)
{
   mapping opt;
   mixed tmp;

   SECURE;

   if( !options )
      options=([]);
   options["end_call"]=
      call_at_end ? CLOSURE_CONTAINER->do_bind(call_at_end) : 0;
   options["mode"]=EDITOR_MODE_FILE;

   str=str||"";
   if( str == "#" )
   {
      editor_keyboard_test();
      return 1;
   }
   if( str == "-" )
   {
      if( !buffer )
      {
         write("Der Textbuffer ist leer.\n");
         return 1;
      }
      if (!editor_process_options())
         return 1;
      continue_editing();
      return 1;
   }
   if( str == "*" )
   {
      editor_save_current_file();
      return 1;
   }
   
   opt=getopt(str, ([
      "x": "%s",
      "X": 0,
      "y": "%s",
      "Y": 0,
      "s": "%d",
      "S": 0,
      "i": 0,
      "I": 0,
      "t": "%d",
      "T": 0,
      "p": 0,
      "P": 0,
      "b": 0,
      "B": 0,
      "m": 0,
      "O": 0,
      "o": 0 ]), GO_FAILS );

   if( !mappingp(opt) || opt["errors"] )
      return 0;

   buffer=({});

   if( opt["o"] || opt["O"] )
   {
      if( !options["filename"]=owner_search_filename(
          opt["args"] ? opt["args"][0] : "") )
      {
         if( !sizeof(opt["args"]) )
            notify_fail("In Markierung @0 ist nichts markiert.\n");
         else
            notify_fail("Objekt '"+opt["args"][0]+"' nicht gefunden.\n");
         return 0;
      }
      filename=owner_convert_filename(options["filename"]);
   }
   if( opt["x"] && sizeof(opt["x"]))
   {
      int x;
     
      if( !strlen(opt["x"][0]) || (str2int(opt["x"][0], &x) && strstr("automatisch", opt["x"][0])))
         return notify_fail("Syntax-Fehler bei Option -x.\n");
     
      opt["x"] = ({x});
   }
   if( opt["y"] && sizeof(opt["y"]))
   {
      int y;
     
      if( !strlen(opt["y"][0]) || (str2int(opt["y"][0], &y) && strstr("automatisch", opt["y"][0])))
         return notify_fail("Syntax-Fehler bei Option -y.\n");
     
      opt["y"] = ({y});
   }
   
   editor_get_options();

   convert_options(opt, "max_x",     "X", "x", 0,                 0);
   convert_options(opt, "max_y",     "Y", "y", 0,                 0);
   convert_options(opt, "split_y",   "S", "s", DEFAULT_SPLIT_Y,   0);
   convert_options(opt, "tab_width", "T", "t", DEFAULT_TAB_WIDTH, 0);
   convert_options(opt, "show_pos", "P", "p",  0,                 1);
   convert_options(opt, "insert",   "I", "i",  0,                 1);
   convert_options(opt, "backup",   "B", "b",  0,                 1);

   if( options["max_x"] && options["max_x"] < 80 )
   {
      write("Die angegebene max. Zeilenbreite ("+options["cur_max_x"]+") ist zu "+
         "klein.\nMindestwert ist 80.\n");
      return 1;
   }
   if( options["max_y"] && options["max_y"] < 10 )
   {
      write("Die angegebene max. Zeilenanzahl ("+options["max_y"]+") ist zu "+
         "klein.\nMindestwert ist 10.\n");
      return 1;
   }

   if( options["split_y"] < 0 )
   {
      write("Der Splitpunkt muss groesser als 1 sein.\n");
      return 1;
   }

   if( opt["m"] )
      editor_save_options();

   if (!editor_process_options())
      return 1;

   if( !editor_load_keyrc() )
      return 1;

   if( !options["filename"] )
      filename=options["filename"]="";
   if( !options["template_dir"] )
      options["template_dir"]=EDITOR_TEMPLATE_DIR;

   if( !opt["o"] )
   {
      if( !sizeof(opt["args"]) || opt["O"] )
      {
         buffer=({});
         start_editor();
         file_browser(#'editor_load_2, 0, 0, 
            opt["O"] ? options["filename"] : 0);
         return 1;
      }
   
      options["filename"]=owner_add_path(opt["args"][0]);
      filename=owner_convert_filename(options["filename"]);

      if( file_size(options["filename"]) > EDITOR_MAX_FILE_SIZE )
      {
         write("Die Datei ist groesser als "+EDITOR_MAX_FILE_SIZE+" Bytes, "+
            "und kann deshalb nicht geladen werden.\n");
         return 1;
      }
   }

   tmp=editor_read_file(options["filename"]);
   if(tmp && strlen(tmp&"\n")>=query_limits()[LIMIT_ARRAY])
   {
      write(wrap("Die Datei hat mehr als "+(query_limits()[LIMIT_ARRAY])+
         " Zeilen, und kann deshalb nicht geladen werden."));
      return 1;
   }
   buffer = tmp ? explode(tmp,"\n") : ({});
   
   start_editor();
   if( tmp=strlen(implode(buffer,"\n")) )
      msg("Datei geladen: '"+options["filename"]+"' ("+tmp+" Bytes)");
   else
      msg("Neue Datei: '"+options["filename"]+"'");
      
   return 1;
}

//
// Datei editieren
//
// 'file':        Die zu editierende Datei
// 'call_at_end': Closure, die beim Verlassen des Editors aufgerufen wird
//                Deklaration: funktion(string *buffer, int esc_key)
//
// Liefert 1, bei Erfolg, ansonsten 0 oder -1.
// (Fehlermeldung wird per write ausgegeben)
int edit_file(string file, closure call_at_end)
{
   mixed tmp;
   
   SECURE;

   if( !options )
      options=([]);
   options["end_call"]=
      call_at_end ? CLOSURE_CONTAINER->do_bind(call_at_end) : 0;
   options["mode"]=EDITOR_MODE_FILE;

   editor_get_options();
   options["split_y"]=options["split_y"] || DEFAULT_SPLIT_Y;
   options["tab_width"]=options["tab_width"] || DEFAULT_TAB_WIDTH;
   if( !member(options,"show_pos") ) options["show_pos"]=1;
   if( !member(options,"insert") ) options["insert"]=1;
   if( !member(options,"backup") ) options["backup"]=1;

   if (!editor_process_options())
      return 0;

   buffer=({});
   if( !editor_load_keyrc() )
      return 0;
   options["filename"]=filename="";
   if( !options["template_dir"] )
      options["template_dir"]=EDITOR_TEMPLATE_DIR;

   options["filename"]=file;
   filename=owner_convert_filename(options["filename"]);

   if( file_size(options["filename"]) > EDITOR_MAX_FILE_SIZE )
   {
      write("Die Datei ist groesser als "+EDITOR_MAX_FILE_SIZE+" Bytes, "+
         "und kann deshalb nicht geladen werden.\n");
      return 0;
   }

   tmp=editor_read_file(options["filename"]);
   if(tmp && strlen(tmp&"\n")>=query_limits()[LIMIT_ARRAY])
   {
      write(wrap("Die Datei hat mehr als "+(query_limits()[LIMIT_ARRAY])+
         " Zeilen, und kann deshalb nicht geladen werden."));
      return 0;
   }
   buffer = tmp ? explode(tmp,"\n") : ({});
   
   start_editor();

   if( tmp=strlen(implode(buffer,"\n")) )
      msg("Datei geladen: '"+options["filename"]+"' ("+tmp+" Bytes)");
   else
      msg("Neue Datei: '"+options["filename"]+"'");
      
   return 1;
}


//
// Buffer editieren
//
// 'edit_buffer': Inhalt des Textbuffers
// 'call_at_end': Closure, die beim Verlassen des Editors aufgerufen wird
//                Deklaration: funktion(string *buffer, int esc_key)
//
int edit_buffer(string *edit_buffer, closure call_at_end)
{
   SECURE;

   if( !edit_buffer || !call_at_end )
      return 0;
   if( !editor_load_keyrc() )
      return 0;

   if( !options )
      options=([]);
   options["end_call"]=CLOSURE_CONTAINER->do_bind(call_at_end);
   options["mode"]=EDITOR_MODE_BUFFER;

   editor_get_options();
   options["split_y"]=options["split_y"] || DEFAULT_SPLIT_Y;
   options["tab_width"]=options["tab_width"] || DEFAULT_TAB_WIDTH;
   if( !member(options,"show_pos") ) options["show_pos"]=1;
   if( !member(options,"insert") ) options["insert"]=1;
   if( !member(options,"backup") ) options["backup"]=1;

   if (!editor_process_options())
      return 0;

   buffer=({})+edit_buffer;
   options["filename"]=filename="";
   start_editor();
   msg("Text editieren ("+strlen(implode(buffer,"\n"))+" Bytes) - "+
      "Editor verlassen mit <ctrl+k>, <ctrl+x>");
   return 1;
}

//
// xEd initialisieren (sollte im init() des Tools aufgerufen werden)
//
void init_xeditor(object _owner)
{
   if( owner )
      return;
 
   owner=_owner;

   S_clr_scr=sprintf("%c[2J",27);
   S_clr_eos=sprintf("%c[J",27);
   S_reset=sprintf("%cc",27);
   S_home=sprintf("%c[H",27);
   S_revers=sprintf("%c[7m",27);
   S_underline=sprintf("%c[4m",27);
   S_norm=sprintf("%c[0m",27);
   S_split_=sprintf("%c[",27);
   S_pos_=sprintf("%c[",27);
}


//
// Avalon-Mudlib - spezifische Funktionen, die im Player stehen
// (koennen von aussen ueberlagert werden, falls sie nicht vorhanden sind)
//

// Macht aus einer relativen Pfadangabe in 'fname' eine absolute.
// Beruecksichtigt auch die Pfadkuerzel.
string owner_add_path(string fname)
{
   return (string)owner->add_path(
      regreplace(fname,sprintf("[^!-%c",127)+"]","",1));
}

// Akt. Pfad, in dem sich der Wizard befindet
string owner_query_current_path()
{
   string ret;
   
   return strlen(ret=(string)owner->query_current_path()) > 1 
      ? (ret+"/.") 
      : "/.";
}

// Aendern des akt. Pfades
void owner_set_current_path(string path)
{
   owner->set_current_path(path);
}

// Sucht nach einem Objekt 'name', und liefert dessen Filenamen
string owner_search_filename(string name)
{
   object ob;
   string ret, tmp;
   
   if( ob=search_object(name) )
   {
      ret=explode(object_name(ob),"#")[0]+".c";
#if MUD_NAME == "Seifenblase"
      return ret;
#else
      return (tmp=map2domain(ret,1)) ? tmp : ret;
#endif
   }
}

// Veraendert auf Wunsch das Aussehen des Filenamens fuer den Header
string owner_convert_filename(string fname)
{
   string *tmp;
   
   tmp=explode(fname,"/");
   return implode(tmp[0..2],"/") == ("/w/"+geteuid())
      ? ("~/"+implode(tmp[3..],"/"))
      : fname;
}

// Speichert die Editor-Optionen im Spieler
void owner_set_editor_options(mapping options)
{
   owner->set_editor_options(options);
}

// Liefert die Editor-Optionen vom Spieler
mapping owner_query_editor_options()
{
   return (mapping)owner->query_editor_options() || ([]);
}

// Liefert den grossgeschriebenen Namen des Spielers
string owner_query_cap_name()
{
   string name;
   
   name=(string)owner->query_cap_name();
   if( lower_case(name) != (string)owner->query_real_name() )
      name=capitalize((string)owner->query_real_name());

   return name;
}

// Darf 'owner' Fileoperationen ausfuehren?
int owner_is_wizard()
{
#ifdef FinalFrontier // FF ist leider nicht mehr Unilib-kompatibel
   return owner && wizp(owner);
#endif
   return owner && owner->query_wiz_level();
}

int owner_query_client_height()
{
    return owner && owner->query_client_height(1);
}

int owner_query_client_width()
{
    return owner && owner->query_client_width();
}

// Kann von aussen aufgerufen werden, wenn man etwas schief laufen sollte
void editor_save_current_file()
{
   string fname;
   
   if( owner ) // && this_interactive() == owner )
   {
      if( getuid() != owner->query_real_name() )
         write("File kann nicht abgespeichert werden.\n");
      else
      if( !sizeof(buffer) )
         write("Buffer leer.\n");
      else
      {
         fname=sprintf("/w/%s/DEAD_ED%%%d",getuid(),time());
         if( !editor_write_file(fname,implode(buffer,"\n")) )
            write(wrap("Die Datei '"+fname+"' konnte nicht erfolgreich "+
               "geschrieben werden."));
         else
            write(wrap("Der Text wurde in '"+fname+"' abgespeichert."));
      }
   }
   else
      write("Du darfst das nicht.\n");
}

// Soll Editor nach dem Editieren zerstoert werden?
static int query_remove_after_editing() { return 0; }
 
// Erstarrt der Spieler zu einer Statue, wird der Editor-Shadow automatisch
// entfernt
void notify_net_dead(object who)
{
   if( who )
      who->destruct_editor_shadow();
   editor_save_current_file();
}
 
// Und das gleiche nochmal fuer die UNItopia-Lib
void notify_netdead(object who)
{
   notify_net_dead(who);
}
 
#ifdef Seifenblase
// Der Editor darf beim Wechsel einer Domain nicht zerstoert werden
int query_farmove_allowed() 
{
   return 1;
}
#endif
 
//
// Interessante Variablen...
//
mapping query_editor_keys()     { return copy(keys);    }
mapping query_editor_options()  { return copy(options); }
object query_editor_owner()     { return owner; }


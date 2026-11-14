// This file ist part of Avalon Mudlib.
// Copyright 1996-99 by Avatar@Avalon. All rights reserved.
// ----------------------------------------------------------------
// File:        /i/xeditor/utils.inc
// Description: Utilitiy-Funs
// Author:      Avatar
// Modified:
//
// $Log: utils.inc,v $
// Revision 1.11  2009-03-20 08:05:04  gnomi
// Man kann die Hoehe und Breite nun auf Automatik stellen.
//
// Revision 1.10  2008/01/28 13:19:04  gnomi
// Typo.
//
// Revision 1.9  2007/08/11 23:31:14  gnomi
// VT100-Client deaktivieren, waehrend einer Editor-Sitzung.
//
// Revision 1.8  2006/08/29 22:34:28  gnomi
// Evalsparrendere Tab-Ersetzung.
//
// Revision 1.7  2005/06/03 16:46:31  menaures
// Tab-Konvertierung, Einlesen und Speichern von Dateien verbessert.
//
// Revision 1.6  2003/05/28 01:04:03  gnomi
// MAY_WRITE statt MASTER->valid_write nehmen.
//
// Revision 1.5  2001/11/25 05:03:20  gnomi
// Test auf 3000-Zeilen-Maximum eingebaut.
//
// Revision 1.4  2001/03/15 14:59:52  freaky
// geshadowte Variablen rausgenommen.
//
// Revision 1.3  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#include <simul_efuns.h>

//
// Textausgabe
//
private string Head()
{
   if( fb_map )
      return fb_map["inherit_top"]
         ? sprintf(S_pos(1,options["split_y"]+1)+S_revers+
           "   Inherit-Browser: %-43s   Zeile: %3d   \n"+S_norm,
           fb_map["inherit_top"][<39..],cur_y+delta_y)
         : sprintf(S_pos(1,options["split_y"]+1)+S_revers+
           "   File-Browser: %-46s   Zeile: %3d   \n"+S_norm,
           fb_map["path"][<42..],cur_y+delta_y);

   if( options["show_pos"] )
      return sprintf(S_pos(1,options["split_y"]+1)+S_revers+
         " %s %-30s  Spalte: %3d   Zeile: %3d   Ctrl-O = Hilfe   \n"+S_norm,
         options["insert"] ? "I" : " ",
         filename[<30..],cur_x+delta_x,cur_y+delta_y);

   return sprintf(S_pos(1,options["split_y"]+1)+S_revers+
      "   %-57s   Ctrl-O = Hilfe   \n"+S_norm,filename[<57..]);
}

varargs private string Line(int not_revers)
{
   int buffer_y;

   if( (buffer_y=delta_y+cur_y-1) >= sizeof(buffer) )
      return "";

   if( fb_map && !not_revers )
      return 
         (options["show_pos"] ? Head() : "")+
         S_revers+
         S_pos(1,options["split_y"]+cur_y+1)+
         buffer[buffer_y]+
         S_norm;

   return 
      ((buffer_y >= block_begin && buffer_y <= block_end) ? S_revers : "")+
      S_pos(1,options["split_y"]+(qst_map ? options["cur_max_y"] : cur_y)+1)+
      buffer[buffer_y][delta_x..delta_x+options["cur_max_x"]-2]+
      S_norm;
}

private string Clean_line()
{
   return Line(1);
}

private string Cursor()
{
   if( fb_map )
      return Line();

   return (options["show_pos"] ? Head() : "")+
      S_pos(cur_x,options["split_y"]+(qst_map ? options["cur_max_y"] : cur_y)+1);
}

private string Screen()
{
   string ret;
   int max_y;
   closure extr;
   
   extr=lambda(({'str}),({#'[..],'str,0,options["cur_max_x"]-2}));
#  define IMP(x,y) (sizeof(x) ? ("\n"+y+implode(x,"\n")) : y)

   if( block_begin <= block_end &&
       block_begin < (max_y=delta_y+options["cur_max_y"]-1) &&
       block_end > delta_y )
   {
      int y0, y1;

      y0 = block_begin < delta_y ? delta_y : block_begin;
      y1 = block_end > max_y ? max_y : block_end;

      ret=IMP(map(buffer[delta_y..y0-1],extr),"")+
          IMP(map(buffer[y0..y1],extr),S_revers)+
          IMP(map(buffer[y1+1..max_y],extr),S_norm);
   }
   else
      ret=IMP(map(buffer[delta_y..delta_y+options["cur_max_y"]-1],extr),"");

   return
      //S_split(1,options["split_y"])+
      S_pos(1,options["split_y"])+
      (options["split_y"] ? S_clr_eos : S_clr_scr)+
      Head()+
      ret[1..];
}



//
// Output-Routinen
//
private void out(string txt)
{
   tell_object(owner,txt);
}

private void msg(string txt)
{
   out(
      S_pos(1,options["split_y"]+options["cur_max_y"]+1)+
      S_revers+
      sprintf("%:-*s",options["cur_max_x"]-1,txt)+
      S_norm+
      Cursor());

   msg_printed=1;
}

private void erase_msg()
{
   int buffer_y;
   
   msg_printed=0;

   buffer_y=delta_y+options["cur_max_y"]-1;
   
   out(
      S_pos(1,options["split_y"]+options["cur_max_y"])+
      sprintf("%:-*s\n%:-*s",
         options["cur_max_x"]-1,
         (buffer_y-1) < sizeof(buffer)
            ? buffer[buffer_y-1][delta_x..delta_x+options["cur_max_x"]-2]
            : "",
         options["cur_max_x"]-1,
         buffer_y < sizeof(buffer)
            ? buffer[buffer_y][delta_x..delta_x+options["cur_max_x"]-2]
            : "" ) +
      Cursor() );
}


//
// Disk-IO
//
private string editor_read_file(string filename)
{
   int byte_limit, i;
   string ret, tmp;

#if 0
   options["filename"]=filename;
#endif

   byte_limit = query_limits()[LIMIT_BYTE];
   ret = "";

   while(tmp = read_bytes(filename, i, byte_limit))
   {
       i += byte_limit;
       ret += tmp;
   }
      
   // Avatar: TAB-Konvertierung muss noch verbessert werden!
   // ret=regreplace(ret,"\t","        ",1);

   ret=regreplace(ret,"[\r]","",1);
   ret=regreplace(ret,sprintf("[^\t\n -%c",255)+"]","@",1);

   /* Tab-Ersetzung a la Menaures: */
   /* Gnomi-Ergaenzung: Wir verlangen das \n am Anfang, das erspart der
      Regexp-Engine ein bisschen Sucherei und spart uns Evals. */
   ret = regreplace("\n"+ret, "\n[^\n]*\t",
         (:  // $1 ist Zeile mit beliebig vielen (mindestens einem) \t
	     // und beginnend mit einem \n.
             $2 = member($1, '\t');

             do
             {
                 $3 = 8 - (($2-1) % 8);
                 $1[$2..$2] = " "*$3;
                 $2 = member($1, '\t');
             } while($2 != -1);

             return escape_string($1, ESCAPE_REPLACE);
         :), 1)[1..];

   return ret;
}

private int editor_write_file(string filename, string data)
{
   return write_file(filename, data);
}


varargs private string *load_buffer(string str, int template)
{
   string file, *_buffer;

   if( template && strlen(str) && str[0] != '/' && str[0] != '~' )
      str=EDITOR_TEMPLATE_DIR+str;

   str=owner_add_path(str);

   if( file_size(str) > EDITOR_MAX_FILE_SIZE )
      msg("Datei ist groesser als "+EDITOR_MAX_FILE_SIZE+" Bytes, und kann "+
         "deshalb nicht geladen werden.");
   else
   if( !file=editor_read_file(str) )
      msg("Datei konnte nicht geladen werden: '"+str+"'");
   else
   if(strlen(file&"\n")>=query_limits()[LIMIT_ARRAY])
       msg("Datei hat mehr als "+(query_limits()[LIMIT_ARRAY])+
          " Zeilen und kann deshalb nicht geladen werden.");
   else
   if( !sizeof(_buffer=explode(file,"\n")) )
      msg("Datei ist leer: '"+str+"'");
   else
   {
      block_begin=1;
      block_end=0;
      return _buffer;
   }
}



//
// Buffer-Behandlung
//
private int line_length()
{
   int buffer_y;
   
   if( (buffer_y=delta_y+cur_y-1) < sizeof(buffer) )
      return strlen(buffer[buffer_y]);
}

private void add_str(string str)
{
   int i, len;
   int buffer_x, buffer_y;
   string ret;
   
   buffer_x=delta_x+cur_x-1;
   buffer_y=delta_y+cur_y-1;
   
   while( sizeof(buffer) <= buffer_y )
      buffer+=({ "" });

   if( (len=strlen(buffer[buffer_y])) < (delta_x+cur_x) )
      buffer[buffer_y]+=copies(" ",delta_x+cur_x-len-1);

   for(i=0;i<strlen(str);++i)
   {
      if( str[i] != '\r' && str[i] != '\n' )
      {
         if( str[i] < ' ' )
            str[i]='@';

         if( options["insert"] )
         {
            ret=str[i..i]+buffer[buffer_y][buffer_x..];
            
            buffer[buffer_y]=
               buffer[buffer_y][0..buffer_x-1]+
               str[i..i]+
               buffer[buffer_y][buffer_x..];
         }
         else
         {
            ret=str[i..i]+buffer[buffer_y][buffer_x+1..];
            
            buffer[buffer_y]=
               buffer[buffer_y][0..buffer_x-1]+
               str[i..i]+
               buffer[buffer_y][buffer_x+1..];
         }

         ++buffer_x;

         if( ++cur_x > options["cur_max_x"] )
         {
            // Exception
            --cur_x;
            ++delta_x;
            out(Line()+Cursor());
         }
         else
            // Faster output
            out(
               ((buffer_y >= block_begin && buffer_y <= block_end) 
                  ? S_revers : "" )+
               ret[0..options["cur_max_x"]-cur_x]+S_norm+Cursor());
      }
      else
      {
         cur_x=1;
         ++cur_y;
      }
      
      if( cur_y >= options["cur_max_y"]+1 )
         --cur_y;
   }
}



//
// Keybuffer loeschen
//
private void clear_key_buffer()
{
   possible_keys=keys;
   key_buffer="";
}

                  

//
// Qst: fragt in der unteren Editor-Zeile nach einem Text
//      'txt':   nach was wird gefragt
//      'def':   Default-Wert
//      'func':  Funktion, die nach dem Druck auf <Return> angespr. wird
//      'extra': Extra-Parameter, die dieser Funktion uebergeben werden
//
// Deklaration von 'func': int function(string eingabe_string, mixed extra)
// Liefert 'func' einen Wert zurueck, kehrt die Routine nicht automatisch
// in die Eingabeschleife loop() zurueck.
//
private varargs void qst(string txt, string def, closure func, mixed extra)
{
   if( !sizeof(buffer) )
      buffer = ({ "" });

   qst_map = ([
      "func":        func,
      "extra":       extra,
      "sik_buffer":  buffer[0],
      "sik_cur_x":   cur_x,
      "sik_cur_y":   cur_y,
      "sik_delta_x": delta_x,
      "sik_delta_y": delta_y,
      "x0":          strlen(txt)+3 ]);

   buffer[0]=txt+": "+def;
   cur_x=qst_map["x0"];
   cur_y=1;
   delta_x=delta_y=0;
   msg_printed=0;

   out(
      S_pos(1,options["split_y"]+options["cur_max_y"])+
      copies("_",options["cur_max_x"]-1)+"\n"+
      S_norm+
      copies(" ",options["cur_max_x"]-1)+      
      Line()+
      Cursor());
}

varargs private mixed __qst()
{
   closure func;
   mixed extra;
   string ret;

   func=qst_map["func"];
   extra=qst_map["extra"];
   ret=buffer[0][qst_map["x0"]-1..];

   buffer[0]=qst_map["sik_buffer"];
   cur_x=qst_map["sik_cur_x"];
   cur_y=qst_map["sik_cur_y"];
   delta_x=qst_map["sik_delta_x"];
   delta_y=qst_map["sik_delta_y"];

   qst_map=0;
   msg_printed=1;

   return ({ func, ret, extra });
}

private int qst_ok()
{
   mixed arg;

   arg=__qst();
   return funcall(arg[0],arg[1],arg[2]);
}

private void qst_esc()
{
   __qst();
   msg("Vorgang abgebrochen.");
   efun::input_to("loop", EDITOR_INPUT_TO_FLAGS);
}


//
// Ask: wartet in der unteren Editor-Zeile auf eine Bestaetigung: Ja/Nein/Abbr.
//      'txt':   nach was wird gefragt
//      'func':  Funktion, die nach dem Druck auf <Return> angespr. wird
//      'extra': Extra-Parameter, die dieser Funktion uebergeben werden
//
// Deklaration von 'func': int function(string eingabe_string, mixed extra)
// Liefert 'func' einen Wert zurueck, kehrt die Routine nicht automatisch
// in die Eingabeschleife loop() zurueck.
//
private varargs void ask(string txt, closure func, mixed extra)
{
   txt+=" ('J'a/'N'ein/'A'bbruch)? ";
   msg(txt);
   out(S_pos(strlen(txt)+1,options["split_y"]+options["cur_max_y"]+1));
   efun::input_to("ask_loop", EDITOR_INPUT_TO_FLAGS, func,extra);
}

void ask_loop(string str, closure func, mixed extra)
{
   if( str == "J" || str == "j" )
   {
      if( funcall(func,ANSWER_YES,extra) )
         return;
   }
   else
   if( str == "N" || str == "n" )
   {
      if( funcall(func,ANSWER_NO,extra) )
         return;
   }
   else
   if( str != "A" && str != "a" && str[0] != 3 && str[0] != 27 )
   {
      str="Bitte mit 'J' oder 'N' bestaetigen, "+
         "oder 'A' fuer Abbruch tippen: ";
      msg(str);
      out(S_pos(strlen(str)+1,options["split_y"]+options["cur_max_y"]+1));
      efun::input_to("ask_loop", EDITOR_INPUT_TO_FLAGS, func, extra);
      return;
   }
   else
   {
      owner_wants_quit=0;
      out(Line());
      msg("Vorgang abgebrochen.");
   }

   efun::input_to("loop", EDITOR_INPUT_TO_FLAGS);
}


//
// File-Browser
//
//      'func':    Funktion, die nach dem Druck auf <Return> angespr. wird
//      'extra':   Extra-Parameter, die dieser Funktion uebergeben werden
//                 function(string eingabe_string, mixed extra)
//      'cd_path': Wechselt kurzzeitig in ein anderes Verzeichnis, welches
//                 in options[cd_path] steht, und kehrt nach dem Auswaehlen
//                 des Filenamens in das vorrige Verzeichnis zurueck.
//      'inherit': Filenamen eines Inherits - dadurch wird der Inherit-
//                 Browser gestartet
//
// Deklaration von 'func': int function(string eingabe_string, mixed extra)
//
private varargs void file_browser(closure func, mixed extra, string cd_path,
   string inherit_top)
{
   fb_map = ([
      "func":        func,
      "extra":       extra,
      "inherit_top": inherit_top,
      "sik_buffer":  buffer,
      "sik_cur_x":   cur_x,
      "sik_cur_y":   cur_y,
      "sik_delta_x": delta_x,
      "sik_delta_y": delta_y ]);

   if( cd_path )
   {
      fb_map["sik_path"]=owner_query_current_path();
      fb_map["cd_path"]=cd_path;
      owner_set_current_path(options[cd_path]);
   }

   file_browser_init_buffer();
}

private void file_browser_init_buffer()
{
   int i, siz, tim, is_read, is_write, is_exec;
   mixed dir;
   string path, file, ct;

   string *file_buffer, *dir_buffer;
   mixed file_struc, dir_struc;

   cur_x=cur_y=1;
   delta_x=delta_y=0;

   if( fb_map["inherit_top"] )
   {
      string *ilist, *_ilist;

      ilist=inherit_list(load_object(fb_map["inherit_top"]));

      // Avatar: duplikate aussortieren. Das bekannte m_indices(mkmapping-
      // Konstrukt hilft hier nicht weiter, da es die Reihenfolge
      // durcheinander bringt.

      path="";
      dir=_ilist=({});
      for(siz=sizeof(ilist), i=0; i<siz; ++i)
         if( member(_ilist, ilist[i]) < 0 )
         {
            _ilist += ({ ilist[i] });
            dir    += get_dir(ilist[i], 7);
            dir[<3] = ilist[i];
         }
   }
   else
   {
      dir=get_dir(path=owner_query_current_path(),0x07);
      if( strlen(path=path[0..<2]) > 1 )
         dir=({ "..", -2, file_time(implode(explode(path,"/")[0..<2],"/")) })
             + (dir||({}));
   }

   tim=time();
   file_buffer=dir_buffer=({});
   file_struc=dir_struc=({});
   for(siz=sizeof(dir), i=0;i<siz;i+=3)
   {
      file=path+dir[i];

      // Routine fuer Long-Dir teilweise aus /i/zepter/zfiles.inc
      ct=ctime(dir[i+2]);
      ct=(tim-dir[i+2] > 15552000) ? (ct[4..10]+ct[19..]) : ct[4..15];

      is_read=(int)MASTER_OB->valid_read(
         !i ? path : file,geteuid(),"read_file",this_object()) ? 'r' : '-';
#ifndef UNITOPIA_MUDLIB
      is_write=(int)MASTER_OB->valid_write(
         !i ? path : file,geteuid(),"write_file",this_object()) ? 'w' : '-';
#else
      is_write=MAY_WRITE(!i ? path : file, this_object()) ? 'w' : '-';
#endif
      is_exec=file[<2..<1] == ".c" && find_object(file) ? 'x' : '-';

      if( dir[i+1] == -2 )
      {
         dir_buffer+=({ sprintf("%:-*s",options["cur_max_x"]-2,
            sprintf("d%c%c%c%10s  %s  %s", is_read, is_write, is_exec,
               "<DIR>", ct, dir[i]+(dir[i] == ".." ? "" : "/"))) });
         dir_struc+=dir[i..i+2];
      }
      else
      {
         file_buffer+=({ sprintf("%:-*s",options["cur_max_x"]-2,
            sprintf("-%c%c%c%10d  %s  %s", is_read, is_write, is_exec,
               dir[i+1], ct, dir[i])) });
         file_struc+=dir[i..i+2];
      }
   }

   buffer=dir_buffer+file_buffer;
   fb_map["dir"]=dir_struc+file_struc;
   fb_map["path"]=path;

   out(
      S_pos(1,options["split_y"])+
      (options["split"] ? S_clr_eos : S_clr_scr)+
      Head()+
      Screen()+
      Cursor());
}

private void file_browser_quit(int esc)
{
   closure func;
   int extra;
   string fname;
   
   buffer=fb_map["sik_buffer"];
   cur_x=fb_map["sik_cur_x"];
   cur_y=fb_map["sik_cur_y"];
   delta_x=fb_map["sik_delta_x"];
   delta_y=fb_map["sik_delta_y"];
   func=fb_map["func"];
   extra=fb_map["extra"];
   fname=fb_map["fname"];
   if( fb_map["cd_path"] )
   {
      options[fb_map["cd_path"]]=owner_query_current_path();
      owner_set_current_path(fb_map["sik_path"]);
   }

   fb_map=0;
   possible_keys=keys;
   key_buffer="";

   if( esc && filename == "" )
      quit_editor("",1);
   else
   {
      out(Head()+Screen()+Line()+Cursor());
      if( !esc )
         funcall(func,fname,extra);
      efun::input_to("loop", EDITOR_INPUT_TO_FLAGS);
   }
}

private void file_browser_selection()
{
   int y, is_dir;
   string fname;
   
   y=delta_y+cur_y-1;
   if( y >= sizeof(buffer) )
      return;

   if( is_dir=(fb_map["dir"][y*3+1] == -2) )
   {
      if( fb_map["dir"][y*3] == ".." )
      {
         if( !strlen(fname=implode(explode(fb_map["path"],"/")[0..<3],"/")) )
            fname="/";
      }
      else
         fname=fb_map["path"]+fb_map["dir"][y*3];
   }
   else 
      fname=fb_map["path"]+fb_map["dir"][y*3];

   fb_map["fname"]=fname;
   owner_set_current_path(fname);

   if( is_dir )
      file_browser_init_buffer();
   else
      file_browser_quit(0);
}

//
// Einlesen der Tastaturcodes
//
private void add_key(int key, int *path, mixed keys)
{
   int c;

   c=path[0];
   if( sizeof(path=path[1..]) )
   {
      if( !mappingp(keys[c]) )
         keys[c]=([]);
      add_key(key,path,keys[c]);
   }
   else
      keys[c]=key;
}

private mapping get_key_desc()
{
   int i, siz;
   string fname, file, *lines, line;
   mixed desc, id, key, codes;
   mapping ret;

   fname=EDITOR_KEYRC;
   if( !file=read_file(fname) )
   {
      write("xed: konnte '"+fname+"' nicht einlesen.\n");
      return ([]);
   }
   siz=sizeof(lines=explode(file,"\n"));
   for(ret=([]),i=0;i<siz;++i)
   {
      line=regreplace(regreplace(lines[i]," [ ]*"," ",1),"^ [ ]*| [ ]*$","",1);
      if( strlen(line) && line[0..0] != "#" )
      {
         if( sscanf(line,"%s %s %s %s",desc,id,key,codes) != 4 )
         {
            write("xed: Syntax-Fehler in '"+fname+"', Zeile "+(i+1)+".\n");
            return 0;
         }
         if( (id=to_int(id)) >= 0 )
         {
            write("xed: Syntax-Fehler in '"+fname+"', Zeile "+(i+1)+":\n"+
               "Fehlerhafte Kommando-ID.\n");
            return 0;
         }
         if( !ret[id] )
            ret[id]="";
         ret[id]+=sprintf("%-20s  %5d  %-10s  %s\n",
            desc,id,key,codes);
      }
   }
   return ret;
}

private int editor_load_keyrc()
{
   int i, siz;
   string fname, file;
   string *lines, line;
   mixed desc, id, key, codes;
   mixed tmp;
   mapping all_keys;

   fname="/w/"+geteuid()+"/.keyrc";
   if( file_size(fname) < 0 )
      fname=EDITOR_KEYRC;
   if( (tmp=file_time(fname)) >= 0 )
   {
      if( tmp <= keyrc_lasttime )
         return 1;
      keyrc_lasttime=tmp;
   }

   all_keys=fname != EDITOR_KEYRC ? get_key_desc() : ([]);

   keys=([]);
   if( !file=read_file(fname) )
   {
      write("xed: konnte '"+fname+"' nicht einlesen.\n");
      return 0;
   }
   siz=sizeof(lines=explode(file,"\n"));
   for(i=0;i<siz;++i)
   {
      line=regreplace(regreplace(lines[i]," [ ]*"," ",1),"^ [ ]*| [ ]*$","",1);
      if( strlen(line) && line[0..0] != "#" )
      {
         if( sscanf(line,"%s %s %s %s",desc,id,key,codes) != 4 )
         {
            write("xed: Syntax-Fehler in '"+fname+"', Zeile "+(i+1)+".\n");
            return 0;
         }
         if( (id=to_int(id)) >= 0 )
         {
            write("xed: Syntax-Fehler in '"+fname+"', Zeile "+(i+1)+":\n"+
               "Fehlerhafte Kommando-ID.\n");
            return 0;
         }
         if( !sizeof(tmp=explode(codes,",")) )
         {
            write("xed: Syntax-Fehler in '"+fname+"', Zeile "+(i+1)+":\n"+
               "Fehlerhafter/fehlender Tastaturcode.\n");
            return 0;
         }
         add_key(id,map(tmp,#'to_int),keys);
         all_keys=m_delete(all_keys,id);
      }
   }
   
   // Gibt es neue Keycodes, welche nicht im privaten .keyrc-File eingetragen
   // sind?
   if( sizeof(all_keys) )
   {
      desc="ACHTUNG: Es gibt einen/ein paar neue Keycodes, welche noch "+
         "nicht in Deinem\nprivaten .keyrc-File ('"+fname+"') "+
          "eingetragen sind.\nDas solltest Du nun erstmal nachholen.\n\n"+ 
          "Bezeichnung              ID   Taste      Keycodes\n"+
          "-------------------------------------------------\n";
      for(i=sizeof(tmp=m_indices(all_keys));i--;)
         desc+=all_keys[tmp[i]];
      write(desc);
      keyrc_lasttime=0;
      return 0;
   }

   return 1;
}

varargs void editor_keyboard_test(string str, int flag)
{
   if( !flag )
   {
      write("Mit diesem Utility kannst Du die Tastatur-Codes Deines\n"+
         "Terminals herausfinden.\n"+
         "Abbruch mit der Return-Taste.\n");
   }
   else
   {
      if( str[0] == '\r' || str == "\n" )
      {
         write("Vorgang abgebrochen.\n");
         return;
      }
      printf("Code: %d (0x%x)\n",str[0],str[0]);
   }
   efun::input_to("editor_keyboard_test", EDITOR_INPUT_TO_FLAGS, 1);
}


//
// Optionen speichern/laden
//
varargs private void editor_save_options()
{
   int i;
   string *ind;
   mapping map;

   map=owner_query_editor_options();
   // Lieber einzeln kopieren, damit kein Muell mit hineinkommt
   
   ind=({"max_x","max_y","split_y","insert","show_pos","tab_width","backup"});
   for(i=sizeof(ind);i--;)
      map[ind[i]]=options[ind[i]];
   map["version"]=EDITOR_VERSION;
   map["timestamp"]=time();

   owner_set_editor_options(map);
}

private void editor_get_options()
{
   int i;
   string *ind;
   mapping map;

   map=owner_query_editor_options();

   // Lieber einzeln kopieren, damit kein Muell mit hineinkommt
   ind=({"max_x","max_y","split_y","insert","show_pos",
         "tab_width","keys","backup"});
   for(i=sizeof(ind);i--;)
      if( member(map,ind[i]) )
         options[ind[i]]=map[ind[i]];
}

// Options-Wert ermitteln
private void convert_options(mapping opt, string ind, string X, string x, 
   mixed def, int flag)
{
   if( opt[X] )
      options[ind] = def;
   else
      if( flag )
         options[ind] = opt[x] 
            ? opt[x] 
            : member(options,ind)
                 ? options[ind]
                 : 1;
      else
         options[ind] = sizeof(opt[x]) 
            ? opt[x][0]
            : member(options,ind)
                 ? options[ind]
                 : def;
}

private int editor_process_options()
{
   if( !options["max_x"] )
      options["cur_max_x"] = owner_query_client_width() || DEFAULT_MAX_X;
   else
      options["cur_max_x"] = options["max_x"];

   if( !options["max_y"] )
   {
      options["cur_max_y"] = owner_query_client_height();
      if(options["cur_max_y"])
        options["cur_max_y"]--;
      else
        options["cur_max_y"] = DEFAULT_MAX_Y;
   }
   else
      options["cur_max_y"] = options["max_y"];
      
   if( options["cur_max_x"] < 80 )
   {
      write("Die aktuelle max. Zeilenbreite ("+options["cur_max_x"]+") ist zu "+
         "klein.\nMindestwert ist 80.\n");
      return 0;
   }
   if( options["cur_max_y"] < 10 )
   {
      write("Die aktuelle max. Zeilenanzahl ("+options["cur_max_y"]+") ist zu "+
         "klein.\nMindestwert ist 10.\n");
      return 0;
   }

   return 1;
}


//
// Editor starten (non-public)
//
private void continue_editing()
{
   if( !sizeof(keys||([])) )
   {
      write("xed: Tastatur-Codes konnten nicht initialisiert werden.\n");
      return;
   }

   cur_x=cur_x||1;
   cur_y=cur_y||1;
   possible_keys=keys;
   key_buffer="";
   qst_map=fb_map=0;
   owner_wants_quit=0;
   block_begin=1;
   block_end=0;

   editor_shadow=clone_object(EDITOR_SHADOW);
   editor_shadow->init_editor_shadow(owner,options["split_y"]);
   owner->suspend_mudclient();
   out(S_home+Screen()+Cursor());
   efun::input_to("loop", EDITOR_INPUT_TO_FLAGS);
}

private void start_editor()
{
   cur_x=cur_y=1;
   delta_x=delta_y=0;

   continue_editing();
}

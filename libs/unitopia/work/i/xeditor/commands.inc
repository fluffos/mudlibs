// This file is part of Avalon Mudlib
// Copyright 1996-99 by Avatar@Avalon. All rights reserved.
// ----------------------------------------------------------------
// File:        /i/xeditor/commands.inc
// Description: Kommandos fuer den xEd
// Author:      Avatar
// Modified:
//
// $Log: commands.inc,v $
// Revision 1.8  2011-03-15 21:55:12  sorcerer
// Argument von editor_help() -> string
//
// Revision 1.7  2009-03-20 08:05:04  gnomi
// Man kann die Hoehe und Breite nun auf Automatik stellen.
//
// Revision 1.6  2007/08/11 23:31:14  gnomi
// VT100-Client deaktivieren, waehrend einer Editor-Sitzung.
//
// Revision 1.5  2004/04/17 02:18:27  gnomi
// find_search_next: pos initialisieren.
//
// Revision 1.4  2003/05/28 01:04:03  gnomi
// MAY_WRITE statt MASTER->valid_write nehmen.
//
// Revision 1.3  2003/02/14 03:54:56  gnomi
// Rueckwaertssuche:
//  - Geht bis zum Anfang (statt nur bis zur 2. Zeile)
//  - Wenn Cursor uebern Ende hinaus, RTE verhindern.
//  - Bei Suchwiederholung vom Ende letzte Zeile mitbeachten.
//
// Revision 1.2  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//


varargs private void cursor_up(int count)
{
   int tmp;

   if( fb_map )
      out(Clean_line());
   
   if( delta_x )
   {
      delta_x=0;
      out(Line());
   }   

   cur_y-=count;

   if( cur_y < 1 )
      if( delta_y > 0 )
      {
         tmp=options["cur_max_y"]/2;
         if( (delta_y-=tmp) < 0 )
         {
            delta_y=0;
            cur_y=1;
         }
         else
            cur_y=tmp;
                       
         out(Screen());
      }
      else
         cur_y=1;
                  
   out(Cursor());
}

varargs private void cursor_down(int count, int no_output)
{
   int tmp;
   
   if( fb_map )
      out(Clean_line());

   if( delta_x )
   {
      delta_x=0;
      if( !no_output )
         out(Line());
   }

   cur_y+=count;

   if( fb_map && (cur_y+delta_y) >= sizeof(buffer) )
      cur_y=sizeof(buffer)-delta_y;

   if( cur_y >= options["cur_max_y"] )
   {
      tmp=options["cur_max_y"]/2;
      delta_y+=tmp;
      cur_y=tmp+1;

      if( !no_output )
         out(Screen());
   }

   if( !no_output )
      out(Cursor());
}

private int cursor_on_word()
{
   int len, buffer_x, buffer_y, siz;

   buffer_y=delta_y+cur_y-1;
   siz=sizeof(buffer);

   if( buffer_y >= siz )
      return 0;

   buffer_x=delta_x+cur_x-1;
   len=line_length();
      
   if( !buffer_y && !buffer_x )
      return 0;

   if( len && buffer_x < line_length() )
      if( buffer[buffer_y][buffer_x] != ' ' )
         if( buffer_x )
            return buffer[buffer_y][buffer_x-1] != ' ';
         else
            return 0;

   return 1;
}

varargs private void cursor_left(int word)
{
   int len, max_x;

   if( qst_map && (cur_x+delta_x) <= qst_map["x0"] )
      return;

   do
   {
      if( cur_x > 1 )
      {
         len=line_length();

         if( cur_x > (len+1) )
         {
            cur_x=len+1;
            out(Line());
         }
         else
            --cur_x;
      }
      else
         if( delta_x > 0 )
         {
            --delta_x;
            out(Line());
         }
         else
            if( (cur_y+delta_y) > 1 )
            {
               cursor_up(1);
               len=line_length();
               max_x=options["cur_max_x"];

               if( (cur_x=len+1) >= max_x )
               {
                  delta_x=cur_x-max_x;
                  cur_x=max_x;
               }
               out(Line());
            }
            else
               word=0;

   } while( word && (word=cursor_on_word()) );

   out(Cursor());
}

varargs private void cursor_right(int word)
{
   int len;

   do
   {   
      len=line_length();
   
      if( (delta_x+cur_x-1) >= len )
      {
         if( qst_map )
            return;
         cur_x=1;
         cursor_down(1);
         out(Line());
      }
      else
         if( cur_x < options["cur_max_x"] )
            ++cur_x;
         else
            if( len >= (cur_x+delta_x) )
            {
               ++delta_x;
               out(Line());
            }

   } while( word && (word=cursor_on_word()) );

   out(Cursor());
}

varargs private int cursor_goto_line_2(string _line, int x, int dx)
{
   int tmp, line;
   
   if( (line=to_int(_line)) < 1 || line > sizeof(buffer) )
   {
      msg("Diese Zeile gibt es nicht.");
      return 0;
   }

   if( x )
   {
      cur_x=x;
      delta_x=dx;
   }
   else
   {
      cur_x=1;
      delta_x=0;
   }

   delta_y=0;
   cur_y=line;
   if( cur_y >= options["cur_max_y"] )
   {
      tmp=options["cur_max_y"]/2;
      cur_y=tmp+2;
      delta_y=line-cur_y;
   }

   out((fb_map ? Clean_line() : "")+Screen()+Line()+Cursor());
}

private void cursor_goto_line()
{
   qst("Zeile anspringen (^C fuer Abbruch)","",#'cursor_goto_line_2);
}

private void cursor_delete(int backspace)
{
   int buffer_x, buffer_y;
   
   if( qst_map && (cur_x+delta_x) < (qst_map["x0"]+backspace) )
      return;

   buffer_x=delta_x+cur_x-1;
   buffer_y=delta_y+cur_y-1;

   if( sizeof(buffer) <= buffer_y ||
       strlen(buffer[buffer_y]) < (delta_x+cur_x-1) )
   {
      if( backspace )
         cursor_left();
      return;
   }   

   if( backspace )
   {
      if( !buffer_x && buffer_y && options["insert"] )
      {
         cursor_left();
         --buffer_y;
         buffer[buffer_y]+=buffer[buffer_y+1];
         buffer=buffer[0..buffer_y]+buffer[buffer_y+2..];
         out(Screen()+Line()+Cursor());
         return;
      }
      buffer[buffer_y] = options["insert"]
         ? (buffer[buffer_y][0..buffer_x-2]+
            buffer[buffer_y][buffer_x..])
         : (buffer[buffer_y][0..buffer_x-2]+
            " "+
            buffer[buffer_y][buffer_x..]);

      out(Line()+" ");
      cursor_left();
   }
   else
   {
      if( options["insert"] && buffer_x >= strlen(buffer[buffer_y]) )
      {
         if( qst_map )
            return;
         
         if( buffer_y < (sizeof(buffer)-1) )
         {
            buffer[buffer_y]+=buffer[buffer_y+1];
            buffer=buffer[0..buffer_y]+buffer[buffer_y+2..];
            if( block_begin <= block_end )
            {
               if( buffer_y < block_begin )
                  --block_begin;
               if( buffer_y <= block_end )
                  --block_end;
            }
         }
         out(Screen()+Line()+Cursor());
         return;
      }

      buffer[buffer_y] = options["insert"]
         ? (buffer[buffer_y][0..buffer_x-1]+
            buffer[buffer_y][buffer_x+1..])
         : (buffer[buffer_y][0..buffer_x-1]+
            " "+
            buffer[buffer_y][buffer_x+1..]);

      out(Line()+" "+Cursor());
   }
}

private void cursor_delete_line()
{
   int buffer_y;
   
   buffer_y=delta_y+cur_y-1;

   if( sizeof(buffer) > buffer_y )
   {
      buffer=buffer[0..buffer_y-1]+buffer[buffer_y+1..];
      if( block_begin <= block_end )
      {
            if( buffer_y < block_begin )
               --block_begin;
            if( buffer_y <= block_end )
               --block_end;
      }
      out(Screen()+Cursor());
   }
}

private void cursor_return()
{
   if( options["insert"] )
   {
      int buffer_x, buffer_y;
   
      buffer_x=delta_x+cur_x-1;
      buffer_y=delta_y+cur_y-1;

      while( sizeof(buffer) <= buffer_y )
         buffer+=({ "" });
         
      buffer=
         buffer[0..buffer_y-1]+
         ({ buffer[buffer_y][0..delta_x+cur_x-2] }) +
         ({ buffer[buffer_y][delta_x+cur_x-1..] })+
         buffer[buffer_y+1..];

      if( block_begin <= block_end )
      {
         if( buffer_y <= block_begin )
            ++block_begin;
         if( buffer_y <= block_end )
            ++block_end;
      }

      delta_x=0;
      cur_x=1;
      cursor_down(1,1);
      out(Screen()+Cursor());
   }   
   else
   {
      delta_x=0;
      cur_x=1;
      out(Line());
      cursor_down(1);
   }
}

private void cursor_tab()
{
   if( !((delta_x+cur_x-1)%options["tab_width"]) )
      options["insert"] ? add_str(" ") : cursor_right();
   while( (delta_x+cur_x-1)%options["tab_width"] )
      options["insert"] ? add_str(" ") : cursor_right();
}

varargs private void cursor_home(int screen)
{
   if( screen )
   {
      cur_x=cur_y=1;
      delta_x=delta_y=0;
      out(Screen()+Cursor());
   }
   else
   {
      cur_x = qst_map ? qst_map["x0"] : 1;
      delta_x=0;
      out(Line()+Cursor());
   }
}

varargs private void cursor_end(int screen)
{
   int tmp;
   
   if( screen )
   {
      cur_x=1;
      delta_x=0;
      tmp=options["cur_max_y"]/2;
      if( (delta_y=sizeof(buffer)-tmp) < 0 )
      {
         delta_y=0;
         cur_y=sizeof(buffer)||1;
      }
      else
         cur_y=tmp;
         
      out(Screen()+Cursor());
   }
   else
   {
      cur_x=1;
      delta_x=0;
      ++cur_y;
      cursor_left();
   }
}

private void switch_insert_mode()
{
   options["insert"] = options["insert"] ? 0 : 1;
   out(Head()+Cursor());
}


private void quit_editor(string txt, int esc)
{               
   int key;
   
   owner_wants_quit=1;
   out(S_clr_scr+S_home+S_norm);

   if( !options["end_call"] )
      out(txt ? wrap(txt) : "Editor verlassen, ohne Datei abzuspeichern.\n");

   if( editor_shadow )
   {
      key=editor_shadow->flush_buffer(1);
      editor_shadow->destruct_editor_shadow(key);
   }

   if( options["end_call"] )
      catch( funcall(options["end_call"],({})+buffer,esc) );
   else
      if( !key )
         out("\nMit 'xed -' kannst Du weitereditieren.\n");

   if( query_remove_after_editing() )
   {
      this_object()->remove();
      if( this_object() )
         destruct(this_object());
   }
   else
    owner->restart_mudclient();
}


private int editor_save_3(int res, mixed extra)
{
   string txt;
   string file;
   string fname, abs_fname;

   if( res != ANSWER_YES )
   {
      msg("Datei nicht ueberschrieben.");
      return 0;
   }

   file=implode(
      extra[2] ? (buffer[block_begin..block_end]+({""})) : buffer,"\n");

   if( strlen(file) > EDITOR_MAX_FILE_SIZE )
   {
      msg("Die Datei ist groesser als "+EDITOR_MAX_FILE_SIZE+" Bytes, und "+
         "kann deshalb nicht abgespeichert werden.");
      return 0;
   }

   abs_fname=extra[0];
   fname=extra[1];

#ifndef UNITOPIA_MUDLIB   
   if( !__MASTER_OBJECT__->valid_write(abs_fname, geteuid(), "write", owner) )
#else
   if( !MAY_WRITE(abs_fname, owner))
#endif
   {
      msg("Kein Schreibrecht auf Datei.");
      return 0;
   }

   if( options["backup"] )
   {
      rm(abs_fname+"~");
      catch( rename(abs_fname,abs_fname+"~") );
   }
   else
      rm(abs_fname);

   res=0;
   catch( res=editor_write_file(abs_fname,file) );
   if( res )
   {
      txt="Gespeichert: '"+abs_fname+"'"+" ("+strlen(file)+" Bytes)";
      
      if( owner_wants_quit )
      {
         quit_editor(txt,0);
         return 1;
      }
      else
         msg(txt);

      if( !extra[2] && options["mode"] != EDITOR_MODE_BUFFER )
      {       
         options["filename"]=abs_fname;
         filename=fname;
      }
   }
   else
      msg("Konnte nicht speichern: '"+abs_fname+"'");

   out(Head()+Cursor());
}

private varargs int editor_save_2(string fname, mixed save_block)
{
   string abs_fname;
   int res;
   
   abs_fname=owner_add_path(fname);
   fname=owner_convert_filename(fname);

   if( catch(res=file_size(abs_fname)) )
   {
      msg("Illegaler Filename: '"+abs_fname+"'");
      return 0;
   }

   if( res > 0 )
      ask("Datei existiert schon. Soll sie ueberschrieben werden",
         #'editor_save_3,({abs_fname,fname,save_block}));
   else
      return editor_save_3(ANSWER_YES,({abs_fname,fname,save_block}));

   return owner_wants_quit;
}

private void editor_save()
{
   qst("Speichern - Dateiname",options["filename"],#'editor_save_2);
}

private int editor_load_3(int res, mixed extra)
{
   if( res != ANSWER_YES )
   {
      msg("Aktueller Text nicht ueberschrieben.");
      return 0;
   }

   buffer=extra[1];
   delta_x=delta_y=0;
   cur_x=cur_y=1;
   if( options["mode"] != EDITOR_MODE_BUFFER )
   {
      options["filename"]=extra[0];
      filename=extra[2];
   }

   out(Screen());
   msg("Datei geladen: '"+extra[0]+"' ("+strlen(implode(buffer,"\n"))+
      " Bytes)");
}

varargs private int editor_load_2(string fname)
{
   string *_buffer;
   string abs_fname;

   if( !fname || fname == "" )
   {
      file_browser(#'editor_load_2,0);
      return 0;
   }
   
   abs_fname=fname;
   fname=owner_convert_filename(fname);
   if( !_buffer=load_buffer(&abs_fname) )
      return 0;

   if( sizeof(buffer-({""})) )
      ask("Soll der aktuelle Text wirklich ueberschrieben werden",
         #'editor_load_3,({abs_fname,_buffer,fname}));
   else
      editor_load_3(ANSWER_YES,({abs_fname,_buffer,fname}));
}

private void editor_load()
{
   qst("Laden - Dateiname (Ret.=Browser)","",#'editor_load_2);
}

private int editor_merge_2(string str, int template)
{
   int buffer_y;
   string *_buffer;
   string _str, tmp;

   if( !str || str == "" )
   {
      file_browser(#'editor_merge_2,
         template, template ? "template_dir" : 0);
      return 0;
   }
   
   _str=str;
   if( !_buffer=load_buffer(&str,template) )
      return 0;

   if( template )
   {
      options["template"]=_str;
      tmp=implode(_buffer,"\n");
      tmp=regreplace(tmp,"\\$\\$NAME",owner_query_cap_name(),1);
      tmp=regreplace(tmp,"\\$\\$DATE",explode(shorttimestr(time())," ")[0],1);
      tmp=regreplace(tmp,"\\$\\$FILE",options["filename"],1);
      _buffer=explode(tmp,"\n");
   }

   buffer_y=delta_y+cur_y-1;

   while( sizeof(buffer) <= buffer_y )
      buffer+=({ "" });
         
   buffer = 
      buffer[0..buffer_y-1] + 
      (_buffer[<1] == "" 
         ? _buffer[0..<2]
         : _buffer) +
      buffer[buffer_y..];

   delta_x=0;
   cur_x=1;

   out(Screen());
   msg("Dateiinhalt eingefuegt von: '"+str+"' ("+
      strlen(implode(_buffer,"\n"))+" Bytes)");
}

private void editor_merge()
{
   qst("Einfuegen - Dateiname (Ret.=Browser)","",#'editor_merge_2);
}

private void editor_template()
{
   qst("Schablone Einfuegen - Dateiname (Ret.=Browser)","",#'editor_merge_2,1);
}

private void editor_mark_begin()
{
   block_begin=delta_y+cur_y-1;
   out(Screen()+Cursor());
}

private void editor_mark_end()
{
   block_end=delta_y+cur_y-1;
   out(Screen()+Cursor());
}

private void editor_block_delete()
{
   int y0, y1;
   int siz;

   if( block_begin > block_end )
      return;

   siz=sizeof(buffer);
   if( (y0=block_begin-1) >= siz )
      y0=siz-1;
   if( (y1=block_end+1) >= siz )
      y1=siz-1;
   buffer=buffer[0..y0]+buffer[y1..];
   block_begin=1;
   block_end=0;
   cursor_goto_line_2(to_string((y0+1)||1));
}

private void editor_block_handling(int mode)
{
   int i, buffer_y, y0, y1;
   int siz;

   if( block_begin > block_end )
      return;
   buffer_y=delta_y+cur_y-1;
   if( mode == 0 || mode == 1 ) // copy oder move
   {
      if( buffer_y >= block_begin && buffer_y <= block_end )
         return;
      buffer_y=delta_y+cur_y-1;
      while( sizeof(buffer) <= buffer_y )
         buffer+=({ "" });
   }

   siz=sizeof(buffer);
   if( (y0=block_begin) > siz )
      y0=siz;
   if( (y1=block_end) > siz )
      y1=siz;

   switch( mode )
   {
      case 1:  // move block
         if( buffer_y < block_begin )
            buffer=buffer[0..buffer_y-1]+buffer[y0..y1]+
               buffer[buffer_y..y0-1]+buffer[y1+1..];
         else
         {
            buffer=buffer[0..y0-1]+buffer[y1+1..buffer_y-1]+buffer[y0..y1]+
               buffer[buffer_y..];
            buffer_y-=(y1-y0)+1;
            block_begin=buffer_y;
            block_end=buffer_y+(y1-y0);
            cursor_goto_line_2(to_string((buffer_y+1)||1));
         }
         break;
      case 2:  // shift left
         for(i=block_begin;i<=block_end;++i)
            buffer[i]=buffer[i][1..];
         break;
      case 3:  // shift right
         for(i=block_begin;i<=block_end;++i)
            buffer[i]=" "+buffer[i];
         break;
      default: // copy block
         buffer=buffer[0..buffer_y-1]+buffer[y0..y1]+buffer[buffer_y..];
   }

   if( mode == 0 || mode == 1 ) // copy oder move
   {
      block_begin=buffer_y;
      block_end=buffer_y+(y1-y0);
   }
   out(Screen()+Cursor());
}

private void editor_block_copy()
{
   editor_block_handling(0);
}

private void editor_block_move()
{
   editor_block_handling(1);
}

private void editor_block_left()
{
   editor_block_handling(2);
}

private void editor_block_right()
{
   editor_block_handling(3);
}

private void editor_block_unmark()
{
   block_begin=0;
   block_end=-1;
   out(Screen()+Cursor());
}

private void editor_block_save()
{
   if( block_begin >= block_end )
      msg("Keinen Block markiert.");
   else
      qst("Block Speichern - Dateiname","",#'editor_save_2,1);
}

private int editor_end_3(int res)
{
   quit_editor(0,res == ANSWER_NO);
   return 1;
}

private int editor_end_2(int res)
{
   if( res == ANSWER_NO )
   {
      quit_editor(0,0);
      return 1;
   }
   else
   {
      owner_wants_quit=1;
      qst("Speichern - Dateiname",options["filename"],#'editor_save_2);
   }
}

private void editor_end(int with_save)
{
   if( options["mode"] == EDITOR_MODE_BUFFER )
      ask("Soll der Text abgeschickt werden",#'editor_end_3);
   else
   if( with_save )
      ask("Editor verlassen - aktuellen Text abspeichern",#'editor_end_2);
   else
      quit_editor(0,0);
}

varargs void editor_help(string flag)
{
   if( !flag )
   {
      string page;
   
      page =
         "@CURSOR~             @LOESCHEN~            @BLOCK~            @DATEI~\n"
         "^A  Erste Spalte   ^Y  Zeile loeschen  ^KB Beginn       ^DS Speichern\n"
         "^E  Letzte Spalte                      ^KE Ende         ^DL Laden\n"
         "^U  Seite zurueck  @HILFE~               ^KD Loeschen     ^DE Einfuegen\n"
         "^V  Seite vor      ^O  Diese Seite     ^KC Kopieren     ^DT Schablone\n"
         "^KU Erste Zeile    ^R  'Refresh'       ^KM Bewegen\n"+
         "^KV Letzte Zeile                       ^KL nach Links   @SUCHEN~\n"+
         "^G  Gehezu Zeile   @VERLASSEN~           ^KR nach Rechts  ^F  Suchen (quick ^X)\n"+
         "^Q  Wort zurueck   ^C  Verlassen       ^KJ Mark. loes.  ^N  Weitersuchen\n"+
         "^W  Wort vor       2 mal ESC: Abbruch  ^KW Speichern    ^B  Backward\n\n"+
         "Anmerkung: ^KB steht z.B. fuer die Tastenkombination: <ctrl-k>, <ctrl-b>\n";

      page=regreplace(page,"@",S_underline,1);
      page=regreplace(page,"~",S_norm,1);
      out(
         S_pos(1,options["split_y"])+
         (options["split"] ? S_clr_eos : S_clr_scr)+
         Head()+
         S_pos(1,options["split_y"]+2)+
         page+
         S_revers+
         sprintf("%:-*s",options["cur_max_x"]-1,
            "xEd Version "+EDITOR_VERSION+" - Bitte eine Taste druecken...")+
         S_norm);
      efun::input_to("editor_help", EDITOR_INPUT_TO_FLAGS, 1);
   }
   else
   {
      out(Screen()+Line()+Cursor());
      efun::input_to("loop", EDITOR_INPUT_TO_FLAGS);
   }
}

private void editor_refresh()
{
   out(S_reset+S_clr_scr+Screen()+Line()+Cursor());
}

private int editor_fn_2b(int res)
{
   if( res != ANSWER_YES )
   {
      msg("Suchvorgang abgebrochen.");
      return 0;
   }
   cursor_end(1);
   cursor_down(1);
   editor_find_next(1);
}

private int editor_fn_2(int res)
{
   if( res != ANSWER_YES )
   {
      msg("Suchvorgang abgebrochen.");
      return 0;
   }
   cursor_home(1);
   editor_find_next(0);
}

private void editor_replace_it(int res, mixed extra)
{
   int buffer_y;

   buffer_y=delta_y+cur_y-1;

   if( res == ANSWER_YES )
      buffer[buffer_y] =
         buffer[buffer_y][0..options["replace_expr_begin"]-1]+
         options["replace_expr"]+
         buffer[buffer_y][options["replace_expr_end"]+1..];

   cur_x += strlen(options["replace_expr"]) -
      (options["replace_expr_end"]-options["replace_expr_begin"]);

   out(Line());
   editor_find_next(0);
}

private void editor_find_next(int backward)
{
   int suc, pos;
   int siz, buffer_y, buffer_x;
   string expr;
   mixed tmp;
   
   buffer_y=delta_y+cur_y-1;
   buffer_x=delta_x+cur_x-1;
   siz=sizeof(buffer);
   expr=options["find_expr"]||"";
   pos=-1;

#undef SEARCHING_PER_REG_EXP
#ifdef SEARCHING_PER_REG_EXP
   if( buffer_y < siz &&
      !(suc=sizeof(regexp(({buffer[buffer_y][buffer_x..]}),expr))) )
   {
      buffer_x=0;
      while( !suc && ++buffer_y < siz )
         suc=sizeof(regexp(({buffer[buffer_y]}),expr));
   }
#else
   if( backward )
   {
      if( buffer_y >= siz )
      {
         buffer_y = siz-1;
	 buffer_x = strlen(buffer[<1]);
      }
      
      if( buffer_y >= 0 &&
         (pos=strstr(buffer[buffer_y][0..buffer_x-1],expr)) < 0 )
      {
         buffer_x=0;
         delta_x=0;
         while( pos < 0 && --buffer_y >= 0 )
            pos=strstr(buffer[buffer_y],expr);
      }
   }
   else
   {
      if( buffer_y < siz &&
         (pos=strstr(buffer[buffer_y][buffer_x..],expr)) < 0 )
      {
         buffer_x=0;
         delta_x=0;
         while( pos < 0 && ++buffer_y < siz )
            pos=strstr(buffer[buffer_y],expr);
      }
   }
   suc=pos >= 0;
#endif

   if( !suc )
   {
      if( backward )
         ask("Suchbegriff nicht gefunden - Am Ende weitersuchen",#'editor_fn_2b);
      else
         ask("Suchbegriff nicht gefunden - Am Anfang weitersuchen",#'editor_fn_2);
      return;
   }

#ifdef SEARCHING_PER_REG_EXP
   tmp=regexplode(buffer[buffer_y][buffer_x..],expr);
   siz=strlen(tmp[0])+1;
   if( sizeof(tmp) > 1 )
      siz+=strlen(tmp[1]);
   cur_x=buffer_x+siz;
#else
   if( backward )
   {
      cur_x=pos+1;
   }
   else
   {
      siz=pos+strlen(expr)+1;
      cur_x=buffer_x+siz;
   }
#endif
   if( cur_x > options["cur_max_x"] )
   {
      delta_x=cur_x-options["cur_max_x"];
      cur_x=options["cur_max_x"];
   }

   cursor_goto_line_2(to_string(buffer_y+1),cur_x,delta_x);

   if( options["replace_expr"] )
   {
      siz=strlen(expr);
      options["replace_expr_begin"]=delta_x+cur_x-siz-1;
      options["replace_expr_end"]=delta_x+cur_x-2;

      out(S_pos(1,options["split_y"]+cur_y+1)+
         buffer[buffer_y][delta_x..delta_x+cur_x-siz-2]+ 
         S_underline+
         buffer[buffer_y][delta_x+cur_x-siz-1..delta_x+cur_x-2]+
         S_norm+
         buffer[buffer_y][delta_x+cur_x-1..delta_x+options["cur_max_x"]-2]+
         S_norm);

      ask("Ersetzen", #'editor_replace_it);
   }
}

private int editor_replace(string expr)
{
   if( !expr )
      msg("Kein Ersetzbegriff angegeben.");
   else
   {
      options["replace_expr"]=expr;
      editor_find_next(0);
   }
}

private int editor_find_3(string cmd)
{
   cmd=strip(lower_case(cmd||""));
   if( !strlen(cmd) || strstr(cmd, "v") == 0 )
      editor_find_next(0);
   else
   if( strstr(cmd, "r") == 0 )
      editor_find_next(1);
   else
   if( strstr(cmd, "e") == 0 )
   {
      qst("Ersetzen durch", options["replace_expr"]||"", #'editor_replace);
   }
   else
      msg("Suche abgebrochen (nur V, R und E sind gueltig)!");
}

private int editor_find_2(string expr)
{
   if( !expr )
      msg("Kein Suchbegriff angegeben.");
   else
   {
      options["find_expr"]=expr;
      qst("(V)orwaerts (R)ueckwaerts (E)rsetzen", "", #'editor_find_3);
   }
}

private void editor_find_quick(string expr)
{
   if( !expr )
      msg("Kein Suchbegriff angegeben.");
   else
   {
      options["find_expr"]=expr;
      editor_find_next(0);
   }
}

private void editor_find(int quick)
{
   options["replace_expr"]=0;

#ifdef SEARCHING_PER_REG_EXP
   qst("Suchen (Reg-Exp) (^C fuer Abbruch)",
#else
   qst("Suchen (^C fuer Abbruch)",
#endif
      options["find_expr"]||"",quick ? #'editor_find_quick : #'editor_find_2);
}


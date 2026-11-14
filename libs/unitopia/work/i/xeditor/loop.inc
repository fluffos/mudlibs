// This file ist part of Avalon Mudlib.
// Copyright 1996-99 by Avatar@Avalon. All rights reserved.
// ----------------------------------------------------------------
// File:        /i/xeditor/loop.inc
// Description: Die Hauptschleife
// Author:      Avatar
// Modified:
//
// $Log: loop.inc,v $
// Revision 1.4  2009-03-20 08:05:04  gnomi
// Man kann die Hoehe und Breite nun auf Automatik stellen.
//
// Revision 1.3  2005/10/12 22:07:36  gnomi
// Workaround fuer Windows-Telnet (sendet \r\n als Zeilenumbruch).
//
// Revision 1.2  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//


#define NOT_QST_MODE         if( qst_map ) break
#define NOT_FB_MODE          if( fb_map ) break
#define NOT_QST_AND_FB_MODE  if( qst_map || fb_map ) break

#define CHECK_FILE_OPERATION if( !owner_is_wizard() ) \
   { \
      msg("Das darfst Du nicht."); \
      break; \
   }

string ignore_chars;

void loop(string str)
{
   int i, c, no_loop;
   mixed tmp;

   if (str == "")
       str = "!";

   c=str[0];
   
   if( tmp=possible_keys[c] )
   {
      if( mappingp(tmp) )
      {
         possible_keys=tmp;
         key_buffer+=str;
      }
      else
      {
         if( msg_printed )
            erase_msg();

         if( qst_map && c == 3 && !strlen(key_buffer) )
         {
            qst_esc();
            return;
         }


         switch( tmp )
         {
            case KEY_LEFT:
               NOT_FB_MODE;
               cursor_left();
               break;
            case KEY_RIGHT:
               NOT_FB_MODE;
               cursor_right();
               break;
            case KEY_UP:
               NOT_QST_MODE;
               cursor_up(1);
               break;
            case KEY_DOWN:
               NOT_QST_MODE;
               cursor_down(1);
               break;
            case KEY_SCR_UP:
               NOT_QST_MODE;
               cursor_up(options["cur_max_y"]/2);
               break;
            case KEY_SCR_DOWN:
               NOT_QST_MODE;
               cursor_down(options["cur_max_y"]/2);
               break;
            case KEY_FIRSTLINE:
               NOT_QST_MODE;
               cursor_home(1);
               break;
            case KEY_LASTLINE:
               NOT_QST_MODE;
               cursor_end(1);
               break;
            case KEY_BACKSPACE:
               NOT_FB_MODE;
               cursor_delete(1);
               break;
            case KEY_DELETE:
               NOT_FB_MODE;
               cursor_delete(0);
               break;
            case KEY_INSERT:
               NOT_FB_MODE;
               switch_insert_mode();
               break;
            case KEY_HOME:
               cursor_home();
               break;
            case KEY_END:
               cursor_end();
               break;

            case KEY_DELETE_LINE:
               NOT_QST_AND_FB_MODE;
               cursor_delete_line();
               break;
            case KEY_GOTO_LINE:
               NOT_QST_MODE;
               cursor_goto_line();
               break;
            case KEY_NEXT_WORD:
               NOT_QST_AND_FB_MODE;
               cursor_right(1);
               break;
            case KEY_LAST_WORD:
               NOT_QST_AND_FB_MODE;
               cursor_left(1);
               break;
            case KEY_END_EDITOR:
               NOT_QST_MODE;
               if( fb_map )
               {
                  file_browser_quit(1);
                  if( filename == "" )
                     return;
               }
               else
                  editor_end(1);
               no_loop=1;
               break;
            case KEY_SAVE:
               NOT_QST_AND_FB_MODE;
               CHECK_FILE_OPERATION;
               editor_save();
               break;
            case KEY_LOAD:
               NOT_QST_AND_FB_MODE;
               CHECK_FILE_OPERATION;
               editor_load();
               break;
            case KEY_MERGE:
               NOT_QST_AND_FB_MODE;
               CHECK_FILE_OPERATION;
               editor_merge();
               break;
            case KEY_M_TEMPLATE:
               NOT_QST_AND_FB_MODE;
               CHECK_FILE_OPERATION;
               editor_template();
               break;
               
            case KEY_BLOCK_BEGIN:
               NOT_QST_AND_FB_MODE;
               editor_mark_begin();
               break;
            case KEY_BLOCK_END:
               NOT_QST_AND_FB_MODE;
               editor_mark_end();
               break;
            case KEY_BLOCK_DELETE:
               NOT_QST_AND_FB_MODE;
               editor_block_delete();
               break;
            case KEY_BLOCK_COPY:
               NOT_QST_AND_FB_MODE;
               editor_block_copy();
               break;
            case KEY_BLOCK_MOVE:
               NOT_QST_AND_FB_MODE;
               editor_block_move();
               break;
            case KEY_BLOCK_LEFT:
               NOT_QST_AND_FB_MODE;
               editor_block_left();
               break;
            case KEY_BLOCK_RIGHT:
               NOT_QST_AND_FB_MODE;
               editor_block_right();
               break;
            case KEY_BLOCK_UNMARK:
               editor_block_unmark();
               break;
            case KEY_BLOCK_SAVE:
               NOT_QST_AND_FB_MODE;
               CHECK_FILE_OPERATION;
               editor_block_save();
               break;
               
            case KEY_HELP:
               NOT_QST_MODE;
               editor_help();
               break;
            case KEY_REFRESH:
               editor_refresh();
               break;
            
            case KEY_FIND:
               NOT_QST_MODE;
               editor_find(0);
               break;
            case KEY_FIND_QUICK:
               NOT_QST_MODE;
               editor_find(1);
               break;
            case KEY_FIND_NEXT:
               NOT_QST_MODE;
               options["replace_expr"]=0; // Avatar: ohne faende ich es
                                          //         praktischer
               editor_find_next(0);
               break;
            case KEY_FIND_LAST:
               NOT_QST_MODE;
               options["replace_expr"]=0; // Avatar: ohne faende ich es
                                          //         praktischer
               editor_find_next(1);
               break;
         }
         
         clear_key_buffer();

         if( no_loop )
            return;
      }
   }
   else if(ignore_chars && member(ignore_chars, str[0])>=0)
   {
      ignore_chars = 0;
   }
   else
   {
      if( msg_printed )
         erase_msg();

      if( str == "\r" || str == "\n" )
      {
         /* Nach einem \r ein \n oder \0 ignorieren und
	    nach einem \n ein \r oder \0 ignorieren.
	    Ein Zeilenumbruch genuegt
	 */
         ignore_chars = (str=="\r")?"\n\0":"\r\0";
	 
         if( qst_map )
         {
            if( qst_ok() )
               return;
         }
         else
         if( fb_map )
            file_browser_selection();
         else
            cursor_return();
      }
      else
      if( str[0] == 27 && 
          strlen(key_buffer) && key_buffer[0] == 27 )
      {
         if( qst_map )
            qst_esc();
         else
         if( fb_map )
         {
            file_browser_quit(1);
            if( filename == "" )
               return;
         }
         else
         {
            quit_editor(0,1);
            return;
         }
      }
      else
      if( str == "\t" )
      {
         if( fb_map )
            file_browser_selection();
         else
            cursor_tab();
      }
      else
      {
         if( !fb_map )
            add_str(key_buffer+str);
         clear_key_buffer();
      }
   }

   efun::input_to("loop", EDITOR_INPUT_TO_FLAGS);
}


// This file is part of Avalon Mudlib
// ----------------------------------------------------------------
// File:        /i/wizard_shell/shell.inc
// Author:      Avatar (11/96)
// Description: Key-Handling
//
//
// $Log: shell.inc,v $
// Revision 1.2  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

private static string act_command;

void init_command_shell()
{
   act_command="";
}

private void tab_completion(string str)
{
   string *frag, path, abs_path, *dir;

#define BEEP_EXIT { printf("%c",7); return; }

   if( !strlen(str) )
      BEEP_EXIT;
   frag=explode(str," ");
   if( !strlen(path=frag[<1]) )
      BEEP_EXIT;
   path=add_path(path);
   dir = frag[<1][<1..<1] == "/"
      ? get_dir(path+"/.")
      : get_dir(path+"*");
   if( !sizeof(dir) )
      BEEP_EXIT;
   if( sizeof(dir) == 1 )
   {
      path=implode(explode(path,"/")[0..<2],"/")+"/"+dir[0];
      if( file_size(path) == -2 )
         path += "/";
      str=implode(frag[0..<2]," ")+" "+path;
   }
   else
      printf("%c\n%-79#s\n",7,implode(dir,"\n"));
}

void get_command(string str)
{
   string tmp;

   if( !strlen(str) )
      return;
   switch( str[0] )
   {
      case 8:
      case 127:
         if( !strlen(act_command) )
            printf("%c",7);
         else
         {
            act_command=act_command[0..<2];
            printf("%c[D %c[D",27,27);
         }
         break;

      case 10:
      case 13:
         write("\n");
	 efun::command(act_command);
         return;

      case 3:  // '^C'
      case 27: // ESC
         write("\n");
         return;

      case 18: // '^R'
         write("\n"+files::query_current_path()+act_command);
         break;

      case '\t':
         tab_completion(&act_command);
         printf("%c%s%s",13,files::query_current_path(),act_command);
         break;

      default:
         act_command+=str;
         write(str);
   }
   input_to("get_command",3);
}


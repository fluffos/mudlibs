#include <const.h>

int draw_page( string file, int line_start, int num_lines ) {
   string out;

   out = cleanup_string(read_file( file, line_start, num_lines ));
   if( !out ) return 0;
   write( out );
   return 1;
}

int main(string param) {
   string file_name;

   if( this_player()->query_level() < WIZLEVEL ) {
      notify_fail("==> [Error] Access denied\n");
      return 0;
   }

   if( !param ) {
      notify_fail("==> [Format] more filename\n");
      return 0;
   }

   file_name = this_player()->make_path_absolute( param );
   if( !file_exists(file_name) ) {
      notify_fail("==> [Error] Can't view "+file_name+": It seems the file doesn't exist.\n");
      return 0;
   }
   if( !query_read_access(file_name, this_player()) ) {
      notify_fail("==> [Error] Can't view "+file_name+": Your access level isn't high enough.\n");
      return 0;
   }
   this_player()->remove_env_var("_curr_more_file");
   this_player()->set_env_var("_curr_more_file", ({ file_name, 1 }) );
   draw_page( file_name, 1, this_player()->query_term_height() - 2 );
   add_interface("view_file", "[Viewing file "+file_name+" | ? for help] ~PROM");
   return 1;
}

void view_file(string c) {
   string file_name;
   mixed *var;
   int line;

   var = this_player()->query_env_var( "_curr_more_file" );
//   write(""+pointerp(var)+"\n");

   if( !pointerp(var) ) {
      msg("==> [Error] Lost your information for viewing this file.");
      drop_interface();
      return;
   }
   file_name = var[0];
   line = var[1];

   if( c == " " || c == "l" ) {
      if( this_player()->query_ansi() ) msg_bare("~Y-01~X-99~CEOL");
      else msg_bare("\n");
      line++;
      if( !draw_page(file_name, line + this_player()->query_term_height() - 2, 1) ) {
         this_player()->remove_env_var("_curr_more_file");
         drop_interface();
         return;
      }
   }
   if( c == "" || c == "d" ) {
      if( this_player()->query_ansi() ) msg_bare("~Y-01~X-99~CEOL");
      else msg_bare("\n");
      line += this_player()->query_term_height() - 2;
      if( !draw_page(file_name, line, this_player()->query_term_height() - 2) ) {
         this_player()->remove_env_var("_curr_more_file");
         drop_interface();
         return;
      }
   }
   if( c == "u" ) {
      if( this_player()->query_ansi() ) msg_bare("~Y-01~X-99~CEOL");
      else msg_bare("\n");
      msg_bare("-- BREAK --" + tab("-", this_player()->query_term_width() - 13) + "\n");
      line -= this_player()->query_term_height() - 2;
      if( line < 1 ) line = 1;
      if( !draw_page(file_name, line, this_player()->query_term_height() - 2) ) {
         this_player()->remove_env_var("_curr_more_file");
         drop_interface();
         return;
      }
   }
   if( c == "?" ) {
      msg_bare("\nHelp for listing tool\n=====================\n[Space] or [l] - Next line\n[Enter] or [d] - Next page\n[?] - This help\n[q] - Exit tool\n"+
               "[u] - Back up one page\n");
   }
   if( c == "q" ) {
      if( this_player()->query_ansi() ) msg_bare("~Y-01~X-99~CEOL");
      else msg_bare("\n");
      this_player()->remove_env_var("_curr_more_file");
      drop_interface();
      return;
   }
   this_player()->set_env_var("_curr_more_file", ({ file_name, line }) );
}
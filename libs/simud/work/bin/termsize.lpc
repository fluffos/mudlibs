#include <textdraw.h>

main(string str) {
   object ob;

   if( str == "manual" || str == "set" ) {
      add_interface( "enter_width", "[Enter your terminal's width in columns] ");
      return 1;
   }

   if( str == "guide" ) {
      int i;
      string s;
      msg("Use the guide below to figure out your terminal width.");
      s="~[070";
      for( i = 1; i < 200; i++ ) {
         if( i % 10 == 0 )
            if( i < 100 ) s += "~[150" + i / 10 + "~[070";
            else s += "~[140" + (i-100) / 10 + "~[070";
         else s += i%10;
      }
      msg_bare(s+"\n");
      return 1;
   }

   if( str == "vguide" ) {
      int i;
      string s;
      s = "";
      for( i = 60; i > 1; i-- )
      if( i % 10 == 0 )
         s += "~CLAB" + i + "\n~CBRT";
      else
         s += "" + i + "\n";
      msg_bare( s + "1 ~CDEF(Vertical size guide for your terminal) " );
      return 1;
   }

   if( str ) {
      notify_fail("termsize [set/guide/vguide]\nType 'help termsize' for more information.\n");
      return 0;
   }

   msg("Your current terminal size is "+this_player()->query_term_width()+" columns by "+this_player()->query_term_height()+" rows.");
   return 1;
}

enter_width(string str) {
   int x;

   if( sscanf(str, "%d", x ) != 1 ) {
      msg_bare("That is not a valid width, cancelling.\n");
      drop_interface();
   }
   else {
      shift_interface("enter_height", "[Enter your terminal's height in rows] ");
      this_player()->set_term_width(x);
   }
}

enter_height( string str ) {
   int x;

   if( sscanf(str, "%d", x ) != 1 ) {
      msg_bare("That is not a valid height, cancelling.\n");
      drop_interface();
   }
   else {
      drop_interface();
      this_player()->set_term_height(x);
      msg_bare("Your terminal size is now "+this_player()->query_term_width()+"x"+
         this_player()->query_term_height()+"\n");
   }
}
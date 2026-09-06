/** This base object is used by simul_efun to interpret ANSI codes.
 * As a rule, you should not need to call functions in this object.
 */

/// A string of length one containing the ESCAPE character (ASCII #27)
string ESCAPE;

/** The so-called "designer codes" are modifiable codes, so far used
 * only for color but actually translatable to any code recognized
 * by this object. One restriction is that they cannot translate into
 * a *sequence* of codes; they must be exactly one code long.
 * They are not suitable for new functionality. A running list of
 * existing designer codes should be kept in /help/wiz/colors.hlp
 *
 * Example: If I want to make ~CGRA mean "color 7 on color 0"
 * (gray on black) then I would set an entry in designer_codes
 * as designer_codes["CGRA"]="~[070"; This would then be translated
 * as I want.
 */

mapping designer_codes;

/** Sets a single "designer" code. This is basically a code
 * that aliases to another code. This is an important function
 * for setting things like time of day, etc.
 *
 * Note that designer codes may later be changed to be carried
 * on the player object, so that different players can have
 * different color schemes (for varying weather, etc.)
 *
 * \param code_name The alias code, i.e. ~CCOM
 * \param newcode The code to which it will alias, i.e. ~[100
 */

void set_code( string code_name, string newcode ) {
   if( !stringp(code_name) || !stringp(newcode) ) return;
   if( !member( designer_codes, code_name ) || strlen(newcode) != 4 ) return;
   designer_codes[code_name] = newcode;
}

/// Allows you to query the code associated with a designer code.
string query_code( string code_name ) {
   return designer_codes[code_name];
}

/// Initializes the ESCAPE string and the standard designer codes.
create()
{
   ESCAPE = " ";
   ESCAPE[0] = 0x1B;
   designer_codes = ([ "CDEF":"[070", "CREF":"[100", "CHLP":"[060",
                       "CCOM":"[140", "CBRT":"[150", "CEMO":"[100",
                       "CLAB":"[140", "CACT":"[100", "CTIT":"[110",
                       "CDRK":"[080", "CSC1":"[040", "CSC2":"[120",
                       "CSC3":"[060", "CSC4":"[140", "CSC5":"[150",
                       "CMA1":"[060", "CMA2":"[100", "CMA3":"[070",
                       "CMA4":"[110", "CMA5":"[140", "CWRN":"[090" ]);
}

/** The most important function in this file; this takes a tilde code
 * in and returns an ANSI escape sequence that will perform the
 * desired action on an ANSI compliant terminal.
 *
 * \param codename The tilde code, with the tilde already stripped off.
 * \param dest The object which will be receiving the code. Most of the
 * codes will only be returned properly if dest->query_ansi() is 1.
 * \return An ANSI escape sequence; "" on invalid codes.
 */
string get_code(string codename, object dest) {
   int fg, bg;
   string ansicode;

   if(!dest) dest = this_player();
   if(!dest) return codename;

   ansicode = "";
   if(strlen(codename) != 4) return "[AnsErrLen]";

   if( member(designer_codes, codename) ) codename = designer_codes[codename];

   if(codename == "BACK") {
      if(dest->query_ansi()) return "\27[1D";
      else return "\b";
   }

   if(codename == "NEWL") {
      return "\n";
   }

   if(codename == "SPAC") return " ";
   if(codename == "TILD") return "~";
   if(codename == "LPAR") return "(";
   if(codename == "LINK") return "";
   if(codename == "PROM")
      if( dest->query_ansi() ) return "( )\27[1D\27[1D";
      else return "( )\b\b";

   /* Change color */
   if(codename[0] == '[') {
      fg = 10*(codename[1]-'0') + codename[2]-'0';
      bg = codename[3] - '0';
      if(fg < 0 || fg > 15 || bg < 0 || bg > 7)
         return "~"+codename;

      if(!dest->query_ansi()) return "";
      if(fg > 7) {
         ansicode = "1;";
         fg -= 8;
      } else ansicode = "0;";
      ansicode = ansicode + (fg + 30) + ";";
      ansicode = ansicode + (bg + 40);
      return "\27[" + ansicode + "m";
   } else

   /* Cursor position */
   if(codename[0] >= '0' && codename[0] <= '9') {
      int i1, i2;
      codename=codename[0..1]+" "+codename[2..3];
      if(sscanf(codename, "%d %d", i1, i2) == 2)
      return "\27[" + i1 + ";" + i2 + "H";
   } else

   /* Clear screen */
   if(codename == "CLRS") {
      if(!dest->query_ansi()) return tab("\n", dest->query_term_height());
      return "\27[2J";
   }

   /* Change line of cursor */
   if(codename[0] == 'Y') {
      if(codename[1] == '+')
         return "\27[" + codename[2..3] + "B";
      if(codename[1] == '-')
         return "\27[" + codename[2..3] + "A";
   } else

   /* Change column of cursor */
   if(codename[0] == 'X') {
      if(codename[1] == '+')
         return "\27[" + codename[2..3] + "C";
      if(codename[1] == '-')
         return "\27[" + codename[2..3] + "D";
   } else

   /* Save cursor position */
   if(codename == "SAVE") return "\27[s"; else

   /* Recall cursor position */
   if(codename == "RECL") return "\27[u"; else

   if(codename == "CEOL") return "\27[K";

   return "~"+codename;
}

string get_code_noansi() {
  return "";
}

/** A simple function useful for testing if a terminal is ANSI compliant.
 * \warn This function uses input_to (a privileged efun on this lib) and will
 * conflict with interfaces.
 */
ansitest() {
   int x, y;

   write( "\27[2J" + "\27[1;1H");
   write("==> [AnsiTest] Color test -- You should see a colorful grid.\n");
   for(y=40;y<48;y++) {
      for(x=30;x<38;x++)
         write("\27[0;"+y+";"+x+"m*"+"\27[1;"+x+"m*");
      write("\27[0m\n");
   }

   this_player()->set_curr_prompt("[AnsiTest | Colors | Push Enter] ~PROM");
   write(this_player()->query_prompt());
   input_to("ansitest2");
}

/// Part 2 of the ANSI testing function.
ansitest2() {
   int x, y;

   write("\27[2J"+"\27[1;1H");
   write("==> [AnsiTest] Positioning -- You should see two boxes below, centered.\n");
   write("==> [AnsiTest] Memory -- The prompt should be *above* the boxes.\n");

   write("\27[s");
   write("\27[0;41m");
   for(x=20; x < 35; x+=2) {
      write("\27[6;"+x+"H  ");
      write("\27[12;"+x+"f  ");
   }

   for(y=6; y < 13; y ++) {
      write("\27["+y+";20H  ");
      write("\27["+y+";34H  ");
      write("\27["+y+";45f  ");
      write("\27["+y+";59f  ");
   }

   for(x=45; x < 60; x+=2) {
      write("\27[6;"+x+"H  ");
      write("\27[12;"+x+"f  ");
   }
   write("\27[0m");
   write("\27[u");
   this_player()->set_curr_prompt("[AnsiTest | Cursor | Push Enter] ~PROM");
   this_player()->write_prompt();
   input_to("ansitest3");
}

/// Part 3 of the ANSI testing function.
ansitest3() {
   int y;

   for(y=0;y<25;y++) write("\27["+y+";0f"+"\27[K");
   write("==> [AnsiTest] Test completed. Now returning to the MUD.\n");
   this_player()->set_curr_prompt();
}

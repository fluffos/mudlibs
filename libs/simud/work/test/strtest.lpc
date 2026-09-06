void func() {
   int i, j, istrstr, cases;

   string mystr;

   write("Testing...\n");
   for( cases = 3; cases < 50; cases++ ) {
      mystr = "";
      for( i = 0; i < cases; i++ )
         mystr += " X ";
      for( i = 0; i < cases; i++ ) {
         for( j = i; j < cases; j++ )
             if( mystr[i..i+cases-1][j] == 'X' ) break;
         if( j == cases ) j = -1;
         if( (istrstr = strstr(mystr[i..i+cases-1], "X", i)) != j ) {
            write("Fails with cases="+cases+": ");
            write("mystr='"+mystr+"'\n, i="+i+", strstr(mystr["+i+".."+(i+cases-1)+"], \"X\", "+i+")="+istrstr+", j="+j+"\n");
         }
      }
   }
   write("Test done.\n");
}
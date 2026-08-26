/* cat command, trial out by Turrican for a commands daemon. */

inherit COMMAND_BASE;

mixed cmd(string str, int LINE_NUMBERS) {
   string *filenames, *lines;
   int loop, i, w;

   if( !str )  {
      notify_fail("Cat what file ?\n");
      return 0;
   }
   
   filenames = this_player()->get_files(str);
   if (!sizeof(filenames)) {
      notify_fail(str + ": No such file.\n");
      return 0;
   }
   for(loop = 0; loop < sizeof(filenames); loop++) {
      if(sizeof(filenames) > 1) {
         write("FILE : " + filenames[loop] + "\n");
      }

      if(LINE_NUMBERS) {
         str = read_file( filenames[loop] );
         if (str)  {
            lines = explode( str , "\n" );
            w = sizeof( sprintf( "%d", sizeof( lines ) ) );
            
            for( i = 0; i < sizeof( lines ); i++ )
               lines[i] = sprintf( "%*d: %s", w, (i+1), lines[i] );
            printf("%s\n", implode(lines, "\n"));
         }
         else write(filenames[loop] + ": No such file.\n");
      }

      else cat(filenames[loop]);
   }
   return 1;
}

mixed *query_patterns()  {
   return ({ "-n <string'file'>", (: cmd($4[0], 1) :),
              "<string'file'>", (: cmd($4[0], 0) :) });
}

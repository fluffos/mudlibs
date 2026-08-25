#include <standard.h>
#include <cmd.h>
#include <runtime_config.h>
inherit CMD_BASE;

void setup(){

    position = 1;
}



protected int cmd(mixed words, object me) {
    int i, j,k, size;
    string line, found, output, pattern, *files, *lines, *match;

    seteuid( geteuid( this_player() ) );
    if ( !words || ( words == "" ) )
        return notify_fail( "Syntax: grep <pattern> <files>\n" );
    if ( sscanf( words, "%s %s", pattern, words ) != 2 )
        return notify_fail( "Syntax: grep <pattern> <files>\n" );
    files = me->get_files( words );
    if ( !sizeof( files )  )
        return notify_fail( "File(s) "+ words +" not found.\n" );
    output = "";
    for ( i = 0; i < sizeof( files ); i++ ) {
        found = "";
        if ((size = file_size( files[ i ] )) > 0) 
        {
/*
            if (size > get_config(__MAX_READ_FILE_SIZE__) ||
              size > get_config(__MAX_STRING_LENGTH__) ) 
*/
       if(size > 20000)
            {
                if(sizeof(files) == 1) // do insane on ONE file
                {
                    if (!read_bytes(files[0], 0, 1)) 
                    {
                        log_file("GREP_ERRORS", sprintf("File %s made grep barf.\n",
                            files[0]));
                        output += sprintf("File %s is not an ASCII file.\n", files[0]);
      break;
                    }
                    /* This is horribly slow. You really don't want this to happen
                    * since it freezes the mud as well. *sigh* */
                    k = 1;
                    while ((line = read_file(files[0],k+=500, 500)) != 0) 
                    {
                        lines = explode(line, "\n");
                        match = regexp(lines, pattern, 1);
                        size = sizeof(match);
                        for (j = 0; j < size; j+=2) {
                            found += sprintf("%5d: %s\n", k+match[j+1], match[j]);
                        }
                        if ( found != "" )
                            output += files[0] +"\n"+ found;
                    }
                }
                else
                {
                    output += sprintf("File %s is too big,try one file at a time.\n", files[i]);
                    continue;
                }
            }      
            else
            {
                if (!read_bytes(files[i], 0, 1)) 
                {
                    log_file("GREP_ERRORS", sprintf("File %s made grep barf.\n",
                        files[i]));
                    output += sprintf("File %s is not an ASCII file.\n", files[i]);
                    //continue;
                }
                lines = explode(read_file(files[i]), "\n");
                match = regexp(lines, pattern, 1);
                size = sizeof(match);
                for (j = 0; j < size; j+=2) 
                {
                    found += sprintf("%5d: %s\n", match[j+1], match[j]);
                }
                if ( found != "" )
                    output += files[ i ] +"\n"+ found;
            }  
        }
    }
    if ( output != "" )
        me->more_string( output, "Grep" );
    else
        printf( "Pattern not found.\n" );
    return 1;

    me->set_trivial_action();
    return 1;
} /* grep() */



// Notes: This grep command was originally written for "Wallowing MUD"
// (wallowing.whatever.net.au 2000) and therefore credit is due to
// Stormdragon for it. Thanks Jason.

// Modified for the SIMud mudlib by Acius.

#define OPT_NUMBER 0x01
#define OPT_LIST 0x02

int main(string str) {
  string pattern, *files, *lines, *matches, source, current, arg;
  int i, j, m, n, options, start;

  if (!str) {
    notify_fail( "==> [Format] grep [-ln] [\"]pattern[\"] file(s)\n" );
    return 0;
  }
  while( sscanf(str, "-%s %s", arg, str) == 2 ) {
    if( member(arg, 'l') != -1 )
      options |= OPT_LIST;
    if( member(arg, 'n') != -1 )
      options |= OPT_NUMBER;
  }
  if( sscanf(str, "\"%s\" %s", pattern, str) == 2 );
  else if( sscanf(str, "%s %s", pattern, str) == 2 );
  else {
    notify_fail( "==> [Format] grep [-ln] [\"]pattern[\"] file(s)\n" );
    return 0;
  }
  str = this_player()->make_path_absolute( str );
  // Dropped the query_read_access(), it can't do wildcards.
  if( !str ) {
    notify_fail( "No read access\n" );
    return 0;
  }
  files = get_dir( str );
  if( !files ) {
    notify_fail( "No files match \"" + str + "\".\n" );
    return 0;
  }
  source = str;

  for( i = strlen(str); str[i] != '/'; i-- );
  str = str[..i];

  if( (i = member(files, ".")) != -1 )
    files = array_delete( files, i );
  if( (i = member(files, "..")) != -1 )
    files = array_delete( files, i );

  if (!files || !sizeof(files)) {
    notify_fail("No files match \"" + source + "\".\n");
    return 0;
  }

  for( i = 0, n = sizeof(files); i < n; i++ ) {
     current = str + files[i];
     if( file_size(current) < 1 )
        continue;
     start = 1;
     while( (source = read_file(current, start, 640)) != 0 ) {
        lines = explode( source, "\n" );
        if( lines && sizeof(lines) ) {
           matches = regexp( lines, pattern );
           if( (m = sizeof(matches)) != 0 ) {
              if( options & OPT_LIST )
                 write( files[i] + "\n" );
              else {
                 if( options & OPT_NUMBER ) {
                    int k;
                    k = 0;
                    for( j = 0; k < sizeof(matches) && j < sizeof(lines); j++ )
                    if( matches[k] == lines[j] ) {
                       if( n != 1 )
                          arg = files[i] + " " + (start + j) + ":";
                       else
                          arg = (string) (start + j) + ":";
                       write( arg + matches[k] + "\n" );
                       k++;
                    }
                 }
                 else
                 for( j = 0; j < m; j++ ) {
                    if( n != 1 )
                       arg = files[i]+":";
                    else
                       arg = "";
                    write( arg + matches[j] + "\n" );
                 } // } Loop through all matches
              } // } If list-filename only option is on
           } // } If there were matches in those lines
        } // } If any lines were read
        start += 640;
     } // Loop through lines of this file
  } // Loop through files
  return 1;
}

string help() {
  write("Usage: grep [-ln] [\"]<pattern>[\"] <files>\n\n"+
  "Searches the files specifed for the pattern specified. Patterns are the\n"+
  "same as in ed. (man regexp for more info)\n"+
  "The -l option shows just a list of files that match.\n"+
  "The -n option gives line numbers of matches.\n");
}
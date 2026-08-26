
inherit COMMAND_BASE;

string help();

int cmd(string str)
{
  int     i;
  string  file, date;
  string *parts;
  string orig_file;
  object user = this_player();
  if (!str)
    return notify_fail( "Usage : backup <filename>\n" );

  if( file_size( str ) < 0 )
    str = user -> query_current_path() + "/" + str;

  if( file_size( str ) < 0 )
    return notify_fail( "Cannot find file to backup.\n" );

  orig_file = str;

  date = ctime( time() );
  i = member_array( date[ 4..6 ],
                      ({ "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                         "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" }) );
  i++;
  date = date[ 22..23 ] + i + date[ 8..9 ];
  if( strlen( date ) == 5 )
    date = date[ 0..1 ] + "0" + date[ 2..4 ];
  date = replace( date, " ", "0" );
  date = replace( date, " ", "0" );

  parts = explode(str, "/");
  parts = parts[0..<2] + ({"BACKUPS"}) + parts[<1..<1];
  switch(file_size(implode(parts[0..<2], "/")))
  {
    default:
      return notify_fail("File named BACKUPS exists.  please rename it.\n");
    case -1:
      if(!mkdir(implode(parts[0..<2], "/") ) )
        return notify_fail("Couldn't make BACKUPS dir.\n");
    case -2:
  }

  str = implode(parts, "/");

  if( file_size( str + "." + date ) != -1 )
  {
    i = 2;
    while( file_size( str + "." + date + "v" + i ) != -1 )
      i++;
    date += "v" + i;
  }
  file = read_file( orig_file );
  write_file( str + "." + date, file );
  if(file_size( str + "." + date ) == -1)
    return notify_fail( "Backup failed\n" );
  write("File backed up to " + str + "." + date + "\n" );
  return 1;
} /* cmd() */

string help() { return "Syntax: backup <file>\n"; }

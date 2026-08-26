#include <log.h>
#include <db.h>
#include <config.h>

/* Define this to use the old ERROR_REPORTS file system */
#undef OLD_SYSTEM

/* Define this to use the new SQL based errors system */
#define NEW_SYSTEM

int db_fd;

void create() {
    catch( db_fd = db_connect("localhost", CONFIG_DB_ERRORS, CONFIG_DB_USER ) );
} /* create() */

void smart_log(string full_type, string reporter, string text,
               string trace, string file) {
  int i;
  string type, temp1, *j, *person, dir;
#ifdef OLD_SYSTEM
  string temp2, report;
#endif
#ifdef NEW_SYSTEM
  string query, name, category;
  int rtime;
#endif

  seteuid("Root");
  person = ({ });
  if (file[0] == '/') {
    file = file[1..];
  }
  switch (file[0..1]) {
  case "w/" :
    sscanf(file, "w/%s/%*s", temp1);
    if (file_size("/w/"+temp1) == -2) {
      person += ({ temp1 });
    } else
      person += ({ "shaydz" });
    break;
  case "d/" :
    sscanf(file, "d/%s/%*s", temp1);
    person += DOMAIN_H->query_leaders(temp1);
    break;
  default :
    log_file( "ERRORS", sprintf("%s %d %s\n", reporter, time(), file));
  }
  if (file[0..4] == "room/") {
    person += ({ "shaydz" });
  }
  if (file[0..6] == "global/") {
    person += ({ "shaydz" });
  }
  if (file[0..8] == "handlers/") {
    person += ({ "shaydz" });
  }
  if ( file[ 0 .. 3 ] == "std/" ) {
    person += ({ "shaydz" });
  }
  if (file[0..3] == "net/") {
    person += ({ "shaydz" });
  }
  if ( file[ 0 .. 3 ] == "obj/" ) {
    if ( sscanf( file[ 4 .. ], "%*sspell%*s" ) == 2 ) {
      person += ({ "shiannar" });
    } else if ( sscanf( file[ 4 .. ], "%*srituals%*s" ) == 2 ) {
      person += ({ "sandoz" });
    } else if (sscanf(file[4..], "%*smusic%*s") == 2) {
      person += ({ "shaydz" });
    } else {
      person += ({ "shaydz" });
    }
  }
  if (file[0..6] == "secure/") {
    person += ({ "shaydz" });
  }
  if (file[0..4] == "cmds/") {
    person += ({ "shaydz", "shiannar", "sandoz" });
  }

  j = explode(file, "/");
  dir = "/" + implode(j[0..<2], "/");
#ifdef OLD_SYSTEM
  temp2 = dir + "/" + ERROR_LOG;
  i = unguarded((: file_length, temp2 :));
  if (i > 0) {
    temp1 = unguarded((: read_file, temp2, i, 1 :));
    if(sscanf(temp1, ".END %d", i) == 1)
      i += 1;
    else
      i = 1;
  } else i = 1;
  report = reporter + "\n" + text;
  if (trace) {
    report += "\nError:\n" + trace;
  }
  if (sscanf(full_type, "%s %s", temp1, type) == 2) {
    report = temp1+" "+type+"\n"+file+"\n"+"\n\n"+time()+"\n"+report;
    report = ".START " + i + "\n" + report + ".END " + i + "\n";
    unguarded((: write_file, temp2, report :));
  } else {
    report = file + "\n" + "\n\n" + time() + "\n" + report;
    report =  full_type + "\n" + report;
    /*
      if ( type == "IDEA" )
      log_file( type, text );
      */
    report = ".START " + i + "\n" + report + ".END " + i + "\n";
    unguarded((: write_file, temp2, report :));
  }
#endif /* OLD_SYSTEM */
#ifdef NEW_SYSTEM
  sscanf(full_type, "%s %s", category, full_type);
  if (!sscanf(full_type, "%s %s", type, name)) {
    type = full_type;
    name = "";
  }
  rtime = time();
  query = sprintf("INSERT LOW_PRIORITY INTO errors (EntryDate, DirEntryDate, "
                  "Directory, Filename, Category, Type, Name, Reporter, "
                  "Report, Runtime) VALUES(%d, %d, '%s', '/%s', '%s', '%s', "
                  "'%s', '%s', '%s', '%s');", rtime, rtime, dir,
                  db_escape(file), category, type, db_escape(name), reporter,
                  db_escape(text), (trace ? db_escape(trace) : ""));
  catch(db_exec(db_fd, query));
#endif /* NEW_SYSTEM */
  j = explode( file, "/" );
  file = "/"+ implode( j[ 0 .. <2 ], "/" );
  for(i=0;i<sizeof(person);i++) {
    temp1 = read_file("/w/"+person[i]+"/"+PLAYER_ERROR_LOG);
    if (!temp1) {
      temp1 = "";
    }
    j = explode(temp1, "\n");
    if (!j) {
      j = ({ });
    }
    if (member_array(file, j) == -1) {
      j += ({ file });
    }
    temp1 = implode(j, "\n")+ "\n";
    master()->do_log(person[i], temp1);
  }

  event(users(),"inform",reporter+" has submitted a bug report.("+
       file+")","error");

} /* smart_log()*/

void dest_me() {
    object ob;

    ob = TO;

    catch( db_close(db_fd) );

    if( ob )
        destruct(ob);

} /* dest_me() */

void clean_up() { dest_me(); }

void reset() { dest_me(); }

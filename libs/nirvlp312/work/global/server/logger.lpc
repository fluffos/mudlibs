/*                               Logger

   by Walchy @ Tubmud
      introduced to the corelib by Alfe 98-May-15

   version : 3.79

         start : 21.12.1997
   last update : 20.05.1998

*/

#pragma strong_types

#include   <libs.h>
#include   <limits.h>
#include   <kernel.h>
#include   <logger.h>

inherit    ACCESS;
inherit    "basic/create";
inherit    "basic/tools/time";

/********************************************************************/
/*                                Defines                           */
/********************************************************************/

#define    SAVE_LOGS    "/save/log_index"

#define  L_MAIN              "main" // Key for the index-maindata

// Array-index (per log)

#define  L_LOG_NAME         -1      // Key of the mapping
#define  L_LOG_LASTCHANGE    0      // Last change (time())
#define  L_LOG_LINES         1      // Lines in Name.log
#define  L_LOG_OLDLINES      2      // Lines in Name.old
#define  L_LOG_MAXLOGLINES   3      // Maximal lines in Name.log
#define  L_LOG_MAXOLDLINES   4      // Maximal lines in Name.old
#define  L_LOG_SWAPLINES     5      // Number of lines to swapout
#define  L_LOG_STOPPED       6      // No new logs to this file ?
#define  L_LOG_PRIVILEGE     7      // Logs to this fire privileged ?

// Array-index (main)

#define  L_MAI_NAME         -1      // Key for the mapping
#define  L_MAI_OWNER         0      // Owner of the logdirectory
#define  L_MAI_PATH          1      // Complete path of the logdirectory
#define  L_MAI_LASTCHANGE    2      // time() of lastchange to this ld
#define  L_MAI_MAXLOGLINES   3      // Standart number of Name.log
#define  L_MAI_MAXOLDLINES   4      // Standart number of Name.old
#define  L_MAI_SWAPLINES     5      // Standart number to swapout
#define  L_MAI_DIRSTOPPED    6      // No new logs to this logdir ?
#define  L_MAI_PRIVILEGE     7      // Logs to this dir privileged ?

/********************************************************************/
/*                               Variables                          */
/********************************************************************/

private mapping      logs = ([]);        // Data-list of indices
private mapping      news = ([]);        // List of all logreaders which
                                         // receive news.

/********************************************************************/
/*                              Load / Save                         */
/********************************************************************/

private status
load_logs() {
  if(file_size(SAVE_LOGS+".o") > 0) {
    logs = LIB_SAVER -> load(SAVE_LOGS);
    return 1;
  }
  return 0;
}

private void
save_logs() {
  unguarded(1, #'call_other, ({ LIB_SAVER, "save", logs,
                                SAVE_LOGS }) );
}

private string
load_long_file(string filename) {
  string   back;
  int      flength, i;
  int      blocks, rest;

  back = "";
  flength = file_size(filename);

  if (flength > 0) {
    if (flength > MAX_READ) {
      blocks = flength / MAX_READ;
      rest = flength - (blocks * MAX_READ);
      for (i = 0; i < blocks; i++) {
        back += read_bytes(filename, i * MAX_READ, MAX_READ);
      }
      if (rest > 0) {
        back += read_bytes(filename, blocks * MAX_READ, rest);
      }
    } else {
      back = read_file(filename);
    }
  }
  return back;
}

private int
save_log(string filename, string tosave) {
  int   blocks, rest;
  int   i;

  if (tosave) {
    if (file_size(filename) > -1) {
      unguarded( 1, #'rm, ({ filename }) );
    }
    if (strlen(tosave) > MAX_READ) {
      blocks = strlen(tosave) / MAX_READ;
      rest = strlen(tosave) - (blocks * MAX_READ);
      for (i = 0; i < blocks; i++) {
        unguarded( 1, #'write_file,
                   ({ filename,
                      tosave[i * MAX_READ..i * MAX_READ + MAX_READ - 1] }) );
      }
      if (rest > 0) {
        unguarded( 1, #'write_file,
                   ({ filename,
                      tosave[blocks * MAX_READ..blocks * MAX_READ + rest] }) );
      }
      return 1;
    } else {
      unguarded( 1, #'write_file, ({ filename, tosave }) );
      return 1;
    }
  }
  return 0;
}

/********************************************************************/
/*                          Internal functions                      */
/********************************************************************/

private status
check_priv(string path, object player) {
  mixed h;
  h = get_privilege(player);
  return (SECURITY->
          higher_privilege(h,SECURITY->query_protection(path+"blablub", 1)) &&
          check_previous_privilege(h));
}

private void
create_new_log_entry(string iname, string lname) {
  if (lname == L_MAIN) { return; }
  if (lname != SYSTEMLOG) {
    logs[iname] += ([ lname : ({ time(), 0, 0,
                                 logs[iname][L_MAIN][L_MAI_MAXLOGLINES],
                                 logs[iname][L_MAIN][L_MAI_MAXOLDLINES],
                                 logs[iname][L_MAIN][L_MAI_SWAPLINES],
                                 0, 0 }) ]);
  } else {
    logs[iname] += ([ SYSTEMLOG : ({ time(), 0, 0, 30, 50, 10, 0, 0 }) ]);
  }
  save_logs();
}

private string
check_for_illegal(string text) {
  string  *check, ntext;
  int      i;

  if (strlen(text) > 2990) {
    ntext = text[0..2990];
  } else {
    ntext = text;
  }
#if 0 // sunbloof 7-jul-99
  check = explode(text, "");
  for (i = 0; i < sizeof(check); i++) {
    if (check[i] == "\n") { check[i] = ""; }
  }
  return implode(check, "");
#else
  return regreplace(text, "\n", "", 1);
#endif
}

private string
check_path_name(string opath) {
  string  *check, npath;

  check = explode(opath, "");
  if (check[sizeof(check)-1] != "/") { check += ({ "/" }); }
  npath = implode(check, "");
  if (file_size(npath) != -2) { return 0; }
  return npath;
}

private int
check_file_length(string iname, string lname) {
  status   fk;
  string   compfile, out;
  string  *logfile, *oldfile, *swap;
  int      i, testl;

  if ( (logs[iname][lname][L_LOG_LINES] + 1) >
        logs[iname][lname][L_LOG_MAXLOGLINES]) {

    swap = ({});

    compfile = load_long_file(logs[iname][L_MAIN][L_MAI_PATH]+
                              lname+".log");
    logfile = explode(compfile, "\n");
#if 0 // sunblood 7-jul-99
    fk = 1;
    while (fk) {
      for (i = 0; i < logs[iname][lname][L_LOG_SWAPLINES]; i++) {
        swap += ({ logfile[0] });
        logfile[0..0] = ({});
      }
      if (sizeof(logfile) <= logs[iname][lname][L_LOG_MAXLOGLINES]) {
        fk = 0;
      }
    }
#else
    logs[iname][lname][L_LOG_LINES] = sizeof(logfile); // might be different
						     // if somebody wrote
						     // to the file
    if (sizeof(logfile) + 1 > logs[iname][lname][L_LOG_MAXLOGLINES]) 
    {
      int sw;
      sw = logs[iname][lname][L_LOG_SWAPLINES];
      
      do {
	swap += logfile[0..sw-1];
	logfile[0..sw-1] = ({});
      } while (sizeof(logfile) > logs[iname][lname][L_LOG_MAXLOGLINES]);
    }
#endif
    save_log(logs[iname][L_MAIN][L_MAI_PATH]+
             lname+".log", implode(logfile, "\n"));

    if (logs[iname][lname][L_LOG_MAXOLDLINES] > 0) {
      if (file_size(logs[iname][L_MAIN][L_MAI_PATH]+
                    lname+".old") > -1) {

        compfile = load_long_file(logs[iname][L_MAIN][L_MAI_PATH]+
                                  lname+".old");
        oldfile = explode(compfile, "\n");
      } else {
        oldfile = ({});
      }
#if 0 // sunblood 7-jul-99
      for(i = 0; i < sizeof(swap); i++) {
        oldfile += ({ swap[i] });
      }
#else
      oldfile += swap;
#endif
      if (sizeof(oldfile) > logs[iname][lname][L_LOG_MAXOLDLINES]) {
        testl = sizeof(oldfile) - logs[iname][lname][L_LOG_MAXOLDLINES];
#if 0 // sunblood
        for (i=0; i < testl; i++) {
          oldfile[0..0] = ({});
        }
#else
	oldfile[0..testl-1] = ({});
#endif
      }
      save_log(logs[iname][L_MAIN][L_MAI_PATH]+
               lname+".old", implode(oldfile, "\n"));

      logs[iname][lname][L_LOG_LINES] = sizeof(logfile);
      logs[iname][lname][L_LOG_OLDLINES] = sizeof(oldfile);
    } else {
      for (i = 0; i < sizeof(swap); i++) {
        oldfile = explode(swap[i], "@");
        out = ("@"+nice_date(to_int(oldfile[0]), 3)+" "+
               sprintf("%-13s", LIB_STRINGS->cut_string_nicely(oldfile[1],12))+
               sprintf("%3s", oldfile[2])+" "+
               break_string(oldfile[3],77,32,1)+"\n");
        unguarded(1, #'write_file, ({ logs[iname][L_MAIN][L_MAI_PATH]+
                                      lname+".old",
                                      out}) );
      }
      logs[iname][lname][L_LOG_LINES] = sizeof(logfile);
      logs[iname][lname][L_LOG_OLDLINES] += sizeof(swap);
    }
  }
  save_logs();
  return 1;
}

private int
send_news(string iname, string lname, int ti, string objname,
          string objlevel, string text) {
  int      i;

  if (member(news, iname)) {
    news[iname] -= ({ 0 });
    if (sizeof(news[iname])) {
      for(i = 0; i < sizeof(news[iname]); i++) {
#if 1 // Not enough arguments to call_other ?!?
        call_out(#'call_other, 0, news[iname][i], "receive_news",
                 ([ L_INDEX: iname,
                    L_FILE: lname,
                    L_LTIME: ti,
                    L_OBJNAME: objname,
                    L_OBJLEVEL: objlevel,
                    L_TEXT: text ]) );
#else
        news[iname][i] -> receive_news( ([ L_INDEX: iname,
                                           L_FILE: lname,
                                           L_LTIME: ti,
                                           L_OBJNAME: objname,
                                           L_OBJLEVEL: objlevel,
                                           L_TEXT: text ]) );
#endif
      }      
    }
    return 1;
  }
  return 0;
}

/********************************************************************/
/*                             log function                         */
/********************************************************************/

// The main function to log anything

varargs int
log(string text, string lname, string iname, mixed trigger) {
  int      check, i;
  string   triggername, triggerlevel;
  string  *pathname;
  string   endwrite;

  if (!iname) {
    check = 0;
    pathname = explode(object_name(previous_object()), "/");
    for (i = 0; i < sizeof(pathname); i++) {
      if (member(logs, pathname[i])) {
        check = 1;
        break;
      }
    }
    if (!check) {
      return L_B_NOINDEX;
    }
  } else {
    if (!member(logs, iname)) { return L_B_NOINDEX; }
  }

  trigger = trigger || this_player() || previous_object();

  if (logs[iname][L_MAIN][L_MAI_PRIVILEGE] && lname != SYSTEMLOG) {
    if (!check_previous_privilege(logs[iname][L_MAIN][L_MAI_PRIVILEGE])) {
      return L_B_NOWRITEPRIVILEGE;
    }
  }
  if (logs[iname][L_MAIN][L_MAI_DIRSTOPPED] && lname != SYSTEMLOG) {
    return L_B_NEWENTRYSTOPPED;
  }
  if (!member(logs[iname], lname)) {
    if (!stringp(lname))
      raise_error("Bad argument 2 to log()\n");
    if (lname == L_MAIN) { return 0; }
    create_new_log_entry(iname, lname);
    if (lname != SYSTEMLOG) {
      log("New log added : "+lname+".", SYSTEMLOG,
          iname,previous_object());
    }
  }
  if (logs[iname][lname][L_LOG_PRIVILEGE] && lname != SYSTEMLOG) {
    if (!check_previous_privilege(logs[iname][lname][L_LOG_PRIVILEGE])) {
      return L_B_NOWRITEPRIVILEGE;
    }
  }
  if (logs[iname][lname][L_LOG_STOPPED] && lname != SYSTEMLOG) {
    return L_B_NEWENTRYSTOPPED;
  }

#if 1  // this bugs due to an unknown reason. No time to fix that now.
       // Coogan, 30-Jun-99
       // 0 -> 1 sunblood, 7-jul-99
  check_file_length(iname, lname);
#endif

  if (!trigger) {
    triggername  = "unknown";
    triggerlevel = "xx";
  } else {
    if (stringp(trigger)) {
       triggername  = check_for_illegal(trigger);
       triggerlevel = "st";
    } else {
      if (living(trigger)) {
        if (find_player(trigger -> query_name())) {
          triggername  = capitalize(trigger -> query_real_name());
          triggerlevel = trigger -> query_level();
        } else {
          triggername  = trigger -> query_name();
          triggerlevel = "NP";
        }
      } else {
        if (objectp(trigger)) {
          triggername  = trigger -> short();
          triggerlevel = "OB";
        } else {
          if (stringp(trigger)) {
            triggername  = trigger;
            triggerlevel = "st";
          }
        }
      }
    }
  }
  endwrite = "";
  if (logs[iname][lname][L_LOG_LINES] > 0) { endwrite = "\n"; }
  endwrite += (time()+"@"+triggername+"@"+triggerlevel+"@"+
               check_for_illegal(text));
  send_news(iname, lname, time(), triggername, triggerlevel, text);
  unguarded(1,#'write_file,({logs[iname][L_MAIN][L_MAI_PATH]+
                             lname+".log", endwrite }) );
  logs[iname][lname][L_LOG_LINES] ++;
  logs[iname][lname][L_LOG_LASTCHANGE] = time();
  logs[iname][L_MAIN][L_MAI_LASTCHANGE] = time();
  save_logs();

  return L_B_SUCCESS;
}

/********************************************************************/
/*                               read_log                           */
/********************************************************************/

mixed
read_log(string lname, string iname, int since, mixed flags) {
  mapping   blines;
  int       logdir, logname;
  int       i, getline, match, getall;
  string   *logfile, *oneline;
  string    objname;
  
  objname = 0;
  match = 0;
  getall = 0;

  if (member(flags, L_OBJECT) != -1) {
    objname = flags[member(flags, L_OBJECT)+1];
    match ++;
  }
  if (member(flags, L_SHOWALL) != -1) {
    getall = 1;
  }
  if (since) { match ++; }

  logfile = ({});
  blines = ([ LR_ERROR: ({}),
              LR_TEXT: ({}),
              LR_LTIME: ({}),
              LR_OBJNAME: ({}),
              LR_OBJLEVEL: ({}),
           ]);

  if (!member(logs, iname)) {
    blines[LR_ERROR] += ({ ({ -1, "Indexname not found." }) });
  } else {
    if (!member(logs[iname], lname)) {
      blines[LR_ERROR] += ({ ({ -2, "Logfile not found." }) });
    } else {
      if (member(flags, L_SHOWOLD) != -1 &&
          logs[iname][lname][L_LOG_OLDLINES] > 0 &&
          logs[iname][lname][L_LOG_MAXOLDLINES] > 0) {
        logfile += explode(load_long_file(logs[iname][L_MAIN][L_MAI_PATH]+
                                          lname+".old"),"\n");
      } else {
        if (member(flags, L_SHOWOLD) != -1) {
          if (logs[iname][lname][L_LOG_MAXOLDLINES] == 0) {
            blines[LR_ERROR] += ({ ({ -3, "*.old can't be displayed." }) });
          }
        }
      }
      logfile += explode(load_long_file(logs[iname][L_MAIN][L_MAI_PATH]+
                                        lname+".log"),"\n");
      for (i = 0; i < sizeof(logfile); i++) {
        oneline = explode(logfile[i], "@");
        if (sizeof(oneline) > 4) {
          oneline[3] = implode(oneline[3..], "@");
        }
        getline = 0;

        if (getall && !objname) {
          getline = match + 1;
        } else {
          if (since) { 
            if (since <= to_int(oneline[0])) { getline ++; }
          }
          if (objname) {
            if (objname == oneline[1]) {
              if (getall) {
                getline = match + 1;
              } else {
                getline ++;
              }
            }
          }
        }        

        if (getline >= match) {
          blines[LR_TEXT] += ({ oneline[3] });
          blines[LR_LTIME] += ({ to_int(oneline[0]) });
          blines[LR_OBJNAME] += ({ oneline[1] });
          blines[LR_OBJLEVEL] += ({ oneline[2] });
        }
      }
    }
  }

  return blines;
}

/********************************************************************/
/*                    Add, remove and info functions                */
/********************************************************************/

// Add a new logdirectory.

int
add_index(string path, string iname,
          int maxloglines, int maxoldlines, int swaplines,
          mixed privilege) {
  object    tp;
  int       i;
  string    npath;
  mixed     priv;
  mapping   onelog;

  priv = 0;

  if (member(logs, iname)) {
#if 0 // sunblood 7-jul-99
    throw(({ L_B_ALREADY_IN_USE,logs[i][0][L_MAI_OWNER] }));
#else
    throw(({ L_B_ALREADY_IN_USE,logs[iname][L_MAIN][L_MAI_OWNER] }));
#endif
  }
  npath = check_path_name(path);
  if (!npath) {
    throw(({ L_B_NO_SUCH_PATH }));
  }
  if (!check_priv(npath, this_player())) {
    throw(({ L_B_NO_WRITE_PERMISSIONS }));
  }
#if 0
  onelog = load_ldir(npath);
  if (onelog) {
    throw(({ L_B_DIRECTORY_NOT_FREE,
             onelog[0][L_MAI_OWNER],
             onelog[0][L_MAI_NAME] }));
  }
#endif

  if (maxloglines > L_MAX_LOGLINES)  { maxloglines = L_MAX_LOGLINES; }
  if (maxoldlines > L_MAX_OLDLINES)  { maxoldlines = L_MAX_OLDLINES; }
  if (swaplines   > L_MAX_SWAPLINES) { swaplines   = L_MAX_SWAPLINES; }

#if 1 // sunblood 7-jul-99
  if (maxloglines < 10)  { maxloglines = 10; }
  if (maxoldlines < 10)  { maxoldlines = 10; }
  if (swaplines   < 5)  { swaplines   = 5; }
#endif

  if (privilege) {
    if (stringp(privilege) || privilege == 1) {
      priv = privilege;
    } else {
      raise_error("Illegal privilege\n");
    }
  }

  logs += ([ iname: ([ L_MAIN: ({ this_player()->query_real_name(), npath,
                                  time(), maxloglines, maxoldlines,
                                  swaplines, 0, priv, ({}) }) ]) ]);
  save_logs();
  if (this_player() && is_wizard(this_player())) // sunblood, 7-jul-99
    tell_object(this_player(), "--- New index added. Data : ---\n"+
                "Owner         : "+logs[iname][L_MAIN][L_MAI_OWNER]+"\n"+
                "Log name      : "+iname+"\n"+
                "Path          : "+logs[iname][L_MAIN][L_MAI_PATH]+"\n"+
                "Maxent. l/o/s : "+logs[iname][L_MAIN][L_MAI_MAXLOGLINES]+"/"+
                                   logs[iname][L_MAIN][L_MAI_MAXOLDLINES]+"/"+
                                   logs[iname][L_MAIN][L_MAI_SWAPLINES]+"\n"+
                "Privilege     : "+logs[iname][L_MAIN][L_MAI_PRIVILEGE]+"\n");
  log("This logindex added.", SYSTEMLOG, iname, previous_object());
  return 1;
}

string
info_index(string iname, string lname) {
  int      i, l;
  int      c, s;
  string   out;

  if (!member(logs, iname)) {
    return "The indexname "+iname+" isn't in the list.\n";
  }
  if (!lname) {
    out = "Owner         : "+logs[iname][L_MAIN][L_MAI_OWNER]+"\n"+
          "Index name    : "+iname+"\n"+
          "Path          : "+logs[iname][L_MAIN][L_MAI_PATH]+"\n"+
          "Maxent. l/o/s : "+logs[iname][L_MAIN][L_MAI_MAXLOGLINES]+"/"+
                             logs[iname][L_MAIN][L_MAI_MAXOLDLINES]+"/"+
                             logs[iname][L_MAIN][L_MAI_SWAPLINES]+"\n"+
          "Privilege     : "+logs[iname][L_MAIN][L_MAI_PRIVILEGE]+"\n"+
          "Stopped       : ";
    if (logs[iname][L_MAIN][L_MAI_DIRSTOPPED]) {
      out += "Yes";
    } else {
      out += "No";
    }
    out += "\nActive logs   : "+
           to_string(sizeof(m_indices(logs[iname]))-1);
    s = 0;
    for (c = 1; c < sizeof(m_indices(logs[iname]))-1; c++) {
      if (logs[iname][m_indices(logs[iname])[c]][L_LOG_STOPPED]) { s++; }
    }
    if (s > 0) {
      out += " ("+to_string(s)+" stopped)";   
    }
    out += "\n";
    return out;
  } else {
    if (!member(logs[iname], lname)) {
      return "Logfile not found : "+lname+".\n";
    }
    out = "Owner          : "+logs[iname][L_MAIN][L_MAI_OWNER]+"\n"+
          "Index name     : "+iname+"\n"+
          "Maxent. l/o/s  : "+logs[iname][lname][L_LOG_MAXLOGLINES]+"/"+
                              logs[iname][lname][L_LOG_MAXOLDLINES]+"/"+
                              logs[iname][lname][L_LOG_SWAPLINES]+"\n";
    if (logs[iname][L_MAIN][L_MAI_PRIVILEGE] ||
        logs[iname][lname][L_LOG_PRIVILEGE]) {
      out += "Privilege      : "+logs[iname][lname][L_LOG_PRIVILEGE];
      if (logs[iname][L_MAIN][L_MAI_PRIVILEGE] !=
          logs[iname][lname][L_LOG_PRIVILEGE]) {
        out += " ("+logs[iname][L_MAIN][L_MAI_PRIVILEGE]+")";
      }
      out += "\n";
    }
    if (logs[iname][L_MAIN][L_MAI_DIRSTOPPED] ||
        logs[iname][lname][L_LOG_STOPPED]) {
      out += "Stopped        : ";
      if (logs[iname][lname][L_LOG_STOPPED]) {
        out += "Yes";
      } else {
        out += "No";
        if (logs[iname][L_MAIN][L_MAI_DIRSTOPPED]) {
          out += " (Yes)";
        }
      }
      out += "\n";
    }
    out += "Entrys log/old : "+to_string(logs[iname][lname][L_LOG_LINES])+"/"+
                               to_string(logs[iname][lname][L_LOG_OLDLINES])+"\n";
    return out;
  }
}

int
remove_index(string iname, int rall) {
  int      i;
  string   lname;

  if (!member(logs, iname)) {
    return -1;
  }
  if (!check_priv(logs[iname][L_MAIN][L_MAI_PATH], this_player())) {
    return -2;
  }
  if (!rall) {
    log("Index removed (this logdir)", SYSTEMLOG, iname);
  } else {
    for(i = 1; i < sizeof(m_indices(logs[iname]))-1; i++) {
      lname = m_indices(logs[iname])[i];
      unguarded(1, #'rm, ({ logs[iname][L_MAIN][L_MAI_PATH]+
                            lname+".log" }) );
      unguarded(1, #'rm, ({ logs[iname][L_MAIN][L_MAI_PATH]+
                            lname+".old" }) );
    }
  }
  logs -= ([ iname ]);
  save_logs();
  return 1;
}

int
remove_log_file(string iname, string lname, int which) {

  if (!member(logs, iname)) {
    return 0;
  }
  if (!member(logs[iname], lname)) {
    return -1;
  }
  if (!check_priv(logs[iname][L_MAIN][L_MAI_PATH], this_player())) {
    return -2;
  }
  if (which == 0) {
    unguarded( 1, #'rm, ({ logs[iname][L_MAIN][L_MAI_PATH]+
                           lname+".log" }) );
  }
  unguarded( 1, #'rm, ({ logs[iname][L_MAIN][L_MAI_PATH]+
                         lname+".old" }) );
  if (which == 0) {
    logs[iname] -= ([ lname ]);
  } else {
    logs[iname][lname][L_LOG_OLDLINES] = 0;
  }
  save_logs();
  if (which == 0) {
    log("Logfile removed : "+lname+".", SYSTEMLOG, iname);
  } else {
    log("Oldfile removed : "+lname+".old.", SYSTEMLOG, iname);
  }
  return 1;
}

int
toggle_new_logs(string iname, string lname) {
  if (!member(logs, iname)) {
    return -1;
  }
  if (!check_priv(logs[iname][L_MAIN][L_MAI_PATH], this_player())) {
    return -2;
  }

  if (!lname || lname == "") {
    if (logs[iname][L_MAIN][L_MAI_DIRSTOPPED] == 0) {
      log("New logs to this index forbidden.", SYSTEMLOG, iname);
      logs[iname][L_MAIN][L_MAI_DIRSTOPPED] = 1;
    } else {
      log("New logs to this index allowed.", SYSTEMLOG, iname);
      logs[iname][L_MAIN][L_MAI_DIRSTOPPED] = 0;
    }
    save_logs();
    return 1;
  }

  if (!member(logs[iname], lname)) {
    return -3;
  }

  if (logs[iname][lname][L_LOG_STOPPED] == 0) {
    log("New logs forbidden : "+lname+".", SYSTEMLOG, iname);
    logs[iname][lname][L_LOG_STOPPED] = 1;
  } else {
    log("New logs allowed : "+lname+".", SYSTEMLOG, iname);
    logs[iname][lname][L_LOG_STOPPED] = 0;
  }
  save_logs();
  return 1;
}

public void
add_notify(object newsobj, string iname) {
  if (member(news, iname)) {
    if (member(news[iname], newsobj) != -1) {
      return;
    }
    news[iname] += ({ newsobj });
  } else {
    news += ([ iname: ({ newsobj }) ]);
  }
}

public void
remove_notify(object newsobj, string iname) {
  if (member(news, iname)) {
    if (member(news[iname], newsobj) != -1) {
      news[iname] -= ({ newsobj });
      if (!sizeof(news[iname])) {
        news -= ([ iname ]);
      }
    }
  }
}

int
set_new_privilege(string iname, string lname, mixed privilege) {
  if (!member(logs, iname)) { return -1; }
  if(!SECURITY -> higher_privilege(get_privilege(this_player()),
                                   logs[iname][L_MAIN][L_MAI_PRIVILEGE])) {
    return -2;
  }
  if (!check_priv(logs[iname][L_MAIN][L_MAI_PATH], this_player())) {
    return -3;
  }
  if (!member(logs[iname], lname)) {
    logs[iname][L_MAIN][L_MAI_PRIVILEGE] = privilege;
    log("Privilege of index changed : "+to_string(privilege)+".",
        SYSTEMLOG, iname);
    save_logs();
    return 1;
  } else {
    if(SECURITY -> higher_privilege(get_privilege(this_player()),
                                    logs[iname][lname][L_LOG_PRIVILEGE])) {
      logs[iname][lname][L_LOG_PRIVILEGE] = privilege;
      log("Privilege of logfile "+lname+" changed : "+to_string(privilege)+".",
          SYSTEMLOG, iname);
      save_logs();
      return 1;
    } else {
      return -2;
    }
  }
  return 1;  
}

int
set_new_entrynr(string iname, string lname, int *ent) {
  int  *set;

  set = ({ L_MAX_LOGLINES, L_MAX_OLDLINES, L_MAX_SWAPLINES });
  if (ent[0] < L_MAX_LOGLINES && ent[0] != 0){ set[0] = ent[0]; }
  if (ent[1] < L_MAX_OLDLINES) { 
    if (ent[1] == 0) {
      if (check_previous_privilege(1)) {
        set[1] = 0;
      } else {
        set[1] = L_MAX_OLDLINES;
      }
    } else {
      set[1] = ent[1];
    }
  }
  if (ent[2] < L_MAX_SWAPLINES && ent[2] != 0) { set[2] = ent[2]; }

  if (!member(logs, iname)) { return -1; }
  if (!check_priv(logs[iname][L_MAIN][L_MAI_PATH], this_player())) {
    return -3;
  }
  if (!member(logs[iname], lname)) {
    logs[iname][L_MAIN][L_MAI_MAXLOGLINES] = set[0];
    logs[iname][L_MAIN][L_MAI_MAXOLDLINES] = set[1];
    logs[iname][L_MAIN][L_MAI_SWAPLINES] = set[2];
    log("Max entrys of index changed : "+to_string(set[0])+","+
        to_string(set[1])+","+to_string(set[2])+".",
        SYSTEMLOG, iname);
  } else {
    logs[iname][lname][L_MAI_MAXLOGLINES] = set[0];
    logs[iname][lname][L_MAI_MAXOLDLINES] = set[1];
    logs[iname][lname][L_MAI_SWAPLINES] = set[2];
    log("Max entrys of logfile "+lname+" changed : "+to_string(set[0])+","+
        to_string(set[1])+","+to_string(set[2])+".",
        SYSTEMLOG, iname);
  }
  save_logs();
  return 1;
}

/********************************************************************/
/*                          Standard functions                      */
/********************************************************************/

status
prevent_move() { return 1; }      // Don't move this object.

void
create() {
  if (clonep()) { destruct(this_object()); } // Destruct if a clone
  if (!load_logs()) {
    logs = ([]);
  }
}

void
notify_destruct() {
  if (!clonep())
    save_logs();
}

/********************************************************************/
/*                            Query functions                       */
/********************************************************************/

// For debuggingpurposes
mapping
query_logs() {
  if (!check_previous_privilege(1))
    raise_error("Illegal call\n");
  return logs;
}

mixed
query_news() {
  if (!check_previous_privilege(1))
    raise_error("Illegal call\n");
  return news;
}
// End

mixed
query_log_names(string iname) {
  if (!member(logs, iname)) { return 0; }
  return m_indices(logs[iname]) - ({ L_MAIN });
}

int
query_date_of_last_change(string iname,string lname) {
  if (!member(logs, iname)) { return 0; }
  if (!member(logs[iname], lname)) { return 0; }
  return logs[iname][lname][L_LOG_LASTCHANGE];
}

status
index_exists(string iname) {
  return member(logs, iname);
}

status
logfile_exists(string iname,string lname) {
  if (!member(logs, iname)) { return 0; }
  return member(logs[iname], lname);
}

mixed
load_unlimited_log(string iname,string lname) {
  if (!member(logs, iname)) { return 0; }
  if (!member(logs[iname], lname)) { return 0; }
  if (logs[iname][lname][L_LOG_MAXOLDLINES] == 0) {
    return load_long_file(logs[iname][L_MAIN][L_MAI_PATH]+
                          lname+".old");
  }
  return 0;
}

int
last_index_change(string iname) {
  if (!member(logs, iname)) { return 0; }
  return logs[iname][L_MAIN][L_MAI_LASTCHANGE];
}

mixed *
query_index_logfiles(string iname) {
  return query_log_names(iname);
}

int
query_logfile_lastchange(string iname, string lname) {
  if (!member(logs, iname)) { return 0; }
  if (!member(logs[iname], lname)) { return 0; }
  return logs[iname][lname][L_LOG_LASTCHANGE];
}

int *
query_logfile_lines(string iname, string lname) {
  if (!member(logs, iname)) { return 0; }
  if (!member(logs[iname], lname)) { return 0; }
  return ({ logs[iname][lname][L_LOG_LINES],
            logs[iname][lname][L_LOG_OLDLINES],
            logs[iname][lname][L_LOG_MAXLOGLINES],
            logs[iname][lname][L_LOG_MAXOLDLINES],
            logs[iname][lname][L_LOG_SWAPLINES] });
}

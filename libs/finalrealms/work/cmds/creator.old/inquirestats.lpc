/* Print statistics from /net/inquired.c.
   Hamlet, Jun 1997
*/

#include <standard.h>
#include <cmd.h>
#include "/net/inquired.h"
#include <inquire_err.h>

inherit CMD_BASE;

void setup() {
  position = 1;
}

string help() {
  return "Usage: inq*uirestats\n";
}

string full_help() {
  return help() + "Print statistics for quick socket queries.\n";
}

string fd_owner(int fd, int len, int strip);

mapping fds, hist;

protected int cmd(string str, object me) {
  mixed *them;
  int i, j, pos;
  string state;
  string ret;
  int *totals = allocate(6);
  float *tmp;

  fds = INQUIRED->get_current_stats();
#ifdef HISTORICAL_STATS
  hist = INQUIRED->get_historical_stats();
#endif

  them = keys(fds);

#ifndef EXTENSIVE_STATS
ret = "Fd       Callback               Address\n"
      "--  -------------------  ---------------------\n";

  for(i=0; i < sizeof(them); i++) {
    ret += sprintf("%2d  %|19s  %-21s\n", them[i], fd_owner(them[i], 19, 0), 
                   (fds[them[i]][NUMERICIP] + " " + fds[them[i]][PORT]));
#else
ret = "Fd       Callback               Address          Start      State"
      "    Last Act\n"
      "--  -------------------  ---------------------  --------  ---------"
      "  --------\n";

  for(i=0; i < sizeof(them); i++) {
    for(pos=4; !fds[them[i]][TIMESTATS][pos]; pos--); /* <----- ; */
    switch(pos) {
      case CREATED   : state = "CREATED";
                       break;
      case BOUND     : state = "BOUND";
                       break;
      case CONNECTED : state = "CONNECTED";
                       break;
      case CURREAD   : state = "READING";
                       break;
    }
    ret += sprintf("%2d  %|19s  %-21s  %s  %|9s  %s\n", them[i], 
                   fd_owner(them[i], 19, 0), 
                   (fds[them[i]][NUMERICIP] + " " + fds[them[i]][PORT]),
                   ctime(fds[them[i]][TIMESTATS][CREATED])[11..18], state,
                   ctime(fds[them[i]][TIMESTATS][pos])[11..18]);
#endif
  }

#ifdef HISTORICAL_STATS
  them = keys(hist) - ({ "GLOBALS:" });

#ifndef EXTENSIVE_STATS
  ret += "\n\n"
         "                                %   Time-\n"
         "   Caller      Calls  Answers  Ans  outs\n"
         "-------------  -----  -------  ---  -----\n";
  for(i=0; i < sizeof(them); i++) {
    if(hist[them[i]][CALLS])
      tmp = ({ to_float(hist[them[i]][ANSWERS]) * 100 / 
               to_float(hist[them[i]][CALLS]) });
    else
      tmp = ({ 0.0 });
    ret += sprintf("%-13s  %4d   %5d    %3d  %4d\n",
                   them[i], hist[them[i]][CALLS], hist[them[i]][ANSWERS],
                   to_int(tmp[0]), hist[them[i]][TIMEOUTS]); 
    for(j=0; j <= TIMEOUTS; j++)
      totals[j] += hist[them[i]][j];
  }
  ret += "-------------  -----  -------  ---  -----\n";
  if(totals[CALLS])
    tmp = ({ to_float(totals[ANSWERS]) * 100 / to_float(totals[CALLS]) });
  else
    tmp = ({ 0.0 });

  ret += sprintf("%-13s  %4d   %5d    %3d  %4d\n",
                 "TOTALS:", totals[CALLS], totals[ANSWERS],
                 to_int(tmp[0]), totals[TIMEOUTS]); 
  ret += "\n\nFailures to create a socket:  "+hist["GLOBALS:"][CREATED] +
         "\n";

#else /* defined(EXTENSIVE_STATS) */
  ret += "\n\n"
         "                                            Avg   Avg\n"
         "                                %   Time-  Time   Read  Avg Num\n"
         "   Caller      Calls  Answers  Ans  outs   (sec)  Time  Packets\n"
         "-------------  -----  -------  ---  -----  -----  ----  -------\n";
  for(i=0; i < sizeof(them); i++) {
    if(hist[them[i]][CALLS]) 
      tmp = ({ (to_float(hist[them[i]][ANSWERS]) * 100 / 
                to_float(hist[them[i]][CALLS])),
               (to_float(hist[them[i]][QTIME]) / 
                to_float(hist[them[i]][CALLS])) });
    else
      tmp = ({ 0.0, 0.0 });

    if(hist[them[i]][ANSWERS])
      tmp += ({ (to_float(hist[them[i]][READTIME]) / 
                 to_float(hist[them[i]][ANSWERS])),
                (to_float(hist[them[i]][NUMPACKETS]) / 
                 to_float(hist[them[i]][ANSWERS])) });
    else
      tmp += ({ 0.0, 0.0 });

    ret += sprintf("%-13s  %4d   %5d    %3d  %4d   %5.2f  %4.2f  %7.2f\n",
                   them[i], hist[them[i]][CALLS], hist[them[i]][ANSWERS],
                   to_int(tmp[0]), hist[them[i]][TIMEOUTS], tmp[1], 
                   tmp[2], tmp[3]);
    for(j=0; j < 6; j++)
      totals[j] += hist[them[i]][j];
  }
  ret += "-------------  -----  -------  ---  -----  -----  ----  -------\n";
  if(totals[CALLS]) 
    tmp = ({ (to_float(totals[ANSWERS]) * 100 / to_float(totals[CALLS])),
             (to_float(totals[QTIME]) / to_float(totals[CALLS])) });
  else
    tmp = ({ 0.0, 0.0 });

  if(totals[ANSWERS])
    tmp += ({ (to_float(totals[READTIME]) / to_float(totals[ANSWERS])),
              (to_float(totals[NUMPACKETS]) / to_float(totals[ANSWERS])),
              (to_float(hist["GLOBALS:"][BOUND]) / 
               to_float(totals[ANSWERS])),
              (to_float(hist["GLOBALS:"][CONNECTED]) / 
               to_float(totals[ANSWERS])),
              (to_float(hist["GLOBALS:"][FIRSTREAD]) / 
               to_float(totals[ANSWERS])) });
  else
    tmp += ({ 0.0, 0.0, 0.0, 0.0, 0.0 });

  ret += sprintf("%-13s  %4d   %5d    %3d  %4d   %5.2f  %4.2f  %7.2f\n",
                   "TOTALS:", totals[CALLS], totals[ANSWERS], 
                   to_int(tmp[0]), totals[TIMEOUTS], tmp[1], tmp[2], tmp[3]);
  ret += sprintf("\n\n%-40s:  %d\n%-40s:  %6.4f\n%-40s:  %6.4f\n"
                 "%-40s:  %6.4f\n",
                 "Failures to create a socket", hist["GLOBALS:"][CREATED],
                 "Average time taken by resolve()", tmp[4],
                 "Average time to connect", tmp[5],
                 "Average time between connect and read", tmp[6]);
#endif /* EXTENSIVE_STATS */
#endif /* HISTORICAL_STATS */

  tell_object(me, ret);
  return 1;
}

/* If (len > 0), characters will be stripped from the left until
   strlen() matches len.  If (strip), Any #2323 (clone number)
   will be removed before return.
*/
string fd_owner(int fd, int len, int strip) {
  string obname;

  switch(fds[fd][CALLBACK][0]) { /* cbtype */
    case FUNC_PTR :  
#ifdef v22
                     obname = file_name(
                                function_owner(fds[fd][CALLBACK][1]) );
#else
                     obname = sprintf("%O", fds[fd][CALLBACK][1]);
                     obname = replace_string(obname, "(: ", "");
                     obname = replace_string(obname, " :)", ""); 
#endif
                     break;
    case OBJ_OB   :  obname = file_name(fds[fd][CALLBACK][2]);
                     break;
    case STR_OB   :  obname = fds[fd][CALLBACK][2];
                     break;
  }

  if(strip) {
    obname = explode(obname,"#")[0];
    obname = explode(obname,"/")[<1];
  }

  if(len)
    obname = obname[<len..];

  return obname;
} /* fd_owner() */

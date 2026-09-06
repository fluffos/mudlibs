/* /secure/remover
** 
** Removes old (secure) save files.
** A non-wizard player is removed if his age in weeks exceeds the
** magic formula '1 + xp-level * (xp-level <= 10 ? 6 : 12)' weeks.
**
** Players for which a file '<name>' or '<name>.o' exists in MUMMYDIR
** aren't removed at all.
**
** This could have been included into the /secure/master, but why carry
** code around which is need just once a week?
**
**   09-Feb-92 [mateese]
**   10-Feb-93 [mateese] Removal of Seers and learners;
**                       Check of /secure/save; MUMMYDIR
**   20-Feb-93 [mateese] Check for /ftp/public/<remove_name>
**   25-May-93 [mateese] Put in some comments; removed a bug in statistics.
**   15-Jun-93 [mateese] Nr of players is counted as well; upped DELAY
**   18-Jun-93 [mateese] Newsmatrix nrc.o-files are removed as well.
**   25-Sep-93 [hyp]     Files must be at least four weeks old
**   19-Dec-93 [mateese] Absent wizards are suggested for compression.
**   14-Sep-94 [mateese] Implemented removal of single players/wizards.
**   16-Feb-95 [mateese] Recognizes compressed wizard directories.
**   18-Jun-95 Takes care of new savefile variables aLevel and aXP.
**   28-Feb-96 [mateese] Made absense-intervals longer, old players over
**                       level LEVEL aren't removed at all.
**   10-Apr-96 [mateese] Players over LEVEL are at least suggested.
**   18-Jul-96 [mateese] Uninited variables caused the remover to overlook
**                       several outdated players.
**   18-Feb-97 [mateese] Remover now also removes several guild savefiles
**                       and houses.
**   30-Jul-97 [mateese] Adapted for One Step Beyond
**   15-Mar-98 [mateese] New level system.
*/

#include <secure/config.h>
#include <secure/wizlevels.h>

#define LEVEL 14
#define LOGFILE  "REMOVER"
#define LOGSUGG  "TOREMOVE"
#define LOGREM   "REMOVED"
#define MUMMYDIR "/secure/mummy/"
#define SAVEFILE "/secure/save/.remover"
#define DELAY 10
#define IS_ADMIN(pl) (IS_WIZARD(pl))
#define PO previous_object()
#define TO this_object()
#define TP this_player()
#define TI this_interactive()
#define ONEWEEK 604800
#define DEBUG 0

/*------------------------------------------------------------------------*/

  /* Restored from the player savefiles */
int level;
int experience;
int pLastSave;
int aLevel;
int aXP;
int bRemoved;  /* This variable exists only in secure/save-Files of removed
		* players/wizards. */

  /* Holds the time of the last run. */
int last_run;

/*------------------------------------------------------------------------*/

nosave int dirno;  /* Number of the directory to be scanned */
nosave string abc = "abcdefghijklmnopqrstuvwxyz";
nosave int ctotal, cnopl, csugg, cpl, cbogus;
nosave int stotal, snopl, ssugg, spl, sbogus;
nosave int nrnopl, nrpl, nrsugg;
nosave mixed *files;  /* Files to scan from one directory */
nosave string bname;  /* Pathname of the actual directory */
nosave int base;      /* Startindex of actual bunch in *files */

public void start_dragon();
protected void _start_dragon_1();
protected void scan_sfiles();
protected void scan_files();
protected void scan_sdirs();
protected void scan_dirs();
int remove_player(string name);

#if DEBUG
/*------------------------------------------------------------------------*/
nosave string msg;
void addmsg(string m)
{
  if (!msg) msg = m;
  else msg += m;
}
void writemsg()
{
  write_file("/log/REMOVE.debug", msg);
  msg = 0;
}
#else
#define addmsg(m)
#define writemsg()
#endif

/*------------------------------------------------------------------------*/

void create() {
  seteuid(getuid(TO));

  if (clonep()) {
    log_file (LOGFILE,
 ctime(time())+": Illegal attempt!\n"
+"  this:        "+object_name(TO)+" ["+getuid(TO)+"]\n"
+"  previous:    "+(PO ? object_name(PO)+" ["+getuid(PO)+"]" : "<none>")+"\n"
+"  player:      "+(TP ? object_name(TP)+" ["+getuid(TP)+"]" : "<none>")+"\n"
+"  interactive: "+(TI ? object_name(TI)+" ["+getuid(TI)+"]" : "<none>")+"\n\n"
             );
    destruct (TO);
  }
}

/*------------------------------------------------------------------------*/
/* Check all savefiles for expired players and/or wizards.
 * This function must be called by the MASTER only.
 */

protected void _start_dragon_1() {
  dirno = 0;
  log_file (LOGFILE, ctime(time())+": Checking " SAVEPATH "\n");
  scan_dirs();
}

public void start_dragon() {
  if (   PO != find_object(MASTER)
      || getuid(TO) != ROOTID 
      || -1 != member(object_name(TO), '#')) {
    log_file (LOGFILE,
 ctime(time())+": check_all_players(): Illegal attempt!\n"
+"  this:        "+object_name(TO)+" ["+getuid(TO)+"]\n"
+"  previous:    "+(PO ? object_name(PO)+" ["+getuid(PO)+"]" : "<none>")+"\n"
+"  player:      "+(TP ? object_name(TP)+" ["+getuid(TP)+"]" : "<none>")+"\n"
+"  interactive: "+(TI ? object_name(TI)+" ["+getuid(TI)+"]" : "<none>")+"\n\n"
             );
    destruct (TO);
    return;
  }

  if (restore_object(SAVEFILE)
      && last_run + ONEWEEK - 3600 > time()) {
    destruct (TO);
    return;
  }

  last_run = time();
  save_object(SAVEFILE);
  call_out(#'_start_dragon_1,10);
}

/*------------------------------------------------------------------------
** Remove the data for one player/wizard, manual mode.
*/

int remove_player(string name) {
  int rc, wlvl, dirempty, doecho, i, j;
  string tmp, *dir, *tmp2;

  if (!stringp(name)) {
    write("No name given.\n");
    return 0;
  }
  name = lower_case(name);
  if (   !TI 
      || TI != TP
      || (   !IS_ADMIN(TI) 
          && (name != getuid(TI) || TI != PO))
     ) {
    log_file (LOGREM,
 ctime(time())+": remove_player(): Illegal attempt!\n"
+"  this:        "+object_name(TO)+" ["+getuid(TO)+"]\n"
+"  previous:    "+(PO ? object_name(PO)+" ["+getuid(PO)+"]" : "<none>")+"\n"
+"  player:      "+(TP ? object_name(TP)+" ["+getuid(TP)+"]" : "<none>")+"\n"
+"  interactive: "+(TI ? object_name(TI)+" ["+getuid(TI)+"]" : "<none>")+"\n\n"
             );
    write("Permission denied.\n");
    return 0;
  }

  if (   file_size(SAVEPATH+name[0..0]+"/"+name+".o") < 0
      && file_size(SECURESAVEPATH+name[0..0]+"/"+name+".o") < 0
      && !find_player(name) 
     ) {
    write("There is no player '"+capitalize(name)+"' in " MUDNAME ".\n");
    return 0;
  }

  dirempty = 1;
  dir = ({});
  wlvl = query_user_level(name);
  if (wlvl && -2 == file_size(WPATH+name)) {
    dir = get_dir(WPATH+name+"/*") - ({ ".", ".." });
    for (i = sizeof(dir); i--; ) {
      if (!dir[i])
        continue;
      if (dir[i][0] != '.') {
        dirempty = 0;
        dir[i] = 0;
        continue;
      }
      dir[i] = WPATH+name+"/"+dir[i];
    }

    if (!dirempty && !IS_ADMIN(TI)) {
      write("You still have files left.\n");
      return 0;
    }
  }

  doecho = (name == getuid(TI) && wlvl);

  log_file(LOGREM, ctime()+": "+capitalize(getuid(TI))+" removes "
                   +(wlvl ? "wizard" : "player")
                   +" "+capitalize(name)+" ("
                   +(wlvl ? "w" : "")+wlvl+")\n"
          );

  write("Removing "+capitalize(name)+" from the game...\n");

  if (name != getuid(TI)) {
    object pl;
    if (pl = find_player(name)) {
      tell_object(pl, "=== Your being is no longer here ===\n");
      catch(pl->remove());
      if(pl)
        destruct(pl);
      if (doecho) write("  Destructed "+capitalize(name)+".\n");
      log_file(LOGREM, "  Destructed player.\n");
    }
  }

  /* Remove the mummification.
   */
  if (   file_size(MUMMYDIR+name) >=0 
      || file_size(MUMMYDIR+name+".o") >= 0
     ) {
    rc = rm(MUMMYDIR+name);
    if (rm(MUMMYDIR+name+".o")) rc = 1;
    tmp = "  "+MUMMYDIR+name+"[.o]"+(rc ? "" : " not")+" removed\n";
    log_file(LOGREM, tmp);
    if (doecho) write(tmp);
  }

  /* Remove the savefile. 
   */
  tmp = SAVEPATH+name[0..0]+"/"+name+".o";
  if (file_size(tmp) >= 0) {
    rc = rm(tmp);
    tmp = "  "+tmp+(rc ? "" : " not")+" removed\n";
  }
  else
    tmp = "  No savefile to remove.\n";
  log_file(LOGREM, tmp);
  if (doecho) write(tmp);

  /* Remove the secure/savefile. 
   */
  tmp = SECURESAVEPATH+name[0..0]+"/"+name+".o";
  if (file_size(tmp) >= 0) {
    rc = rm(tmp);
    tmp = "  "+tmp+(rc ? "" : " not")+" removed\n";
  }
  else
    tmp = "  No secure/savefile to remove.\n";
  log_file(LOGREM, tmp);
  if (doecho) write(tmp);

  /* Remove the mailfile.
   */
  tmp = MAILPATH+name[0..0]+"/"+name+".o";
  if (file_size(tmp) >= 0) {
    rc = rm(tmp);
    tmp = "  "+tmp+(rc ? "" : " not")+" removed\n";
  }
  else
    tmp = "  No mailfile to remove.\n";
  log_file(LOGREM, tmp);
  if (doecho) write(tmp);

  /* Remove the banishfile.
   */
  tmp = BANISHPATH+name+".o";
  if (file_size(tmp) >= 0) {
    rc = rm(tmp);
    tmp = "  "+tmp+(rc ? "" : " not")+" removed\n";
  }
  else
  {
    tmp = BANISHPATH+name;
    if (file_size(tmp) >= 0) {
      rc = rm(tmp);
      tmp = "  "+tmp+(rc ? "" : " not")+" removed\n";
    }
    else
      tmp = "  No banishfile to remove.\n";
  }
  log_file(LOGREM, tmp);
  if (doecho) write(tmp);

  /* Remove the newsfile.
   */
  tmp = "/log/news/"+name+".nrc.o";
  if (file_size(tmp) >= 0) {
    rc = rm(tmp);
    tmp = "  "+tmp+(rc ? "" : " not")+" removed\n";
  }
  else
    tmp = "  No newsfile to remove.\n";
  log_file(LOGREM, tmp);
  if (doecho) write(tmp);

  /* Remove all dotfiles from the homedirectory, then the directory itself.
   */
  if (wlvl && -2 == file_size(WPATH+name)) {
    dir -= ({ 0 });
    if (sizeof(dir))
      map(dir, #'rm);
    tmp = WPATH+name;
    rc = rmdir(tmp);
    tmp = "  "+tmp+"/"+(rc ? "" : " not")+" removed\n";
    log_file(LOGREM, tmp);
    if (doecho) write(tmp);
  }

  /* Try to remove an ftp-directory as well.
   */
  for (j = 0; j < 2; j++)
  {
    tmp = (j ? "/ftp/pub/" : "/ftp/wizards/")+name;
    if (file_size(tmp) == -2) {
      dir = get_dir(tmp+"/*") - ({ ".", ".." });
      for (i = sizeof(dir); i--; ) {
        if (dir[i])
          rm(tmp+"/"+dir[i]);
      }
      rc = rmdir(tmp);
      tmp = "  "+tmp+"/"+(rc ? "" : " not")+" removed\n";
      log_file(LOGREM, tmp);
      if (doecho) write(tmp);
    }
    else if (file_size(tmp) >= 0) {
      rc = rm(tmp);
      tmp = "  "+tmp+(rc ? "" : " not")+" removed\n";
      log_file(LOGREM, tmp);
      if (doecho) write(tmp);
    }
  }
  
  /* Remove some object savefiles
   */
  tmp2 = ({ "/d/hell/common/rover/looks/"+name+".o"
	  , "/d/hell/rover/obj/looks/"+name+".o"
	  , "/d/woodland/common/spellbooks/"+capitalize(name)+".o"
	  , "/d/woodland/common/spellbooks/REMOVED/"+capitalize(name)+".o"
	  , "/d/woodland/common/guilds/druids/save/"+name+".o"
	  , "/d/daydream/common/fanclub/fandata/"+capitalize(name)+".o"
	  , "/d/avalon/common/save/schilda/"+name+".o"
	  , "/d/drannor/common/guild/members/"+capitalize(name)+".o"
	  , "/d/shadows/common/guilds/vampires/"+capitalize(name)+".o"
	  , "/p/guilds/paladins/save/"+name+".o"
	  , "/p/guilds/druids/save/"+name+".o"
         });
  for (i = 0; i < sizeof(tmp2); i++)
  {
    tmp = tmp2[i]+name;
    if (file_size(tmp) >= 0) {
      rc = rm(tmp);
      tmp = "  "+tmp+(rc ? "" : " not")+" removed\n";
      log_file(LOGREM, tmp);
      if (doecho) write(tmp);
    }
  }
  
  /* Remove some houses
   */
  tmp2 = ({ "/d/archwiz/common/houses/"
	  , "/d/halfling/common/houses/"
	  , "/d/hell/common/room/bazaar/houses/"
	  , "/d/woodland/common/mandukam/houses/"
	  , "/d/woodland/common/beach/"
	  , "/d/daydream/common/houses/"
	  , "/d/avalon/common/village/houses/"
	  , "/d/avalon/common/viking/"
	  , "/d/atlantis/common/room/houses/base/"
	  , "/d/atlantis/common/room/houses/"
	  , "/d/orient/common/houses/"
	  , "/d/ireland/common/houses/"
         });
  for (i = 0; i < sizeof(tmp2); i++)
  {
    tmp = tmp2[i]+name;
    if (file_size(tmp) != -2)
      continue;
    dir = get_dir(tmp+"/*") - ({ ".", ".." });
    for (j = sizeof(dir); j--; ) {
      if (dir[j])
        rm(tmp+"/"+dir[j]);
    }
    rc = rmdir(tmp);
    tmp = "  "+tmp+"/"+(rc ? "" : " not")+" removed\n";
    log_file(LOGREM, tmp);
    if (doecho) write(tmp);
  }
  
  MASTER->expunge_userinfo(name);
  return 1;
}

/*------------------------------------------------------------------------
** Scan through all dirs SAVEPATH? and check the save-files in them
** with scan_files(). This implies chaining by call_outs.
** When done, continue scanning with scan_sdirs().
*/

protected void scan_dirs() {
  if (dirno >= sizeof(abc)) {
    dirno = 0;
    log_file (LOGFILE, "\n"+ctime(time())+": Checking " SECURESAVEPATH "\n");
    scan_sdirs();
    return;
  }
  bname = SAVEPATH+abc[dirno..dirno]+"/";
  files = get_dir (bname+abc[dirno..dirno]+"*", 7);
  base = 0;
  dirno++;
  scan_files();
}

/*------------------------------------------------------------------------
** Scan through all dirs SECURESAVEPATH? and check the save-files in them
** witch scan_sfiles(). This implies chaining by call_outs.
** When done, print out the statistics and terminate.
*/

protected void scan_sdirs() {
  if (dirno >= sizeof(abc)) {
    log_file(LOGFILE,
 "\n"+ctime(time())+": Done\n"
+"  Total     : "+ctotal+" files\t"+stotal+" bytes for "+(nrpl+nrnopl+nrsugg)
  +" characters\n"
+"  Player    : "+cpl+" files\t"+spl+" bytes for "+nrpl+" characters\n"
+"  NonWiz    : "+cnopl+" files\t"+snopl+" bytes for "+nrnopl+" characters\n"
+"  Bogus     : "+cbogus+" files\t"+sbogus+" bytes\n"
+"  Suggested : "+csugg+" files\t"+ssugg+" bytes for "+nrsugg+" characters\n\n"
               );
    if (csugg) log_file (LOGSUGG, "\n");
    destruct (TO);
    return;
  }
  bname = SECURESAVEPATH+abc[dirno..dirno]+"/";
  files = get_dir (bname+abc[dirno..dirno]+"*", 7);
  base = 0;
  dirno++;
  scan_sfiles();
}

/*------------------------------------------------------------------------
** Scan the files contained in *files, taken from the save-directory
** denoted by bname. The check is done in bunches of 20 files, chained
** by call_outs.
** The save-files are checked for validity and if the character is
** expired (wasn't logged in for long time). If yes, it is removed.
*/

protected void scan_files() {
  int bunch, i, j, k, rc, age, lvl, wlvl;
  string pname, *tmp2, *dir;
  mixed tmp;

    /* Do at max. 20 files == 60 entries */
  if ((bunch = sizeof(files) - base) > 60) bunch = 60;
  for (i = base; i < base+bunch; i+= 3) {
    age = (time() - files[i+2]) / ONEWEEK;
addmsg(sprintf("%s: file age %d\n", files[i], age));
    if (files[i+1] <= 0 || age <= 4) {
addmsg(sprintf("%*s  -> no file or younger than 4\n", sizeof(files[i]), ""));
      continue; /* Hyp */
    }
    pname = files[i][0..<3];

      /* If the savefile can't be read, denote it as 'bogus',
      ** but don't remove it (yet).
      */

    pLastSave = 0;
    experience = aXP = 0;
    level = aLevel = 0;
      
    if (catch (rc = restore_object (bname+pname)) || !rc) {
      if ( /* rc = rm(bname+files[i]) */ rc = 0, 1 ) {
        sbogus += files[i+1]; cbogus++;
        stotal += files[i+1]; ctotal++;
      }
      log_file (LOGFILE, 
                "  Bogus "+bname+files[i]+(rc ? "" : " not")+" removed\n"
		);
addmsg(sprintf("%*s  -> bogus\n", sizeof(files[i]), ""));
      continue;
    }
    if (!experience && aXP)
      experience = aXP;
    if (!level && aLevel)
      level = aLevel;

addmsg(sprintf("%*s  xp %d, level %d\n", sizeof(files[i]), "", experience, level));
    /* If the save-date is stored, use that instead of the file-date. */
    if (pLastSave)
    {
      age = (time() - pLastSave) / ONEWEEK;
addmsg(sprintf("%*s  read age %d\n", sizeof(files[i]), "", age));
      if (age <= 4)
      {
addmsg(sprintf("%*s  -> younger than 4\n", sizeof(files[i]), ""));
	continue;
      }
    }

      /* If this file is mummified (an /secure/mummy/<name>, opt. with .o,
      ** exists), don't do any further checking.
      */
    if (file_size (MUMMYDIR+pname) >=0 || file_size(MUMMYDIR+files[i]) >= 0)
    {
addmsg(sprintf("%*s  -> mummified\n", sizeof(files[i]), ""));
      continue;
    }

      /* Compare the allowed not-login-time according to the level
      ** of the character.
      */
    wlvl = query_user_level(pname);
    if (!wlvl && file_size (WDIR+"/"+pname) == -2) wlvl = 21;
    if (wlvl) lvl = LEVEL;
    else lvl = ({int})RACEMASTER->XPtoLevel (experience);
    if (lvl < 1)
      lvl = 1;

addmsg(sprintf("%*s  lvl %d, wlvl %d\n", sizeof(files[i]), "", lvl, wlvl));
      /* If the character is an absent archwiz or domainlord, suggest the
      ** the demotion.
      */
    if (wlvl < 60 && ((wlvl >= 35 && wlvl < 40) || (wlvl >= 45)) && age >= 15)
    {
      log_file(LOGSUGG,
               capitalize(pname)+": "+query_user_tag(pname)+", "+age
               +" weeks -- suggested for demotion.\n");
addmsg(sprintf("%*s = %s suggested for demotion.\n", sizeof(files[i]), "", query_user_tag(pname)));
      }
      
      /* If the character is an absent wizard, suggest the compressions
      ** of its directory.
      */
    if (wlvl >= LVL_WIZARD && (age >= 52) && (age <= 56)) {
      tmp = get_dir("/players/"+pname+"/*");
      if (   pointerp(tmp) 
          && sizeof(tmp-({".", "..", ".err", pname+".tar.gz", pname+".tar.z"}))
         )
        log_file (LOGSUGG, 
                  capitalize (pname)+" : wlvl "+wlvl+", "+age
                  +" weeks -- suggested for compression.\n");
addmsg(sprintf("%*s  = wizard suggested for compression\n", sizeof(files[i]), ""));
      continue;
    }

    if (lvl < LEVEL && age <= 1 + (lvl-1) * 6) 
    {
addmsg(sprintf("%*s  -> lvl < %d && age < %d\n", sizeof(files[i]), "", LEVEL, 1+(lvl-1)*6));
      continue;
    }
      
      /* If the character is an expired wizard/player, suggest its removal.
      */
    if (wlvl > LVL_PLAYER) {
      if (age <= 1 + (LEVEL-1) * 6)
      {
addmsg(sprintf("%*s  -> wizard and age < %d\n", sizeof(files[i]), "", 1+(LEVEL-1)*6));
	  continue;
      }
      log_file (LOGSUGG, 
                capitalize (pname)+" : wlvl "+wlvl+", "+age+" weeks.\n");
      ssugg += files[i+1]; csugg++;
      stotal += files[i+1]; ctotal++;
      nrsugg++;
addmsg(sprintf("%*s  = wizard suggested\n", sizeof(files[i]), ""));
      continue;
    }
    if (lvl >= LEVEL) {
      if (age <= 52)
      {
addmsg(sprintf("%*s  -> lvl > %d and age <= 52\n", sizeof(files[i]), "", LEVEL));
	  continue;
      }
      log_file (LOGSUGG, 
                capitalize (pname)+" :  lvl "+lvl+", "+age+" weeks.\n");
      ssugg += files[i+1]; csugg++;
      stotal += files[i+1]; ctotal++;
      nrsugg++;
addmsg(sprintf("%*s  = player suggested\n", sizeof(files[i]), ""));
      continue;
    }

addmsg(sprintf("%*s  = removed\n", sizeof(files[i]), ""));
      /* The character is an expired (super-)player.
      ** All of its possible files are now removed.
      */

      /* Remove the savefile. 
      */
    if (rc = rm (bname+files[i])) {
      if (wlvl) snopl += files[i+1], cnopl++, nrnopl++;
      else spl += files[i+1], cpl++, nrpl++;
      stotal += files[i+1]; ctotal++;
    }
    log_file (LOGFILE,
              "  "+bname+files[i]+" [lvl "+lvl+", "+age+" weeks]"
	      +(rc ? "" : " not")+" removed\n"
	      );

      /* Remove the secure/save-file. 
      */
    tmp = SECURESAVEPATH+files[i][0..0]+"/"+files[i];
    if (file_size(tmp) > 0) {
      if (rc = rm (tmp)) {
        if (wlvl) snopl += files[i+1], cnopl++;
        else spl += files[i+1], cpl++;
        stotal += files[i+1]; ctotal++;
      }
      log_file (LOGFILE, 
                "    "+tmp+(rc ? "" : " not")+" removed\n"
		);
    }
    else
      log_file (LOGFILE, "  No "+tmp+"\n");

      /* Remove the mailfile. 
      */
    if (file_size(MAILPATH+files[i][0..0]+"/"+files[i]) >= 0) {
      if (rc = rm (MAILPATH+files[i][0..0]+"/"+files[i])) {
        if (wlvl) snopl += files[i+1], cnopl++;
        else spl += files[i+1], cpl++;
        stotal += files[i+1]; ctotal++;
      }
      log_file (LOGFILE, 
                "    "+MAILPATH+files[i][0..0]+"/"+files[i]
                +(rc ? "" : " not")+" removed\n"
		);
    }

      /* Remove a newsmatrix-file.
      */
    tmp = "/log/news/"+files[i][0..<2]+"nrc.o";
    if (file_size(tmp) >= 0) {
      if (rc = rm (tmp)) {
        if (wlvl) snopl += files[i+1], cnopl++;
        else spl += files[i+1], cpl++;
        stotal += files[i+1]; ctotal++;
      }
      log_file (LOGFILE, "    "+tmp+(rc ? "" : " not")+" removed\n");
    }
 
    /* Remove some object savefiles
     */
    tmp2 = ({ "/d/hell/common/rover/looks/"+pname+".o"
            , "/d/hell/rover/obj/looks/"+pname+".o"
            , "/d/woodland/common/spellbooks/"+capitalize(pname)+".o"
            , "/d/woodland/common/spellbooks/REMOVED/"+capitalize(pname)+".o"
            , "/d/woodland/common/guilds/druids/save/"+pname+".o"
            , "/d/daydream/common/fanclub/fandata/"+capitalize(pname)+".o"
            , "/d/avalon/common/save/schilda/"+pname+".o"
            , "/d/drannor/common/guild/members/"+capitalize(pname)+".o"
            , "/d/shadows/common/guilds/vampires/"+capitalize(pname)+".o"
            , "/p/guilds/paladins/save/"+pname+".o"
            , "/p/guilds/druids/save/"+pname+".o"
           });
    for (j = 0; j < sizeof(tmp2); j++)
    {
      tmp = tmp2[j];
      if (file_size(tmp) >= 0) {
        rc = rm(tmp);
        tmp = "    "+tmp+(rc ? "" : " not")+" removed\n";
        log_file(LOGFILE, tmp);
      }
    }
  
    /* Remove some houses
     */
    tmp2 = ({ "/d/archwiz/common/houses/"
            , "/d/halfling/common/houses/"
            , "/d/hell/common/room/bazaar/houses/"
            , "/d/woodland/common/mandukam/houses/"
            , "/d/woodland/common/beach/"
            , "/d/daydream/common/houses/"
            , "/d/avalon/common/village/houses/"
            , "/d/avalon/common/viking/"
            , "/d/atlantis/common/room/houses/base/"
            , "/d/atlantis/common/room/houses/"
            , "/d/orient/common/houses/"
            , "/d/ireland/common/houses/"
           });
    for (j = 0; j < sizeof(tmp2); j++)
    {
      tmp = tmp2[j]+pname;
      if (file_size(tmp) != -2)
      {
        continue;
      }
      dir = get_dir(tmp+"/*") - ({ ".", ".." });
      for (k = sizeof(dir); k--; ) {
        if (dir[k])
          rm(tmp+"/"+dir[k]);
      }
      rc = rmdir(tmp);
      tmp = "    "+tmp+"/"+(rc ? "" : " not")+" removed\n";
      log_file(LOGFILE, tmp);
    }
  
      /* Suggest any ftp-directory for removal.
      */
    if (file_size("/ftp/public/"+pname) != -1) {
      csugg++; ctotal++;
      log_file (LOGSUGG, "/ftp/public/"+pname+" : Player removed.\n");
    }
  } /* for */

writemsg();
    /* Chain the next operation: next bunch of files
    ** or next directory.
    */
  base += bunch;
  if (base >= sizeof(files)) call_out (#'scan_dirs, DELAY);
  else call_out (#'scan_files, DELAY);
}

/*------------------------------------------------------------------------
** Scan the files contained in *files, taken from the 
** secure/save-directory denoted by bname. 
** The check is done in bunches of 20 files, chained by call_outs.
** This functions just checks the files for validity and that they
** have a matching save-file).
*/

protected void scan_sfiles() {
  int bunch, i, rc;
  string pname;

    /* Do at max. 20 files == 60 entries */
  if ((bunch = sizeof(files) - base) > 60) bunch = 60;
  for (i = base; i < base+bunch; i+= 3) {
    pname = files[i][0..<3];

      /* If the savefile can't be read, denote it as 'bogus',
      ** but don't remove it (yet).
      */
    bRemoved = 0;
    if (catch (rc = restore_object (bname+pname)) || !rc) {
      if ( /* rc = rm(bname+files[i]) */ rc = 0, 1 ) {
        sbogus += files[i+1]; cbogus++;
        stotal += files[i+1]; ctotal++;
      }
      log_file (LOGFILE, 
                "  Bogus "+bname+files[i]+(rc ? "" : " not")+" removed\n"
               );
      continue;
    }

      /* Don't check mummified/removed characters any further. */
    if (   file_size (MUMMYDIR+pname) >=0 
	|| file_size(MUMMYDIR+files[i]) >= 0
	|| bRemoved
	)
      continue;

      /* Check if the matching save-file exists. */
    if (file_size (SAVEPATH+pname[0..0]+"/"+files[i]) >= 0)
      continue;

    rc = rm(bname+files[i]);
    log_file(LOGFILE, "  "+bname+files[i]+" with no matching /save-file:"
                      +(rc ? "" : " not")+" removed\n");
    if (!rc)
    {
      log_file (LOGSUGG, bname+files[i]+" : No matching /save-file found.\n");
      ssugg += files[i+1]; csugg++;
    }
    stotal += files[i+1]; ctotal++;
  } /* for */

    /* Chain the next operation: next bunch of files
    ** or next directory.
    */
  base += bunch;
  if (base >= sizeof(files)) call_out (#'scan_sdirs, DELAY);
  else call_out (#'scan_sfiles, DELAY);
}

/*========================================================================*/

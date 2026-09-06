/*--------------------------------------------------------------------------
 * /p/daemons/toplist_d.c  --  The toplist daemon
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
* [Softbyte] 11aug98: Changed pathnames to save/daemons
 *--------------------------------------------------------------------------
 * The toplist object can be cloned from /obj/toplist.c
 */

#include <secure/wizlevels.h>
#include <daemons.h>
#include <properties.h>

inherit "/lib/string";

#define QP_LIST   "/save/daemons/toplist.qp"
#define AGE_LIST  "/save/daemons/toplist.age"
#define SAVEFILE  "/save/daemons/toplist"
#define DELAY 20

#define PO previous_object()
#define TO this_object()

#define ONEDAY (86400-1800)

int last_run;

nosave int dirno;
nosave string abc = "abcdefghijklmnopqrstuvwxyz";
nosave mixed *files;
nosave string bname;
nosave int base;
nosave int step;
nosave mixed *qp_list;
nosave mixed *age_list;

public void start_dragon();  /* Forward Declaration */
protected void scan_dirs();
protected void scan_files();
private void gen_top_list();
private void insert_player(string name, int qp, int xp, int age, int level, int expl);

string QueryAgeFile() {return AGE_LIST;}
string QueryQPFile() {return QP_LIST;}

void create() {
  seteuid(getuid());

  if (clonep()) {
    destruct (TO);
  }
}

public void start_dragon()
{
  int i;

  restore_object(SAVEFILE);
  if (last_run + ONEDAY > time()) {
    destruct (TO);
    return;
  }

  dirno = 0;
  qp_list = allocate(21);
  age_list = allocate (21);

  for (i=0;i<21;i++) {
    qp_list[i]  = ({"",0,0,0,0,0});
    age_list[i] = ({"",0});
  }

  call_out(#'scan_dirs /*'*/, 5);
}

protected void scan_dirs() {
  if (dirno >= sizeof(abc))
  {  gen_top_list();
     last_run = time();
     save_object(SAVEFILE);
     destruct(TO);
     return;
  }
  bname = SAVEPATH+abc[dirno..dirno]+"/";
  files = get_dir (bname+abc[dirno..dirno]+"*");
  base = 0;
  dirno++;
  scan_files();
}

protected void scan_files() {
  int bunch, i;
  string pname;
  mapping data;

  if ((bunch = sizeof(files) - base) > 10) bunch = 10;

  for (i = base; i < base+bunch; i++) {
    if (files[i][<2..] != ".o") continue;
    pname = explode(files[i],".")[0];

  /* Check if it's a player or wizard */
    if (IS_WIZARD(pname)) continue;

  /* Check if it's a testplayer */
    if (({mixed})TESTY_D->CheckTesty(pname)) continue;

    if ( data = ({mapping})"/obj/player_dummy"->QueryProperties( pname ) )
      insert_player( pname,
                     ({int})QUEST_D->QueryQuestPoints(pname),
                     data[P_XP],
                     data[P_AGE],
                     data[P_LEVEL],
                     ({int})EXPLORER_D->CountBits(data[P_EXPLORED]) );
  }

  base += bunch;
  if (base >= sizeof(files)) call_out (#'scan_dirs, DELAY);
  else call_out (#'scan_files, DELAY);
}

private void insert_player(string name, int qp, int xp, int age, int level, int expl) {
  int   i,mark;
  mixed dummy;

  for (i=19;i>-1;i--)
    if (qp_list[i][1] > qp || (qp_list[i][1] == qp && qp_list[i][2] >= xp))
      break;
  i++;
  if (i<20) {
    mark = i;
    qp_list[20] = ({name,qp,xp,age,level,expl});
    for (i=20;i>mark;i--) {
      dummy        = qp_list[i-1];
      qp_list[i-1] = qp_list[i];
      qp_list[i]   = dummy;
    }
  }

  for (i=19;i>-1;i--)
    if (age_list[i][1] > age)
      break;
  i++;
  if (i<20) {
    mark = i;
    age_list[20] = ({name,age});
    for (i=20;i>mark;i--) {
      dummy        = age_list[i-1];
      age_list[i-1] = age_list[i];
      age_list[i]   = dummy;
    }
  }
}

/* Generate the two toplists */
private void gen_top_list() {
  int i;

  rm (QP_LIST);
  rm (AGE_LIST);

  write_file(QP_LIST,"ONE STEP BEYOND'S HALL OF FAME  " + ctime(time()) +
                     "\n\
            (sponsored by Rover)\n\n\
     Rank Name            QP      XP    expl  Hours  Level\n\
     -----------------------------------------------------\n");

  for (i=0;i<20;i++)
    write_file(QP_LIST,"     " +
               radjust(to_string(i+1),3) + "  " +
               ladjust(capitalize(qp_list[i][0]),11) + " : " +
               radjust(to_string(qp_list[i][1]),4) +
               radjust(to_string(qp_list[i][2]),11) +
               radjust(to_string(qp_list[i][5]),5) +
               radjust(to_string(qp_list[i][3]/1800),7) +
               radjust(to_string(qp_list[i][4]),6) + "\n"
              );

  write_file(AGE_LIST,"LIST OF VETERANS  " + ctime(time()) +
                      "\n\
          (sponsored by Rover)\n\n\
        Rank Name           Hours\n\
        --------------------------\n");

  for (i=0;i<20;i++)
    write_file(AGE_LIST,"        " +
               radjust(to_string(i+1),3) + "  " +
               ladjust(capitalize(age_list[i][0]),12) + " : " +
               radjust(to_string(age_list[i][1]/1800),5) + "\n"
              );
}

//----------------------------------------------------------------------------
// Title:						Author:
//	Monk's soul command system.					Sauron.
//
// File:						Started:
//	/players/sauron/guild/soul/soul_cmd.h				141096.
//
// Purpose:
//	This file contains the guild soul's command handling funs.
//
// History of revisions/fixes:
//
// 141096: Sauron: Started programming.
//
//----------------------------------------------------------------------------

#ifndef __SOUL_CMD_H__

#define __SOUL_CMD_H__

// Preprocessor directives:

#include "/players/sauron/guild/soul/soul_basic.h"

// End preprocessor directives.


// Prototypes:

int _activate(string str);
varargs int execute_cmd(string file,string str,string cmd,object tp,int flag);
int execute_skill_init(string file,string verb,string str,object tp);
int execute_skill(string file,string verb,string str,object tp);
int do_cmd(string str);

// End prototypes.


int _activate(string str) {
  if(!str || !id(str)) {
    notify_fail("Activate what?\n");
    return 0;
  }
  if(first_inventory(query_tmp("owner"))!=TO) {
    MOVE(TO,query_tmp("owner"));
    printf("%s activated.\n",CAP(str));
  }
  return 1;
}

varargs int execute_cmd(string file,string str,string cmd,object tp,
                        int flag) {
  string err;
  int ret;

  if((err=catch((ret=(int)file->main(str))))) {
    WRITE(sprintf("The command '%s' could not be completed as the module \
'%s' is bugged...\n",cmd,file));
    if(APPR(tp))
      printf("\n%s\n",err);
    if(!flag)
      guild_log_file("bugged.cmd",
                     sprintf("Module '%s' gave the following error with the \
command '%s':\n%s\n\n",file,cmd,err));
    return 1;	// Cmd was found, but buggy.
  }
  else
    return ret;
}

int execute_skill_init(string file,string verb,string str,object tp) {
  string err,*cmd;
  int ret;

  cmd=query_tmp("doing_cmd");

  if((err=catch((ret=(int)file->init_check(tp,verb,str))))) {
    WRITE(sprintf("The command '%s' could not be completed as the \
module '%s' is bugged...\n",cmd[0],file));
    if(APPR(tp))
      printf("\n%s\n",err);
    guild_log_file("bugged.skill",
                   sprintf("Skill '%s' gave the following error with \
the command '%s':\n%s\n\n",file,cmd[1],err));
    return 0;	// Act as if tp failed the check.
  }
  else
    return ret;
}

int execute_skill(string file,string verb,string str,object tp) {
  string err,*cmd;
  int ret;

  cmd=query_tmp("doing_cmd");
  unset_tmp("doing_cmd");

  if((err=catch((ret=(int)file->main(tp,verb,str))))) {
    WRITE(sprintf("The command '%s' could not be completed as the module \
'%s' is bugged...\n",cmd[0],file));
    if(APPR(tp))
      printf("%s\n",err);
    guild_log_file("bugged.skill",
                   sprintf("Skill '%s' gave the following error with the \
command '%s':\n%s\n\n",file,cmd[1],err));
    return 1;	// Skill was found, but buggy.
  }

  else
    return ret;
}

int do_cmd(string str) {
  string verb,file,orig_cmd,new_cmd,err,pbin;
  int time,sz,ret;
  object tp;
  mixed *tmp;

  if(!(tp=query_tmp("owner")) || tp!=TP) {
    write("do_cmd() failed...");
    if(tp)
      write("\"owner\" = "+tp);
    write("\n");
    return 0;
  }

  check_guild_shadow();		// Just to be on the safe side.

  verb=VERB;
  orig_cmd=verb+(str?" "+str:"");

  if(verb[0..0]=="'" || member(verb,'.')!=-1)
    return 0;

  tmp=soul_alias(verb,str,tp);
  verb=tmp[0];
  str=tmp[1];

  new_cmd=verb+(str?" "+str:"");

  if(pbin=(string)query("personal_bin") && APPR(tp)) {
    if(pbin[<1..<1]!="/")
      pbin+="/";
    if(file_size(pbin+verb+".lpc")>0)
      return execute_cmd(pbin+verb,str,orig_cmd,tp,1);
  }

  else if((file=valid_guild_command(verb,tp)))
    return execute_cmd(file,str,orig_cmd,tp);

  else if((file=valid_guild_skill_cmd(verb,TP))) {
    if(!query_tmp("doing_cmd")) {
      time=(int)G_SM->query_cmd_info(verb,CMD_TIME);
      set_tmp("doing_cmd",({orig_cmd,new_cmd}));
      if(!time)
        return execute_skill(file,verb,str,tp);
      else {
        if(!execute_skill_init(pbin+verb,verb,str,tp)) {
          unset_tmp("doing_cmd");
          return 1;
        }
        else {
          call_out("execute_skill",time,file,verb,str,tp);
          return 1;
        }
      }
    }
    else {
#ifdef SKILL_BUSY_MSG
      WRITE(sprintf("Be patient. You are already executing the command \
'%s'...\n",query_tmp("doing_cmd")[0]));
#endif
      return 1;
    }
  }

  else
    return 0;
}

#endif // __SOUL_CMD_H__

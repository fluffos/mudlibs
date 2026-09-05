#ifndef  _DEF_H_
#define  _DEF_H_


/***************************************************
 *************** BEGIN VOTE SETTINGS ***************
 ***************************************************/

#define MANAGER               "dune"
#define MAX_VOTES             20
#define MIN_CDAYS              1
#define MAX_CDAYS             30

#define MAX_VOTENAME_LENGTH   40
#define VOTE_SEP_SIZE         20
#define VOTE_SEP              "####################"
#define CHOICE_SEP            "/"

#define INDEX_VOTENAME 0
#define INDEX_OWNER    1
#define INDEX_CHOICES  2
#define INDEX_CDAYS    3
#define INDEX_PUB      4
#define INDEX_DESC     5

/***************************************************
 *************** END VOTE SETTINGS *****************
 ***************************************************/


#include "/obj/ansi.h"


/***************************************************
 ************ BEGIN GENERAL DEFINITIONS ************
 ***************************************************/

/* Directories */
#define ROOTPATH "/obj/voting"
#define SAVEROOT  "obj/voting"
#define SAVEPATH       SAVEROOT+"/votes"
#define LIB_CMDS       ROOTPATH+"/cmds/"
#define VOTEDIR        ROOTPATH+"/votes"
#define SVOTEDIR       ROOTPATH+"/votes_secret"
#define LOGDIR         ROOTPATH+"/logs"

/* Objects and misc. */
#define VOTED          ROOTPATH+"/votedaem.lpc"
#define VOTERS         ROOTPATH+"/VOTERS.h"
#define MORED          ROOTPATH+"/moredaem.lpc"
#define VOTEHELP       ROOTPATH+"/votehelp.txt"
#define LINE "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"

/* Macros */
#define TP     this_player()
#define ETO    environment(this_object())
#define ETN    capitalize((string)ETO->query_name())
#define TPN    capitalize((string)TP->query_name())
#define OPN    capitalize((string)ob->query_name())
#define TRN    capitalize((string)TP->query_real_name())
#define ORN    capitalize((string)ob->query_real_name())
#define POS    query_possessive()

/***************************************************
 ************ END GENERAL DEFINITIONS **************
 ***************************************************/


#endif

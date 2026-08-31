/*
 *  Header file for Count
 *
 *  RCS:
*      $Revision: 2.3 $
 *      $Date: 1996/05/03 02:20:22 $
 *
 *  Security:
 *      Unclassified
 *
 *  Description:
 *      text
 *
 *  Input Parameters:
 *      type    identifier  description
 *
 *      text
 *
 *  Output Parameters:
 *      type    identifier  description
 *
 *      text
 *
 *  Return Values:
 *      value   description
 *
 *  Side Effects:
 *      text
 *
 *  Limitations and Comments:
 *      text
 *
 *  Development History:
 *      who                 when        why
 *      muquit@semcor.com   05-Jun-95   first cut
 */

#ifndef _COUNT_H
#define _COUNT_H

#include <stdio.h>

#if STDC_HEADERS || HAVE_STRING_H
#include <string.h> /* ANSI string.h and pre-ANSI memory.h might conflict*/
#if !STDC_HEADERS && HAVE_MEMORY_H
#include <memory.h>
#endif
#else
#if  HAVE_STRINGS_H
#include <strings.h>
#endif
#endif

#if HAVE_STDLIB_H 
#include <stdlib.h>
#endif

#if HAVE_CTYPE_H
#include <ctype.h>
#endif

#if HAVE_SYS_WAIT_H
#include <sys/wait.h>
#endif

#if SYS_UNIX
#include <sys/stat.h>
#endif

#ifdef SYS_WIN32
#include <io.h>
#include <share.h>
#endif

#if HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif

#if HAVE_UNISTD_H
#include <sys/types.h>
#include <unistd.h>
#endif

#if HAVE_FCNTL_H
#ifndef O_RDONLY    /* prevent multiple inclusion on lame systems (from vile)*/
#include <fcntl.h>
#endif
#endif

#if HAVE_MALLOC_H
#include <malloc.h>
#endif


#ifdef HAVE_SYS_FILE_H
#include <sys/file.h>
#endif

#if TIME_WITH_SYS_TIME
#include <sys/time.h>
#include <time.h>
#else
#if HAVE_SYS_TIME_H
#include <sys/time.h>
#else
#include <time.h>
#endif
#endif

#ifndef F_OK
#define F_OK    0
#endif

#ifndef True
#define True 1
#endif

#ifndef False
#define False 0
#endif

#define LF  10
#define SHOW_COUNTER    1
#define SHOW_CLOCK      2
#define SHOW_DATE       3
#define SHOW_GIF_FILE   4


#define DATE_MMDDYY     1
#define DATE_DDMMYY     2
#define DATE_YYMMDD     3
#define DATE_YYDDMM     4
#define DATE_MMYYDD     5
#define DATE_DDYYMM     6

#if __STDC__ || defined(sgi) || defined(_AIX)
#define _Declare(formal_parameters) formal_parameters
#else
#define _Declare(formal_parameters) ()
#define const
#endif

#ifdef Extern
#undef Extern
#endif

#ifndef __Main__
#define Extern extern
#else
#define Extern
#endif

#define Version "2.3"
#define Author          "muquit@semcor.com"
#define Url             "http://www.semcor.com/~muquit/Count.html"


#define MaxTextLength 2048

/*
** Maximum number of sites to ignore
*/
#define MaxSites    100

/*
** ErrorCodes
*/
#define ConfigOpenFailed        100
#define NoIgnoreHostsBlock      101
#define UnpexpectedEof          102
#define NoRefhBlock             103
#define NoAccessList            104
#define IncompleteAccessList    105
#define NoAutofcBlock           106
#define NoStrictBlock           107
#define NoRgbMappingBlock       108

#define NoLoginName             200
#define NoDatafile              201

/*
** global variables
*/

    Extern char 
        *GrefererHost[MaxSites+1],
        *GignoreSite[MaxSites+1];

    Extern int
        Grhost,
        Gsite;
    Extern unsigned int
        Gdebug;
    Extern int
        Gauto_file_creation,
        Gstrict_mode,
        GrgbMappingIsError;
     
/*
** maxumim line length in authorization file
*/
#define MaxLineLength 2048


#if MISSING_EXTERN_GETENV
extern char *getenv _Declare ((const char *));
#endif

#if MISSING_EXTERN_ATOI
extern int atoi _Declare ((char *));
#endif

#if MISSING_EXTERN_SRAND
extern void srand _Declare ((int));
#endif

#if MISSING_EXTERN_RAND
extern int rand _Declare ((void));
#endif

#if MISSING_EXTERN_ISDIGIT
extern int isdigit _Declare ((int));
#endif

#if MISSING_EXTERN_FLOCK
extern int flock _Declare ((int,int));
#endif

void DisplayCounter _Declare ((void));
int checkfilename _Declare ((char *));
int CheckFile _Declare ((char *));
void SendErrorImage _Declare ((unsigned char *, int));
char *mystrdup _Declare ((char *));
char *mystrtok _Declare ((char *,char *));
int mystrcasecmp _Declare ((char *,char *));
int GetLine _Declare ((FILE *, char *));
void RemoveTrailingSp _Declare ((char *));
int ParseConfig _Declare ((void));
int CheckOwner _Declare ((char *, char *));
int ParseQueryString _Declare ((char *, DigitInfo *, FrameInfo *));
int ParseInteger _Declare ((char *,int *,int,int));
int ParseDigitString _Declare ((char *,char *,int));
int ParseOptionString _Declare ((char *,int *));
int ParseLiteralString _Declare ((char *,char *,int));
int ParseDateFormat _Declare ((char *,int *));
int ParseBool _Declare ((char *,int *));
int ParseRGB _Declare ((char *,unsigned char *,unsigned char *,
        unsigned char *));
int ParseSize _Declare ((char *,int *, int *));
int ParseError _Declare ((char *,char *,int,char *));
void Warning _Declare ((char *));
char *GetTime _Declare ((void));
void PrintHeader _Declare ((void));
void WriteCounterImage _Declare ((char *,DigitInfo *, FrameInfo *));
void MogrifyImage _Declare ((Image **,DigitInfo *,FrameInfo *));
void GetRemoteReferer _Declare ((char *, char *));
void SetLock _Declare ((int));
void UnsetLock _Declare ((int));
int CheckDirs _Declare ((void));
void StringImage _Declare ((char *));
unsigned int CheckRemoteIP _Declare ((char *, char *));
void Commaize _Declare ((char *));

time_t netMktime _Declare ((struct tm *));
time_t checkTimezone _Declare ((char *));


#endif /* _COUNT_H */

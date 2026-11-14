/* SilberLand MUDlib
 *
 * /secure/questmaster.h -- header file for questmaster object
 *
 * $Date: 1997/07/02 09:50:48 $
 * $Revision: 1.23 $
 * $Log: questmaster.h,v $
 * Revision 1.23  1997/07/02 09:50:48  Woody
 * QGROUP_3 raus
 *
 * Revision 1.22  1997/06/12 12:25:35  Woody
 * QP_MIN formhalber auskommentiert
 *
 * Revision 1.21  1997/03/24 21:17:40  Woody
 * XP_NEEDED_FOR_WIZ wieder auf 1 Mio. gesetzt
 *
 * Revision 1.20  1997/03/15 23:41:06  Woody
 * prepared for revision control
 *
 * Revision 1.12d QP_MIN == 75, Woody, 25.2.97
 * Revision 1.12c QP_MIN == 50, XP_NEEDED...=500,000, Woody
 * Revision 1.12b QP_MIN == 5, Woody
 * Revision 1.12a QP_MIN == 48, Mupfel
 *
 * Revision 1.12  1995/05/22  19:34:21  Kirk
 * Added QP_MIN == 1196
 *
 * Revision 1.11  1995/05/22  18:53:39  Kirk
 * QDONTNEED removed
 *
 * Revision 1.10  1995/04/19  20:31:33  Kirk
 * QDONTNEED changed
 *
 * Revision 1.9  1995/03/30  13:47:00  Kirk
 * *** empty log message ***
 *
 * Revision 1.8  1994/12/17  08:54:49  Kirk
 * *** empty log message ***
 *
 * Revision 1.7  1994/10/07  14:50:06  Kirk
 * added new #define XP_NEEDED_FOR_WIZ
 *
 * Revision 1.6  1994/09/26  13:23:46  Kirk
 * *** empty log message ***
 *
 * Revision 1.5  1994/06/29  07:20:59  Rumata
 * added QGROUPS
 *
 * Revision 1.4  1994/06/13  22:45:50  Kirk
 * added defines for questgroups
 *
 * Revision 1.3  1994/05/16  09:21:29  Kirk
 * changed location of logfile to /log
 *
 * Revision 1.2  1994/03/01  22:20:24  Kirk
 * added logging
 *
 * Revision 1.1  1994/02/28  21:34:37  Kirk
 * Initial revision
 *
 * 
 */

#ifndef __QUESTMASTER_H__
#define __QUESTMASTER_H__

//XP threshold  
#define XP_NEEDED_FOR_WIZ 1000000

// the questmaster
#define QM         "/secure/questmaster"

// the quests file
#define QUESTS     "/secure/ARCH/quests"

// percentage of max_QP which is needed to become wizard
#define QP_PERCENT 80

// minimum of QP to become Seer or Wizzard
// --- Note: Not needed anymore! The questmaster does it... (Woody, 12 Jun 97)
// #define QP_MIN 75

// log to file
#define QMLOG(x) write_file("/log/QUESTMASTER",ctime(time())+": "+\
geteuid(this_interactive())+" -> "+ x +"\n")

// quest groups
#define QGROUP_1 8
#define QGROUP_2 15
#define QGROUP_3 20
// alte werte fuer QGROUP_1 und _2 = 35 bzw 70
// #define QGROUP_3 100
#define QGROUPS ({ 1, QGROUP_1, QGROUP_2, QGROUP_3 })

#define OK              1
#define GQ_ALREADY_SET -1
#define GQ_KEY_INVALID -2
#define GQ_ILLEGAL_OBJ -3
#define GQ_IS_INACTIVE -4
#define DQ_NOT_SET     -1
#define DQ_KEY_INVALID -2
#define DQ_ILLEGAL_OBJ -3
#define QQ_GUEST       2
#define QQ_KEY_INVALID 0

#define ERRNO_2_STRING(x,y) (["GQ1" : "Ok.",\
			      "GQ-1": "Die Quest ist bereits gelöst worden.",\
			      "GQ-2": "Ungültiger Questname.",\
			      "GQ-3": "Unbefugter Zugriff.",\
			      "GQ-4": "Die Quest ist derzeit inaktiv.",\
			      "DQ1" : "Ok.",\
			      "DQ-1": "Die Quest war nicht gesetzt.",\
			      "DQ-2": "Ungültiger Questname.",\
			      "DQ-3": "Unbefugter Zugriff.",\
			      "QQ1" : "Ok.",\
                              "QQ2" : "Gäste können keine Quest lösen.",\
			      "QQ0" : "Ungültiger Questname.",\
			      ])[x+y]

#endif /* __QUESTMASTER_H__ */

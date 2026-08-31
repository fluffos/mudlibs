/*
   mudlib: Basis
   created: 1992/07/26
   file: log.h
   purpose: to be included by objects wishing to write to a logfile in LOG_DIR
*/

#ifndef _LOG_H
#define _LOG_H

#define log(which, msg) write_file(LOG_DIR + which, msg)

#define ENTER "/enter"

#endif

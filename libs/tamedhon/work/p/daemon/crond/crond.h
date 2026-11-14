/*
 *  crond.h  -  Deklarationsdatei fuer cron-daemon 
 *
 * (c) 1998-2000 MUD Silberland - Adrian Holzwarth / Anatol@Silberland
 * 
 * Die Dokumentation zum CRON-DAEMON sowie allgemeine Hinweise zur 
 * Erstellung einer CRONTAB befinden sich in /p/daemon/crond/doku.txt.
 *
 * 2000-11-15 Revision 1.1    CRON ist ins crond-Verzeichnis gerutscht.
 */

#ifndef _CRON_H_
#define _CRON_H_

#define CRON                     "/p/daemon/crond/crond"
#define UPDATECRONTAB(x)         (CRON->UpdateCrontab(x))
#define REMOVECRONTAB(x)         (CRON->RemoveCrontab(x))
#define PRINTCRONTABS(x)         (CRON->PrintCrontabs(x))
#define PO_IS_CRON               (object_name(previous_object())==CRON)
#define CRON_ONLY                if (!PO_IS_CRON) return

#endif


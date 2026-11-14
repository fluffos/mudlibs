// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /sys/notify_fail.h
// Description: Konstanten fuer notify_fail
// Author:      Sissi & Gnomi
//
// $Log: notify_fail.h,v $
// Revision 1.1  2001/07/13 00:33:39  gnomi
// Prioritaeten fuer notify_fail.
//

#ifndef NOTIFY_FAIL_H
#define NOTIFY_FAIL_H

#define FAIL_NOT_CMD   (-1) /* Das Objekt definiert das betreffende
                             * Kommando nicht.
                             * Beispiel: "ziehe brot an"
                             */
#define FAIL_NOT_OBJ   ( 0) /* Das Objekt definiert das betr. Kommando,
                             * ist aber offensichtlich nicht gemeint.
                             * (Voreinstellung)
                             * Beispiel: "trink tee" wenn das Objekt ein Glas
                             *           Wasser ist
                             */
#define FAIL_WRONG_ARG ( 1) /* Das Objekt definiert das betr. Kommando,
                             * koennte auch gemeint sein, die Argumente
                             * stimmen aber nicht.
                             * Beispiel: "schliesse tuer mit brot auf"
                             */
#define FAIL_INTERNAL  ( 2) /* Die Syntax der Argumente stimmt, aber aus
                             * internen Gruenden funktioniert das Kommando
                             * nicht.
                             * Beispiel: "schliess tuer mit schluessel auf",
                             *           die Tuer ist aber gar nicht zu.
                             */

#endif
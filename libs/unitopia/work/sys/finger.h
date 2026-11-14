// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/finger.h
// Description:	Defines fuer den Finger - Befehl
// Author:	Sissi, 14. Mai 2001
//
// $Log: finger.h,v $
// Revision 1.2  2001/10/10 22:57:48  sissi
// Von aussen aus darf man den Fingertext auch sehen.
//
// Revision 1.1  2001/05/27 21:24:00  sissi
// Finger.h hinzugefuegt fuer Finger - Flag - Defines
//
//

#ifndef FINGER_H
#define FINGER_H 1

#define FINGER_OB "/secure/udp/finger"

// Fingerflags
#define FINGER_FLAG_VALID 1

// Fingerflags, wenn man selbst angefingert wird
#define FINGER_FLAG_OWN_TOWN 2
#define FINGER_FLAG_OWN_DATE 4
#define FINGER_FLAG_OWN_TIME 8
#define FINGER_FLAG_OWN_BIRTHDAY 16

#define FINGER_FLAG_OWN_DEFAULT (FINGER_FLAG_VALID | FINGER_FLAG_OWN_DATE)

// Fingerflags beim Anfingern von anderen
#define FINGER_FLAG_OTHER_TEXT 2
#define FINGER_FLAG_OTHER_PLAN 4
#define FINGER_FLAG_OTHER_CURRICULUM_VITAE 8
#define FINGER_FLAG_OTHER_APPRECIATIONS 16
#define FINGER_FLAG_OTHER_APPRECIATIONS_SORT_BY_DATE 32

#define FINGER_FLAG_OTHER_DEFAULT (FINGER_FLAG_VALID | \
    FINGER_FLAG_OTHER_TEXT | FINGER_FLAG_OTHER_PLAN | \
    FINGER_FLAG_OTHER_APPRECIATIONS | \
    FINGER_FLAG_OTHER_APPRECIATIONS_SORT_BY_DATE)

#define FINGER_FLAG_OTHER_EXTERN (FINGER_FLAG_VALID | FINGER_FLAG_OTHER_TEXT)
#define FINGER_FLAG_OTHER_LOGIN FINGER_FLAG_VALID


#endif // FINGER_H

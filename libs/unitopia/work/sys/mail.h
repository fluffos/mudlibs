// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /sys/mail.h
// Description: Headerfile fuer Post
// Author:      Freaky	(16.01.93)
// Modified by:	Garthan	(04.05.95)	neue Mailstruktur, Mailaliases,...
//		Freaky  (12.04.96)	Internet Mailer
//
// $Log: mail.h,v $
// Revision 1.5  2013/12/01 12:40:36  gnomi
// Maximale Postfachgroesse erhoeht.
//
// Revision 1.4  2005/11/12 18:43:38  gnomi
// Header von Internet-Mails speichern.
//
// Revision 1.3  2002/01/13 06:54:03  gnomi
// Defines zur Unterscheidung systemweiter und privater Aliase.
//
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef MAIL_H
#define MAIL_H 1

// Der Mail-Deamon
#define MAILD "/apps/maild"

// UDP Mailer
#define UDP_MAILD "/secure/udp/udp_mail"

// Internet Mailer
#define INTERNET_MAILD "/apps/emaild"
#define MQUEUE "/var/spool/mqueue"

// System Mail Aliases
#define SYSTEM_ALIASES "/nosave/adm/ALIASES"

// Defines fuer das MailArray der Post
#define MM_FROM    0
#define MM_TO      1
#define MM_CC      2
#define MM_SUBJECT 3
#define MM_DATE    4
#define MM_FLAG    5
#define MM_TEXT    6
#define MM_HEADER  7
#define MM_SIZE    8 // Groesse einer Mail
#define MM_MIN_SIZE 7 // Mindesgroesse (der Rest ist optional)

// Defines fuer das Status-Byte MM_FLAG
#define MM_READ 0x01
#define MM_DEL  0x02
#define MM_OLD	0x04

#define GLOBAL_ALIASES  1
#define PRIVATE_ALIASES	2

// In diesen Folder kommen die neuen Mails
#define DEFFOLDER   "+Neues+"

// Mailgroessen
#define MAILSIZE_SIGNAL 409600  // Ab da wird ein Ausrufezeichen im Mailreader angezeigt
#define MAILSIZE_WARN   460800  // Ab da gibt's Warnmeldungen
#define MAILSIZE_MAX    512000  // Da kommt man nicht mehr aus dem Reader raus

#endif // MAIL_H

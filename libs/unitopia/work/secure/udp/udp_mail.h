// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/udp/udp_mail.h
// Description:	Headerfile fuer /secure/udp/udp_mail.c
// Author:	Alvin@Sushi
// Modified by:	Freaky (01.10.94)
//
// $Log: udp_mail.h,v $
// Revision 1.2  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

/*
 * VERSION 1.0
 * Include file for the UDP MAIL system (Author: Alvin@Sushi)
 * Requires INETD V0.60 or higher (INETD Author: Nostradamus@Zebedee)
 */

/*
 * Your local mail delivery system
 * Needs to have the following functions :-
 * void deliver_mail(string to,string from,string subjct,string mail_body)
 * int query_recipient_ok(string name)
 */
#ifndef MAILD
#include <mail.h>
#endif
#define LOCAL_MAILER			MAILD

/*
 * The directory in which mail is kept if the initial attempt times out
 * The mail will be recent every UDPM_RETRY_SEND minutes until
 * UDPM_SEND_FAIL minutes have passed
 * NOTE: UDPM_SPOOL_DIR must end with / and must be writable
 */
#define UDPM_SPOOL_DIR			"/var/spool/mqueue/"

/* The following two times are in MINUTES */
#define UDPM_RETRY_SEND			30
#define UDPM_SEND_FAIL			1440	 /* 24 Hours */

/* PLEASE DO NOT ALTER THE FOLLOWING */

#define UDPM_WRITER			"udpm_writer"
#define UDPM_CC				"udpm_cc"
#define UDPM_SUBJECT			"udpm_subject"
#define UDPM_STATUS			"udpm_status"
#define UDPM_SPOOL_NAME			"udpm_spool_name"

#define UDPM_STATUS_TIME_OUT		0
#define UDPM_STATUS_DELIVERED_OK	1
#define UDPM_STATUS_UNKNOWN_PLAYER	2
#define UDPM_STATUS_IN_SPOOL		3

/* things to do with the spool directory */

#define UDPMS_TIME			"udpm_spool_time"
#define UDPMS_TO			"udpm_spool_to"
#define UDPMS_DEST			"udpm_spool_dest"
#define UDPMS_FROM			"udpm_spool_from"
#define UDPMS_CC			"udpm_spool_cc"
#define UDPMS_SUBJECT			"udpm_spool_subject"
#define UDPMS_BODY			"udpm_spool_body"

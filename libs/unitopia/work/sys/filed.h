// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /sys/filed.h
// Description: Include file fuer filed.c
// Author:	Garthan	(17.08.94)
//
// $Log: filed.h,v $
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef FILED_H
#define FILED_H 1

// Indices des Mappings
#define FD_ENTRY		0
#define FD_TESTER		1
#define FD_ADMIN_OB		2

#define FD_MAPPING_WIDTH	3

// Indices der Eintraege
#define FD_FILE			0
#define FD_CODERS		1
#define FD_PARAMETERS		2
#define FD_REMARKS		3

// Returnvalues
#define FDR_OK			0
#define FDR_ILLEGAL_TYPE	1
#define FDR_NO_AUTH		2
#define FDR_NO_FILE		3
#define FDR_NO_CODERS		4
#define FDR_ENTRY_EXISTS	5
#define FDR_ENTRY_NOT_EXISTANT	6
#define FDR_NO_TESTER		7
#define FDR_FILE_NOT_FOUND	8

#endif // FILED_H

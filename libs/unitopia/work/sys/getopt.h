// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /sys/getopt.h
// Description: Defines fuer /i/tools/getopt::getopt()
// Author:      Garthan (13.02.94)
//
// $Log: getopt.h,v $
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef GETOPT_H
#define GETOPT_H 1

#define GO_ATOM_ERRS    0x01
#define GO_ATOM_FAILS   0x02
#define GO_ATOM_SLOPPY  0x04
#define GO_ERRS         GO_ATOM_ERRS
#define GO_FAILS        (GO_ATOM_ERRS|GO_ATOM_FAILS)
#define GO_SLOPPY       GO_ATOM_SLOPPY

#endif // GETOPT_H

// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/pipe.h
// Description: Headerfile fuer Pipes
// Author:      Freaky (23.12.93)
//
// $Log: pipe.h,v $
// Revision 1.3  2001/06/25 11:47:56  freaky
// defines auf output-funktionen umgebaut.
//
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef PIPE_H
#define PIPE_H 1

#define W(x)		add_output(x)
#define WLN(x)		add_output(x + "\n")
#define CLEAR_BUFFER	set_output("")
#define BEGIN_PIPE(x)	if (!begin_output(&x)) return 0
#define PRINT		if (!end_output()) return 0

#endif // PIPE_H

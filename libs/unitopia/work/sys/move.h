// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/move.h
// Description:	Defines fuer /i/move::move()
//
// $Log: move.h,v $
// Revision 1.7  2008/01/28 13:21:39  gnomi
// Defines besser angeordnet.
//
// Revision 1.6  2008/01/24 22:53:36  gnomi
// Defines fuer die Geisterbewegung.
//
// Revision 1.5  2002/03/16 06:14:23  gnomi
// MOVE_FORCE entfernt.
//
// Revision 1.4  2001/06/24 00:33:04  gnomi
// MOVE_ERR_REMOVE, MOVE_FORCE, ENC_FORCE eingefuehrt.
//
// Revision 1.3  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef MOVE_H
#define MOVE_H 1

// retcode defines for /i/move::move() 

#define MOVE_NOT_ALLOWED	0
#define MOVE_OK			1
#define MOVE_NO_ROOM		2
#define MOVE_DESTRUCTED		3
#define MOVE_DEST_CLOSED        4
#define MOVE_ENV_CLOSED         5
#define MOVE_NO_DEST            6


// move mode defines for /i/move: move(dest, MODE, ...) 

// internals 
#define MOVE_ATOM_MESSAGE	0x01
#define MOVE_ATOM_MAGIC		0x02
#define MOVE_ATOM_NOT_NOTIFY	0x04
#define MOVE_ERR_REMOVE         0x08
#define MOVE_ATOM_GHOST		0x10

// fuer den Aufruf von move 
#define MOVE_MAGIC   (MOVE_ATOM_MESSAGE | MOVE_ATOM_MAGIC)
#define MOVE_NORMAL  (MOVE_ATOM_MESSAGE)
#define MOVE_SECRET  (MOVE_ATOM_NOT_NOTIFY)
// Darf *NUR*(!) von der Mudlib genutzt werden:
#define MOVE_GHOST   (MOVE_ATOM_MESSAGE | MOVE_ATOM_MAGIC | MOVE_ATOM_GHOST)


// fuer add_encumbrance
#define ENC_ADD		0x01
#define ENC_REMOVE	0x02
#define ENC_MODIFY	0x04
#define ENC_TEST	0x10
#define ENC_TEST_ADD	0x11
#define ENC_TEST_REMOVE	0x12
#define ENC_TEST_MODIFY	0x14
#define ENC_FORCE       0x20        // NICHT VERWENDEN, NUR FUER /i/move!

#define MOVE_MSG_IN	"msg_in"
#define MOVE_MSG_OUT	"msg_out"

#endif // MOVE_H

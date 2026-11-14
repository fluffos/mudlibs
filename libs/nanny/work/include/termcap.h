/*
 * termcap.h
 *
 * This file is a intended to be included by objects wishing
 * to do full-screen movements.
 *
 * Copyright (c) 1993 Peter Eriksson <pen@lysator.liu.se>
 *
 * Everyone is granted permission to copy and modify this file
 * under the condition that this copyright notice remains unchanged.
 */

#ifndef _IN_TERMCAP_C_
inherit "obj/termcap";
#endif

/*
 * Flags used in tioctl() call
 */
#define T_SETFL		1
#define T_GETFL		2

/*
 * Mode flags for terminal I/O, set/get via tioctl()
 */
#define F_BUFFERED	1


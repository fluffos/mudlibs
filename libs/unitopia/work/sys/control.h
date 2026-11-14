// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/control.h
// Description:	Konstanten fuer Flags von /i/item/control.c
// Author:	Gnomi (23.02.2004)
//
// $Log: control.h,v $
// Revision 1.2  2013-03-18 21:40:35  gnomi
// CONTROLLER_CALL() eingebaut.
//
// Revision 1.1  2005/02/13 17:31:07  gnomi
// Defines fuer do_notifies/do_forbiddens.
//

#ifndef CONTROL_H
#define CONTROL_H

#define C_RESORT	1
#define C_OMIT_OBJ	2
#define C_NO_HERE	4

#if __BOOT_TIME__ < 1363380000

#define CONTROLLER_CALL_OB(ob,fun)  ("/apps/description_container"->do_bind_with_args_ignore_n(#'call_other, 1, (ob), (fun)))
#define CONTROLLER_CALL(fun)  ("/apps/description_container"->do_bind_with_args_ignore_n(#'call_other, 1, object_name(), (fun)))

#else

#include "apps.h"
#define CONTROLLER_CALL_OB(ob,fun)  (CLOSURE_CONTAINER->do_bind_with_args_ignore_n(#'call_other, 1, (ob), (fun)))
#define CONTROLLER_CALL(fun)  (CLOSURE_CONTAINER->do_bind_with_args_ignore_n(#'call_other, 1, object_name(), (fun)))

#endif

#endif // CONTROL_H

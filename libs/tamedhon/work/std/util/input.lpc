// SilberLand MUDlib
//
// std/util/input.c -- generic input handling
//
// $Id: input.c,v 2.0 1997/03/13 02:40:44 Woody Exp mud $
// $Date: 1997/03/13 02:40:44 $
/* $Revision: 2.0 $
 * $Log: input.c,v $
 * Revision 2.0  1997/03/13 02:40:44  Woody
 * prepared for revision control
 *
 * Revision 1.1  1995/05/02  16:51:22  Jof
 * Initial revision
 *
 */

#pragma strong_types

varargs void input(mixed prompt, mixed pargs, mixed ctrl, mixed ctrlargs)
{
  mixed tmp;
  if(closurep(prompt))
    tmp = apply(prompt, pointerp(pargs) ? pargs : ({}));
  else tmp = prompt;
  write(stringp(tmp) ? tmp : "");
  input_to("done", 0, prompt, pargs, ctrl, ctrlargs);
}

void done(string in_, mixed prompt, mixed pargs, mixed ctrl, mixed ctrlargs)
{
  if(closurep(ctrl) &&
     apply(ctrl, ({ in_ }) + (pointerp(ctrlargs) ? ctrlargs : ({})))) 
    return;
  input(prompt, pargs, ctrl, ctrlargs);
}

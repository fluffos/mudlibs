#ifndef _sys_stack_h
#define _sys_stack_h

#define PUSH(what,stack) ((stack) + ({ what }))
#define POP(stack) ((stack)[0..<2])
#define TOP(stack) ((stack)[<1])

#endif /* _sys_stack_h */

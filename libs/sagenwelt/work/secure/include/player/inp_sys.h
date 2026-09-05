/// @file inp_sys.h
/// @brief input system api
/// @author Gwenhwyvar
/// @version 0.1.0
/// @date 2016-02-01

#ifndef __SEC_PLAYER_INP_SYS_H
#define __SEC_PLAYER_INP_SYS_H

#define INPUT_NORMAL    0
#define INPUT_AUTO_POP  1
#define INPUT_CHAR_MODE 2

public varargs nomask void      modal_push(function input_func, mixed prompt, int secure, function return_to_func, int lock );
public varargs nomask void      modal_simple(function input_func, mixed prompt, int secure, int lock);
public         nomask void      modal_push_char(function input_func, int type = INPUT_NORMAL);
public varargs nomask void      modal_func(function input_func, mixed prompt, int secure, int lock);
public         nomask void      modal_pop(void);
public         nomask void      modal_pass(string str);
public         nomask void      force_me(string str);
public         nomask int       modal_stack_size(void);
public                string    stat_me(void);

#endif  // __SEC_PLAYER_INP_SYS_H

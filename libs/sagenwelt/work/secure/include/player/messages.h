/// @file messages.h
/// @brief message system api
/// @author Gwenhwyvar
/// @version 0.0.0
/// @date 2016-02-01

#ifndef __SEC_PLAYER_MESSAGES_H
#define __SEC_PLAYER_MESSAGES_H

public nomask void      update_translations(void);
public nomask void      set_colour(string which, string what);
public nomask void      remove_colour(string which);
public nomask void      query_colour(string which);
public nomask string *  query_colours(void);

public nomask void      add_receive_class(int msg_class);
public nomask void      remove_receive_class(int msg_class);

#endif  // __SEC_PLAYER_MESSAGES_H

/// @addtogroup privileged
/// @{
/// @file message.h
/// @brief macros for efun::message
/// @author Gwenhwyvar
/// @version 0.0.0
/// @date 2016-01-24

#ifndef __SEC_MESSAGE_H
#define __SEC_MESSAGE_H

// message classes (numbers > 31 reserved for flags)
#define MSGCLASS_SYSTEM     0           // system messages (e.g. shutdown imminent)
#define MSGCLASS_ERROR      1           // error messages (master::error_handler)

#define MSGCLASS_MASK      31
#define MSG_FLAG_MASK     ~31

// message flags, can be set by binary or ('|') with a message class
#define MSG_WRAP           32
#define MSG_INDENT         64

#endif // __SEC_MESSAGE_H
///  @}

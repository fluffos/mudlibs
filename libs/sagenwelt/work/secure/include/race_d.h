/// @file race_d.h
/// @brief macros concerning the race daemon
/// @author Gwenhwyvar
/// @version 0.0.0
/// @date 2016-03-31


#ifndef __SEC_RACE_D_H
#define __SEC_RACE_D_H

// answers to character generation
// races mapping
#define RD_RACE_GENDER  "g"         // array with allowed genders
#define RD_RACE_INFO    "i"         // info text
// gender mapping
#define RD_GENDER_RACE  "r"         // array with allowed races

// prototypes
public mapping get_gender_map(void);
public mapping get_races_map(void);

#endif  // __SEC_RACE_D_H

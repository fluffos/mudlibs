/// @file config.h
/// @brief configurations for the mudlib
///
/// please check carefully and adjust to your likings
/// @Attention changing anything after creating the first character might
/// yield to unresolvable problems!!!
/// Ýou have been warned!
/// @author Gwenhwyvar
/// @version 0.0.0
/// @date 2016-01-28

#ifndef __SEC_CONFIG_H
#define __SEC_CONFIG_H

#define __SAVE_EXT          ".sav"                      // same as SAVE_EXTENSION from driver local_options.h
#define __SAVE_GZ_EXT       ".sav.gz"                   // same as SAVE_GZ_EXTENSION from driver local_options.h

#define __ADMIN_EMAIL       "<you@example.org>"         // admin contact in RL
#define __LANGUAGE          "English"                   // everything else might be difficult to setup (parser!)
#define __LOCATION          "Germany"

#define MIN_LEN_PASSWD      10                          // minimum length for new passwords, should he adjusted according
                                                        // advancements in computing technology
#define MAX_VALID_PASSWD    365                         // maximum time (in days) until a password change is enforced (-1: disabled)

#define PWD_CRYPT_DFLT      PWD_CRYPT_SHA1              // see </secure/include/simul_erun.h> for other options

#endif  // __SEC_CONFIG_H

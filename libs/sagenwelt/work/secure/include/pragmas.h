/// @addtogroup privileged
/// @{
/// @file pragmas.h
/// @Synopsis standard pragmas for all privileged objects
/// @author Gwenhwyvar
/// @version 0.0.0
/// @date 2015-11-27

#ifndef __SEC_PRAGMAS_H
#define __SEC_PRAGMAS_H

#pragma strict_types        // we want to be informed of all possible type errors
#pragma save_binary         // we can save the precompiled master for faster loading
#pragma warnings            // like strict_types this helps with debugging
#pragma optimize            // since the precompiled objects will be saved we can savely spend more time on optimization
#pragma show_error_context  // again for easier debugging

#endif // __SEC_PRAGMAS_H

///  @}

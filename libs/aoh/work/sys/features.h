/* -------------------------------------------------------------------------
 * sys/features.h -- features to be included
 *
 * Copyright (C) 1997,1998 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *
 * CHANGES
 *  06/28/98 [Mica] initial creation
 */

#ifndef FEATURES_H
#define FEATURES_H

/* define this for left-right exits
 */
#define FEATURES_LREXITS

/* define this for intermud-3 support
 */
#if __HOST_NAME__ == MUDHOST
#define FEATURES_INTERMUD3
#else
#undef FEATURES_INTERMUD3
#endif

#endif

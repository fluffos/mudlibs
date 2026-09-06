#ifndef _SECURE_DOMAININFO_
#define _SECURE_DOMAININFO_ 1

/*--------------------------------------------------------------------------
 * /sys/secure/domaininfo.h -- Domaininfo definitions.
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

#define DOMAININFO "/secure/domaininfo"

  /* state of the domaininfo */
#define DI_UNINITED -1
#define DI_INITED    0
#define DI_INITING   1

  /* Indices into the domain-structure */
#define D_NAME    0
#define D_DATA    1
#define DD_HASDIR 0
#define DD_WIZ    1
#define DW_NAME   0
#define DW_DSTAT  1

  /* Empty structures */
#define DW_EMPTY ({ ({}), ({}) })
#define DD_EMPTY ({ 0, DW_EMPTY })
#define D_EMPTY  ({ ({}),({}) })

  /* Membershipvalues of DW_DSTAT */
#define D_NOMEMBER -1 /* Used for QueryWizard(), SetWizard() */
#define D_MEMBER    0
#define D_VICE      1
#define D_LORD      2

#endif /* _SECURE_DOMAININFO_ */


#ifndef __LIMB_STATUS_H__
#define __LIMB_STATUS_H__

#define LIMB_ERROR     0

#define LIMB_WIELDABLE (1 << 0)
#define LIMB_WIELDING  (1 << 1)
#define LIMB_WEARING   (1 << 2)
#define LIMB_SEVERED   (1 << 3)
#define LIMB_CRIPPLED  (1 << 4)

#define LIMB_STATUS_MAX LIMB_CRIPPLED

#endif

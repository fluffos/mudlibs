#ifndef vehicle_h
#define vehicle_h

/* VehicleSize */
// VS_SHUTTLE was referenced (lib/special/planet.lpc's atmosphere-entry
// size gate) but never actually defined anywhere in this archive --
// added as the smallest tier, one step below VS_YACHT, matching this
// file's existing size-ordered bitflag convention.
#define VS_SHUTTLE        (1 << 0)
#define VS_YACHT          (1 << 1)
#define VS_GALLEY         (1 << 2)
#define VS_CRUISER        (1 << 3)
#define VS_DREADNAUGHT    (1 << 4)
/* SensorSuite */
#define VSE_LOCAL         (1 << 1)
#define VSE_WIDE          (1 << 2)
/* WeaponSystem */
#define VW_SMALL          (1 << 1)
#define VW_MEDIUM         (1 << 2)
#define VW_HUGE           (1 << 3)
#define VW_DEVASTATING    (1 << 4)
/* DriveSystem */
#define VM_COASTAL        (1 << 1)
#define VM_DEEP           (1 << 2)
/* ShieldSystem */
#define VSH_SMALL         (1 << 1)
#define VSH_MEDIUM        (1 << 2)
#define VSH_LARGE         (1 << 3)

#endif

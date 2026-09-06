#ifndef _RACECONST_H_
#define _RACECONST_H_

#define RACE_DIR   "/race/"

#define BP_HEAD    0x00000001
#define BP_NECK    0x00000002
#define BP_CHEST   0x00000004
#define BP_GROIN   0x00000008
#define BP_BACK    0x00000010

#define BP_RARM    0x00000020
#define BP_LARM    0x00000040
#define BP_RWRIST  0x00000080
#define BP_LWRIST  0x00000100
#define BP_RHAND   0x00000200
#define BP_LHAND   0x00000400

#define BP_RLEG    0x00000800
#define BP_LLEG    0x00001000
#define BP_RFOOT   0x00002000
#define BP_LFOOT   0x00004000

#define BP_RARM2   0x00008000
#define BP_LARM2   0x00010000
#define BP_RWRIST2 0x00020000
#define BP_LWRIST2 0x00040000
#define BP_RHAND2  0x00080000
#define BP_LHAND2  0x00100000

#define BP_RLEG2   0x00200000
#define BP_LLEG2   0x00400000
#define BP_RFOOT2  0x00800000
#define BP_LFOOT2  0x01000000

#define BP_RLEG3   0x02000000
#define BP_LLEG3   0x04000000
#define BP_RFOOT3  0x08000000
#define BP_LFOOT3  0x10000000

#define BP_TAIL    0x20000000

// Baka! Don't waste reserved spots!
//#define BP_OTHER   0x40000000
//#define BP_OTHER2  0x80000000

// Combinations
#define BP_ARMS    (BP_LARM | BP_RARM)
#define BP_ARMS2   (BP_LARM2 | BP_RARM2)
#define BP_WRISTS  (BP_LWRIST | BP_RWRIST)
#define BP_WRISTS2 (BP_LWRIST2 | BP_RWRIST2)
#define BP_HANDS   (BP_LHAND | BP_RHAND)
#define BP_HANDS2  (BP_LHAND2 | BP_RHAND2)
#define BP_LEGS    (BP_LLEG | BP_RLEG)
#define BP_LEGS2   (BP_LLEG2 | BP_RLEG2)
#define BP_LEGS3   (BP_LLEG3 | BP_RLEG3)
#define BP_FEET    (BP_LFOOT | BP_RFOOT)
#define BP_FEET2   (BP_LFOOT2 | BP_RFOOT2)
#define BP_FEET3   (BP_LFOOT3 | BP_RFOOT3)
#define BP_TORSO   (BP_CHEST | BP_BACK | BP_GROIN)
#define BP_SHIRT   (BP_CHEST | BP_BACK | BP_ARMS)
#define BP_PANTS   (BP_LEGS | BP_GROIN)

// Body types
#define BT_HUMANOID  (BP_HEAD | BP_NECK | BP_TORSO | BP_ARMS | \
                      BP_HANDS | BP_WRISTS | BP_LEGS | BP_FEET)
#define BT_QUADRUPED (BP_HEAD | BP_NECK | BP_TORSO | BP_LEGS | \
                      BP_FEET | BP_LEGS2 | BP_FEET2)
#define BT_INSECT    (BP_HEAD | BP_NECK | BP_TORSO | BP_LEGS | \
                      BP_LEGS2 | BP_LEGS3)

// (<body_part> name:name, size:size, vitality:vitality);
// Default values for body parts...
#define DEFAULT_BP_MAP   ([ BP_HEAD:(<body_part> name:"head", size:1, vitality:2), \
                            BP_NECK:(<body_part> name:"neck", size:1, vitality:2), \
                            BP_BACK:(<body_part> name:"back", size:3, vitality:0), \
                            BP_TAIL:(<body_part> name:"tail", size:3, vitality:-2), \
                            BP_CHEST:(<body_part> name:"chest", size:4, vitality:0), \
                            BP_GROIN:(<body_part> name:"groin", size:0, vitality:1), \
                            BP_LARM:(<body_part> name:"left arm", size:2, vitality:-1), \
                            BP_RARM:(<body_part> name:"right arm", size:2, vitality:-1), \
                            BP_LWRIST:(<body_part> name:"left wrist", size:0, vitality:-2), \
                            BP_RWRIST:(<body_part> name:"right wrist", size:0, vitality:-2), \
                            BP_LHAND:(<body_part> name:"left hand", size:1, vitality:-2), \
                            BP_RHAND:(<body_part> name:"right hand", size:1, vitality:-2), \
                            BP_LLEG:(<body_part> name:"left leg", size:2, vitality:-1), \
                            BP_RLEG:(<body_part> name:"right leg", size:2, vitality:-1), \
                            BP_LFOOT:(<body_part> name:"left foot", size:1, vitality:-2), \
                            BP_RFOOT:(<body_part> name:"right foot", size:1, vitality:-2) ])

#endif

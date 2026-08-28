#ifndef s_damage_types_h
#define s_damage_types_h

#define BLUNT              (1 << 1)
#define SLASH              (1 << 2)
#define PIERCE             (1 << 3)
#define WATER              (1 << 4)
#define SHOCK              (1 << 5)
#define COLD               (1 << 6)
#define HEAT               (1 << 7)
#define GAS                (1 << 8)
#define ACID               (1 << 9)
#define MAGIC              (1 << 10)
#define HUNGER             (1 << 11)
#define DISEASE            (1 << 12)
#define POISON             (1 << 13)
#define VACUUM             (1 << 14)
#define SOUND              (1 << 15)
#define DROWNING           (1 << 16)

#define MAX_DAMAGE_BIT     DROWNING

#define ALL_DAMAGE   ((MAX_DAMAGE_BIT << 1) -2)

#define ALL_PHYSICAL BLUNT|SLASH|PIERCE|ACID
#define ALL_ELEMENTS HEAT|COLD|SHOCK|WATER|SOUND
#define ALL_EXTERNAL ALL_PHYSICAL|ALL_ELEMENTS|MAGIC|VACUUM
#define ALL_HEALTH HUNGER|DISEASE|POISON

#endif /* s_damage_types_h */

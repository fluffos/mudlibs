#ifndef SPELL_H
#define SPELL_H

#ifndef MONSTER_H /* make sure they match */

#define TARGET        loaded_spell[0]
#define SPELL_NAME    loaded_spell[1]
#define SPELL_TYPE    loaded_spell[2]
#define SPELL_COST    loaded_spell[3]
#define SPELL_DAM     loaded_spell[4]
#define TARGET_MSG    loaded_spell[5]
#define CASTER_MSG    loaded_spell[6]
#define ROOM_MSG      loaded_spell[7]
#define IMMUNE_TYPE   loaded_spell[8]
#define AREA_EFFECT   loaded_spell[9]
#define SPELL_LEVEL   loaded_spell[10]
#define SPELL_OBJ     loaded_spell[11]
#define SPELL_TIME    loaded_spell[12]
#define PREPARE_MSG   loaded_spell[13]
#define PREP_MSG_ROOM loaded_spell[14]
#define COMPONENT     loaded_spell[15]
#define PASSIVE       loaded_spell[16]
#define ARGUMENT      loaded_spell[17]

#else

#define TARGET        default_spell[0]
#define SPELL_NAME    default_spell[1]
#define SPELL_TYPE    default_spell[2]
#define SPELL_COST    default_spell[3]
#define SPELL_DAM     default_spell[4]
#define TARGET_MSG    default_spell[5]
#define CASTER_MSG    default_spell[6]
#define ROOM_MSG      default_spell[7]
#define IMMUNE_TYPE   default_spell[8]
#define AREA_EFFECT   default_spell[9]
#define SPELL_LEVEL   default_spell[10]
#define SPELL_OBJ     default_spell[11]
#define SPELL_TIME    default_spell[12]
#define PREPARE_MSG   default_spell[13]
#define PREP_MSG_ROOM default_spell[14]
#define COMPONENT     default_spell[15]
#define PASSIVE       default_spell[16]
#define ARGUMENT      default_spell[17]

#endif /* MONSTER */

#define SPELL_ALLOCATE 18

#endif /* SPELL_H */


//锻造物品库
//gamer@88 2003.10
//不要随便改动等级的数字和顺序，否则。。。。。
//如果有新的效果添加，/adm/daemons/diablod里的效果库也要相应改动.
#ifndef __FORGE__
#define __FORGE__

#define CRUDE           1
#define CRACKED         2
#define LOW_QUALITY     3
#define NORMAL          4
#define SUPERIOR        5
#define RARE            6
#define UNIQUES         7
#define SET             8   //固定物品

#define DODGE_EFF       50
#define PARRY_EFF       51
#define FORCE_EFF       52
#define SPELLS_EFF      53
#define ATTACK_EFF      54
#define DEFENSE_EFF     55
#define ARMOR_EFF       56


#define STR_EFF         100
#define COR_EFF         101
#define INT_EFF         102
#define SPI_EFF         103
#define CPS_EFF         104
#define PER_EFF         105
#define CON_EFF         106
#define KAR_EFF         107
#define ADD_KEE         108
#define ADD_SEN         109
#define ADD_FORCE       110
#define ADD_MANA        111
#define MAGIC_FIND      112


#define COMBAT_BLOOD_KEE        200
#define COMBAT_BLOOD_SEN        201
#define COMBAT_BLOOD_FORCE      202
#define COMBAT_BLOOD_MANA       203
#define PARRY_BLOCK_ATTACK      204
#define ADD_SPELL_KEE           205
#define ADD_SPELL_SEN           206
#define ADD_SPELL_ALL           207
#define SKILL_DOUBLE_DAMAGE     208


#define FORCE_VS_DAMAGE         300
#define SPELLS_VS_DAMAGE        301
#define ANTI_SPELL_KEE          302
#define ANTI_SPELL_SEN          303
#define ANTI_SPELL_ALL          304

#define ADD_MAX_KEE         400
#define ADD_MAX_SEN         401
#define ADD_MAX_FORCE       402
#define ADD_MAX_MANA        403
#define CAN_INSET           404
#define ADD_ALL_SKILL       405

#define LEVEL_1_EFF             50 + random(7)
#define LEVEL_2_EFF             100 + random(13)
#define LEVEL_3_WEAPON_EFF      200 + random(9)
#define LEVEL_3_ARMOR_EFF       300 + random(5)
#define LEVEL_3_ALL_EFF         400 + random(6)

#endif/**/

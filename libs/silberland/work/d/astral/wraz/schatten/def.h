#define GEBIET "schatten"
#define LOGMASTER ZONE "master/log_master"
#define LISTMASTER ZONE "master/list_master"
#define RMASTER ZONE "master/room_master"
#define DEATHLIST ZONE "list/shadowsterbeliste.read"
#define KILLLIST ZONE "list/shadowkillliste.read"
#define SHADOWLVLLIST ZONE "list/shadowlvlliste.read"
#define TPU getuid(this_player())

#define AZA_ROOM 250
#define TEMP_LAST_ALLOWED_ROOM 502

#define DIVIDEND_RAND 12
#define DIVISOR 10

#define DEF_ITEM_LIFETIME 6048000 // 70 Tage
#define DC_A 0.0 // difficulty() Konstanten in OBJ obj.c
#define DC_B 1.015

 // Defaultwerte fuer incorporeal NPC der Schattenwelt
    // Physische Schaeden -> immun
    // Terror -> immun
    // Gift -> immun
    // Elemente u.ae. -> -70%
    // Feuer (weil Lichtkomponente) -> -30%
    // Magie & Holy -> +10%
    // Licht -> +20%
#define SHADOW_INC_DEF_RESISTANCE_STR ([ DT_FIRE: -0.3, DT_COLD: -0.7, DT_WATER: -0.7 , DT_AIR: -0.7, DT_LIGHTNING:-0.7, DT_EXPLOSION: -0.7 , DT_SOUND: -0.7, DT_LIGHT: 0.2, DT_ELECTRIC: -0.7 , DT_ACID: -0.7, DT_POISON: -1.0, DT_TERROR: -1.0 , DT_HOLY: 0.1, DT_UNHOLY: -1.0, DT_MAGIC: 0.1 , DT_MIND: -1.0, DT_SLASH: -1.0, DT_BLUDGEON: -1.0 , DT_PIERCE: -1.0, DT_SQUEEZE: -1.0, DT_WHIP: -1.0 , DT_RIP: -1.0 ])

 // Defaultwerte fuer physische NPC der Schattenwelt
    // Physische Schaeden -> -50%
    // Terror -> immun
    // Gift -> immun
    // Elemente u.ae. -> -70%
    // Feuer (weil Lichtkomponente) -> -30%
    // Magie & Holy -> +10%
    // Licht -> +20%
    // Cold -> immun
#define SHADOW_DEF_RESISTANCE_STR ([ DT_FIRE: -0.3, DT_COLD: -1.0, DT_WATER: -0.7 , DT_AIR: -0.7, DT_LIGHTNING:-0.7, DT_EXPLOSION: -0.7 , DT_SOUND: -0.7, DT_LIGHT: 0.2, DT_ELECTRIC: -0.7 , DT_ACID: -0.7, DT_POISON: -1.0, DT_TERROR: -1.0 , DT_HOLY: 0.1, DT_UNHOLY: -1.0, DT_MAGIC: 0.1 , DT_MIND: -0.5, DT_SLASH: -0.5, DT_BLUDGEON: -0.5 , DT_PIERCE: -0.5, DT_SQUEEZE: -0.5, DT_WHIP: -0.5 , DT_RIP: -0.5 ])

#include "../def.h"

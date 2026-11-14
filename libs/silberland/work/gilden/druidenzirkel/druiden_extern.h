#ifndef __DRUIDEN_EXTERN_H__
#define __DRUIDEN_EXTERN_H__

/* Die Elemente */
#define ERZ "erz"
#define FEUER "feuer"
#define LUFT "luft"
#define WASSER "wasser"
#define HUMUS "humus"
#define EIS "eis"
#define GEIST "geist"

#ifndef P_ELEMENT
#define P_ELEMENT "element"
#endif

#define ELEMENTAL_CASTER "e_caster"
#define ELEMENTAL_OWNER "e_owner"

// elementarraeume
#define P_ELEMENTAL_ROOM "elemental_room"
// fuers amulett + drufen
#define P_TMP_DRUID_LISTENER "tmp_druid_listener"
// Aendern des Handkampfes
#define P_DRUID_ADD_HAND_DAMAGE "druid_add_hand_damage"
#define P_DRUID_HAND_DAMAGE_TYPE "druid_hand_damage_type"
// Darf ein Item trotz Metall benutzt werden? (id)
#define DRUID_ALLOWED_METAL_ITEM "\nallowed_metal_item"
// definiert in itemd.h, hier auch nomal:
#ifndef P_ITEMD_ELEMENTAL_VALUE
#define P_ITEMD_ELEMENTAL_VALUE "itemd_elemental_value"
#endif
// Farben bei den Spells?
#define P_DRUID_SPELL_COLORS "druid_spell_colors"

// Id der Ringe
#define ELEMENT_RING_ "\nelement_ring_"
#define ELEMENT_RING_FEUER "\nelement_ring_feuer"
#define ELEMENT_RING_WASSER "\nelement_ring_wasser"
#define ELEMENT_RING_LUFT "\nelement_ring_luft"
#define ELEMENT_RING_ERZ "\nelement_ring_erz"
#define ELEMENT_RING_HUMUS "\nelement_ring_humus"
#define ELEMENT_RING_EIS "\nelement_ring_eis"

#define DRUIDEN_FLASCHE "\ndruiden_flasche_"

#endif /* __DRUIDEN_EXTERN_H__ */

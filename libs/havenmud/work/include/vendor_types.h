#ifndef s_vendor_types_h
#define s_vendor_types_h

#define VT_TREASURE    (1 << 1)
#define VT_WEAPON      (1 << 2)
#define VT_ARMOUR      (1 << 3)
#define VT_LIGHT       (1 << 4)
#define VT_FOOD        (1 << 5)
#define VT_DRINK       (1 << 6)
#define VT_MAGIC       (1 << 7)
#define VT_FISHING     (1 << 8)
#define VT_PLANT       (1 << 9)
#define VT_HERB        (1 << 10)
#define VT_FUR         (1 << 11)
#define VT_GEM         (1 << 12)
#define VT_INSTRUMENT  (1 << 13)
#define VT_CLOTHING    (1 << 14)
#define VT_SMOKE       (1 << 15)

#define MAX_VENDOR_BIT VT_SMOKE

#define VT_ALL        ((MAX_VENDOR_BIT << 1) -2)

#endif /* s_vendor_types_h */

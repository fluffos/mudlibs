
// potion shop list
#define POTION_SHOP_LIST ({ "vendor", "farwind", "easta", })

// frequency for count to recover potio quota, unit 2 sec
#define POTION_QUOTA_FREQUENCY 30

// the frequency of count for recover potion quota,
// total time = POTION_QUOTA_FREQUENCY * POTION_QUOTA_RECOVER_FREQUENCY
// now is 5400 sec = 1 hr 30 mins.
#define POTION_QUOTA_RECOVER_FREQUENCY 90

// min number of amount a potion can define.
#define MIN_QUOTA 10

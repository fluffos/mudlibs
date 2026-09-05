#ifndef _sys_timedep_h
#define _sys_timedep_h

#define TD_DAY2 ({ "day2" })
#define TD_DAY2_WHEN ({ 28800, 72000 })
#define TD_DAY2_WHAT ({ "day", "night" })

#define set_timedep2() set_default_depspace(TD_DAY2)


#define TD_DAY4 ({ "day4" })
#define TD_DAY4_WHEN ({ 21600, 25200, 64800, 68400 })
#define TD_DAY4_WHAT ({ "dawn", "day", "dusk", "night" })

#define set_timedep4() set_default_depspace(TD_DAY4)


#define TD_DAY6 ({ "day6" })
#define TD_DAY6_WHEN ({0,14400,28800,43200,57600,72000})
#define TD_DAY6_WHAT ({"midnight","morning","forenoon","afternoon","evening","night"})

#define set_timedep6() set_default_depspace(TD_DAY6)


#define TD_DAY8 ({ "day8" })
#define TD_DAY8_WHEN ({0,3600,18000,28800,43200,46800,64800,72000})
#define TD_DAY8_WHAT ({"midnight","late night","morning","forenoon","noon","afternoon","evening","night"})

#define set_timedep8() set_default_depspace(TD_DAY8)


#define TD_SUN ({ "sun" })
#define TD_SUN_WHEN ({0,18000,25200,28800,39600,46800,64800,68400,72000})
#define TD_SUN_WHAT ({"late night","dawn","sunrise","forenoon","noon","afternoon","sunset","dusk","night"})


#define TU_MOON     "query_tu_moon"
#define TU_MOONDAY  "query_tu_moontime"
#define TU_MONTH    "query_tu_month"
#define TU_WEEKDAY  "query_tu_weekday"


#define TD_MOON4 ({ "moon4" })
#define TD_MOON4_WHEN ({ 16, 165, 196, 345 })
#define TD_MOON4_WHAT ({ "waxing", "full", "waning", "new" })


#define TD_YEAR4 ({ "year4" })
#define TD_YEAR4_WHEN ({ 2, 5, 8, 11 })
#define TD_YEAR4_WHAT ({ "spring", "summer", "autumn", "winter" })


#define TD_WEEKDAY ({ "weekday" })
#define TD_WEEKDAY_WHEN ({ 0, 1, 2, 3, 4, 5, 6 })
#define TD_WEEKDAY_WHAT ({"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"})


// Defaults
#define DEFAULT_DEPSPACE ({ 0, 0, TD_DAY2, 0, TD_DAY4, 0, TD_DAY6, 0, TD_DAY8})

#define TD_WHAT ([ TD_DAY2[0]     : TD_DAY2_WHAT,   \
                   TD_DAY4[0]     : TD_DAY4_WHAT,   \
                   TD_DAY6[0]     : TD_DAY6_WHAT,   \
                   TD_DAY8[0]     : TD_DAY8_WHAT,   \
                                                    \
                   TD_MOON4[0]    : TD_MOON4_WHAT,  \
                   TD_WEEKDAY[0]  : TD_WEEKDAY_WHAT,\
                   TD_YEAR4[0]    : TD_YEAR4_WHAT,  \
                   TD_SUN[0]      : TD_SUN_WHAT ])

#define TD_WHEN ([ TD_DAY2[0]     : TD_DAY2_WHEN,   \
                   TD_DAY4[0]     : TD_DAY4_WHEN,   \
                   TD_DAY6[0]     : TD_DAY6_WHEN,   \
                   TD_DAY8[0]     : TD_DAY8_WHEN,   \
                                                    \
                   TD_MOON4[0]    : TD_MOON4_WHEN,  \
                   TD_WEEKDAY[0]  : TD_WEEKDAY_WHEN,\
                   TD_YEAR4[0]    : TD_YEAR4_WHEN,  \
                   TD_SUN[0]      : TD_SUN_WHEN ])

#define TD_WHICH ([ TD_MOON4[0]   : TU_MOON,        \
                    TD_WEEKDAY[0] : TU_WEEKDAY,     \
                    TD_YEAR4[0]   : TU_MONTH ])

#endif  // _sys_timedep_h

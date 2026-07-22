#include <ansi.h>
mapping *quest = ({
     ([      "quest":                "Ò×½î¾­ÎÄÑ§Æª",
                "diff":                 3,
        ]),
        ([      "quest":                "²ÝÝ®",
                "diff":                 2,
        ]),
        ([      "quest":                "Ö¸Ì×",
                "diff":                 1,
        ]),
     ([      "quest":                "¹þÃÜ¹Ï",
                "diff":                 2,
        ]),
     ([      "quest":                "ÍÃÈâ",
                "diff":                 2,
        ]),
     ([      "quest":                "²ñ",
                "diff":                 2,
        ]),
     ([      "quest":                HIY "¶¬²»À­" NOR,
                "diff":                 5,
        ]),
        ([      "quest":                "»¨µñ¾Æ´ü",
                "diff":                 2,
        ]),
        ([      "quest":                "¿¾Ñ¼",
                "diff":                 2,
        ]),
        ([      "quest":                "Âé²¼´ü",
                "diff":                 1,
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

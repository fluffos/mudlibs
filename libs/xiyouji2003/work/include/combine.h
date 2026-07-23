// Update by waiwai@2002/12/05

#include "ansi.h"

mapping combine_list = ([
        // 三个钻石碎片合并成为一个钻石
        ({ "/obj/self/cdiamond-1",
           "/obj/self/cdiamond-2",
           "/obj/self/cdiamond-3" }) : "/obj/self/diamond",

        // 三个钻石合并成为一个精美钻石
        ({ "/obj/self/diamond-1",
           "/obj/self/diamond-2",
           "/obj/self/diamond-3" }) : "/obj/self/fdiamond",

        // 三个精美钻石合并成为一个神之钻石
        ({ "/obj/self/fdiamond-1",
           "/obj/self/fdiamond-2",
           "/obj/self/fdiamond-3" }) : "/obj/self/item/mdiamond",

        // 三个玛瑙碎片合并成为一个玛瑙
        ({ "/obj/self/cagate-1",
           "/obj/self/cagate-2",
           "/obj/self/cagate-3" }) : "/obj/self/agate",

        // 三个玛瑙合并成为一个精美玛瑙
        ({ "/obj/self/agate-1",
           "/obj/self/agate-2",
           "/obj/self/agate-3" }) : "/obj/self/fagate",

        // 三个精美玛瑙合并成为一个神之玛瑙
        ({ "/obj/self/fagate-1",
           "/obj/self/fagate-2",
           "/obj/self/fagate-3" }) : "/obj/self/item/magate",

        // 三个水晶碎片合并成为一个水晶
        ({ "/obj/self/ccrystal-1",
           "/obj/self/ccrystal-2",
           "/obj/self/ccrystal-3" }) : "/obj/self/crystal",

        // 三个水晶合并成为一个精美水晶
        ({ "/obj/self/crystal-1",
           "/obj/self/crystal-2",
           "/obj/self/crystal-3" }) : "/obj/self/fcrystal",

        // 三个精美水晶合并成为一个神之水晶
        ({ "/obj/self/fcrystal-1",
           "/obj/self/fcrystal-2",
           "/obj/self/fcrystal-3" }) : "/obj/self/item/mcrystal",

        // 三个翡翠碎片合并成为一个翡翠
        ({ "/obj/self/cjade-1",
           "/obj/self/cjade-2",
           "/obj/self/cjade-3" }) : "/obj/self/jade",

        // 三个翡翠合并成为一个精美翡翠
        ({ "/obj/self/jade-1",
           "/obj/self/jade-2",
           "/obj/self/jade-3" }) : "/obj/self/fjade",

        // 三个精美翡翠合并成为一个神之翡翠
        ({ "/obj/self/fjade-1",
           "/obj/self/fjade-2",
           "/obj/self/fjade-3" }) : "/obj/self/item/mjade",

        // 三个蓝水晶合并成为一个蓝晶
        ({ "/d/tianpeng/dong/obj/lanshuijing-1",
           "/d/tianpeng/dong/obj/lanshuijing-2",
           "/d/tianpeng/dong/obj/lanshuijing-3" }) : "/obj/self/item/lanshuijing",

        // 三个星星合并成为一个月亮
        ({ "/obj/self/star-1",
           "/obj/self/star-2",
           "/obj/self/star-3" }) : "/obj/self/item/moon",

]);


// SN:<Pj_B;\QKG8Aa[^m
// pet.c

#include "/clone/npc/pet.h"

void setup()
{
        set_name("[1;36m乌云驹[2;37;0m", ({"wuyun ju"}));        
        set("gender", "男性");                
        set("unit", "匹");
        set("long", "ううぜとのぢさ
它是红豆的坐骑。
");
        set_temp("owner_id", "hongdou");
        set_temp("owner_name", "红豆");
        ::setup();
}


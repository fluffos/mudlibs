
inherit NPC;

void create()
{
        set_name("麝鹿", ({ "she lu","lu"}) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只麝正在低头吃草。名贵的香料－－麝香，就是从这种动物身上\n"
                    "得到的。\n");

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        if( random(2) == 1){
        set("combat_exp", 5000+random(3000));}
        else {
        set("combat_exp", 20000+random(20000));
        set_skill("unarmed",60);}
        //set_wugong("unarmed",60,60,0);
        setup();
}



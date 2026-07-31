// By zjb@ty

inherit ITEM; 
int zjb = random(4);
mapping *weapon= ({
([     "name":     "星空流星石",
       "id":        "zjb shi",
       "yanse":        HIB,
       "int":           35,
       "str":           25,
       "dex":           30,
       "con":           20,
       "damage":       250,
       "lei":            1,
]),
([     "name":     "小志风云岩",
       "id":    "daniel shi",
       "yanse":        HIW,
       "int":           25,
       "str":           35,
       "dex":           20,
       "con":           30,
       "damage":       250,
       "lei":            2,
]),
([     "name":     "风间苍月钢",
       "id":    "cangyue gang",
       "yanse":        WHT,
       "int":           15,
       "str":           45,
       "dex":           20,
       "con":           30,
       "damage":       250,
       "lei":            3,
]),
([     "name":     "魔睛烛舞铁",
       "id":    "zhuwu tie",
       "yanse":       HIR,
       "int":           45,
       "str":           15,
       "dex":           15,
       "con":           35,
       "damage":       250,
       "lei":            4,
]),
});
int panduan(int arg) {  if ( arg )   zjb = arg - 1;  }
void create()
{
    string name,id;

    name = weapon[zjb]["name"];

    set_name(weapon[zjb]["yanse"]+name+NOR,({weapon[zjb]["id"]}) );  
    set_weight(100);
    if( clonep() )
    set_default_object(__FILE__);
    else {
         set("unit", "个");                        
        }

   set("ty_weapon",1);
   set("no_get",1);
   set("no_drop",1);             
   set("no_put",1);
   set("no_give",1);
   set("zhongji_hc",1);
   set("bh",weapon[zjb]["lei"]);
   if (weapon[zjb]["str"])
   set("str",weapon[zjb]["str"]);
   if (weapon[zjb]["con"])
   set("con",weapon[zjb]["con"]);
   if (weapon[zjb]["dex"])
   set("dex",weapon[zjb]["dex"]);
   if (weapon[zjb]["int"])
   set("int",weapon[zjb]["int"]);
   if (weapon[zjb]["damage"])
   set("damage",weapon[zjb]["damage"]);
   set("long", "这是一个差不多绝种的金属，可以用来合成兵器!(help hecheng)\n");
   
   setup();
  }


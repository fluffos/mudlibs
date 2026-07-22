// By jh@ty

inherit ITEM; 
int jh = random(5); 
mapping *weapon= ({
([     "name":     "青钢",
       "id":  "qing gang",
       "yanse":       HIC,
       "int":           8+random (22),
       "lei":            1,
]),
([     "name":     "点钢",
       "id": "dian gang",
       "yanse":       HIW,
       "str":           8+random (22),
       "lei":            2,
]),
([     "name":     "黑钢",
       "id":   "hei gang",
       "yanse":       WHT,
       "dex":           8+random (22),
       "lei":            3,
]),
([     "name":     "绿钢",
       "id":    "lv gang",
       "yanse":       HIG,
       "con":           8+random (22),
       "lei":            4,
]),
([     "name":     "血钢",
       "id":    "xue gang",
       "yanse":       HIR,
       "damage":      150+random (220),
       "lei":            5,
]),
});
int panduan(int arg) {  if ( arg )   jh = arg - 1;  }
void create()
{
    string name,id;

    name = weapon[jh]["name"];

    set_name(weapon[jh]["yanse"]+name+NOR,({weapon[jh]["id"]}) );  
    set_weight(100);
    if( clonep() )
    set_default_object(__FILE__);
    else {
         set("unit", "个");                        
        }

   set("ty_weapon",1);
   set("no_get",1);
   set("no_put",1);
   set("value",1);
   //set("no_give",1);
   set("zhongji_hc",1);
   set("bh",weapon[jh]["lei"]);
   if (weapon[jh]["str"])
   set("str",weapon[jh]["str"]);

   if (weapon[jh]["con"])
   set("con",weapon[jh]["con"]);

   if (weapon[jh]["dex"])
   set("dex",weapon[jh]["dex"]);

   if (weapon[jh]["int"])
   set("int",weapon[jh]["int"]);

   if (weapon[jh]["damage"])
   set("damage",weapon[jh]["damage"]);
   set("long", "这是一个钢级的金属，可以用来镶嵌兵器(xiangqian)和合成装备!\n");
   
   setup();
  }


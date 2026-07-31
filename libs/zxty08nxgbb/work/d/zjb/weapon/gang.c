// By zjb@ty

inherit ITEM; 
int zjb = random(5); 
mapping *weapon= ({
([     "name":     "青钢",
       "id":  "qing gang",
       "yanse":       HIC,
       "int":           8,
       "lei":            1,
]),
([     "name":     "点钢",
       "id": "dian gang",
       "yanse":       HIW,
       "str":           8,
       "lei":            2,
]),
([     "name":     "黑钢",
       "id":   "hei gang",
       "yanse":       WHT,
       "dex":           8,
       "lei":            3,
]),
([     "name":     "绿钢",
       "id":    "lv gang",
       "yanse":       HIG,
       "con":           8,
       "lei":            4,
]),
([     "name":     "血钢",
       "id":    "xue gang",
       "yanse":       HIR,
       "damage":      150,
       "lei":            5,
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
   set("no_put",1);
   set("no_drop",1);
   set("no_give",1);
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
   set("long", "这是一个钢级的金属，可以用来合成兵器!(help hecheng)\n");
   
   setup();
  }


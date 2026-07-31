 inherit ITEM;
void create()
{
        set_name("名单", ({"list", "名单"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", 
"一张白纸上列了许多名字，每个名字下却有个括弧，括弧里有的写着
“少林”，有的写着“武当”，每一个都写的是名门大派，也许，这
是这些门派中奸细的名字？
         阿平                     三清宫        
         阿龙                     武当派    
         天正下着雨               神水宫    
         朱云                     狼山                     
         阿谈                     铁雪
         赤无极                   少林 
        。。。。。。                       
\n");
                set("value", 1);
        }
}        

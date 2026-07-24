// 道具生成器 itemmaker.c 
// Written by Doing Lu    1998/11/2

#define ITEM_DIR        "/d/item/make/"

// 生成道具文檔, 需要一個的道具粗坯對象 item_temp (object is ITEM_DIR/origin.c)
// 生成以后建立 ITEM_DIR/???.c 然后刪除舊的 item_temp, 生成一件新的道具，返回文件名

// 關于item_temp各個屬性的說明
// ------ 用戶可以描述的屬性
// name                 道具的名稱， 必須要
// id                   道具的ID，   必須要
// long                 道具的描述，系統會在生成道具時自動添加關于煉制原料的描述
// wield_msg            裝備武器的描述，如果沒有系統會自動生成
// unwield_msg          收回武器時的描述
// wear_msg             穿上護甲時的描述
// unwear_msg           脫掉護甲時的描述

// ------ 不是用戶描述的屬性
// owner                制造者
// material1            原料1
// material2            原料2，可以沒有
// unit                 單位，系統自動生成
// point                道具的傷害力/防御力
// item_type            道具的類型 weapon 或 armor
// type                 道具的類別 weapon 為 sword, blade, whip, stick ﹔ armor 為 armor
// ctype                道具的類別的中文名 weapon 為 劍、刀、鞭、杖 ﹔ armor 為 護甲
// weigth               道具的重量
// value                道具的價值

// ------ 說明是用戶自練的道具的屬性
// item_make            1

int save_item_file(string filename, string content);

string create_file(object item_temp)
{
        string  buf;                    // 生成文件的緩沖區
        string  filename;
        int     i;

        // 生成文件名
        for (i = 0; i < 100; i++)
        {               
                filename = ITEM_DIR + item_temp->query("ownerid") + 
                           sprintf("%d.lpc", random(8999) + 1000);
                if (file_size(filename) <= 0) break;
        }
        if (i >= 100)
        {
                write("無法生成檔案，請通知巫師處理。\n");
                return 0;
        }
        buf = "// ITEM Made by player " + filename + 
              "\n// Written by ITEMMAKER(Doing Lu 1998/11/2)\t" + ctime(time()) + "\n";
        if (item_temp->query("item_type") == "weapon")
        {
                // 生成武器道具文件
                string desc;            // 武器的描述
                if (item_temp->query("material2") == "")
                {
                        desc = "這是由" + item_temp->query("material1") + "煉制而成的一" +
                                item_temp->query("unit") + item_temp->query("ctype") + "。\\n";
                } else
                {
                        desc = "這是由" + item_temp->query("material1") + "輔以" + 
                                item_temp->query("material2") + "煉制而成的一" +
                                item_temp->query("unit") + item_temp->query("ctype") + "\\n";
                }
                desc += item_temp->query("ctype") + "柄上刻著一行小字：" +
                        item_temp->query("owner") + "(" + item_temp->query("ownerid") + ")\\n";
                // 自動補充空信息
                if (item_temp->query("wield_msg") == "")
                {
                        item_temp->set("wield_msg", "$N一聲清嘯，抖出一" +
                                        item_temp->query("unit") + item_temp->query("item/name") + "。");
                }
                if (item_temp->query("unwield_msg") == "")
                {
                        item_temp->set("unwield_msg", "$N隨手一抹，收起了" +
                                        item_temp->query("item/name") + "。");
                }
                buf += "#include <ansi.h>\n\n";
                buf += "#include <weapon.h>\n\n";
                buf += "inherit " + item_temp->query("inherit") + ";\n\n";
                buf += @ITEMCODE
string query_autoload() { return "1"; }

void autoload(string param)
{
}

void create()
{
ITEMCODE;               
                buf += sprintf("\tset_name(\"%s\", ({ \"%s\" }));\n",
                                item_temp->query("item/name"), item_temp->query("item/id"));
                buf += sprintf("\tset_weight(%d);\n", item_temp->query_weight());
                buf += @ITEMCODE
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("item_make", 1);
ITEMCODE;
                buf += sprintf("\t\tset(\"unit\", \"%s\");\n", item_temp->query("unit"));
                buf += sprintf("\t\tset(\"long\", \"%s\\n\");\n", desc + item_temp->query("long"));
                buf += sprintf("\t\tset(\"value\", %d);\n", item_temp->query("value"));
                buf += sprintf("\t\tset(\"materail\", \"%s\");\n", item_temp->query("material1"));
                buf += sprintf("\t\tset(\"wield_msg\", \"%s\\n\");\n", item_temp->query("wield_msg"));
                buf += sprintf("\t\tset(\"unwield_msg\", \"%s\\n\");\n", item_temp->query("unwield_msg"));
                buf += sprintf("\t}\n");
                buf += sprintf("\tinit_%s(%d);\n", item_temp->query("type"), item_temp->query("point"));
                buf += sprintf("\tsetup();\n");
                buf += sprintf("}\n");
        } else
        {
                // 生成防護道具文件
                string desc;            // 道具的描述
                if (item_temp->query("material2") == "")
                {
                        desc = "這是由" + item_temp->query("material1") + "煉制而成的一" +
                                item_temp->query("unit") + item_temp->query("ctype") + "。\\n";
                } else
                {
                        desc = "這是由" + item_temp->query("material1") + "輔以" + 
                                item_temp->query("material2") + "煉制而成的一" +
                                item_temp->query("unit") + item_temp->query("ctype") + "\\n";
                }
                desc += item_temp->query("ctype") + "上刻著一行小字：" +
                        item_temp->query("owner") + "(" + item_temp->query("ownerid") + ")\\n";
                // 自動補充空信息
                if (item_temp->query("wear_msg") == "")
                {
                        item_temp->set("wear_msg", YEL "$N隨手一揮，披上了" +
                                        item_temp->query("item/name") + YEL "。" NOR);
                }
                if (item_temp->query("remove_msg") == "")
                {
                        item_temp->set("remove_msg", YEL "$N略微一抖，收起了" +
                                        item_temp->query("item/name") + YEL "。" NOR);
                }
                buf += "#include <armor.h>\n\n";
                buf += "inherit " + item_temp->query("inherit") + ";\n\n";
                buf += @ITEMCODE
string query_autoload() { return "1"; }

void autoload(string param)
{
}

void create()
{
ITEMCODE;               
                buf += sprintf("\tset_name(\"%s\", ({ \"%s\" }));\n", 
                                item_temp->query("item/name"), item_temp->query("item/id"));
                buf += sprintf("\tset_weight(%d);\n", item_temp->query_weight());
                buf += @ITEMCODE
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("item_make", 1);
                set("item_file_name", __FILE__);
ITEMCODE;
                buf += sprintf("\t\tset(\"unit\", \"%s\");\n", item_temp->query("unit"));
                buf += sprintf("\t\tset(\"long\", \"%s\\n\");\n", desc + item_temp->query("long"));
                buf += sprintf("\t\tset(\"value\", %d);\n", item_temp->query("value"));
                buf += sprintf("\t\tset(\"materail\", \"%s\");\n", item_temp->query("material1"));
                buf += sprintf("\t\tset(\"wear_msg\", \"%s\\n\");\n", item_temp->query("wear_msg"));
                buf += sprintf("\t\tset(\"remove_msg\", \"%s\\n\");\n", item_temp->query("remove_msg"));
                buf += sprintf("\t\tset(\"armor_prop/armor\", %d);\n", item_temp->query("point"));
                buf += sprintf("\t}\n");
                buf += sprintf("\tsetup();\n");
                buf += sprintf("}\n");
        }       
        if (save_item_file(filename, buf) == 1)
        {
                return filename;
        }
        return "";
}

// filename 是寫入文檔的名稱，已經包含有路徑
// content 是寫入文檔的內容
int save_item_file(string filename, string content)
{
        rm(filename);
        write(content);
        if ( write_file(filename, content) )
        {
                write("成功的生成了文擋！\n");
                return 1;
        } else
        {
                write("寫入檔案(" + filename + ")時出錯，請通知巫師處理。\n");
                return 0;
        }
}


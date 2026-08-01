// 道具生成器 itemmaker.c 
// Written by Doing Lu    1998/11/2

#define	ITEM_DIR	"/d/item/make/"

// 生成道具文档, 需要一个的道具粗坯对象 item_temp (object is ITEM_DIR/origin.c)
// 生成以后建立 ITEM_DIR/???.c 然后删除旧的 item_temp, 生成一件新的道具，返回文件名

// 关于item_temp各个属性的说明
// ------ 用户可以描述的属性
// name			道具的名称， 必须要
// id			道具的ID，   必须要
// long			道具的描述，系统会在生成道具时自动添加关于炼制原料的描述
// wield_msg		装备武器的描述，如果没有系统会自动生成
// unwield_msg		收回武器时的描述
// wear_msg		穿上护甲时的描述
// unwear_msg		脱掉护甲时的描述

// ------ 不是用户描述的属性
// owner		制造者
// material1		原料1
// material2		原料2，可以没有
// unit			单位，系统自动生成
// point		道具的伤害力/防御力
// item_type		道具的类型 weapon 或 armor
// type			道具的类别 weapon 为 sword, blade, whip, stick ； armor 为 armor
// ctype		道具的类别的中文名 weapon 为 剑、刀、鞭、杖 ； armor 为 护甲
// weigth		道具的重量
// value		道具的价值

// ------ 说明是用户自练的道具的属性
// item_make		1

int save_item_file(string filename, string content);

string create_file(object item_temp) {
  string buf;   // 生成文件的缓冲区
  string filename;
  int i;

  // 生成文件名
  for (i = 0; i < 100; i++) {
    filename = ITEM_DIR + item_temp->query("ownerid") + sprintf("%d.lpc", random(8999) + 1000);
    if (file_size(filename) <= 0) break;
  }
  if (i >= 100) {
    write("无法生成档案，请通知巫师处理。\n");
    return 0;
  }
  buf = "// ITEM Made by player " + filename + "\n// Written by ITEMMAKER(Doing Lu 1998/11/2)\t" + ctime(time()) + "\n";
  if (item_temp->query("item_type") == "weapon") {
    // 生成武器道具文件
    string desc;  // 武器的描述
    if (item_temp->query("material2") == "") {
      desc = "这是由" + item_temp->query("material1") + "炼制而成的一" + item_temp->query("unit") + item_temp->query("ctype") + "。\\n";
    } else {
      desc = "这是由" + item_temp->query("material1") + "辅以" + item_temp->query("material2") + "炼制而成的一" + item_temp->query("unit") + item_temp->query("ctype") + "\\n";
    }
    desc += item_temp->query("ctype") + "柄上刻着一行小字：" + item_temp->query("owner") + "(" + item_temp->query("ownerid") + ")\\n";
    // 自动补充空信息
    if (item_temp->query("wield_msg") == "") {
      item_temp->set("wield_msg", "$N一声清啸，抖出一" +
        item_temp->query("unit") + item_temp->query("item/name") + "。");
    }
    if (item_temp->query("unwield_msg") == "") {
      item_temp->set("unwield_msg", "$N随手一抹，收起了" +
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
  } else {
    // 生成防护道具文件
    string desc;  // 道具的描述
    if (item_temp->query("material2") == "") {
      desc = "这是由" + item_temp->query("material1") + "炼制而成的一" + item_temp->query("unit") + item_temp->query("ctype") + "。\\n";
    } else {
      desc = "这是由" + item_temp->query("material1") + "辅以" + item_temp->query("material2") + "炼制而成的一" + item_temp->query("unit") + item_temp->query("ctype") + "\\n";
    }
    desc += item_temp->query("ctype") + "上刻着一行小字：" + item_temp->query("owner") + "(" + item_temp->query("ownerid") + ")\\n";
    // 自动补充空信息
    if (item_temp->query("wear_msg") == "") {
      item_temp->set("wear_msg", YEL "$N随手一挥，披上了" +
        item_temp->query("item/name") + YEL "。" NOR);
    }
    if (item_temp->query("remove_msg") == "") {
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
  if (save_item_file(filename, buf) == 1) {
    return filename;
  }
  return "";
}

// filename 是写入文档的名称，已经包含有路径
// content 是写入文档的内容
int save_item_file(string filename, string content) {
  rm(filename);
  write(content);
  if (write_file(filename, content)) {
    write("成功的生成了文挡！\n");
    return 1;
  } else {
    write("写入档案(" + filename + ")时出错，请通知巫师处理。\n");
    return 0;
  }
}

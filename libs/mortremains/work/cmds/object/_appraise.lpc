/* _appraise.c - The wizard item appraisal command.
 *
 * (05-06-96) Written by Chronos.
 * (04-10-98) Revamped by Chronos@NK.
 */

#include <mudlib.h>

int cmd_appraise(string str) {
    object ob;
    if (!str) {
	notify_fail("Appraise what?\n");
	return 0;
    }
    ob = present(str, TP);
    if (!ob)ob = present(str, environment(TP));
    if (!ob) {
	notify_fail("Appraise: Cannot find object.\n");
	return 0;
    }
    if (living(ob)) {
	notify_fail("Appraise: Object is living; use stat instead.\n");
	return 0;
    }
    write("  Appraisal of '"+str+"' ... "+identify(ob)+"\n\n");
    write("  Value: "+(int)ob->query("value")+" coins.\t\t");
    if (ob->query("armor_object")) 
    {
        write("Armor: "+capitalize((string)ob->query("type")) + ", AC "+
   (int)ob->query("armor")) ;
  if (ob->query("bonus")) write(" (+"+ob->query("bonus")+")\n") ;
  else write("\n") ;
	if ((int)ob->query("size")==-1) {
   write("  Size: -1 (Anyone can use it.)") ;
	} else {
   write("  Size: "+ob->query("size") + "\t\t") ;
	}
    }
    else if (ob->query("weapon"))
    {
	write("Weapon: "+capitalize((string)ob->query("weapon_type_set")) + ", WC "+
	  (int)ob->query("weapon")+"\n");
	if ((int)ob->query("size")==-1) 
      write("  Size: -1 (Anyone can use it.)") ;
  else write("  Size: "+ob->query("size") + "\t\t") ;
    }
    else if (ob->query("container")) 
        write("Container.\n  Size: Irrelevant.") ;
  else write("Miscellaneous object.\n  Size: Irrelevant.") ;
  if (ob->query("material_type"))
  write("\tMaterial: "+capitalize((string)ob->query("material_type")) + 
   ".\n") ;
  else write("\t\tMaterial: Irrelevant.\n") ;
    write("  Mass: "+(int)ob->query("mass"));
    if (ob->query("to_hit_adj")) 
    {
	write("\t\t\tTo Hit Adjustment: +"+(int)ob->query("to_hit_adj") ) ;
	write("\n") ;
    }
  else write("\n") ;
    write("  Bulk: "+(int)ob->query("bulk"));
    if (ob->query("dam_adj")) 
	write("\t\t\tDamage Adjustment: +"+(int)ob->query("dam_adj") ) ;
  write("\n") ;
   write("------------------------------------------------------------------\n");
    if (ob->query("nosecond")) write("This is a two-handed weapon.\n");
    if (ob->query("second")) write("This is a suitable second weapon.\n");
    if (ob->query("prevent_clean")) 
	write("This object can not be cleaned.\n");
    if (ob->query("prevent_drop")) 
	write("This object can not be dropped.\n");
    if (ob->query("prevent_sell")) 
	write("This object can not be sold.\n");
    if (ob->query("hit_func")) 
	write("** This weapon has a special hit function.\n");
    if (ob->query("prevent_give")) 
	write("This object can not be given away.\n");
    if (ob->query("prevent_get")) 
	write("This object can not be picked up.\n");
    if (ob->query("destruct_when_sold")) 
	write("This object will be destroyed when/if it is sold.\n");
    if (ob->query("equip_func")) 
	write("This armor has a special wear function.\n");
    if (ob->query("unequip_func") )
	write("This armor has a special remove function.\n");
    if (ob->query("cursed")) 
	write("This object carries a curse of some sort.\n");
    if (ob->query("enchanted"))
	write("This object carries an enchantment of some sort.\n");
    if (ob->query("wield_func"))
	write("This armor has a special wield function.\n");
    if (ob->query("unwield_func"))
	write("This armor has a special unwield function.\n");
    if (ob->query("charges"))
	write("This item has "+(int)ob->query("charges")+" charges.\n");
    if (ob->query("raise_stat")) 
	write("This item has the power to raise a player's stats.\n");
    if (ob->query("author"))
	write("This item was coded by "+capitalize(ob->query("author"))+
	  ".\n") ;
    return 1;
}

string help() {
  return @ENDHELP
Usage: appraise <item>

Used by wizards to get quick information on an object.

Another fun wizard utility brought to you by Chronos!
ENDHELP
  ;
}
/* EOF */


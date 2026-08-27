/* Taniwha 1995. code for giving players the cloud spells */
/* the givee's are in the Hoerk quest
*/
int add_spell(object tp,int x)
{
   switch(tp->query_guild_name())
   {
      case "Grimbrand":
      case "timion":
      case "Cyrcia":
   case "ducky":
   case "virga":
      case "cle-war":
      case "hokemj":
      case "taniwha":
      case "paladin":
      case "antipaladin":
         tp->add_spell("sex change","sex_change",1);
      break;
      case "wizard":
      case "drow_wizard":
      case "necromancer":
      case "conjurer":
      case "abjurer":
      case "enchanter":
      case "illusionist":
      case "invoker":
      case "wiz-war":
      case "transmuter":
      case "wizthief":
      case "bard":
      case "aphelic" :
         tp->add_spell("mirror image","mirror",1);
      break;
      }
}

/* Taniwha 1995. code for giving players the cloud spells */
/* the givee's are in the Hoerk quest
*/
int add_spell(object tp,int x)
{
   switch(tp->query_guild_name())
   {
      case "timion":
      case "Cyrcia":
   case "ducky":
   case "virga":
      case "cle-war":
      case "hokemj":
      case "taniwha":
      case "paladin":
      case "antipaladin":
      case "Grimbrand":
         if(x) tp->add_spell("blade barrier","bbarrier",1);
         else tp->add_spell("silence","silence",1);
      break;
      case "wizard":
      case "drow_wizard":
      case "necromancer":
      case "conjurer":
      case "abjurer":
      case "enchanter":
      case "illusionist":
      case "invoker":
      case "transmuter":
      case "bard":
         if(x) tp->add_spell("confusion","ccloud",1);
         else tp->add_spell("stinking cloud","scloud",1);
      break;
      // Taniwha. 1995. They have a cloud spell, these are more use.
      case "wiz-war":
      case "wizthief":
         if(x) tp->add_spell("fireball","fireball",1);
         else tp->add_spell("snowball swarm","snowball",1);
      break;
      }
}

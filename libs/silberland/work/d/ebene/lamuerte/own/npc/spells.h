void spell_poison( object enemy, int damage, mixed dam_type)
{
    enemy->AddPoison(1+random(2));
 return;
}

void spell_shielddestruct( object enemy, int damage, mixed dam_type)
{

object *things;
object ob;
int x;

 things=enemy->QueryProp(P_ARMOURS);

 for(x=sizeof(things)-1;x>=0;x--){
    ob=things[x];
    if(ob->QueryProp(P_ARMOUR_TYPE) == AT_SHIELD ){
      tell_object(enemy,"  "+Name(WER,2)+" trifft Dein Schild mit voller Kraft!\n");
      ob->Damage(1);
      if(random(100)>=80 && !ob->id("NODESTRUCT") && !ob->QueryProp(P_CURSED) ){
        tell_object(enemy,"  "+Name(WER,2)+" zerstoert "+ob->name(WEN,1)+"!\n");
        ob->remove( 1 );
      }
    }
  }
 return;
}


void spell_weapondestruct( object enemy, int damage, mixed dam_type)
{

object ob;
int x;

    if(ob=enemy->QueryProp(P_WEAPON) && !ob->id("NODESTRUCT") && !ob->QueryProp(P_CURSED) ){
      if(random(1000)>=990){
        tell_object(enemy,"  "+Name(WER,2)+" zerstoert "+ob->name(WEN,1)+"!\n");
        ob->remove( 1 );
        return;
      }
      else if(enemy->QueryProp(P_WEAPON) && random(1000)>700 && !ob->QueryProp(P_CURSED) ){
        tell_object(enemy,break_string("  "+Name(WER,2)+" reisst Dir "+ob->name(WEN,1)+
              " aus den Haenden und steckt "+ob->QueryPronoun(WEN)+" ein!\n", 78));
        ob->move(this_object(),M_NOCHECK);
        return;
      }
      else{
        tell_object(enemy,"  "+Name(WER,2)+" schafft es nicht Dir Deine Waffe "
            "wegzunehmen.\n");
        return;
      }
    }
        tell_object(enemy,"  "+Name(WER,2)+" schaut verbluefft, als "+
            QueryPronoun(WER)+" merkt das Du keine Waffe gezueckt hast.\n");
 return;
}


void spell_moneydestruct( object enemy, int damage, mixed dam_type)
{
object ob;
    if(ob=deep_present("\ngeld",enemy)){
      tell_object(enemy,"  "+Name(WER,2)+" klaut Dir Geld und frisst es auf!\n");
        ob->AddAmount(-(1000+random(2000)));
    }
 return;
}


void spell_hold( object enemy, int damage, mixed dam_type)
{
  int t;

  t=random(2)+(this_object()->QueryProp(P_LEVEL)/3);
  
  if(!enemy->QueryProp(P_TMP_MOVE_HOOK)){
    enemy->SetProp(P_TMP_MOVE_HOOK, ({ time()+t,
                    this_object(), "player_tries_to_move" }) );
  }

return;
}

string player_tries_to_move(object pl,string dir,mapping dest)
{
  return("Du kannst nicht Laufen, Deine Beine sind gelaehmt!\n");
}

void spell_flue( object enemy, int damage, mixed dam_type)
{
  if(random(100)>50){
    clone_object("/d/dschungel/dante/weg/obj/dmala.lpc")->move(enemy,M_NOCHECK);
  }
  return;
}

void spell_backspeech( object enemy, int damage, mixed dam_type)
{
  if(!present("backspeech",enemy)) 
      {
  if(random(100)>50){
      clone_object("/d/seher/angrox/obj/backspeech.lpc")->move(enemy,M_NOCHECK);
      } 
  }
  return;
}



void spell_brainstorm( object enemy, int damage, mixed dam_type)
{
    clone_object("/d/ebene/lamuerte/brunnen/spellobj/brainstorm.lpc")->move(enemy,M_NOCHECK);
  return;
}

void spell_manadrain( object enemy, int damage, mixed dam_type)
{
    clone_object("/d/ebene/lamuerte/brunnen/spellobj/mana_drain.lpc")->move(enemy,M_NOCHECK);
  return;
}

void spell_strengthdrain( object enemy, int damage, mixed dam_type)
{
    clone_object("/d/ebene/lamuerte/brunnen/spellobj/strength_drain.lpc")->move(enemy,M_NOCHECK);
  return;
}
void spell_bloodloss( object enemy, int damage, mixed dam_type)
{
    clone_object("/d/ebene/lamuerte/brunnen/spellobj/bloodloss.lpc")->move(enemy,M_NOCHECK);
  return;
}


void spell_tarn( object enemy, int damage, mixed dam_type)
{
  string dammsg;
  mixed *damtype;
  int dam;
  object ob,ME,fake;

  ME=this_object();
  fake=enemy;
  
  if(this_object()->QueryProp("tarned")!=1) {
    tell_object(enemy,"  "+this_object()->QueryProp(P_SHORT)+" tarnt sich als DU SELBST!\n");
    if(enemy->QueryProp(P_LEVEL)>20 && enemy->QueryProp(P_LEVEL)<=100) {
        ME->create_default_npc((enemy->QueryProp(P_LEVEL))/2);
       }
       else{
       ME->create_default_npc(10);
       }
    ME->SetProp(P_ARTICLE,0);
    ME->SetProp(P_GENDER, fake->QueryProp(P_GENDER));
    ME->SetProp(P_NAME, fake->QueryProp(P_NAME));
    ME->SetProp(P_SHORT, fake->QueryProp(P_PRESAY)+QueryProp(P_NAME)+" " +fake->QueryProp(P_TITLE));
    ME->SetProp(P_LONG, fake->long());
    ME->AddId(lower_case(QueryProp(P_NAME)));
    ME->SetProp(P_MSGIN, fake->QueryProp(P_MSGIN));
    ME->SetProp(P_MSGOUT, fake->QueryProp(P_MSGOUT));
    if(ob=fake->QueryProp(P_WEAPON)) {
      dammsg=sprintf(" mit eine%s %s", ob->QueryProp(P_GENDER)==FEMALE?"r":"m",
      ob->QueryProp(P_NAME));
      damtype=ob->QueryProp(P_DAM_TYPE);
      dam=ob->QueryProp(P_WC);
     }
    else {
      dammsg=fake->QueryProp(P_HANDS)[0];
      damtype=fake->QueryProp(P_HANDS)[2];
      dam=fake->QueryProp(P_HANDS)[1];
         }

    ME->SetProp(P_HANDS, ({dammsg, 500+dam, damtype}));
    ME->SetProp("tarned",1);
    return ;
    
  }
  return;
}

string well_level()
{
    string roomname;

    if(!environment(previous_object())) return 0;
       roomname=file_name(environment(previous_object()));
        if(roomname[0..36]!="/d/ebene/lamuerte/brunnen/rooms/level") return 0;
          if(roomname[38..38]=="/")
          return (roomname[37..37]);
            else
          return (roomname[37..38]);
}


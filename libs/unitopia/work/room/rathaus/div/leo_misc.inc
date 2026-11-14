// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /room/rathaus/div/leo_misc.inc
// Description: Sonstige Dinge von Leo, unserm tollen Goetterboten
// Author:
// Modified by:
//
// $Log: leo_misc.inc,v $
// Revision 1.18  2015/08/18 17:38:55  myonara
// will [keine] gummigoettchen => an/aus
//
// Revision 1.17  2014/12/09 15:58:53  myonara
// Hinweis Kobold und Orkmist eingebaut.
//
// Revision 1.16  2014/11/11 16:38:06  myonara
// Hinweise fuer Treppennische eingebaut
//
// Revision 1.15  2009-02-06 22:38:09  menaures
// Sin: Orkschlaechter-Log
//
// Revision 1.14  2007-08-30 20:33:48  gnomi
// Typo.
//
// Revision 1.13  2006/05/12 10:00:27  gnomi
// Leo gruesst nur zurueck, wenn er denjenigen nicht schon begruesst hat.
//
// Revision 1.12  2004/11/27 21:41:07  menaures
// "will helfen" fuer Orkschlaechter-Raetsel
//
// Revision 1.11  2003/12/15 00:03:08  gnomi
// Einige static-Funktionen privatisiert.
//
// Revision 1.10  2002/07/24 21:11:52  gnomi
// Fehler bei Auswahl der Begruessung.
//
// Revision 1.9  2001/08/30 00:53:03  sissi
// Leo begruesst jetzt Leute.
//
// Revision 1.8  2001/06/14 22:40:16  gnomi
// castle() rausgeschmissen.
//
// Revision 1.7  2001/05/18 23:06:26  gnomi
// Bugfix: Wenn ADMINS-Array leer ist, gab's ein RTE.
//
// Revision 1.6  2001/04/07 00:12:15  gnomi
// Header/CVS-Log eingebaut.
//

#define LEO_MISC_SAVE "/save/leo_misc.o"

#include <tips.h>
#include <move.h>
#include <time.h>
#include <quest.h>
#include <invis.h>

void do_sequence(mixed *arr);

void helfen(string str)
{
    if(IS_INVIS(this_player()))
    {
        if(!wizp(this_player()))
        {
            do_command("sage Mach dich doch erstmal sichtbar, "+
                       this_player()->query_real_name()+".");
        }

        return;
    }

    if(this_player()->get_one_skill( ({"skill", "raetsel", "ork-schlaechter"}) )
       == (QUEST_ROOM->query_quest_points("ork-schlaechter")) )
    {
        do_sequence( ({
            "staune",
            "sage Du hast mir doch schon geholfen!",
            "denk Mist, wo hab ich den Orkschlaechter nur hingelegt?"
        }) );

        return;
    }

    do_sequence( ({
        "emote wird hellhoerig.",
        "frage Du moechtest der Menschheit im Kampf gegen die Orks beistehen?",
        "gruebel",
        "sage Dazu musst du in das Heiligtum der Orks eindringen.",
        "denke Das ist allerdings nicht ganz ungefaehrlich.",
        "sage Dort ist der sagenumwobene Orkschlaechter verborgen, "
             "den du mir bringen musst.",
        "sage Es ist nur ein erster Schritt, aber damit waere mir "
             "schon sehr geholfen.",
        "",
        "schnipp",
        "sage In der Stadtwache wurde kuerzlich ein Ork inhaftiert.",
        "sage Vielleicht bekommst du aus ihm heraus, wo der Orkschrein "
             "versteckt ist.",
        "denke Wenn er dir nicht gleich die Kehle durchschneidet...",
        "sage Viel Erfolg!",
    }) );
}

int orkschlaechter(object ob,object woher)
{
    if (ob->query_orc_slayer())
    {
       if(woher==find_player(ob->query_quester()||""))
       {
          do_command("sage Danke!");
          QUEST_ROOM->set_quest("ork-schlaechter", Q_SOLVED, woher);
          do_command("sage Gut gemacht! Du hast das Raetsel geloest.");
          do_command("echo Leo steckt " + den(ob) + " weg.");
          log_file("LEO_ORKSCHLAECHTER",
             sprintf("%s: %O %O %O %O owner\n",
                     shorttimestr(time()), //Zeit/Datum
                     ob,                   // Orkschlaechterpfad
                     ob->query_creator(),  // creator
                     ob->query_quester(),  // eingetragener Questername
                     woher));              // Quelle des Schwerts 
          ob->remove();
          return 1;
       }
       else
       {
          object quester=find_player(ob->query_quester()||"");
          do_command("sage Danke!");
          if(quester)
	  {
             QUEST_ROOM->set_quest("ork-schlaechter", Q_SOLVED, quester);
             do_command("sage Gut gemacht! "+
                        Der(quester)+" hat das Raetsel geloest.");
          }
          do_command("echo Leo steckt " + den(ob) + " weg.");
          log_file("LEO_ORKSCHLAECHTER",
             sprintf("%s: %O %O %O %O %O not owner\n",
                     shorttimestr(time()), //Zeit/Datum
                     ob,                   // Orkschlaechterpfad
                     ob->query_creator(),  // creator
                     ob->query_quester(),  // eingetragener Questername
                     quester,              // gefundenes Questerobjekt
                     woher));              // Quelle des Schwerts 
          ob->remove();
          return 1;
       }
    }
    else
    {
       do_command("sage Nette Faelschung.\n");
       return 0;
    }
}

mapping gegruesst = ([:0]);

void gruss(string str)
{
    gegruesst = filter(gegruesst, (: present($1, environment()) :));
    if(member(gegruesst, this_player()))
	return;
    else
	m_add(gegruesst, this_player());
    do_command("sage Willkommen, "+this_player()->query_cap_name()+".");
}

void begruessung()
{
    if (!this_player() || !present (this_player(),environment())
        || (this_player()->query_invis()))
        return;

    gegruesst = filter(gegruesst, (: present($1, environment()) :));
    m_add(gegruesst, this_player());
    
    if (spielerratp (this_player())) {
        do_command ("sage Seid gegruesst, "+
            ((["weiblich":"Spielerraetin","maennlich":"Spielerrat",
              "saechlich":"Spielerratendes"])
            [this_player()->query_gender()])+
            " "+this_player()->query_cap_name()+".");
        return;
    }
    if (adminp (this_player())) {
        do_command ("sage Hallo, "
           +this_player()->query_cap_name()+".");
        exec_command ("knuddle",this_player());
        return;
    }
    if (lordp (this_player())) {
        do_command ("sage Es ist mir eine Ehre, "+
            ((["weiblich":"verehrte Lady","maennlich":"verehrter Lord",
              "saechlich":"verehrtes Lordwesen"])
            [this_player()->query_gender()])+
            " "+this_player()->query_cap_name()+".");
        exec_command ("verneige",this_player(),"tief");
        return;
    }
    if (wizp (this_player())) {
        do_command ("sage Seid willkommen, "+
            ((["weiblich":"Goettin","maennlich":"Gott",
              "saechlich":"Gottwesen"])
            [this_player()->query_gender()])+
            " "+this_player()->query_cap_name()+".");
        exec_command ("verneige",this_player());
        return;
    }
    if (hlpp (this_player())) {
        do_command ("sage "+
          (IS_DAY ? "Guten Tag, " : "Gute Nacht, ")+
            ((["weiblich":"Engelin","maennlich":"Engel",
              "saechlich":"Engelwesen"])
            [this_player()->query_gender()])+
            " "+this_player()->query_cap_name()+
            ", seid herzlichst gegruesst.");
        do_command ("ruempfe ein wenig");
        return;
    }
    do_command ("sage "+
      (IS_DAY ? "Guten Tag, " : "Gute Nacht, ")+
        ((["weiblich":"liebe","maennlich":"lieber",
          "saechlich":"liebes"])
        [this_player()->query_gender()])+
        " "+this_player()->query_cap_name()+
        ", seid herzlichst gegruesst.");
    exec_command ("laechle",this_player());

}

void keingott(string str)
{
    if(wizp(this_player()))
       do_command("sage Das haettest Du Dir frueher ueberlegen sollen!\n");
    else if(hlpp(this_player()))
       do_command("sage Dann bleib einfach, was Du bist!\n");
    else
       do_command("sage Du kannst auch noch kein Gott werden.");
}

void do_admin(int i)
{
    switch(i)
    {
       case 0:
         switch(random(2))
         {
           case 0:
             exec_command("emote bricht in einen Lachkrampf aus und "
               "geht prustend in die Knie.");
             break;
           case 1:
             exec_command("emote bricht prustend vor &dem(",this_player(),
               "zusammen.");
             break;
         }
         break;
       case 1:
         exec_command("kringle");
         break;
       case 2:
       case 3:
         break;
       case 4:
         if(!present(this_player(),environment())) return;
         exec_command("betrachte",this_player());
         break;
       case 5:
         exec_command("waelz");
         break;
       case 6:
         break;
       case 7:
         exec_command("emote kann nicht mehr vor Lachen.");
         break;
       case 8:
         break;
       case 9:
         exec_command("taetschle",this_player(),"grinsend");
	 break;
       case 10:
         exec_command("sage Da werde am besten erstmal ein Gott.");
	 break;
       case 11:
         exec_command("denke Und so nach 2-3 aktiven Jahren sehen wir dann weiter.");
	 break;
       case 12:
         exec_command("huestel"); 	 	
         return;
    }
    call_out("do_admin",2,i+1);
}

mapping ma=([]);

void admin(string str)
{
    if(strstr(str," kein ")>=0 || strstr(str," nicht ")>=0)
    {
       if(adminp(this_player()))
       {
         exec_command("sage zu",this_player()," Zu spaet.");
         call_out("exec_command",2,"troeste",this_player());
       }
       else
         exec_command("sage zu",this_player()," Kein Problem. Bleibe einfach "
           "so, wie du bist.");
       return;
    }
    if(wizp(this_player()))
    {
       if(adminp(this_player()))
       {
         exec_command("sage zu",this_player()," Aehm. Schau dich mal an.");
         call_out("exec_command",2,"stupse",this_player());
         return;
       }
       exec_command("bewundere",this_player());
       call_out("exec_command",2,
         "sage zu",this_player(),"Da wende dich am besten mal direkt "
         "vertrauensvoll an "+liste(map(ADMINS,#'capitalize)," oder ")+".");
       return;
    }
    if(find_call_out("do_admin")<0)
       do_admin(0);
    if(IS_INVIS(this_player()) ||
       lower_case(this_player()->query_name()) !=
       this_player()->query_real_name())
         return;
    if(!guestp(this_player())) ma[this_player()->query_real_name()]=5;
    rm(LEO_MISC_SAVE); write_file(LEO_MISC_SAVE,save_value(ma));
}

protected void init_misc()
{
    string str;
    add_init_ob(this_object());
    str=read_file(LEO_MISC_SAVE);
    if(str) ma=restore_value(str);
    add_controller("notify_seele",this_object());
}

void monster_init(object to, object wer)
{
    call_out("monster_init_ca",2,wer);
}

void monster_init_ca(object wer)
{
    string rn;
    if(!wer || !present(wer,environment()) || IS_INVIS(wer) ||
       !ma[rn=wer->query_real_name()] ||
       lower_case(wer->query_name()) != rn)
         return;
    ma[rn]--;
    if(!ma[rn]) ma-=([rn]);
    rm(LEO_MISC_SAVE); write_file(LEO_MISC_SAVE,save_value(ma));
    switch(random(5))
    {
      case 0:
        exec_command("grins",wer,"breit");
        break;
      case 1:
        exec_command("grins",wer);
        break;
      case 2:
        exec_command("taetschle",wer);
        break;
      case 3:
        exec_command("grins");
        break;
      case 4:
        exec_command("stoehn");
        break;
    }
}

void do_sequence(mixed *arr)
{
  if(!this_player() || !present(this_player(),environment()) ||
    IS_INVIS(this_player()) || !sizeof(arr))
      return;
  apply(#'exec_command,arr[0]);
  call_out("do_sequence",2+random(3),arr[1..<1]);
}

void wiegehts(string str)
{
  do_sequence( ({
    ({
      "seufz",
      "sage Ach, weisst du...",
      "sage Jeden Tag hier stehen und zu sehen, wie alle nur an einem "
            "vorbeirennen, ist auf die Dauer recht langweilig.",
      "sage Aber die Goetter sind nett zu mir.",
      "sage Sie laden mich sogar manchmal auf ihre Partys ein.",
      ({"fluestere",this_player(),"Das duerfte ich eigentlich gar nicht verraten."}),
      ({"tuschle",this_player(),"Aber wenn du wuesstest, was auf diesen Partys los ist..."})
    }),
    ({
      "sage Danke der Nachfrage, mir geht es gut.",
    }),
    ({
      "sage Gut, Danke.",
    }),
    ({
      "seufz",
      "sage Du solltest mal den ganzen Tag hier stehen...",
      "sage Aber ich weiss ja, ihr habt besseres zu tun.",
      "",
      ({"frage ",this_player(),"Wann macht ihr mal wieder eine kleine Party?"}),
      "denke So mit Schiffe versenken, Engel abschiessen..."
    }) })[(random(5)+(wizp(this_player())?2:1))/2]);


}

void werbistdu(string str)
{
  if(wizp(this_player()))
    do_sequence( ({
      ({"sage Du kennst mich nicht mehr?",
        "seufz sehr tief.",
        "sage Ich war derjenige, der dich zum Engel machte.",
        "sage Und dich danach im Kreis der Goetter Willkommen hiess.",
        "sage Man nennt mich Leo, den Goetterboten.",
        "seufz",
      }),
      ({({"emote schaut &den(",this_player(),") sorgenvoll an."}),
        "denke Und schon wieder einer, der mich vergessen hat...",
        ({"sage zu",this_player(),"Ich heisse Leo. Leo, der Goetterbote."})
      }),
      ({({"frage",this_player(),"Hallo? Erkennst du mich nicht?"}),
        ({"frage",this_player(),"Leo? Ich heisse Leo!"}),
        "sage Der Goetterbote.",
        "sage Ich war der Typ, der dich zum Engel erhob.",
        "sage Ich war auch da, als du Lehrling im Pantheon wurdest.",
        "nicke"
      }) })[random(3)]);
  else if(hlpp(this_player()))
    do_sequence( ({
      ({({"grummel",this_player()}),
        "denke Kaum Engel, vergessen sie einen wieder...",
        "seufz"
      }),
      ({"sage Ich bin Leo.",
        "sage Der Goetterbote.",
        "sage Der Typ, der dich zum Engel erhob.",
        ({"frage",this_player(),"Erinnerst du dich noch?"})
      }) })[random(2)]);
  else
    do_sequence( ({
      ({"sage Ich bin Leo.",
        "sage Der Goetterbote."}),
      ({"sage Ich heisse Leo.",
        "sage Ich kuemmere mich ein wenig um die Engel, oder besser welche, "
          "die Engel werden wollen.",
      }) })[random(2)]);
}

void kobold(string str)
{
    do_command("sage Der Kobold haust hier in einer Ecke.");
}

//Reaktionen, auf Seele-Befehle mit Leo als Partner.
//0 steht fuer den Ausloeser.
nosave mapping personal_soul_reactions=
  ([
    MIES: ({({"grummle",0}),({"knurre",0})}),
    NEUTRAL:({({}),({}),({}),({}),({"ich schaut &den(",0,") an."})}),
    NETT: ({({}),({}),({"laechle",0})}),
    "schmieg":({({}),({"sage Na na!"})}),
    "begruess":({({"verneige",0})}),
    "dank":({({"laechle",0})}),
    "droh":({({"knurre",0}),({"taetschel",0})}),
    "entschuldige":({({"ich schaut &den(",0,") erstaunt an."}),({"frage",0,"Wofuer entschuldigst du dich?"})}),
    "gaehn":({({"gaehne zurueck"})}),
    "gratulier":({({"danke",0})}),
    "grummel":({({"grummel",0}),({"knurre",0}),({"taetschel",0})}),
    "hechel":({({"taetschle",0})}),
    "jammer":({({"troeste",0})}),
    "kitzel":({({})}),
    "knicks":({({"verneige",0})}),
    "knuddel":({({"verneige",0})}),
    "knurr":({({"knurre zurueck"}),({"grummel",0})}),
    "knutsch":({({"erroete"})}),
    "kuess":({({"erroete"})}),
    "kuschel":({({"erroete"}),({"emote schaut verwirrt."})}),
    "laechel":({({"laechle zurueck"})}),
    "maul":({({"zucke"})}),
    "nick":({({"nicke",0})}),
    "nies":({({"sage zu",0," Gesundheit!"})}),
    "noergel":({({"zucke"}),({"taetschel",0})}),
    "quengel":({({})}),
    "schimpf":({({"taetschel",0})}),
    "schmus":({({"erroete",0})}),
    "schnurr":({({"taetschle",0})}),
    "schrei":({({"frage",0,"Wie Bitte?"})}),
    "starr":({({"starre",0})}),
    "stier":({({"stiere",0})}),
    "strahl":({({"laechle",0})}),
    "stups":({({})}),
    "umarm":({({"umarme",0}),({"laechle",0,"lieb"})}),
    "verabschiede":({({"winke",0})}),
    "verbeug":({({"verneige",0})}),
    "verneig":({({"verneige",0})}),
    "wein":({({"troeste",0})}),
    "wink":({({"winke",0})}),
    "wuerg":({({"ich ringt nach Luft."})}),
    "wuschel":({({"denke Ja, ja. Und dann muss heute Abend "+
                capitalize((ADMINS+({"Jemand"}))[random(sizeof(ADMINS))])+
                " Ueberstunden machen, nur um meine Frisur wieder hinzubekommen."}),
                ({"seufz"}),({})}),
    "zwinker":({({"zwinker",0})}),
  ]);

//Seele-Reaktionen ohne Partner
nosave mapping soul_reaction_wp=
  ([
    "seufz":({({"troeste",0}),({})}),
    "wein":({({"troeste",0})}),
    "wink":({({"winke",0})}),
  ]);

void notify_seele(object wer, mixed wen, mixed what, string adverb, int align,
        int flags, int msg_typ_wer, int msg_typ_wen, int msg_typ_andere)
{
  if(wer==this_object()) return;
  if(wen==this_object())
  {
    if(!member(personal_soul_reactions,what)) what=align;
    apply(#'call_out,#'exec_command,1+random(4),
      map(personal_soul_reactions[what]
        [random(sizeof(personal_soul_reactions[what]))],
        (:$1||$2:),wer));
  }
  else if((!wen) && member(soul_reaction_wp,what))
    apply(#'call_out,#'exec_command,1+random(4),
      map(soul_reaction_wp[what][random(sizeof(soul_reaction_wp[what]))],
        (:$1||$2:),wer));
}

void wasengel(string str)
{
  if(wizp(this_player()))
    do_sequence( ({
      ({
        "denke Das frage ich mich auch manchmal.",
	"sage Also Engel, das sind diese Leute mit den Fluegeln.",
	({"tuschle",this_player(),"Man munkelt, dass sie kaum noch laufen koennen."}),
      }),
      ({
        "sage Wenn du das nicht weisst, woher soll ich es dann wissen?"
      }) })[!random(3)]);
  else if(hlpp(this_player()))
    do_sequence( ({
      ({
        ({"deute",this_player()}),
	"sage Sowas ist ein Engel."
      }),
      ({
        "sage Also du kennst doch sicher diese Menschen mit den Fluegeln?",
	({"deute fluegel von",this_player()}),
	"sage Das sind Engel."
      }),
      ({
        "sage Also Engel sind Spieler, welche einen weiten Weg gegangen sind "
	   "und deshalb von den Goettern einige Gaben erhalten."
      }) })[random(3)]);
  else
    do_sequence( ({
        "sage Engel sind Spieler, die einen weiten Weg gegangen sind und "
	   "fuer ihr Wissen und ihre Erfolge durch die Goetter belohnt werden.",
	"sage Sie erhalten von den Goettern schoene Gaben.",
	({"fluestere",this_player(),"Es sollen sogar einige grosse Erzengel "
	   "leben, welche gottgleiche Gaben besitzen."})
      }) );
}

void wasgott(string str)
{
  if(wizp(this_player()))
    do_sequence(
      ({
        ({"betrachte",this_player()}),
	"sage Goetter, das sind die armen Schweine, deren einziger "
	  "Daseinszweck darin besteht, unser Magyra zu erhalten und auszubauen.",
	"sage So ein Gott, der hat es ja nicht leicht.",
	"sage Dauernd nur arbeiten und die Wuensche der Spieler erfuellen...",
	({"fluestere",this_player(),"Wann gibt's die naechste Party?"})
      }) );
  else 
  {
   do_command("sage Hinweise zur Gottwerdung sind in der betretbaren Nische "
              "unter der Treppe zu finden.");
   do_sequence( ({
     ({//Erstmal 'hilfe gott' einarbeiten...
       "sage Das Leben eines Gottes in Magyra ist hart.",
       "sage Sein einziger Daseinszweck ist die Erhaltung und Erweiterung Magyras.",
       ({"fluestere",this_player(),"So sollte man sehr, sehr vorsichtig sein, "
         "wenn man einem Gott begegnet, denn durch die ganze Arbeiterei sind "
	 "Goetter sehr leicht reizbar und unberechenbar."}),
       "sage Bitte nie einen Gott um einen Gefallen.",
       "sage Du koenntest das bekommen, was Du willst und noch VIEL mehr!",
       "sage Der Friedhof ist voller Spielern, denen geholfen wurde...",
       "nicke ernst"
     }),
     ({
       "sage Die Goetter haben all das hier erschaffen.",
       "sage Ohne sie gaebe es hier gar nichts.",
       "emote erschaudert."
     }),
     ({
       "sage Die Goetter sind die maechtigsten Wesen in ganz Magyra.",
       "sage Kein anderes Wesen kann es mit ihnen aufnehmen.",
       ({"sage zu",this_player(),"Deshalb sei auch Du vorsichtig Goettern "
         "gegenueber."}),
       "sage Es koennte fuer Dich sehr ungesund werden, einen Gott zu reizen."
     }) })[random(3)]);
   }
}

void gummiaus(string str)
{
    if (this_player()->query_keine_gummigoettchen())
    {
        do_command("sage Du erhaeltst bereits keine Gummigoettchen mehr.");
    }
    else
    {
        this_player()->set_keine_gummigoettchen(1);
        do_command("sage Du erhaeltst nun keine Gummigoettchen mehr.");
    }
}

void gummian(string str)
{
    if (this_player()->query_keine_gummigoettchen())
    {
        this_player()->set_keine_gummigoettchen(0);
        do_command("sage Du erhaeltst nun wieder Gummigoettchen.");
    }
    else
    {
        do_command("sage Du erhaeltst schon Gummigoettchen.");
    }
}

// Jetzt kommen die Tips

void neuer_tip()
{
    object fb;
    fb = present ("formblatt",this_player());
    if (fb) {
        exec_command ("betrachte",this_player());
        do_command ("sage Aber Du hast doch schon "+ein(fb)+". "
            "Fuell das erstmal aus.");
        return;
    }
    fb = present ("tips-tool",this_player());
    if (fb) {
        exec_command ("betrachte",this_player());
        do_command ("sage Aber Du hast doch schon "+ein(fb)+". "
            "Damit kannst Du auch neue Tips hinzufuegen.");
        return;
    }
    if (!wizp (this_player())) {
        do_command ("sage Du hast einen neuen Tip? Das find ich toll! "
            "Da geb ich Dir doch gleich das einzige behoerdlich "
            "zugelassene Formblatt fuer neue Tips.");
        fb = clone_object (TIPS_FORMBLATT);
        if (!fb) {
            do_command ("sage Hmpf, die Formblaetter sind mir ausgegangen. "
                "Komm doch naechste Woche nochmal.");
            return;
        }
    } else  {
        do_command ("sage Du hast einen neuen Tip? Das find ich toll! "
            "Da geb ich Dir doch gleich das Tips Werkzeug fuer Goetter.");
        fb = clone_object (TIPS_TOOL);
        if (!fb) {
            do_command ("sage Hmpf, die Tips Werkzeuge fuer Goetter "
                "sind mir ausgegangen. "
                "Komm doch naechste Woche nochmal.");
            return;
        }
    }
    if (fb->move (this_player()) != MOVE_OK) {
        do_command ("sage Ich wuerde Dir ja gerne "+ein(fb)
            +" geben, aber das klappt nicht.");
        fb->remove ();
        return;
    }
    send_message (MT_LOOK, MA_MOVE,
        wrap (Der()+" gibt "+dem(this_player())+" "+ein(fb)+"."),
        wrap (Der()+" gibt Dir "+ein(fb)+"."),
        this_player());
}

void init()
{
    if (playerp (this_player()))
        call_out ("begruessung",4);
}


nosave mixed DHOEHLE=({ 
    "Du stehst verlassen mitten in der weiten Hoehle. ", ({ "hoehle","wand","waende"}), 
  "Weiter wanderst Du durch die weite Hoehle. ", ({ "hoehle","wand","waende" }), 
  "Die weite Hoehle zieht sich endlos weiter vor Dir her. ", ({ "hoehle","wand","waende" }), 
  "Deine Wanderung treibt Dich durch die Hoehle voran. ", ({ "wanderung","hoehle","wand","waende" }), 
  "Die Hoehle befindet sich rings um Dich herum. ", ({ "hoehle","wand","waende" }), 
  "Noch immer geht es weiter durch die Hoehle. ", ({ "hoehle","wand","waende" }), 
  "Ob die Hoehle ueberhaupt ein Ende hat? ", ({ "ende","wand","waende" }), 
  "Kann man die Hoehle absperren? ", ({ "hoehle","wand","waende" }), 
  "Du glaubst Deinen Augen nicht mehr. ", ({ "auge","augen","wand","waende" }), 
  "Die Hoehle mit all ihren Gefahren lauert schon auf Dich. ", ({ "hoehle","gefahr","gefahren","wand","waende" }), 
  "Hm, hier in der Hoehle schaut alles so gleich aus. ", ({ "hoehle","wand","waende" }), 
  "Dir gefaellt es in der Hoehle nicht. ", ({ "hoehle","wand","waende" }), 
  });

nosave mixed DFERNE=({ 
  "Die Hoehle scheint sich endlos hinzuziehen. ", ({ "hoehle" }), 
  "In der Ferne glaubst Du ein Licht zu erkennen. ", ({ "ferne","licht" }), 
  "Vor Deinen Augen verschwimmt alles. ", ({ "augen" }), 
  "Viele Hoehlenabschnitte befinden sich noch auf dem Weg vor Dir. ", ({ "abschnitt","abschnitte","hoehlenabschnitt","hoehlenabschnitte","weg" }), 
  "Hinter Dir blieben viele Spuren zurueck. ", ({ "spuren","spur" }), 
  "In der Ferne kannst Du ein paar Schatten sehen. ", ({ "ferne","schatten" }), 
  "Du kannst Dir nicht mehr denken, wie weit Du schon gewandert bist. ", ({  }), 
  "Wie weit mag sich die Hoehle wohl noch dahinziehen? ", ({ "hoehle" }), 
  "Du siehst auch in der Ferne keinen Ausweg aus der Hoehle. ", ({ "ferne","ausweg","hoehle" }), 
  "Wie gerne waerst Du jetzt schon am Ausgang, um endlich hier wegzukommen. ", ({ "ausgang" }), 
  "Es geht immer weiter. ", ({  }), 
  "Wohin wird Dich Deine Wanderung noch bringen? ", ({ "wanderung" }), 
  });

nosave mixed DBODEN=({ 
  "Der Staub knirscht unter Deinen Fuessen. ", ({ "boden","staub","fuesse" }), 
  "Auf dem Boden ist nur Staub, Staub, Staub. ", ({ "boden","staub" }), 
  "Du moechtest den Staub unter Dir nicht mehr sehen. ", ({ "boden","staub" }), 
  "Deine Fuesse sind im Staub vergraben. ", ({ "boden","fuesse","staub" }), 
  "Der feine Staub erschwert das Vorwaertskommen wirklich sehr. ", ({ "boden","staub","vorwaertskommen" }), 
  "Unter Dir befindet sich nur eins: STAUB! ", ({ "boden","staub" }), 
  "Der Staub unter Deinen Fuessen wird langsam ziemlich nervig. ", ({ "boden","fuesse" }), 
  "Es kann keinen Ort mit mehr Staub geben! ", ({ "boden","ort","staub" }), 
  "Der Staub unter Dir nimmt eher zu als ab. ", ({ "boden","staub" }), 
  "Am liebsten wuerdest Du hier eine Staubburg bauen. ", ({ "boden","staubburg" }), 
  "Der Boden ist kuehl und staubig. ", ({ "boden" }), 
  "Nur Staub, nur Staub, nur Staub, nur Staub, doch da, was? Nur Staub! ", ({ "boden","staub" }), 
  "Der Staub unter Deinen Fuessen ist grobkoernig. ", ({ "staub","fuesse" }), 
  });

nosave mixed DDECKE=({ 
  "Die Decke scheint Dich erdruecken zu wollen! ", ({ "decke" }), 
  "Die Decke ist dunkel. ", ({ "decke" }), 
  "Hier hat wohl noch nie wer geputzt. ", ({ "decke" }), 
  "Die Schatten druecken Dir auf das Gehirn. ", ({ "decke","sonne","gehirn" }), 
  "An der Decke befinden sich nur Stalagtiten. ", ({ "decke","stalagtit","stalagtiten" }), 
  "An der Decke ist kein Lebewesen zu erkennen. ", ({ "decke","lebewesen" }), 
  });

nosave mixed DSONSTIGES=({ 
  "Fast haettest Du etwas verloren und es waere fuer immer im Staub verschwunden. ", ({ "staub" }), 
  "Du hast Angst niemals wieder aus der Hoehle herauszukommen. ", ({ "angst","hoehle" }), 
  "Ob Du jemals den Ausgang aus der Hoehle finden wirst? ", ({ "ausgang","hoehle" }), 
  "Du bist froh, nicht immer hier leben zu muessen. ", ({ "" }), 
  "Wie schoen waere jetzt doch ein Glas voller Wasser! ", ({ "glas","wasser" }), 
  "Nicht ein einziger Tropfen Wasser ist zu finden. ", ({ "tropfen","wasser" }), 
  "Wie gerne wuerdest Du jetzt nur ein kuehles Bier zu Dir nehmen! ", ({ "bier" }), 
  "Hier gibt es seltsame Spuren. ", ({ "spuren" }), 
  "Wie soll man hier nur ueberleben? ", ({ }), 
  "Welch grausame Gegend die Hoehle doch ist! ", ({ "hoehle","gegend" }), 
  "Mit einem Kompass waerst Du hier sicher gut beraten. ", ({ "kompass" }), 
  "Du bist am Verdursten! ", ({  }), 
  });

nosave mapping DDETAILS=([ 
  "decke": ({ 
    "Die Decke scheint Dich zu erdruecken.", ({}), 
    "An der Decke ist nichts zu erkennen.", ({}), 
    "Du kannst nach oben schauen wieviel Du willst, da ist nichts!", ({}), 
    "Der Decke ist total langweilig hier.", ({})}), 
  "boden": ({ 
    "Der Boden ist mit Staub uebersaet.", ({ "staub" }), 
    "Der Boden besteht nur aus feinem weissem Staub.", ({ "staub" }), 
    "Der Boden ist genau unter Dir.", ({ }), 
    "Auf dem Boden ist nichts besonderes zu erkennen.", ({ }) }), 
  "staub": ({ 
    "Der Staub staubt unter Deinen Fuessen.", ({ "fuesse" }), 
    "Egal wohin Du schaust, ueberall ist nur dieser Staub.", ({ }), 
    "So langsam kannst Du den vielen Staub nicht mehr sehen.", ({ }), 
    "Du hinterlaesst ein paar sichtbare Spuren im Staub.", ({"spuren"}), 
    "Der viele Staub macht Dich noch wahnsinnig.", ({ }) }), 
  "hoehle": ({ 
    "Die Hoehle erstreckt sich in alle Richtungen.", ({ "richtungen" }), 
    "Du bist mitten in der Hoehle.", ({ }), 
    "Die Hoehle zieht sich endlos weit hin.", ({ }), 
    "Dir gefaellt es hier in der Hoehle gar nicht.", ({ }), 
    "Hoehle, Hoehle, Hoehle, Staub, Staub, Staub.. egal wohin Du schaust.", ({ "staub","hoehle" }) }), 
  "wanderung": ({ 
    "Deine Wanderung bringt Dich immer tiefer und weiter in die Hoehle.", ({ }), 
    "Deine Wanderung scheint kein Ende zu nehmen.", ({ "ende" }), 
    "Eigentlich ist es hier viel zu heiss fuer solch eine Wanderung.", ({ }), 
    "Du wuerdest Deine Wanderung lieber nicht mehr im Schatten fortsetzen.", ({ "schatten" }), 
    "Du bist hierher gekommen. Ob Du auch wieder raus findest?", ({ }) }), 
  "ende": ({ 
    "Die Hoehle muss doch eigentlich ein Ende haben.", ({ "hoehle" }), 
    "Ob das Ende der Hoehle noch sehr weit weg ist?", ({ "hoehle" }), 
    "Das Ende der Hoehle wird Dein Ende sein!", ({ "hoehle" }), 
    "Hier ist die Hoehle jedenfalls nicht am Ende.", ({ "hoehle" }), 
    "Du kannst das Ende der Hoehle hier jedenfalls nicht erkennen.", ({ "hoehle" }) }), 
  "augen": ({ 
    "Du traust Deinen eigenen Augen schon nicht mehr so recht.", ({ }), 
    "Du wischst Dir ein wenig Staub aus den Augen.", ({ "staub" }), 
    "Dir verschwimmt alles immer mehr vor Deinen Augen.", ({ }), 
    "Deine Augen sind schon voller Staub.", ({ "staub" }), 
    "Deine Augen traenen.", ({ }) }), 
  "gefahren": ({ 
    "Es gibt in der Hoehle sehr viele Gefahren!", ({ "hoehle" }), 
    "Gefahren lauern hier ueberall um Dich herum.", ({ }), 
    "Vielleicht solltest Du schnell an das Ende der Hoehle gehen!", ({ "ende","hoehle" }), 
    "Von der Decke kommen die groessten Gefahren auf Dich zu.", ({ "decke" }), 
    "Du bildest Dir schon die groessten Gefahren ein!", ({ }) }), 
  "koerper": ({ 
    "Dein Koerper ist schon ganz ausgelaugt.", ({ }), 
    "Dein Koerper ist ganz mit Staub uebersaet.", ({ "staub" }), 
    "Dein Koerper kommt Dir immer schwerer vor.", ({ }), 
    "Schweissperlen rinnen an Dir herunter.", ({ "schweissperlen" }) }), 
  "schweissperlen": ({ 
    "Viele kleine Schweissperlen rinnen an Deinem Koerper herunter.", ({ "koerper" }), 
    "Du schwitzt wie schon lange nicht mehr.", ({ }), 
    "Die Schweissperlen verdampfen bei dieser Hitze sofort.", ({ "hitze" }), 
    "Dein ganzer Koerper klebt bereits.", ({ "koerper" }), 
    "Wie schoen waer jetzt etwas zu trinken!", ({ }) }), 
  "verstand": ({ 
    "Den hast Du schon fast verloren.", ({ }), 
    "Du hattest wohl nie einen, sonst waerst Du nie in die weite Hoehle gegangen!", ({ "hoehle" }), 
    "Wo ist er denn hin?", ({ }), 
    "Sowas findest Du hier nicht mehr!", ({ }), 
    "Du verlierst fast den Verstand.", ({ }) }), 
  "schweiss": ({ 
    "Du schwitzt.", ({ }), 
    "Du hast am ganzen Koerper Schweiss.", ({ "koerper"}), 
    "Du solltest besser schnell etwas Wasser finden.", ({ "wasser" }) }), 
  "luft": ({ 
    "Die Luft flimmert vor Deinen Augen.", ({ "augen" }), 
      "Die Luft flimmert.", ({ }) }),
  "fuesse": ({ 
    "Die sind wie immer unter Dir.", ({ }), 
    "Deine Fuesse sind noch dran.", ({ }), 
    "Deine Fuesse stinken. Waeh!", ({ }) }), 
  "nasenspitze": ({ 
    "Dir ist heiss.", ({ }), 
    "Der Schweiss rinnt Dir vom ganzen Koerper.", ({ "koerper" }) }), 
  "ort": ({ 
    "Du bist in der weiten Hoehle.", ({ }), 
    "Dieser Ort wird Dich noch umbringen.", ({ }) }), 
  "ferne": ({ 
    "In der Ferne ist doch etwas. Renn schnell hin!", ({ }), 
    "Ob Du schon haluzinierst?", ({ }), 
    "Ob in der Ferne das Ende der Hoehle liegt?", ({ "ferne","hoehle" }), 
    "Hier jedenfalls wuerdest Du sterben!", ({ }), 
    "In der Ferne ist einen sich bewegenden Schatten zu erkennen.", ({ "schatten" }) }), 
  "schatten": ({ 
    "Du glaubst in der Ferne einen sich bewegenden Schatten zu erkennen.", ({ "ferne","schatten" }), 
    "Ob es in dieser Hoehle wirklich eine Oase gibt?", ({ "hoehle" }), 
    "Den Schatten hast Du Dir wohl nur eingebildet.", ({ }), 
    "Rings um Dich herum gibt es viele Schatten.", ({ }), 
    "Du stehst in einem grossen Schatten.", ({ }), 
    "Ueberall gibt es hier Schatten.", ({ }), 
    "Die Schatten umringen Dich.", ({ }) }), 
  "spuren": ({ 
    "Die Spuren duerften von Dir sein.", ({ }), 
    "Du hinterlaesst eindeutige Spuren im Staub.", ({ "staub" }), 
    "Deine Spuren verwehen im Staub.", ({ "staub" }), 
    "Du betrachtest Deine eigenen Spuren.", ({ }) }), 
  "tiere": ({ 
    "In der weiten Hoehle leben nur wenige Tiere.", ({ "hoehle" }), 
    "Die Tiere sind hier alle sehr hungrig und durstig.", ({ }), 
    "Hoffentlich faellt Dich keines der Tiere an.", ({ }) }), 
  "ausweg": ({ 
    "Es gibt keinen sicheren Ausweg aus der weiten Hoehle.", ({ }) }), 
  "ausgang": ({ 
    "Es gibt keinen sicheren Ausgang aus der weiten Hoehle.", ({ }) }), 
  "staubburg": ({ 
    "Das wuerde leider viel zu lange dauern.", ({ }), 
    "Wer soll denn in Deiner Staubburg wohnen?", ({ }), 
    "Du bist doch kein Kind mehr, oder?", ({ "kind" }) }), 
  "kind": ({ 
    "Du bist wahrlich kein Kind mehr!", ({ }), 
    "Bist Du aber kindisch!", ({ }), 
    "Du siehst hier kein kleines Kind.", ({ }), 
    "Wo nur das kleine Kind in Dir geblieben ist?", ({ }), 
    "Nur ein Kind wuerde hier ein Kind vermuten.", ({ }) }), 
  "gehirn": ({ 
    "Wo?", ({ }), 
    "Welches?", ({ }), 
    "Ausgetrocknet!", ({ }), 
    "Verdampft!", ({ }), 
    "Sowas hattest Du noch nie.", ({ }) }), 
  "lebewesen": ({ 
    "Du kannst ja mal nach anderen Lebewesen suchen.", ({ }), 
    "Manche Lebewesen hier sind sehr gefaehrlich.", ({ }), 
    "Die meisten Lebewesen in der Hoehle sind Froesche.", ({ "hoehle","froesche","frosch" }), 
    "Wie gerne wuerdest Du jetzt nur ein Lebewesen verspeisen.", ({ }), 
    "Das naechste Lebewesen, welches hier stirbt, bist wahrscheinlich Du selbst.", ({ }) }), 
  "angst": ({ 
    "Diese Angst ist auch durchaus berechtigt.", ({ }), 
    "Diese Angst ist sehr gross.", ({ }), 
    "Du schlotterst vor Angst.", ({ }), 
    "Deine Angst laesst Dich beben.", ({ }) }), 
  "kompass": ({ 
    "Vielleicht hast Du ja sogar zufaellig einen dabei?", ({ }), 
    "Der koennte Dich wahrscheinlich aus der toedlichen weiten Hoehle bringen.", ({ }), 
    "Ein Kompass waere jetzt sicher hilfreich.", ({ }), 
    "Ein Kompass kann Dich nicht vor allen Gefahren schuetzen.", ({ "gefahren" }) }), 
  "tropfen": ({ 
    "Ein einziger Tropfen Wasser ist in der Hoehle unendlich viel wert.", ({ "hoehle" }), 
    "*plitsch* *platsch* Du hast DURST!", ({ }), 
    "Was wuerdest Du jetzt nur alles zahlen fuer einen einzigen Tropfen Wasser?", ({ "wasser" }), 
    "Kein Tropfen weit und breit.", ({ }) }), 
  "bier": ({ 
    "Es gibt in der Hoehle kein kuehles Bier!", ({ }) }), 
  "gegend": ({ 
    "Die grausamste von allen!", ({ }), 
    "Ziemlich grausam hier.", ({ }), 
    "Die Hoehle ist sehr trostlos.", ({ "hoehle" }), 
    "Dir gefaellt die weite Hoehle nicht wirklich.", ({ "hoehle" }) }), 
  "richtungen": ({ 
    "In wirklich alle Richtungen.", ({ }), 
    "Nach links, nach rechts, nach oben, nach unten, nach vorne, nach hinten...", ({ }) }), 
  "pfad": ({ 
    "Wohin der Pfad genau fuehrt, wirst Du nur durch Ausprobieren herausfinden koennen!", ({ }), 
    "Dieser Pfad kann den Ausweg aus der weiten Hoehle bedeuten!", ({ }), 
    "Du solltest diesem Pfad unbedingt folgen!", ({ }), 
    "Wenn Du vom Pfad abkommst, wirst Du bestimmt sterben!", ({ }) }), 
  "wand": ({
    "Die Wand besteht aus purem Granit.", ({ "granit" }),
    "Die Wand sieht so aus, als waere sie natuerlichen Ursprungs.", ({"ursprung"}),
      "Die Wand sieht recht stabil aus, sie scheint aus purem Granit zu bestehen.", ({"granit"}) }),
  "waende": ({
    "Die Waende bestehen aus purem Granit.", ({ "granit" }),
    "Die Waende sehen so aus, als waeren sie natuerlichen Ursprungs.", ({"ursprung"}),
      "Die Waende sehen recht stabil aus, sie scheinen aus purem Granit zu bestehen.", ({"granit"}) }),
  "granit": ({
      "Alles hier scheint aus Granit zu bestehen.", ({}),
	"Die Decke und die Waende bestehen aus Granit.", ({}),
	"Sogar der Boden unter seiner dicken Staubschicht besteht aus Granit.", ({}) })
  
  ]);


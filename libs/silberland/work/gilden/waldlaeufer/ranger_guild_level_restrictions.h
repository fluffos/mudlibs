//-- Gildenstufen ------------------------------------------------------------
#define XP_PER_LEVEL\
({0, 0, 20000, 35000, 50000, 100000, 250000, 400000, 600000, 800000,\
  1000000, 1250000, 1700000, 2200000, 2800000, 3500000, 5500000,\
  6000000, 7000000, 8000000, 10000000})

//Minimum XP, wegen der Ausgabe manuell gesetzt
#define GUILD_QUESTS \
  ([ 1: "Der Wettkampf der Bogenschuetzen";"Beweise Dich im Umgang mit dem Bogen. Es heisst " \
        "Du kannst im Dschungel ein Turnier gewinnen, bei den Dschungelelfen. Komm wieder wenn Du es geschafft hast.", \
     2: "Der Fluch des Einhorns";"Der alte Magier Mabruk hat sich in den Sternenwald zurueckgezogen. Schau nach was er vorhat, stell Dich " \
        "hilfsbereit wenn es sein muss.", \
     3: "Eesthils Befreiung";"Wir Waldlaeufer am Pfad des Iama verwenden, ein Instrument, das Iama, um die alten " \
         "Melodien zu spielen. Fuer unsere Rekruten muessen wir neue herstellen. Dazu benoetigen wir die Hilfe von Eesthil. Leider haben wir " \
        "lange nichtsmehr von ihm gehoert. Er fertigt sie immer fuer " \
        "uns an. Sieh nach ihm und finde heraus warum er uns nicht antwortet.", \
     4: "Runen der Priesterin";"Unsere Verbuendeten aus Dhrkion haben " \
        "Probleme mit der Dunkelheit in ihrer Stadt. Hilf der Priesterin.",\
     5: "Hilf dem weisen Schriftgelehrten";"Eine uralte Gefahr bedroht die " \
        "Waelder. Diesmal kommt sie aus den tiefen des Gebirges, Du musst " \
        "Tschubax aufsuchen und ihm helfen!",\
     6: "1000 Qualen im Dorf der Kannibalen";"Wir muessen Tijara helfen, " \
        "einige Bewohner wurden von dan Kannibalen im Suedosten entfuehrt. " \
        "Du musst Diese Leute finden und befreien!",\
     7: "Kampf in der Unterwelt";"In der Unterwelt ist ein Krieg entfacht. " \
        "Einige abtruennige Waldlaeufer haben sich in den Kampf verwicklen " \
        "lassen. Beende diesen Krieg, egal wie.",\
     8: "Cailleac'h's Harfe";"Die Druiden brauchen unsere Hilfe. Frag " \
        "Anvar ob Du ihm helfen kannst einen wichtigen elementare Gegenstand " \
        "zu finden, der tief im Gebirge verschollen ist.",\
     9: "Der verschollene Hoehlenforscher";"Man hat nach uns geschickt. " \
        "Halron ist verschwunden, Du musst ihn finden. Zuletzt wurde er " \
        "bei Felonia gesehen. Eile Dich!",\
    10: "Bedrohung aus einer anderen Dimension";"Der Zauberer Aranor hat mich um " \
        "Unterstuetzung gebeten, es scheint als wuerden irgendwelche " \
        "Daemonen unsere Welt betreten. Du musst sie aufhalten!",\
    12: "Auf Grosswildjagd";"In Tijara wildert seit langer Zeit der " \
        "Grosswildjaeger. Finde heraus was er vorhat, wenn er immernoch " \
        "- trotz unserer Warnungen - immernoch jagt und jagen laesst, dann " \
        "toete ihn.", \
    14: "Das Siegel der Elemente";"Hueter, uns wurde von einer finsteren Gefahr " \
        "berichtet, die droht erneut zu erwachen. Vor langer Zeit haben die ersten " \
        "Druiden in der Klamm der Seelen eine maechtige Kreatur des Boesen, die " \
        "einst drohte das ganze Silberland mit Finsternis zu ueberziehen gebannt. " \
        "Das Siegel, das diese Kreatur gefangen haelt ist schwach geworden und muss " \
        "erneuert werden. Kuemmere dich darum!", \
    16: "Tod dem Riesen";"Der alte Sica hat uns um Hilfe gebeten. Eine Aufgabe, " \
        "die eindeutig beweist, dass du dem Rang eines Meisters wuerdig bist, da " \
        "sie grosse Fertigkeit und Kraft benoetigt. Sica moechte einen Heiltrank " \
        "brauen, wofuer er das Herz eines Riesen in der Unterwelt benoetigt. " \
        "Bring ihm das Herz dieser Kreatur!"  ])
        
mixed guild_level_mission_text = ({"","", 
  // Stufe 1 - SS 13
  "Im Sueden des Waldes haben einige Wilderer ihr Lager aufgeschlagen. Sie "
   "sind noch sehr jung und unerfahren. Deswegen reagieren sie auch nicht "
   "auf unsere Warnungen, die letzte haben sie gestern Nacht erhalten. Die "
   "Tiere sagen sie sind noch immer dort, also wirst Du sie vertreiben. "  
   "Toete Fuenf von ihnen und komm dann wieder her.", 
  // Stufe 2 - SS 16
  "Unsere Kundeschafter haben bei den Wilderern eine Schuppe gefunden. Sie stammt "
   "von einem unbekannten Monster. Es handelt sich dabei nicht um eine Drachenschuppe. Aber ich"
   " kenne da Jemanden der mehr Teile des Silberlandes kennt, Du wirst sie "
   "ihm zeigen. Er war einst ein Kapitaen und Matrose und hat sich im Fischerdorf "
   "zur Ruhe gesetzt. Zeige Kilian die Schuppe!",
  // Stufe 3 - SS 19
  "Die Insel Hypros scheint also der Ursprung dieser Schuppen zu sein. Du " // einen agenten aus vilay bog treffen und toeten
   "musst zu dieser Insel und mehr herausfinden. Zeige die Schuppe den "
   "Bewohnern dort und bringe in Erfahrung was sie wissen!",
  // Stufe 4 - SS 21
  "", 
  // Stufe 5 - SS 24
  "Einige abtruennige Waldlaeufer haben sich irgendwo im Kristallwald " // erstes teil des omegatherion in Vilay bog vernichten
   "verschanzt. Unsere Kundschafter berichten, dass sie sich nicht nur von "
   "unserer Gemeinschaft losgesagt, sondern scheinen auch hinter der "
   "Sache mit den Wilderern und den Hydraschuppen zu stecken. Finde heraus was "
   "sie vorhaben und vereitle ihre Plaene!",
  // Stufe 6 - SS 26, 
  "Die Ereignisse in Vilay-Bog sind mehr als bedenklich. Doch eine gute Nachricht!"
   " Kronosch kann uns helfen eine Waffe gegen die Kreatur, "
   "die du gesehen hast, zu erschaffen. Doch musst Du dich erst seiner "
   "Mitarbeit versichern, der alte Zwerg sammelt Waffen. Bring ihm ein "
   "Schwert, eine Axt, einen Bogen, ein Messer, einen Speer, eine "
   "und eine Keule. Allerdings sollten diese "
   "Waffen nicht zu schlecht sein. Suche was ordentliches. Dann werden wir "
   "sehen, was er machen kann.",
  // Stufe 7 - SS 28 schattenschwet -> klamm, feuerpeitsche -> balrog, luftschwert -> friedhof, Lichtkeuel -> Bergwerk, Silberschwert -> Offizier, blauschwert -> magier
  "Nachdem wir uns Kronoschs Mithilfe gesichert haben, meinte er wir "
   "benoetigen einige Essenzen. Bring Kronosch eine Flammenpeitsche, eine Lichtkeule, ein "
   "Schattenschwert, ein Luftschwert, ein blaues Schwert, einen "
   "Eisdorn und ein Silberschwert. Aus diesen Waffen "
   "kann der alte Zwerg die notwendigen Essenzen ziehen.",
  // Stufe 8 - SS 31
  "Anvar hat mir berichetet, dass seine Druiden womoeglich mehr zu der Kreatur "
   "herausgefunden haben, die du bei den falschen Waldlaeufern gesehen hast. Einige "
   "der Druiden sind zur Todesinsel aufgebrochen, wo sie wohl etwas herausgefunden "
   "haben, das so wichtig ist, dass sie es uns nur direkt verraten wollen. Triff "
   "dich dort mit dem Abgesanten des Druidenzirkels und finde heraus was sie wissen.",
  // Stufe 9 - SS 34
  "Es klang auch zu gut um wahr zu sein. Dass sogar Mitglieder des Druidenzirkels "
   "in diese Machenschaften verstrickt sind, ist sehr bedenklich. Wir koennen niemandem "
   "mehr vertrauen! Nun gut. Kronosch kommt mit der Waffe einigermassen gut vorran. "
   "Allerdings fehlen ihm noch wichtige Teile. Er will noch mit einigen Dingen "
   "experimentieren. Bring ihm 10 Drachenschuppen und 10 Wasserfragmente.",
  // Stufe 10 - SS 37
  "Kronosch hat jetzt alles zusammen, was er fuer die neuen Ruestungen "
   "benoetigt. Schon bald werden wir die Waffe gegen das Omegatherion in unsern "
   "Haenden halten. Unter den Dunkelelfen haben wir einige Verbuendete. Myr Ak Ulix, der "
   "Lehrling von Mystixfis ist ein solhcer. Er hat davon berichtet, dass er verdaechtige "
   "Gestalten mit der Larve des "
   "Omegatherions in der noerdlichen Unterwelt gesehen hat. Dort waechst "
   "die Kreatur wohl immer weiter heran. Auch wenn unsere Waffe noch nicht bereit "
   "ist, finde diese Kultisten und vernichte sie samt der Kreatur! Vielleicht haben "
   "wir noch eine Chance...",
  // Stufe 11 - SS 40
  "Wiedereinmal haben unsere Feinde uns eine Falle gestellt. Und obendrein haben unsere Wachen "
   "versagt. Offenbar waren die Berichte, die dich in die Unterwelt gelockt haben "
   "nur eine Ablenkung! Eine unserer Waldlaeuferinnen hat die "
   "Waffe von Kronosch gestohlen. Sie sollte sie hierher bringen doch "
   "ist nie angekommen. Die Augen meiner Tiere haben sie auf der Todesinsel "
   "gesichtet. Irgendetwas braut sich da zusammen, das uns noch verborgen bleibt. Geh zu Hork! "
   "Er kann dich mit seinem Riesenadler zur Insel fliegen, wo ihr die Verraeterin fangen muesst.", 
  // Stufe 12 - SS 43
  "Wir haben offenbar in ein Wespennest gestochen! Unsere Spaeher in der Unterwelt "
   "wurden von den Nekromanten ueberwaeltigt. Kann es so einfach sein? Stecken sie hinter allem? "
   "Im Moment muessen wir uns etwas Luft verschaffen und Informationen "
   "sammeln. Deine Aufgabe ist es jetzt die Waechter von Burg Sturmfels abzulenken. Leite einen "
   "Angriff auf das Haupttor von Burg Sturmfels, der unseren Agenten als Ablenkung dient.",
  // Stufe 13 - SS 45
  "Die Kraehen, die wir auf Burg Sturmfels platziert haben brauche noch einige Zeit um zu "
   "schluepfen. Sobald sie gross genug sind werden sie uns berichten was in der Burg vor "
   "sich geht. Unterdessen koennen wir uns unseren anderen Feinden zuwenden. Die Nekromanten "
   "haben einen maechtigen untoten Diener erhoben, um ihn gegen uns zu schicken. Die Kreatur "
   "soll uns aufhalten und wurmt sich bereits durch die Eingeweide der Unterwelt: Ein maechtiger "
   "Skelettdrache! Ich weiss, unsere Waffen sind nicht die maechtigsten gegen untote Diener, "
   "dennoch - Zieh aus und vernichte die Kreatur!",
  // Stufe 14 - SS 47
  "Wir sind unseren Feinden bereits sehr nahe, doch es gelingt ihnen immer wieder uns in "
   "Scharmuetzel zu verwickeln. Erinnerst du dich an den Sangurit, den sie in der Unterwelt "
   "gestohlen haben? Mit ihm wollen sie eine maechtige Kreatur unterwerfen. "
   "Irgendwo in einem Turm in der Steppe soll damit die Koenigsmumie unter die Kontrolle der "
   "Kultisten gebracht werden. Vernichte sie, bevor unsere Feinde sie erreichen koennen! Wenn "
   "dir dies gelingt, versetzen wir unseren Feinden einen bleibenden Schlag.",
  // Stufe 15 SS 50
  "Wir haben den Vormarsch unserer Feinde fuer den Moment aufgehalten. Das gibt uns Zeit "
    "die gestohlene Waffe zurueck zu erlangen. Unsere Aufklaerungsmission auf Burg "
    "Sturmfels hat sich in dieser Hinsicht gelohnt. Die Raben sind geschluepft und konnten "
    "berichten, dass jemand die Waffe zu Hugen dem Schmied gebracht hat, um sie auseinander "
    "zu nehmen. Egal, ob Hugen wissentlicher Kultist oder unschuldiges Opfer ist - er "
    "ist unser Schluessel. Bring von Hugen in Erfahrung wer ihm die Waffe gebracht hat. "
    "Wenn noetig, toete ihn!", 
  "Dank der gefangenen Verraeterin Lysandra konnten wir das Symbol der schwarzen Rose "
    "entschluesseln. Es gibt einen verborgenen Ritterorden der schwarzen Rose, der "
    "irgendwo am Rande der Welt einen Uebergang zur finsteren Nacht bewachen soll. Ihr "
    "Anfuehrer ist eine finstere Kreatur der Dunkelheit. Wie "
    "es aussieht haben sie die Teile der Waffe in ihren Besitz gebracht, oder waren "
    "zumindest Helfershelfer. Beseitige den Kommandanten des Ordens der schwarzen Rose!",
  //"Diese Aufgabe ist noch nicht bereit. Ich schicke nach dir, wenn ich weiss was unser "
  //  "naechster Schachzug sein wird.",
  "Nachdem du Lord Soth ausgeschalten hattest konnten meine Agenten das Versteck der "
  "Ritter durchsuchen. Dort fanden wir einen Hinweis darauf, dass sie die Teile der "
  "Waffe versteckt haben. Ein Kurier wurde ausgeschickt dem Obersten des Kults eine Nachricht "
  "zu ueberbringen, wo sich die Teile nun befinden. Dieser Kurier hat sich gut getarnt, doch "
  "wissen wir, dass er zur Rasse deiner Erzfeinde zaehlt. Deshalb entsende ich dich ihn zu finden! "
  "'Schaetz'e deine Erzfeinde, um ihn zu enttarnen. Dann finde die Teile der Waffe.",
  //"Diese Aufgabe ist noch nicht bereit. Ich schicke nach dir, wenn ich weiss was unser "
  //  "naechster Schachzug sein wird.",
  0,
  0,
  // Stufe 20
  "Es ist soweit. Wir werden in den Kampf gegen die letzte Kreatur, das Omegatherion "
   "ziehen. Kronosch hat die Waffe bereit gemacht, die das Wesen verletzen kann. Soweit "
   "wir wissen werden sich die Kultisten auf der Todesinsel treffen, um dort das letzte "
   "Ritual abzuhalten. Unsere Provokation hat also gewirkt. Hol dir den Elementarbogen "
   "von Kronosch und geh zur Insel. Vernichte das Omegatherion ein fuer alle Mal!"});

#define ALL_QUEST_BIT "___'" // Fuer Testies
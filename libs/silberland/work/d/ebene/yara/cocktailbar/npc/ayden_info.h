/*
** Ayden der Masseur, Infos und Massagmeldungen Yara@SL
** ---
** 2005-12-13
*/

mapping infoMap = ([
  "stdMInfo": 
    "Meine Massageoele sind ausschliesslich fuer Frauen bestimmt.";
    "meint ernst: ";
    "Ayden sagt: Meine Massageoele sind ausschliesslich fuer Frauen "
    "bestimmt.",
//---------------
  "liebe": 
    "Die Liebe ist zauberhaft, zaertlich und sanft, wild und leidenschaftlich "
    "und voller Eleganz, fast so wie Du...";
    "fluestert leise in Dein Ohr: ";
    "Ayden fluestert _TPN etwas ins Ohr.",

  "m_liebe":
    "geniesst und schweigt.";
    "";
    "Ayden geniesst und schweigt.",
//---------------
  "eleganz": 
    "Ja, wie Du.";
    "laechelt: ";
    "Ayden fluestert _TPN etwas ins Ohr.",

  "m_eleganz":
    "traumt.";
    "";
    "Ayden traeumt.",
//---------------
  "koerper": 
    "Willst Du Dich bei einer Massage entspannen?";
    "fragt: ";
    "Ayden bietet _TPN eine entspannende Massage an.",
//---------------
  "oel":
    "Das verwende ich, damit sich nicht nur der Koerper, sondern auch die "
    "Seele enspannen kann. Es gibt verschiedene Arten von Oelen und sicher "
    "ist auch eins dabei, das zu einem zauberhaften Wesen wie Dir passt.";
    "erklaert: ";
    "Ayden erzaehlt _TPN etwas ueber seine Oele.",
//---------------
  "seele":
    "Sicher tut es auch Deiner Seele gut, wenn sie mal entspannen darf. Wenn "
    "Du magst, massiere ich Dich gern. Waehle Dir eins der Massageoele aus "
    "und dann bin ich nur fuer Dich da.";
    "laechelt: ";
    "Ayden bietet _TPN laechelnd eine wohltuende Massage an.",
  
  "m_seele": 
    "Frauen haben eine wundervolle Seele.";
    "meint traeumerisch: ";
    "Ayden meint traeumerisch: Frauen haben eine wundervolle Seele.",
//---------------
  "wesen": 
    "Du bist das zauberhafteste Wesen, das ich je gesehen habe! Ich wuerde "
    "mich freuen, wenn ich Dir mit meiner Kunst dienen kann.";
    "meint fasziniert: ";
    "Ayden antwortet _TPN fasziniert.",
  
  "m_wesen": 
    "zuckt mit den Schultern.";
    "";
    "Ayden zuckt mit den Schultern.",
//---------------
  "arten": 
    "Ich habe folgende Mischungen: Antistressoel, Entspannungsoel, "
    "Drachenoel, Mondoel, Orientoel und Duftoel. Moechtest Du eine "
    "davon auswaehlen?";
    "erzaehlt: ";
    "Ayden zeigt _TPN sein Sortiment Massageoele.",
  
  "m_arten": 
    "Das geht Dich nichts an.";
    "sagt: ";
    "Ayden sagt: Das geht Dich nichts an.",
  
//OELE:---------------
  "stress": 
    "Wenn Du viel Stress hast, empfehle ich Dir dieses Antistressoel. "
    "Es enthaelt unter anderem Bergamotte und wirkt ausgleichend.";
    "sagt ruhig: ";
    "Ayden zeigt _TPN das Antistressoel.",
//---------------
  "entspannung": 
    "Ich mag besonders den Duft von Lavendel an diesem Oel. Es entspannt "
    "aber auch wunderbar.";
    "erzaehlt: ";
    "Ayden zeigt _TPN das Entspannungsoel.",
//---------------
  "drachenoel": 
    "Das Drachenoel ist eine feurige wohlig waermende Mischung. "
    "Deine Verspannungen werden davon hinwegschmelzen. "
    "Es ist besonders wohltuend nach einem harten Tag des Drachenkaempfens.";
    "sagt: ";
    "Ayden zeigt _TPN das Drachenoel.",
//---------------
  "mondoel": 
    "Kennst Du die Geheimnisse der Nacht? Dann ist das das richtige Oel "
    "fuer Dich.";
    "zwinkert: ";
    "Ayden zeigt _TPN das Mondoel.",
//---------------
  "orientoel": 
    "Diese wohlausgeglichene Mischung zielt darauf Deinen Koerper und deinen "
    "Geist harmonisch zu vereinen. Lass mich Dich in einen orientalischen "
    "Traum entfuehren, Du wirst es nicht bereuen.";
    "haucht Dir ins Ohr: ";
    "Ayden fluestert _TPN etwas zu.",
//---------------
  "duftoel": 
    "Der Duft dieser aetherischen Oele entfaltet sich erst richtig "
    "waehrend einer prickelnden Massage. Ausserdem enthaelt es Mandeloel "
    "fuer die Pflege der Haut.";
    "sagt: ";
    "Ayden zeigt _TPN das Duftoel.",
//---------------
  "kaempfen":
    "Eigentlich hast Du es doch gar nicht noetig zu kaempfen. Wenn ich Dein "
    "Gegner waere, wuerde ich mich sofort Deiner Schoenheit ergeben.";
    "saeuselt: ";
    "Ayden unterhaelt sich mit _TPN ueber das Kaempfen.",
  
  "m_kaempfen":
    "Ich kaempfe schon lange nicht mehr.";
    "antwortet: ";
    "Ayden sagt: Ich kaempfe schon lange nicht mehr.",
//---------------
  "tag":
    "Heute ist ein wundervoller Tag - weil Du hier bei mir bist.";
    "meint: ";
    "Ayden antwortet _TPN.",
   
  "m_tag":
    "Ist heute nicht ein schoener Tag?";
    "fragt: ";
    "Ayden fragt: Ist heute nicht ein schoener Tag?",
//---------------
  "verspannung":
    "Ich kann Deine Verspannungen bestimmt loesen.";
    "zwinkert Dir vielsagend zu: ";
    "Ayden macht _TPN ein unwiderstehliches Angebot.",
    
  "m_verspannung":
    "Danke der Nachfrage, ich habe grad keine Verspannung.";
    "sagt: ";
    "Ayden sagt: Danke der Nachfrage, ich habe grad keine Verspannung.",
//---------------
  "nacht":
    "Ayden tritt langsam, um Dich nicht zu bedraengen, an Dich heran. "
    "Ayden fluestert Dir zu: Wie waere es mit uns heut Nacht? Ich     "
    "Ayden fluestert Dir zu: wuerde Dir eine ganz private Massage     "
    "Ayden fluestert Dir zu: schenken.                                "
    "Ayden schaut Dich verfuehrerisch an.";
    "\b\b\b\b\b\b";
    "Ayden fluestert _TPN etwas zu.",

  "m_nacht":
    "Nachts habe ich geschlossen.";
    "sagt: ";
    "Ayden sagt: Nachts habe ich geschlossen.",
//---------------
  "haut":
    "Deine Haut ist so seidenweich, wirklich unglaublich.";
    "sagt: ";
    "Ayden bewundert die Haut von _TPN.",

  "m_haut":
    "zuckt mit den Schultern.";
    "";
    "Ayden zuckt mit den Schultern.",
//---------------
  "traum":
    "Traeum ich gerade? Solange Du in meinem Traum bist, will ich nie "
    "wieder aufwachen.";
    "meint sehnsuechtig: ";
    "Ayden antwortet _TPN",

  "m_traum":
    "zuckt mit den Schultern.";
    "";
    "Ayden zuckt mit den Schultern.",
//---------------
  "massage":
    "Wenn Du magst, massiere ich Dich gern. Waehle Dir eins der Massageoele aus "
    "und dann bin ich nur fuer Dich da. Sag mir einfach, dass ich Dich massieren "
    "soll.";
    "sagt: ";
    "Ayden bietet _TPN laechelnd eine wohltuende Massage an.",
  
  "m_massage":
    "Ich massiere nur Frauen.";
    "sagt: ";
    "Ayden sagt: Ich massiere nur Frauen."
]);




mapping massMap = ([
    1: //dies ist immer die erste meldung
      "Ayden reibt seine Haende aneinander um sie zu waermen. "
       "Er loest das Tuch, in das Du Dich gewickelt hast, um besser an "
       "Deinen Ruecken zu kommen. Dann traeufelt er etwas Massageoel "
       "auf seine Haende.",
    2: //dies ist immer die zweite meldung
      "Ayden legt sanft seine warmen Haende auf Deinen Ruecken "
      "und beginnt langsam ueber Deine Haut zu streichen.",
    3:
      "Ayden massiert Deine Schultern und "
      "arbeitet sich dann langsam ueber Deinen Ruecken bis zum "
      "unteren Ende Deiner Wirbelsaeule vor.",
    4:
      "Ayden greift an Deine Schultermuskulatur und uebt leichten Druck "
      "darauf aus.",
    5:
      "Ayden erkundigt sich nach Deinem Wohlbefinden. Aus Deinem "
      "wohligen Schnurren entnimmt er, dass es Dir gut geht.",
    6:
      "Ayden kuemmert sich gruendlich um die Verspannung in Deinem Nacken.",
    7:
      "Seitlich streicht er Deinen Ruecken entlang zum Po. "
      "Seine Streichungen sind fest aber nicht unangenehm.",
    8:
      "Ayden plaudert ein wenig mit Dir. Er hat eine angenehme Stimme.",
    9:
      "Ayden nimmt noch ein wenig Oel hinzu.",
    10:
      "Jetzt legt er seine Haende an den Lendenbereich Deines Rueckens "
      "und streicht dann kreisend ueber die Seiten Deines "
      "Rueckens hinauf zu den Schultern.",
    11:
      "Als naechstes klopft Ayden sanft Deinen Ruecken ab, "
      "so dass es ein wohliges Kribbeln ausloest.",
    12:
      "Du denkst Dir: Ob man Ayden auch fuer zu Hause mieten kann?",
    13:
      "Ayden massiert sanft Deine Arme und laesst auch die Handflaechen "
      "nicht aus, auf die er mit kreisenden Fingerbewegungen leichten "
      "Druck ausuebt.",
    14:
      "Du schliesst die Augen und geniesst Aydens Massage in vollen "
      "Zuegen.",
    15:
      "Aydens Haende hinterlassen ein wohliges Prickeln auf Deiner Haut.",
    16:
      "Ayden massiert in kreisenden Bewegungen an Deiner Wirbelsaeule "
      "entlang, Du spuerst, wie sich Deine Verspannungen loesen.",
    17: //das ist immer die letzte meldung
      "Zum Schluss streichelt Ayden noch eine Weile zaertlich "
      "ueber Deinen Ruecken und entlaesst Dich dann mit einem "
      "zuckersuessen Laecheln."
]);
  
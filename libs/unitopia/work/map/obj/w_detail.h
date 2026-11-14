
  set_share_v_items(1);
  add_v_item(([
    "name"     : "schwanzfluke",
    "gender"   : "weiblich",
    "id"       : ({"fluke", "schwanzflosse","schwanzfluke",
                   "natural#weapon"}),
    "long"     : "Mit seiner beeindruckend grossen Schwanzfluke bewegt "
                 "sich der Pottwal scheinbar spielend leicht durch das "
                 "Wasser.",
    "look_msg" : "$Der() betrachtet mit gebietender Ehrfurcht die "
                 "riesige Schwanzfluke des Pottwales."
    ]));

  add_v_item(([
    "name":"flossen",
    "gender":"weiblich",
    "plural":1,
    "id":({"flosse","flossen"}),
    "long":"Du kannst an dem Wal keine Flossen finden. Stattdessen "
           "benutzt er zur Fortbewegung die maechtige Schwanzfluke, "
           "sowie die flossenartigen Vordergliedmasse.",
    "look_msg":"$Der() sucht den Wal vergebens nach Flossen ab."
    ]));

  add_v_item(([
    "name":"vordergliedmasse",
    "gender":"saechlich",
    "plural":1,
    "id":({"vordergliedmasse","gliedmasse","seitenflosse"}),
    "long":"Die Vordergliedmasse sind zu flossenartigen Gebilden "
           "umgestaltet, die dem Wal zur Steuerung dienen.",
    "look_msg":"$Der() wirft einen schnellen Blick auf die momentan "
               "aus dem Wasser ragenden Vordergliedmasse."
    ]));

  add_v_item(([
    "name":"koerper",
    "gender":"maennlich",
    "id":({"koerper","walkoerper"}),
    "long":"Von dem etwa 20 Meter messenden, gedrungenen Koerper "
           "des Wales ist nur ein Teil der Oberseite und zuweilen "
           "auch die Schwanzfluke ueber der Wasseroberflaeche sichtbar.",
    "look_msg":"$Der() versucht, den 20 Meter messenden Wal der "
               "Laenge nach zu betrachten."
    ]));

  add_v_item(([
    "name":"kopf",
    "gender":"maennlich",
    "id":({"kopf","walkopf","vorderende","oberkopf","haupt"}),
    "long":"Ein eingelagertes Walratkissen verleiht dem massigen Kopf "
           "des Pottwales seine unfoermige Gestalt. Der Oberkopf "
           "ist dadurch so stark aufgewoelbt, dass das Vorderende "
           "nahezu senkrecht in die Hoehe ragt. Weit vorne, an der "
           "Oberseite des maechtigen Walkopfes, befindet sich das "
           "Blasloch.", // *einen abbrech* - vielleicht gehts ja
                        // auch noch einfacher
    "look_msg":"$Der() bestaunt den massigen Walkopf."
    ]));

  add_v_item(([
    "name":"auge",
    "gender":"saechlich",
    "id":({"auge","augen"}),
    "long":"Die gegen den restlichen Koerper geradezu winzig wirkenden "
           "Augen des Wales befinden sich zu beiden Seiten weit "
           "unten am ueberdimensionierten Kopf. Kurz dahinter setzen "
           "die kompakten, kurzen Vordergliedmasse an.",
    "look_msg":"$Der() schaut sich eines der eher kleinen Augen "
               "des Wales genauer an."
    ]));

  add_v_item(([
    "name":"haut",
    "gender":"weiblich",
    "id":({"haut","epidermis","oberflaeche","natural#armour",
           "falten","hautfalten","farbe"}),
    "long":"Die glaenzende Haut des Wales liegt an manchen Stellen "
           "in Falten und ist grau gefaerbt.", 
    "look_msg":"$Der() laesst $seinen(([name:blick,gender:maennlich]),"
               "0,OBJ_TP) ueber die Haut des Wales streifen."
    ]));

  add_v_item(([
    "name":"blasloch",
    "gender":"saechlich",
    "id":({"blasloch","loch","atemwegsoeffnung","atemloch",
           "atemoeffnung"}),
    "long":"Weit vorne auf der Oberseite des maechtig aufgewoelbten "
           "Walkopfes kann man das Blasloch erkennen, welches als "
           "Atemoeffnung dient.",
    "look_msg":"$Dem() gelingt es, einen Blick auf das Blasloch "
               "zu werfen."
    ]));

  add_v_item(([
    "name":"maul",
    "gender":"saechlich",
    "id":({"maul","mund","mundoeffnung"}),
    "long":"Das Maul des Wales erstreckt sich bis zu den "
           "kleinen Augen und trennt den voluminoesen oberen "
           "Teil des Kopfes von dem vergleichsweise flachen "
           "und schmalen bezahnten Unterkiefer.",
    "look_msg":"$Der() betrachtet das riesige Maul des Wales."
    ]));

  add_v_item(([
    "name":"zaehne",
    "gender":"maennlich",
    "plural":1,
    "id":({"zaehne","zahn","walzaehne","walzahn"}),
    "long":"Wenn der Wal sein Maul oeffnet, kann man eine Reihe, auf "
           "dem Unterkiefer sitzender, weisser, spitzer Zaehne erkennen.",
    "look_msg":"$Der() versucht, dem Wal ins geoeffnete Maul zu blicken."
    ]));

  add_v_item(([
    "name":"unterkiefer",
    "gender":"maennlich",
    "id":({"unterkiefer","kiefer"}),
    "long":"Der schmale Unterkiefer des Wales verschwindet regelrecht "
           "unter dem riesigen Oberkopf. Er traegt eine Reihe kleiner, "
           "spitzer Zaehne.",
    "look_msg":"$Der() mustert den unteren Teil des Walkopfes."
    ]));

  add_v_item(([
    "name":"bauch",
    "gender":"maennlich",
    "id":({"bauch","unterseite","bauchseite","dorsalseite"}),
    "long":"Der Bauch des Wales ist staendig im Wasser und daher "
           "nur sehr verschwommen zu erkennen.",
    "look_msg":"$Der() versucht vergeblich, den Bauch des Wales "
               "zu Gesicht zu bekommen."
    ]));

  add_v_item(([
    "name":"ruecken",
    "gender":"maennlich",
    "id":({"ruecken","rueckseite","dorsalseite","walruecken"}),
    "long":"Der Walruecken ist kaum gebogen und geht mit einen "
           "leichten Knick in den Bereich des Schwanzes ueber.",
    "look_msg":"$Der() schaut den Walruecken entlang."
    ]));
  
  add_v_item(([
    "name":"schwanz",
    "gender":"maennlich",
    "id":({"schwanz","walschwanz"}),
    "long":"Der Schwanz des Wales faellt auf der Oberseite durch "
           "hervorstehende Wirbel auf, die den Uebergang zum Ruecken "
           "wellig erscheinen lassen. " // Hmmm..., gewagte Formulierung :)
           "Die waagerecht stehende Schwanzfluke bildet den Abschluss des "
           "Schwanzes, der etwas schmaler ist als der kompakte Koerper.",
    "look_msg":"$Der() verfolgt den Schwanz des Wales mit $seinem"
               "(([name:augen,gender:saechlich,plural:1]),0,OBJ_TP)"
    ]));

  add_v_item(([
    "name":"blaswolke",
    "gender":"weiblich",
    "id":({"blaswolke","wolke"}),
    "long":"Kurz nachdem der Wal ausgeatmet hat, ist ueber ihm eine "
           "Blaswolke zu sehen, welche er mit hohem Druck aus seinen "
           "Atemwegen schleudert. Sie ist etwa sieben Meter hoch und "
           "weist schraeg nach vorne.",
    "look_msg":"$Der() schaut nach oben."
    ]));
  set_share_v_items(0);

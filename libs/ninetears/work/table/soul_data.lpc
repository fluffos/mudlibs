/* Excluding this from the soul.c, just to make things a little cleaner */
/* Wonderflug, 1996 */

global_adj = ",lentamente,felizmente,tristemente,nerviosamente,ironicamente,ampliamente,torcidamente,"+
"estupidamente,idioticamente,condescendientemente,conironia,pacientemente,brillantemente,"+
"ligeramente,desagradablemente,excitadamente,estranyamente,reluctantemente,flexiblemente,"+
"cuidadosamente,sadisticamente,desequilibradamente,comounpez,comoungato,ligeramente,"+
"comounpato,enfadadamente,paranoicamente,inocentemente,comounarana,astutamente,"+
"debilmente,murmullantemente,paradojicamente,sarcasticamente,viciosamente,llamativamente,"+
"dulcemente,inocentemente,conamor,sonyadoramente,radiantemente,entusiasticamente,"+
"insolentemente,caprichosamente,portodaspartes,inconscientemente,borrachamente,"+
"locamente,lindamente,maliciosamente,quizas,fugazmente,"+
"distraidamente,bruscamente,disturbadoramente,increiblemente,calladamente,"+
"altamente,diferentemente,ganadoramente,triunfantemente,seductoramente,"+
"estiradamente,portodoesto,suavemente,positivamente,"+
"vivamente,demoniacamente,calientemente,friamente,borrachamente,negativamente,"+
"comounmaniaco,cautelosamente,sardonicamente,perezosamente,serenamente,desaprobadoramente";

soul_data =
([
 "asco" : ({ ({ 0, "%s", 0, "a %s" }),
      ({ "Te dan arcadas",
      "A $mcname$ le dan arcadas",
      "Le haces ascos a $hcname$",
      "$mcname$ te hace ascos",
      "$mcname$ le hace ascos a $hcname$", }) }),
  "reconocer" : ({ ({ 0, "%s" }), ({
      "Reconoces a $hcname$",
      "$mcname$ te reconoce",
      "$mcname$ reconoce a $hcname$" }) }),
  "acusar" : ({ ({ 0, "%s", 2, "%s de %s", 2, "%s %s", 3, "%s" }), ({
      "$ifarg:Acusas a $arg:#$$else$El Creador lo hizo!~$",
      "$mcname$ $ifarg:acusa a $lastarg$$else$acusa al Creador~$",
      "Acusas a $hcname$$ifarg: de $arg:#$~$",
      "$mcname$ te acusa $ifarg:de $lastarg$~$",
      "$mcname$ acusa a $hcname$$ifarg: de $lastarg$~$" }) }),
  "admirar" : ({ ({ 0, "%s", 2, "%s %s", 3, "%s" }), ({
      "$ifarg:Admiras a $arg:#$$else$Admiras este maravilloso MUD y a Super Grimfang!~$",
      "$mcname$ $ifarg:admira a $lastarg$$else$admira este maravilloso MUD y a Super Grimfang~$",
      "Admiras a $hcname$$ifarg: por ser $arg:#$~$",
      "$mcname$ te admira$ifarg: por ser $lastarg$~$",
      "$mcname$ admira a $hcname$$ifarg: por ser $lastarg$~$" }) }),
  "sorprender" : ({ ({ 0, "%s" }), ({
      "Sorprendes a todo el mundo con tu existencia!",
      "$mcname$ no es sorprendente?" }) }),
  "enojar" : ({ ({ 0, "%s", }), ({
      "Enojas a $hcname$ hasta la muerte",
      "$mcname$ te enoja hasta la muerte",
      "$mcname$ enoja a $hcname$ hasta la muerte", }) }),
  "disculparse" : ({
    ({ 3, "%s", 1, "%s a %s", 1, "%s %s", 2, "%s %s", }), ({
      "Te disculpas $arg:profusamente,felizmente,tristemente,reservadamente,"+
      "cuidadosamente,lentamente,superficialmente,bruscamente,viciosamente,"+
      "sedosamente,borrachamente,infelizmente,profesionalmente,pomposamente,"+
      "de todo corazon,parcialmente,fatigosamente,como un pez,facetadamente,"+
      "innecesariamente,espontaneamente,por partida doble,minuciosamente,murmullantemente$",
      "$mcname$ se disculpa $lastarg$",
      "Pides disculpas $arg:profusamente,felizmente,tristemente,reservadamente,"+
      "cuidadosamente,lentamente,superficialmente,bruscamente,viciosamente,"+
      "malhumoradamente,borrachamente,infelizmente,profesionalmente,pomposamente,"+
      "de todo corazon,parcialmente,fatigosamente,como un pez,facetadamente,"+
      "innecesariamente,espontaneamente,por partida doble,minuciosamente,murmullantemente$,"+
      " a $hcname$",
      "$mcname$ te pide disculpas $lastarg$",
      "$mcname$ le pide disculpas $lastarg$ a $hcname$" }) }),
  "aplaudir" : ({
    ({ 0, "%s", 1, "%s %s", 2, "%s %s", 3, "%s" }), ({
      "Aplaudes $arg:de todo corazon,ruidosamente,suavemente,vagamente,brevemente$",
      "$mcname$ aplaude $lastarg$",
      "Aplaudes la actuacion de $hcname$ $arg:de todo corazon,ruidosamente,suavemente,"+
      "vagamente,brevemente$",
      "$mcname$ aplaude tu actuacion $lastarg$",
      "$mcname$ aplaude la actuacion de $hcname$ $lastarg$" }) }),
  "asombrar" : ({ ({ 0, "%s" }), ({
      "Estas asombrado con la inteligencia de Grimfang al traducir toda esta basura!",
      "$mcname$ esta asombrado con la inteligencia de Grifamang!",
      "Sorprendes a $hcname$$ifarg:con tu $arg:estupidez,inteligencia"+
      ",virilidad$~$!",
      "$mcname$ te sorprende$ifarg: con su $lastarg$~$!",
      "$mcname$ sorprende a $hcname$$ifarg: con su $lastarg$~$" }) }),
  "deacuerdo" : ({ ({ 0, "%s", 0, "con %s", 1, "%s con %s", 1, "%s %s",
      2, "con %s %s", 3, "%s" }), ({
      "Estas de acuerdo $arg:de todo corazon,sin entusiasmo,parcialmete,minuciosamente,"+
      "en algun grado$",
      "$mcname$ esta de acuerdo $lastarg$",
      "Estas de acuerdo $arg:de todo corazon,sin entusiasmo,parcialmente,minuciosamente,"+
      "en algun grado$ con $hcname$",
      "$mcname$ esta de acuerdo $lastarg$ contigo",
      "$mcname$ esta de acuerdo $lastarg$ con $hcname$" }) }),
  "flechazo" : ({ ({ 0, "%s" }), ({
      "Disparas una flecha alcanzando a $hcname$, de repente "+
      "se vuelve loco por ti y te quiere mucho, como la trucha al trucho!",
      "Sientes un pinchazo en el esfinter anal, y, de repente, te das cuenta "+
      "de que te has vuelto loco por $mcname$ y lo quieres mucho, como la trucha al trucho",
      "$hcname$ es herido por una flecha y se vuelve completamente "+
      "loco por $mcname$" }) }),
  "bofetada" : ({ ({ 0, "%s" }), ({
      "Le pegas una ostia descomunal a $hcname$ en la mejilla, dejandole la marca de "+
      "tus dedos al rojo de una manera un tanto artistica",
      "$mcname$ descarga toda su furia concentrada en su palma contra ti, sientes un gran "+
      "escozor en la mejilla derecha y te pitan los oidos",
      "Pero que pedazo de ostia acaba de endinyarle "+
      "$mcname$ a $hcname$ en toda la jeta, te ha dolido hasta a ti" }) }),
  "bah" : ({ ({ 0, "%s", 3, "%s", 1, "%s %s" }), ({
      "Dices bah$ifarg: $arg:fervorosamente,menospreciadoramente$~$",
      "$mcname$ dice bah$ifarg: $lastarg$~$",
      "Dics bah$ifarg: $arg:fervientemente$~$ a $hcname$",
      "$mcname$ te dice bah$ifarg: $lastarg$~$",
      "$mcname$ le dice bah$ifarg: $lastarg$~$ a $hcname$" }) }),
  "ladrar" : ({ ({ 3, "%s" }), ({
      "Ladras como un $arg:perro,gato,arbol,pato,lobo,perro de caza,labrador,"+
      "pastor aleman ,bicho cualquiera que ladre,"+
      "fox terrier,tren,tiburon mutante con mala leche$",
      "$mcname$ ladra como un $lastarg$", }) }),
  "irradiar" : ({ ({ 3, "%s", 1, "%s a %s", 1, "%s %s", 2, "a %s %s",
      2, "%s %s", 0, "%s" }), ({
      "Emites un rayo de luz $arg:brillantemente,felizmente,estranyamente,felizmente,estaticamente,"+
      "orgullosamente,como un tren,como un pez,radiactivamente$",
      "$mcname$ emite un rayo de luz $lastarg$",
      "Emites un rayo de luz hacia $hcname$$ifarg: $arg:brillantemente,admirantemente,"+
      "estranyamente,felizmente,radiactivamente"+
      "estaticamente,como un pez,como un pato con el pico abierto,como un tren,$~$",
      "$mcname$ te lanza un rayo de luz$ifarg: $lastarg$~$",
      "$mcname$ emite un rayo de luz a $hcname$$ifarg: $lastarg$~$", }) }),
  "beep" : ({ ({ 3, "%s" }), ({
      "Haces beep $arg:felizmente,#$",
      "$mcname$ hace beep $arg:felizmente,#$" }) }),
  "suplicar" : ({ ({
      0, "a %s", 0, "%s", 2, "a %s %s", 2, "a %s como un %s",
      1, "como un %s a %s", 1, "%s a %s", 1, "%s %s", 1, "%s %s",
      3, "%s", 3, "como un %s", }), ({
      "Suplicas por tu vida como un $arg:perro,gato,sapo,pollo,frisbee,toro,garn oso,"+
      "caniche,chihuahua,tren,mendigo,noble,perro de cine,labrador,pastor aleman,"+
      "canibal,chimpance,orang-u-tang,bibliotecario,pez,delfin,toxicomano,"+
      "espiritu,perro infernal,San bernardo,santo,husky,lobo,dingo,dogo canario$",
      "$mcname$ suplica por su vida como un $lastarg$",
      "Le suplicas como un $arg:perro,gato,sapo,pollo,frisbee,toro,garn oso,"+
      "caniche,chihuahua,tren,mendigo,noble,perro de cine,labrador,pastor aleman,"+
      "canibal,chimpance,orang-u-tang,bibliotecario,pez,delfin,toxicomano,"+
      "espiritu,perro infernal,San bernardo,santo,husky,lobo,dingo,dogo canario,"+
      "tren$ a $hcname$ por tu vida",
      "$mcname$ te te suplica como un $lastarg$ por su vida",
      "$mcname$ le suplica como un $lastarg$ a $hcname$por su vida", }) }),
  "bing" : ({ ({ 0, "a %s", 0, "%s", 1, "%s a %s", 1, "%s %s", 2, "%s %s",
      2, "a %s %s", 3, "%s" }), ({
      "Haces bing $arg:felizmente,tristemente,juguetonamente,cuerdamente,sabiamente,rapidamente,"+
      "ruidosamente,cuidadosamente,funestamente,excitadamente,nerviosamente,brillantemente,"+
      "inciertamente$",
      "$mcname$ hace bing $lastarg$",
      "Le haces bing $arg:felizmente,tristemente,juguetonamente,cuerdamente,sabiamente,"+
      "rapidamente,excitadamente,nerviosamente,brillantemente,inciertamente,"+
      "ruidosamente,cuidadosamente,funestamente$ a $hcname$",
      "$mcname$ te hace bing $lastarg$",
      "$mcname$ le hace bing $lastarg$ a $hcname$" }) }),
  "bingf" : ({ ({ 0, "a %s", 0, "%s", 1, "%s a %s", 1, "%s %s", 2, "%s %s",
      2, "a %s %s", 3, "%s" }), ({
      "Haces bing de un modo $arg:sarcastico,triste,jugueton,cuerdo,sabio,"+
      "rapido,"+
      "ruidoso,cuidadoso,funesto,excitado,nervioso,brillante,"+
      "incierto$, pero correcto",
      "$mcname$ hace bing de un modo $lastarg$, pero correcto",
      "Le haces bing de un modo $arg:sarcastico,triste,jugueton,cuerdo,sabio,"+
      "rapido,"+
      "ruidoso,cuidadoso,funesto,excitado,nervioso,brillante,"+
      "incierto$ pero correcto a $hcname$",
      "$mcname$ te hace bing de un modo $lastarg$, pero correcto",
      "$mcname$ le hace bing de un modo $lastarg$, pero correcto a $hcname$" }) }),
  "cuerno" : ({ ({ 0, "%s" }), ({
      "Levantas tu dedo corazon y le sacas el cuerno a $hcname$",
      "$mcname$ levanta su dedo corazon y te saca el cuerno",
      "$mcname$ levanta su dedo corazon y le saca el cuerno a $hcname$" }) }),
  "morder" : ({ ({ 0, "%s", 2, "%s %s", 1, "%s %s" }), ({
      "Te muerdes un huevo",
      "$mcname$ se muerde un huevo",
      "Muerdes a $hcname$$ifarg: $arg:duramente,desagradablemente,cuidadosamente,"+
      "educadamente,como un pez,"+
      "amorosamente,refrescantemente,felizmente,como un tren,senyaladoramente,"+
      "objetivamente,malhumoradamente,caballerosamente,brillantemente,excitadamente,"+
      "inciertamente,"+
      "como un perro,como un lobo,piadosamente,despiadadamente,suavemente,dulcemente,"+
      "profesionalmente,hambriento,traviesamente,casualmente,"+
      "en los tobillos,en el brazo,en la pierna,"+
      "en la nariz,en la oreja,en el dedo del pie,en el dedo$~$,"
      "$mcname$ te muerde$ifarg: $lastarg$~$",
      "$mcname$ le muerde a $hcname$$ifarg: $lastarg$~$", }) }),
  "cotillear" : ({ ({ 0, "%s" }), ({
      "Cotilleas",
      "$mcname$ cotillea" }) }),
  "blah" : ({ ({ 0, "%s" }), ({
      "Dices blahblahblah",
      "$mcname$ dice blahblahblah",
      "Le dices blahblahblah a $hcname$",
      "$mcname$ te dice blahblahblah",
      "$mcname$ le dice blahblahblah a $hcname$" }) }),
  "culpar" : ({ ({ 0, "%s", 2, "%s por %s" }), ({
      "Culpas a $hcname$$ifarg: por $arg:#$~$",
      "$mcname$ te culpa$ifarg: por $lastarg$~$",
      "$mcname$ culpa a $hcname$$ifarg: por $lastarg$~$" }) }),
  "sangrar" : ({ ({ 3, "%s" }), ({
      "Sangras $arg:levemente,en cantidades industriales,"+
      "verde,azul ... como un principe!,ketchup,hasta la muerte$",
      "$mcname$ sangra $lastarg$" }) }),
  "sangrar2" : ({ ({ 3, "%s" }), ({
      "$ifarg:Tu $arg:corazon,pierna,brazo,cabeza,oreja,nariz,profusamente"+
      "$ sangra$else$Sangras~$",
      "$ifarg:El $lastarg$ de $mcname$ sangra$else$$mcname$ sangra~$", }) }),
  "parpadear" : ({ ({ 0, "%s", 3, "%s" }), ({
      "Parpadeas$ifarg: $arg:como una lechuza,lentamente,cuidadosamente$~$",
      "$mcname$ parpadea$ifarg: $lastarg$~$",
      "Parpadeas hacia $hcname$",
      "$mcname$ parpadea hacia ti",
      "$mcname$ parpadea hacia $hcname$" }) }),
  "sonrojarse" : ({ ({ 3, "%s", 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "Te sonrojas$ifarg: $arg:avergonzadamente,ruborizadamente,levemente,"+
      "preocupadamente$~$",
      "$mcname$ se sonroja$ifarg: $lastarg$~$",
      "Te sonrojas$ifarg: $arg:avergonzadamente,ruborizadamente,levemente,"+
      "preocupadamente$~$ al mirar a $hcname$",
      "$mcname$ se sonroja$ifarg: $lastarg$~$ al mirarte",
      "$mcname$ se sonroja$ifarg: $lastarg$~$ al mirar a $hcname$" }) }),
  "defenestrar" : ({ ({ 0, "%s" }), ({
      "Defenestras a $hcname$ arrancandole la caja toracica e introduciendosela en el ano",
      "$mcname$ te defenestra arrancandote la caja toracica e introduciendotela en el ano",
      "$mcname$ defenestra a $hcname$ con una maniobra que te produce dolor anal ajeno" }) }),
  "pasmar" : ({ ({ 3, "%s", 0, "a %s", 0, "%s" }), ({
      "Dejas pasmado a $arg:el concepto,#$", "$mcname$ deja pasmado a $lastarg$",
      "Dejas pasmado a $hcname$",
      "$mcname$ te deja pasmado",
      "$mcname$ deja pasmado a $hcname$", }) }),
  "bonk" : ({ ({ 0, "%s" }), ({
      "B O N K !",
      "$mcname$ hace B O N K !",
      "Le haces B O N K ! a $hcname$ en la cabeza",
      "$mcname$ te hace B O N K ! en la cabeza, lo que te irrita",
      "$mcname$ le hace B O N K ! a $hcname$ en la cabeza, irritandolo" }) }),
  "bop" : ({ ({ 0, "%s" }), ({
      "You bop to the beat",
      "$mcname$ bops to the beat",
      "You bop $hcname$ on the head",
      "$mcname$ bops you on the head",
      "$mcname$ bops $hcname$ on the head" }) }),
  "balancearse" : ({ ({ 0, "%s", 1, "%s alrededor %s", 1, "%s %s", 2, "%s %s", 3, "%s" }), ({
      "$ifarg:Te balanceas alrededor $arg:excitado,como un pato,asustado,feliz$"+
      "$else$B O U N C E ! !~$",
      "$mcname$ se balancea alrededor$ifarg: $lastarg$~$",
      "Te balanceas alrededor de $hcname$$ifarg: $arg:feliz,con cuidado,salvaje,"+
      "excitado,ondeante,jugueton,una vez,lentamente,sugestivamente,"+
      "feliz,acunadamente$~$",
      "$mcname$ se balancea alrededor de ti$ifarg: $lastarg$~$",
      "$mcname$ se balancea alrededor de $hcname$$ifarg: $lastarg$~$", }) }),
  "breakdance" : ({ 0, ({
      "Realizas una complicada maniobra de break-dance al estilo de Hansel, ahora es lo mas",
      "$mcname$ realiza una complicada maniobra de break-dance al estilo de Hansel", }) }),
  "respirar" : ({ ({ 3, "%s", }), ({
      "Respiras $arg:rapidamente,seductoramente,dolorosamente,desagradablemente,lentamente,"+
      "una vez,pesadamente,cuidadosamente,con furia asesina$",
      "$mcname$ respira $lastarg$", }) }),
  "eructar" : ({ ({ 3, "%s" }), ({
      "Eructas$ifarg: $arg:asquerosamente,debilmente,ruidosamente,rudamente$~$",
      "$mcname$ eructa$ifarg: $lastarg$~$" }) }),
  "inclinarse" : ({ ({ 0, "%s", 0, "ante %s", 1, "%s ante %s", 1, "%s %s", 3, "%s" }), ({
      "Te inclinas$ifarg: $arg:solemnemente,profundamente,formalmente,precipitadamente,levemente,"+
      "respetuosamente,"+
      "insolentemente,desmanyadamente,con gracia,diestramente,salvajemente,coloridamente$~$",
      "$mcname$ se inclina$ifarg: $lastarg$~$",
      "Te inclinas$ifarg: $arg:solemnemente,profundamente,formalmente,apresuradamente,"+
      "precipitadamente,con gracia,respetuosamente,"+
      "insolentemente,desmanyadamente,diestramente,salvajemente,coloridamente$~$ ante $hcname$",
      "$mcname$ se inclina$ifarg: $lastarg$~$ ante ti",
      "$mcname$ se inclina$ifarg: $lastarg$~$ ante $hcname$" }) }),
  "burbujas" : ({ ({ 0, "%s", 0, "hacia %s" }), ({
      "Haces pompitas de jabon divirtiendote mucho!",
      "$mcname$ hace pompitas de jabon, parece divertirse.",
      "Lanzas pompas de jabon hacia $hcname$",
      "$mcname$ te lanza pompas de jabon",
      "$mcname$ lanza pompas de jabon hacia $hcname$" }) }),
  "arder" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "Te rocias de gasolina y empiezas a arder como una antorcha humana",
      "$mcname$ se prende fuego asimismo",
      "Le prendes fuego a la $arg:cabellera,pierna,mano,nariz,dentadura,piel,alfombra,"+
      "cama,inteligencia,retina,casa,lengua,pantalla,"+
      "sesera,idea,esperanza,gata,personalidad,creencia$ de $hcname$",
      "$mcname$ le prende fuego a tu $lastarg$",
      "$mcname$ le prende fuego a la $lastarg$ de $hcname$", }), }),
  "risa" : ({ ({ 3, "%s" }), ({
      "Te ries $ifarg:$arg:con gran regocijo,maniacamente,traviesamente,desagradablemente,"+
      "desesperadamente,hasta caer de espaldas$$else$with glee~$",
      "$mcname$ $ifarg:se rie $lastarg$$else$"+
      "lanza la cabeza hacia atras y se rie con gran regocijo~$" }) }),
  "calmarse" : ({ ({ 0, "%s", 0, "%s down" }), ({
      "Te calmas",
      "$mcname$ se calma",
      "Calmas a $hcname$",
      "$mcname$ te calma",
      "$mcname$ calma a $hcname$", }) }),
  "travesura" : ({ ({ 3, "%s" }), ({
      "Empiezas a hacer travesuras$ifarg: como un $arg:tonto,pollo,guason,"+
      "bimbo,rubio,sulam,seductor,entusiasta,"+
      "loco,pata a la carrera,"+
      "tio feliz,caballero educado,satiro$"+
      "$else$ locamente~$", /* giggle */
      "$mcname$ empieza a hacer travesuras$ifarg: como un $lastarg$$else$ locamente~$", }) }),
  "acariciar" : ({ ({ 0, "%s", 2, "%s %s", }), ({
      "Acaricias a $hcname$$ifarg: $arg:gentilmente,estranyamente,violentamente,"+
      "firmemente,seductoramente,sugestivamente,levemente,sensualmente,"+
      "reluctantemente,educadamente,amorosamente,vigorosamente,entusiasticamente,vivamente$~$",
      "$mcname$ te acaricia$ifarg: $lastarg$~$",
      "$mcname$ acaricia a $hcname$$ifarg: $lastarg$~$", }) }),
  "desafiar" : ({ ({ 0, "%s", }), ({
      "Desafias a $hcname$ a un duelo a muerte",
      "$mcname$ te desafia a un duelo a muerte",
      "$mcname$ desafia a $hcname$ a un duelo a muerte", }) }),
  "brindar" : ({ ({ 0, "%s", 0, "con %s", 1, "%s con %s", 1, "%s %s", 2, "con %s %s", 3, "%s" }),
    ({
      "Levantas tu copa y brindas $arg:entusiasticamente,excitadamente,calladamente,"+
      "calmadamente,cuidadosamente,educadamente,salvajemente,de forma rara,"+
      "de manera poco convincente,sarcasticamente,felizmente,hacia arriba$",
      "$mcname$ levanta su copa y brinda $lastarg$",
      "Levantas tu copa y brindas $arg:entusiasticamente,excitadamente,calladamente,calmadamente,"+
      "salvajemente,de manera poco convincente,sarcasticamente,cuidadosamente,felizmente,"+
      "educadamente,de forma rara,levemente,hacia arriba$ con $hcname$",
      "$mcname$ levanta su copa y brinda $lastarg$ contigo",
      "$mcname$ levanta su copa y brinda $lastarg$ con $hcname$", }) }),
  "gallina" : ({ ({ 0, "%s" }), ({
      "Cacareas y mueves las plumas como una gallina mientras incubas un huevo",
      "$mcname$ cacarea y mueve las plumas como una gallina mientras incuba un huevo",
      "Revelas a todo el mundo lo gallina que es $hcname$",
      "$mcname$ le revela a todo el mundo lo gallina que eres$force#gallina#2$",
      "$mcname$ le revela a todo el mundo lo gallina que es $hcname$" }) }),
  "sofocar" : ({ ({ 0, "%s" }), ({
      "Te sofocas debido al abrasante calor",
      "$mcname$ se sofoca, esta sudando como un cerdo",
      "Sofocas a $hcname$",
      "$mcname$ te sofoca",
      "$mcname$ sofoca a $hcname$$force#respirar dolorosamente#2$" }) }),
  "chocolate" : ({ ({ 0, "%s" }), ({
      "Le das a $hcname$ un gran corazon de chocolaaaateeee",
      "$mcname$ te da un gran corazon de chocolaaaateeee",
      "$mcname$ le da a $hcname$ un gran corazon de chocolaaaateeee" }) }),
  "risita" : ({ ({ 3, "%s" }), ({
      "Te ries entredientes $arg:educadamente,desagradablemente,demoniacamente$",
      "$mcname$ se rie entre dientes $lastarg$" }) }),
  "palmas" : ({ ({ 0, "%s", 3, "%s" }), ({
      "Haces palmas $arg:brevemente,ruidosamente,entusiasticamente,desganadamente "+
      "con las orejas como Sloth$",
      "$mcname$ hace palmas $lastarg$",
      "Aplaudes la actuacion de $hcname$",
      "$mcname$ aplaude tu actuacion",
      "$mcname$ aplaude la actuacion de $hcname$" }) }),
  "consolar" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "Consuelas a $hcname$$ifarg: $arg:sinceramente,de todo corazon,traviesamente,"+
      "desganadamente,vagamente,entusiasticamente,completamente,amorosamente,falsamente,"+
      "caballerosamente,dulcemente,tristemente,seriamente,con las alas,en la oreja,en la pierna,"+
      "por partida doble,ansiosamente,cuidadosamente,delicadamente,como cualquier otro$~$",
      "$mcname$ te consuela$ifarg: $lastarg$~$",
      "$mcname$ consuela a $hcname$$ifarg: $lastarg$~$" }) }),
  "confesar" : ({ ({ 3, "%s" }), ({
      "Confieso $ifarg:$arg:#$$else$ser una bruja~$",
      "$mcname$ confiesa $ifarg:$lastarg$$else$ser una bruja, "+
      "a la hoguera!$~$", }), }),
  "felicitar" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "Tu$ifarg: $arg:de todo corazon,calidamente$~$ felicitas a todo el mundo",
      "$mcname$$ifarg: $lastarg$~$ felicita a todo el mundo",
      "Felicitas a $hcname$$ifarg: $arg:de todo corazon,calidamente$~$",
      "$mcname$ te felicita$ifarg: $lastarg$~$",
      "$mcname$ felicita a $hcname$$ifarg: $lastarg$~$" }) }),
  "buen_rollo" : ({ 0, ({
      "Irradias buen rollo, paz y amor por todo el lugar",
      "$mcname$ irradia ondas chachiguays in de templus" }) }),
  "toser" : ({ 0, ({ "Toses", "$mcname$ tose" }) }),
  "vaca" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s", 3, "%s" }), ({
      "Te pones a pastar $arg:descerebradamente,silenciosamente,felizmente,cuidadosamente,#$",
      "$mcname$ se pone a pastar $lastarg$",
      "Transformas a $hcname$ en una vaca loca$ifarg: $arg:lentamente,cuidadosamente,"+
      "insoportablemente,felizmente,regocijadamente,magicamente$~$",
      "$mcname$ te transforma en una vaca loca$ifarg: $lastarg$~$",
      "$mcname$ transforma a $hcname$ en una vaca loca$ifarg: $lastarg$~$"+
      "$force#muu#2$" }) }),
  "agacharse" : ({ ({ 3, "%s" }), ({
      "Te agachas $arg:en una esquina,asustadamente,furtivamente,timidamente,cagado de miedor,"+
      "desagradablemente$",
      "$mcname$ se agacha $lastarg$", }), }),
  "crujir" : ({ ({ 0, "%s" }), ({
      "Haces crujir tus nudillos confiadamente",
      "$mcname$ hace crujir sus nudillos confiadamente",
      "Diriges tu mirada hacia $hcname$ mientras haces crujir tus nudillos "+
      "con aire desafiante",
      "$mcname$ dirige su mirada hacia ti mientras"+
      "hace crujir sus nudillos con aire desafiante",
      "$mcname$ dirige la mirada hacia $hcname$ mientras "+
      "hace crujir sus nudillos con aire desafiante" }) }),
  "acobardarse" : ({ 0, ({
      "Gritas como una pija histerica$ifarg: con $arg:terror,verguenza$~$",
      "$mcname$ grita como una pija histerica$ifarg: in $lastarg$~$" }) }),
  "croar" : ({ 0, ({
      "%^BOLD%^GREEN%^Ribbit!!!",
      "$mcname$ croa (%^BOLD%^GREEN%^ribbit!!!%^RESET%^) Dara 50k?" }) }),
  "cruzar" : ({ ({ 3, "%s", 3, "my %s" }), ({
      "Cruzas los $arg:dedos,pies,ojos haciendo el vizco como Aokromes$",
      "$mcname$ cruza los $lastarg$", }) }),
  "multitud" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s", 2, "%s en %s",
      3, "%s" }), ({
      "La multitud se vuelve $arg:salvaje,#$",
      "La multitud se vuelve $arg:salvaje,#$",
      "Apinyas a $hcname$ en $arg:una esquina,#$",
      "$mcname$ te apinya $lastarg$",
      "$mcname$ apinya a $hcname$ en $lastarg$" }) }),
  "llorar" : ({ 0, ({ "Buaaaaaaaaa, es mi Scattergories y me lo llevo!",
      "$mcname$ llora ruidosamente cual Aokromes insultado" }) }),
  "abrazar" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "Abrazas carinyosamente a $hcname$",
      "$mcname$ te abraza con amor y ternura",
      "$mcname$ abraza a $hcname$, una aureola de amor los rodea" }) }),
  "maldecir" : ({ ({ 0, "%s", 1, "%s %s",  1, "%s a %s", 2, "a %s %s",
      2, "%s %s" , 3, "%s" }), ({
      "Maldices$ifarg: $arg:estrepitosamente,fuertemente,rudamente,profusamente,sin miedo,#$~$",
      "$mcname$ maldice$ifarg: $lastarg$~$",
      "Maldices a $hcname$$ifarg: $arg:estrepitosamente,fuertemente,profusamente,rudamente,"+
      "sin miedo,#$~$",
      "$mcname$ te maldice$ifarg: $lastarg$",
      "$mcname$ maldice$ifarg: $lastarg$~$ a $hcname$" }) }),
  "reverencia" : ({ ({
      0, "%s", 0, "a %s", 0, "%s", 1, "%s %s",
      2, "%s %s", 2, "%s a %s",3, "%s" }), ({
      "Haces una reverencia$ifarg: $arg:con gracia,humilde,rapida,de rodillas,leve$~$",
      "$mcname$ hace una reverencia$ifarg: $lastarg$~$",
      "Le haces una reverencia$ifarg: $arg:con gracia,humilde,rapida,corta,arrodillado,"+
      "leve,adorable,felizmente,dulce,sarcastica$~$ a $hcname$",
      "$mcname$ te hace una reverencia$ifarg: $lastarg$~$",
      "$mcname$ le hace una reverencia$ifarg: $lastarg$~$ a $hcname$" }) }),
  "bailar" : ({ ({ 0, "%s", 0, "con %s" }), ({
      "Te marcas un peaso de baile raperete moviendo la mano como si tuvieras parkinson",
      "$mcname$ se baila un rap de una forma muy ortopedica",
      "Deslizas a $hcname$ por la pista de baile",
      "$mcname$ te desliza por la pista de baile mientras te mete mano",
      "$mcname$ desliza a $hcname$ por la pista de baile" }) }),
  "retar" : ({ ({ 0, "%s", 2, "%s %s", 2, "%s a %s" }), ({
      "Retas a $hcname$$ifarg: a $arg:#$~$",
      "$mcname$ te reta$ifarg: a $lastarg$~$",
      "$mcname$ reta a $hcname$$ifarg: a $lastarg$~$" }) }),
  "sonyar_despierto" : ({ ({ 3, "%s", }), ({
      "Suenyas despierto$ifarg: pensando en $arg:#$~$",
      "$mcname$ suenya despierto$ifarg: pensando en $lastarg$~$", }) }),
  "negar" : ({ ({ 0, "%s" }), ({
      "Lo niegas absolutamente todo",
      "$mcname$ lo niega absolutamente todo",
      "Niegas todo lo que $hcname$ ha dicho",
      "$mcname$ niega todo lo que has dicho",
      "$mcname$ niega todo lo que $hcname$ ha dicho" }) }),
  "morirse" : ({ ({0, "%s",  1, "%s %s",
      1, "%s a %s", 2, "%s %s",
      2, "a %s %s",  3, "%s" }),  ({
      "Te mueres $arg:de repente,dramaticamente,de aburrimiento,de hambre,de "+
      "anticipacion,pateticamente,con gracia,con sensibilidad,estupidamente,"+
      "tragicamente,lentamente,dolorosamente,de una forma atroz$",
      "$mcname$ se muere $lastarg$",
      "Te mueres$ifarg: $arg:de repente,dramaticamente,de aburrimiento,de hambre,de "+
      "anticipacion,pateticamente,con gracia,con sensibilidad,estupidamente,"+
      "tragicamente,lentamente,dolorosamente,de una forma atroz$~$"+
      " a un de 1D3 -1 rooms de $hcname$",
      "$mcname$ se muere$ifarg: $lastarg$~$ a 1D3 -1 rooms de ti",
      "$mcname$ se muere$ifarg: $lastarg$~$ a 1D3 -1 rooms de $hcname$" }) }),
  "despreciar" : ({ ({ 0, "%s" }), ({
      "Miras desdenyosamente a $hcname$, como la basura que es",
      "$mcname$ te mira desdenyosamente, como la basura que eres",
      "$mcname$ mira desdenyosamente a $hcname$" }) }),
  "babear" : ({ ({0, "%s", 0, "sobre %s", 0, "toda %s"  }), ({
      "Empiezas a babear toda la parte frontal de tu camisa",
      "$mcname$ empieza a babear toda la parte frontal de su camisa",
      "Empiezas a babear sobre $hcname$",
      "$mcname$ Empieza a babearte toda la camisa nueva",
      "$mcname$ empieza a babear sobre $hcname$" }) }),
  "babear2" : ({ ({ 0, "%s", 0, "a %s" }), ({
      "Empiezas a babear como un bebe. Gugu Tata!",
      "$mcname$ empieza a babear y a balbucear como un bebe",
      "Llenas de babas y demas fluidos bucales a $hcname$",
      "$mcname$ te llena de babas y ... de algo verdoso y pegajoso",
      "$mcname$ llena de babas a $hcname$" }) }),
  "ahogar" : ({ ({ 0, "%s", 2, "%s %s" }), ({
      "Ahogas tus penas con en botella",
      "$mcname$ ahoga sus penas en una botella",
      "Te desahogas en $arg:brazos,#$ de $hcname$",
      "$mcname$ ahoga sus penas en tus $lastarg$",
      "$mcname$ ahoga sus penas en $lastarg$ de $hcname$" }) }),
  "cubrirse" : ({ 0, ({
      "Te agachas buscando covertura",
      "$mcname$ se agacha buscando covertura" }) }),
  "duh" : ({ 0, ({
      "Gritas \"Duh!\"",
      "$mcname$ grita \"Duh!\"", }) }),
  "oreja" : ({ ({ 0, "%s" }), ({
      "Te arrancas una oreja y se la envias a $hcname$ como muestra "+
      "de tu amor imperecedero",
      "$mcname$ se arranca una oreja y te la envia "+
      "como muestra de su amor imperecedero",
      "$mcname$ se arranca una oreja y se la envia a $hcname$ "+
      "como muestra de su amor imperecedero" }) }),
  "avergonzar" : ({ ({ 0, "%s" }), ({
      "Averguenzas a $hcname$ mandandole una docena de rosas "+
      "a su oficina con una tarjetita "+
      "que dice: \n     \"Con carinyo de tu Flor de Pitimini\"",
      "$mcname$ te averguenza enviandote una docena de rosas "+
      "al trabajo con una tarjetita "+
      "que dice: \n     \"Con carinyo de tu Flor de Pitimini\"",
      "$mcname$ envia $hcname$ una docena de rosas con una "+
      "tarjetita que dice:\n     \"Con carinyo de tu Flor de Pitimini\""+
      "\n$hcname$ esta tremendamente avergonzado" }) }),
  "esquimal" : ({ ({ 0, "%s" }), ({
      "Sostienes la cabeza de $hcname$ entre tus manos y gentilmente "+
      "le das un besito de esquimal",
      "$mcname$ sostiene tu cabeza en sus manos "+
      "y gentilmente te da un besito de esquimal",
      "$mcname$ sostiene la cabeza de $hcname$ entre sus "+
      "manos y gentilmente le da un besito de esquimal" }) }),
  "reojo" : ({ ({ 0, "%s" }), ({
      "Miras de reojo a $hcname$",
      "$mcname$ te mira de reojo",
      "$mcname$ mira de reojo a $hcname$", }), }),
  "sacrificar" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s", 3, "%s" }), ({
      "Te clavas un punyal en las tripas y te inmolas a$ifarg: $arg:#$~$",
      "$mcname$ se sacrifica a una poderosa deidad",
      "Sacrificas a $hcname$ a la deidad$ifarg: $arg:#$~$",
      "$mcname$ te sacrifica a la deidad$ifarg: $lastarg$~$",
      "$mcname$ sacrifica a $hcname$ a la deidad$ifarg: $lastarg$~$" }) }),
  "expectante" : ({  ({ 0, "%s", 0, "en %s" }), ({
      "Clavas tu mirada en $hcname$ expectantemente",
      "$mcname$ te clava su mirada en ti expectantemente",
      "$mcname$ mira a $hcname$ expectantemente" }) }),
  "explotar" : ({ 0, ({
      "%^BOLD%^RED%^K A B O O M !!! %^RESET%^Explotas en un millon de pedacitos",
      "%^BOLD%^RED%^K A B O O M !!! %^RESET%^$mcname$ explota en un millon de pedacitos", }) }),
  "suspirar" : ({ ({ 3, "%s", 0, "%s" }), ({
      "Suspiras$ifarg: $arg:cansado,aburrido,desencantado$~$",
      "$mcname$ suspira$ifarg: $lastarg$~$",
      "Suspiras sobre $hcname$",
      "$mcname$ suspira sobre ti",
      "$mcname$ suspira sobre $hcname$" }) }),
  "pedo" : ({ 0, ({ /* don't like this emote, can you tell?? */ /* yes :) */
      "Por un momento dejas de mantener el esfinter apretado y se te escapa un minusculo"+
      "pedete. Una nube marron y maloliente inunda la habitacion y amenaza con asfixiar"+
      "a todo el mundo",
      "$mcname$ se cuaja de una manera horrible y apestosa. Te llevas las manos a la garganta"+
      "intentando tomar una bocanada de aire puro sin exito" }) }),
  "miedo" : ({ ({ 0, "%s" }), ({
      "Le gritas a $hcname$ como una loca miedica",
      "$mcname$ te grita como una loca miedica",
      "$mcname$ le grita a $hcname$ como una loca miedica" }) }),
  "juguetear" : ({ 0, ({
      "Jugueteas con algo",
      "$mcname$ juguetea con algo", }), }),
  "bolsillo" : ({ ({
      0, "%s", 0, "en %s", 1, "en busca de %s en %s pockets",
      1, "en busca de %s en %s", 1, "%s en %s", 2, "%s %s", 3, "%s" }), ({
      "Metes la mano en tu bolsillo y palpas$ifarg: en busca de $arg:#$~$",
      "$mcname$ mete la mano en su bolsillo y palpa$ifarg: en busca de $lastarg$~$",
      "Metes la mano en el bolsillo de $hcname$ y palpas$ifarg: en busca de $arg:#$~$",
      "$mcname$ mete la mano en tu bolsillo y palpa$ifarg: en busca de $lastarg$~$",
      "$mcname$ mete la mano en el bolsillo de $hcname$ y palpa$ifarg: en busca de $lastarg$~$" }) }),
  "aletear" : ({ ({ 3, "%s" }), ({
      "Aleteas tus $arg:orejas como Slort,brazos,alas,pestanyas$",
      "$mcname$ aletea sus $arg:ears,arms,wings,eyelashes$" }) }),
  "buu" : ({ ({ 0, "%s" }), ({
      "Sales de detras de unos arbustos y le pegas un chillillo a $hcname$ en el oido. BUUU!",
      "$mcname$ sale de detras de unos arbustos y te pega un chillillo en el oido. BUUUUUUUUU!",
      "$mcname$ sale de detras de unos arbustos y le pega un chillillo a $hcname$ en el oido" }) }),
  "flexionar" : ({ ({ 3, "%s" }), ({
      "Flexionas tus $arg:musculos,esculturales biceps,triceps,piernas,pensamientos,mocos,orejas$",
      "$mcname$ flexiona sus $lastarg$", }) }),
  "voltereta" : ({  ({ 3, "%s", 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "Pegas un bote $arg:hacia atras,hacia alante,a los lados,"+
      "alrededor,cuidadosamente,lentamente,doble,como un perro,embarazosamente,disturbadoramente,"+
      "asquerosamente,rapidamente,lentamente,con gracia,sobre la luna,"+
      "y realiza una complicada doble voltereta mortal hacia atras,"+
      "y da media voltereta, cayendo sobre la cabeza ... ouch$",
      "$mcname$ pega un bote $lastarg$",
      "Botas encima de $hcname$ $arg:y cae en una papelera,"+
      "viciosamente,peligrosamente,espectacularmente$",
      "$mcname$ bota sobre ti $lastarg$",
      "$mcname$ bota encima de $hcname$ $lastarg$" }) }),
  "flirtear" : ({ ({ 0, "%s", 1, "%s con %s", 1, "%s %s", 2, "%s %s" }), ({
      "Flirteas$ifarg: $arg:seductoramente,sin miedo,estupidamente,"+
      "adorablemente,ganadoramente,asquerosamente,carinyosamente$~$ con $hcname$",
      "$mcname$ flirtea$ifarg: $lastarg$~$ contigo",
      "$mcname$ flirtea$ifarg: $lastarg$~$ con $hcname$" }) }),
  "desmayarse" : ({ ({ 3, "%s" }), ({
      "Te desmayas $arg:sofocadamente,como un pez fuera del agua,"+
      "muy malito,como un palomo,cuidadosamente,rudamente,un poquito,una vez,como un goblin,"+
      "maravillosamente,impresionantemente,sugestivamente,perezosamente,felizmente,pensativamente$",
      "$mcname$ se desmaya $lastarg$" }) }),
  "ruborizarse" : ({ 0, ({
      "Te ruborizas",
      "$mcname$ se ruboriza", }) }),
  "fondle" : ({ ({ 0, "%s", 1, "%s %s" }), ({
      "You fondle $ifarg:$hcname$ $arg:#$$else$$hcname$~$",
      "$mcname$ fondles$ifarg: with your $lastarg$$else$ you~$",
      "$mcname$ fondles $ifarg:with $hcname$ $lastarg$$else$$hcname$~$" }) }),
  "foo" : ({ ({ 3, "%s" }), ({
      "Dices foo $arg:vagamente,cuidadosamente,lentamente,peligrosamente$",
      "$mcname$ dice foo $lastarg$", }), }),
  "perdonar" : ({ ({ 0, "%s", }), ({
      "Perdonas $hcname$",
      "$mcname$ te perdona",
      "$mcname$ perdona a $hcname$", }), }),
  "rana" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s", 3, "%s" }), ({
      "Croas por alrededor $arg:descerebradamente,silenciosamente,felizmente,cuidadosamente,#$",
      "$mcname$ croa por los alrededores $lastarg$",
      "Transformas a $hcname$ en una rana$ifarg: $arg:lentamente,cuidadosamente,"+
      "de forma atroz,felizmente,maliciosamente,magicamente$~$",
      "$mcname$ te transforma en una rana$ifarg: $lastarg$~$",
      "$mcname$ transforma a $hcname$ en una rana$ifarg: $lastarg$~$"+
      "$force#croar#2$" }) }),
  "frances" : ({ ({ 0, "%s" }), ({
      "Le das a $hcname$ un profundo y apasionado beso que parece durar eternamente ..",
      "$mcname$ te da un profundo y apasionado beso que parece durar eternamente..",
      "$mcname$ le da a $hcname$ un profundo y apasionado beso que parece durar eternamente.." }) }),
  "espumear" : ({ 0, ({
      "Echas espumajarros por la boca",
      "$mcname$ echa espumajarros por la boca como un perro rabioso" }) }),
  "fruncir" : ({ ({ 3, "%s", 3, "%s" }), ({
      "$ifarg:Frunces el cejo $arg:concentradamente,duramente,enfadado,"+
      "depresivo,como un gato,feliz,#$$else$Frunces el cejo~$",
      "$ifarg:$mcname$ frunce el cejo $lastarg$$else$$mcname$ frunce el cejo~$" }) }),
  "humo" : ({ ({ 3, "%s", }), ({
      "Empiezas a humear $arg:calladamente,insultantemente,desesperadamente$",
      "$mcname$ empieza a echar humo $lastarg$", }) }),
  "vomitar" : ({ 0, ({
      "Echas la pota entre terribles convulsiones, lo remueves todo y te lo vuelves a tragar."+
      "No hay que desaprovechar la comida",
      "$mcname$ llena el suelo de vomito, lo remueve con un cucharon y se lo vuelve a tragar"+
      "Que asco!!!" }) }),
  "jadear" : ({ ({ 3, "%s", 3, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "Jadeas $arg:sorprendido,con pavor,excitadamente,con terror,con miedo,asustado,"+
      "sorprendido,dolorosamente,como una putita cuando trabaja$",
      "$mcname$ jadea $lastarg$",
      "Le jadeas $arg:sorprendido,con pavor,excitadamente,con terror,con miedo,asustado,"+
      "sorprendido,dolrosamente,como una putita cuando trabaja$ a $hcname$",
      "$mcname$ te jadea $lastarg$",
      "$mcname$ jadea $lastarg$ a $hcname$" }) }),
  "mirada" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "Clavas tu mirada$ifarg: $arg:sorprendido,carinyosamente,desdenyosamente,profundamente,"+
      "con pavor,"+
      "sonyadoramente,amorosamente,peligrosamente,vizcamente como Aokromes$~$"+
      " en $hcname$",
      "$mcname$ te clava su mirada$ifarg: $lastarg$~$",
      "$mcname$ clava su mirada$ifarg: $lastarg$~$ en $hcname$" }) }),
  "gesticular" : ({ 0, ({
      "Gesticulas salvajemente",
      "$mcname$ gesticula salvajemente" }) }),
  "farfullar" : ({ 0, ({
      "Farfullas como un viejo enano grunyon",
      "$mcname$ farfulla como un viejo enano grunyon con artritis y reuma", }) }),
  "risilla" : ({ ({ 0, "%s", 3, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "Se te escapa una risilla$ifarg: $arg:loca,ruidosa,estupida,"+
      "queda,idiota,diabolica$~$",
      "A $mcname$ se le escapa una risilla$ifarg: $lastarg$~$",
      "Se te escapa una risilla$ifarg: $arg:loca,ruidosa,estupida,"+
      "queda,idiota,diabolica$~$ mientras miras a $hcname$",
      "A $mcname$ se le escapa una risilla$ifarg: $lastarg$~$ mientras te mira",
      "A $mcname$ se le escapa una risilla$ifarg: $lastarg$~$ mientras mira a $hcname$" }) }),
  "mirada2" : ({ ({
      0, "%s", 0, "a %s", 1, "%s a %s", 2, "a %s %s",
      1, "%s %s", 2, "%s %s", 3, "%s" }), ({
      "Miras $arg:petreamente,severamente,calidamente,intencionadamente,"+
      "solemnemente,idioticamente,de igual a igual,"+
      "malignamente$ a todo el mundo en general",
      "$mcname$ mira $lastarg$ a su alrededor",
      "Miras $arg:petreamente,severamente,calidamente,intencionadamente,solemnemente,"+
      "malignamente,de igual a igual,"+
      "idioticamente$ a $hcname$",
      "$mcname$ te mira $lastarg$",
      "$mcname$ mira $lastarg$ a $hcname$", }) }),
  "bienvenida" : ({ ({ 0, "%s" }), ({
      "Le das la bienvenida a $hcname$ $arg:felizmente,tristemente,con los brazos abiertos,"+
      "estaticamente,cuidadosamente,cortesmente,histericamente,"+
      "reservadamente,calidamente,friamente,insolentemente,bruscamente,"+
      "distraidamente$",
      "$mcname$ te da la bienvenida $lastarg$",
      "$mcname$ le da la bienvenida a $hcname$ $lastarg$", }) }),
  "mueca" : ({ ({ 3, "%s" }), ({
      "Haces una mueca de $arg:disgusto,enfado,durezat,poder,desesperacion$",
      "$mcname$ hace una mueca de $lastarg$", }), }),
  "burla" : ({ ({ 0, "%s", 0, "de %s", 1, "%s de %s", 2, "de %s %s",
      1, "%s %s", 2, "%s %s", 3, "%s" }), ({
      "Te burlas$ifarg: $arg:maniacamente,malignamente,locamente,traviesamente,"+
      "enfermamente,de oreja a oreja,como un tonto del culo,"+
      "impiamente,a carrillos llenos,idioticamente,tentativamente,"+
      "como un pato con el buche flexible$~$",
      "$mcname$ se burla$ifarg: $lastarg$~$",
      "Te burlas$ifarg: $arg:maniacamente,malignamente,locamente,traviesamente,"+
      "enfermamente,de oreja a oreja,como un tonto del culo,"+
      "impiamente,a carrilos llenos,idioticamente,"+
      "como un pato con el buche flexible$~$ de $hcname$",
      "$mcname$ se burla$ifarg: $lastarg$~$ de ti",
      "$mcname$ se burla$ifarg: $lastarg$~$ de $hcname$" }) }),
  "rechinar" : ({ ({ 3, "%s" }), ({
      "Haces rechinar tus dientes $arg:ruidosamente,seducotramente,causando terror,juntosr,"+
      "molestamente,sugetivamente,dolorosamente,enfadadamente$",
      "$mcname$ hace rechinar sus dientes $lastarg$", }) }),
  "gemir" : ({ ({ 3, "%s" }), ({
      "Gimes$ifarg: $arg:placenteramente,resignadamete,cansadamente$~$",
      "$mcname$ gime$ifarg: $lastarg$~$" }) }),
  "palpar" : ({ ({ 0, "%s", 1, "%s %s" }), ({
      "Palpas a $ifarg:$hcname$ $arg:#$$else$$hcname$~$",
      "$mcname$ te palpa$ifarg: $lastarg$~$",
      "$mcname$ palpa a $ifarg:$hcname$ $lastarg$$else$$hcname$~$" }) }),
  "arrastrarse" : ({ ({ 0, "%s", 0, "ante %s", 1, "%s %s", 1, "%s ante %s", 3, "%s", 2, "ante %s %s", }),
    ({
      "Te arrastras$ifarg: $arg:sin miedo,violentamente,sin temor$~$",
      "$mcname$ se arrastra$ifarg: $lastarg$~$",
      "Te arrastras$ifarg: $arg:sin miedo,violentamente,sin temor$~$ ante"+
      " $hcname$",
      "$mcname$ se arrastra$ifarg: $lastarg$~$ ante ti",
      "$mcname$ se arrastra$ifarg: $lastarg$~$ ante $hcname$" }) }),
  "grunyir" : ({ ({
      0, "%s", 0, "a %s", 1, "%s %s", 1, "%s a %s",
      2, "a %s %s", 2, "%s %s", 3, "%s" }), ({
      "Grunyes  $arg:amenazadoramente,desagradablemente,ruidosamente,juguetonamente$",
      "$mcname$ grunye $lastarg$",
      "Grunyes $arg:amenazadoramente,desagradablemente,ruidosamente,juguetonamente$ a $hcname$",
      "$mcname$ te grunye $lastarg$",
      "$mcname$ grunye $lastarg$ a $hcname$" }) }),
  "quejarse" : ({ ({ 3, "%s", }), ({
      "Te quejas $arg:calladamente,amargamente,amenazadoramente,desganadamente,"+
      "seductoramente,sugestivamente,ruidosamente,molestamente,devastadoramente,cuidadosamente,"+
      "salvajemente,mas o menos$",
      "$mcname$ se queja $lastarg$", }) }),
  "gorjear" : ({ ({ 3, "%s" }), ({
      "Gorjeas $arg:ruidosamente,rudamente,estruendosamente,traviesamente,"+
      "felizmente,cuidadosamente,desagradablemente,sorprendido,"+
      "como un tren,rapidamente,lentamente$",
      "$mcname$ gorjea $lastarg$" }) }),
  "ahorcarse" : ({ ({ 3, "%s", }), ({
      "Te ahorcas$arg:avergonzado,arrepentido,desesperado,feliz$",
      "$mcname$ se ahorca $lastarg$", }) }),
  "suicidarse" : ({ ({ 0, "%s" }), ({
      "Coges la escopeta de perdigones del abuelo y te vuelas la cabeza en miles de cachitos",
      "$mcname$ coge una escopeta y se vuela la cabeza en miles de cachitos" }) }),
  "pino" : ({ ({ 0, "encima de %s", 0, "%s" }), ({
      "Haces el pino", "$mcname$ hace el pino",
      "Haces el pino encima de $hcname$", "$mcname$ hace el pino encima tuyo",
      "$mcname$ hace el pino encima de $hcname$" }) }),
  "corazon" : ({ ({ 0, "%s" }), ({
      "Le entregas tu corazon a $hcname$ con una notita de amor",
      "$mcname$ te entrega su corazon con una notita de amor",
      "$mcname$ le entrega su corazon a $hcname$ con una notita de amor" }) }),
  "hipo" : ({ 0, ({ /* exciting stuff */
      "Te da hipo. Quieres que traiga al Balrog a que te de un sustito?",
      "A $mcname$ le da hipo, pero parece pasarsele rapidamente" }) }),
  "choca5" : ({ ({ 0, "%s" }), ({
      "Alzas la mano y chocas los cinco con $hcname$",
      "Alzas la mano y chocas los cinco con $mcname$",
      "$mcname$ y $hcname$ alzan la mano y chocan los cinco, haciendote sentir"+
      " un poco marginado" }) }),
  "sisear" : ({ ({ 0, "%s" }), ({
      "Siseas con gran enfado",
      "$mcname$ sisea con gran enfado",
      "Le siseas con gran enfado a $hcname$",
      "$mcname$ te sisea con gran enfado",
      "$mcname$ sisea con gran enfado a $hcname$" }) }),
  "ulular" : ({ ({ 3, "%s" }), ({
      "Ululas $arg:como un buho,molestamente,distraidamente,"+
      "mientras trabajas,distractoramente,senyaladoramente,silenciosamente,ruidosamente,"+
      "ruidosamente,con gracia,vagamente,obviamente,sin hacer mucho ruido$",
      "$mcname$ ulula $lastarg$" }), }),
  "aullar" : ({ ({ 3, "%s", 3, "a la %s" }), ({
      "AUUUUUUUUUUUUUUUUUUUUUUUUUUU!!!!!",
      "$mcname$ aulla$ifarg: $arg:a la luna,a #$~$" }) }),

  "achuchar" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "achuchas a $hcname$$ifarg: $arg:cercanamente,caballerosamente,calidamente,"+
      "tensamente,vigorosamente,desesperadamente,amorosamente,felizmente,como un oso$~$",
      "$mcname$ te achucha$ifarg: $lastarg$~$",
      "$mcname$ achucha a $hcname$$ifarg: $lastarg$~$" }) }),
  "tararear" : ({ ({ 3, "%s" }), ({
      "Tarareas $arg:una melodia de la merry,desastrosamente,molestamente,vagamente,"+
      "distraidamente,"+
      "mientras trabajas,distractoramente,acusadoramente,silenciosamente,ruidosamente,"+
      "rudamente$",
      "$mcname$ tararea $lastarg$" }), }),
  "idle" : ({ ({ 0, "%s", 3, "%s" }), ({
      "Idleas $arg:casi tan bien como Leviathan,aun mas que Ghejed,como Burt Reynolds,"+
      "como las putitas,"+
      "como un goblin,como todo el mundo,galantemente,rapidamente,"+
      "increiblemente bien,sin usar las manos,de arriba a abajo,"+
      "hiperactivamente,erguido,con arte,de aqui para alla,intensamente,como el sastre de Tarzan$",
      "$mcname$ idlea $lastarg$",
      "Idleas como $hcname$",
      "$mcname$ idlea como tu",
      "$mcname$ idlea como $hcname$", }), }),
  "ignorar" : ({ ({ 0, "%s" }), ({
      "Ignoras al mundo entero",
      "$mcname$ ignora al mundo entero",
      "Ignoras a $hcname$",
      "$mcname$ te ignora",
      "$mcname$ ignora a $hcname$", }) }),
  "james" : ({ 0, ({
      "Yeeeah! I feel good! da na da na da na da! I knew that I would!",
      "$mcname$ feels good, da na da na da na da!" }) }),
  "malabarismos" : ({ ({ 3, "%s" }), ({
      "Haces juegos malabares con $arg:pelotas,palitos,bastones,gatos,perros,ranas de 50k,pollos,"+
      "espadas,cuchillos,brazos,piernas :)__,pelotitas,arboles,sierras mecanicas,botellas,"+
      "mocos,antorchas,palomas,ramas de arbol,cabezas de inmortales del 23,"+
      "las pelotas de los inmortales del 23,vasos de vino,agua,gente,fuego,senyoritas,elefantes$",
      "$mcname$ hace juegos malabares con $lastarg$", }) }),
  "saltar" : ({ ({ 0, "sobre %s", 0, "%s", 2, "sobre %s %s",
      1, "%s sobre %s", 1, "%s %s", 2, "%s %s", 3, "%s" }), ({
      "Saltas de arriba a abajo $arg:excitadamente,felizmente,cuidadosamente,lentamente,"+
      "juguetonamente,inestablemente,estaticamente,preocupado,y de lado a lado,"+
      "distraidamente,como un Aokorki,como una piranya hambrienta$",
      "$mcname$ salta de arriba a abajo $lastarg$",
      "Saltas de arriba a abajo sobre $hcname$$ifarg: $arg:"+
      "excitadamente,felizmente,cuidadosamente,lentamente,"+
      "juguetonamente,inestablemente,estaticamente,preocupadamente,de lado a lado,"+
      "distraidamente,como un Aokorki$~$",
      "$mcname$ salta de arriba a abajo$ifarg: $lastarg$~$ sobre ti",
      "$mcname$ salta de arriba a abajo sobre $hcname$$ifarg: $lastarg$~$" }) }),
  "patada" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s", 3, "%s" }), ({
      "Te pegas una patada en las pelotas, para ver que se siente.$ifarg: $arg:#$~$",
      "$mcname$ se pega una patada en las pelotas y parece satisfecho.",
      "Le pegas una patada a $hcname$$ifarg: $arg:#$~$",
      "$mcname$ te pega una patada$ifarg: $lastarg$~$",
      "$mcname$ le pega una patada a $hcname$$ifarg: $lastarg$~$" }) }),
  "besar" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "Besas a $hcname$$ifarg: $arg:apasionadamente,profundamente,dulcemente,caballerosamente,"+
      "carinyosamente,"
      "amorosamente,largamente,como un pez,cuidadosamente,pediguenyamente,sensualmente,#$~$",
      "$mcname$ te besa$ifarg: $lastarg$~$",
      "$mcname$ besa a $hcname$$ifarg: $lastarg$~$" }) }),
  "arrodillarse" : ({ ({ 0, "%s", 1, "%s %s" }), ({
      "Te arrodillas ante $hcname$$ifarg: $arg:#$~$",
      "$mcname$ se arrodilla ante ti$ifarg: $lastarg$~$",
      "$mcname$ se arrodilla ante $hcname$$ifarg: $lastarg$~$" }) }),
  "reirse" : ({ ({
      0, "de %s", 0, "%s", 1, "%s %s", 1, "%s de %s",
      2, "de %s %s", 3, "%s"}), ({
      "$ifarg:Te ries $arg:desagradablemente,agradablemente,calladamente,descontroladamente,"+
      "educadamente,felizmente,histericamente,maniacamente,estaticamente,demoniacamente$"+
      "$else$Te ries~$",
      "$ifarg:$mcname$ se rie $lastarg$$else$$mcname$ se rie~$",
      "Te ries$ifarg: $arg:desagradablemente,agradablemente,calladamente,descontroladamente,"+
      "educadamente,felizmente,histericamente,maniacamente,estaticamente,demoniacamente$~$"+
      " de $hcname$",
      "$mcname$ se rie$ifarg: $lastarg$~$ de ti",
      "$mcname$ se rie$ifarg: $lastarg$~$ de $hcname$" }) }),
  "brincar" : ({ ({ 3, "%s" }), ({
      "Brincas$ifarg: $arg:muy alto,excitadamente,rapidamente,lentamente,desmanyadamente,"+
      "educadamente,sin hacer ruido,ruidosamente$~$ hacia el vacio",
      "$mcname$ brinca$ifarg: $lastarg$~$ hacia el vacio", }) }),
// bonito soul ke overridea mis add_command leer y actions! xD
/*  "leer" : ({ ({ 0, "%s", 0, "at %s" }), ({
      "You leer at yourself",
      "$mcname$ leers at $mobj$self, hmm interesting",
      "You leer at $hcname$",
      "$mcname$ leers at you",
      "$mcname$ leers at $hcname$", }), }), */
  "lamer" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "Te lames los labios de arriba a abajo y se te cae la babilla",
      "$mcname$ se lame los labios y se le cae un hilillo de baba por la comisura de los labios",
      "Lames a $hcname$$ifarg: $arg:suavemente,caballerosamente,profesionalmente,"+
      "meticulosamente$~$",
      "$mcname$ te lame$ifarg: $lastarg$~$",
      "$mcname$ lame a $hcname$$ifarg: $lastarg$~$" }) }),
  "elevar" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "Elevas a $hcname$ en tus brazos$ifarg: $arg:#$~$",
      "$mcname$ te eleva en sus brazos$ifarg: $lastarg$~$",
      "$mcname$ eleva a $hcname$ en sus brazos$ifarg: $lastarg$~$" }) }),
  "escuchar" : ({ ({ 0, "%s" }), ({
      "Escuchas atentamente a $hcname$",
      "$mcname$ te escucha atentamente",
      "$mcname$ escucha atentamente a $hcname$" }) }),
  "surgir" : ({ ({ 0, "%s", 0, "over %s" }), ({
      "Surges de la nada ante $hcname$",
      "$mcname$ aparece de la nada sobre ti",
      "$mcname$ aparece de la nada sobre $hcname$", }) }),
  "amor" : ({ ({ 0, "%s" }), ({
      "Susurras palabras de amor al oido de $hcname$",
      "$mcname$ te susurra palabras de amor al oido",
      "$mcname$ susurra a $hcname$" }) }),
  "lujuria" : ({ ({ 0, "%s" }), ({
      "Te lames los labios y miras a $hcname$ lujuriosamente",
      "$mcname$ se lame los labios y te mira lujuriosamente",
      "$mcname$ se lame los labos y mira a $hcname$ lujuriosamente" }) }),
  "masaje" : ({ ({ 0, "%s", 2, "%s %s", }), ({
      "Le das a $hcname$ un$ifarg: $arg:buen,mal,horrible,largo,"+
      "refrescante,rosa,completo,sedutor,sensual,estranyo,"+
      "doloroso,profundo,sentido,ergonomico,economico,"+
      "indoloro,memorable,diferente,no deseado,no garantizado,"+
      "no provocado,desconocido,sigiloso,desapercibido,llevadero,"+
      "profesional,no profesional,feliz,triste,entrenado,desentrenado,"+
      "compacto,rapido$~$,"+
      "massage",
      "$mcname$ le da un$ifarg: $lastarg$~$ masaje",
      "$mcname$ le da a $hcname$ un$ifarg: $lastarg$~$ masaje", }) }),
  "derretirse" : ({ ({ 0, "%s" }), ({
      "Te conviertes en mantequilla y te derrites en los brazos de $hcname$",
      "$mcname$ se convierte en mantequilla y se derrite en tus brazos",
      "$mcname$ se convierte en mantequilla y se derrite en los brazos de $hcname$" }) }),
  "echar_de_menos" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "Le haces saber a $hcname$ que le hechas de menos$ifarg: "+
      "$arg:un monton,desperatadamente$~$",
      "$mcname$ te echa de menos$ifarg: $lastarg$~$",
      "$mcname$ echa de menos a $hcname$$ifarg: $lastarg$~$" }) }),
  "imitar" : ({ ({ 0, "%s" }), ({
      "Imitas a $hcname$ escandalosamente",
      "$mcname$ te imita escandalosamente",
      "$mcname$ te imita $hcname$ escandalosamente" }), }),
  "muu" : ({ 0, ({
      "Muuuuuuuuuuuuuuu!",
      "$mcname$ muerde el polvo (MUUUUUUUUU)" }) }),
  "culo" : ({ ({ 0, "%s", }), ({
      "Te bajas los pantalones y le ensenyas el culo a $hcname$",
      "$mcname$ se baja los pantalones y te hace un calvo",
      "$mcname$ se baja los pantalones y le hace un calvo a $hcname$", }), }),
  "cuello" : ({ ({ 0, "%s" }), ({
      "Le das a $hcname$ un beso en el cuello presionando los labios "+
      "suavemente contra su suave piel",
      "$mcname$ te besa en el cuello, "+
      "extasiandote",
      "$mcname$ besa a $hcname$ "+
      "en el cuello, extasiandolo" }) }),
  "acurrucarse" : ({ ({ 0, "%s", }), ({
      "Te acurrucas sobre $hcname$ $arg:afectuosamente,amorosamente,curiosamente$",
      "$mcname$ se acurruca sobre ti $lastarg$",
      "$mcname$ se acurruca sobre $hcname$ $lastarg$", }) }),
  "mordisquear" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "Mordisqueas a $hcname$ en $arg:la oreja,el dedo,el labio,el brazo,la pierna,"+
      "en el cuello,en la nariz$",
      "$mcname$ te mordisquea $lastarg$",
      "$mcname$ mordisquea a $hcname$ en $lastarg$" }) }),
  "asentir" : ({ ({
      0, "%s", 1, "%s a %s", 1, "%s %s", 2, "a %s %s",
      2, "%s %s", 3, "%s" }), ({
      "Asientes con la cabeza$ifarg: $arg:solemnemente,felizmente,brillantemente,secamente,"+
      "pacientemente,lentamente,cansadamente,sarcasticamente,"+
      "sabiamente,vigorosamente,en acuerdo,en desacuerdo,tentativamente$~$",
      "$mcname$ asiente$ifarg: $lastarg$~$",
      "Le asientes con la cabeza$ifarg: $arg:solemnemente,felizmente,brillantemente,secamente,"+
      "pacientemente,lentamente,cansadamente,sarcasticamente,"+
      "sabiamente,vigorosamente$~$"+
      " a $hcname$",
      "$mcname$ te asiente con la cabeza$ifarg: $lastarg$~$ at you",
      "$mcname$ asiente con la cabeza a$ifarg: $lastarg$~$ at $hcname$" }) }), 
  "arrimarse" : ({ ({ 0, "%s" }), ({
      "Te arrimas a $hcname$ con ganas de roce",
      "$mcname$ se arrima a ti con ganas de roce",
      "$mcname$ se arrima a $hcname$ con ganas de roce", }), }),
  "juramento" : ({ ({ 0, "%s" }), ({
      "Juras amor eterno e imperecedero por $hcname$",
      "$mcname$ jura amor eterno e imperecedero por ti",
      "$mcname$ jura amor eterno e imperecedero por $hcname$" }) }),
  "frotar" : ({ ({ 0, "%s", 3, "%s" }), ({
      "Te frotas $arg:las manos,los ojos,la nariz,la pierna,el brazo,las cejas,la cabeza$",
      "$mcname$ se frota $lastarg$",
      "Frotas a $hcname$ como si fuera la lampara de Aladin",
      "$mcname$ te frota como si fueras la lampara de Aladin",
      "$mcname$ frota a $hcname$ como si fuera la lampara de Aladin", }) }),
  "panico" : ({ 0, ({
      "Cundes al panico como una histerica",
      "$mcname$ cunde al panico como una loca histerica", }) }),
  "resollar" : ({ ({ 3,"%s" }), ({
      "Resuellas $arg:como un perro,aterrado,en cortas bocanadas,"+
      "apresurado,cansadamente,rapidamente$",
      "$mcname$ resuella $lastarg$" }) }),
  "palmadita" : ({ ({ 0, "%s", 2, "%s en %s", 2, "%s en %s", 1, "%s %s", 2, "%s %s" }), ({
      "Le das palmaditas a $hcname$ en $arg:la cabeza,la espalda,la pierna,la mano,la nariz,"+
      "en el culito$",
      "$mcname$ te da unas palmaditas $lastarg$",
      "$mcname$ le da unas palmaditas a $hcname$ en $lastarg$" }) }),
  "hurgar" : ({ ({ 3, "%s" }), ({
      "Te hurgas $arg:la nariz, la oreja,#$",
      "$mcname$ se hurga $lastarg$" }) }),
  "pellizcar" : ({ ({ 0, "%s", 2, "%s en %s", 2, "%s en %s", 1, "%s %s", 2, "%s %s" }),({
      "Te pellizcas para ver si estas sonyando",
      "$mcname$ se pellizca y parece defraudado",
      "Pellizcas a $hcname$$ifarg: en $arg:el culito,la pierna,el brazo,la mejilla$~$",
      "$mcname$ te pellizca$ifarg: en $lastarg$~$",
      "$mcname$ pellizca a $hcname$$ifarg: en $lastarg$~$",}) }),
  "ping" : ({ ({ 0, "%s" }), ({
      "Le haces P I N G! a $hcname$", "$mcname$ te hace P I N G!$force#asco $mname$#2$",
      "$mcname$ le hace P I N G! a $hcname$" })  }),
  "senyalar" : ({ ({ 0, "%s", 0, "at %s", 1, "%s at %s", 2, "at %s %s" }), ({
      "Senyalas con el dedo$ifarg: $arg:acusadoramente,discretamente$~$ a $hcname$",
      "$mcname$ te senyala con el dedo$ifarg: $lastarg$~$",
      "$mcname$ senyala con el dedo$ifarg: $lastarg$~$ a $hcname$" }) }),
  "codazo2" : ({ ({ 0, "%s", 2, "%s en %s", 2, "%s en %s", 2, "%s %s", 1, "%s %s" }), ({
      "Le das un ligero codazo a $hcname$$ifarg: en $arg:los ojos,las costillas,las piernas,"+
      "la nariz,la oreja,"+
      "el estomago,#$~$",
      "$mcname$ te da un ligero codazo$ifarg: en $lastarg$~$",
      "$mcname$ le da un ligero codazo a $hcname$$ifarg: en $lastarg$~$" })  }),
  "abalanzarse" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "Te abalanzas sobre $hcname$ $arg:salvajemente,lujuriosamente,felizmente,agresivamente$",
      "$mcname$ se abalanza sobre ti $lastarg$",
      "$mcname$ se abalanza sobre $hcname$ $lastarg$", }) }),
  "ponderar" : ({ 0, ({
      "Ponderas la situacion",
      "$mcname$ ponderas la situacion" }) }),
  "pucheros" : ({ ({ 3, "%s" }), ({
      "Haces pucheritos$ifarg: $arg:como un crio pequenyo,silenciosamente,resignadamente$~$",
      "$mcname$ hace pucheritos$ifarg: $lastarg$~$" }) }),
  "protestar" : ({ ({ 3, "%s" }), ({
      "Protestas$ifarg: $arg:vehementemente,ruidosamente,fuertemente,debilmente,"+
      "contra la caza de patos,ruidosamente,molestamente,#$~$",
      "$mcname$ protesta$ifarg: $lastarg$~$" }) }),
  "tirar"  : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "Tiras a $hcname$ de $arg:la manga,#$, para llamar su atencion",
      "$mcname$ te tira de $lastarg$, para llamar tu atencion",
      "$mcname$ le tira a $hcname$ de $lastarg$, para llamar su atencion" }) }),
  "punyetazo" : ({ ({ 0, "%s" }), ({
      "Te pegas un punyetazo en el estomago",
      "$mcname$ se pega un punyetazo en el estomago",
      "Le pegas un punyetazo a $hcname$",
      "$mcname$ te pega un punyetazo",
      "$mcname$ le pega un punyetazo a $hcname$", }) }),
  "puntapie" : ({ ({ 0, "%s" }), ({
      "Le pegas un puntapie a $hcname$",
      "$mcname$ te pega un puntapie",
      "$mcname$ le pega un puntapie a $hcname$" }) }),
  "ronronear" : ({ ({ 3, "%s" }), ({
      "Ronroneas $arg:contenidamente,ruidosamente,felizmente,sensualmente$",
      "$mcname$ ronronea $lastarg$" }) }),
  "empujar" : ({ ({ 0, "%s", }), ({
      "Te empujas a ti mismo",
      "$mcname$ se empuja asimismo",
      "Empujas a $hcname$ al vacio",
      "$mcname$ te empuja al vacio",
      "$mcname$ empuja a $hcname$ al vacio", }) }),
  "rodar" : ({ ({ 2, "%s %s", 1, "%s %s", 3, "%s", 0, "%s" }), ({
      "Ruedas $arg:tus ojos,por el suelo riendote,"+
      "boca arriba y te haces el muerto,como un ovillo,"+
      "de lado,hacia atras,prefesionalmente,como un espia a traves "+
      "de una puerta imaginaria,causando temor,tensamente,lentamente$",
      "$mcname$ rueda $lastarg$",
      "Ruedas $ifarg:$arg:rapidamente,lentamente,dolorosamente,excitadamente,amorosamente,"+
      "cuidadosamente$ ~$sobre $hcname$",
      "$mcname$ rueda $ifarg:$lastarg$ ~$sobre you",
      "$mcname$ rueda $ifarg:$lastarg$ ~$sobre $hcname$" }) }),
  "agitar" : ({ ({ 0, "%s", 2, "%s %s", 1, "%s %s" }), ({
      "Le agitas el pelo a $hcname$$ifarg: $arg:juguetonamente,afectuosamente$~$",
      "$mcname$ te agita el pelo$ifarg: $lastarg$~$",
      "$mcname$ le agita el pelo a $hcname$$ifarg: $lastarg$~$" }) }),
  "saludar" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "Saludas a $hcname$$ifarg: $arg:felizmente,respetuosamente,"+
      "sarcasticamente,salvajemente,formalmente$~$",
      "$mcname$ te saluda$ifarg: $lastarg$~$",
      "$mcname$ saluda a $hcname$$ifarg: $lastarg$~$" }) }),
  "embestir" : ({ ({ 0, "%s" }), ({
      "Embistes a $hcname$ como un rottweiler rabioso",
      "$mcname$ te embiste como un rottweiler rabioso",
      "$mcname$ embiste a $hcname$ como un rottweiler rabioso" }) }),
  "sobresaltar" : ({ ({ 0, "%s" }), ({
      "Te acercas por la espalda de $hcname$ y le pegas un toquecito, sobresaltandolo",
      "$mcname$ te da un toque en la espalda cuando menos te lo esperabas$force#miedo $mname$#2$",
      "$mcname$ se acerca sigilosamente a $hcname$ y le pega un toquecito en la espalda" }) }),
  "rascarse" : ({ ({0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "Te rascas la cabeza",
      "$mcname$ se rasca la cabeza",
      "$ifarg:Rascas $arg:viciosamente,levemente,amorosamente$ la cabeza de $hcname$"+
      "$else$Rascas a $hcname$~$",
      "$ifarg:$mcname$ $lastarg$ te rasca la cabeza$else$"+
      "$mcname$ $lastarg$ te rasca~$",
      "$mcname$ $ifarg:$lastarg$ ~$le rasca la cabeza a $hcname$"
    }) }),
  "chillar" : ({ ({ 3, "%s", 3, "in %s" }), ({
      "$ifarg:Chillas con $arg:terror,miedo,pavor,panico,sorpresa,frustacion,"+
      "desesperacion,enfado$$else$Arrggghhhhh!!!!~$",
      "$mcname$ chilla$ifarg: con $lastarg$$else$ ruidosamente~$" }) }),
  "seducir" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "Seduces a $hcname$$ifarg: $arg:carinyosamente,desagradablemente,"+
      "profesionalmente,dulcemente,cuidadosamente,adorablemente,sadisticamente$~$",
      "$mcname$ te seduce$ifarg: $lastarg$~$",
      "$mcname$ seduce a $hcname$$ifarg: $lastarg$~$" }) }),
  "sacudir" : ({ ({ 0, "%s", 1, "%s with %s", 1, "%s %s", 1, "%s %s", 3, "%s",
      1, "%s at %s", 3, "my %s", }), ({
      "Sacudes la cabeza$ifarg: $arg:arrepentidamente,cuidadosamente,lentamente,"+
      "una vez,rapidamente,secamente,en desacuerdo,vigorosamente,completamente,como un pez,"+
      "tentativamente,en acuerdo$~$",
      "$mcname$ sacude su cabeza$ifarg: $lastarg$~$",
      "Sacudes $ifarg: $arg:las manos con,las orejas con,los dedos con,las piernas con,"+
      "las alas con,los tentaculos con,los punyos con$~$ $hcname$",
      "$mcname$ sacude$ifarg: $lastarg$~$tigo",
      "$mcname$ sacudes$ifarg: $lastarg$~$ $hcname$" }) }),
  "sollozar" : ({ ({ 3, "con %s", 3, "%s" }), ({
      "Sollozas$ifarg: $arg:con miedo,por el frio,levemente,#$~$",
      "$mcname$ solloza$ifarg: $lastarg$~$" }) }),
  "hombros" : ({ 0, ({ "Te encoges de hombros", "$mcname$ se encoge de hombros", }) }),
  "estremecerse" : ({ ({ 3, "%s" }), ({
      "Te estremeces $ifarg:de $arg:miedo,asco,desilusion,extasis"+
      "$$else$de horror~$",
      "$mcname$ se estremece $ifarg:de $lastarg$$else$de horror~$", }) }),
  "cantar" : ({ ({ 0, "%s", 3, "%s" }), ({
      "Cantas $arg:en tributo a la vida,#$",
      "$mcname$ $ifarg:canta $lastarg$$else$desafinadoramente~$",
      "Le cantas una sereneta a $hcname$",
      "$mcname$ te canta una serenata",
      "$mcname$ le canta una serenata a $hcname$" }) }),
  "sentarse" : ({ 0, ({
      "Te sientas",
      "$mcname$ se sienta", }) }),
  "dormir" : ({ ({ 0, "%s" }), ({
      "Te duermes",
      "$mcname$ se duerme",
      "Te duermes en los brazos de $hcname$",
      "$mcname$ se duerme en tus brazos",
      "$mcname$ se duerme en los brazos de $hcname$", }) }),
  "besuquear" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "Besuqueas a $hcname$ $arg:amorosamente,afectivamente,hasta la eternidad,calidamente,"+
      "gently$",
      "$mcname$ te besuquea $lastarg$",
      "$mcname$ besuquea a $hcname$ $lastarg$" }) }),
  "sonreir" : ({ ({
      0, "a %s", 0, "%s", 1, "%s a %s", 1, "%s %s", 2, "a %s %s",
      2, "%s %s", 3, "%s", }), ({
      "Sonries$ifarg: $arg:felizmente,tristemente,nerviosamente,ironicamente,ampliamente,torcidamente,"+
      "estupidamente,idioticamente,condescendientemente,pacientemente,brillantemente,"+
      "ligeramente,desagradablemente,excitadamente,estranyamente,con forzada paciencia,elasticamente,"+
      "cuidadosamente,sadisticamente,desequilibradamente,como un pez,como un gato,levemente,"+
      "maniacamente,como un tren,enfadadamente,paranoicamente,inocentemente,como un sapo,astutamente,"+
      "debilmente,farfullando,paradojicamente,sarcasticamente,viciosamente,llamativamente,"+
      "dulcemente,inocentemente,amorosamente,sonyadoramente,radiantemente,entusiasticamente,"+
      "insolentemente,caprichosamente,completamente,inconscientemente,borrachamente,"+
      "esperanzadamente,locamente,lindamente,maliciosamente,"+
      "distraidamente,secamente,disturbadoramente,increiblemente,quedamente,"+
      "ruidosamente,diferentemente,ganadoramente,triunfantemente,seductoramente,"+
      "tensamente,joder hay un webo de argumentos,suavemente,orgullosamente,"+
      "vivamente,demoniacamente,calidamente,espasmodicamente,ovejunamente,oscuramente,"+
      "enfermamente,guerreramente,sardonicamente,perezosamente,serenamente,desaprobadoramente$~$",
      "$mcname$ sonrie$ifarg: $lastarg$~$",
      "Sonries$ifarg: $arg:felizmente,tristemente,nerviosamente,ironicamente,ampliamente,torcidamente,"+
      "estupidamente,idioticamente,condescendientemente,pacientemente,brillantemente,"+
      "ligeramente,desagradablemente,excitadamente,estranyamente,con forzada paciencia,elasticamente,"+
      "cuidadosamente,sadisticamente,desequilibradamente,como un pez,como un gato,levemente,"+
      "maniacamente,como un tren,enfadadamente,paranoicamente,inocentemente,como un sapo,astutamente,"+
      "debilmente,farfullando,paradojicamente,sarcasticamente,viciosamente,llamativamente,"+
      "dulcemente,inocentemente,amorosamente,sonyadoramente,radiantemente,entusiasticamente,"+
      "insolentemente,caprichosamente,completamente,inconscientemente,borrachamente,"+
      "esperanzadamente,locamente,lindamente,maliciosamente,"+
      "distraidamente,secamente,disturbadoramente,increiblemente,quedamente,"+
      "ruidosamente,diferentemente,ganadoramente,triunfantemente,seductoramente,"+
      "tensamente,joder hay un webo de argumentos,suavemente,orgullosamente,"+
      "vivamente,demoniacamente,calidamente,espasmodicamente,ovejunamente,oscuramente,"+
      "enfermamente,guerreramente,sardonicamente,perezosamente,serenamente,desaprobadoramente$~$"+
      " a $hcname$",
      "$mcname$ te sonrie$ifarg: $lastarg$~$",
      "$mcname$ sonrie$ifarg: $lastarg$~$ a $hcname$" }) }),
  "castigar" : ({ ({ 0, "%s" }), ({
      "Castigas a $hcname$ desde los cielos",
      "$mcname$ te castiga desde los cielos",
      "$mcname$ castiga a $hcname$ desde los cielos" }) }),
  "chasquear" : ({ ({ 0, "%s", 1, "%s hacia %s", 1, "%s hacia %s", 3, "%s" }), ({
      "Chasqueas tus $arg:dedos,piernas,brazos en un rapido saludo$",
      "$mcname$ chasquea sus $lastarg$",
      "Chasqueas tus $arg:dedos,piernas,brazos en un rapido saludo$ hacia $hcname$",
      "$mcname$ chasquea sus $lastarg$ hacia ti",
      "$mcname$ chasquea sus $lastarg$ hacia $hcname$" }) }),
  "estornudar" : ({ ({ 0, "a %s", 2, "%s a %s", 3, "%s" }), ({
      "Estornudas $arg:violentamente,ruidosamente,silenciosamente,quedamente,de repente,"+
      "inesperadamente$~$",
      "$mcname$ estornuda $lastarg$",
      "Le estornudas $arg:violentamente,ruidosamente,silenciosamente,quedamente,de repente,"+
      "inesperadamente$~$ at $hcname$",
      "$mcname$ te estornuda $lastarg$",
      "$mcname$ estornuda $lastarg$ a $hcname$" }) }),
  "husmear" : ({ ({ 3, "%s" }), ({
      "Husmeas$ifarg: $arg:apenadamente,ruidosamente,silenciosamente,con desprecio$~$",
      "$mcname$ husmea$ifarg: $lastarg$~$" }) }),
  "roncar" : ({ ({ 0, "%s", 3, "%s" }), ({
      "$ifarg:Roncas $arg:ruidosamente,como un tren,descuidadamente$~$"+
      "else$...zzZZzzZZZzzZZzzzzzZZZzzZZZzZz...~$",
      "$mcname$ ronca$ifarg: $lastarg$~$" }) }),
  "resoplar" : ({ 0, ({
      "Resoplas",
      "$mcname$ resopla", }) }),
  "zurrar" : ({ ({ 0, "%s", 2, "%s %s" }), ({
      "Le zurras a $hcname$$ifarg: $arg:seductoramente,cuidadosamente,caballerosamente,"+
      "incontrolablemente,educadamente,sensualmente,selectivamente,inesperadamente,"+
      "con una sonrisa siniestra,dolorosamente,sigilosamente,sin haber sido provocado,"+
      "profesionalmente,vigorosamente,"+
      "reflexivamente,con un gato,como un tren,como la Virgen Maria,"+
      "con una Virgen Maria$~$",
      "$mcname$ te zurra$ifarg: $lastarg$~$",
      "$mcname$ zurra a $hcname$$ifarg: $lastarg$~$", }) }),
  "escupir" : ({ ({ 0, "%s", 3, "%s" }), ({
      "Escupes$ifarg: $arg:diestramente,como un camello$~$",
      "$mcname$ escupe$ifarg: $lastarg$~$",
      "Le escupes a $hcname$ en la cara",
      "$mcname$ te escupe en la cara",
      "$mcname$ escupe a $hcname$ en la cara" }) }),
  "estrujar" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "Estrujas a $hcname$ $arg:a fondo,caballerosamente,tensamente$",
      "$mcname$ te estruja $lastarg$"}) }),
  "pisotear" : ({ ({ 0, "%s", 2, "%s %s" }), ({
      "Pisoteas a $hcname$ $arg:como a un insecto,"+
      "con el pie divino,removiendo sus restos,ensanyadamente$",
      "$mcname$ te pisotea $lastarg$",
      "$mcname$ pisotea a $hcname$ $lastarg$" }) }),
  "estrangular" : ({ ({ 0, "%s", 1, "%s por %s", 1, "%s %s" }), ({
      "Te estrangulas a ti mismo",
      "$mcname$ se estrangula asimismo",
      "Estrangulas a $hcname$$ifarg: por $arg:#$~$",
      "$mcname$ te estrangula$ifarg: por $arg:#$~$",
      "$hcname$ estrangula a $mcname$$ifarg: por $arg:#$~$", }) }),
  "arullar" : ({ ({ 0, "%s" }), ({
      "Arrullas a $hcname$",
      "$mcname$ te arrulla",
      "$mcname$ arrulla a $hcname$", }) }),
  "pavonearse" : ({ 0, ({
      "Te pavoneas como un buen palomo",
      "$mcname$ se pavonea orgullosamente por toda la room" }) }),
  "tropezarse" : ({ ({ 3, "%s" }), ({
      "Te tropiezas $ifarg:$arg:#$$else$con una piedra del camino~$",
      "$mcname$ se tropieza $ifarg:$arg:#$$else$con una piedra del camino~$" }) }),
  "chupar" : ({ ({ 3, "%s" }), ({
      "Te chupas $arg:el pulgar,el lapiz,#$",
      "$mcname$ se chupa $lastarg$" }) }),
  "enfurrunyarse" : ({ 0, ({
      "Te vas a una esquina y te haces una pelotita enfurrunyada",
      "$mcname$ se va a una esquina y se hace una pelotita enfurrunyada" }) }),
  "nadar" : ({ 0, ({
      "Haces una gran demostracion de tus dotes como nadador", "$mcname$ nada por ahi" }) }),
  "simpatizar" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s" }), ({
      "Simpatizas$ifarg: arg:sinceramente,felizmente,parcialmente,"+
      "a veces,de algun modo$~$ con $hcname$",
      "$mcname$ simpatiza $lastarg$ contigo",
      "$mcname$ simpatiza $lastarg$ con $hcname$" }) }),
  "tango" : ({ ({ 0, "%s" }), ({
      "Deslizas a $hcname$ en un tango apasionado",
      "$mcname$ te desliza en un tango apasionado",
      "$mcname$ desliza a $hcname$ en un tango apasionado" }) }),
  "desgarrar"  : ({ ({ 0, "%s" }), ({
      "Desgarras a $hcname$ convirtiendolo en fettuccini",
      "$mcname$ te desgarra convirtiendote en fettuccini",
      "$mcname$ desgarra a $hcname$ convirtiendolo en fettuccini" }) }),
  "tentar" : ({ ({ 0, "%s", 2, "%s con %s" }), ({
      "Tientas a $hcname$$ifarg: con $arg:bayas,"+
      "dinero,putas,drogas,amor,sexo$~$",
      "$mcname$ te tienta$ifarg: con $lastarg$~$",
      "$mcname$ tienta a $hcname$$ifarg: con $lastarg$~$" }) }),
  "agradecer" : ({ ({ 0, "%s", 2, "%s %s" }), ({
      "Te muestras agradecido con $hcname$$ifarg: $arg:profusamente,gratuitamente,un monton,"+
      "levemente,reservadamente,solemnemente,con todo tu corazon$~$",
      "$mcname$ te lo agradece$ifarg: $lastarg$~$",
      "$mcname$ se lo agradece a $hcname$$ifarg: $lastarg$~$" }) }),
  "pensar" : ({ ({ 3, "%s", }), ({
      "Piensas $ifarg:$arg:#$$else$cuidadosamente~$",
      "$mcname$ piensa $ifarg:$lastarg$$else$cuidadosamente~$" }) }),
  "lanzar" : ({ ({ 0, "%s" }), ({
      "Hi yyyyaaa",
      "$mcname$ Te lanza por los suelos$force#sonreir fel $mname$#2$",
      "$mcname$ throws $hcname$ to the floor in a happy embrace" }) }),
  "finfanfun" : ({ ({ 0, "%s"  }), ({
      "T H W O K K ! !",
      "$mcname$ \"T H W O K K ! !",
      "Finfanfunflas a $hcname$",
      "Has sido sumariamente finfanfunflado por $mcname$",
      "$mcname$ finfanfunfla $hcname$" }) }),
  "cosquillas" : ({ ({ 0,"%s", 1, "%s %s", 2, "%s %s" }), ({
      "Le haces cosquillas a $hcname$$ifarg: $arg:despiadadamente,duramente,sin miedo,"+
      "rapidamente,sigilosamente,debilmente,cuidadosamente,gentilmente,furiosamente,increiblemente"+
      "lentamente$~$",
      "$mcname$ te hace cosquillas$force#bofetada#2$$ifarg: $lastarg$~$",
      "$mcname$ le hace cosquillas a $hcname$$ifarg: $lastarg$~$" }) }),
  "lengua" : ({ ({ 0,"%s", }), ({
      "Le sacas la lengua a $hcname$",
      "$mcname$ te saca la lengua",
      "$mcname$ le saca la lengua a $hcname$", }) }),
  "temblar" : ({ ({ 3, "%s" }), ({
      "Tiemblas $arg:de miedo,nervioso,de dolor,levemente,violentamente,"+
      "insistentemente,cuidadosamente,en un traje rosa,en antici.......pacion$",
      "$mcname$ tiembla $lastarg$", }), }),
  "esperar" : ({ ({
      0, "%s", 0, "a %s", 0, "a %s %s", 1, "%s %s",
      0, "a %s", 1, "%s a %s",
      2, "%s %s", 3, "%s" }), ({
      "Esperas$ifarg: $arg:pacientemente,impacientemente,medio dormido,perezosamente,"+
      "felizmente,cansadamente,excitadamente,largamente$~$",
      "$mcname$ espera$ifarg: $lastarg$~$",
      "Esperas$ifarg: $arg:pacientemente,impacientemente,medio dormido,perezosamente,"+
      "felizmente,cansadamente,excitadamente,largamente$~$ a $hcname$",
      "$mcname$ te espera$ifarg: $lastarg$~$",
      "$mcname$ espera$ifarg: $lastarg$~$ a $hcname$" }) }),
  "vals" : ({ ({ 0, "%s", }), ({
      "Bailas un vals por toda la habitacion con $hcname$",
      "$mcname$ baila un vals por toda la habitacion contigo",
      "$mcname$ baila un vals por toda la habitacion con $hcname$", }) }),
  "despedirse" : ({ ({
      0, "%s", 0, "at %s", 0, "to %s", 2, "at %s %s", 1, "%s %s",
      1, "%s to %s", 2, "to %s %s", 0, "at %s", 1, "%s at %s",
      2, "%s %s", 3, "%s" }), ({
      "Te despides$ifarg: $arg:cansadamente,medio dormido,profundamente,perezosamente,tristemente,"+
      "felizmente,redundantemente,excitadamente,largamente,acusadoramente,"+
      "con las alas,con las plumas,con los tentaculos,con las raices$~$",
      "$mcname$ se despide$ifarg: $lastarg$~$",
      "Te despides$ifarg: $arg:cansadamente,medio dormido,profundamente,perezosamente,tristemente,"+
      "felizmente,redundantemente,excitadamente,largamente,acusadoramente,"+
      "con las alas,con las plumas,con los tentaculos,con las raices$~$ de $hcname$",
      "$mcname$ se despide de ti$ifarg: $lastarg$~$",
      "$mcname$ se despide$ifarg: $lastarg$~$ de $hcname$" }) }),
  "relinchar" : ({ 0, ({
      "Relinchas como un caballo",
      "$mcname$ relincha como un caballo", }) }),
  "silbar" : ({ ({ 0, "%s", 1, "%s %s", 2, "%s %s", 3, "%s" }), ({
      "Silbas $arg:inocentemente,apreciativamente,ruidosamente,musicalmente,agradablemente,"+
      "discordantemente$",
      "$mcname$ silba $lastarg$",
      "Le silbas $arg:inocentemente,apreciativamente,ruidosamente,musicalmente,agradablemente,"+
      "discordantemente,carinyosamente,seductoramente$ a $hcname$",
      "$mcname$ te silba $lastarg$",
      "$mcname$ le silba $lastarg$ a $hcname$" }) }),
  "mueca" : ({ 0, ({ "Haces una mueca de dolor", "$mcname$ hace una mueca de dolor" }) }),
  "menear" : ({ ({ 0, "%s", 2, "%s hacia %s", 3, "%s" }), ({
      "Meneas tu culito$ifarg: $arg:tentadoramente,sugestivamente,vigorosamente,"+
      "arrogantemente,galantemente,rapidamente$~$",
      "$mcname$ menea su culito$ifarg: $lastarg$~$",
      "Meneas tu culito$ifarg: $arg:tentadoramente,sugestivamente,vigorosamente,"+
      "arrogantemente,galantemente,rapidamente$~$ hacia $hcname$",
      "$mcname$ menea su culito$ifarg: $lastarg$~$ hacia ti",
      "$mcname$ menea su culito$ifarg: $lastarg$~$ hacia $hcname$" }) }),
  "pestanyear" : ({ ({ 0, "%s", 0, "hacia %s", 1, "%s hacia %s", 1, "%s %s",
      2, "hacia %s %s", 2, "%s %s", 3, "%s" }), ({
      "Pestanyeas$ifarg: $arg:sugestivamente,ampliamente,lentamente,ruidosamente,malhumoradamente,"+
      "desesperadamente,timidamente,insolentemente,secamente,amorosamente,"+
      "pacientemente,sadisticamente,cautelosamente,seductoramente,perezosamente$~$",
      "$mcname$ pestanyea$ifarg: $lastarg$~$",
      "Pestanyeas$ifarg: $arg:sugestivamente,ampliamente,lentamente,ruidosamente,malhumoradamente,"+
      "desesperadamente,timidamente,insolentemente,secamente,amorosamente,"+
      "pacientemente,sadisticamente,cautelosamente,seductoramente,perezosamente$~$ hacia $hcname$",
      "$mcname$ pestanyea$ifarg: $lastarg$~$ hacia ti",
      "$mcname$ pestanyea$ifarg: $lastarg$~$ hacia $hcname$" }) }),
  "tambalearse" : ({ ({ 3, "%s" }), ({
      "Te tambaleas $arg:por alrededor,como recien salido de un holy,inestablemente,"+
      "felizmente$",
      "$mcname$ se tambalea $lastarg$", }) }),
  "preguntarse" : ({ ({ 3, "%s" }), ({
      "Te preguntas $ifarg:$arg:#$$else$sobre la realidad "+
      "y como de aburrida puede llegar a ser~$",
      "$mcname$ se pregunta $ifarg:$arg:#$$else$sobre la realidad "+
      "y como de aburrida puede llegar a ser~$", }) }),
  "woo" : ({ 0, ({
      "Dices Wooooo con gran placer!",
      "$mcname$ dice Wooooo con gran placer!" }) }),
  "adorar" : ({ ({ 0, "%s", 3, "%s" }), ({
      "Adoras a $ifarg:$arg:#$$else$Grimfang~$",
      "$mcname$ adora a $ifarg:$lastarg$$else$Grimfang~$",
      "Adoras a $hcname$",
      "$mcname$ te adora", "$mcname$ adora a $hcname$" }) }),
  "bostezar" : ({ ({ 3, "%s" }), ({
      "Bostezar $arg:cansadamente,aburrido,medio dormido$",
      "$mcname$ bosteza $lastarg$" }) }) ,
  "gatonegro" : ({ ({ 0, "%s" }), ({
      "Te transformas en un gato negro y todo el mundo palidece!",
      "AAAHHH!!!!  un gato negro!!, date la vuelta!!",
      "Transformas a $hcname$ en un gato negro",
      "$mcname$ te transforma en un gato negro!",
      "AAAHHH!!!! un gato negro!!, date la vuelta!!" }) }),
  "huir" : ({ ({ 0, "%s", }), ({
      "LLamas a la puerta de $hcname$ y sales corriendo de vuelta a la oscuridad",
      "Oyes como alguien llama a tu puerta y sales a abrir, solo para ver a "+
      "$mcname$ huyendo hacia a la oscuridad",
      "Logras ver a $mcname$ huyendo hacia la oscuridad, justo cuando "+
      "te dirigias a casa de $hcname$" }) }),
  "susto_o_caramelos" : ({ ({ 0, "%s" }), ({
      "LLamas a la puerta de $hcname$ exclamando 'Susto o caramelos!'",
      "$mcname$ llama a tu puerta exclamando 'Susto o caramelos!'",
      "Oyes un grito de 'Susto o caramelos' en algun lugar" }) }),
  "volar" : ({ ({ 0, "%s" }), ({
      "Vuelas alrededor con tu escoba voladora",
      "$mcname$ vuela alrededor con su escoba voladora",
      "Vuelas alrededor de $hcname$ con tu escoba voladora",
      "$mcname$ vuela a tu alrededor con su escoba voladora",
      "$mcname$ vuela alrededor de $hcname$ con su escoba voladora" }) }),
  "descojonarse" : ({ ({ 0, "%s" }), ({
      "Te descojonas de $hcname$ hasta que se te saltan las lagrimas",
      "$mcname$ se descojona de ti hasta que se le saltan las lagrimas",
      "$mcname$ se descojona de $hcname$ hasta que se le saltan las lagrimas" }) }),
						  
]);
